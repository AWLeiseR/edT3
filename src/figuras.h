#ifndef _FIGURAS_H
#define _FIGURAS_H
/*================================================
Get and Set e deslocamento de Semaforo
==================================================*/

typedef void *Figura;
 
/*define Retangulo
pre->todos os parametros != NULL
pos->retorna um Semaforo(void*)*/
Figura defineRetangulo(char tipo[], int i,double pX,double pY, double pH,double pW,char pStroke[], char pFill[],double pStrokeWidth);

/*define circulo
pre->todos os parametros != NULL
pos->retorna um Semaforo(void*)*/
Figura defineCirculo(char tipo[], int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStrokeWidth);

/*desloca a figura(circ) em x e y
pre->todos os parametros != NULL
pos->retorna um Semaforo(void*)*/
void deslocaFigura(Figura f,double dx, double dy);

//gets and sets

/*
pre->parametro != NULL
pos->retorna o Tipo(strig)"c" ou "r" */
char *getFiguraTipo(Figura f);

/*
pre->parametro != NULL
pos->retorna o id da figura */
int getFiguraId(Figura f);

/*
pre->parametro != NULL
pos->retorna o X da figura */
double getFiguraX(Figura f);

/*
pre->parametro != NULL
pos->retorna o Y da figura */
double getFiguraY(Figura f);

/*
pre->parametro != NULL
pos->retorna o R do criculo */
double getCirculoR(Figura f);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Semaforo*/
char* getFiguraCfill(Figura f);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do Semaforo*/
char* getFiguraCstrk(Figura f);

/*
pre->parametro != NULL
pos->retorna o W do Retangulo*/
double getRetanguloW(Figura f);

/*
pre->parametro != NULL
pos->retorna o H do criculo */
double getRetanguloH(Figura f);

#endif