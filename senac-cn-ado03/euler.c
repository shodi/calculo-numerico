#define _POSIX_C_SOURCE 2
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void open_file_connection(FILE **fp, char *output_name) {
    *fp = popen("gnuplot --persist", "w");
    fprintf(*fp, "set terminal png\n");
    fprintf(*fp, "set output '%s'\n", output_name);
    fprintf(*fp, "set logscale x\n");
    fprintf(*fp, "plot '-' with lines\n");
}

int main(void) {
    FILE *fp_float, *fp_double, *fp_long_double;
    fp_float = fp_double = fp_long_double = NULL;
    long double iterator = 1;
    open_file_connection(&fp_float, "euler_flt.png");
    open_file_connection(&fp_double, "euler_dbl.png");
    open_file_connection(&fp_long_double, "euler_ldbl.png");
    for(; iterator <= _MAX_ITERATION; iterator *= 10) {
        printf("iter_index: %.0Lf\tfloat: %.5f\tdouble: %.5lf\tlong double: %.5Lf\n", iterator, get_euler_float(fp_float, iterator), get_euler_double(fp_double, iterator), get_euler_long_double(fp_long_double, iterator));
    }
    fprintf(fp_float, "e\n");
    fprintf(fp_double, "e\n");
    fprintf(fp_long_double, "e\n");
    pclose(fp_float);
    pclose(fp_double);
    pclose(fp_long_double);
    exit(0);

}
