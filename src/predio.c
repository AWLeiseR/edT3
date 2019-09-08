#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#include"predio.h"
typedef struct{
    char cep[50];
    double x;
    double y;
    double w;
    double h;
    char face;
    int num;
    double f;
    double p;
    double mrg;
}PredioStruct;

Predio definePredio(char pCep[],char pFace,int pNum,double pF,double pP,double pMrg,double pX,double pY,double pW,double pH){
    PredioStruct *predio=malloc(sizeof(PredioStruct));
    strcpy(predio->cep,pCep);
    predio->face=pFace;
    predio->num=pNum;
    predio->f=pF;
    predio->p=pP;
    predio->mrg=pMrg;
    predio->x=pX;
    predio->y=pY;
    predio->w=pW;
    predio->h=pH;
    return predio;
}

char *getPredioCep(Predio p){
    PredioStruct *predio=p;
    return  predio->cep;
}

char getPredioFace(Predio p){
    PredioStruct *predio=p;
    return predio->face;
}

int getPredioNum(Predio p){
    PredioStruct *predio=p;
    return predio->num;
}

double getPredioF(Predio p){
    PredioStruct *predio=p;
    return predio->f;
}

double getPredioP(Predio p){
    PredioStruct *predio=p;
    return predio->p;
}

double getPredioMrg(Predio p){
    PredioStruct *predio=p;
    return predio->mrg;
}

double getPredioX(Predio p){
    PredioStruct *predio=p;
    return predio->x;
}

double getPredioY(Predio p){
    PredioStruct *predio=p;
    return predio->y;
}

double getPredioW(Predio p){
    PredioStruct *predio=p;
    return predio->w;
}

double getPredioH(Predio p){
    PredioStruct *predio=p;
    return predio->h;
}