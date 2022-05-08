/*
 * Passenger.c
 *
 *  Created on: 6 may. 2022
 *      Author: Emanuel
 */

#include "ArrayPassenger.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
static int initId = 1000;
static int sPassenger_IdGenerator(void)
{
	return initId++;
}

/// @fn int sPassenger_initPassenger(sPassenger*, int)
/// @brief Inicializar todos los campos isEmpty
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


/// @fn int sPassenger_findFreeSpace(sPassenger*, int)
/// @brief Encontrar un espacio Libre
///
/// @pre
/// @post
/// @param list Array pasajeros
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

/// @fn sPassenger sPassenger_InputsDataPassenger(char[])
/// @brief Ingresar datos en un Pasajeros excepto modificar el estado
///
/// @pre
/// @post
/// @param mensajeError Mensje si no se pudieron cargar bien los datos
/// @return Un pasajero, exceptuando su estado
sPassenger sPassenger_InputsDataPassenger(char mensajeError[])
{
	sPassenger auxiliar;
	int flag;

	if(mensajeError != NULL)
	{
		do
		{
			//CARGO UNA ENTIDAD AUXILIAR DE TODOS SUS DATOS Y VALIDO QUE SEAN CORRECTOS
			flag = 1;
			if(
			Utn_GetName(auxiliar.name, NAME, "\nIngrese el nombre", "ERROR. Maxima cantidad de caracteres: 50 o No es un Nombre", 3) != 0 ||
			Utn_GetName(auxiliar.lastName, NAME, "Ingrese el Apellido", "ERROR. Maxima cantidad de caracteres: 50 o No es un Apellido", 3) != 0 ||
			Utn_GetString(auxiliar.flycode, "Ingrese el codigo de vuelo", "ERROR. Maxima cantidad de caracteres: 9", FLYCODE, 3)!= 0 ||
			Utn_GetNumeroFloat(&auxiliar.price, "Ingrese el precio de vuelo", "ERROR. Debe ser entre 0 y 10000", 10000, 0, 3)!= 0 ||
			Utn_GetNumeroInt(&auxiliar.typePassenger, "Ingrese el tipo de Pasajero:\n\t1)Primera clase."
					"\n\t2)Clase ejecutiva o business.\n\t3)Clase premium economy\n\t4)Clase turista o económica.\nOPCIÓN", "ERROR. Debe ser entre 1 y 4", 4, 1, 3)!= 0)
			{
				printf("\n%s\n",mensajeError);
				//SI ALGUNO DE LOS DATOS SON INCONRRECTOS, VUELVE A SOLICITARLOS TODOS
				flag = 0;
			}
		}while(flag == 0);
		auxiliar.id = sPassenger_IdGenerator();
	}

	return auxiliar;
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
		list[indiceLibre].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/// @fn int sPassenger_Modification(sPassenger*, int)
/// @brief Modificar una entidad de un array
///
/// @pre
/// @post
/// @param list Array
/// @param len Tamaño del array
/// @param id id a buscar
/// @return -1 si el array = NULL o el tamaño es <=0
/// -2 si no se pudo encontrar ningun Id para modificar
/// -3 si colocó mal la opcion para seleccionar el menu
/// -4 si no realizó bien la modificacion
int sPassenger_Modification(sPassenger * list,int len,int id)
{
	int retorno;
	int indiceId;
	int opcionMenu;

	retorno = -1;
	if(list != NULL && len>0)
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
						//MODIFICAR CODIGO DE VUELO
						if(Utn_GetString(list[indiceId].flycode, "Ingrese el nuevo codigo de vuelo", "El codigo de vuelo supera el buffer",FLYCODE, 3) == 0)
						{
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
		retornoBaja = sPassenger_findPassengerById(list, len, id);
		if(retornoBaja >=0)
		{
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
	printf("\nEl nombre es: %s\nEl apellido es: %s\nEl precio es: %.2f\nEl id es: %d\nEl tipo es: %d\nEl codigo de vuelo es: %s\nEl estado es: %d\n",passenger.name,passenger.lastName,passenger.price,passenger.id,passenger.typePassenger,passenger.flycode,passenger.isEmpty);
}

/// @fn int sPassenger_printAll(sPassenger*, int)
/// @brief Imprimir todas las entidades de un array que se hayan ingresado
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
			if(list[i].isEmpty != TRUE)
			{
				sPassenger_printOne(list[i]);
			}

		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int sPassenger_printAllIdByStatus(sPassenger*, int, int)
/// @brief Imprimir todas los id de entidades segun su estado
///
/// @pre
/// @post
/// @param list array
/// @param len tamaño del array
/// @param status estado
/// @return -1 si no encuentra entidades según estado, -2 si array es NULL o tamaño array <=0, 0 si salio bien
int sPassenger_printAllIdByStatus(sPassenger* list,int len,int status)
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
			if(list[i].isEmpty == status)
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

/// @fn int sPassenger_sortPassengersByTypePassenger(sPassenger*, int, int)
/// @brief Ordenar array de entidad segun TYPEPASSENGER
///
/// @pre
/// @post
/// @param list Array
/// @param len Tamaño del array
/// @param order 1 ascendente, -1 si es decreciente
/// @return -1 si array = NULL o tamaño de array<=0 o Order != 1 o !=-1
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
					if(list[i].typePassenger < list[i-1].typePassenger)
					{
						auxiliar = list[i-1];
						list[i-1] = list[i];
						list[i] = auxiliar;
						flagNoEstaOrdenado = 1;
						break;
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
					if(list[i].typePassenger > list[i-1].typePassenger)
					{
						auxiliar = list[i];
						list[i] = list[i-1];
						list[i-1] = auxiliar;
						flagNoEstaOrdenado = 1;
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

/// @fn int sPassenger_sortPassengersByStatus(sPassenger*, int, int)
/// @brief Ordenar array de entidad por ISEMPTY
///
/// @pre
/// @post
/// @param list array
/// @param len Tamaño de array
/// @param order 1 si el orden es ascendente, -1 si es decreciente
/// @return -1 si array = NULL o tamaño de array<=0 o Order != 1 o !=-1
int sPassenger_sortPassengersByStatus(sPassenger* list, int len, int order)
{
	int retorno;
	int i;
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
					if(list[i].isEmpty < list[i-1].isEmpty)
					{
						auxiliar = list[i-1];
						list[i-1] = list[i];
						list[i] = auxiliar;
						flagNoEstaOrdenado = 1;
						break;
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
					if(list[i].isEmpty > list[i-1].isEmpty)
					{
						auxiliar = list[i];
						list[i] = list[i-1];
						list[i-1] = auxiliar;
						flagNoEstaOrdenado = 1;
						break;
					}
				}

			}

		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int sPassenger_sortPassengersByCode(sPassenger*, int, int)
/// @brief Ordenar array de entidad según FLYCODE y ISEMPTY
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
		//ORDENO POR ESTADO
		sPassenger_sortPassengersByStatus(list, len, order);

		//ORDENAMIENTO ALFABETICO ASCENDENTE
		if(order == 1)
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

