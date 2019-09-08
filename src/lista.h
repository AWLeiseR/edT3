#ifndef _LISTA_H
#define _LISTA_H

typedef void* Lista;

typedef void* Forma;

Lista createLista(int tam_lista);

int getFree(Lista lista);

int getOcupados(Lista l);

int getFirst(Lista L);

int getUltimo(Lista L);

int getProx(Lista L,int posicao);

int getAnt(Lista L,int posicao);

Forma getItem(Lista L,int pos);

int length(Lista L);

void freeList(Lista lista);

Lista insert(Lista L,Forma f);

void delet(Lista lista, int p);
#endif