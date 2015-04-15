#include "tad_fila.h"
#include <stdlib.h>

struct lista {
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

struct fila {
    Lista* inicio;
    Lista* fim;
};

Fila* fila_cria (void){
    Fila* f = ( Fila* ) malloc ( sizeof ( Fila ) ) ;
    f -> inicio = f -> fim = NULL ;
    return f ;
}

void fila_insere ( Fila* f, float v ){
    Lista* n = ( Lista* ) malloc ( sizeof ( Lista ) ) ;
    n -> info = v;
    n -> prox = NULL;
    if ( f -> fim != NULL )
       f -> fim -> prox = n ;
    else
    f -> inicio = n ;
    f -> fim = n ;
}


float fila_retira ( Fila* f ){
    Lista* t ;
    float v ;
    if ( fila_vazia ( f ) ) {
        printf ( " Fila vazia. \n " );
        exit ( 1 ) ;
    }
    t = f -> inicio ;
    v = t -> info ;
    f -> inicio = t -> prox ;
    if ( f -> inicio == NULL )
       f -> fim = NULL;
    free ( t );
    return v;
}

int fila_vazia ( Fila* f ){
    return ( f-> inicio == NULL ) ;
}

void fila_libera ( Fila* f ){
    Lista* q = f -> inicio;
    while ( q != NULL ) {
        Lista* t = q -> prox ;
        free ( q ) ;
        q = t ;
    }
    free ( f ) ;
}
