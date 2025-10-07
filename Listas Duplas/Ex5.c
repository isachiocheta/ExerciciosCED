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
    doub *p=s->head;
    if (p==NULL) return;
    if (p->next==NULL){
        free(p);
        s->head=NULL;
        s->tail=NULL;
        return;
    }
    s->head=p->next;
    s->head->prev=NULL;
    free(p);
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
