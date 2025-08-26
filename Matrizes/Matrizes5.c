// Leia uma matriz 4 x 4 e imprima a triangular superior.

#include <stdio.h>

int main() {
    int m[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d", &m[i][j]);

    printf("Triangular superior:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j>=i) printf("%d ", m[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}