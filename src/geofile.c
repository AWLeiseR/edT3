#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"qryFile.h"
#include"svgFile.h"
#include"lista.h"
#include"quadra.h"
#include"figuras.h"
#include"radioBase.h"
#include"semaforo.h"
#include"hidrante.h"
#include"predio.h"
#include"muro.h"

void leituraGeo(char pathsaida[],char saidasvg[],FILE *arq,Lista listFig, Lista listQua,Lista listRad,Lista listHid,Lista listSem,Lista listPre,Lista listMuro){  
    Hidrante hid;
    Figura fig;
    Quadra qua;
    Radio ra;
    Semaforo se;
    Predio pre;
    Muro mu;
    FILE *svg;
    
    //char que recebe o identificador de tipo
    char cfill[20] = "yellow";
    char cstrk[20] = "blue";
    char comando[4];
    //string
    //char linha[50];
    char cep[50];
    char i[50];
    char face;
    int num;
    double f;
    double mrg;
    double p;
    char *nomeSaidaGeo;
    //int s=0;
    //inteiro que recebe o identificador das formas
    int id;
    double x,x2,y,y2,w,h,r=5;
    double cw=2.0;
    double rw=3.0;
    double swq,sws,swh,swr;    
    char *line_buf=NULL;
    size_t line_buf_size = 0;
    size_t line_size;
    nomeSaidaGeo=(char *)malloc(strlen(pathsaida)+strlen(saidasvg)*sizeof(char)+3);
    sprintf(nomeSaidaGeo,"%s/%s",pathsaida,saidasvg);
    
   //abertura de arquivos
   //svgGEO
   svg=fopen(nomeSaidaGeo,"w");
   if(svg==NULL){
       printf("\nGEO NAO FOI POSSIVEL ABRIR O ARQ: %s\n",saidasvg);;
        perror("");
        exit(1);
   }
   //printf("\nsaidaSVG=%s\n",saidasvg);
    cabecalho(svg);
   //loop que varre o arquivo .geo
    while(1){
        r=1;
        //pega o comando do arquivo geo
        fscanf(arq,"%s",comando);
        // 'c', circulo
        if(strcmp("c",comando)==0){
            //lea tres doubles responsaveis pelo centro(x,y) e raio depois duas strings responsaveis pelas cores de dentro e da borda
            fscanf(arq,"%d %lf %lf %lf %s %s",&id,&r,&x,&y,cstrk,cfill);
            fig=defineCirculo(comando,id,x,y,r,cstrk,cfill,cw);
            listFig=insert(listFig,fig);
            imprimiCirculo(svg,x,y,r,cstrk,cfill);
            //printf("\n%s %d %lf %lf %lf %s %s\n",comando,id,r,x,y,cstrk,cfill);
        }else if(strcmp("r",comando)==0){//'r',  retangulo               
                //le tquatro doubles responsaveis pel ancora(canto superio esquerdo) e comprimento e altura depois duas strings responsaveis pelas cores de dentro e da borda
                fscanf(arq,"%d %lf %lf %lf %lf %s %s",&id,&w,&h,&x,&y,cstrk,cfill);
                
                fig=defineRetangulo(comando,id,x,y,h,w,cstrk,cfill,rw);
                listFig=insert(listFig,fig);
                imprimiRetangulo(svg,x,y,w,h,cstrk,cfill);
                //printf("%c %d %lf %lf %lf %lf %s %s\n",comando,id,x,y,w,h,cstrk,cfill);
        }else if(strcmp("t",comando)==0){//caso for 't',  texto
                //pega as coordenadas do texto
                fscanf(arq,"%lf %lf",&x,&y);
                //pega a linha toda de testo
                line_size = getline(&line_buf, &line_buf_size, arq);
                //imprime no arquivo
                imprimiTexto(x,y,line_buf,svg);
        }else if(strcmp("q",comando)==0){
            fscanf(arq,"%s %lf %lf %lf %lf",cep,&x,&y,&w,&h);
            //printf("\nQuadra\n");
            qua=defineQuadra(cep,x,y,w,h,cfill,cstrk,swq);
            listQua=insert(listQua,qua);
            
            imprimiRetangulo(svg,x,y,h,w,cstrk,cfill);
        }else if(strcmp("h",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            //printf("\nHidrante\n");
            hid=defineHidrante(i,x,y,cfill,cstrk,swh);
            listHid=insert(listHid,hid);
            //printf("\nInseriu %lf\n",swh);

            imprimiHidrante(svg,x,y,swh,cfill,cstrk);
        }else if(strcmp("s",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            //printf("\nSemaforo\n");
            se=defineSemaforo(i,x,y,cfill,cstrk,sws);
            listSem=insert(listSem,se);
            imprimiSemaforo(svg,x,y,0.0,cfill,cstrk);
        }else if(strcmp("rb",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            //radio=criaRadio();
            ra=defineRadio(i,x,y,cfill,cstrk,swr);
            listRad=insert(listRad,ra);
            //printf("\nRadio-Base\n");
            imprimiRadio(svg,x,y,swr,cstrk,cfill);
        }else if(strcmp("cq",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &swq);
            //printf("\ncores 1\n");

        }else if(strcmp("ch",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &swh);
            //printf("\ncores 2\n");

        }else if(strcmp("cr",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &swr);
            //printf("\ncores 3\n");
                
        }else if(strcmp("cs",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sws);
            //printf("\ncores 4\n");

        }else if(strcmp("sw",comando)==0){
            fscanf(arq,"%lf %lf",&cw, &rw);
            //printf("\nEspessura\n");

        }else if(strcmp("prd",comando)==0){
            fscanf(arq,"%s %c %d %lf %lf %lf ",cep,&face,&num,&f,&p,&mrg);
            int prox=getFirst(listQua);
            qua=getItem(listQua,prox);
            while(prox!=-1) {
                if(strcmp(cep,getQuadraCep(qua))==0){ 
                    x=getQuadraX(qua);
                    y=getQuadraY(qua);
                    w=getQuadraW(qua);
                    h=getQuadraH(qua);
                   switch(face){
                        case 'N':
                            imprimiRetangulo(svg,x+num-(f/2),y+h-mrg-p,p,f,"red","black");
                            pre=definePredio(cep,face,num,f,p,mrg,x+num-(f/2),y+h-mrg-p,f,p);
                            listPre=insert(listPre,pre);
                        break;
                        case 'S':
                            imprimiRetangulo(svg,x+num-(f/2),y+mrg,f,p,"red","black");
                            pre=definePredio(cep,face,num,f,p,mrg,x+num-(f/2),y+mrg,p,f);
                            listPre=insert(listPre,pre);
                        break;
                        case 'L':
                            imprimiRetangulo(svg,x+w-(p+mrg),y+h-(num+(f/2)),p,f,"red","black");
                            pre=definePredio(cep,face,num,f,p,mrg,x+w-(p+mrg),y+h-(num+(f/2)),f,p);
                            listPre=insert(listPre,pre);
                        break;
                        case 'O':
                            imprimiRetangulo(svg,x+mrg,y+(num-(f/2)),p,f,"red","black");
                            pre=definePredio(cep,face,num,f,p,mrg,x+mrg,y+(num-(f/2)),f,p);
                            listPre=insert(listPre,pre);
                        break;
                    }
                    break;
                }else{
                    
                     prox=getProx(listQua,prox); 
                    qua=getItem(listQua,prox); 
                }  
            }
            //printf(" %s %c %d %lf %lf %lf\n ",getPredioCep(pre),getPredioFace(pre),getPredioNum(pre),getPredioF(pre),getPredioP(pre),getPredioMrg(pre));
            
        }else if(strcmp("mur",comando)==0){
            fscanf(arq,"%lf %lf %lf %lf",&x,&y,&x2,&y2);
            mu=defineMuro(x,y,x2,y2);
            listMuro=insert(listMuro,mu);
            imprimiLinha(x,y,x2,y2,svg);
            
        }
            //testa se esta no final do arquivo
            if (feof(arq)){
                //printf("\nFIM\n");
                break; 
            }                    
        }

        
       
    rodape(svg);
    //fecha o arquivo
    fclose(arq);
    fclose(svg);

    
    
    //printf("FIM LEITURA GEO\n");
    //reetorna o ponteiro para formas
    //return void;
//printf("FIM LEITURA GEO\n");
}