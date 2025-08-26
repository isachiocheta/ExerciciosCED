// Leia uma matriz 4 x 4 e escreva a localização (linha e coluna) do maior valor.

#include <stdio.h>

int main() {
    int m[4][4], maior, linha=0, coluna=0;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) {
            scanf("%d", &m[i][j]);
            if(i==0 && j==0 || m[i][j] > maior) {
                maior = m[i][j];
                linha = i;
                coluna = j;
            }
        }

    printf("Maior valor = %d na posicao [%d][%d]\n", maior, linha, coluna);
    return 0;
}