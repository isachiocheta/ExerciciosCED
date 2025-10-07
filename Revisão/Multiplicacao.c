//Implemente uma função recursiva multiplica(a, b) que multiplica dois números inteiros usando apenas somas e subtrações.

#include <stdio.h>

int multiplica(int a, int b) {
    if (b == 0) {
        return 0;  // Caso base: qualquer número multiplicado por 0 é 0
    } else if (b > 0) {
        return a + multiplica(a, b - 1);  // Soma 'a' repetidamente 'b' vezes
    } else {
        return -multiplica(a, -b);  // Se 'b' for negativo, inverte o sinal
    }
}

int main() {
    int num1, num2;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &num1, &num2);
    printf("A multiplicacao de %d e %d = %d\n", num1, num2, multiplica(num1, num2));
    return 0;
}