//insere, consulta, lista e sai de temperaturas com float em uma lista encadeada
#include <stdio.h>
#include <stdlib.h>

struct ttemp {
    float temp;
    struct ttemp *next;
};typedef struct ttemp temperatura;

void inserirTemp(temperatura *f) {
   temperatura *p;
   p = (temperatura *)malloc(sizeof(temperatura));
   printf("Insere temperatura: %.2f\n", p->temp);
   scanf("%f", &p->temp);
   p->next=NULL;
   if (p  == NULL) {
       temperatura *aux;
       for(aux=f; aux->next != NULL; aux=aux->next); //procura o ultimo elemento
       aux->next = p;
       return f;
   }
}

void listar(temperatura *inicio) {
    temperatura *aux = inicio;
    printf("\n Lista de Temperaturas\n");
    while (aux != NULL) {
        printf("%.2f\n", aux->temp);
        aux = aux->next;
    }
}


int main() {
    temperatura *inicio = NULL;
    int opcao;
    float valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir temperatura\n");
        printf("2. Consultar temperatura\n");
        printf("3. Listar temperaturas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a temperatura a ser inserida: ");
                scanf("%f", &valor);
                inserir(&inicio, valor);
                break;
            case 2:
                printf("Digite a temperatura a ser consultada: ");
                scanf("%f", &valor);
                if (consultar(inicio, valor)) {
                    printf("Temperatura %.2f encontrada na lista.\n", valor);
                } else {
                    printf("Temperatura %.2f nao encontrada na lista.\n", valor);
                }
                break;
            case 3:
                listar(inicio);
                break;
            case 0:
                printf("Saindo\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    temperatura *aux = inicio;
    while (aux != NULL) {
        temperatura *tmp = aux;
        aux = aux->next;
        free(tmp);
    }

    return 0;
}