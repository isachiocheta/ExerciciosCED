#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int value;
    struct tree *left;
    struct tree *right;
} tree;

tree *insertNode(tree *root, int v){
    tree *t = malloc(sizeof(tree));
    if (!t) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    t->value = v;
    t->left = NULL;
    t->right = NULL;

    if (root == NULL) return t;

    tree *taux = root;
    tree *parent = NULL;
    while (taux != NULL) {
        parent = taux;
        if (v < taux->value) {
            taux = taux->left;
        } else if (v > taux->value) {
            taux = taux->right;
        } else {
            free(t);
            return root;
        }
    }

    if (v < parent->value)
        parent->left = t;
    else
        parent->right = t;

    return root;
}

tree *searchNode(tree *r, int v){
    tree *taux = r;
    while (taux != NULL){
        if (v == taux->value) return taux;
        if (v < taux->value)
            taux = taux->left;
        else
            taux = taux->right;
    }
    return NULL;
}

int main(){
    tree *root = NULL;
    int op = 1, val;
    tree *res;
    while (op != 0){
        printf("1 - Inserir \n2 - Buscar \n0 - Sair\n");
        if (scanf("%d",&op) != 1) break;
        if (op == 1){
            printf("Valor a inserir: ");
            if (scanf("%d",&val) != 1) break;
            root = insertNode(root, val);
        }
        if (op == 2){
            printf("Valor a consultar: ");
            if (scanf("%d",&val) != 1) break;
            res = searchNode(root, val);
            if (res == NULL){
                printf("Valor nao encontrado\n");
            } else {
                printf("Valor %d encontrado\n", res->value);
            }
        }
    }
    return 0;
}