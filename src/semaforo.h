#ifndef _SEMAFARO_H
#define _SEMAFARO_H
/*================================================
Get and Set e deslocamento de Semaforo
==================================================*/

typedef void* Semaforo;

/*define um Semaforo
pre->todos os parametros != NULL
pos->retorna um Semaforo(void*)
*/
Semaforo defineSemaforo(char i[], double pX, double pYs, char pCfill[], char pCstrk[],double pSw);

/*desloca o semaforo  
pre->todos os parametros != NULL e dois doubles com as medidas para delocar o semaforo
dx->eixo x
dy->eixo y
pos->e retorna um ponteiro para o id do semaforo deslocado
*/
char* deslocaSemaforo(Semaforo s, double dx, double dy);

/*
pre->parametro != NULL
pos->retorna o X do Semaforo*/
double getSemaforoX(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o Y do Semaforo*/
double getSemaforoY(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o espessura da borda do Semaforo*/
double getSemaforoSw(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o id (string) do Semaforo*/
char* getSemaforoId(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Semaforo
*/
char* getSemaforoCfill(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do Semaforo*/
char* getSemaforoCstrk(Semaforo s);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoX(Semaforo s, double pX);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoY(Semaforo s, double pY);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoCfill(Semaforo s, char pCfill[]);

/*
pre->parametro != NULL
pos->retorna o um void*/
void setSemaforoCstrk(Semaforo s, char pCstrk[]);
#endif