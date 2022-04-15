/*
 * get.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Emanuel
 */

#include "get.h"

/// @fn int GetCharacter(char[], char[], char*, char, char, int)
/// @brief Solicita un caracter al usuario
///
/// @pre
/// @post
/// @param mensaje Mensaje de Solicitud de ingreso
/// @param mensajeError Mensaje de error en la solicitud
/// @param pCaracter Puntero del catacter ingresado
/// @param maximo Valor máximo del caracter a ingresar
/// @param minimo Valor minimo del caracter a ingresar
/// @param reintentos Cantidad de intentos fallidos permitidos
/// @return -1  si salio mal, 0 si salio bien
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


/// @fn int GetInt(int*, char[], char[], int, int, int)
/// @brief Solicita un numero entero al usuario
///
/// @pre
/// @post
/// @param numero Puntero del número a ingresar
/// @param mensaje Mensaje de solicitud de ingreso
/// @param mensajeError Mensaje de error en la solicitud
/// @param minimo Valor minimo a ingresar
/// @param maximo Valor maximo a ingresar
/// @param reintentos Cantidad de intentos fallidos permitidos
/// @return -1 si salio mal, 0 si salio bien
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

/// @fn int GetFloat(float*, char[], char[], float, float, int)
/// @brief Solicita un numero flotante al usuario
///
/// @pre
/// @post
/// @param numero Puntero del número a ingresar
/// @param mensaje Mensaje de solicitud de ingreso
/// @param mensajeError Mensaje de error en la solicitud
/// @param minimo Valor minimo a ingresar
/// @param maximo Valor maximo a ingresar
/// @param reintentos reintentos Cantidad de intentos fallidos permitidos
/// @return -1 si salio mal, 0 si salio bien
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
