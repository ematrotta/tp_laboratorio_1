/*
 * OperacionesMatematicas.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Emanuel
 */
#include "OperacionesMatematicas.h"

float Promedio2NumerosInt(int num1,int num2)
{
	float promedio;
	float retorno;

	promedio = ((float) num1 + num2)/2;
	retorno = promedio;


	return retorno;
}

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

