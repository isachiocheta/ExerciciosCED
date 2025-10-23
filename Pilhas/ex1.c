//Faça um programa que receba uma string, caractere por caractere
//Cada caractere é colocado em uma pilha
//No fim da entrada, esvazie a pilha imprimindo os caracteres armazenados
#include <stdio.h>
#include <string.h>

int main() {
    char pilha[100];
    int topo = -1;
    char texto[100];
    int i;

    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin);
    
    texto[strcspn(texto, "\n")] = '\0';

    for (i = 0; texto[i] != '\0'; i++) {
        topo++;
        pilha[topo] = texto[i];
    }

    printf("String invertida:\n");
    while (topo >= 0) {
        printf("%c", pilha[topo]);
        topo--;
    }

    printf("\n");
    return 0;
}