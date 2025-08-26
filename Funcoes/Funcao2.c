//Crie uma função que receba 2 números e retorne o maior valor entre eles (se forem iguais, retorna o segundo).

#include <stdio.h>

int maiorValor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}