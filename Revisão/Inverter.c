//Implemente uma função recursiva inverter(n) que retorna o número n invertido.
#include <stdio.h>

int inverter(int n) {
    if (n < 10) {
        return n;  // Caso base: quando n for um único dígito, retorna n
    } else {
        int digito = n % 10;  // Obtém o último dígito
        int resto = n / 10;   // Remove o último dígito
        int num_digitos = 0;
        int temp = resto;
        while (temp > 0) {
            temp /= 10;
            num_digitos++;
        }
        return digito * pow(10, num_digitos) + inverter(resto);  // Concatena o último dígito invertido com o resto invertido
    }
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("Numero invertido: %d\n", inverter(numero));
    return 0;
}