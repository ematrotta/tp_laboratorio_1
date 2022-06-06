/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

/// @fn Passenger Passenger_new*()
/// @brief Encontrar un puntero dinamico
///
/// @pre
/// @post
/// @return puntero a pasajero o NULL en caso de no haberlo encontrado
Passenger* Passenger_new()
{
	Passenger* p;
	p = (Passenger*)malloc(sizeof(Passenger));
	return p;
}
/*
 * 	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;*/


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoStr,char* estadoStr)
{
	Passenger* pAux;
	pAux = Passenger_new();

	if(pAux != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoStr != NULL && estadoStr != NULL)
	{
		if(Passenger_setId(pAux,atoi(idStr)) != 0 || Passenger_setNombre(pAux, nombreStr) != 0 || Passenger_setApellido(pAux, apellidoStr) != 0 ||
				Passenger_setCodigoVuelo(pAux, codigoStr) != 0 || Passenger_setEstadoVuelo(pAux, estadoStr) != 0 ||	Passenger_setTipoPasajero(pAux, tipoPasajeroStr) != 0 || Passenger_setPrecio(pAux, atof(precioStr)) )
		{
			pAux = NULL;
		}

	}
	return pAux;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int Passenger_setId(Passenger* this,int id)
{
	int retorno;
	retorno = -1;
	if(this != NULL && id >0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno;
	retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,TAM_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,TAM_NOMBRE);
		retorno = 0;
	}
	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(this->apellido,apellido,TAM_APELLIDO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido,this->apellido,TAM_APELLIDO);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,TAM_CODIGOVUELO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,TAM_CODIGOVUELO);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(this->tipoPasajero,tipoPasajero,TAM_TIPOPASAJERO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;
	retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(tipoPasajero,this->tipoPasajero,TAM_TIPOPASAJERO);
		retorno = 0;
	}
	return retorno;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;
	retorno = -1;
	if(this != NULL && precio >0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;
	retorno = -1;
	if(this != NULL && precio >0)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(this->estadoVuelo,estadoVuelo,TAM_ESTADOVUELO);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;
	retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		strncpy(estadoVuelo,this->estadoVuelo,TAM_ESTADOVUELO);
		retorno = 0;
	}
	return retorno;
}

int Passenger_printOne(Passenger* this)
{
	int retorno;
	retorno = -1;

	int auxId;
	char auxNombre[TAM_NOMBRE];
	char auxApellido[TAM_APELLIDO];
	float auxPrecio;
	char auxTipoPasajero[TAM_TIPOPASAJERO];
	char auxCodigoVuelo[TAM_CODIGOVUELO];
	char auxEstadoVuelo[TAM_ESTADOVUELO];

	if(this != NULL)
	{
		if(auxNombre!= NULL && auxApellido != NULL && auxTipoPasajero != NULL && auxCodigoVuelo != NULL && auxEstadoVuelo != NULL)
		{
			if(!Passenger_getId(this, &auxId) && !Passenger_getNombre(this, auxNombre) && !Passenger_getApellido(this, auxApellido) && !Passenger_getPrecio(this, &auxPrecio) && !Passenger_getTipoPasajero(this, auxTipoPasajero)
					&& !Passenger_getCodigoVuelo(this, auxCodigoVuelo) && !Passenger_getEstadoVuelo(this, auxEstadoVuelo))
			{
				printf("%10d | %15s | %15s | %15.2f | %15s | %15s | %15s\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo,auxEstadoVuelo);
				retorno = 0;
			}

		}
	}

	return retorno;
}

/// @fn int Passenger_getNewId(int*, char*)
/// @brief Obtener de un archivo el último id
///
/// @pre
/// @post
/// @param nuevoId Puntero a int por nuevoID
/// @param path Ruta del archivo que contiene el último ID
/// @return -1 si alguno de los parámetros es erroneo;-2 si no pudo abrir el archivo;-3 si el id que contiene el archivo no es un numero entero;
/// 0 si salio todo bien
int Passenger_getNewId(int*nuevoId,char* path)
{
	int retorno;
	char id[100];
	retorno =-1;

	if(nuevoId != NULL && path != NULL)
	{
		retorno = -2;
		FILE* pArchivoUltimoID = fopen(path,"r");
		if(pArchivoUltimoID != NULL)
		{
			retorno = -3;
			fscanf(pArchivoUltimoID,"%s",id);
			if(!atoi(id))
			{
				*nuevoId = atoi(id);
				retorno = 0;
			}

		}
	}
	return retorno;
}

int Passenger_setNewId(int*nuevoId,char* path)
{
	int retorno;
	char id[100];
	retorno =-1;

	if(nuevoId != NULL && path != NULL)
	{
		retorno = -2;
		FILE* pArchivoUltimoID = fopen(path,"r");
		if(pArchivoUltimoID != NULL)
		{
			retorno = -3;
			fscanf(pArchivoUltimoID,"%s",id);
			if(!atoi(id))
			{
				*nuevoId = atoi(id);
				retorno = 0;
			}

		}
	}
	return retorno;
}


