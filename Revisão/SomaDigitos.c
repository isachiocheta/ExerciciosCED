#include <stdio.h>

int soma_digitos(int n) {
    if (n == 0) {
        return 0;  // Caso base: quando n for 0, para a recursão
    } else {
        return (n % 10) + soma_digitos(n / 10);  // Soma o último dígito e chama recursivamente
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("A soma dos dígitos de %d = %d\n", numero, soma_digitos(numero));

    return 0;
}