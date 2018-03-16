#include <stdlib.h>

int sum(int a, int b) {
    return a + b;
}

int check_representation(char *input) {
    short unsigned int i = 0;
    while(input[i] != '\0') {
        if(input[i] < 48 || input[i] > 57) {
            if((input[i] < 65 || input[i] > 90) && (input[i] < 97 || input[i] > 122)) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int get_integer_value(char *number) {
    register short unsigned int i = 0;
    while(number[i] != '\0') {
        if(number[i] < 48 || number[i] > 57) {
            return -1;
        }
        i++;
    }
    return atoi(number);
}

long int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power(base, --exponent);
}

int get_int_from_char(char value) {
    if(value >= 48 && value <= 57) return value - 48;
    else return (value >= 65 && value <= 90) ? value - 55 : value - 87;
}

int baseN_to_10(char *number, int base) {
    register int i = 0;
    long int result = 0;
    unsigned short int exponent = 0;
    while(number[i] != '\0') i++;
    for(; i > 0; i--) {
        result += get_int_from_char(number[i - 1]) * power(base, exponent++);
    }
    return result;
}