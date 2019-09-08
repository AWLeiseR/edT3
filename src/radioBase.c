#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include"radioBase.h"
typedef struct{
    char id[30];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}RadioStruct;

Radio defineRadio(char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw){
    RadioStruct *radio=malloc(sizeof(RadioStruct));
    strcpy(radio->id,i);
    radio->x=pX;
    radio->y=pY;
     strcpy(radio->cfill,pCfill);
    strcpy(radio->cstrk,pCstrk);
    radio->sw=pSw;
    return radio;
}


char* deslocaRadio(Radio r, double dx, double dy){
    RadioStruct *radio=r;
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}

char* getRadioId(Radio r){
    RadioStruct *radio=r;
    return radio->id;
}

double getRadioX(Radio r){
    RadioStruct *radio=r;
    return radio->x;
}

double getRadioY(Radio r){
    RadioStruct *radio=r;
    return radio->y;
}

double getRadioSw(Radio r){
    RadioStruct *radio=r;
    return radio->sw;
}

char* getRadioCfill(Radio r){
    RadioStruct *radio=r;
    return radio->cfill;
}

char* getRadioCstrk(Radio r){
    RadioStruct *radio=r;
    return radio->cstrk;
}

void setRadioX(Radio r, double pX){
    RadioStruct *radio=r;
    radio->x=pX;
}

void setRadioY(Radio r, double pY){
    RadioStruct *radio=r;
    radio->y=pY;
}

void setRadioCfill(Radio r, char pCfill[]){
    RadioStruct *radio=r;
    strcpy(radio->cfill,pCfill);
}

void setRadioCstrk(Radio r, char pCstrk[]){
    RadioStruct *radio=r;
    strcpy(radio->cstrk,pCstrk);
}