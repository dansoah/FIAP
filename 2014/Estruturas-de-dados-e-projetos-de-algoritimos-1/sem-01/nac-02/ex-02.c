#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
} Lista;

Lista *l1 = NULL;
Lista *l2 = NULL;

Lista *concatena(Lista *l1, Lista *l2);
int comprimento(Lista *l);
void imprimir(Lista *l);
void printL();
void put(Lista **l);


int main(void){
    
    int opt = 0;
    int tot = 0;
    do{

        system("CLS");
        printf("-------------------------------------------\n");
        printf("|  Lista de opções para as listas         |\n");
        printf("-------------------------------------------\n");
        printf("|  (1) Inserir na primeira lista          |\n");
        printf("|  (2) Inserir na segunda lista           |\n");
        printf("|  (3) Concatena na primeira lista        |\n");
        printf("|  (4) Concatena na segunda lista         |\n");
        printf("|  (5) Quais são os valores?              |\n");
        printf("|  (*) Sair                               |\n");
        printf("-------------------------------------------\n");
        scanf("%d", &opt);
    
        system("CLS");
    
        switch(opt){
            case 1:
                put(&l1);
                system("CLS");
                printf("\n _-_-_-_-_-_-_ VALORES DA LISTA 1 _-_-_-_-_-_-_\n\n");
                imprimir(l1);
                printf("\n_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_\n");
                break;
            case 2:
                put(&l2);
                system("CLS");
                printf("\n _-_-_-_-_-_-_ VALORES DA LISTA 2 _-_-_-_-_-_-_\n\n");
                imprimir(l2);
                printf("\n_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_\n");
                printf("\n\n");
                break;
            case 3:
                l1 = concatena(l1, l2);
                l2 = NULL;
                break;
            case 4:
                l2 = concatena(l1, l2);
                l1 = NULL;
                break;
            case 5:
                printL();
                break;
        }
    
        
        system("PAUSE");

    }while(opt < 6);
}

void put(Lista **l){
    Lista *aux = malloc(sizeof(Lista));
    Lista *per = *l;

    printf("\nAdicionar: ");
    scanf("%d", &aux->info);

    if(*l == NULL){
        aux->prox = aux;
    }else{
        aux->prox = *l;
        do{
            per = per->prox;
        }while(per->prox != *l);
        per->prox = aux;
    }

    *l = aux;
}

int comprimento(Lista *l){
    Lista *aux = l;
    int i = 0;

    if(aux == NULL)
        return i;

    do{
        aux = aux->prox;
        i++;
    }while(aux != l);

    return i;
}

Lista *concatena(Lista *l1, Lista *l2){
    Lista *novo;
    
    //Nenhuma das duas pode ser nula
    if(l1 == NULL && l2 == NULL)
        return NULL;
        
    if(l1 != NULL && l2 == NULL)
        return l1;

    if(l1 == NULL && l2 != NULL)
        return l2;

    novo = l1;

    do{
        novo = novo->prox;
    }while(novo->prox != l1);

    novo->prox = l2;

    do{
        novo = novo->prox;
    }while(novo->prox != l2);

    novo->prox = l1;

    return l1;
}



void imprimir(Lista *l){
    Lista *aux = l;

    if(aux == NULL){
        printf("Nada\n");
        return;
    }

    do {
        printf("%d", aux->info);
        aux = aux->prox;
        if(aux != 1)
            printf(",");
    } while (aux != l);
    printf("\n");
}

void printL(){
     int sum;
     sum = comprimento(l1);
     printf("~~\nLista 1: %d\n", sum);
    
     sum = 0;
     sum = comprimento(l2);
     printf("~~\nLista 2: %d\n\n", sum);     
}
