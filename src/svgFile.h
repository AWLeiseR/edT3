#ifndef _SVGFILE_H
#define _SVGFILE_H
#include"lista.h"
/*======================================================
funçoes responsavel pela impressao do svg
========================================================*/
/*imprimir o cabecalho do svg
pre->ponterio para o arquivo a ser impresso
pos->void*/
void cabecalho(FILE* arq);

/*imprimir o rodape do svg
pre->ponterio para o arquivo a ser impresso
pos->void*/
void rodape(FILE* arq);

/*imprimi retangulo
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiRetangulo(FILE* arq,double x,double y,double h, double w, char cor1[],char cor2[]);

/*imprimi Circulo
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiCirculo(FILE* arq,double x,double y, double r, char cor1[],char cor2[]);

/*imprimi ponto(circulo de raio 1 ou 0)
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiPonto(FILE* arq);

/*imprimi linha
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiLinha(double x1,double y1,double x2, double y2, FILE *arq);

/*imprimi retangulo tracejado
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiRetanguloDash(double x, double y, double w, double h, char stroke[], FILE *arq, int res);

/*imprimi texto
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiTexto(double x, double y, char texto[], FILE *arq);

/*imprimi Semaforo
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiSemaforo(FILE *arq,double x,double y,double sw,char cFill[],char cStrk[]);

/*imprimi Hidrante
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiHidrante(FILE *arq,double x, double y,double sw,char cFill[],char cStrk[]);

/*imprimi Radio
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiRadio(FILE *arq,double x, double y,double sw,char cFill[],char cStrk[]);

/*cria arq pra impressao do bb
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiSvgbb(Lista list,char *dirsaida,char sufixo[],char cor[],char sufixogeo[]);

/*imprimi varre e imprime todos os elementos das listas
pre->ponteiro p/ o arq a ser impresso
pos->retorna um void*/
void imprimiSvg(Lista listPre,Lista listFig,Lista listQua,Lista listRad,Lista listHid,Lista listSem,Lista listMuro,FILE *svg);

#endif