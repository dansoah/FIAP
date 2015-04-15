#include <stdio.h>
#include <stdlib.h>

typedef struct number{
    int info;
    struct number *prox;
} Lista;

int sizeOf(Lista *l);
void display(Lista *l);
void insere(Lista **l);

int main(void){
    Lista *l = NULL;
    int opcao = 0;
    int total;

    do{

        system("CLS");
        printf("=============MENU=================\n");
        printf("|\n");
        printf("|   1. Adicionar numero\n");
        printf("|   2. Exibir\n");
        printf("|   3. Contagem\n");
        printf("|   4. Sair\n");
        printf("|\n");
        printf("==================================\n");
        scanf("%d", &opcao);
    
        system("CLS");
    
        switch(opcao){
            case 1:
                insere(&l);
                break;
            case 2:
                display(l);
                printf("\n\n");                
                break;
            case 3:
                total = sizeOf(l);
                printf("Total: %d\n\n", total);
                break;
        }
        if(opcao != 4)
            system("PAUSE");
    }while(opcao != 4);
}

int sizeOf(Lista *l){
    Lista *aux = l;
    int i = 0;

    while(aux != NULL){
        aux = aux->prox;
        i++;
    }

    return i;
}

void insere(Lista **l){
    Lista *aux = malloc(sizeof(Lista));

    printf("\nValor: ");
    scanf("%d", &aux->info);

    aux->prox = *l;

    *l = aux;
}



void display(Lista *l) {
    Lista *aux = l;

    while (aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}
