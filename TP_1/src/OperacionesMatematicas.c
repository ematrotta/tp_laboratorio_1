/*
 * OperacionesMatematicas.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Emanuel
 */
#include "OperacionesMatematicas.h"

/// @fn float Promedio2NumerosInt(int, int)
/// @brief Promediar 2 numeros enteros
///
/// @pre
/// @post
/// @param num1 Numero 1
/// @param num2 Numero 2
/// @return Promedio Flotante
float Promedio2NumerosInt(int num1,int num2)
{

	float retorno;

	retorno = ((float) num1 + num2)/2;


	return retorno;
}

/// @fn int PorcentajeInt(int, int, char, float*)
/// @brief Modificar un numero entero segun porcentaje
///
/// @pre
/// @post
/// @param numero Numero a modificarse
/// @param porcentajeAplicado Porcentaje a aplicar
/// @param operacion + para aumento, - para disminucion
/// @param resultado Puntero del numero modificado
/// @return -1 Si salio mal, 0 si salio bien
int PorcentajeInt(int numero,int porcentajeAplicado,char operacion,float*resultado)
{
	int retorno;
	float resultadoPorcentaje;
	retorno = -1;

	if(numero>0 && porcentajeAplicado>0 && resultado != NULL && (operacion == '+'|| operacion == '-'))
	{
		if(operacion == '+')
		{
			resultadoPorcentaje = (float) numero + (numero*porcentajeAplicado/100);
		}
		else
		{
			resultadoPorcentaje = (float) numero - (numero*porcentajeAplicado/100);

		}
		*resultado = resultadoPorcentaje;
		retorno = 0;
	}

	return retorno;
}

/// @fn int PorcentajeFloat(float, float, char, float*)
/// @brief Modificar un numero flotante segun porcentaje
///
/// @pre
/// @post
/// @param numero Numero a modificarse
/// @param porcentajeAplicado Porcentaje a aplicar
/// @param operacion + para aumento, - para disminucion
/// @param resultado Puntero del numero modificado
/// @return -1 Si salio mal, 0 si salio bien
int PorcentajeFloat(float numero,float porcentajeAplicado,char operacion,float*resultado)
{
	int retorno;
	float resultadoPorcentaje;
	retorno = -1;

	if(numero>0 && porcentajeAplicado>0 && resultado != NULL && (operacion == '+'|| operacion == '-'))
	{
		if(operacion == '+')
		{
			resultadoPorcentaje = numero + (numero*porcentajeAplicado/100);
		}
		else
		{
			resultadoPorcentaje = numero - (numero*porcentajeAplicado/100);

		}
		*resultado = resultadoPorcentaje;
		retorno = 0;
	}
	return retorno;
}

/// @fn int DivisionInt(int, int, char[], float*)
/// @brief Dividir 2 numeros enteros, siendo el divisor mayor que 0
///
/// @pre
/// @post
/// @param dividendo Numero a dividir
/// @param divisor Numero divisor
/// @param mensajeError Mensaje de Error en caso que el divisor sea 0
/// @param resultado Puntero del resultado de la division
/// @return -1 Si salio mal, 0 si salio bien
int DivisionInt(int dividendo,int divisor,char mensajeError[],float *resultado)
{
	int retorno;
	float resultadoDivision;
	retorno = -1;

	if(divisor>0)
	{
		resultadoDivision = (float)dividendo / divisor;
		*resultado = resultadoDivision;
		retorno = 0;
	}
	else
	{
		printf("%s",mensajeError);
	}
	return retorno;
}

/// @fn int DivisionFloat(float, float, char[], float*)
/// @brief Dividir 2 numeros floatntes, siendo el divisor mayor que 0
///
/// @pre
/// @post
/// @param dividendo Numero a dividir
/// @param divisor Numero divisor
/// @param mensajeError Mensaje de Error en caso que el divisor sea 0
/// @param resultado Puntero del resultado de la division
/// @return -1 Si salio mal, 0 si salio bien
int DivisionFloat(float dividendo,float divisor,char mensajeError[],float *resultado)
{
	int retorno;
	float resultadoDivision;
	retorno = -1;

	if(divisor>0)
	{
		resultadoDivision = dividendo / divisor;
		*resultado = resultadoDivision;

		retorno = 0;
	}
	else
	{
		printf("%s",mensajeError);

	}
	return retorno;
}

/// @fn int RestaInt(int, int, int*)
/// @brief Restar 2 numeros enteros
///
/// @pre
/// @post
/// @param numero1 Numero 1
/// @param numero2 Numero 2
/// @param resultado Puntero del resultado
/// @return -1 Si salio mal, 0 si salio bien
int RestaInt(int numero1,int numero2,int*resultado)
{
	int retorno;
	int resultadoResta;

	retorno = -1;
	if(resultado != NULL)
	{
		resultadoResta = numero1 - numero2;
		*resultado = resultadoResta;
		retorno = 0;
	}

	return retorno;
}

/// @fn int RestaFloat(float, float, float*)
/// @brief Restar 2 numeros flotantes
///
/// @pre
/// @post
/// @param numero1 Numero 1
/// @param numero2 Numero 2
/// @param resultado Puntero del resultado
/// @return -1 Si salio mal, 0 si salio bien
int RestaFloat(float numero1,float numero2,float*resultado)
{
	int retorno;
	float resultadoResta;

	retorno = -1;
	if(resultado != NULL)
	{
		resultadoResta = numero1 - numero2;
		*resultado = resultadoResta;
		retorno = 0;
	}

	return retorno;
}

