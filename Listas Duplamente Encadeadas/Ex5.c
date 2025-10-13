#include <stdio.h>
#include <stdlib.h>

struct tdouble{
    float value;
    struct tdouble *next, *prev;
};
typedef struct tdouble doub;

struct tsent{
    doub *head, *tail;
};
typedef struct tsent sentinela;

void delValue(sentinela *s, int key){
    doub *aux=s->head;

    if (aux==NULL) {
        printf("Lista vazia\n");
        return;
    }
    if (aux->value==key){
        if (aux->next==NULL){
            free(aux);
            s->head=NULL;
            s->tail=NULL;
            return;
        }
        s->head=aux->next;
        s->head->prev=NULL;
        free(aux);
        return;
    }
    while (aux!=NULL && aux->value!=key) {
        aux=aux->next;
    }
    if (aux==NULL) {
        return;
    }
    if (aux->next==NULL){
        s->tail=aux->prev;
        s->tail->next=NULL;
        free(aux);
        return;
    }
    aux->prev->next=aux->next;
    aux->next->prev=aux->prev;
    free(aux);
    return;
}

void setValue (sentinela*s, float v){
    doub *p;
    p=(doub *)malloc(sizeof(doub)); //passo 1
    p->value=v;//passo 2
    p->next=NULL;//passo 2
    p->prev=NULL;//passo 2
    
    //passo 3 - encadear
    if (s->head==NULL){
        s->head=p;
        s->tail=p;
        return;
    }
    s->tail->next=p;
    p->prev=s->tail;p->tail=p;
    return;
}

int main(){
    sentinela sent = {NULL, NULL};
    for (int i=0; i<25;i++){
        setValue(&sent,i/3);
    }
    
    for (doub *aux=sent.head; aux!=NULL; aux=aux->next){
    printf("%f\n", aux->value);
    return 0;
    }
    
    //imprime o inverso da lista
    for (doub *aux=sent.tail;aux!=NULL; aux=aux->prev);
    printf("%d\n", aux->value);
}
