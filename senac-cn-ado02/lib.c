#include "lib.h"
#include <math.h>

long double fatorial(int value) {
    long double result = 1;
    int i = 1;
    while(i <= value) {
        result *= i;
        i++;
    }
    return result;
}

double seno(double value, int n_value) {
    double sum = 0;
    double aux = (value * PI) / 180.0;
    // série de taylor
    for(int i = 0; i <= n_value; i++) {
        long double fac = fatorial(2 * i + 1);
        printf("fatorial %d = %Lf\n", 2 * i + 1, fac);
        sum += powl(-1, i) * (powl(aux, 2 * i + 1) / fac);
    }
    return sum;
}

double cosseno(double value, int n_value) {
    double sum = 0;
    double aux = (value * PI) / 180.0;
    // série de taylor
    for(int i = 0; i <= n_value; i++) {
        sum += powl(-1, i) * (powl(aux, 2 * i) / fatorial(2 * i));
    }
    return sum;
}