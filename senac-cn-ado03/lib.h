#ifndef _MAX_ITERATION
#define _MAX_ITERATION 1e20+0.0
#endif
#include <stdio.h>
float get_euler_float(FILE *fp, long double iteration_index);
double get_euler_double(FILE *fp, long double iteration_index);
long double get_euler_long_double(FILE *fp, long double iteration_index);