#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include "predio.h"
#include"svgFile.h"
#include "geometria.h"
#include "radioBase.h"
#include"ordenacao.h"
#include"muro.h"
#include"segmento.h"
double fx,fy;

void preencheVet(Lista l,Forma vet[]){
    int i;
    int prox=getFirst(l);
    //printf("tamanho l:%d, pri:%d",getOcupados(l),prox);
    for(i=0;i<getOcupados(l);i++){
        vet[i]=getItem(l,prox);
        prox=getProx(l,prox);
       // printf("prox:%d\n",prox);
    }
    //printf("\nFIM\n");
}



int comparaMenorSe(Semaforo s1,Semaforo s2){
    double dis1,dis2;
    //printf("\nentrou comparacao cep=%s %lf cep=%s %lf\n",getSemaforoId(s1),getSemaforoX(s1),getSemaforoId(s2),getSemaforoX(s2));

    dis1=distancia(getSemaforoX(s1),getSemaforoY(s1),fx,fy);
    dis2=distancia(getSemaforoX(s2),getSemaforoY(s2),fx,fy);
    if(dis1<dis2){
        return 1;
    }else{
        return 0;
    }
}

int comparaMenorHid(Hidrante hid1,Hidrante hid2){
    double dis1,dis2;
    //printf("\nentrou comparacao cep=%s %lf cep=%s %lf\n",getSemaforoId(s1),getSemaforoX(s1),getSemaforoId(s2),getSemaforoX(s2));

    dis1=distancia(getHidX(hid1),getHidY(hid1),fx,fy);
    dis2=distancia(getHidX(hid2),getHidY(hid2),fx,fy);
    if(dis1<dis2){
        return 1;
    }else{
        return 0;
    }
}

int comparaMaiorHid(Hidrante hid1,Hidrante hid2){
    double dis1,dis2;
    //printf("\nentrou comparacao cep=%s %lf cep=%s %lf\n",getSemaforoId(s1),getSemaforoX(s1),getSemaforoId(s2),getSemaforoX(s2));

    dis1=distancia(getHidX(hid1),getHidY(hid1),fx,fy);
    dis2=distancia(getHidX(hid2),getHidY(hid2),fx,fy);
    if(dis1>dis2){
        return 1;
    }else{
        return 0;
    }
}

