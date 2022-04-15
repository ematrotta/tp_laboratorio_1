/*
 * OtrasFunciones.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Emanuel
 */
#include "OtrasFunciones.h"

int RetornoDeNumeroEntero(int numeroEntero)
{
	int retorno;

	retorno = 0;
	if(numeroEntero >0)
	{
		retorno = 1;
	}
	else
	{
		if(numeroEntero < 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int SubMenuTp1(float kilometrosIngresados,float precioVuelo,float*precionConTarjetaDebito,float*precionConTarjetaCredito,float*precioBitcoin,float*precioUnitario)
{
	int retorno;
	float auxiliarPrecioConTarjetaDebito;
	float auxiliarPrecioConTarjetaCredito;
	float auxiliarPrecioBitcoin;
	float auxiliarPrecioUnitario;


	retorno = -1;
	if(kilometrosIngresados>0 && precioVuelo>0 && precionConTarjetaDebito != NULL && precionConTarjetaCredito != NULL && precioBitcoin != NULL && precioUnitario != NULL)
	{
		//Determino Precio de vuelo con Tarjeta de d�bito
		PorcentajeFloat(precioVuelo, 10, '-', &auxiliarPrecioConTarjetaDebito);

		//Determino Precio de vuelo con tarjeta de cr�dito
		PorcentajeFloat(precioVuelo, 25, '+', &auxiliarPrecioConTarjetaCredito);

		//Determino Precio de vuelo con Bitcoins
		DivisionFloat(precioVuelo, 4606954.55, "ERROR. No se puede dividir por 0", &auxiliarPrecioBitcoin);

		//Determino Precio Unitario
		DivisionFloat(precioVuelo, kilometrosIngresados, "ERROR. No se puede dividir por 0", &auxiliarPrecioUnitario);

		*precionConTarjetaDebito=auxiliarPrecioConTarjetaDebito;
		*precionConTarjetaCredito=auxiliarPrecioConTarjetaCredito;
		*precioBitcoin=auxiliarPrecioBitcoin;
		*precioUnitario=auxiliarPrecioUnitario;

		retorno = 0;


	}


	return retorno;
}
