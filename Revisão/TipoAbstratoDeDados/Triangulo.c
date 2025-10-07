#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
} Triangulo;

void setTria(Triangulo *t, int a, int b, int c) {
    t->a = a;
    t->b = b;
    t->c = c;
}

int isTriangle(Triangulo t) {
    if (t.a + t.b > t.c && 
        t.b + t.c > t.a && 
        t.a + t.c > t.b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Triangulo t1;

    setTria(&t1, 16, 20, 30);

    if (isTriangle(t1)) {
        printf("As medidas formam um triangulo.\n");
    } else {
        printf("As medidas NAO formam um triangulo.\n");
    }

    return 0;
}