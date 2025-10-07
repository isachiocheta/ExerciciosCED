//Implemente uma função recursiva eh_potencia_de_2(n) que retorna 1 se n for potência de 2, ou 0 caso contrário.
#include <stdio.h>

int eh_potencia_de_2(int n) {
    if (n < 1) {
        return 0;  // Números menores que 1 não são potências de 2
    } else if (n == 1) {
        return 1;  // 2^0 = 1 é uma potência de 2
    } else if (n % 2 != 0) {
        return 0;  // Números ímpares maiores que 1 não são potências de 2
    } else {
        return eh_potencia_de_2(n / 2);  // Divide por 2 e verifica recursivamente
    }
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    if (eh_potencia_de_2(numero)) {
        printf("%d é potência de 2.\n", numero);
    } else {
        printf("%d não é potência de 2.\n", numero);
    }
    return 0;
}