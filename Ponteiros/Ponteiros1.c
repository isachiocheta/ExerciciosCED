// Escreva uma função chamada troca(), que receba dois ponteiros para inteiros e troca os valores entre eles.
//Exemplo de chamada: troca(&a, &b)

 #include <stdio.h>

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 10, b = 20;
    printf("Antes da troca: a = %d, b = %d\n", a, b);

    troca(&a, &b);

    printf("Depois da troca: a = %d, b = %d\n", a, b);
    return 0;
}