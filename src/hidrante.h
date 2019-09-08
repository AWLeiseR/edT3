#ifndef _HIDRANTE_H
#define _HIDRANTE_H

/*================================================
Get and Set e deslocamento de Semaforo
==================================================*/


typedef void* Hidrante;



/*define hidrante
pre->todos os parametros != NULL
pos->retorna um Hidrante(void*)
*/
Hidrante defineHidrante( char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw);

/*desloca hidrante 
pre->todos os parametros != NULL e dois doubles com as medidas para delocar o Hidrante
dx->eixo x
dy->eixo y
pos->e retorna um ponteiro para o id do semaforo deslocado*/
char* deslocaHidrante(Hidrante hid, double dx, double dy);

/*
pre->parametro != NULL
pos->retorna o X do Hidrante*/
double getHidX(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o Y do Hidrante*/
double getHidY(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o espessura do Hidrante*/
double getHidSw(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o id(string) do Hidrante*/
char* getHidId(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do Hidrante*/
char* getHidCfill(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Hidrante*/
char* getHidCstrk(Hidrante hid);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidX(Hidrante hid, double pX);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidY(Hidrante hid, double pY);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidCfill(Hidrante hid, char pCfill[]);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setHidCstrk(Hidrante hid, char pCstrk[]);
#endif