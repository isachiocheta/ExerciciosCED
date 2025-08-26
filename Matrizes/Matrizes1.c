// Leia uma matriz 4 x 4 (de inteiros) e imprima a diagonal principal.

#include <stdio.h>

int main() {
    int matriz[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            scanf("%d", &matriz[i][j]);

    printf("Numeros digitados na diagonal principal:\n");
    for(int i=0; i<4; i++)
        printf("%d ", matriz[i][i]);
    return 0;
}