#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    int dia;
    int mes;
    int ano;
};
typedef struct date Date;

struct employee {
    int id;
    char name[41];
    double income;
    Date dbirth;
    struct employee *next;
};
typedef struct employee Employee;

void imprimirFuncionarios(Employee *inicio) {
    Employee *aux = inicio;
    printf("\n--- Lista de Funcionários ---\n");
    while (aux != NULL) {
        printf("ID: %d\n", aux->id);
        printf("Nome: %s\n", aux->name);
        printf("Salário: %.2f\n", aux->income);
        printf("Data de nascimento: %02d/%02d/%04d\n\n",
               aux->dbirth.dia, aux->dbirth.mes, aux->dbirth.ano);
        aux = aux->next;
    }
}

void imprimirInverso(Employee *inicio) {
    if (inicio == NULL) return;
    imprimirInverso(inicio->next);
    printf("ID: %d | Nome: %s | Salário: %.2f | Nasc.: %02d/%02d/%04d\n",
           inicio->id, inicio->name, inicio->income,
           inicio->dbirth.dia, inicio->dbirth.mes, inicio->dbirth.ano);
}

void liberarLista(Employee *inicio) {
    Employee *aux = inicio;
    while (aux != NULL) {
        Employee *tmp = aux;
        aux = aux->next;
        free(tmp);
    }
}

int main() {
    Employee *first = NULL, *aux = NULL, *novo = NULL;

    printf("Digite os dados dos funcionários (id=0 encerra):\n");

    while (1) {
        novo = (Employee *)malloc(sizeof(Employee));
        if (novo == NULL) {
            printf("Erro de alocação!\n");
            return 1;
        }

        printf("\nID: ");
        scanf("%d", &novo->id);
        if (novo->id == 0) {
            free(novo);
            break;
        }

        printf("Nome: ");
        scanf(" %[^\n]", novo->name);

        printf("Salário: ");
        scanf("%lf", &novo->income);

        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &novo->dbirth.dia, &novo->dbirth.mes, &novo->dbirth.ano);

        novo->next = NULL;

        if (first == NULL) {
            first = novo;
            aux = novo;
        } else {
            aux->next = novo;
            aux = novo;
        }
    }

    imprimirFuncionarios(first);

    printf("\n--- Lista em ordem inversa ---\n");
    imprimirInverso(first);

    liberarLista(first);

    return 0;
}