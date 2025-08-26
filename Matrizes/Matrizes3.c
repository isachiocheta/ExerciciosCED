// Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos. Imprima, ao final, a matriz obtida.

#include <stdio.h>

int main() {
    int m[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j) m[i][j]=1;
            else m[i][j]=0;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}