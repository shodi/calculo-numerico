#include "lib.h"
#include <math.h>

long double fatorial(int value) {
    long double result = value;
l1: if(value > 1) {
        result *= value;
        value--;
        goto l1;
    }
    return result;
}

double seno(double value, int n_value) {
    double sum = 0;
    double aux = (value * PI) / 180.0;
    // série de taylor
    for(int i = 0; i <= n_value; i++) {
        sum += (pow(-1, i) / fatorial(2 * i + 1)) * pow(aux, 2 * i + 1);
    }
    return sum;
}

double cosseno(double value, int n_value) {
    double sum = 0;
    double aux = (value * PI) / 180.0;
    // série de taylor
    for(int i = 0; i <= n_value; i++) {
        sum += (pow(-1, i) / fatorial(2 * i)) * pow(aux, 2 * i);
    }
    return sum;
}