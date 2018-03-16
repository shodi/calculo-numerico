#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char **argv) {
    char *representation;
    int baseN, baseM;
    if (argc != 4) {
        printf("Erro nos valores inputados\n");
        exit(1);
    }
    representation = argv[1];
    if(!check_representation(representation)) {
        printf("Representacao do valor invalida\n");
        exit(1);
    }
    baseN = get_integer_value(argv[2]);
    baseM = get_integer_value(argv[3]);
    if(baseN == -1 || baseM == -1) {
        printf("Base inesistente\n");
        exit(1);
    }
    printf("valor na base decimal: %d\n", baseN_to_10(representation, baseN));
    exit(0);
}