#define _POSIX_C_SOURCE 2
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void open_file_connection(FILE *fp, char *output_name, char *data_type) {
    fp = popen("gnuplot --persist", "w");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output \"%s\"\n", output_name);
    fprintf(fp, "set logscale x\n");
    fprintf(fp, "plot 'e (%s)' with lines\n", data_type);
}

int main(void) {
    FILE *fp = NULL;
    long double a = 1;
    open_file_connection(fp, "float_file", "float");
    for(; a <= _MAX_ITERATION; a *= 10) {
        get_euler_float(fp, a);
    }
    fprintf(fp, "e\n");
    pclose(fp);
        // a = 1;
        // open_file_connection(fp, "double_file", "double");
        // for(; a <= _MAX_ITERATION; a *= 10) {
        //     get_euler_double(fp, a);
        // }
        // fprintf(fp, "e\n");
        // pclose(fp);
        // a = 1;
        // open_file_connection(fp, "long_double_file", "LongDouble");
        // for(; a <= _MAX_ITERATION; a *= 10) {
        //     get_euler_long_double(fp, a);
        // }
        // fprintf(fp, "e\n");
        // pclose(fp);
    exit(0);

}