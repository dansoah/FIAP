#include <stdio.h>
#include "fila.h"

Fila* multiplica_filas(Fila* f1, Fila* f2);

int main(){
    
    
    int i = 1;
    float valor = 0;
    
    Fila* f1 = fila_cria();
    Fila* f2 = fila_cria();
    
    //Preenche F1
    printf("Valores da primeira fila:\n");
    for(int i = 1;i<=5;i++){
            valor = 0;
           
            
            printf("Valor #%d: ",i); 
            scanf("%f",&valor);          
            fila_insere(f1,valor);
    }
    
    //Preenche F2
    printf("Valores da segunda fila:\n");
    for(int i = 1;i<=5;i++){
            valor = 0;
           
            
            printf("Valor #%d: ",i); 
            scanf("%f",&valor);          
            fila_insere(f2,valor);
    }
    
    system("CLS");
    printf("RESULTADOS\n");
    
    
    Fila * f3 = multiplica_filas(f1,f2);
    
    Lista* lista_res = f3 -> inicio;
     
    while ( lista_res != NULL ) {
        
        
        printf("%f\n",lista_res->info);
        
        
        lista_res = lista_res -> prox ;
     }
    
    printf("\n");
    system("PAUSE");
}


Fila* multiplica_filas(Fila* f1, Fila* f2){
     
     Fila* f3 = fila_cria();
     
     Lista* a = f1 -> inicio;
     Lista* b = f2 -> inicio;
     
     float val = 0;
     while ( a != NULL ) {
        
        
        val = b->info * a->info;
        
        fila_insere(f3,val);
        
        a = a -> prox ;
        b = b -> prox ;
     }
     
     return f3;     
     
}
