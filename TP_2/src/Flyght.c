/*
 * Flight.c
 *
 *  Created on: 10 may. 2022
 *      Author: Emanuel
 */
#include "Flyght.h"

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


