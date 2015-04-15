#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *ant;
    struct no *prox;
} Lista;

void addBefore(Lista **l);
void addAfter(Lista *l);
void separa(Lista *l,int n);

int main(void){
    Lista *l1 = NULL;
    int opcao;
    int n;
    
    do{
        system("CLS");
    
        printf("Menu:\n\n");
        printf("(1) Adiciona elemento no inicio da lista\n");
        printf("(2) Adiciona elemento no final da lista\n");
        printf("(3) Separar em duas listas\n");
        printf("(*) Sair\n\n\n");
        printf("Opcao: ");
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
                 
                 printf("Quebrar no numero: ");
                 scanf("%d",&n);
                 separa(l1,n);
                 system("PAUSE");
                 break;
                
        }
    
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

void separa(Lista *l,int n){
     int flagHasSeenNumber = 0;
     
     Lista *aux = l;
     
     if(aux == NULL){
            printf("Impossivel encontrar algo em uma lista vazia!");
            return;
     }
     
     printf("Lista 1:\n");
     while(aux != NULL){
               
         if(flagHasSeenNumber == 0)
             printf("%d ", aux->info);
         
         if(aux->info == n && flagHasSeenNumber == 0)
             printf("\n Lista 2:\n");
             
         if(aux->info == n || flagHasSeenNumber == 1){
             printf("%d ", aux->info); 
             flagHasSeenNumber = 1;    
         }
         aux = aux->prox;   
                                
     }
     
     if(flagHasSeenNumber == 0)
             printf("Não foi encontrado o numero '%d'",n);
     
}


