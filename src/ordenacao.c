#include<stdio.h>
#include"lista.h"


//typedef int (*operacao)(Forma,Forma);

void heapsort(Forma a[], int n,int z,int(*op)(Forma,Forma)) {
    z++;
   int i = n / 2, pai, filho;
   Forma *t;
   //printf("\n entrou heap %d %d %d\n",i,n,z);

    while(1) {
        
        if(i > 0){
            i--;

            t = a[i];
           /// printf("\n if 1 while%lf\n",getSemaforoX(t));
        }else{
             //printf("\n else 1 while\n");
            n--;
            z--;
            if(n == 0||z==0)return;
            t = a[n];
            a[n] = a[0];
        }
         
        pai = i;
        filho = i * 2 + 1;
        //printf("\n fim 1 while %d %d\n",pai,filho);
        while(filho < n){
            
            if((filho + 1 < n)  &&  op(a[filho + 1] , a[filho])){
                filho++;
                 //printf("\n 1 if 2 while\n");
            }   
            if (op(a[filho] , t)) {
                 //printf("\n 2 if 2 while\n");
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }else{
                 //printf("\n else 2 while\n");
                break;
            }
        }

        a[pai] = t;
    }

}