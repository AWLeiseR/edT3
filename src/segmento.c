#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include"segmento.h"

typedef struct {
    Elemento seg;
    double x,y;
    double angulo;
}pontoStruct;

typedef struct {
    Ponto *pInicio;
    Ponto *pFim;
}segmentoStruct;

Ponto definePonto(double pX,double pY){
    pontoStruct *pto=malloc(sizeof(pontoStruct));
    pto->x=pX;
    pto->y=pY;
    return pto;
}

double getPontoX(Ponto p){
    pontoStruct *ponto = p ;
    return ponto->x; 
}

double getPontoY(Ponto p){
    pontoStruct *ponto = p ;
    return ponto->y; 
}

void *getPontoSeg(Ponto p){
    pontoStruct *ponto = p ;
    return ponto->seg; 
}

double getPontoAngulo(Ponto p){
    pontoStruct *ponto = p ;
    return ponto->angulo; 
}

void setPontoAngulo(Ponto p,double ang){
    pontoStruct *ponto = p ;
     ponto->angulo=ang; 
}

void setPontoY(Ponto p, double yValor){
    pontoStruct *ponto = p ;
    ponto->y = yValor; 
}

void setPontoX(Ponto p, double xValor){
    pontoStruct *ponto = p ;
    ponto->x = xValor; 
}

void setPontoSeg(Ponto p, Segmento s){
    pontoStruct *ponto = p ;
    ponto->seg = s;
}

Segmento defineSegmento(Ponto p1,Ponto p2){
    segmentoStruct *s=malloc(sizeof(Segmento));
    s->pInicio=p1;
    s->pFim=p2;
    return s;
}

void setSegmentoIni(Segmento sg, Ponto pto){
    segmentoStruct *s=sg;
    //pontoStruct *p=pto;
    s->pInicio = pto; 
}

void setSegmentoFim(Segmento sg, Ponto pto){
    segmentoStruct *s=sg;
    //pontoStruct *p=pto;
    s->pFim = pto; 
}

Ponto getSegmentoIni(Segmento sg){
    segmentoStruct *s=sg;
    return s->pInicio; 
}

Ponto getSegmentoFim(Segmento sg){
    segmentoStruct *s=sg;
    return s->pFim; 
}

void trocaPontos(Segmento sg){
    segmentoStruct *s=sg;
    Ponto a,b;
    a = getSegmentoIni(s);
    b = getSegmentoFim(s);
    setSegmentoIni(s, b);
    setSegmentoFim(s, a);
}

int lado(double x1, double y1, double x2, double y2, double x3, double y3){
    double S = x1*y3 - y1*x3 + y1*x2 - x1*y2 + x3*y2 - y3*x2;
    if(S < 0){
        return -1;
    }else if(S > 0){
        return 1;
    }else{
        return 0;
    }
}

double determinante(double x1,double y1, double x2,double y2, double x3,double y3, double x4,double y4){
    double det;
    //printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n",x1,y1,x2,y2,x3,y3,x4,y4);
    det = (x4 - x3) * (y2 - y1)  -  (y4 - y3) * (x2 - x1);
   // printf("%lf\n",det);
    if (det == 0.0){
        return 0 ; // não há intersecção
    }
      //s = ((x4 - x3) * (y3 - y1) - (y4 - y3) * (x3 - x1))/ det ;
    //t = ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1))/ det ;
    return det; // há intersecção   
}

Ponto lineIntersection(Ponto p1, Ponto p2,Ponto p3,Ponto p4){
    pontoStruct *this = malloc(sizeof(pontoStruct));
        //Line AB represented as a1x + b1y = c1
    //double a1 = getPontoY(p2) - getPontoY(p1);
    //printf("%lf %lf\n",getPontoY(p2),getPontoY(p1));
    //double b1 = getPontoX(p1) - getPontoX(p2);
    //double c1 = a1*(getPontoX(p1)) + b1*(getPontoY(p1));

    //Line CD represented as a2x + b2y = c2
    //double a2 = getPontoY(p4) - getPontoY(p3);
   // double b2 = getPontoX(p3) - getPontoX(p4);
    
    //double c2 = a2*(getPontoX(p3)) + b2*(getPontoY(p3));
    //printf("%lf, %lf, %lf, %lf,%lf, %lf\n",a1,b1,c1,a2,b2,c2);

    double determinant = determinante(getPontoX(p1),getPontoY(p1),getPontoX(p2),getPontoY(p2),getPontoX(p3),getPontoY(p3),getPontoX(p4),getPontoY(p4));
    //printf("\ndet -> %f",determinant);
    if(determinant == 0.0){
        return NULL;
        
    }else{
        //printf("(%lf,%lf)\n",(b2*c1 - b1*c2)/determinant,(a1*c2 - a2*c1)/determinant);
        this->x=((getPontoX(p4)-getPontoX(p3))*(getPontoY(p3)-getPontoY(p1))-((getPontoY(p4)-getPontoY(p3))*(getPontoX(p3)-getPontoY(p1))))/determinant;

        this->y=((getPontoX(p2)-getPontoX(p1))*(getPontoY(p3)-getPontoY(p1))-((getPontoY(p2)-getPontoY(p1))*(getPontoX(p3)-getPontoX(p1))))/determinant;
        //this->x = (b2*c1 - b1*c2)/determinant;
        //this->y = (a1*c2 - a2*c1)/determinant;
        
        return this;
    }

    
}

