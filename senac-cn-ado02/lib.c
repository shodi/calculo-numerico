#include "lib.h"
#include <math.h>

unsigned long long int fatorial(int value) {
    unsigned long long int result = 1;
    for(int i = 1; i <= value; i++)
        result *= i;
    return result;
}

double seno(double value, int n_value) {
    double sum = 0;
    value = value * PI / 180;
    // série de taylor
    for(int i = 0; i <= n_value; i++) {
        sum += (pow(-1, i) / (double)fatorial(2 * i + 1)) * pow(value, 2 * i + 1);
    }
    return sum;
}

double cosseno(double value, int n_value) {
    double sum = 0;
    value = value * PI / 180;
    // série de taylor
    for(int i = 0; i <= n_value; i++) {
        sum += (pow(-1, i) / (double)fatorial(2 * i)) * pow(value, 2 * i);
    }
    return sum;
}