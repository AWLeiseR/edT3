#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"figuras.h"
#include"radioBase.h"
#include"quadra.h"
#include"semaforo.h"
#include"predio.h"
#include"hidrante.h"
#include"muro.h"
#include"lista.h"


//imprimir o cabecalho do svg
void cabecalho(FILE* arq){
    fprintf(arq,"<svg>");
}

//imprimir o rodape do svg
void rodape(FILE* arq){
    fprintf(arq,"</svg>");
}

//imprimi retangulo
void imprimiRetangulo(FILE* arq,double x,double y,double h, double w, char cor1[],char cor2[]){
    fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\"  stroke=\"%s\" fill=\"%s\" fill-opacity=\"0.5\" stroke-width=\"1\" stroke-opacity=\"0.5\"/>",x,y,w,h,cor1,cor2);
}

//imprimi Circulo
void imprimiCirculo(FILE* arq,double x,double y, double r, char cor1[],char cor2[]){

    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,r,cor1,cor2);
}

//imprimi ponto(circulo de raio 1 ou 0)
void imprimiPonto(FILE* arq,double x,double y,char cor1[],char cor2[]){
    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,cor1,cor2);
}

void imprimiLinha(double x1,double y1,double x2, double y2, FILE *arq){
   fprintf(arq," <line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" />",x1,y1,x2,y2);
}

void imprimiRetanguloDash(double x, double y, double w, double h, char stroke[], FILE *arq, int res){
    if(!res)
        fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-dasharray=\"5\" stroke-width=\"2\" />",x,y,w,h,stroke);
    else
     fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width=\"2\" />",x,y,w,h,stroke);
}

void imprimiTexto(double x, double y, char texto[], FILE *arq){
    fprintf(arq,"<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>",x,y,texto);
}

void imprimiSemaforo(FILE *arq,double x,double y,double sw,char cFill[],char cStrk[]){
    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" fill=\"%s\" />",x,y,2.0,cStrk,sw,cFill);    
}

void imprimiHidrante(FILE *arq,double x, double y,double sw,char cFill[],char cStrk[]){
    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" fill=\"%s\" />",x,y,2.0,cStrk,sw,cFill);
    fprintf(arq,"<text x=\"%lf\" y=\"%lf\" fill=\"white\" font-size=\"5px\" >H</text>",x-1.85,y+2);

}

void imprimiRadio(FILE *arq,double x, double y,double sw,char cFill[],char cStrk[]){
    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" fill=\"%s\" />",x,y,2.0,cStrk,sw,cFill);
    imprimiTexto(x,y,"R",arq);
}

void imprimiSvgbb(Lista list,char *dirsaida,char sufixo[],char cor[],char sufixogeo[]){
    FILE *svg;
    Figura f;
    char *saida;
    //int j;
    int prox=getFirst(list);
    
    double x,y,w,h,r;
   // char tipo;
    char *borda,*dentro;
   
    saida=(char *) malloc((strlen(dirsaida)+strlen(sufixo)+strlen(sufixogeo)+7)*sizeof(char));

    sprintf(saida,"%s/%s-%s.svg",dirsaida,sufixogeo,sufixo);

    svg=fopen(saida,"w");

    if(svg==NULL){
        perror("");
        exit(1);
    }

    fprintf(svg,"<svg>");
    
    f=getItem(list,prox);
    while(prox!=-1){
        
        if(strcmp("c",getFiguraTipo(f))==0){
            
            x=getFiguraX(f);
            y=getFiguraY(f);
            r=getCirculoR(f);
            borda=getFiguraCstrk(f);
            dentro=getFiguraCfill(f);
            fprintf(svg,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,r,borda,dentro);
            fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\"  fill=\"none\" stroke=\"%s\" stroke-width=\"1\" />",x-r,y-r,r*2,r*2,cor);
        }else if(strcmp("r",getFiguraTipo(f))==0){
            x=getFiguraX(f);
            y=getFiguraY(f);
            h=getRetanguloH(f);                    
            w=getRetanguloW(f);
            borda=getFiguraCstrk(f);
            dentro=getFiguraCfill(f);
            fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"  stroke-width=\"2\" />",x,y,w,h,borda,dentro);
            fprintf(svg,"<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width=\"2\" />",x+(w/2),y+(h/2),w/2,h/2,cor);
        }
        prox=getProx(list,prox);
        f=getItem(list,prox);        
    }
    fprintf(svg,"</svg>");

    fclose(svg);
}

