// Aula/Ex09.c
// Crie uma lista encadeada de inteiros, alocando dinamicamente os nós
#include <stdio.h>
#include <stdlib.h>

struct tint {
    int value;
    struct tint *next;
};

typedef struct tint Tint;

int main() {
    Tint *p, *aux, *first = NULL;
    int i = 0;

    while (i < 5) {
        i++;
        p = (Tint *) malloc(sizeof(Tint));
        if (p == NULL) {
            printf("Erro de alocação!\n");
            return 1;
        }
        p->value = i;
        p->next = NULL;

        if (first == NULL) {
            first = p;
            aux = p;
        } else {
            aux->next = p;
            aux = p;
        }
    }

    printf("Valores na lista:\n");
    for (aux = first; aux != NULL; aux = aux->next) {
        printf("%d\n", aux->value);
    }

    aux = first;
    while (aux != NULL) {
        Tint *tmp = aux;
        aux = aux->next;
        free(tmp);
    }

    return 0;
}
