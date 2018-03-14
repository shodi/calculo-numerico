#include <stdio.h>
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
    baseN = atoi(argv[2]);
    baseM = atoi(argv[3]);
    exit(0);
}