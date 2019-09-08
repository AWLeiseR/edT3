#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"semaforo.h"
typedef struct{
    char id[20];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}SemaforoStruct;

Semaforo defineSemaforo(char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw){
    SemaforoStruct *semaforo=malloc(sizeof(SemaforoStruct));
    strcpy(semaforo->id,i);
    semaforo->x=pX;
    semaforo->y=pY;
    strcpy(semaforo->cfill,pCfill);
    strcpy(semaforo->cstrk,pCstrk);
    semaforo->sw=pSw;

    return semaforo;

}

char* deslocaSemaforo(Semaforo s, double dx, double dy){
    SemaforoStruct *semaforo=s;
    semaforo->x=semaforo->x+dx;
    semaforo->y=semaforo->y+dy;

    return semaforo->id;
}

char* getSemaforoId(Semaforo s){
    SemaforoStruct *se=s;
    return se->id;
}

double getSemaforoX(Semaforo s){
    SemaforoStruct *se=s;
    return se->x;
}

double getSemaforoY(Semaforo s){
        SemaforoStruct *se=s;
    return se->y;
}

double getSemaforoSw(Semaforo s){
    SemaforoStruct *se=s;
    return se->sw;
}

char* getSemaforoCfill(Semaforo s){
    SemaforoStruct *se=s;
    return se->cfill;
}

char* getSemaforoCstrk(Semaforo s){
    SemaforoStruct *se=s;
    return se->cstrk;
}

void setSemaforoX(Semaforo s, double pX){
    SemaforoStruct *se=s;
    se->x=pX;
}

void setSemaforoY(Semaforo s, double pY){
    SemaforoStruct *se=s;
    se->y=pY;
}

void setSemaforoCfill(Semaforo s, char pCfill[]){
    SemaforoStruct *se=s;
    strcpy(se->cfill,pCfill);
}

void setSemaforoCstrk(Semaforo s, char pCstrk[]){
    SemaforoStruct *se=s;
    strcpy(se->cstrk,pCstrk);
}