/*
 * Input.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Emanuel
 */


int getFloatUtn(char mensaje[],char mensajeError[],float maximo, float minimo, int reintentos,float* pNumeroFloat)
{
	int retorno;
	float auxiliar;
	retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pNumeroFloat != NULL && minimo<maximo && reintentos >0)
	{

		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%f",&auxiliar);
			if(auxiliar > maximo || auxiliar< minimo)
			{
				printf("%s\n",mensajeError);
			}
			else
			{
				reintentos = 0;
				*pNumeroFloat = auxiliar;
				retorno = 0;
			}

			reintentos--;

		}while(reintentos>0);

	}
	return retorno;
}



