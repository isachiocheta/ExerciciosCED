// recebe a base e o expoente e devolve o resultado, sem printf e scanf
#include <stdio.h>

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

int main() {
    int base = 2;
    int expoente = 3;
    int resultado = potencia(base, expoente);
    return 0;
}