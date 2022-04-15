/*
 * get.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Emanuel
 */

#include "get.h"

int GetCharacter(char mensaje[],char mensajeError[],char *pCaracter,char maximo, char minimo,int reintentos)
{
	int rtn;
	rtn = -1;
	char auxiliar;

	if(mensaje != NULL && mensajeError != NULL && pCaracter != NULL && minimo < maximo && reintentos>0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&auxiliar);
			if(auxiliar > maximo || auxiliar < minimo)
			{
				printf("%s",mensajeError);
				reintentos--;
			}
			else
			{
				*pCaracter = auxiliar;
				reintentos = 0;
				rtn = 0;
			}
		}while(reintentos > 0);
	}
	return rtn;
}


int GetInt(int*numero,char mensaje[],char mensajeError[],int minimo,int maximo,int reintentos)
{
    int retorno;
    int buffer;
    retorno = -1;
    if(numero !=NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos>0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);//Validacion por su el usuario ingresa un caracter
            scanf("%d",&buffer);
            if(buffer<minimo || buffer>maximo)
            {
                printf("%s",mensajeError);
                reintentos--;
            }
            else
            {
                retorno = 0;
                reintentos = 0;
                *numero=buffer;
            }

        }while(reintentos>0);
    }

    return retorno;
}

int GetFloat(float*numero,char mensaje[],char mensajeError[],float minimo,float maximo,int reintentos)
{
    int retorno;
    float buffer;
    retorno = -1;
    if(numero !=NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos>0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin); //Validacion por su el usuario ingresa un caracter
            scanf("%f",&buffer);
            if(buffer<minimo || buffer>maximo)
            {
                printf("%s",mensajeError);
                reintentos--;
            }
            else
            {
                retorno = 0;
                reintentos = 0;
                *numero=buffer;
            }

        }while(reintentos>0);
    }

    return retorno;

}
