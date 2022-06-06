/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Inputs.h"
#include "Outputs.h"

#define TAM_NOMBRE 50
#define TAM_APELLIDO 50
#define TAM_CODIGOVUELO 20
#define TAM_TIPOPASAJERO 20
#define TAM_ESTADOVUELO 20




typedef struct
{
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	float precio;
	char tipoPasajero[TAM_TIPOPASAJERO];
	char codigoVuelo[TAM_CODIGOVUELO];
	char estadoVuelo[TAM_ESTADOVUELO];


}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoStr,char* estadoStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_printOne(Passenger* this);



#endif /* PASSENGER_H_ */
