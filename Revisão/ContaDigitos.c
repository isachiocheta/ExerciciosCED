//Implemente uma função recursiva conta_digitos(n) que retorna o número de dígitos de n.

#include <stdio.h>

int conta_digitos(int n) {
    if (n == 0) {
        return 0;  // Caso base: quando n for 0, para a recursão
    } else {
        return 1 + conta_digitos(n / 10);  // Conta o último dígito e chama recursivamente
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("O numero de digitos de %d = %d\n", numero, conta_digitos(numero));

    return 0;
}