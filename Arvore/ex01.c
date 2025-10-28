#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} tree;

tree *insertNode(tree *root, int v){

 tree *t, *taux, *tauxant;
 char dir;
 t=(tree *)malloc(sizeof(tree));
 t->value=v;
 t->left=NULL;
 t->right=NULL;
    if (root==NULL) return t;
    taux=root;
    while(taux!=NULL){
        tauxant=taux;
        if (v > taux->value){
            taux=taux->left;
            dir='R';
        } else {
            taux=taux->right;
            dir='L';
        }
    }
    if(dir=='R'){
        tauxant->left=t;
    } else {
        tauxant->right=t;
    }
    return root;
}

tree *searchNode(tree *r, int v){
    tree *taux=r;
    while(taux!=NULL){
        if(v==taux->value) return taux;
        if(v>taux->value){
            taux=taux->left;
        } else {
            taux=taux->right;
        }
    }
    return taux;
}

int main(){
    tree *root=NULL;
   root=insertNode(root,50);
   root=insertNode(root,30);    
   root=insertNode(root,70);    
   tree *node= searchNode (root,30);
   if (node!=NULL){
       printf ("Elemento %d encontrado\n", node->value);
   }
   return 0;
}