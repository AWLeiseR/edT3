#ifndef _RADIOBASE_H
#define _RADIOBASE_H
/*================================================
Get and Set e deslocamento de Radio Base
==================================================*/
/*aloca um radio*/
typedef void* Radio;

/*define uma torre radio
pre->todos os parametros != NULL
pos->retorna um Radio(void*)
*/
Radio defineRadio(char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw);

/*desloca radio e 
pre->todos os parametros != NULL e dois doubles com as medidas para delocar o radio
dx->eixo x
dy->eixo y
pos->retorna um id(vetorstring) do radio deslocado*/
char* deslocaRadio(Radio r, double dx, double dy);

/*
pre->parametro != NULL
pos->retorna o X do Radio
*/
double getRadioX(Radio r);

/*
pre->parametro != NULL
pos->retorna o Y do Radio
*/
double getRadioY(Radio r);

/*
pre->parametro != NULL
pos->retorna o espessura da borda do Radio
*/
double getRadioSw(Radio r);

/*
pre->parametro != NULL
pos->retorna o id(vetorstring) do radio
*/
char* getRadioId(Radio r);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) do Radio
*/
char* getRadioCfill(Radio r);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) do radio
*/
char* getRadioCstrk(Radio r);

/*
pre->parametro != NULL e double para X
pos->retorna um void
*/
void setRadioX(Radio r, double pX);

/*
pre->parametro != NULL e double eixo Y
pos->retorna um void
*/
void setRadioY(Radio r, double pY);

/*
pre->parametro != NULL e uma string
pos->retorna um void
*/
void setRadioCfill(Radio r, char pCfill[]);

/*
pre->parametro != NULL e uma string
pos->retorna um void
*/
void setRadioCstrk(Radio r, char pCstrk[]);
#endif