void imprimiSvg(Lista listPre,Lista listFig,Lista listQua,Lista listRad,Lista listHid,Lista listSem,Lista listMuro,FILE *svg){
    //printf("\nimprimi svg\n");
    Quadra qua;
    Radio ra;
    Semaforo se;
    Hidrante hid;
    Figura f;
    Predio pre;
    Muro mu;
    int proxFig,proxQuad,proxSem,proxHid,proxRad,proxPre,proxMuro;
    double x,y,h,w,r,sw,x1,y1;
    char cFill[20],cStrk[20];
   
    proxFig=getFirst(listFig);
    proxQuad=getFirst(listQua);
    proxHid=getFirst(listHid);
    proxSem=getFirst(listSem);
    proxRad=getFirst(listRad);
    proxPre=getFirst(listPre);
    proxMuro=getFirst(listMuro);
    f=getItem(listFig,proxFig);
    qua=getItem(listQua,proxQuad);
    se=getItem(listSem,proxSem);
    hid=getItem(listHid,proxHid);
    ra=getItem(listRad,proxRad);
    pre=getItem(listPre,proxPre);
    mu=getItem(listMuro,proxMuro);
    while(proxFig!=-1||proxQuad!=-1||proxSem!=-1||proxHid!=-1||proxRad!=-1||proxPre!=-1){
        if(proxFig!=-1){
             if(strcmp("c",getFiguraTipo(f))==0){
                x=getFiguraX(f);
                y=getFiguraY(f);
                r=getCirculoR(f);
                strcpy(cFill,getFiguraCstrk(f));
                strcpy(cStrk,getFiguraCfill(f));
                fprintf(svg,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,r,cStrk,cFill);
            }
            if(strcmp("r",getFiguraTipo(f))==0){
                x=getFiguraX(f);
                y=getFiguraY(f);
                h=getRetanguloH(f);                    
                w=getRetanguloW(f);
                strcpy(cFill,getFiguraCstrk(f));
                strcpy(cStrk,getFiguraCfill(f));
                fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"  stroke-width=\"2\" />",x,y,w,h,cStrk,cFill);
            }
        }
        if(proxQuad!=-1){
            x=getQuadraX(qua);
            y=getQuadraY(qua);
            h=getQuadraH(qua);
            w=getQuadraW(qua);
            strcpy(cFill,getQuadraCfill(qua));
            strcpy(cStrk,getQuadraCstrk(qua));
            imprimiRetangulo(svg,x,y,h,w,cStrk,cFill);
        }
        if(proxSem!=-1){
            x=getSemaforoX(se);
            y=getSemaforoY(se);
            sw=getSemaforoSw(se);
            strcpy(cFill,getSemaforoCfill(se));
            strcpy(cStrk,getSemaforoCstrk(se));
            
            imprimiSemaforo(svg,x,y,sw,"blue",cStrk);
        }
        if(proxHid!=-1){
            x=getHidX(hid);
            y=getHidY(hid);
            sw=getHidSw(hid);
            strcpy(cFill,getHidCfill(hid));
            strcpy(cStrk,getHidCstrk(hid));
            imprimiHidrante(svg,x,y,sw,cFill,cStrk);
        }
        if(proxRad!=-1){
            x=getRadioX(ra);
            y=getRadioY(ra);
            sw=getRadioSw(ra);
            strcpy(cFill,getRadioCfill(ra));
            strcpy(cStrk,getRadioCstrk(ra));
            imprimiRadio(svg,x,y,sw,cFill,cStrk);
        }
        if(proxPre!=-1){
            x=getPredioX(pre);
            y=getPredioY(pre);
            h=getPredioH(pre);
            w=getPredioW(pre);
            imprimiRetangulo(svg,x,y,h,w,cStrk,cFill);
        }
        if(proxMuro!=-1){
            x=getMuroX1(mu);
            y=getMuroY1(mu);
            x1=getMuroX2(mu);
            y1=getMuroY2(mu);
            imprimiLinha(x,y,x1,y1,svg);
        }
            proxFig=getProx(listFig,proxFig);
            f=getItem(listFig,proxFig);

            proxQuad=getProx(listQua,proxQuad);
            qua=getItem(listQua,proxQuad);

            proxHid=getProx(listHid,proxHid);
            hid=getItem(listHid,proxHid);

            proxRad=getProx(listRad,proxRad);
            ra=getItem(listRad,proxRad);  

            proxSem=getProx(listSem,proxSem);
            se=getItem(listSem,proxSem);

            proxPre=getProx(listPre,proxPre);
            pre=getItem(listPre,proxPre);
            
            proxMuro=getProx(listMuro,proxMuro);  
            mu=getItem(listMuro,proxMuro);
    }
    
}