#include "lib.h"
#include <math.h>

void get_euler_float(FILE *fp, long double iteration_index) {
    float value = pow(1 + (1 / iteration_index), iteration_index);
    fprintf(fp, "%f %f\n", (float)iteration_index, value);
}

void get_euler_double(FILE *fp, long double iteration_index) {
    double value = pow(1 + (1 / iteration_index), iteration_index);
    fprintf(fp, "%lf %lf\n", (double)iteration_index, value);
}

void get_euler_long_double(FILE *fp, long double iteration_index) {
    long double value = pow(1 + (1 / iteration_index), iteration_index);
    fprintf(fp, "%Lf %Lf\n", (long double)iteration_index, value);
}