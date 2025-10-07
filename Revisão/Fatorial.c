//Implemente uma função recursiva fatorial(n) que calcula o fatorial de n.

#include <stdio.h>

int fatorial(int n) {
    if (n == 0) {
        return 1;  // Caso base: 0! é 1
    } else {
        return n * fatorial(n - 1);  // n! = n * (n-1)!
    }
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("O fatorial de %d é: %d\n", numero, fatorial(numero));
    return 0;
}