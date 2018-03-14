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
    short unsigned int i = 0;
    while(number[i] != '\0') {
        if(number[i] < 48 || number[i] > 57) {
            return -1;
        }
        i++;
    }
    return atoi(number);
}