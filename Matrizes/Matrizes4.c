// Faça um programa que preenche uma matriz 5 x 5 com o produto da posição da linha e da coluna de cada elemento. Em seguida, imprima.

#include <stdio.h>

int main() {
    int m[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            m[i][j] = i * j;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}