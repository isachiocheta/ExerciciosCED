#include <stdio.h>
#include <stdlib.h>

struct tdoub {
    char c;
    struct tdoub *next, *prev;
};

struct tsentinel {
    struct tdoub *head, *tail;
};
typedef struct tdoub doub;
typedef struct tsentinel sentinel;

void insertSortList(sentinel *s, char cr){
    doub *d; 
    d=(doub *)malloc(sizeof(doub));
    //2
    d->c=cr;
    d->prev=NULL;
    d->next=NULL;
    //procuro a posição
    if (s->head->c > d->c){ //lista vazia
        s->head=d;
        s->tail=d;
        return;
    }

    if (s->head==NULL){ 
        s->head->prev=d;
        d->next=s->head;
        s->head=d;
        return;
    }
    //depois do ultimo
    if (s->tail->c < d->c){
        s->tail->next=d;
        d->prev=s->tail;
        s->tail=d;
        return;
    }
    //no meio
    doub *aux;
    for (aux=s->head;aux!=NULL;aux=aux->next){
        if (aux->c > d->c) break;
    }
    //inserir no meio
    d->next=aux;
    d->prev=aux->prev;
    aux->prev->next=d;
    aux->prev=d;
    return;
}

void insertList(sentinel *s, char cr){
    doub *d; //1 - inserir no fim
    d=(doub *)malloc(sizeof(doub));
    //2
    d->c=cr;
    d->prev=NULL;
    d->next=NULL;
    //3
    if (s->head==NULL){
        s->head=d;
        s->tail=d;
    } else {
        s->tail->next=d;
        d->prev=s->tail;
        s->tail=d;
    }
}

void printList(sentinel *s){
    doub *aux;
    for (aux=s->head;aux!=NULL;aux=aux->next){
        printf("%c ",aux->c);
    }
}

void printListInverse(sentinel *s){
    doub *aux;
    for (aux=s->tail;aux!=NULL;aux=aux->prev){
        printf("%c ",aux->c);
    }
}

void deleteList(sentinel *s, char cr){
    doub *aux;
    //primeiro buscar o elemento
    for (aux=s->head;aux!=NULL;aux=aux->next){
        if (aux->c==cr) 
        break;
    }
    //excluir o elemento
    if (aux==NULL) return; //nao encontrou
    if(s->head==s->tail){ //1 elemento
        free(aux);
        s->head=NULL;
        s->tail=NULL;
        return;
    }
    if (aux==s->head){ //primeiro
        s->head=aux->next;
        s->head->prev=NULL;
        free(aux);
    }
    if (aux==s->tail) {
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

doub *SearchList(sentinel *s, char cr){
    doub *aux;
    for (aux=s->head;aux!=NULL;aux=aux->next){
        if (aux->c==cr) break;
    }
    return aux;
}

int main(){
    sentinel s={NULL,NULL};
    int op=1;
    char caracter;
    while(op!=0){
        printf("1 - Inserir no fim\n2 - Inclui Ordem \n3 - Excluir \n4 - Print \n5 - Print Inverso \n6 - Consultar \n0 - Sair\n");
        scanf("%d",&op); getchar();

        switch(op){
            case 1: 
            printf("Digite um caracter: ");
            scanf(" %c",&caracter);
            insertList(&s,caracter);
            break;

            case 2:
            printf("Digite um caracter: ");
            scanf(" %c",&caracter);
            insertSortList(&s,caracter);
            break;

            case 3: //EXCLUI
            printf("Digite um caracter a ser excluido: ");
            scanf(" %c",&caracter);
            deleteList(&s,caracter);
            break;

            case 4:
            printList(&s);
            break;

            case 5: 
            printListInverse(&s);
            break;

            case 6:
            printf("Digite um caracter a ser consultado: ");
            scanf(" %c",&caracter);
            doub *d;
            d=SearchList(&s,caracter);
            if (d!=NULL) printf("Caracter %c encontrado\n",d->c);
            else printf("Caracter %c nao encontrado\n",caracter); 
            break;
        }
    }
    return 0;
}