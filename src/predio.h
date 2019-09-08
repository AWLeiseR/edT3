#ifndef _PREDIO_H
#define _PREDIO_H
/*=====================================
Todas as funções relacionadas a predios
=======================================*/

/* ponteiro para o predio*/
typedef void* Predio;
/*
pre->todos os parametros != NULL
pos->retorna um Predio(void*)
*/
Predio definePredio(char pCep[],char pFace,int pNum,double pF,double pP,double pMrg,double pX,double pY,double pW,double pH);
/*
pre->parametro != NULL
pos->retorna o cep(Vetor) do Predio(void*)
*/
char *getPredioCep(Predio p);

/*
pre->parametro != NULL
pos->retorna o Face(caracter) do Predio(void*)
*/
char getPredioFace(Predio p);

/*
pre->parametro != NULL
pos->retorna o num do Predio(void*)
*/
int getPredioNum(Predio p);

/*
pre->parametro != NULL
pos->retorna a frente/fachada do Predio(void*)
*/
double getPredioF(Predio p);

/*
pre->parametro != NULL
pos->retorna a profundidade do Predio(void*)
*/
double getPredioP(Predio p);

/*
pre->parametro != NULL
pos->retorna a margem do Predio(void*)
*/
double getPredioMrg(Predio p);

/*
pre->parametro != NULL
pos->retorna o X do Predio(void*)
*/
double getPredioX(Predio p);

/*
pre->parametro != NULL
pos->retorna o Y do Predio(void*)
*/
double getPredioY(Predio p);

/*
pre->parametro != NULL
pos->retorna o W do Predio(void*)
*/
double getPredioW(Predio p);

/*
pre->parametro != NULL
pos->retorna o H do Predio(void*)
*/
double getPredioH(Predio p);

#endif