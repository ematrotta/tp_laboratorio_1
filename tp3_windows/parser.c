#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return -1 si el archivo, la lista o puntero auxiliar son nulos,; -2 si alguno de los buffers de datos son nulos,0 si salio todo bien
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	char id[TAM_BUFFER_PARSER];
	char nombre[TAM_BUFFER_PARSER];
	char apellido[TAM_BUFFER_PARSER];
	char precio[TAM_BUFFER_PARSER];
	char codigoVuelo[TAM_BUFFER_PARSER];
	char tipoPasajero[TAM_BUFFER_PARSER];
	char estadoVuelo[TAM_BUFFER_PARSER];
	int cantidadLeida;

	Passenger* aux;
	retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = -2;
		if(id != NULL && nombre != NULL && apellido != NULL && precio != NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
		{
			//fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
			//id,name,lastname,price,flycode,typePassenger,statusFlight
			while(!feof(pFile))
			{
				cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				if(cantidadLeida == 7)
				{
					aux = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);

					if(aux != NULL)
					{
						ll_add(pArrayListPassenger,aux);
					}

				}

			}
			retorno = 0;
		}

	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
