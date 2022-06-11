#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int -1 si alguno de los par�metros es NULL, -2 si alguno de los buffers es NULL, 0 si salio todo bien
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	int cantidadLecturas;
	retorno = -1;
	char auxId[TAM_BUFFER];
	char auxNombre[TAM_BUFFER];
	char auxApellido[TAM_BUFFER];
	char auxPrecio[TAM_BUFFER];
	char auxTipoPasajero[TAM_BUFFER];
	char auxEstadoVuelo[TAM_BUFFER];
	char auxCodigoVuelo[TAM_BUFFER];
	Passenger* pAux;

//id,name,lastname,price,flycode,typePassenger,statusFlight



	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
		retorno = -2;
		if(auxId != NULL && auxNombre != NULL && auxApellido != NULL && auxPrecio != NULL && auxTipoPasajero != NULL &&
				auxEstadoVuelo != NULL && auxCodigoVuelo != NULL)
		{

			while(!feof(pFile))
			{


				cantidadLecturas = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);

				if(cantidadLecturas == 7)
				{
					pAux = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
					if(pAux != NULL)
					{

						ll_add(pArrayListPassenger, pAux);

					}
				}

			}
			retorno = 0;


		}

	}
    return retorno;
}

/** \brief Parsea los datos de los vuelos desde el archivo dataFlyghts.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFlyghts LinkedList*
 * \return int -1 si alguno de los par�metros es NULL, -2 si alguno de los buffers es NULL, 0 si salio todo bien
 *
 */
int parser_FlyghtsFromText(FILE* pFile , LinkedList* pArrayListFlyghts)
{

	int retorno;
	retorno = -1;
	int cantidadLecturas;
	char auxEstadoVuelo[TAM_BUFFER];
	char auxCodigoVuelo[TAM_BUFFER];
	sFlyght* pAux;

//id,name,lastname,price,flycode,typePassenger,statusFlight



	if(pFile != NULL && pArrayListFlyghts != NULL)
	{


		fscanf(pFile,"%[^,],%[^\n]\n",auxCodigoVuelo,auxEstadoVuelo);
		retorno = -2;
		if(auxEstadoVuelo != NULL && auxCodigoVuelo != NULL)
		{


			while(!feof(pFile))
			{


				cantidadLecturas = fscanf(pFile,"%[^,],%[^\n]\n",auxCodigoVuelo,auxEstadoVuelo);
				if(cantidadLecturas == 2)
				{
					pAux = Flyght_newParametros(auxCodigoVuelo,auxEstadoVuelo);
					if(pAux != NULL)
					{

						ll_add(pArrayListFlyghts, pAux);

					}
				}

			}
			retorno = 0;


		}

	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si no se pudo leer ning�n pasajero, <0 si pudo leer alg�n pasajero
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int cantidadLecturas;
	int retornoRead;
	cantidadLecturas = 0;
	Passenger* auxPasajero;

	if(pFile != NULL && pArrayListPassenger)
	{
		do
		{
			//PRIMERO LE ASIGNO MEMORIA DINAMICA
			auxPasajero = Passenger_new();
			retornoRead = fread(auxPasajero,sizeof(Passenger),1,pFile);
			if(retornoRead == 1 && auxPasajero != NULL)
			{
				ll_add(pArrayListPassenger, auxPasajero);
				cantidadLecturas++;
			}

		}while(!feof(pFile));
	}

    return cantidadLecturas;
}
