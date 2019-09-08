#include<math.h>
#include<stdio.h>
#include"svgFile.h"
//#include"geometria.h"
/*calcula a distancia euclidiana entre os pontoos (x1,y1) e (x2,y2)*/
double distancia (double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;

    double dist = sqrt(dx*dx + dy * dy);
    return dist;
}
//retorna o maior valor
double max(double n1,double n2){
    if(n1>n2)
        return n1;
    else
        return n2;
}
//retorna o menor valor
double min(double n1,double n2){
    if(n1<n2)
        return n1;
    else
        return n2;
}

int pontoInternoCirculo(double px, double py, double cx, double cy, double r){
    double d = distancia (px,py,cx,cy);
    int res = d <= r? 1:0;
    return res;
}

int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2){
    if(px>=cx1 && px<=cx2 && py>=cy1 && py<=cy2)
        return 1;
    else
        return 0;
} 
int retanguloInteriorCirculo(double x,double y,double w,double h,double cx,double cy,double r){
    int res;
    if(pontoInternoCirculo(x,y,cx,cy,r) && pontoInternoCirculo(x+w,y,cx,cy,r)&&
        pontoInternoCirculo(x,y+h,cx,cy,r)&&pontoInternoCirculo(x+w,y+h,cx,cy,r)){
            res=1;
    }else{
        res=0;
    }
    return res;
}

int retanguloInteriorRetangulo(double x,double y,double w,double h,double x1,double y1,double w1,double h1){
    if(pontoInteriorRetangulo(x,y,x1,y1,x+w1,y+h1)&&pontoInteriorRetangulo(x+w,y,x1,y1,x+w1,y+h1)&&
    pontoInteriorRetangulo(x,y+h,x1,y1,x+w1,y+h1)&&pontoInteriorRetangulo(x+w,y+h,x1,y1,x+w1,y+h1)){
        return 1;
    }else{
        return 0;
    }
}
int retanguloInteriorLosango(double r, double cx, double cy, double x, double y, double w, double h){
    if(fabs(x-cx)+fabs(y-cy)<=r &&fabs((x+w)-cx)+fabs(y-cy)<=r&&
    fabs(x-cx)+fabs((y+h)-cy)<=r&&fabs((x+w)-cx)+fabs((y+h)-cy)<=r){
        return 1;
    }else{
        return 0;
    }
}

int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR){
    double deltaX;
    double deltaY;
    
    deltaX=cX-max(recX,min(cX,recX+recW));
    deltaY=cY-max(recY,min(cY,recY+recH));
    if((deltaX*deltaX+deltaY*deltaY)<=(cR*cR))
        return 1;
    else
        return 0;
}
int sobreposicaoCirculoCirculo(double x1, double y1, double r1, double x2, double y2,double r2,char cor[],FILE *arq3){
    int res;
    double /*x,y,*/h,w;
    double dis,raios;
    //calcula a distancia entre os rcentros
    dis=distancia(x1,y1,x2,y2);
    
    //soma so raios
    raios=r1+r2;
    
    //verifica se a distancia é menos ou igual ao soma dos raios
    if(dis<=raios)
        res=1;
    else
        res=0;
    
    w=max(x1,x2)-min(x1,x2)+r1+r2;
   
    h=max(y1,y2)-min(y1,y2)+r1+r2;
   
    imprimiRetanguloDash(min(x1,x2)-max(r1,r2),min(y1,y2)-max(r1,r2),w,h,cor,arq3,res);
    return res;
}

int sobreposicaoCirculoRetangulo(double x1, double y1, double r1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3){
 int res;
    double w,h;
    res=collision(x2,y2,w2,h2,x1,y1,r1);
    w=max(x2+w2,x1+r1)-min(x2,x1-r1);    
    h=max(y2+h2,y1+r1)-min(y2,y1-r1);
    imprimiRetanguloDash(min(x2,x1-r1),min(y2,y1-r1),w,h,cor,arq3,res);
    return res;
    
}

int sobreposicaoRetanguloRetangulo(double x1, double y1, double h1, double w1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3){
    int res;
    double w,h;
    if(x1<x2+w2 && x1+w1>x2 && y1<y2+h2 && y1+h1>y2)
        res=1;
    w=max(x1+w1,x2+w2)-min(x1,x2);   
    h=max(y1+h1,y2+h2)-min(y1,y2);
    imprimiRetanguloDash(min(x1,x2),min(y1,y2),w,h,cor,arq3,res);
    return res;
}