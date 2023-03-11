#include "Encadeamentoduplo.h"

header *cria_header(void){
    header *x = (header*) malloc(sizeof(header));

    x -> primeiro = NULL;
    x -> ultimo = NULL;

    return x;
}

void cria_lista(header *h, int num){
    lista *x = (lista*) malloc(sizeof(lista));

    if(h -> primeiro == NULL){
        h -> primeiro = x;
        h -> ultimo = x;
        x -> proxima = NULL;
        x -> anterior = NULL;
        x -> num = num;
    }

    x -> num = num;
    x -> proxima = NULL;
    x -> anterior = h -> ultimo;
    h -> ultimo -> proxima = x; 
    h -> ultimo = x;
}

void retira_procurado(header *h, int proc){
    
    lista *p = h -> primeiro;
    lista *aux;
    
    if(p == NULL){
        printf("Lista ja esta vazia!\n");
        return 0;
    }

    while(p != NULL){
        if(proc == p -> num){
            if(h -> primeiro == p && h -> ultimo == p){
                free(p);
                p = NULL;
            }else if(h -> ultimo == p){
                p -> anterior -> proxima = NULL;
                h -> ultimo = p -> anterior;
                free(p);
                p = NULL;
            }else if(h -> primeiro == p){
                aux = p -> proxima;
                p -> proxima -> anterior = NULL;
                h -> primeiro = p -> proxima;
                free(p);
                p = aux;
            }else{
                aux = p -> proxima;
                p -> anterior -> proxima = p -> proxima;
                p -> proxima -> anterior = p -> anterior;
                free(p);
                p = aux;
            }
        }else{
            p = p -> proxima;
        }
    }
}

void limpa_lista(header *h){
    lista *p = h -> primeiro;
    lista *aux;

    if(p == NULL){
        printf("\nLista vazia!\n\n");
        return 0;
    }

    while(p != NULL){
        aux = p -> proxima;
        free(p);
        p = aux;
    }

    free(h);
}

void printa_lista(header *h){
    lista *p = h -> primeiro;

    if(p == NULL){
        printf("\nLista vazia!\n");
        return 0;
    }

    printf("\n..:: LISTA ENCADEADA DUPLAMENTE ::..\n");

    while(p != NULL){
        printf("Num: %d\n", p -> num);
        p = p -> proxima;
    }

    printf("\n");
}