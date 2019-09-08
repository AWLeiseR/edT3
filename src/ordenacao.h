#ifndef _ORDENACAO_H
#define _ORDENACAO_H
#include"lista.h"
/*HeapSort 
pre Forma (void*) nao pode ser NULL
n -> tamano do vetor
z-> numero de elementos a ser ordenado
*op->ponteiro para funçao de comparacao
pos->retorna o vetor com k maiores ou maiores no final do vetor */
void heapsort(Forma a[], int n,int z,int(*op)(Forma,Forma)) ;
#endif 