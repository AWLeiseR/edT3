#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hidrante.h"

typedef struct{
    char id[50];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}HidranteStruct;


Hidrante defineHidrante( char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw){
    HidranteStruct *hid=malloc(sizeof(HidranteStruct));
    strcpy(hid->id,i);
    hid->x=pX;
    hid->y=pY;
    strcpy(hid->cfill,pCfill);
    strcpy(hid->cstrk,pCstrk);
    hid->sw=pSw;
    return hid;
}

char* deslocaHidrante(Hidrante hid, double dx, double dy){
    HidranteStruct *h=hid;
        h->x=+dx;
        h->y=+dy;

        return h->id;
}

double getHidX(Hidrante hid){
    HidranteStruct *h=hid;
    return h->x;
}

double getHidY(Hidrante hid){
    HidranteStruct *h=hid;
    return h->y;
}

double getHidSw(Hidrante hid){
    HidranteStruct *h=hid;
    return h->sw;
}

char* getHidId(Hidrante hid){
    HidranteStruct *h=hid;
    return h->id;
}
char* getHidCfill(Hidrante hid){
    HidranteStruct *h=hid;
    return h->cfill;
}

char* getHidCstrk(Hidrante hid){
    HidranteStruct *h=hid;
    return h->cstrk;
}

void setHidX(Hidrante hid, double pX){
    HidranteStruct *h=hid;
    h->x=pX;
}

void setHidY(Hidrante hid, double pY){
    HidranteStruct *h=hid;
    h->y=pY;
}

void setHidCfill(Hidrante hid, char pCfill[]){
    HidranteStruct *h=hid;
    strcpy(h->cfill,pCfill);
}

void setHidCstrk(Hidrante hid, char pCstrk[]){
    HidranteStruct *h=hid;
    strcpy(h->cstrk,pCstrk);
}