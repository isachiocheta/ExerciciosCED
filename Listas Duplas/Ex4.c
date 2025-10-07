#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

struct funcionario {
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *prev;
    struct funcionario *next;
};
typedef struct funcionario Funcionario;

void buscarFuncionario(Funcionario *lista, int id) {
    Funcionario *p = lista;
    while (p != NULL) {
        if (p->id == id) {
            printf("\nFuncionário encontrado:\n");
            printf("ID: %d\n", p->id);
            printf("Nome: %s\n", p->nome);
            printf("Salário: %.2f\n", p->salario);
            printf("Nascimento: %02d/%02d/%04d\n",
                   p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
            return;
        }
        p = p->next;
    }

    printf("\nFuncionário com ID %d não encontrado.\n", id);
}

Funcionario* criarFuncionario(int id, const char* nome, double salario, int dia, int mes, int ano) {
    Funcionario *novo = (Funcionario*) malloc(sizeof(Funcionario));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->salario = salario;
    novo->nascimento.dia = dia;
    novo->nascimento.mes = mes;
    novo->nascimento.ano = ano;
    novo->prev = NULL;
    novo->next = NULL;
    return novo;
}

Funcionario* inserirNoFinal(Funcionario *lista, Funcionario *novo) {
    if (lista == NULL) return novo;
    Funcionario *p = lista;
    while (p->next != NULL) p = p->next;
    p->next = novo;
    novo->prev = p;
    return lista;
}

int main() {
    Funcionario *lista = NULL;

    lista = inserirNoFinal(lista, criarFuncionario(1, "Ana", 2500.0, 10, 3, 1995));
    lista = inserirNoFinal(lista, criarFuncionario(2, "João", 3200.0, 22, 7, 1988));
    lista = inserirNoFinal(lista, criarFuncionario(3, "Carla", 2800.0, 5, 11, 1992));

    int idBusca;
    printf("Digite o ID do funcionário que deseja buscar: ");
    scanf("%d", &idBusca);

    buscarFuncionario(lista, idBusca);

    return 0;
}