double calcularAngulo(double x1,double y1,double x2,double y2){
    double pi=3.14159265;
    double val =180.0/pi;
    double y=y2-y1;
    double x=x2-x1;
    return atan2(y,x)*val;
}

double minVet(double n[],int tam){
    double  min;
        for(int i =0;i<tam;i++){
            if(i==0){
                min=n[i];
            }else{
                if(min>n[i]){
                    min=n[i];
                }
                    
            }
        }
        return min;
}
double maxVet(double n[],int tam){
    double  max;
        for(int i =0;i<tam;i++){
            if(i==0){
                max=n[i];
            }else{
                if(max<n[i]){
                    max=n[i];
                }
                    
            }
        }
        return max;
}

Ponto intersectionLines(Ponto pto1,Ponto pto2,Ponto pto3,Ponto pto4){
    
    double m1, c1, m2, c2;
    double dx1, dy1,dx2, dy2;
    double intersection_X, intersection_Y;
 
    double Ax1 = getPontoX(pto1);
    double Ay1 = getPontoY(pto1);
    double Ax2 = getPontoX(pto2);
    double Ay2 = getPontoY(pto2);
 
    double Bx1 = getPontoX(pto3);
    double By1 = getPontoY(pto3);
    double Bx2 = getPontoX(pto4);
    double By2 = getPontoY(pto4);
 
    dx1 = Ax2 - Ax1;
 
    dy1 = Ay2 - Ay1;
 
    if(dx1==0){
        m1=0;
        Ay1=0;
    }
    else m1 = dy1 / dx1;
 
    // y = mx + c
 
    // intercept c = y - mx
 
    c1 = Ay1 - m1 * Ax1; // which is same as y2 - slope * x2
 
    dx2 = Bx2 - Bx1;
    dy2 = By2 - By1;
 
    if(dx2==0){
        m2=0;
        By1=0;
    }
    else m2 = dy2 / dx2;
    // y = mx + c
    // intercept c = y - mx
    c2 = By1 - m2 * Bx1; // which is same as y2 - slope * x2
 
    if( (m1 - m2) == 0 && m1!=0 && m2!=0){
        printf("No Intersection between the lines\n");
        return NULL;
    }else{
        if(dx1==0){
            intersection_X=Ax1;
            intersection_Y = m2 * intersection_X+c2;
        }
        else if(dx2==0){
            intersection_X=Bx1;
            intersection_Y = m1 * intersection_X+c1;
        }else{
            intersection_X = (c2 - c1) / (m1 - m2);
            intersection_Y = m1 * intersection_X + c1;  
        }
 
        double Xs[4] = {Ax1,Ax2,Bx1,Bx2};
        double Ys[4] = {Ay1,Ay2,By1,By2};
        
        double minX=minVet(Xs,4);
        double maxX=maxVet(Xs,4);
        double minY=minVet(Ys,4);
        double maxY=maxVet(Ys,4);
        
       if((intersection_X > minX-100 || intersection_X >= minX) && (intersection_X < maxX+100 || intersection_X>=maxX) && (intersection_Y > minY-100 || intersection_Y>=minY) && (intersection_Y < maxY+100 || intersection_Y>=maxY)){
            return definePonto(intersection_X,intersection_Y);
        }else
        {  
            return NULL;
        }
       
    }
}

Ponto pontoIntersecao(Ponto A,Ponto B,Ponto C,Ponto D){
    double s, t,denom;
    if(!seInterceptam(A,B,C,D))
        return NULL;
   
    denom = ((getPontoY(B) - getPontoY(A)) * (getPontoX(D) - getPontoX(C)) - (getPontoY(D) - getPontoY(C)) * (getPontoX(B) - getPontoX(A)));
   
    if(denom == 0)
        return NULL;
 
 
    s = (getPontoX(A) * (getPontoY(D)-getPontoY(C)) + getPontoX(C)*(getPontoY(A)-getPontoY(D)) + getPontoX(D)*(getPontoY(C)-getPontoY(A)))/denom;
 
    t = - (getPontoX(A) * (getPontoY(C)-getPontoY(B)) + getPontoX(B)*(getPontoY(A)-getPontoY(C)) + getPontoX(C)*(getPontoY(B)-getPontoY(A)))/denom;
     //printf("\n%lf %lf\n",s,t);
    if(s>=0 && s<=1 && t>=0 && t<=1){
        return definePonto(getPontoX(A)+s*(getPontoX(B)-getPontoX(A)),getPontoY(A)+s*(getPontoY(B)-getPontoY(A)));
    }else return NULL;
}

int seInterceptam(Ponto A,Ponto B,Ponto C,Ponto D){
    int abc,abd,cda,cdb;
    
    abc = lado1(A,B,C);
    abd = lado1(A,B,D);
    cda = lado1(C,D,A);
    cdb = lado1(C,D,B);

    return ((abc*abd<=0) && (cda*cdb<=0));
}

int lado1(Ponto A,Ponto B,Ponto C){
    int S;
    // S = A.x*C.y - A.y*C.x + A.y*B.x - A.x*B.y + C.x*B.y - C.y*B.x;
    S = getPontoY(A)*getPontoY(C) - getPontoY(A)*getPontoY(C) + getPontoY(A)*getPontoY(B) 
        - getPontoY(A)*getPontoY(B) + getPontoY(C)*getPontoY(B) - getPontoY(C)*getPontoY(B); 

    if(S<0) return -1;
    else if(S>0) return 1;
    else return 0;
}