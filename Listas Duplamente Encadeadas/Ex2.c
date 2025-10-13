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

Funcionario* inserirNoFinal(Funcionario *lista, Funcionario *novo) {
    if (lista == NULL) {
        return novo;
    }
    Funcionario *p = lista;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = novo;
    novo->prev = p;
    return lista;
}

void imprimirLista(Funcionario *lista) {
    Funcionario *p = lista;
    printf("\n--- Lista de Funcionários ---\n");
    while (p != NULL) {
        printf("ID: %d\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("Salário: %.2f\n", p->salario);
        printf("Nascimento: %02d/%02d/%04d\n", 
               p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
        p = p->next;
    }
}

Funcionario* deletarFuncionario(Funcionario *lista, int id) {
    Funcionario *p = lista;
    while (p != NULL && p->id != id) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Funcionário com ID %d não encontrado.\n", id);
        return lista;
    }

    if (p->prev == NULL) {
        lista = p->next;
        if (lista != NULL) {
            lista->prev = NULL;
        }
    } 
    else if (p->next == NULL) {
        p->prev->next = NULL;
    } 
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    free(p);
    printf("Funcionário com ID %d deletado.\n", id);
    return lista;
}

int main() {
    Funcionario *lista = NULL;
    int n, id, dia, mes, ano;
    char nome[41];
    double salario;

    printf("Digite o número de funcionários: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("\n--- Funcionário %d ---\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        getchar();
        printf("Nome: ");
        fgets(nome, 41, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        printf("Salário: ");
        scanf("%lf", &salario);
        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &dia, &mes, &ano);
        getchar();

        Funcionario *novo = criarFuncionario(id, nome, salario, dia, mes, ano);
        lista = inserirNoFinal(lista, novo);
    }

    imprimirLista(lista);

    int idDel;
    printf("\nDigite o ID do funcionário que deseja deletar: ");
    scanf("%d", &idDel);
    lista = deletarFuncionario(lista, idDel);

    imprimirLista(lista);

    return 0;
}
