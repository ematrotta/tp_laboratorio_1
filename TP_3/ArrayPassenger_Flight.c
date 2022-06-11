/*
 * ArrayPassenger_Flight.c
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#include "ArrayPassenger_Flight.h"
//static int initId = 1000;
/*static int sPassenger_IdGenerator(void)
{
	return initId++;
}*/

/// @fn int int sPassenger_InputsDataPassenger(sPassenger *,sFlyght*,int, char*)
/// @brief Ingresar datos en un pasajero a su vez, verifica que el codigo de vuelo ingresado exista
///
/// @pre
/// @post
/// @param passenger puntero a estructura de un pasajero
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @param mensajeError
/// @return -1 si alguno de los parametros es erroneo o si no hay memoria dinamica para un pasajero, -2 si esta mal el nombre, -3 Si esta mal el apellido,
///-4 si el precio no se encuentra en el rango, -5 Si no se ingresó bien el codigo de vuelo, -6 si no se encontró el codigo de vuelo
/// -7 si no se ingresó el tipo de pasajero correcto, -8 si no se pudo colocar el id correctamente
int Passenger_InputsDataPassenger(LinkedList* pArrayPassenger,LinkedList* pArrayVuelos,char mensajeError[])
{
	int retorno;
	int indiceVuelo;
	int tipoPasajero;
	char nombre[TAM_NOMBRE];
	char codigoVuelo[TAM_CODIGOVUELO];
	char apellido[TAM_APELLIDO];
	float precio;

	int estadoVueloInt;
	retorno = -1;


	if(pArrayPassenger != NULL && pArrayVuelos!= NULL && mensajeError != NULL)
	{


		Passenger* pasajero;
		sFlyght* Vuelo;
		pasajero = Passenger_new();
		if(pasajero != NULL)
		{

			//INGRESO MAL EL NOMBRE
			retorno = -2;

			if(!Utn_GetName(nombre, TAM_NOMBRE, "Ingrese el nombre", "No es un nombre. Reintente", 3))
			{
				Passenger_setNombre(pasajero, nombre);
				//INGRESO MAL EL APELLIDO
				retorno = -3;

				if(!Utn_GetName(apellido, TAM_APELLIDO, "Ingrese el Apellido", "No es un Apellido. Reintente", 3))
				{
					Passenger_setApellido(pasajero, apellido);

					//INGRESO MAL EL PRECIO
					retorno = -4;
					if(!Utn_GetNumeroFloat(&precio, "Ingrese el precio", "El precio debe ser entre 1 y 100000", 100000, 1, 3))
					{
						Passenger_setPrecio(pasajero, precio);
						//INGRESO CUALQUIER CARATER EN CODIGO DE VUELO
						retorno = -5;
						if(!Utn_GetStringAlfaNumericaPlus(codigoVuelo, "Ingrese el código de vuelo", "Ingrese solo letras y números", TAM_CODIGOVUELO, 3))
						{
							//EL VUELO NO SE ENCONTRÓ
							retorno = -6;
							indiceVuelo = sFlyght_findFlyghtById(pArrayVuelos,codigoVuelo);
							if(indiceVuelo>=0)
							{
								Passenger_setCodigoVuelo(pasajero,codigoVuelo);
								Vuelo = ll_get(pArrayVuelos, indiceVuelo);
								Flyght_getEstadoVuelo(Vuelo, &estadoVueloInt);

								switch(estadoVueloInt)
								{
								case ATERRIZADO:
									Passenger_setEstadoVuelo(pasajero, "Aterrizado");
									break;
								case DEMORADO:
									Passenger_setEstadoVuelo(pasajero, "Demorado");
									break;
								case EN_VUELO:
									Passenger_setEstadoVuelo(pasajero, "En Vuelo");
									break;
								case EN_HORARIO:
									Passenger_setEstadoVuelo(pasajero, "En Horario");
									break;
								}
								//SI SE INGRESA MAL EL TIPO DE PASAJERO
								retorno = -7;
								if(!Utn_GetNumeroInt(&tipoPasajero, "Ingrese el tipo de pasajero:\n1. EconomyClass\n"
										"2. ExecutiveClass\n3. FirstClass\nOPCIÓN", "La opción debe ser entre 1 y 3", 3, 1, 3))
								{

									switch(tipoPasajero)
									{
									case ECONOMYCLASS:
										retorno = Passenger_setTipoPasajero(pasajero, "EconomyClass");
										break;
									case EXECUTIVECLASS:
										retorno = Passenger_setTipoPasajero(pasajero, "ExecutiveClass");
										break;
									case FIRSTCLASS:
										retorno = Passenger_setTipoPasajero(pasajero, "FirstClass");
										break;
									}
									if(!Passenger_setNewId(pasajero,"UltimoId.txt"))
									{
										ll_add(pArrayPassenger, pasajero);
										retorno = 0;
									}
									else
									{
										retorno = -8;
									}
								}

							}
						}
					}
				}
			}
		}

		if(retorno<0)
		{
			printf("\n%s\n",mensajeError);
			free(pasajero);
			pasajero = NULL;
		}


	}

	return retorno;
}


