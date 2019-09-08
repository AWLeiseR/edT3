#ifndef _QRYFILE_H
#define _QRYFILE_H
#include"lista.h"
#include"semaforo.h"
#include"hidrante.h"

/*recebe uma lista e vet transfere os elementos da lista para o vetor
pre->parametro != NULL
pos->retorna void */
void preencheVet(Lista l,Forma vet[]);

/*
pre->parametro != NULL
pos->retorna q se s1 >s2, e 0 caso contrario */
int comparaMaiorSe(Semaforo s1,Semaforo s2);

/*
pre->parametro != NULL
pos->retorna q se s1 >s2, e 0 caso contrario */
int comparaMenorSe(Forma s1,Semaforo s2);

/*Le arquivo QRY e imprime -qry.svg
pre->parametro != NULL
pos->retorna void */
void leituraQry(char pathqry[], char pathsaida[],char sufixogeo[],char sufixoqry[],Lista listFig,Lista listQua,Lista listRad,Lista listHid,Lista listSem,Lista listPre,Lista listMuro);

#endif