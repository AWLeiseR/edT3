#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "lista.h"
typedef struct{
    Forma *forma;
    int ant;
    int prox;
}Item;

typedef struct {
    Item* item;
    int primeiro;
    int livre;
    int ultimo;
    int tamanho;
    int ocupados;
}ListaFiguras;

Lista createLista(int tam_lista){
    //printf("\nlista criada\n");
    int i=0 ;
    ListaFiguras  *lista= malloc(sizeof(ListaFiguras));
    lista->item = malloc(sizeof(Item)*tam_lista);
    lista->livre=0;
    lista->primeiro=-1;
    lista->ultimo=-1;
    lista->tamanho=tam_lista;
    lista->ocupados=0;
    for(i=0;i<tam_lista;i++){
        lista->item[i].prox=1+i;
    }
    lista->item[tam_lista-1].prox=-1;
    return lista;
}

int getFree(Lista lista){
    ListaFiguras *list=lista;
    int i =list->livre;
    list->livre=list->item[list->livre].prox;
    return i;
}

int getOcupados(Lista l){
    ListaFiguras *list=l;
    return list->ocupados;
}

int getFirst(Lista L){
    ListaFiguras *list=L;
    return list->primeiro;
}

int getUltimo(Lista L){
    ListaFiguras *list=L;
    return list->ultimo;
}

int getProx(Lista L,int posicao){
    ListaFiguras *list=L;
    int i=posicao;
    if(posicao==-1){
        return -1;
    }else
        return list->item[i].prox;
}

int getAnt(Lista L,int posicao){
    ListaFiguras *list=L;
    int i=posicao;
    return list->item[i].ant;
}

Forma getItem(Lista L,int pos){
    ListaFiguras *list=(ListaFiguras *) L;
    return list->item[pos].forma;    
}

int length(Lista L){
    ListaFiguras *list = L;
    return list->tamanho;
}

void freeList(Lista lista){
    ListaFiguras *list=lista;
    int proximo=getFirst(lista);
    //printf("\n%d\n",proximo);
    while(proximo!=-1){
        free(list->item[proximo].forma);
        proximo=getProx(lista,proximo);
        //printf("\n%d\n",proximo);        
    }
    free(list->item);
    free(list);
}

Lista insert(Lista L,Forma f){
    ListaFiguras *list = L;
    if(length(L)==list->ocupados){
        return list;
    }else{
        int livre = getFree(L);

        list->item[livre].forma=f;

        list->item[livre].ant=list->ultimo;
        list->item[livre].prox=-1;


        if(list->primeiro!=-1){
            list->item[list->ultimo].prox=livre;
        }else{
            list->primeiro=livre;        
        }

        list->ultimo=livre;

        list->ocupados++;

        return list;
    }
}

void delet(Lista lista, int p){
    ListaFiguras *list = lista;

    int anterior=list->item[p].ant;
    int prox=list->item[p].prox;

    if(p==list->primeiro){
        list->item[prox].ant=-1;   

        list->item[p].prox=list->livre;
        list->item[p].ant=0;

        list->primeiro=prox;

        list->livre=p; 
    }else if(p==list->ultimo){ 

        list->item[anterior].prox=-1;

        list->item[p].ant=0;
        list->item[p].prox=list->livre;

        list->ultimo=anterior;

        list->livre=p; 
    }else{

        list->item[anterior].prox=prox;

        list->item[prox].ant=anterior;

        list->item[p].ant=0;
        list->item[p].prox=list->livre;


        list->livre=p;

    }
    free(list->item[p].forma);
    list->ocupados--;
}



