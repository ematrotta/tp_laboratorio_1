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
/// @return 0 si es 0, 1 si es un n�mero positivo, -1 si es negativo
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

/// @fn int ImpresionDeResultadosTp1(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Imprime los resultados de la funcion SubMenuTp1
///
/// @pre
/// @post
/// @param kilometrosIngresados Km ingresados por el usuario
/// @param precioVueloAerolineas Precio de Aerol�neas ingresado por el usuario
/// @param precioConTarjetaDebitoAerolineas Resultado de los importes por pago con tarjeta de d�bito Aerol�neas
/// @param precioConTarjetaCreditoAerolineas Resultado de los importes por pago con tarjeta de cr�dito Aerol�neas
/// @param precioBitcoinAerolineas Resultado de los importes por pago con Bitcoins Aerol�neas
/// @param precioUnitarioAerolineas Resultado del precio por km
/// @param precioVueloLatam Precio de Latam ingresado por el usuario
/// @param precioConTarjetaDebitoLatam Resultado de los importes por pago con tarjeta de d�bito Latam
/// @param precioConTarjetaCreditoLatam Resultado de los importes por pago con tarjeta de cr�dito Latam
/// @param precioBitcoinLatam Resultado de los importes por pago con Bitcoins Latam
/// @param precioUnitarioLatam Resultado del precio por km
/// @param diferenciaPrecios Diferencia de precio entre Aerol�neas y Latam
/// @return -1 si sali� Mal, 0 si salio bien.
int ImpresionDeResultadosTp1(float kilometrosIngresados,float precioVueloAerolineas,float precioConTarjetaDebitoAerolineas,float precioConTarjetaCreditoAerolineas,float precioBitcoinAerolineas,float precioUnitarioAerolineas,float precioVueloLatam,float precioConTarjetaDebitoLatam,float precioConTarjetaCreditoLatam,float precioBitcoinLatam,float precioUnitarioLatam,float diferenciaPrecios)
{
	int retorno;
	retorno = -1;

	if(kilometrosIngresados > 0 && precioVueloAerolineas > 0 && precioConTarjetaDebitoAerolineas > 0 && precioConTarjetaCreditoAerolineas > 0 && precioBitcoinAerolineas > 0 && precioUnitarioAerolineas>=0 && precioVueloLatam > 0 && precioConTarjetaDebitoLatam > 0 && precioConTarjetaCreditoLatam > 0 && precioBitcoinLatam > 0 && precioUnitarioLatam>=0)
	{
		printf("\nKMs Ingresados: %.2f km\n\nPrecio Vuelos Aerol�neas: $%.2f\na) Precio con tarjeta de d�bito: $ %.2f\nb) Precio con tarjeta de cr�dito: $ %.2f\nc) Precio pagando con bitcoin: $ %.2f BTC\nd) Precio unitario: $ %.2f\n\nPrecio Vuelos Latam: $%.2f\na) Precio con tarjeta de d�bito: $ %.2f\nb) Precio con tarjeta de cr�dito: $ %.2f\nc) Precio pagando con bitcoin: $ %.2f BTC\nd) Precio unitario: $ %.2f\n\nLa diferencia de precio es : $ %.2f\n\n",kilometrosIngresados,precioVueloAerolineas,precioConTarjetaDebitoAerolineas,precioConTarjetaCreditoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas,precioVueloLatam,precioConTarjetaDebitoLatam,precioConTarjetaCreditoLatam,precioBitcoinLatam,precioUnitarioLatam,diferenciaPrecios);

		retorno = 0;
	}
	return retorno;
}
