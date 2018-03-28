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
    FILE *fp_float, *fp_double, *fp_long_double;
    fp_float = fp_double = fp_long_double = NULL;
    long double iterator = 1;
    open_file_connection(fp_float, "float_file", "float");
    open_file_connection(fp_double, "double_file", "double");
    open_file_connection(fp_long_double, "long_double_file", "long_double");
    for(; iterator <= _MAX_ITERATION; iterator *= 10) {
        printf("iter_index: %.0Lf\tfloat: %.5 lf\tlong double: %.5Lf\n", get_euler_float(fp_float, a), get_euler_double(fp_double, a), get_euler_long_double(fp_long_double, a)));
    }
    fprintf(fp_float, "e\n");
    fprintf(fp_double, "e\n");
    fprintf(fp_long_double, "e\n");
    pclose(fp_float);
    pclose(fp_double);
    pclose(fp_long_double);
    exit(0);

}
