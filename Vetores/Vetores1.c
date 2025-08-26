// Crie um programa que lê 5 valores inteiros, armazena-os em um vetor e, em seguida, mostre na tela os valores lidos.

#include <stdio.h>

int main() {
    int vetor[5] = {10, 25, 7, 42, 18};

    printf("Valores do vetor: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}