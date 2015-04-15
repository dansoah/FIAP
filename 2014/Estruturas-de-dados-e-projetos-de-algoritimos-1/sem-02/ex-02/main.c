#include <stdio.h>
#include "pilha.h"


void gui_insere(void);
void gui_exibe(void);

Pilha * pilha;


int main(char* argv[], int argc){
    pilha = pilha_cria();
    int opt = 0;
     
    do{
        system("CLS");
        printf(":::::::::: PILHA MASTER ::::::::::::::\n");
        printf("1 - Inserir valor\n");
        printf("2 - Exibir pilha\n");
        printf("3 - Sair\n");
        scanf("%i",&opt);
        
        switch(opt){
            case 1:
                 gui_insere();
                 break;
            case 2:
                 gui_exibe();
                 break;
        }
                 
    }while(opt < 3);
    
    free(pilha);
    
    
    return 0;
}

void gui_insere(void){
     
    float n;
    printf("Número: ");
    scanf("%f",&n);
    
    pilha_push(pilha,n);
         
}

void gui_exibe(){
     
    float v;
    
    system("CLS");
    printf("::::: PILHA :::::\n");
    
    while(!pilha_vazia(pilha)){
        
        v = pilha_pop(pilha);
        printf("%.2f\n",v);                                   
    }
    printf("\n\n\n");
    system("PAUSE");
}


