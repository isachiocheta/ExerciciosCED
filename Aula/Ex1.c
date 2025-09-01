// recebe 2 numeros inteiros para multiplicacao e devolve o resultado, sem *
#include <stdio.h>

int multiplicacao(int a, int b) {
    int resultado = 0;
    for (int i = 0; i < b; i++) {
        resultado += a;
    }
    return resultado;
}

int main() {
    int a = 5;
    int b = 10;
    int resultado = multiplicacao(a, b);
    return 0;
}