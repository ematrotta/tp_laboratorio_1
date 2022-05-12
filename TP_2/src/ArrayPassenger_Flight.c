/*
 * ArrayPassenger_Flight.c
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */

#include "ArrayPassenger_Flight.h"
static int initId = 1000;
static int sPassenger_IdGenerator(void)
{
	return initId++;
}

/// @fn int int sPassenger_InputsDataPassenger(sPassenger *,sFlyght*,int, char*)
/// @brief Ingresar datos en un pasajero
///
/// @pre
/// @post
/// @param passenger puntero a estructura de un pasajero
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @param mensajeError
/// @return -1 si el tipo es erroneo, -2 si el precio es erroneo, -3 Si no se encontraron vuelos con el flycode ingresado,
///-4 si no se cargó bien el codigo de vuelo, -5 Si el apellido es erroneo, -6 si el nombre es Erroneo
int sPassenger_InputsDataPassenger(sPassenger * passenger,sFlyght listFlyghts[],int lenflyghts, char mensajeError[])
{
	sPassenger auxiliar;
	int retorno;

	if(passenger != NULL && listFlyghts != NULL && mensajeError != NULL)
	{
		//INGRESO NOMBRE
		if(Utn_GetName(auxiliar.name, NAME, "\nIngrese el nombre", "ERROR. Maxima cantidad de caracteres: 50 o No es un Nombre", 3) == 0)
		{
			//INGRESO APELLIDO
			if(Utn_GetName(auxiliar.lastName, NAME, "Ingrese el Apellido", "ERROR. Maxima cantidad de caracteres: 50 o No es un Apellido", 3) == 0)
			{
				//INGRESO CODIGO DE VUELO
				if(Utn_GetString(auxiliar.flycode, "Ingrese el codigo de vuelo", "ERROR. Maxima cantidad de caracteres: 9", FLYCODE, 3) == 0)
				{
					//BUSCO EL FLYCODE INGRESADO, DENTRO DE LOS VUELOS Y ARROJO EL INDICE
					if(sFlyght_findFlyghtById(listFlyghts, lenflyghts, auxiliar.flycode)>=0)
					{

						//INGRESO PRECIO
						if(Utn_GetNumeroFloat(&auxiliar.price, "Ingrese el precio de vuelo", "ERROR. Debe ser entre 0 y 10000", 10000, 0, 3) == 0)
						{
							//INGRESO TIPO DE PASAJERO
							if(Utn_GetNumeroInt(&auxiliar.typePassenger, "Ingrese el tipo de Pasajero:\n\t1)Primera clase."
									"\n\t2)Clase ejecutiva o business.\n\t3)Clase premium economy\n\t4)Clase turista o económica.\nOPCIÓN", "ERROR. Debe ser entre 1 y 4", 4, 1, 3) == 0)
							{

								//SI ALGUNO DE LOS DATOS SON INCONRRECTOS, VUELVE A SOLICITARLOS TODOS
								auxiliar.id = sPassenger_IdGenerator();
								(*passenger) = auxiliar;
								retorno = 0;

							}
							else
							{
								//SI LO INGRESADO COMO TIPO ES ERRONEO
								retorno = -1;
							}
						}
						else
						{
							//SI EL PRECIO ES ERRONEO
							retorno = -2;
						}
					}
					else
					{
						//SI NO SE ENCONTRÓ UN VUELO
						retorno = -3;
						puts("\nERROR. No se encontró codigo de vuelo.");

					}

				}
				else
				{
					//SI EL CODIGO DE VUELO ES ERRONEO
					retorno = -4;
				}

			}
			else
			{
				//SI EL APELLIDO ES ERRONEO
				retorno = -5;
			}
		}
		else
		{
			//SI EL NOMBRE ES ERRONEO
			retorno = -6;
		}
	}
	if(retorno<0)
	{
		printf("\n%s\n",mensajeError);
	}


	return retorno;
}


