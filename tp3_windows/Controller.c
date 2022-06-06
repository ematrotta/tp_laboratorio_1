#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return -1 si la lista o el path son NULL; -2 si la funcion de parserFromText tiene error;0 si salio todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;

	retorno = -1;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		retorno = -2;
		FILE* pArchivo = fopen(path,"r");
		if(!parser_PassengerFromText(pArchivo,pArrayListPassenger))
		{
			retorno = 0;
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* aux;
	int id;
	char nombre[TAM_NAME];
	char apellido[TAM_APELLIDO];
	float precio;
	char codigoVuelo[TAM_CODIGOVUELO];
	char tipoPasajero[TAM_TIPOPASAJERO];
	char estadoVuelo[TAM_ESTADOVUELO];

	if(pArrayListPassenger != NULL && aux != NULL)
	{
		//INGRESO NOMBRE
		if(Utn_GetName(nombre, TAM_NAME, "\nIngrese el nombre", "ERROR. Maxima cantidad de caracteres: 50 o No es un Nombre", 3) == 0)
		{
			//INGRESO APELLIDO
			if(Utn_GetName(apellido, TAM_APELLIDO, "Ingrese el Apellido", "ERROR. Maxima cantidad de caracteres: 50 o No es un Apellido", 3) == 0)
			{
				//INGRESO CODIGO DE VUELO
				if(Utn_GetString(codigoVuelo, "Ingrese el codigo de vuelo", "ERROR. Maxima cantidad de caracteres: 9", TAM_CODIGOVUELO, 3) == 0)
				{

						//INGRESO PRECIO
						if(Utn_GetNumeroFloat(&precio, "Ingrese el precio de vuelo", "ERROR. Debe ser entre 0 y 10000", 10000, 0, 3) == 0)
						{
							//INGRESO TIPO DE PASAJERO
							if(Utn_GetName(tipoPasajero, TAM_TIPOPASAJERO, "Ingrese el Apellido", "ERROR. Maxima cantidad de caracteres: 50 o No es un Apellido", 3) == 0)
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
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int -1 si La lista o auxiliar puntero son NULL, si salio todo bien
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	int cantidadPasajeros;

	retorno = -1;
	cantidadPasajeros = ll_len(pArrayListPassenger);
	Passenger* pPasajero;

	if(pArrayListPassenger != NULL && pPasajero != NULL)
	{
		printf("%10s | %15s | %15s | %15s | %15s | %15s | %15s\n","ID","NOMBRE","APELLIDO","PRECIO","TIPO PASAJERO","CODIGO VUELO","ESTADO");
		for(i = 0;i<cantidadPasajeros;i++)
		{
			pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_printOne(pPasajero);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

