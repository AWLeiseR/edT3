#ifndef _SEGMENTO_H
#define _SEGMENTO_H

typedef void* Elemento;

typedef void* Ponto;

typedef void* Segmento;

Ponto definePonto(double pX,double pY);

double getPontoX(Ponto p);

double getPontoY(Ponto p);

void *getPontoSeg(Ponto p);

void setPontoY(Ponto p, double yValor);

void setPontoX(Ponto p, double xValor);

void setPontoSeg(Ponto p, Segmento s);

void desalocarPontos(Ponto pto);

Segmento defineSegmento(Ponto p1,Ponto p2);

void setSegmentoIni(Segmento sg, Ponto pto);

void setSegmentoFim(Segmento sg, Ponto pto);

Ponto getSegmentoIni(Segmento sg);

Ponto getSegmentoFim(Segmento sg);

int lado(double x1, double y1, double x2, double y2, double x3, double y3);

void trocaPontos(Segmento sg);

int intersecao(double x1,double y1, double x2,double y2, double x3,double y3, double x4,double y4);

Ponto lineIntersection(void *p1, void *p2, void *p3, void *p4);

double calcularAngulo(double x1,double y1,double x2,double y2);
/*função para calcular pontos de intersecção*/
Ponto intersectionLines(Ponto A1,Ponto A2,Ponto B1,Ponto B2);

Ponto pontoIntersecao(Ponto A,Ponto B,Ponto C,Ponto D);

int seInterceptam(Ponto A,Ponto B,Ponto C,Ponto D);

int lado1(Ponto A,Ponto B,Ponto C);

#endif