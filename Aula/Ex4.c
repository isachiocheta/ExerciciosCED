// recebe 2 numeros inteiros para multiplicacao e devolve o resultado, sem *, recebe a base e o expoente e devolve o resultado, informa o resto da divisao sem usar %
//sem printf 
#include <stdio.h>

int multiplicacao(int a, int b) {
    int resultado = 0;
    for (int i = 0; i < b; i++) {
        resultado += a;
    }
    return resultado;
}

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
       resultado = multiplicacao(resultado, base);
    }
    return resultado;
}

int resto_divisao(int a, int b) {
    while (a >= b) {
        a = a - b;
    }
    return a;
}

int main() {
    int a = 5;
    int b = 10;
    int resultado = multiplicacao(a, b);
    int resultado_potencia = potencia(a, b);
    int resultado_resto = resto_divisao(a, b);  
    return 0;
}