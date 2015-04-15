#include <stdio.h>
#include "pilha.h"


float topo(Pilha* p);

int main(char* argv[], int argc){
    
    //Contador de itens da pilha
    int total = 0;
    
    //GUI
    printf("Quantos itens voce quer inserir?\n");
    scanf("%i",&total);
    system("CLS");
    
    //Construindo auxiliares
    Pilha* user_input = pilha_cria();
    float valor;
    total -= 1;
    int i=0;
    
    for(i=0; i<=total; i++){
        int idx = i + 1;
        printf("Valor #%i: ",idx);
        scanf("%f",&valor);
        pilha_push(user_input,valor);
            
    }
    
    system("CLS");
    
    float top = topo(user_input);
    printf("Numero no topo: %.2f\n",top);
    
    pilha_libera(user_input);
    
    system("PAUSE");
    
    return 0;
}

float topo(Pilha* p){
      float value;
      value = pilha_pop(p);
      pilha_push(p,value);
      return value;
}
