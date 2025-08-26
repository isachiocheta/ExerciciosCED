// Crie uma função somaImpares(), que receba dois inteiros (inicio, fim) e um ponteiro. A função deve somar os ímpares do intervalo.

#include <stdio.h>

void somaImpares(int inicio, int fim, int *soma) {
    *soma = 0;
    for (int i = inicio; i <= fim; i++) {
        if (i % 2 != 0) {
            *soma += i;
        }
    }
}

int main() {
    int soma;
    somaImpares(5, 9, &soma);
    printf("Soma dos impares entre 5 e 9: %d\n", soma);
    return 0;
}