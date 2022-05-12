/*
 * Passenger.c
 *
 *  Created on: 6 may. 2022
 *      Author: Emanuel
 */

#include "ArrayPassenger.h"

/// @fn int sPassenger_initPassenger(sPassenger*, int)
/// @brief Inicializar todos los campos isEmpty de los Pasajeros
///
/// @pre
/// @post
/// @param list Array de Pasajero
/// @param len Tamaño del array
/// @return -1 si está mal, 0 si esta bien
int sPassenger_initPassenger(sPassenger * list, int len)
{
	int retorno;
	int i;
	retorno = -1;

	if(list != NULL && len>0)
	{
		for(i = 0;i<len;i++)
		{
			//SELECCIONO EL CAMPO IS EMPTY E INICIALIZO
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int sPassenger_findPassengerById(sPassenger*, int, int)
/// @brief Buscar Indice de entidad según id
///
/// @pre
/// @post
/// @param list array
/// @param len tamaño del array
/// @param id id a buscar
/// @return -2 si array = NULL o tamaño de array<=0, -1 si no se encontró el id, Indice si salio todo bien
int sPassenger_findPassengerById(sPassenger * list,int len,int id)
{
	int retorno;
	int i;

	retorno = -2;
	if(list != NULL && len>0)
	{
		retorno = -1;
		for(i = 0;i<len;i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}

		}
	}

	return retorno;
}

/// @fn int sPassenger_addPassenger(sPassenger*, int, int, char[], char[], float, int, char[])
/// @brief Cargar datos de Pasajero libre en un array de pasajos
///
/// @pre
/// @post
/// @param list array de pasajeros
/// @param len tamaño del array
/// @param id id del pasajero que se va a cargar
/// @param name nombre del pasajero que se va a cargar
/// @param lastName apellido del pasajero que se va a cargar
/// @param price precio del pasajero que se va a cargar
/// @param typePassenger tipo de pasajero
/// @param flycode Codigo de vuelo del pasajero que se va a cargar
/// @return -1 si el array es nulo o tamaño del array es menor o igual que 0 o si no se encontraron espacios libres, y 0 si esta OK
int sPassenger_addPassenger(sPassenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int retorno;
	int indiceLibre;


	retorno = -1;
	//BUSCA DENTRO DE UN ARRAY DE ENTIDADES, UN ESPACIO LIBRE
	indiceLibre = sPassenger_findFreeSpace(list, len);
	if(list != NULL && len>0 && indiceLibre>=0)
	{
		//CUANDO LO ENCUENTRA, CARGA A UNA ENTIDAD DENTRO DEL ARRAY TODOS SUS CAMPOS
		list[indiceLibre].id = id;
		strncpy(list[indiceLibre].name,name,NAME);
		strncpy(list[indiceLibre].lastName,lastName,NAME);
		list[indiceLibre].price = price;
		list[indiceLibre].typePassenger = typePassenger;
		strncpy(list[indiceLibre].flycode,flycode,FLYCODE);
		//EL ESTADO DE VUELO, SE LO COLOCO LUEGO AL MOMENTO DE REALIZAR EL INFORME
		list[indiceLibre].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}


/// @fn int sPassenger_findFreeSpace(sPassenger*, int)
/// @brief Encontrar un espacio Libre
///
/// @pre
/// @post
/// @param list Array
/// @param len tamaño del array
/// @return -1 si no encontro espacios libres, >=0 correspondiente al indice libre
int sPassenger_findFreeSpace(sPassenger * list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len>0)
	{
		for(i = 0;i<len;i++)
		{
			//BUSCO EN UN ARRAY ALGUNA ENTIDAD QUE SE ENCUENTRE LIBRE Y ARROJO SU INDICE
			if(list[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



/// @fn int sPassenger_removePassenger(sPassenger*, int, int)
/// @brief Dar de baja una entidad dentro de un array
///
/// @pre
/// @post
/// @param list array
/// @param len tamaño del array
/// @param id id a dar de baja
/// @return -1 si array = NULL o len<=0 o no se encontro el id
int sPassenger_removePassenger(sPassenger* list, int len, int id)
{
	int retornoBaja;
	int retorno;

	retorno = -1;
	if(list != NULL && len>0)
	{
		//OBTENGO EL ID DONDE SE ENCUENTRA EL PASAJERO PASADO POR ID
		retornoBaja = sPassenger_findPassengerById(list, len, id);
		if(retornoBaja >=0)
		{
			//CAMBIO EL ESTADO A LOW
			list[retornoBaja].isEmpty = LOW;
			retorno = 0;
		}
	}

	return retorno;
}


/// @fn void sPassenger_printOne(sPassenger)
/// @brief Imprimir Una entidad
///
/// @pre
/// @post
/// @param passenger
void sPassenger_printOne(sPassenger passenger)
{
	//AUXILIAR PARA MOSTRAR CADENA EN TIPO DE PASAJERO
	char auxiliarTypePassenger[TAM_TYPEPASSENGER];
	//AUXILIAR PARA MOSTRAR CADENA EN TESTADO DE VUELO
	char auxiliarStatus[TAM_STATUSFLYGHT];


	switch(passenger.typePassenger)
	{
	case 1:
		strncpy(auxiliarTypePassenger,"Primera Clase",sizeof(auxiliarTypePassenger));
		break;
	case 2:
		strncpy(auxiliarTypePassenger,"Clase Ejecutiva o Business",sizeof(auxiliarTypePassenger));
		break;
	case 3:
		strncpy(auxiliarTypePassenger,"Clase Premium economy",sizeof(auxiliarTypePassenger));
		break;
	case 4:
		strncpy(auxiliarTypePassenger,"Clase turista o economica",sizeof(auxiliarTypePassenger));
		break;
	}
	switch(passenger.statusFlight)
	{
		case ACTIVO:
			strncpy(auxiliarStatus,"ACTIVO",sizeof(auxiliarStatus));
			break;
		case REPROGRAMADO:
			strncpy(auxiliarStatus,"REPROGRAMADO",sizeof(auxiliarStatus));
			break;
		case CANCELADO:
			strncpy(auxiliarStatus,"CANCELADO",sizeof(auxiliarStatus));
			break;

	}

	//IMPRESIÓN DE 1 PASAJERO
	printf("\n%-50s|%-50s|%-10.2f|%-6d|%-30s|%-20s|%-20s",passenger.name,passenger.lastName,passenger.price,passenger.id,auxiliarTypePassenger,passenger.flycode,auxiliarStatus);
}

/// @fn int sPassenger_printPassengers(sPassenger*, int)
/// @brief Imprimir todas las entidades de un array que se hayan ingresado y que esten activas
///
/// @pre
/// @post
/// @param list Array
/// @param len Tamaño del array
/// @return -1 si array = NULL o tamaño es <= 0, 0 si salio bien
int sPassenger_printPassengers(sPassenger* list,int len)
{

	int retorno;
	int i;

	retorno = -1;

	if(list != NULL && len>0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				sPassenger_printOne(list[i]);
			}

		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int sPassenger_printAllIdByInit(sPassenger*, int, int)
/// @brief Imprimir todas los id de entidades segun su estado
///
/// @pre
/// @post
/// @param list array
/// @param len tamaño del array
/// @param status estado
/// @return -1 si no encuentra entidades según estado, -2 si array es NULL o tamaño array <=0, 0 si salio bien
int sPassenger_printAllIdByInit(sPassenger* list,int len,int init)
{
	int retorno;
	int i;
	int flag;

	retorno = 0;
	flag = 0;

	if(list != NULL && len>0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].isEmpty == init)
			{
				printf("\nID: %d\n",list[i].id);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			retorno = -1;
		}
	}
	else
	{
		retorno = -2;
	}

	return retorno;
}

/// @fn int sPassenger_printPassengerByStatus(sPassenger*, int, int)
/// @brief Imprimir todas los id de entidades segun su estado
///
/// @pre
/// @post
/// @param list array
/// @param len tamaño del array
/// @param status estado
/// @return -1 si no encuentra entidades ACTIVAS, -2 si array es NULL o tamaño array <=0, 0 si salio bien
int sPassenger_printPassengerByStatus(sPassenger* list,int len,int status)
{
	int retorno;
	int i;
	int flag;
	char auxiliarStatus[TAM_STATUSFLYGHT];


	retorno = 0;
	flag = 0;

	if(list != NULL && len>0)
	{//RECORRIO EL ARRAY DE PASAJERO
		for(i = 0;i<len;i++)
		{
			//VERIFICO QUE ESTE ACTIVO
			if(list[i].isEmpty == FALSE)
			{
				//SI EL ESTADO DE VUELO ES IGUAL AL QUE CONTIENE EL PASAJERO
				if(list[i].statusFlight == status)
				{
					switch(list[i].statusFlight)
					{
						case ACTIVO:
							strncpy(auxiliarStatus,"ACTIVO",sizeof(auxiliarStatus));
							break;
						case REPROGRAMADO:
							strncpy(auxiliarStatus,"REPROGRAMADO",sizeof(auxiliarStatus));
							break;
						case CANCELADO:
							strncpy(auxiliarStatus,"CANCELADO",sizeof(auxiliarStatus));
							break;

					}

					//IMPRIMO NOMBRE DEL CLIENTE, CODIGO DE VUELO Y ESTADO
					printf("\n%-50s|%-9s|%-13s\n",list[i].name,list[i].flycode,auxiliarStatus);
					flag = 1;
				}

			}
		}
		if(flag == 0)
		{
			retorno = -1;
		}
	}
	else
	{
		retorno = -2;
	}

	return retorno;
}

/// @fn int sPassenger_sortPassengersByTypePassenger(sPassenger*, int, int)
/// @brief Ordenar array de entidad segun TIPO PASAJERO
///
/// @pre
/// @post
/// @param list Array
/// @param len Tamaño del array
/// @param order 1 ascendente, -1 si es decreciente
/// @return -1 si array = NULL o tamaño de array<=0 o Order != 1 o !=-1, 0 si salio bien
int sPassenger_sortPassengersByTypePassenger(sPassenger* list, int len, int order) //ORDENA DE FORMA ASCENDENTE O DESCENDENTE SEGUN CAMPO LASTNAME
{
	int retorno;
	int i;
	int flagNoEstaOrdenado;

	sPassenger auxiliar;
	flagNoEstaOrdenado = 1;

	retorno = -1;

	if(list != NULL && len>0 && (order == 1 || order == -1))
	{
		//ORDENAMIENTO ASCENDENTE
		if(order == 1)
		{
			while(flagNoEstaOrdenado == 1)
			{

				//RECORRO LAS ENTIDADES Y COMPARO POSICION POSTERIOR CON
				//POSICION ANTERIOR
				flagNoEstaOrdenado = 0;
				for(i=1;i<len;i++)
				{
					//SI SUECEDE QUE ES MAYOR EL ANTERIOR
					if(list[i].typePassenger < list[i-1].typePassenger)
					{
						//CAMBIO LOS VALORES EN LAS  POSICIONES
						auxiliar = list[i-1];
						list[i-1] = list[i];
						list[i] = auxiliar;
						flagNoEstaOrdenado = 1;
						//ROMPO
						break;
					}
				}


			}

		}
		//ORDENAMIENTO DESCENDENTE
		else
		{

			while(flagNoEstaOrdenado == 1)
			{
				//RECORRO LAS ENTIDADES Y COMPARO POSICION POSICION POSTERIOR CON
				//POSICION ANTERIOR
				flagNoEstaOrdenado = 0;
				for(i=1;i<len;i++)
				{
					//SI SUCEDE QUE ES MAYOR EL POSTERIOR
					if(list[i].typePassenger > list[i-1].typePassenger)
					{
						auxiliar = list[i];
						list[i] = list[i-1];
						list[i-1] = auxiliar;
						flagNoEstaOrdenado = 1;
						//ROMPO
						break;
					}
				}

			}

		}
		retorno = 0;
	}


	return retorno;
}

/// @fn int sPassenger_sortPassengers(sPassenger*, int, int)
/// @brief Ordenar array de entidad según LASTNAME y TYPEPASSENGER
///
/// @pre
/// @post
/// @param list Array
/// @param len Tamaño del array
/// @param order 1 si el orden es ascendente, -1 si es decreciente
/// @return -1 si array = NULL o tamaño de array<=0 o Order != 1 o !=-1
int sPassenger_sortPassengers(sPassenger* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	int flagNoEstaOrdenado;

	sPassenger auxiliar;
	flagNoEstaOrdenado = 1;

	retorno = -1;

	if(list != NULL && len>0 && (order == 1 || order == -1))
	{
		//ORDENO POR TIPO DE PASAJERO
		sPassenger_sortPassengersByTypePassenger(list, len, order);
		//ORDENAMIENTO ALFABETICO ASCENDENTE
		if(order == 1)
		{
			while(flagNoEstaOrdenado == 1)
			{

				//RECORRO LAS ENTIDADES Y COMPARO POSICION POSICION POSTERIOR CON
				//POSICION ANTERIOR
				flagNoEstaOrdenado = 0;
				for(i=1;i<len;i++)
				{
					//INICIO EN EL INDICE 0 DE LA CADENA DENTRO DEL CAMPO LAST NAME
					for(j=0;j<NAME;j++)
					{
						//SI LA POSICION EN LA CADENA DEL CAMPO LAST NAME DE LA ENTIDAD SUPERIOR
						//ES INFERIOR CAMBIO LOS LUGARES DE LAS ENTIDADES
						if(list[i].lastName[j] < list[i-1].lastName[j])
						{
							auxiliar = list[i-1];
							list[i-1] = list[i];
							list[i] = auxiliar;
							flagNoEstaOrdenado = 1;
							break;
						}
						else
						{
							//SI LA POSICION EN LA CADENA DE LA ENTIDAD SUPERIOR
							//ES SUPERIOR, SALGO DEL FOR QUE INDICA EL INDEX DE LA CADENA
							//EN EL CAMPO LAS NAME
							//INDICA QUE YA ESTA ORDENADO
							if(list[i].lastName[j] > list[i-1].lastName[j])
							{
								break;
							}
							//SI ES IGUAL, PASA AL SIGUIENTE INDICE
							else
							{
								continue;
							}
						}


					}

				}

			}

		}
		else
		{
			while(flagNoEstaOrdenado == 1)
			{
				//RECORRO LAS ENTIDADES Y COMPARO POSICION POSICION POSTERIOR CON
				//POSICION ANTERIOR
				flagNoEstaOrdenado = 0;
				for(i=1;i<len;i++)
				{
					//INICIO EN EL INDICE 0 DE LA CADENA DENTRO DEL CAMPO LAST NAME
					for(j=0;j<NAME;j++)
					{
						//SI LA POSICION EN LA CADENA DEL CAMPO LAST NAME DE LA ENTIDAD SUPERIOR
						//ES SUPERIOR CAMBIO LOS LUGARES DE LAS ENTIDADES
						if(list[i].lastName[j] > list[i-1].lastName[j])
						{
							auxiliar = list[i];
							list[i] = list[i-1];
							list[i-1] = auxiliar;
							flagNoEstaOrdenado = 1;
							break;
						}
						else
						{	//SI LA POSICION EN LA CADENA DE LA ENTIDAD SUPERIOR
							//ES INFERIOR, SALGO DEL FOR QUE INDICA EL INDEX DE LA CADENA
							//EN EL CAMPO LAS NAME
							//INDICA QUE YA ESTA ORDENADO
							if(list[i].lastName[j] < list[i-1].lastName[j])
							{
								break;
							}
							else
							{
								//SI ES IGUAL, PASA AL SIGUIENTE INDICE
								continue;
							}
						}

					}

				}

			}
		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int sPassenger_sortPassengersByCode(sPassenger*, int, int)
/// @brief Ordenar array de entidad según FLYCODE
///
/// @pre
/// @post
/// @param list Array
/// @param len Tamaño del array
/// @param order 1 si el orden es ascendente, -1 si es decreciente
/// @return -1 si array = NULL o tamaño de array<=0 o Order != 1 o !=-1
int sPassenger_sortPassengersByCode(sPassenger* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	int flagNoEstaOrdenado;

	sPassenger auxiliar;
	flagNoEstaOrdenado = 1;

	retorno = -1;

	if(list != NULL && len>0 && (order == 1 || order == -1))
	{
		//ORDENAMIENTO ALFABETICO ASCENDENTE
		if(order == 1)
		{
			while(flagNoEstaOrdenado == 1)
			{

				//RECORRO LAS ENTIDADES Y COMPARO POSICION POSICION POSTERIOR CON
				//POSICION ANTERIOR
				flagNoEstaOrdenado = 0;
				for(i=1;i<len;i++)
				{
					//INICIO EN EL INDICE 0 DE LA CADENA DENTRO DEL CAMPO FLYCODE
					for(j=0;j<NAME;j++)
					{
						//SI LA POSICION EN LA CADENA DEL CAMPO FLYCODE DE LA ENTIDAD SUPERIOR
						//ES INFERIOR CAMBIO LOS LUGARES DE LAS ENTIDADES
						if(list[i].flycode[j] < list[i-1].flycode[j])
						{
							auxiliar = list[i-1];
							list[i-1] = list[i];
							list[i] = auxiliar;
							flagNoEstaOrdenado = 1;
							break;
						}
						else
						{
							//SI LA POSICION EN LA CADENA DE LA ENTIDAD SUPERIOR
							//ES SUPERIOR, SALGO DEL FOR QUE INDICA EL INDEX DE LA CADENA
							//EN EL CAMPO FLYCODE
							//INDICA QUE YA ESTA ORDENADO
							if(list[i].flycode[j] > list[i-1].flycode[j])
							{
								break;
							}
							//SI ES IGUAL, PASA AL SIGUIENTE INDICE
							else
							{
								continue;
							}
						}


					}
				}

			}

		}
		else
		{
			//ORDENO POR TIPO DE PASAJERO
			while(flagNoEstaOrdenado == 1)
			{
				//RECORRO LAS ENTIDADES Y COMPARO POSICION POSICION POSTERIOR CON
				//POSICION ANTERIOR
				flagNoEstaOrdenado = 0;
				for(i=1;i<len;i++)
				{
					//INICIO EN EL INDICE 0 DE LA CADENA DENTRO DEL CAMPO FLYCODE
					for(j=0;j<NAME;j++)
					{
						//SI LA POSICION EN LA CADENA DEL CAMPO FLYCODE DE LA ENTIDAD SUPERIOR
						//ES SUPERIOR CAMBIO LOS LUGARES DE LAS ENTIDADES
						if(list[i].flycode[j] > list[i-1].flycode[j])
						{
							auxiliar = list[i];
							list[i] = list[i-1];
							list[i-1] = auxiliar;
							flagNoEstaOrdenado = 1;
							break;
						}
						else
						{	//SI LA POSICION EN LA CADENA DE LA ENTIDAD SUPERIOR
							//ES INFERIOR, SALGO DEL FOR QUE INDICA EL INDEX DE LA CADENA
							//EN EL CAMPO FLYCODE
							//INDICA QUE YA ESTA ORDENADO
							if(list[i].flycode[j] < list[i-1].flycode[j])
							{
								break;
							}
							else
							{
								//SI ES IGUAL, PASA AL SIGUIENTE INDICE
								continue;
							}
						}

					}

				}

			}
		}
		retorno = 0;
	}

	return retorno;
}

