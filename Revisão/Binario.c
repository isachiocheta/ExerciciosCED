//Implemente uma função recursiva decimal_para_binario(n) que imprime o número binário correspondente.

#include <stdio.h>

int decimal_para_binario(int n) {
    if (n == 0) {
        return 0;  // Caso base: quando n for 0, para a recursão
    } else {
        return (n % 2) + 10 * decimal_para_binario(n / 2);  // Concatena o bit menos significativo com o resultado da chamada recursiva
    }
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("O numero %d em binario é: %d\n", numero, decimal_para_binario(numero));
    return 0;
}