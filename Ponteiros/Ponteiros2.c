//Crie uma função chamada maior(), que receba dois inteiros e um ponteiro para um inteiro. A função deve armazenar o valor do maior no endereço do ponteiro.

#include <stdio.h>

void maior(int a, int b, int *resultado) {
    if (a > b) {
        *resultado = a;
    } else {
        *resultado = b;
    }
}

int main() {
    int x = 15, y = 30, m;
    maior(x, y, &m);
    printf("O maior entre %d e %d eh: %d\n", x, y, m);
    return 0;
}