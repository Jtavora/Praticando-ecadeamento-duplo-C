#include <stdio.h>
#include <stdlib.h>

typedef struct Header{
    struct Encadeamentoduplo *primeiro;
    struct Encadeamentoduplo *ultimo;
}header;

typedef struct Encadeamentoduplo{
    int num;
    struct Encadeamentoduplo *proxima;
    struct Encadeamentoduplo *anterior;
}lista;

header *cria_header(void);
void cria_lista(header *h, int num);
void retira_procurado(header *h, int proc);
void limpa_lista(header *h);
void printa_lista(header *h);

