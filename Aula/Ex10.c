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

int main() {
    Employee *first = NULL, *aux = NULL, *novo = NULL;

    first = (Employee *)malloc(sizeof(Employee));
    if (first == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }
    first->id = 1;
    strcpy(first->name, "Alice");
    first->income = 3000.50;
    first->dbirth.dia = 10;
    first->dbirth.mes = 5;
    first->dbirth.ano = 1998;
    first->next = NULL;
    aux = first;

    novo = (Employee *)malloc(sizeof(Employee));
    if (novo == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }
    novo->id = 2;
    strcpy(novo->name, "Bruno");
    novo->income = 4200.00;
    novo->dbirth.dia = 20;
    novo->dbirth.mes = 7;
    novo->dbirth.ano = 1995;
    novo->next = NULL;

    aux->next = novo;
    aux = novo;

    imprimirFuncionarios(first);

    aux = first;
    while (aux != NULL) {
        Employee *temp = aux;
        aux = aux->next;
        free(temp);
    }

    return 0;
}
