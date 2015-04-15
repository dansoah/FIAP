#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *ant;
    struct no *prox;
} Lista;

void addBefore(Lista **l);
void addAfter(Lista *l);
Lista *merge(Lista *l1, Lista *l2);
int length(Lista *l);

int main(void){
    Lista *l1 = NULL;
    Lista *l2 = NULL;
    char opcao = ' ';
    int value, total;

    do{
        system("CLS");
    
        printf("Menu:\n\n");
        printf("(1) Adiciona elemento no inicio da lista 1\n");
        printf("(2) Adiciona elemento no final da lista 1\n");
        printf("(3) Adiciona elemento no inicio da lista 2\n");
        printf("(4) Adiciona elemento no final da lista 2\n");
        printf("(5) Concatenar na lista 1\n");
        printf("(6) Concatenar na lista 2\n");
        printf("(7) Exibir\n");
        printf("(*) Sair\n\n\n");
        
        scanf("%d", &opcao);
    
        system("CLS");
    
        switch(opcao){
                      
            case 1:
                addBefore(&l1);
                break;
            case 2:
                addAfter(l1);
                break;
            case 3:
                addBefore(&l2);
                break;
            case 4:
                addAfter(l2);
                break;
            case 5:
                l1 = merge(l1, l2);
                l2 = NULL;
                break;
            case 6:
                l2 = merge(l1, l2);
                l1 = NULL;
                break;
            case 7:
                total = length(l1);
                printf("Lista 1: %d\n", total);
    
                total = length(l2);
                printf("Lista 2: %d\n\n", total);
                
                break;
                
        }
        system("PAUSE");
    }while(opcao < 8);


}

void addBefore(Lista **l){
    Lista *aux = malloc(sizeof(Lista));
    Lista *atual = *l;

    printf("\nValor: ");
    scanf("%d", &aux->info);

    if(atual == NULL){
        aux->prox = NULL;
        aux->ant = NULL;
    }else{
        aux->prox = atual;
        aux->ant = NULL;
        atual->ant = aux;
    }

    *l = aux;
}

void addAfter(Lista *l){
    Lista *aux = malloc(sizeof(Lista));
    Lista *atual = l;

    printf("\nValor: ");
    scanf("%d", &aux->info);

    if(atual == NULL){
        aux->prox = NULL;
        aux->ant = NULL;
    }else{
        while(atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = aux;
        aux->ant = atual;
        aux->prox = NULL;
    }
}

Lista *merge(Lista *l1, Lista *l2){
    Lista *aux;

    if(l1 == NULL && l2 == NULL)
        return NULL;

    if(l1 != NULL && l2 == NULL)
        return l1;

    if(l1 == NULL && l2 != NULL)
        return l2;

    aux = l1;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = l2;
    l2->ant = aux;

    return l1;
}

int length(Lista *l){
    Lista *aux = l;
    int i = 0;

    if(aux == NULL)
        return i;

    while(aux->prox != NULL){
        aux = aux->prox;
        i++;
    }

    return i;
}

