#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"muro.h"
typedef struct{
    double x1,y1,x2,y2;
}MuroStruct;

Muro defineMuro(double pX1,double pY1,double pX2,double pY2){
    MuroStruct *m=malloc(sizeof(MuroStruct));
    m->x1=pX1;
    m->y1=pY1;
    m->x2=pX2;
    m->y2=pY2;

    return m;
}

double getMuroX1(Muro muro){
    MuroStruct *m=muro;
    return m->x1;
}

double getMuroX2(Muro muro){
    MuroStruct *m=muro;
    return m->x2;
}

double getMuroY1(Muro muro){
    MuroStruct *m=muro;
    return m->y1;
}

double getMuroY2(Muro muro){
    MuroStruct *m=muro;
    return m->y2;
}