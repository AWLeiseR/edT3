#ifndef _MURO_H
#define _MURO_H
/*=====================================================
aqui estão todos os get and set para os muros
Muro é enxergado pelo resto do software como um void*
=======================================================*/
typedef void* Muro;
/*pré parametros nao devem ser null
pos retorna um Muro(void*) */
Muro defineMuro(double pX1,double pY1,double pX2,double pY2);
/*pré parametros nao devem ser null
pos retorna um double */ 
double getMuroX1(Muro muro);
/*pré parametros nao devem ser null
pos retorna um double */
double getMuroX2(Muro muro);
/*pré parametros nao devem ser null
pos retorna um double */
double getMuroY1(Muro muro);
/*pré parametros nao devem ser null
pos retorna um double */
double getMuroY2(Muro muro);

#endif