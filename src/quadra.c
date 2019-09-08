#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#include"quadra.h"

typedef struct quadra{
    char cep[30];
    double x;
    double y;
    double w;
    double h;
    double sw;
    char cstrk[30];
    char cfill[30];
}QuadraStruct;


Quadra defineQuadra( char pCep[],double pX, double pY, double pW, double pH,char pCfill[], char pCstrk[],double pSw){
   QuadraStruct *quadra=malloc(sizeof(QuadraStruct));
    strcpy(quadra->cep,pCep);
    quadra->x=pX;
    quadra->y=pY;
    quadra->w=pW;
    quadra->h=pH;
    strcpy(quadra->cfill,pCfill);
    strcpy(quadra->cstrk,pCstrk);
    quadra->sw=pSw;
    return quadra;    
}


void setCor(Quadra qua, char cstrk[]){
    QuadraStruct *quadra=qua;
    strcpy(quadra->cstrk,cstrk);
}

char* getQuadraCep(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->cep;
}

double getQuadraX(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->x;
}

double getQuadraY(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->y;
}

double getQuadraW(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->w;
}

double getQuadraH(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->h;
}

char* getQuadraCfill(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->cfill;
}

char* getQuadraCstrk(Quadra qua){
     QuadraStruct *quadra=qua;
    return quadra->cstrk;
}

void setQuadraX(Quadra qua, double pX){
     QuadraStruct *quadra=qua;
    quadra->x=pX;
}

void setQuadraY(Quadra qua, double pY){
     QuadraStruct *quadra=qua;
    quadra->y=pY;
}

void setQuadraCfill(Quadra qua, char pCfill[]){
     QuadraStruct *quadra=qua;
    strcpy(quadra->cfill,pCfill);
}

void setQuadraCstrk(Quadra qua, char pCstrk[]){
 QuadraStruct *quadra=qua;
    strcpy(quadra->cstrk,pCstrk);
}

char* deslocaQuadra(Quadra qua, double dx, double dy){
     QuadraStruct *quadra=qua;
        quadra->x=quadra->x+dx;
        quadra->y=quadra->y+dy;

        return quadra->cep;  
}