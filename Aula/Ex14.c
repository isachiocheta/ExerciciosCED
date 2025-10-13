//insere, consulta, lista e sai de temperaturas com float em uma lista encadeada com exclusao de um elemento da lista
#include <stdio.h>
#include <stdlib.h>

struct ttemp {
    float temp;
    struct ttemp *next;
};
typedef struct ttemp temperatura;

temperatura *insereTemp(temperatura *f) {
   temperatura *p;
   p = (temperatura *)malloc(sizeof(temperatura));
   printf("Insere temperatura: ");
   scanf("%f", &p->temp);
   printf("Temperatura inserida: %.2f\n", p->temp);
   p->next=NULL;
   if (p  == NULL) {
       temperatura *aux;
       for(aux=f; aux->next != NULL; aux=aux->next); //procura o ultimo elemento da lista
       aux->next = p;
       return f;
   }
    return p; 
}

temperatura *printTemp (temperatura *f, float t) {
    temperatura *aux;
    for(aux=f; aux != NULL; aux=aux->next) {
        if (aux->temp==t) { //preparo a lista para ser percorrida
            return aux;
        }
    }
    return NULL;
}

void printAllTemp(temperatura *f) {
    temperatura *aux;
    for(aux=f; aux != NULL; aux=aux->next) { //colocar na cola oficial
        printf("Temperatura: %.2f\n", aux->temp);
    }
}

void freeAll(temperatura *f) {
   temperatura *aux1, *aux2;
   aux1 = f;
   while (aux1 != NULL) {
       aux2 = aux1;
       aux1 = aux1->next;
       free(aux2);
   }
}

temperatura *delTemp(temperatura *f, float t) {
    temperatura *aux;
    aux = printTemp(f, t);
    if (f == NULL) {
        printf("Lista vazia, nada a excluir.\n");
        return f;
    }
    if (f->temp == t) {
        aux = f;
        f = f->next;
        free(aux);
        return f;
    }
    temperatura *aux2;
    aux=f;
    while (aux!=NULL) {
        if (aux->temp == t) break;
        aux2=aux;
        aux=aux->next;
    }
   if (aux == NULL) {
       printf("Temperatura nao encontrada na lista.\n");
       return f;
   }
    if (aux->next == NULL) {
       aux2->next=NULL;
       free(aux);
       return f;
    }
    aux2->next=aux->next;
    free(aux);
   return f;
}
//como fazer uma inserção no meio da lista
int main() {
    temperatura *first, *aux;
    float t;
    int op=1;

    while (op != 0) {
        printf("\nMenu:\n1. Inserir temperatura\n2. Consultar temperatura\n3. Listar temperaturas\n4. Excluir \n0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        switch(op) {
            case 1: first=insereTemp(first);
                break;
            case 2: 
            printf("Temperatura: ");
            scanf("%f", &t);
            aux = printTemp(first, t);
            if (aux != NULL) {
                printf("Temperatura %.2f encontrada na lista.\n", t);
            } else {
                printf("Temperatura %.2f nao encontrada na lista.\n", t);
            }
                break;
            case 3:
                printAllTemp(first);
                break;
                case 4:
                printf("Temperatura a ser excluida: ");
                scanf("%f", &t);
                first = delTemp(first, t);
                break;
        }
    }
    freeAll(first);
    return 0;
}