/// @fn int sPassenger_addPassengerFlyghtStatus(sPassenger *,int,sFlyght*,int)
/// @brief Agregar a cada pasajero ACTIVO el estado de vuelo en base a su codigo de vuelo
///
/// @pre
/// @post
/// @param passenger listado de pasajeros
/// @param lenPassenger Tamaño del array pasajeros
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @return -1 si no se ingresaron correctamente los parametros, 0 si salio todo bien
int sPassenger_addPassengerFlyghtStatus(sPassenger passenger[],int lenPassenger, sFlyght listFlyghts[],int lenflyghts)
{
	int retorno;
	int i;
	int j;

	retorno = -1;
	if(passenger != NULL && lenPassenger>0 && listFlyghts != NULL && lenflyghts>0)
	{
		//RECORREMOS EL ARRAY DE PASAJEROS
		for(j = 0;j<lenPassenger;j++)
		{
			//RECORREMOS TODOS LOS VUELOS
			for(i=0;i<lenflyghts;i++)
			{
				//SI EL PASAJERO NO ESTA DADO DE ALTA, NO SE LE ASIGNA EL ESTADO DE VUELO
				if(passenger[j].isEmpty != FALSE)
				{
					continue;
				}
				else
				{
					//SI ESTA DADO DE ALTA, SE RELACIONA SU CODIGO DE VUELO PREVIAMENTE INGRESADO
					//Y SE ASOCIA AL ESTADO DE VUELO
					if(strncmp(passenger[j].flycode,listFlyghts[i].flycode,FLYCODE)==0)
					{
						passenger[j].statusFlight = listFlyghts[i].status;
						retorno = 0;
						break;
					}

				}

			}


		}
	}

	return retorno;
}



/// @fn int sPassenger_Modification(sPassenger *,int,sFlyght*,int)
/// @brief Modifiar algun campo de la estructura
///
/// @pre
/// @post
/// @param passenger listado de pasajeros
/// @param lenPassenger Tamaño del array pasajeros
/// @param listFlyghts Array Vuelos
/// @param lenflyghts Tamaño del array vuelos
/// @return -1 si no se ingresaron correctamente los parametros, 0 si salio todo bien
int sPassenger_Modification(sPassenger * list,int len,int id,sFlyght listFlyght[],int lenFlyghts)
{
	int retorno;
	int indiceId;
	int opcionMenu;

	char auxiliarFlycode[FLYCODE];

	retorno = -1;
	if(listFlyght != NULL && lenFlyghts>0 && list != NULL && len>0)
	{
		indiceId = sPassenger_findPassengerById(list,len,id);
		if(indiceId<0)
		{
			retorno = -2;
		}
		else
		{
			//DESPLIEGO SUBMENU
			puts("\nQué dato desea modificar?\n\t1)Nombre\n\t2)Apellido"
					"\n\t3)Codigo de vuelo\n\t4)Tipo de pasajero\n\t5)Precio");
			//PIDO QUE INGRESE LA OPCION DEL SUBMENU
			if(Utn_GetNumeroInt(&opcionMenu, "Opcion", "Debe ser entre 1 y 5", 5, 1, 3) != 0)
			{
				retorno = -3;
			}
			else
			{
				switch(opcionMenu)
				{
					case 1:
						//MODIFICAE NOMBRE
						if(Utn_GetName(list[indiceId].name, NAME, "Ingrese el nuevo nombre", "El Max de caracteres 50 o no es un Nombre", 3) == 0)
						{
							retorno = 0;
						}
						break;
					case 2:
						//MODIFICAR APELLIDO
						if(Utn_GetName(list[indiceId].lastName, NAME, "Ingrese el nuevo Apellido", "El Max de caracteres 50 o no es un Apellido", 3) == 0)
						{
							retorno = 0;
						}
						break;
					case 3:
						//MODIFICAR CODIGO DE VUELO SOLO SI SE ENCUENTRA ENTRE LOS VUELOS DISPONIBLES
						if(Utn_GetString(auxiliarFlycode, "Ingrese el nuevo codigo de vuelo", "El codigo de vuelo supera el buffer",FLYCODE, 3) == 0 && sFlyght_findFlyghtById(listFlyght,lenFlyghts,auxiliarFlycode)>=0)
						{
							strncpy(list[indiceId].flycode,auxiliarFlycode,FLYCODE);
							retorno = 0;

						}
						break;
					case 4:
						//MODIFICAR TIPO DE PASAJERO
						if(Utn_GetNumeroInt(&list[indiceId].typePassenger, "Ingrese el nuevo tipo de pasajero", "ERROR. Debe ser entre 1 y 3", 3, 1, 3) == 0)
						{
							retorno = 0;
						}
						break;
					case 5:
						//MODIFICAR EL PRECIO
						if(Utn_GetNumeroFloat(&list[indiceId].price, "Ingrese el nuevo precio", "El precio debe ser entre", 100000, 0, 3) == 0)
						{
							retorno = 0;
						}
						break;
				}
				//VALIDO QUE EL RESULTADO DE LA MODIFICACION DEL CAMPO SEA CORRECTA
				if(retorno != 0)
				{
					//SI NO ES CORRECTA LA MODIFICACION
					retorno = -4;
				}

			}
		}
	}

	return retorno;
}

