#ifndef __GEOMETRIA_H
#define __GEOMETRIA_H
/*==============================================
funçoes relacionadas a calculos
==============================================*/


/*
pre->
pos->retorna 1 se o ponto for interior e 0 se for externo*/
int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2);

/*
pre->
pos->retorna 1 se o ponto for interior e 0 se for externo*/
int pontoInternoCirculo(double px, double py, double cx, double cy, double r);

/*calcula/retorna distancia entre dois pontos
pre->
pos->*/
double distancia (double x1, double y1, double x2, double y2);

/*calcula o maior numero ente n1 e n2
pre->
pos->*/
double max(double n1,double n2);

/*calcula o menor numero ente n1 e n2
pre->
pos->*/
double min(double n1,double n2);

/*calcula o menor numero ente n1 e n2
pre->
pos->*/
int retanguloInteriorCirculo(double x,double y,double w,double h,double cx,double cy,double r);

/*calcula o menor numero ente n1 e n2
pre->
pos->*/
int retanguloInteriorRetangulo(double x,double y,double w,double h,double x1,double y1,double w1,double h1);

/*calcula o menor numero ente n1 e n2
pre->
pos->*/
int retanguloInteriorLosango(double r, double cx, double cy, double x, double y, double w, double h);

/*verirfica se ha colisao ou nao
pre->
pos-> retorna 1 para sim e 0 para nao*/
int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR);

/*verifica sobreposição circulo com circulo
pre->
pos->etorna 1 para sim e 0 para nao*/
int sobreposicaoCirculoCirculo(double x1, double y1, double r1, double x2, double y2,double r2,char cor[],FILE *arq3);

/*verifica sobreposição Circulo e retangulo
pre->
pos->etorna 1 para sim e 0 para nao*/
int sobreposicaoCirculoRetangulo(double x1, double y1, double r1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3);

/*verifica sobreposição retangulo com retangulo
pre->
pos->etorna 1 para sim e 0 para nao*/
int sobreposicaoRetanguloRetangulo(double x1, double y1, double h1, double w1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3);


#endif