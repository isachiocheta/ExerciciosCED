#include <stdio.h>
#include <stdlib.h>

typedef struct listaint {
    int valor;
    struct listaint *prev;
    struct listaint *next;
} ListaInt;

ListaInt* constroiLista(int n, int *v) {
    if (n <= 0) return NULL;

    ListaInt *inicio = NULL;
    ListaInt *atual = NULL;

    for (int i = 0; i < n; i++) {
        ListaInt *novo = (ListaInt*) malloc(sizeof(ListaInt));
        if (novo == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        novo->valor = v[i];
        novo->prev = NULL;
        novo->next = NULL;

        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->next = novo;
            novo->prev = atual;
            atual = novo;
        }
    }

    return inicio;
}

void imprimeLista(ListaInt *lista) {
    ListaInt *p = lista;
    printf("\nLista Encadeada: ");
    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int v[] = {1, 21, 4, 6};
    int n = sizeof(v)/sizeof(v[0]);

    ListaInt *lista = constroiLista(n, v);

    imprimeLista(lista);

    return 0;
}