/*
 * OtrasFunciones.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Emanuel
 */
#include "OtrasFunciones.h"

/// @fn int RetornoDeNumeroEntero(int)
/// @brief Retornar 0, 1 o -1 dependiendo del entero ingresado por parametro
///
/// @pre
/// @post
/// @param numeroEntero Numero ingresado por parametro
/// @return 0 si es 0, 1 si es un número positivo, -1 si es negativo
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

/// @fn int SubMenuTp1(float, float, float*, float*, float*, float*)
/// @brief Calculos Para el menu del TP1 de Programacion
///
/// @pre
/// @post
/// @param kilometrosIngresados Kilometros que ingreso el usuario
/// @param precioVuelo Precio del vuelo ingresado por el usuario
/// @param precionConTarjetaDebito Puntero del resultado del porcentaje del pago con tarjeta de Debito
/// @param precionConTarjetaCredito Puntero del resultado del porcentaje del pago con tarjeta de Credito
/// @param precioBitcoin Puntero del resultado del porcentaje del pago con BitCoins
/// @param precioUnitario Puntero del resultado del precio por kilometro
/// @return -1 Si salio mal, 0 si salio bien
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
		//Determino Precio de vuelo con Tarjeta de débito
		PorcentajeFloat(precioVuelo, 10, '-', &auxiliarPrecioConTarjetaDebito);

		//Determino Precio de vuelo con tarjeta de crédito
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
