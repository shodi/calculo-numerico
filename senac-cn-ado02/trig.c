#define _POSIX_C_SOURCE 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

void open_connection(FILE **fp, char* file_name) {
    *fp = popen("gnuplot --persist", "w");
    fprintf(*fp, "set terminal png\n");
    fprintf(*fp, "set output '%s'\n", file_name);
    fprintf(*fp, "plot '-' with lines\n");
}

void close_connection(FILE **fp) {
    fprintf(*fp, "e\n");
    pclose(*fp);
}

double get_relative_err(double abs_err, double value) {
    if (fabs(value) > 0.0) {
        return abs_err / value;
    }
    return 0.0;
}

int main(void) {
    FILE *_seno, *_cosseno, *sin_dat, *cos_dat;
    _seno = _cosseno = sin_dat = cos_dat = NULL;
    open_connection(&_seno, "seno.png");
    open_connection(&_cosseno, "cosseno.png");
    sin_dat = fopen("seno.dat", "w");
    cos_dat = fopen("cosseno.dat", "w");
    double sen_result, cos_result, sin_err_abs, cos_err_abs, c_sin, c_cos,  aux;
    // 720 = 2*360 = 4 pi rad
    for(int i = 0; i <= 720; i++) {
        aux = (i * PI) / 180.0;
        sen_result = seno(i, __N_APROACH);
        cos_result = cosseno(i, __N_APROACH);
        c_sin = sin(i * PI / 180.0);
        c_cos = cos(i * PI / 180.0);
        sin_err_abs = fabs(c_sin - sen_result);
        cos_err_abs = fabs(c_cos - cos_result);
        printf("meu seno: %lf\tC sin: %lf\n", sen_result, c_sin);
        fprintf(_seno, "%lf %lf\n", aux, sen_result);
        fprintf(_cosseno, "%lf %lf\n", aux, cos_result);
        fprintf(sin_dat, "%d\t%lf\t%lf\t%lf\n", i, sen_result, sin_err_abs, get_relative_err(sin_err_abs, c_sin));
        fprintf(cos_dat, "%d\t%lf\t%lf\t%lf\n", i, cos_result, cos_err_abs, get_relative_err(cos_err_abs, c_cos));
    }
    close_connection(&_seno);
    close_connection(&_cosseno);
    fclose(sin_dat);
    fclose(cos_dat);
    exit(0);
}