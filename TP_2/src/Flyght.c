/*
 * Flight.c
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */
#include "Flyght.h"

/// @fn int sFlyght_findFlyghtById(sFlyght *,int,char*)
/// @brief Encontrar vuelo, en array de vuelo en base a su codigo de vuelo
///
/// @pre
/// @post
/// @param list Listado de vuelos
/// @param len tamaño de array de vuelos
/// @param idFlyght codigo de vuelo
/// @return -2 si no se ingresaron bien los parametros, -1 si no se encontraron vuelos
/// 0 si salio todo bien
int sFlyght_findFlyghtById(sFlyght * list,int len,char idFlyght[])
{
	int retorno;
	int i;

	retorno = -2;
	if(idFlyght != NULL && list != NULL && len>0)
	{
		retorno = -1;
		for(i = 0;i<len;i++)
		{
			if(strncmp(list[i].flycode,idFlyght,FLYCODE)==0)
			{
				retorno = i;
				break;
			}

		}
	}

	return retorno;
}