void leituraQry(char pathqry[], char pathsaida[],char sufixogeo[],char sufixoqry[],Lista listFig,Lista listQua,Lista listRad,Lista listHid,Lista listSem,Lista listPre,Lista listMuro){
    Semaforo se;
    Hidrante hid;
    Quadra qua;
    Radio ra;
    Muro mu;
    Predio predio;
    Figura fig1,fig2;
    Ponto pto1,pto2,pto3,pto4;
    Segmento seg;
    //printf("\nTamanho:%d\n",getOcupados(listSem));
    Forma vetSe[getOcupados(listSem)];
    Hidrante vetHid[getOcupados(listHid)];
    //arquivo qry
    FILE *arq;
    //arquivo txt
    FILE *arq2;
    FILE *arq3;
    char vet[4][10]={"brl","fi","fh","fs"};
    int imprimido=0;
    //pega os comandos do qry
    char letra[3];
    //argumentos de bb
    char palavra[50];
    //numero para printar no meio da linha i?
    char string[20];
    //string com o caminho para arq2
    char *saida;
    //string para cep, metricas
    char comando[5];
    char tipo1[20],tipo2[20];
    //char tipo[15];
    char id[30];
    char cstrk[20];
    char face;
    char cep[20];
    //ponteiro para pegar o sufixo de bb
    char *sufixo;
    //ponteiro para pegar cor usada em bb
    char *cor;
    //nome de saida do txt
    char nometxt[]=".txt"; 
    //char sinal;
    //int id;
    //char *svg;
    int num;
    //recebe inteiro que indentifia uma forma
    int k;
    //recebe inteiro que indentifia uma forma
    int j;
    //recebe os valores 1 ou 0, 1 para dentro da forma e 0 para fora
    int res;
    //recebe os valores 1 ou 0, 1 para dsobreposiçao da forma e 0 para nao sobreposição
    int sobre;
    int ns;
    int prox,proxSe,proxRa,proxHid,proxQuad,proxAux,proxFig,proxPre, proxMuro;
    //int padrao,numQua,numSe,numHi,numRa;
    //double que recebe coordenadas dos comandos do qry
    double x;
    double y;
    double w;
    double h;
    double r;
    //double que recebe distancia entre dois pontos
    double dis;
    //double que recebe ponto medio entre dois pontos
    double mx;
    //double que recebe ponto medio entre dois pontos
    double my;
    double dx;
    double dy;
    double cx1,cy1,h1,w1,r1,cx2,cy2,h2,w2,r2;
    double xMaior = x, xMenor = x, yMaior = y, yMenor = y;
    double dis1,dis2;
    //double raios;
    char nomesvg[]=".svg"; 
    char *nomeqry;
    //abre o arq qry só pra leitura
    arq=fopen(pathqry,"r");
    //printf("\n**%s\n",pathqry);
    //testa se esta null
    if(arq==NULL){
        printf("\nQRY NAO ENCONTRADO ARQUIVO %s\n",pathqry);
        perror("");
        exit(1);
    }
    
    //cria um vetor de char do tamannho de pathsaida e de nometxt +2 por causa do / e do /0 
    saida=(char *) malloc(strlen(pathsaida)+strlen(nometxt)+strlen(sufixogeo)+strlen(sufixoqry)*sizeof(char)+2);
    //escreve dentro do vetor de char adcionando o /
    sprintf(saida,"%s/%s%s%s",pathsaida,sufixogeo,sufixoqry,nometxt);
    
    //abre o e cria o arquivo txt de saida
    arq2=fopen(saida,"w");
    //testa se o ponteiro é null
    if(arq2==NULL){
        printf("\n*NAO ENCONTRADO ARQUIVO %s\n",saida);
        perror("");
        exit(1);
   }
    
    nomeqry=(char *)malloc(strlen(pathsaida)+strlen(sufixogeo)+strlen(nomesvg)+strlen(sufixoqry)*sizeof(char)+3);
    sprintf(nomeqry,"%s/%s-%s%s",pathsaida,sufixogeo,sufixoqry,nomesvg);
    //printf("\nnomeQry-%s\n",nomeqry);
    arq3=fopen(nomeqry,"w");

    //testa se o ponteiro é null
    if(arq3==NULL){
        printf("\n*GEO NAO FOI POSSIVEL ABRIR O ARQ: %s\n",nomeqry);
        perror("");
        exit(1);
   }
    
   cabecalho(arq3);
    
    
    
    //loop para varer o arquivo qry
    while(1){
        fscanf(arq,"%s",letra);
        //printf("\n%s\n",letra);
        //testa se ja chegou ao fim do arquivo
        if(feof(arq))
            break;
        if(strcmp(letra,vet[0])==0||strcmp(letra,vet[1])==0||strcmp(letra,vet[2])==0||strcmp(letra,vet[3])==0){
             
             if(!imprimido){
                imprimiSvg(listPre,listFig,listQua,listRad,listHid,listSem,listMuro,arq3);
                imprimido=1;
                preencheVet(listSem,vetSe);
                preencheVet(listHid,vetHid);
            }
            
            
            if(strcmp("brl",letra)==0){
                fscanf(arq,"%lf %lf",&x,&y);
                imprimiCirculo(arq3,x,y,3,"red","yellow");
                int valorTamanho = (getOcupados(listPre)*4 + 2*getOcupados(listMuro));
                Ponto vetorPontos[valorTamanho];
                Segmento vetorSegmentos[valorTamanho*3];
                double xAux,yAux;
                int j = 0;
                k = 0;
                
                //pegando maior ponto
                proxQuad=getFirst(listQua);
                qua=getItem(listQua,proxQuad);
                while(proxQuad!=-1){
                    
                    double xAux1 = getQuadraX(qua);
                    double yAux1 = getQuadraY(qua);
                    double xAux2 = getQuadraX(qua) + getQuadraW(qua);
                    double yAux2 = getQuadraY(qua) + getQuadraH(qua);
                    if(xAux2 > xMaior){
                            xMaior = xAux2;
                        }
                        if (yAux2 > yMaior)
                        {
                            yMaior = yAux2;
                        }
                        if(xAux1 < xMenor){
                            xMenor = xAux1;
                        }
                        if(yAux1 < yMenor){
                            yMenor = yAux1;
                        }
                        proxQuad=getProx(listQua,proxQuad);
                        qua=getItem(listQua,proxQuad);
                }
                proxMuro=getFirst(listMuro);
                mu=getItem(listMuro,proxMuro);
                while(proxMuro!=-1){
                    
                    double xAux1 = getMuroX1(mu);
                    double yAux1 = getMuroY1(mu);
                    double xAux2 = getMuroX2(mu);
                    double yAux2 = getMuroY2(mu);
                    if(xAux2 > xMaior){
                            xMaior = xAux2;
                        }
                    if (yAux2 > yMaior){
                            yMaior = yAux2;
                        }
                    if(xAux1 < xMenor){
                            xMenor = xAux1;
                        }
                    if(yAux1 < yMenor){
                            yMenor = yAux1;
                        }
                    proxMuro=getProx(listMuro,proxMuro);
                    mu=getItem(listMuro,proxMuro);
                }

                xMaior = xMaior + 100;
                yMaior = yMaior + 100;
                xMenor = xMenor - 100;
                yMenor = yMenor - 100;
                imprimiRetangulo(arq3,xMenor,yMenor,yMaior-yMenor,xMaior-xMenor, "black","none");                
                //adicionando pontos retangulo fora
                //ponto cima esquerda
                pto1=definePonto(xMenor,yMenor);
                vetorPontos[j]=pto1;
                j++;
                //ponto cima direita
                pto2=definePonto(xMaior,yMenor);
                vetorPontos[j]=pto2;
                j++;
                //ponto baixo esquerda
                pto3=definePonto(xMenor,yMaior);
                vetorPontos[j]=pto3;
                j++;
                //ponto baixo direita
                pto4=definePonto(xMaior,yMaior);
                vetorPontos[j]=pto4;
                j++;
                int q = 0;
                //INSERE SEGMENTOS
                //segmento cima
                seg=defineSegmento(pto1,pto2);
                vetorSegmentos[q]=seg;
                q++;
                //segmento direita
                seg=defineSegmento(pto2,pto4);
                vetorSegmentos[q]=seg;
                q++;
                //segmento baixo
                seg=defineSegmento(pto3,pto4);
                vetorSegmentos[q]=seg;
                q++;
                //segmento esquerda
                seg=defineSegmento(pto3,pto1);
                vetorSegmentos[q]=seg;
                q++;

                proxPre=getFirst(listPre);
                predio=getItem(listPre,proxPre);

                proxMuro=getFirst(listMuro);
                mu=getItem(listMuro,proxMuro);
                while(proxPre!=-1 || proxMuro!=-1){
                    if(proxPre!=-1){
                        // ponto cima esquerda
                        xAux = getPredioX(predio);
                        yAux = getPredioY(predio);
                        pto1=definePonto(xAux,yAux);
                        vetorPontos[j]=pto1;
                        j++;
                        //ponto cima direita
                        xAux = getPredioX(predio) + getPredioW(predio);
                        yAux = getPredioY(predio);
                        pto2=definePonto(xAux,yAux);
                        vetorPontos[j]=pto2;
                        j++;
                        //ponto baixo esquerda
                        xAux = getPredioX(predio);
                        yAux = getPredioY(predio) + getPredioH(predio);
                        pto3=definePonto(xAux,yAux);
                        vetorPontos[j]=pto3;
                        j++;
                        //ponto baixo direita
                        xAux = getPredioX(predio) + getPredioW(predio);
                        yAux = getPredioY(predio) + getPredioH(predio);
                        pto4=definePonto(xAux,yAux);
                        vetorPontos[j]=pto4;
                        j++;
                        //INSERE SEGMENTOS
                        //segmento cima
                        seg=defineSegmento(pto1,pto2);
                        vetorSegmentos[q]=seg;
                        q++;
                        //
                        seg=defineSegmento(pto3,pto1);
                        vetorSegmentos[q]=seg;
                        q++;
                        //inferior
                        seg=defineSegmento(pto4,pto3);
                        vetorSegmentos[q]=seg;
                        q++;
                        //segmento direita
                        seg=defineSegmento(pto4,pto1);
                        vetorSegmentos[q]=seg;
                        q++;
                    }if(proxMuro!=-1){
                        xAux = getMuroX1(mu);
                        yAux = getMuroY1(mu);
                        pto1=definePonto(xAux,yAux);
                        vetorPontos[j]=pto1;
                        //printf("\nj=>%d\n",j);
                        j++;
                        xAux = getMuroX2(mu);
                        yAux = getMuroY2(mu);
                        pto2=definePonto(xAux,yAux);
                        vetorPontos[j]=pto2;
                        seg=defineSegmento(pto1,pto2);
                        vetorSegmentos[q]=seg;
                        q++;
                        j++;
                    }
                    proxPre=getProx(listPre,proxPre);
                    predio=getItem(listPre,proxPre);

                    proxMuro=getProx(listMuro,proxMuro);
                    mu=getItem(listMuro,proxMuro);
                }
                k = j/4;
                int tamSegmentos = q;
                pto2=definePonto(x,y);
                pto1=definePonto(getPontoX(vetorPontos[1])+50.0,y);
                fprintf(arq3,"<polygon points=\"");
                //superior
                for(double g=xMenor;g<xMaior;g++){
                    pto1=definePonto(g,yMenor);
                    pto4=definePonto(xMaior,yMenor);
                     for(int i = 0;i < tamSegmentos;i++){
                        pto3=NULL;
                        pto3=pontoIntersecao(pto2,pto1,getSegmentoIni(vetorSegmentos[i]),getSegmentoFim(vetorSegmentos[i]));
                        if(pto3){
                            dis1=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto3),getPontoY(pto3));
                            dis2=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto4),getPontoY(pto4));
                            if(dis1<dis2){
                                pto4=definePonto(getPontoX(pto3),getPontoY(pto3));    
                            }
                        }
                    }
                    fprintf(arq3,"%lf,%lf ",getPontoX(pto4),getPontoY(pto4));
                }
                 //esquerdo
                for(double g=yMenor;g<yMaior;g++){
                    pto1=definePonto(xMenor,g);
                    pto4=definePonto(xMenor,yMaior);
                     for(int i = 0;i < tamSegmentos;i++){
                        pto3=NULL;
                        pto3=pontoIntersecao(pto2,pto1,getSegmentoIni(vetorSegmentos[i]),getSegmentoFim(vetorSegmentos[i]));
                        if(pto3){
                            dis1=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto3),getPontoY(pto3));
                            dis2=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto4),getPontoY(pto4));
                            if(dis1<dis2){
                                pto4=definePonto(getPontoX(pto3),getPontoY(pto3));    
                            }
                        }
                    }
                    fprintf(arq3,"%lf,%lf ",getPontoX(pto4),getPontoY(pto4));
                }  
                 //inferior
                for(double g=xMenor;g<xMaior;g++){
                    pto1=definePonto(g,yMaior);
                    pto4=definePonto(xMenor,yMaior);
                     for(int i = 0;i < tamSegmentos;i++){
                        pto3=NULL;                      
                        pto3=pontoIntersecao(pto2,pto1,getSegmentoIni(vetorSegmentos[i]),getSegmentoFim(vetorSegmentos[i]));
                        if(pto3){
                            dis1=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto3),getPontoY(pto3));
                            dis2=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto4),getPontoY(pto4));
                            if(dis1<dis2){
                                pto4=definePonto(getPontoX(pto3),getPontoY(pto3));    
                            }
                        }
                    }
                    fprintf(arq3,"%lf,%lf ",getPontoX(pto4),getPontoY(pto4));
                }
                //direita
                for(double g=yMaior;g>yMenor;g--){
                    //printf("%lf ",g);
                    pto1=definePonto(xMaior,g);
                    pto4=definePonto(xMaior,yMenor);
                     for(int i = 0;i < tamSegmentos;i++){
                        pto3=NULL;                      
                        pto3=pontoIntersecao(pto2,pto1,getSegmentoIni(vetorSegmentos[i]),getSegmentoFim(vetorSegmentos[i]));
                        if(pto3){
                            dis1=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto3),getPontoY(pto3));
                            dis2=distancia(getPontoX(pto2),getPontoY(pto2),getPontoX(pto4),getPontoY(pto4));
                            if(dis1<dis2){
                                pto4=definePonto(getPontoX(pto3),getPontoY(pto3));    
                            }
                        }
                    }
                    fprintf(arq3,"%lf,%lf ",getPontoX(pto4),getPontoY(pto4));
                }    
                fprintf(arq3,"\"  fill=\"lime\" fill-opacity=\"0.5\" />");
        
            }else if(strcmp("fi",letra)==0){
                //printf("\nentrooou\n");
            
                fscanf(arq,"%lf %lf %d %lf",&fx,&fy,&ns,&r);
                fprintf(arq2,"%s %lf %lf %d %lf\nSemafaros que devem ser aletrados:\n",letra,fx,fy,ns,r);
                
                heapsort(vetSe,getOcupados(listSem),ns,comparaMenorSe);
                for(int q= getOcupados(listSem)-ns;q<getOcupados(listSem);q++){
                    fprintf(arq2,"%s ",getSemaforoId(vetSe[q]));
                    imprimiLinha(getSemaforoX(vetSe[q])-1,getSemaforoY(vetSe[q])-1,fx,fy,arq3);
                    imprimiCirculo(arq3,getSemaforoX(vetSe[q]),getSemaforoY(vetSe[q]),5,"green","none");
                }
                fprintf(arq2,"\nHidrantes quem devem ser alterados: \n");
                proxHid=getFirst(listHid);
                hid=getItem(listHid,proxHid);
                while(proxHid!=-1){
                    //printf("\n%lf,%lf %lf dis=%lf\n",getHidX(hid),getHidY(hid),r,distancia(getHidX(hid),getHidY(hid),fx,fy));
                    if(distancia(getHidX(hid),getHidY(hid),fx,fy)<=r){
                        fprintf(arq2,"%s ",getHidId(hid));
                        imprimiLinha(getHidX(hid)-1,getHidY(hid)-1,fx,fy,arq3);
                        imprimiCirculo(arq3,getHidX(hid),getHidY(hid),5,"red","none");
                    }
                    proxHid=getProx(listHid,proxHid);
                    hid=getItem(listHid,proxHid);
                }
                //printf("\nentrou2\n");
            }else if(strcmp("fs",letra)==0){
                fscanf(arq,"%d %s %c %d",&k,cep,&face,&num);
                fprintf(arq3," %d %s %c %d\n",k,cep,face,num);
                proxPre=getFirst(listPre);
                predio=getItem(listPre,proxPre);
                while(proxPre!=-1){
                    if(proxPre!=-1 && strcmp(getPredioCep(predio),cep)==0 && getPredioFace(predio)==face && getPredioNum(predio)==num){
                        switch(face){
                            case'N':
                                fx=getPredioX(predio)+(getPredioF(predio)/2);
                                fy=getPredioY(predio)+getPredioP(predio);
                                break;
                            case'S':
                                fx=getPredioX(predio)+(getPredioF(predio)/2);
                                fy=getPredioY(predio);
                                break;
                            case'L':
                                fx=getPredioX(predio)+getPredioP(predio);
                                fy=getPredioY(predio)+(getPredioF(predio)/2);
                                break;
                            case'O':
                                fx=getPredioX(predio);
                                fy=getPredioY(predio)+(getPredioF(predio)/2);
                                break;
                        }
                        break;
                    }
                    proxPre=getProx(listPre,proxPre);
                    predio=getItem(listPre,proxPre);

                }
                heapsort(vetSe,getOcupados(listSem),k,comparaMenorSe);
                fprintf(arq3,"Semaforos mais proximos:");
                for(int q= getOcupados(listSem)-k;q<getOcupados(listSem);q++){
                    fprintf(arq2,"%s ",getSemaforoId(vetSe[q]));
                    imprimiLinha(getSemaforoX(vetSe[q])-1,getSemaforoY(vetSe[q])-1,fx,fy,arq3);
                    imprimiCirculo(arq3,getSemaforoX(vetSe[q]),getSemaforoY(vetSe[q]),5,"green","none");
                }

            }else if(strcmp("fh",letra)==0){
                fscanf(arq,"%d %s %c %d",&k,cep,&face,&num);
                fprintf(arq2," %d %s %c %d\n",k,cep,face,num);
                proxPre=getFirst(listPre);
                predio=getItem(listPre,proxPre);
                while(proxPre!=-1){
                    if(proxPre!=-1 && strcmp(getPredioCep(predio),cep)==0 && getPredioFace(predio)==face && getPredioNum(predio)==num){
                        switch(face){
                            case'N':
                                fx=getPredioX(predio)+(getPredioF(predio)/2);
                                fy=getPredioY(predio)+getPredioP(predio);
                                break;
                            case'S':
                                fx=getPredioX(predio)+(getPredioF(predio)/2);
                                fy=getPredioY(predio);
                                break;
                            case'L':
                                fx=getPredioX(predio)+getPredioP(predio);
                                fy=getPredioY(predio)+(getPredioF(predio)/2);
                                break;
                            case'O':
                                fx=getPredioX(predio);
                                fy=getPredioY(predio)+(getPredioF(predio)/2);
                                break;
                        }
                        break;
                    }
                    proxPre=getProx(listPre,proxPre);
                    predio=getItem(listPre,proxPre);

                }
                if(k>0){
                    heapsort(vetHid,getOcupados(listHid),k,comparaMaiorHid);
                    fprintf(arq2,"Hidrantes Mais proximos: ");
                }else if(k<0){
                    k=k*-1;
                    heapsort(vetHid,getOcupados(listHid),k,comparaMenorHid);
                    fprintf(arq2,"Hidrantes Mais distantes: ");
                }
                
                for(int q=getOcupados(listHid)-k;q<getOcupados(listHid);q++){
                    fprintf(arq2,"%s ",getHidId(vetHid[q]));
                    imprimiLinha(getHidX(vetHid[q])-1,getHidY(vetHid[q])-1,fx,fy,arq3);
                    imprimiCirculo(arq3,getHidX(vetHid[q]),getHidY(vetHid[q]),5,"green","none");
                }
            }
        }
       //comando bb: faz um retangulo em volta dos circulos e faz um circulo dentro dos retangulos PRODUZ UM ARQUIVO SEPARADO
       //verifica se letra é = a bb
        else if(strcmp("bb",letra)==0){
            //le o string seguinte e armazena em palavra
            fscanf(arq,"%s",palavra);
            //cria uma string com o tamanho de palavra +1(por causa do /0)
            sufixo=(char *)malloc(strlen(palavra)*sizeof(char)+1);
            //copia o q esta dentro de palavra para sufixo
            strcpy(sufixo,palavra);
            //le a proxima string e armazena em palavra
            fscanf(arq,"%s",palavra);
            //cria uma string do tamanho da string escrita em palavra
            cor=(char *)malloc(strlen(palavra)*sizeof(char)+1);
            //copia o que esta em palavra para cor
            strcpy(cor,palavra);
            //chama função que cria um svg separado, enviando a struct forma, pathsaida, sufixo para o nome do arquivo e cor que sera usada nas boradas das formas
            imprimiSvgbb(listFig,pathsaida,sufixo,cor,sufixogeo);
            free(cor);
            free(sufixo);
        //o?:Sobreposição de formas 
        //confere se a string letra é igual a o?
        }else  if(strcmp("o?",letra)==0){
            //pega os dois inteiros (identificadores) seguintes e armazena em 'j' e 'k' respectivamente
            fscanf(arq," %d %d",&j,&k);

            prox=getFirst(listFig);
            fig1=getItem(listFig,prox);
            while(prox!=-1){
                if(j==getFiguraId(fig1)){
                    strcpy(tipo1,getFiguraTipo(fig1));
                    break;
                }else{
                    prox=getProx(listFig,prox);
                    fig1=getItem(listFig,prox);  
                }
            }
            
             prox=getFirst(listFig);
            fig2=getItem(listFig,prox);
            while(prox!=-1){
                if(k==getFiguraId(fig2)){
                    strcpy(tipo2,getFiguraTipo(fig2));
                    break;
                }else{
                    prox=getProx(listFig,prox);
                    fig2=getItem(listFig,prox);  
                }
            }
            //res(resultado),dis(distancia),raios(soma dos raios ou so o raio)
        
            //verifica se as duas formas sao circulos
            if(strcmp(tipo1,"c")==0&& strcmp(tipo2,"c")==0){
                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                r1=getCirculoR(fig1);
                r2=getCirculoR(fig2);
                sobre=sobreposicaoCirculoCirculo(cx1,cy1,r1,cx2,cy2,r2,"green",arq3);                    
            //verifica se as formas sao um retangulo e um circulo
            }else if(strcmp(tipo1,"r")==0&& strcmp(tipo2,"c")==0){
                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                r1=getCirculoR(fig1);

                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                w1=getRetanguloW(fig2);
                h1=getRetanguloH(fig2);
                sobre=sobreposicaoCirculoRetangulo(cx1,cy1,r1,cx2, cy2,h1,w1,"green",arq3);
            //verifica se as formas sao um circulo e um retangulo    
            }else if(strcmp(tipo1,"c")==0&& strcmp(tipo2,"r")==0){
                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                r1=getCirculoR(fig1);
               
                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                w2=getRetanguloW(fig2);
                h2=getRetanguloH(fig2);

                sobre=sobreposicaoCirculoRetangulo(cx1,cy1,r1,cx2,cy2,h2,w2,"green",arq3);
                res=collision(cx2,cy2,w2,h2,cx1,cy1,r1);
                w=max(cx2+w2,cx1+r1)-min(cx2,cx1-r1);    
                h=max(cy2+h2,cy1+r1)-min(cy2,cy1-r1);
               imprimiRetanguloDash(min(cx2,cx1-r1),min(cy2,cy1-r1),w,h,"green",arq3,res);
            //verifica se as duas formas sao retangulos
            }else if(strcmp(tipo1,"r")==0&& strcmp(tipo2,"r")==0){
                cx1=getFiguraX(fig1);
                cy1=getFiguraX(fig1);
                w1=getRetanguloW(fig1);
                h1=getRetanguloH(fig1);

                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                w2=getRetanguloW(fig2);
                h2=getRetanguloH(fig2);

                sobre=sobreposicaoRetanguloRetangulo(cx1,cy1,h1,w1,cx2,cy2,h2,w2,"green",arq3);                
            }
            //escreve no arquivo txt o enuciado
            fprintf(arq2,"%s %d %d\n%s\n",letra,j,k, sobre? "SIM":"NAO");
        //i?:Ponto dentro ou fora formas
        //confere se a string letra é igual a i?
        }else  if(strcmp("i?",letra)==0){
            //pega o identificador 'j' e as duas coordenadas 'x' e 'y' seguintes
            fscanf(arq," %d %lf %lf",&j,&x,&y);
            //printf(" %d %lf %lf",j,x,y);
            prox=getFirst(listFig);
            fig1=getItem(listFig,prox);
            while(prox!=-1){
                if(j==getFiguraId(fig1)){
                    //tipo1=getFiguraTipo(fig1);
                    break;
                }else{
                    prox=getProx(listFig,prox);
                    fig1=getItem(listFig,prox);  
                }
            }
            strcpy(tipo1,getFiguraTipo(fig1));
            //tipo1=getFiguraTipo(fig1);
            //testa se a forma na posição j é um retangulo
            if(strcmp(tipo1,"r")==0){
                
                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                w1=getRetanguloW(fig1);
                h1=getRetanguloH(fig1);
                //chama a função q retorna um inteiro para testar se o ponto esta dentro ou fora do retangulo
                res=pontoInteriorRetangulo(x,y,cx1,cy1,w1+cx1,h1+cy1);
                //chama a função que cria uma linha entre o ponto e o centro de massa do retangulo
                imprimiLinha(x,y,w1/2+cx1,h1/2+cy1,arq3);
            }
            //testa se a forma na posição j é um circulo
            else if(strcmp(tipo1,"c")==0){
                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                r1=getCirculoR(fig1);
                
                //chama a função q retorna um inteiro para testar se o ponto esta dentro ou fora do circulo
                res=pontoInternoCirculo(x,y,cx1,cy1,r1);
                //chama a função que cria uma linha entre o ponto e o centro de massa do circulo
                imprimiLinha(x,y,cx1,cy1,arq3);
            }
            //cria um circulo de raio pequeno se res for 1(dentro) manda como parameetro a cor green se nao 0 (fora) manda red
            imprimiCirculo(arq3,x,y,5,res?"green":"red",res?"green":"red");
            //escreve no arquivo o enunciado e na linha de baixo see esta dentro ou fora
            fprintf(arq2,"%s %d %lf %lf\n%s\n",letra,j,x,y,res? "interno" : "externo" );
        //d?:distancia entra o centro de massa das formas
        //confere se a string letra é igual a d?
        }else  if(strcmp("d?",letra)==0){
            //pega o identificador 'j' e o identificador 'k'
            fscanf(arq," %d %d",&j,&k);
            //printf(" %d %d",j,k);

            prox=getFirst(listFig);
            fig1=getItem(listFig,prox);
            while(prox!=-1){
                if(j==getFiguraId(fig1)){
                    strcpy(tipo1,getFiguraTipo(fig1));
                    break;
                }else{
                    prox=getProx(listFig,prox);
                    fig1=getItem(listFig,prox);  
                }
            }
            
             prox=getFirst(listFig);
            fig2=getItem(listFig,prox);
            while(prox!=-1){
                if(k==getFiguraId(fig2)){
                    strcpy(tipo2,getFiguraTipo(fig2));
                    break;
                }else{
                    prox=getProx(listFig,prox);
                    fig2=getItem(listFig,prox);  
                }
            }
            //testa se a forma j e a forma k sao circulos
           if(strcmp(tipo1,"c")==0&& strcmp(tipo2,"c")==0){
                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                r1=getCirculoR(fig1);

                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                r2=getCirculoR(fig2);

                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1,cy1,cx2,cy2);
                //chama a função que cria uma linha entre o centro de massa dos dois circulos
                imprimiLinha(cx1,cy1,cx2,cy2,arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+cx2)/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+cy2)/2;

            //testa se a forma j e a forma k sao um retangulo e um circulo
            }else if(strcmp(tipo1,"r")==0&& strcmp(tipo2,"c")==0){

                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                w1=getRetanguloW(fig1);
                h1=getRetanguloH(fig1);

                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                r2=getCirculoR(fig2);

                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1+(w1/2),cy1+(h1/2),cx2,cy2);
                //chama a função que cria uma linha entre o centro de massa do retangulo e do circulo
                imprimiLinha(cx1+(w1/2),cy1+(h1/2),cx2,cy2,arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+(w1/2)+cx2)/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+(h1/2)+cy2)/2;
                
            //testa se a forma j e a forma k sao dois retangulos
            }else if(strcmp(tipo1,"r")==0&& strcmp(tipo2,"r")==0){

                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                w1=getRetanguloW(fig1);
                h1=getRetanguloH(fig1);

                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                w2=getRetanguloW(fig2);
                h2=getRetanguloH(fig2);

                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1+(w1/2),cy1+(h1/2),cx2+(w2/2),cy2+(h2/2));
                //chama a função que cria uma linha entre o centro de massa dos dois retangulos
                imprimiLinha(cx1+(w1/2),cy1+(h1/2),cx2+(w2/2),cy2+(h2/2),arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+(w1/2)+cx2+(w1/2))/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+(h1/2)+cy2+(h1/2))/2;
                
            //testa se a forma j e a forma k sao um circulo e um retangulo
            }else if(strcmp(tipo1,"c")==0&& strcmp(tipo2,"r")==0){

                cx1=getFiguraX(fig1);
                cy1=getFiguraY(fig1);
                r1=getCirculoR(fig1);

                cx2=getFiguraX(fig2);
                cy2=getFiguraY(fig2);
                w2=getRetanguloW(fig2);
                h2=getRetanguloH(fig2);

                //chama a funçao distancia que calcula a distancia entre dois pontos e armazena o resultado em dis
                dis=distancia(cx1,cy1,cx2+(w2/2),cy2+(h2/2));
                //chama a função que cria uma linha entre o centro de massa do circulo e do retangulo
                imprimiLinha(cx1,cy1,cx2+(w2/2),cy2+(h2/2),arq3);
                //escreve/transforma dis (double) em uma string
                sprintf(string,"%lf",dis);
                //calcula a coordenada x do ponto medio
                mx=(cx1+cx2+(w2/2))/2;
                //calcula a coordenada y do ponto medio
                my=(cy1+cy2+(h2/2))/2;    
            }
            //escreve a distancia entre os dois pontos no arquivo svg no ponto meido
            imprimiTexto(mx,my,string,arq3);
            //escreve no arquivo txt o enunciado e a resposta na linha seguinte
            fprintf(arq2,"%s %d %d \n%lf\n",letra,j,k,dis);
        }else if(strcmp("dq",letra)==0){
            fscanf(arq,"%s %s %lf",comando,id,&dis);
            fprintf(arq2,"%s %s %s %lf\n",letra,comando,id,dis);
            
            proxHid=getFirst(listHid);
            proxSe=getFirst(listSem);
            proxRa=getFirst(listRad);

            se=getItem(listSem,proxSe);
            hid=getItem(listHid,proxHid);
            ra=getItem(listRad,proxRa);
            
            while(proxHid!=-1||proxRa!=-1||proxSe!=-1){
                //printf("\n%s\n",getSemaforoId(se));
                if(proxHid!=-1 && strcmp(id,getHidId(hid))==0){
                    strcpy(tipo1,getHidId(hid));
                    cx1=getHidX(hid);
                    cy1=getHidY(hid);
                    setHidCstrk(hid,"black");
                    //printf("\nencontrouHid\n");
                    break;
                }else if(proxSe!=-1 && strcmp(id,getSemaforoId(se))==0){
                    strcpy(tipo1,getSemaforoId(se));
                    cx1=getSemaforoX(se);
                    cy1=getSemaforoY(se);
                    setSemaforoCstrk(se,"black");
                    //printf("\nencontrouSe\n");
                    break;
                }else if(proxRa!=-1 && strcmp(id,getRadioId(ra))==0){
                    cx1=getRadioX(ra);
                    cy1=getRadioY(ra);
                    setRadioCstrk(ra,"black");
                    strcpy(tipo1,getRadioId(ra));
                    //printf("\nencontrouRadio\n");
                    break;                 
                }else{
                    proxHid=getProx(listHid,proxHid);
                    hid=getItem(listHid,proxHid);

                    proxRa=getProx(listRad,proxRa);
                    ra=getItem(listRad,proxRa);  

                    proxSe=getProx(listSem,proxSe);
                    se=getItem(listSem,proxSe);
                }
            }
            
            prox=getFirst(listQua);
            //printf("\n%d\n",prox);
            while(prox!=-1){
                proxAux=prox;
                prox=getProx(listQua,prox);
                qua=getItem(listQua,proxAux);
                x=getQuadraX(qua);
                y=getQuadraY(qua);
                w=getQuadraW(qua);
                h=getQuadraH(qua);
                
                if(strcmp("L1",comando)==0||strcmp("l1",comando)==0){
                    if(retanguloInteriorLosango(dis,cx1,cy1,x,y,w,h)){
                        fprintf(arq2,"\n%s ",getQuadraCep(qua));
                                                    
                        delet(listQua,proxAux);
                    }
                }else if(strcmp("L2",comando)==0||strcmp("l2",comando)==0){
                    //printf("\n%s %d\n",getQuadraCep(qua),retanguloInteriorCirculo(x,y,w,y,cx1,cy1,dis));
                    if(retanguloInteriorCirculo(x,y,w,y,cx1,cy1,dis)){
                        fprintf(arq2,"\n%s ",getQuadraCep(qua));
                        //printf("\nescreveu\n");                            
                        delet(listQua,proxAux);
                    }
                }
            
            }
        }else if(strcmp("del",letra)==0){
            fscanf(arq,"%s",id);
            fprintf(arq2,"\n%s\n%s",letra,id);
            proxQuad=getFirst(listQua);
            proxHid=getFirst(listHid);
            proxSe=getFirst(listSem);
            proxRa=getFirst(listRad);
        
            qua=getItem(listQua,proxQuad);
            se=getItem(listSem,proxSe);
            hid=getItem(listHid,proxHid);
            ra=getItem(listRad,proxRa);
            while(proxQuad!=-1||proxHid!=-1||proxRa!=-1||proxSe!=-1){
                //printf("\n%s\n",getSemaforoId(se));
                if(proxHid!=-1 && strcmp(id,getHidId(hid))==0){
                    fprintf(arq2," %lf %lf\n",getHidX(hid),getHidY(hid));
                    delet(listHid,proxHid);
                    //printf("\nencontrouHid\n");
                    break;
                }else if(proxSe!=-1 && strcmp(id,getSemaforoId(se))==0){
                    fprintf(arq2," %lf %lf\n",getSemaforoX(se),getSemaforoY(se));
                    delet(listSem,proxSe);
                    //printf("\nencontrouSe\n");
                    break;
                }else if(proxRa!=-1 && strcmp(id,getRadioId(ra))==0){
                    fprintf(arq2," %lf %lf \n",getRadioX(ra),getRadioY(ra));
                    delet(listRad,proxRa);
                    //printf("\nencontrouRadio\n");
                    break;                 
                }else if(proxQuad!=-1 && strcmp(id,getQuadraCep(qua))==0){
                    //printf("\nencontrouQuadra\n");
                    fprintf(arq2," %lf %lf %lf %lf\n",getQuadraX(qua),getQuadraY(qua),getQuadraW(qua),getQuadraH(qua));
                    delet(listQua,proxQuad);
                    
                    
                    break;                 
                }else{
                    proxQuad=getProx(listQua,proxQuad);
                    qua=getItem(listQua,proxQuad);

                    proxHid=getProx(listHid,proxHid);
                    hid=getItem(listHid,proxHid);

                    proxRa=getProx(listRad,proxRa);
                    ra=getItem(listRad,proxRa);  

                    proxSe=getProx(listSem,proxSe);
                    se=getItem(listSem,proxSe);
                }
            }
            
            
        }else if(strcmp("cbq",letra)==0){
            fscanf(arq,"%lf %lf %lf %s",&cx1,&cy1,&r1,cstrk);
           fprintf(arq2,"%s\n%lf %lf %lf %s\n",letra,cx1,cy1,r1,cstrk);
            proxQuad=getFirst(listQua);
            qua=getItem(listQua,proxQuad);
            while(proxQuad!=-1){
                if(proxQuad!=-1&&retanguloInteriorCirculo(getQuadraX(qua),getQuadraY(qua),getQuadraW(qua),getQuadraH(qua),cx1,cy1,r1)){
                    fprintf(arq2,"%s ",getQuadraCep(qua));
                    setQuadraCstrk(qua,cstrk);
                }
                proxQuad=getProx(listQua,proxQuad);
                qua=getItem(listQua,proxQuad);
            }
        }else if(strcmp("crd?",letra)==0){
            fscanf(arq,"%s",comando);
            
            proxQuad=getFirst(listQua);
            proxHid=getFirst(listHid);
            proxSe=getFirst(listSem);
            proxRa=getFirst(listRad);
            //printf("\nproxFig=%d,proxQuad=%d,proxSe=%d,proxHid=%d,proxRa=%d\n",proxFig,proxQuad,proxSe,proxHid,proxRa);
            
            qua=getItem(listQua,proxQuad);
            se=getItem(listSem,proxSe);
            hid=getItem(listHid,proxHid);
            ra=getItem(listRad,proxRa);
            while(proxQuad!=-1||proxSe!=-1||proxHid!=-1||proxRa!=-1){
                if(proxQuad!=-1&&strcmp(comando,getQuadraCep(qua))==0){
                    fprintf(arq2,"\n%s %s\nQuadra %s %lf %lf\n",letra,comando,getQuadraCep(qua),getQuadraX(qua),getQuadraY(qua));
                    break;
                }else if(proxSe!=-1&&strcmp(comando,getSemaforoId(se))==0){
                    fprintf(arq2,"\n%s %s\nSemaforo %s %lf %lf\n",letra,comando,getSemaforoId(se),getSemaforoX(se),getSemaforoY(se));
                    break;
                }else if(proxHid!=-1&&strcmp(comando,getHidId(hid))==0){
                    fprintf(arq2,"\n%s %s\nHidrante %s %lf %lf\n",letra,comando,getHidId(hid),getHidX(hid),getHidY(hid));
                    break;
                }else if(proxRa!=-1&&strcmp(comando,getRadioId(ra))==0){
                    fprintf(arq2,"\n%s %s\nRadio Base %s %lf %lf\n",letra,comando,getRadioId(ra),getRadioX(ra),getRadioY(ra));
                    break;
                }
                proxQuad=getProx(listQua,proxQuad);
                proxHid=getProx(listHid,proxHid);
                proxSe=getProx(listSem,proxSe);
                proxRa=getProx(listRad,proxRa);
                //printf("\nproxFig=%d,proxQuad=%d,proxSe=%d,proxHid=%d,proxRa=%d\n",proxFig,proxQuad,proxSe,proxHid,proxRa);

                qua=getItem(listQua,proxQuad);
                se=getItem(listSem,proxSe);
                hid=getItem(listHid,proxHid);
                ra=getItem(listRad,proxRa);
            }
        }else if(strcmp("trns",letra)==0){
            fscanf(arq,"%lf %lf %lf %lf %lf %lf",&x,&y,&w,&h,&dx,&dy);
            proxQuad=getFirst(listQua);
            proxHid=getFirst(listHid);
            proxSe=getFirst(listSem);
            proxRa=getFirst(listRad);
            //printf("\nproxQuad=%d,proxSe=%d,proxHid=%d,proxRa=%d\n",proxQuad,proxSe,proxHid,proxRa);
            
            qua=getItem(listQua,proxQuad);
            se=getItem(listSem,proxSe);
            hid=getItem(listHid,proxHid);
            ra=getItem(listRad,proxRa);
            while(proxQuad!=-1||proxSe!=-1||proxHid!=-1||proxRa!=-1){
                                
                if(proxQuad!=-1&&retanguloInteriorRetangulo(getQuadraX(qua),getQuadraY(qua),getQuadraW(qua),getQuadraH(qua),x,y,w,h)){
                    fprintf(arq2,"\n%s \n%s %lf %lf ",letra,getQuadraCep(qua),getQuadraX(qua),getQuadraY(qua));
                    deslocaQuadra(qua,dx,dy);
                    fprintf(arq2,"Coordenadas atualizadas: %lf %lf",getQuadraX(qua),getQuadraY(qua));
                    
                }
                if(proxSe!=-1&&pontoInteriorRetangulo(getSemaforoX(se),getSemaforoY(se),x,y,x+w,y+h)){
                    //printf("\nSemaforo\n"); 
                    fprintf(arq2,"\n%s \n%s %lf %lf ",letra,getSemaforoId(se),getSemaforoX(se),getSemaforoY(se));
                    deslocaSemaforo(se,dx,dy);
                    fprintf(arq2,"Coordenadas atualizadas: %lf %lf",getSemaforoX(se),getSemaforoY(se));
                    
                }
                if(proxHid!=-1&&pontoInteriorRetangulo(getHidX(hid),getHidY(hid),x,y,x+w,y+h)){
                    fprintf(arq2,"\n%s \n%s %lf %lf ",letra,getHidId(hid),getHidX(hid),getHidY(hid));
                    deslocaHidrante(hid,dx,dy);
                    fprintf(arq2,"Coordenadas atualizadas: %lf %lf",getHidX(hid),getHidY(hid));
                   
                }
                if(proxRa!=-1&&pontoInteriorRetangulo(getRadioX(ra),getRadioY(ra),x,y,x+w,y+h)==1){
                    //printf("\nRAdio\n");    
                    fprintf(arq2,"\n%s \n%s %lf %lf ",letra,getRadioId(ra),getRadioX(ra),getRadioY(ra));
                    deslocaRadio(ra,dx,dy);
                    fprintf(arq2,"Coordenadas atualizadas: %lf %lf",getRadioX(ra),getRadioY(ra));
                    
                }
                proxQuad=getProx(listQua,proxQuad);
                proxHid=getProx(listHid,proxHid);
                proxSe=getProx(listSem,proxSe);
                proxRa=getProx(listRad,proxRa);
                //printf("\nproxQuad=%d,proxSe=%d,proxHid=%d,proxRa=%d\n",proxQuad,proxSe,proxHid,proxRa);
                
                qua=getItem(listQua,proxQuad);
                se=getItem(listSem,proxSe);
                hid=getItem(listHid,proxHid);
                ra=getItem(listRad,proxRa);
            }
        }
    }
    //printf("\nfim qry\n");
    //escreve arquivo svg 
    if(!imprimido){
        imprimiSvg(listPre,listFig,listQua,listRad,listHid,listSem,listMuro,arq3); 
    }
    
    rodape(arq3);
    //fecha os arquivos
    fclose(arq);
    fclose(arq2);
    fclose(arq3);
    
    //desaloca as memorias
    free(saida);
    
}