#ifndef __GEOFILE_H
#define __GEOFILE_H
#include"lista.h"

/*Le arquivo .geo e imprime .svg inicial
pre->parametro != NULL
pos->void */
void leituraGeo(char pathsaida[],char saidasvg[],FILE *arq,Lista listFig, Lista listQua,Lista listRad,Lista listHid,Lista listSem,Lista listPre,Lista listMuro);
#endif