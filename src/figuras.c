#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"geometria.h"
#include"figuras.h"


typedef struct{
    char tipo[2];
    int id;
    double x;
    double y;
    union{
        double r;
        double hw[2];
    };
    
    char stroke[15];
    char fill[15];
    double strokeWidth;
    
}FiguraStruct;

Figura defineRetangulo(char tipo[], int i,double pX,double pY, double pH,double pW,char pStroke[], char pFill[],double pStrokeWidth){
    FiguraStruct *f=malloc(sizeof(FiguraStruct));
    strcpy(f->tipo,tipo);
    f->id=i;
    f->x=pX;
    f->y=pY;
    f->strokeWidth=pStrokeWidth;
    f->hw[0]=pH;
    f->hw[1]=pW;
    
   strcpy(f->stroke,pStroke);
   strcpy(f->fill,pFill);
   return f;
}

Figura defineCirculo(char tipo[], int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStrokeWidth){
    FiguraStruct *f=malloc(sizeof(FiguraStruct));
    strcpy(f->tipo,tipo);
    f->id=i;
    f->x=pX;
    f->y=pY;
    f->strokeWidth=pStrokeWidth;
    f->r=pR;
    strcpy(f->stroke,pStroke);
   strcpy(f->fill,pFill);
   return f;
}

void deslocaFigura(Figura f,double dx, double dy){
    FiguraStruct *fig=f;
    fig->x=+dx;
    fig->y=+dy;
}

char *getFiguraTipo(Figura f){
    FiguraStruct *fig=f;
    return fig->tipo;
}

int getFiguraId(Figura f){
    FiguraStruct *fig=f;
    return fig->id;
}

double getFiguraX(Figura f){
    FiguraStruct *fig=f;
    return fig->x;
}

double getFiguraY(Figura f){
    FiguraStruct *fig=f;
    return fig->y;
}

char* getFiguraCfill(Figura f){
    FiguraStruct *fig=f;
    return fig->stroke;
}

char* getFiguraCstrk(Figura f){
    FiguraStruct *fig=f;
    return fig->fill;
}

double getRetanguloH(Figura f){
    FiguraStruct *fig=f;
    return fig->hw[0];
}

double getRetanguloW(Figura f){
    FiguraStruct *fig=f;
    return fig->hw[1];
}

double getCirculoR(Figura f){
    FiguraStruct *fig=f;
    return fig->r;
}
