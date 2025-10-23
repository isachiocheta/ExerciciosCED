#include <stdio.h>

int main() {
    char fila[100];
    int inicio = 0;
    int fim = 0;
    char caractere;

    printf("Digite uma string (digite '.' para encerrar):\n");

    while (1) {
        scanf("%c", &caractere);

        if (caractere == '.') 
            break;

        fila[fim] = caractere;
        fim++;
    }

    printf("\nString armazenada na fila:\n");

    while (inicio < fim) {
        printf("%c", fila[inicio]);
        inicio++;
    }

    printf("\n");
    return 0;
}