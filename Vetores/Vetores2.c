// Faça uma função que receba um vetor e o seu tamanho como parâmetro e imprima o maior e o menor elemento do vetor. 
// Esta função é do tipo void pois não retorna nenhum valor

#include <stdio.h>

void maiorMenor(int vetor[], int tamanho) {
    int maior = vetor[0];
    int menor = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
}

int main() {
    int vetor[5] = {10, 25, 7, 42, 18};

    printf("Valores do vetor: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    maiorMenor(vetor, 5);
    return 0;
}