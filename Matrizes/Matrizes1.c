// Leia uma matriz 4 x 4 (de inteiros) e imprima a diagonal principal.

#include <stdio.h>

int main() {
    int m[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d", &m[i][j]);

    printf("Diagonal principal:\n");
    for(int i=0;i<4;i++)
        printf("%d ", m[i][i]);

    return 0;
}