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

Funcionario* criarFuncionario(int id, const char* nome, double salario, int dia, int mes, int ano) {
    Funcionario *novo = (Funcionario*) malloc(sizeof(Funcionario));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
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

Funcionario* inserirNoInicio(Funcionario *lista, Funcionario *novo) {
    if (lista != NULL) {
        novo->next = lista;
        lista->prev = novo;
    }
    return novo;
}

void imprimirLista(Funcionario *lista) {
    Funcionario *p = lista;
    while (p != NULL) {
        printf("ID: %d\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("Salário: %.2f\n", p->salario);
        printf("Nascimento: %02d/%02d/%04d\n", 
               p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
        p = p->next;
    }
}

int main() {
    Funcionario *lista = NULL;

    Funcionario *f1 = criarFuncionario(1, "Ana Silva", 2500.00, 15, 4, 1990);
    lista = f1;

    Funcionario *f2 = criarFuncionario(2, "João Pereira", 3200.50, 22, 11, 1985);
    lista = inserirNoInicio(lista, f2);

    imprimirLista(lista);

    return 0;
}
