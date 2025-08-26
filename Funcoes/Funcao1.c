//Faça uma função que lê dois inteiros e apresenta a diferença entre os dois.

#include <stdio.h>

int diferenca(int *a, int *b) {
    return *a - *b;
}

int main() {
    int x, y;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &x, &y);

    printf("A diferenca entre %d e %d eh: %d\n", x, y, diferenca(&x, &y));
    return 0;
}