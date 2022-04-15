/*
 * get.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Emanuel
 */

#ifndef GET_H_
#define GET_H_
#include <stdio.h>
#include <stdlib.h>

int GetCharacter(char mensaje[],char mensajeError[],char *pCaracter,char maximo, char minimo,int reintentos);

//NUMERICOS
int GetInt(int*numero,char mensaje[],char mensajeError[],int minimo,int maximo,int reintentos);
int GetFloat(float*numero,char mensaje[],char mensajeError[],float minimo,float maximo,int reintentos);


#endif /* GET_H_ */
