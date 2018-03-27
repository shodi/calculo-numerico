#include <stdlib.h>
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int check_base_range(char a, int base) {
    if (a == 45) return 1;
    if (base <= 10 && base >= 2) {
        if(a >= 48 && a <= (48 + base - 1)) return 1;
    }
    else if(base <= 36) {
        if ((a >= 48 && a <= 57) || (a >= 65 && a <= (65 + base - 11)) || (a >= 97 && a <= (97 + base - 11))) return 1;
    }
    return 0;
}

int check_representation(char *input, int base) {
    register short unsigned int i = 0;
    while(input[i] != '\0') {
        if (!check_base_range(input[i], base)) return 0;
        if(input[i] != 45 && (input[i] < 48 || input[i] > 57)) {
            if((input[i] < 65 || input[i] > 90) && (input[i] < 97 || input[i] > 122)) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

long long int get_integer_value(char *number) {
    register short unsigned int i = 0;
    while(number[i] != '\0') {
        if(number[i] < 48 || number[i] > 57) {
            return -1;
        }
        i++;
    }
    return atoi(number);
}

long long int power(long long int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power(base, --exponent);
}

int get_int_from_char(char value) {
    if(value == 45) return -1;
    if(value >= 48 && value <= 57) return value - 48;
    else return (value >= 65 && value <= 90) ? value - 55 : value - 87;
}

long long int baseN_to_10(char *number, long long int base) {
    register int i = 0;
    long long int result = 0;
    unsigned short int exponent = 0;
    int is_negative = 0;
    while(number[i] != '\0') i++;
    for(; i > 0; i--) {
        int aux = get_int_from_char(number[i - 1]);
        if (aux == -1) is_negative = 1;
        else
            result += aux * power(base, exponent++);
    }
    return result * (is_negative == 1 ? -1 : 1);
}

char* itoa(long long int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { 
        *result = '\0'; 
        return result; 
    }
    char* ptr = result, *ptr1 = result, tmp_char;
    long long int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void base10_to_N(long long int number, char* buffer, int base_n) {
    itoa(number, buffer, base_n);
}