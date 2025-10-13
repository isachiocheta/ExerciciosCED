#include <stdio.h>
#include <stdlib.h>

//Aula 07/10

struct tdouble {
	int value;
	struct tdouble *next, *prev;
};
typedef struct tdouble doub;

struct tsent {
	doub *head, *tail;
};
typedef struct tsent sentinela;

void delValue (sentinela *s, int key){
    doub *p=s->head;
    if (p==NULL) {
        printf("Lista vazia\n");
        return;
    }
    if (p->value==key){
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
    while (p!=NULL && p->value!=key) {
        p=p->next;
    }
    if (aux==NULL) {
    return;
    }
    if (p->next==NULL){
        s->tail=p->prev;
        s->tail->next=NULL;
        free(p);
        return;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    return;
}

void setValue (sentinela *s, int v)
{
	doub *p;
	p=(doub *)malloc(sizeof(doub)); // passo 1
	p->value=v;   // passo 2
	p->next=NULL; // passo 2
	p->prev=NULL; // passo 2
	//passo 3 - encadear
	if (s->head==NULL)
	{
		s->head=p;
		s->tail=p;
		return;
	}
	s->tail->next=p;   
	p->prev=s->tail;
	s->tail=p;
	return;
}

int main()
{
	sentinela sent={NULL,NULL};
	for (int i=10;i<25;i++)  setValue(&sent,i);
	for (doub *aux=sent.head;aux!=NULL;aux=aux->next)
	   printf("%d\n",aux->value);
	printf("========\n");
	for (doub *aux=sent.tail;aux!=NULL;aux=aux->prev)
	   printf("%d\n",aux->value);
	///
	  
	return 0;
}