#include <stdio.h>
#include "pilha_tad.h"
#define sizeofpilha 100

struct pilha {
    int index;
    float value [ sizeofpilha ];
};

Pilha * pilha_cria(void){
      
      Pilha * p = (Pilha*) malloc(sizeof(Pilha));
      p->index = 0;
      return p;
      
}


void pilha_push(Pilha * p, float v){
     
     if(p->index == sizeofpilha){
     
             printf("Estouro de pilha!!");
             exit(100);
     }
     
     p->value[p->index] = v;
     p->index++;
     
}

float pilha_pop(Pilha* p){
      
      float value;
      
      if(pilha_vazia(p)){
                         
             printf("Pilha em branco!");
             exit(101);
                         
      }
      
      value = p->value[p->index-1];
      p->index--;
      
      return value;
      
}


int pilha_vazia(Pilha* p){
    
    return (p->index == 0);
    
}


void pilha_libera(Pilha *p){
     free(p);
}



