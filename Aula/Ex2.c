// Implemente uma função recursiva que, dados dois números inteiros base (b) e expoente (e), calcula o valor de be (e≥0), se e==0 entao 1, se e==1 entao b, caso contrario b*b
#include <stdio.h>

int potencia(int b, int e) {
    if (e == 0) {
        return 1;
    } else if (e == 1) {
        return b;
    } else {
        return b * potencia(b, e - 1);
    }
}