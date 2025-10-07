#include <stdio.h>

int lg2(int n) {
    if (n < 2) {
        return 0;  // Caso base: quando n for menor que 2, para a recursão
    } else {
        return 1 + lg2(n / 2);  // Divide por 2 e conta +1
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("Log base 2 (parte inteira) de %d = %d\n", numero, lg2(numero));

    return 0;
}

