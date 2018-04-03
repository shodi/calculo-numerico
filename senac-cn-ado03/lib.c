#include "lib.h"
#include <math.h>

float get_euler_float(FILE *fp, long double iteration_index) {
    float value = pow(1 + (1 / iteration_index), iteration_index);
    fprintf(fp, "%f %f\n", (float)iteration_index, value);
    return value;
}

double get_euler_double(FILE *fp, long double iteration_index) {
    double value = pow(1 + (1 / iteration_index), iteration_index);
    fprintf(fp, "%lf %lf\n", (double)iteration_index, value);
    return value;
}

long double get_euler_long_double(FILE *fp, long double iteration_index) {
    long double value = powl(1 + (1 / iteration_index), iteration_index);
    fprintf(fp, "%Lf %Lf\n", (long double)iteration_index, value);
    return value;
}