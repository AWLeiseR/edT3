#ifndef _QUADRA_H
#define _QUADRA_H
/*================================================
Get and Set e deslocamento de quadra
==================================================*/
typedef void* Quadra;


/*
pre->todos os parametros != NULL
pos->retorna um Quadra(void*)
*/
Quadra defineQuadra( char pCep[],double pX, double pY, double pW, double pH,char pCfill[], char pCstrk[],double pSw);
/*muda a cor do stroke 
pre->pre->todos os parametros != NULL e string (nome da cor)
pos->retorna o cep(vetor string) da quadra com a cor alterada
*/char* mudarCor(Quadra qua, char cstrk[]);

/*desloca a quadra 
pre->pre->todos os parametros != NULL e dois doubles com as medidas para delocar a quadra
dx->eixo x
dy->eixo y
pos->e retorna o cep(vetor de string) da quadra deslocada
*/
char* deslocaQuadra(Quadra qua, double dx, double dy);

/*
pre->parametro != NULL
pos->retorna o X da Quadra
*/
double getQuadraX(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o Y da Quadra
*/
double getQuadraY(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o H da Quadra
*/
double getQuadraH(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o W da Quadra
*/
double getQuadraW(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o cep(string) da Quadra
*/
char* getQuadraCep(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o corInterna(string) da Quadra
*/
char* getQuadraCfill(Quadra qua);

/*
pre->parametro != NULL
pos->retorna o corExterna(string) da Quadra
*/
char* getQuadraCstrk(Quadra qua);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraX(Quadra qua, double pX);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraY(Quadra qua, double pY);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraCfill(Quadra qua, char pCfill[]);

/*
pre->parametro != NULL e double
pos->retorna um void
*/
void setQuadraCstrk(Quadra qua, char pCstrk[]);

#endif