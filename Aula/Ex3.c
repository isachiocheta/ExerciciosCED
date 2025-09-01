// informa o resto da divisao sem usar %
#include <stdio.h>

int resto(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

int main() {
    int a = 10;
    int b = 3;
    int resultado = resto(a, b);
    return 0;
}