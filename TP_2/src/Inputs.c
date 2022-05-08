/*
 * Inputs.c
 *
 *  Created on: 23 abr. 2022
 *      Author: Emanuel
 */
#include "Inputs.h"

							//OPERACIONES MATEMATICAS
//OPERACIONES MATEMATICAS CON ENTEROS

/// @fn int RestaInt(int, int, int*)
/// @brief Restar 2 numeros enteros
///
/// @pre
/// @post
/// @param numero1 Numero 1
/// @param numero2 Numero 2
/// @param resultado Puntero del resultado
/// @return -1 Si salio mal, 0 si salio bien
int RestarInt(int numero1,int numero2,int*resultado)
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

/// @fn int SumaInt(int, int, int*)
/// @brief Sumar 2 n�meros enteros
///
/// @pre
/// @post
/// @param numero1
/// @param numero2
/// @param resultado Resultado de la suma
/// @return -1 si salio mal,0 si salio bien
int SumarInt(int numero1,int numero2,int*resultado)
{
	int retorno;
	int resultadoSuma;

	retorno = -1;
	if(resultado != NULL)
	{
		resultadoSuma = numero1 + numero2;
		*resultado = resultadoSuma;
		retorno = 0;
	}

	return retorno;
}

/// @fn int MultiplicarInt(int, int, int*)
/// @brief Multiplicar 2 n�meros enteros
///
/// @pre
/// @post
/// @param numero1
/// @param numero2
/// @param resultado Resultado de la multiplicacion
/// @return -1 si salio mal,0 si salio bien
int MultiplicarInt(int numero1,int numero2,int*resultado)
{
	int retorno;
	int resultadoMultiplicacion;

	retorno = -1;
	if(resultado != NULL)
	{
		resultadoMultiplicacion = numero1 * numero2;
		*resultado = resultadoMultiplicacion;
		retorno = 0;
	}

	return retorno;
}

/// @fn int DividirInt(int, int, char[], float*)
/// @brief Dividir 2 numeros enteros, siendo el divisor mayor que 0
///
/// @pre
/// @post
/// @param dividendo Numero a dividir
/// @param divisor Numero divisor
/// @param mensajeError Mensaje de Error en caso que el divisor sea 0
/// @param resultado Puntero del resultado de la division
/// @return -1 Si salio mal, 0 si salio bien
int DividirInt(int dividendo,int divisor,char mensajeError[],float *resultado)
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
		printf("%s\n",mensajeError);
		*resultado = retorno;
	}
	return retorno;
}

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
	float numeroCasteado;
	float resultadoPorcentaje;
	retorno = -1;
	numeroCasteado = (float) numero;

	if(numero>0 && porcentajeAplicado>0 && resultado != NULL && (operacion == '+'|| operacion == '-'))
	{
		if(operacion == '+')
		{
			SumarFloat(numeroCasteado,(numeroCasteado*porcentajeAplicado/100),&resultadoPorcentaje);
		}
		else
		{
			RestarFloat(numeroCasteado,(numeroCasteado*porcentajeAplicado/100),&resultadoPorcentaje);

		}
		*resultado = resultadoPorcentaje;
		retorno = 0;
	}
	else
	{
		*resultado = (float)retorno;
	}


	return retorno;
}


//OPERACIONES MATEMPATICAS CON FLOTANTES

/// @fn int SumarFloat(float, float, float*)
/// @brief Sumar 2 flotantes
///
/// @pre
/// @post
/// @param numero1
/// @param numero2
/// @param resultado Resultado de la suma de 2 flotantes
/// @return -1 si esta mal, 0 si esta bien
int SumarFloat(float numero1,float numero2,float*resultado)
{
	int retorno;
	float resultadoSuma;

	retorno = -1;
	if(resultado != NULL)
	{
		resultadoSuma = numero1 + numero2;
		*resultado = resultadoSuma;
		retorno = 0;
	}

	return retorno;
}

/// @fn int MultiplicarFloat(float, float, float*)
/// @brief Multiplicar 2 flotantes
///
/// @pre
/// @post
/// @param numero1
/// @param numero2
/// @param resultado Producto de 2 flotantes
/// @return -1 si esta mal, 0 si esta bien

/// @fn int RestarFloat(float, float, float*)
/// @brief Restar 2 numeros flotantes
///
/// @pre
/// @post
/// @param numero1 Numero 1
/// @param numero2 Numero 2
/// @param resultado Puntero del resultado
/// @return -1 Si salio mal, 0 si salio bien
int RestarFloat(float numero1,float numero2,float*resultado)
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

int MultiplicarFloat(float numero1,float numero2,float*resultado)
{
	int retorno;
	float resultadoMultipliacion;

	retorno = -1;
	if(resultado != NULL)
	{
		resultadoMultipliacion = numero1 * numero2;
		*resultado = resultadoMultipliacion;
		retorno = 0;
	}

	return retorno;
}

/// @fn int DividirFloat(float, float, char[], float*)
/// @brief Dividir 2 numeros floatntes, siendo el divisor mayor que 0
///
/// @pre
/// @post
/// @param dividendo Numero a dividir
/// @param divisor Numero divisor
/// @param mensajeError Mensaje de Error en caso que el divisor sea 0
/// @param resultado Puntero del resultado de la division
/// @return -1 Si salio mal, 0 si salio bien
int DividirFloat(float dividendo,float divisor,char mensajeError[],float *resultado)
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
		printf("%s\n",mensajeError);
		*resultado = (float)retorno;

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
			SumarFloat(numero,(numero*porcentajeAplicado/100),&resultadoPorcentaje);
		}
		else
		{
			RestarFloat(numero,(numero*porcentajeAplicado/100),&resultadoPorcentaje);

		}
		*resultado = resultadoPorcentaje;
		retorno = 0;
	}
	else
	{
		*resultado = (float)retorno;
	}
	return retorno;
}

				//FUNCIONES PARA TOMAR DATOS
//UN DATO CUALQUIERA COMO STRING

/// @fn int MyGets(char[], int)
/// @brief Ingresar un dato como cadena de caracteres
///
/// @pre
/// @post
/// @param arrayIngresado Array donde se guardar� la cadena
/// @param tam Tama�o de la cadena
/// @return -1 si salio mal, 0 si salio bien
int MyGets(char arrayIngresado[],int tam)
{
    int retorno;
    char auxiliar[4090]; //DEBO INICIALIZAR EL BUFFER PARA QUE OCUPE LUGAR EN LA MEMORIA
    //NO PUEDO UTILIZAR EL TAMA�O QUE INDICO POR PAR�METRO DEL ARRAY

    retorno = -1;
    if(arrayIngresado != NULL && tam>0)
    {
        fflush(stdin); // ES BUENA PRACTICA
        if(fgets(auxiliar,sizeof(auxiliar),stdin) != NULL) //INDICO SI FGETS PUDO RECOLECTAR ALGO DEL ARCHIVO STDIN
        {
            if(auxiliar[strlen(auxiliar)-1] == '\n') // INDICO SI EN LA CANTIDAD DE CARACTERES HAY UN \N Y LO CAMBIO POR
            {
                auxiliar[strlen(auxiliar)-1] = '\0';
            }
        strncpy(arrayIngresado,auxiliar,tam);
        retorno = 0;
        }
    }

    return retorno;
}


/// @fn int EsNumerica(char[])
/// @brief Indica si un array de caracteres es numerico o no. Se tienen en cuenta '-' y '.' o ','
///
/// @pre
/// @post
/// @param arrayEvaluado Array que ser� evaluado
/// @return -1 si salio mal, 0 si salio bien
int EsNumerica(char arrayEvaluado[])
{
    int retorno;
    int i;
    int contadorPunto;

    i = 0;
    contadorPunto = 0;
    retorno = 0;

    if(arrayEvaluado != NULL)
    {
        while(arrayEvaluado[i] != '\0')
        {
            if(arrayEvaluado[i]>'9' || arrayEvaluado[i]<'0')
            {
                if(i == 0 && arrayEvaluado[i] == '-')
                {
                    i++;
                    continue;
                }
                else
                {
                    if(i>0 && contadorPunto<1 && (arrayEvaluado[i] == '.' || arrayEvaluado[i] == ','))
                    {
                        contadorPunto++;
                        i++;
                        continue;
                    }
                    else
                    {
                        retorno = -1;
                        break;
                    }
                }
            }
            else
            {
                i++;
            }
        }
    }
    return retorno;
}

/// @fn int EsNombre(char[])
/// @brief Evaluar si una cadena ingresada es un Nombre o Apellido
///
/// @pre
/// @post
/// @param arrayEvaluado cadena
/// @return -1 si no es un nombre,0 si todo salio todo bien
int EsNombre(char arrayEvaluado[])
{
    int retorno;
    int i;

    i = 0;
    retorno = 0;

    if(arrayEvaluado != NULL)
    {
        while(arrayEvaluado[i] != '\0')
        {
            if(arrayEvaluado[i]>'z' || arrayEvaluado[i]<'a')
            {
                if(i == 0 && (arrayEvaluado[i]>='A' && arrayEvaluado[i]<='Z'))
                {
                    i++;
                    continue;
                }
				else
				{
					retorno = -1;
					break;
				}
            }
            else
            {
                i++;
            }
        }
    }
    return retorno;
}

/// @fn int EsCuit(char [])
/// @brief Indicar si un numero es cuit. No evalua guiones ni puntos
///
/// @pre
/// @post
/// @param arrayEvaluado Array que ser� evaluado
/// @return -1 si es un numero que excede los dijitos de un CUIT, -2 si no es un cuit, 0 si salio bien
int EsCuit(char arrayEvaluado[])
{
    int retorno;
    int i;

    i = 0;
    retorno = 0;

    if(arrayEvaluado != NULL)
    {
        while(arrayEvaluado[i] != '\0')
        {
            if(arrayEvaluado[i]>'9' || arrayEvaluado[i]<'0')
            {
                i++;
                if(i>10)
                {
                	retorno = -1;
                	break;
                }
            }
            else
            {
            	retorno = -2;
            	break;
            }

        }
    }
    return retorno;
}

/// @fn int GetIntegrer(int*)
/// @brief Convierte una cadena Numerica tomada como cadena de caracteres en tipo Int
///
/// @pre
/// @post
/// @param pNumero Puntero a numero a ingresar
/// @return -1 si salio mal, 0 si salio bien
int GetIntegrer(int * pNumero)
{
	int retorno;
	char arrayNumerosIngresados[12]; //Ingreso 12 porque tengo en cuenta que un int abarca 4294967295 (en sistema de 32bits) y tengo en cuenta '-' y el '.'

	retorno = -1;

	if(pNumero != NULL)
	{
		if(MyGets(arrayNumerosIngresados, sizeof(arrayNumerosIngresados))== 0 && EsNumerica(arrayNumerosIngresados)== 0)
		{
			*pNumero = atoi(arrayNumerosIngresados);
			retorno = 0;
		}
	}
	return retorno;
}


/// @fn int GetFloat(float*)
/// @brief Convierte una cadena Numerica tomada como cadena de caracteres en tipo Float
///
/// @pre
/// @post
/// @param pNumero pNumero Puntero a numero a ingresar
/// @return -1 si salio mal, 0 si salio bien
int GetFloat(float * pNumero)
{
	int retorno;
	char arrayNumerosIngresados[30]; //Cantidad de caracteres aprox que puede tener un float, incluyendo - y , o . (Puede mucho m�s)

	retorno = -1;

	if(pNumero != NULL)
	{
		if(MyGets(arrayNumerosIngresados, sizeof(arrayNumerosIngresados))== 0 && EsNumerica(arrayNumerosIngresados)== 0)
		{
			*pNumero = atof(arrayNumerosIngresados);
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int GetCuit(int*)
/// @brief Convierte una cadena Numerica tomada como cadena de caracteres en tipo Int y verifica que sea un CUIT
///
/// @pre
/// @post
/// @param pNumero Puntero a numero a ingresar
/// @return -1 si salio mal, 0 si salio bien
int GetCuit(int * pNumero)
{
	int retorno;
	char arrayNumerosIngresados[12]; //Ingreso 12 porque tengo en cuenta que un int abarca 4294967295 (en sistema de 32bits) y tengo en cuenta '-' y el '.'

	retorno = -1;

	if(pNumero != NULL)
	{
		if(MyGets(arrayNumerosIngresados, sizeof(arrayNumerosIngresados))== 0 && EsCuit(arrayNumerosIngresados)== 0)
		{
			*pNumero = atoi(arrayNumerosIngresados);
			retorno = 0;
		}
	}
	return retorno;
}




/// @fn int GetCharacter2Options(char * pChar,char mensaje[],char mensajeError[],char op1,char op2, int reintentos)
/// @brief Obtiene un caracter segun 2 opciones
///
/// @pre
/// @post
/// @param pChar Puntero al caracter
/// @param mensaje Mensaje de solicitud de caracter
/// @param mensajeError Mensaje de error si la cadena es mayor a 1 o distinto a opcion 1 y opcion 2
/// @param op1 Opcion 1
/// @param op2 Opcion 2
/// @param reintentos
/// @return -1 si salio mal, 0 si salio bien
int GetCharacter2Options(char * pChar,char mensaje[],char mensajeError[],char op1,char op2, int reintentos)
{
    int retorno;
    char auxiliarChar;

    retorno = -1;

    if(pChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s: ",mensaje);

			if(MyGets(&auxiliarChar, 1) != 0 || (auxiliarChar != op1 && auxiliarChar != op2))
			{
				reintentos--;
				printf("%s - Le quedan: %d reintentos\n",mensajeError,reintentos);
			}
			else
			{
				*pChar = auxiliarChar;
				reintentos = 0;
				retorno = 0;
			}
        }
    }
    return retorno;
}

/// @fn int Utn_GetName(char[])
/// @brief Obtener un Nombre
///
/// @pre
/// @post
/// @param name Puntero a nombre
/// @param Tama�o del nombre
/// @param mensaje
/// @param mensajeError
/// @param reintentos
/// @return -1 si no se ingresaron bien los parametros
/// -2 tam es mayor que el buffer auxiliar, -3 si no es un nombre, 0 si salio todo bien
int Utn_GetName(char name[],int tam, char mensaje[],char mensajeError[],int reintentos)
{
    int retorno;
    char auxiliarCadena[500];

    retorno = -1;

    if(name != NULL && mensaje != NULL && mensajeError != NULL && tam>0 && reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s: ",mensaje);
            //TOMO CON MYGETS LO ESCRITO POR TECLADO Y VALIDO QUE EL TAMA�O
            //INGRESADO POR PARAMETRO, NO EXCEDA EL TAMA�O DEL ARRAY AUXILIAR
            if(MyGets(auxiliarCadena, sizeof(auxiliarCadena))==0 && sizeof(auxiliarCadena)>tam)
            {
            	//VALIDO QUE EL AUXILIAR CADENA SEA UN NOMBRE
            	if(EsNombre(auxiliarCadena) == 0)
            	{
            		//SI LO QUE OBTUVE COMO NOMBRE ES MENOR AL TAMA�O INGRESADO POR PARAMETRO
                	if(strlen(auxiliarCadena)<tam)
                	{
                    	strncpy(name,auxiliarCadena,tam);
                    	retorno = 0;
                    	reintentos = 0;
                	}
                	else
                	{
                		retorno = -2;
                		reintentos--;
                	}
            	}
            	else
            	{
            		retorno = -3;
            		reintentos--;
            	}
                if(retorno == -2 || retorno ==-3)
                {
                	printf("%s - Le quedan %d reintentos\n",mensajeError,reintentos);
                }

            }
            else
            {
                puts("MEMORY ERROR");
                reintentos--;
            }
        }
    }
    return retorno;
}

/// @fn int Utn_GetNumeroInt(int*, char[], char[], int, int, int)
/// @brief Tomar un n�mero entero y validar el rango. Incluye mensaje de error y reintentos
///
/// @pre
/// @post
/// @param pNumero Puntero a n�mero ingresado
/// @param mensaje Mensaje de solicitud del n�mero
/// @param mensajeError Mensaje de error por no estar en el rango
/// @param max Maximo del rango
/// @param min Minimo del rango
/// @param reintentos Cantidad de reintentos
/// @return -1 si esta mal, 0 si est� bien
int Utn_GetNumeroInt(int * pNumero,char mensaje[],char mensajeError[], int max, int min, int reintentos)
{
    int retorno;
    int auxiliarNumero;

    retorno = -1;

    if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && max>=min && reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s: ",mensaje);

			if(GetIntegrer(&auxiliarNumero)!=0 || auxiliarNumero>max || auxiliarNumero< min)
			{
				reintentos--;
				printf("%s - Le quedan: %d reintentos\n",mensajeError,reintentos);
			}
			else
			{
				*pNumero = auxiliarNumero;
				reintentos = 0;
				retorno = 0;
			}

        }
    }
    return retorno;
}

/// @fn int Utn_GetNumeroFloat(float*, char[], char[], float, float, int)
/// @brief Tomar un n�mero flotante y validar el rango. Incluye mensaje de error y reintentos
///
/// @pre
/// @post
/// @param pNumero Puntero a n�mero ingresado
/// @param mensaje Mensaje de solicitud del n�mero
/// @param mensajeError Mensaje de error por no estar en el rango
/// @param max Maximo del rango
/// @param min Minimo del rango
/// @param reintentos Cantidad de reintentos
/// @return -1 si esta mal, 0 si est� bien
int Utn_GetNumeroFloat(float * pNumero,char mensaje[],char mensajeError[], float max, float min, int reintentos)
{
    int retorno;
    float auxiliarNumero;

    retorno = -1;

    if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && max>=min && reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s: ",mensaje);

			if(GetFloat(&auxiliarNumero) !=  0 || auxiliarNumero>max || auxiliarNumero< min)
			{
				reintentos--;
				printf("%s - Le quedan: %d reintentos\n",mensajeError,reintentos);
			}
			else
			{
				*pNumero = auxiliarNumero;
				reintentos = 0;
				retorno = 0;
			}

        }
    }
    return retorno;
}

/// @fn int Utn_GetChar(char*, char[], char[], char, char, int)
/// @brief Obtiene un caracter con un rango de caracteres
///
/// @pre
/// @post
/// @param pChar Puntero al caracter
/// @param mensaje Mensaje de solicitud de caracter
/// @param mensajeError Mensaje de error en Rango
/// @param max Caracter M�ximo
/// @param min Caracter M�nimo
/// @param reintentos
/// @return -1 si salio mal, 0 si salio bien
int Utn_GetChar(char * pChar,char mensaje[],char mensajeError[], char max, char min, int reintentos)
{
    int retorno;
    char auxiliarChar;

    retorno = -1;

    if(pChar != NULL && mensaje != NULL && mensajeError != NULL && max>=min && reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s: ",mensaje);

			if(MyGets(&auxiliarChar, 1) != 0 || auxiliarChar>max || auxiliarChar< min)
			{
				reintentos--;
				printf("%s - Le quedan: %d reintentos\n",mensajeError,reintentos);
			}
			else
			{
				*pChar = auxiliarChar;
				reintentos = 0;
				retorno = 0;
			}
        }
    }
    return retorno;
}


/// @fn int Utn_GetString(char[], char[], char[], int, int)
/// @brief Tomar una cadena. Si excede el l�mite de tama�o de la cadena respecto de la auxiliar
///
/// @pre
/// @post
/// @param cadenaAIngresar Cadena donde se guardar� la ingresada
/// @param mensaje Mensaje de solicitud de la cadena
/// @param mensajeError
/// @param tam Tama�o de la cadena a ingresar
/// @param reintentos
/// @return -1 si el tama�o ingresado por parametro supera el buffer,-2 si lo ingresado por teclado supera el tama�o ingresado por parametro, 0 si est� bien
int Utn_GetString(char cadenaAIngresar[],char mensaje[],char mensajeError[], int tam, int reintentos)
{
    int retorno;
    char auxiliarCadena[500];

    retorno = -1;

    if(cadenaAIngresar != NULL && mensaje != NULL && mensajeError != NULL && tam>0 && reintentos>0)
    {
        while(reintentos>0)
        {
            printf("%s: ",mensaje);
            if(MyGets(auxiliarCadena, sizeof(auxiliarCadena))==0 && sizeof(auxiliarCadena)>tam)
            {
            	if(strlen(auxiliarCadena)<tam)
            	{
                	strncpy(cadenaAIngresar,auxiliarCadena,tam);
                	retorno = 0;
                	reintentos = 0;
            	}
            	else
            	{
            		printf("%s\n",mensajeError);
            		retorno = -2;
            		reintentos--;
            	}

            }
            else
            {
                puts("MEMORY ERROR");
                reintentos--;
            }
        }
    }
    return retorno;
}


				//FUNCIONES PARA ARRAY

//COPIAR ARRAY DE ENTEROS

/// @fn int CopiarArrayInt(int[], int[], int)
/// @brief Copiar Array de Enteros
///
/// @pre
/// @post
/// @param arrayOriginal Array a copiar
/// @param arrayCopiado Array donde se realiza la copia
/// @param tam Tama�o del array original y el que debe tener el copiado
/// @return -1 si salio mal, 0 si salio bien
int CopiarArrayInt(int arrayOriginal[],int arrayCopiado[],int tam)
{
    int retorno;

    retorno = -1;
    if(arrayOriginal != NULL && tam>0)
    {
        for(int i = 0;i<tam;i++)
        {
            arrayCopiado[i] = arrayOriginal[i];

        }
        retorno = 0;
    }
    return retorno;
}

/// @fn int CopiarArrayFloat(float[], float[], int)
/// @brief Copiar Array de flotantes
///
/// @pre
/// @post
/// @param arrayOriginal
/// @param arrayCopiado
/// @param tam Tama�o del array original
/// @return -1 si salio mal, 0 si salio bien
int CopiarArrayFloat(float arrayOriginal[],float arrayCopiado[],int tam)
{
    int retorno;

    retorno = -1;
    if(arrayOriginal != NULL && tam>0)
    {
        for(int i = 0;i<tam;i++)
        {
            arrayCopiado[i] = arrayOriginal[i];

        }
        retorno = 0;
    }
    return retorno;
}

//ORDENAMIENTO ARRAY ENTEROS: Burbujeo Ineficiente
/// @fn int OrdenarArrayIntIneficiente(int[], int)
/// @brief Ordenar un array de numeros enteros: M�todo de Burbujeo ineficiente
///
/// @pre
/// @post
/// @param arrayDesordeando Array a ordenar
/// @param tam Tama�o del array
/// @return -1 si est� mal, 0 si est� bien
int OrdenarArrayIntIneficiente(int arrayDesordeando[],int tam)
{
    int retorno;
    int i;
    int j;
    int aux;

    retorno = -1;

    if(arrayDesordeando != NULL && tam>0)
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(arrayDesordeando[i]>arrayDesordeando[j])
                {
                    aux = arrayDesordeando[i];
                    arrayDesordeando[i]=arrayDesordeando[j];
                    arrayDesordeando[j]=aux;

                }
            }

        }
        retorno = 0;
    }

    return retorno;
}

//ORDENAMIENTO ARRAY ENTEROS: Ordenamiento por Insercion Burbujeo m�s Eficiente
/// @fn int OrdenarArrayIntEficiente(int[], int)
/// @brief Ordenar un array de numeros enteros: M�todo de burbujeo eficiente
///
/// @pre
/// @post
/// @param arrayDesordeando Array a ordenar
/// @param tam Tama�o del array
/// @return -1 si esta mal, 0 si est� bien
int OrdenarArrayIntEficiente(int arrayDesordeando[],int tam)
{
    int retorno;
    int i;
    int aux;
    int flagNoEstaOrdenado;

    retorno = -1;
    flagNoEstaOrdenado = 1;

    if(arrayDesordeando != NULL && tam>0)
    {
        while(flagNoEstaOrdenado == 1)
        {
            flagNoEstaOrdenado = 0;
            for(i = 1;i<tam;i++)
            {
                if(arrayDesordeando[i]<arrayDesordeando[i-1])
                {
                    aux = arrayDesordeando[i-1];
                    arrayDesordeando[i-1]= arrayDesordeando[i];
                    arrayDesordeando[i]=aux;
                    flagNoEstaOrdenado = 1;

                }
            }
        }

        retorno = 0;

    }
    return retorno;
}


//ORDENAMIENTO ARRAY ENTEROS: Ordenamiento por Insercion
/// @fn int OrdenamientoPorInsercion(int[], int)
/// @brief Ordenar un array de numeros enteros: M�todo de Inserci�n
///
/// @pre
/// @post
/// @param arrayDesordeando Array a ordenar
/// @param tam Tama�o del array
/// @return -1 esta mal, 0 si est� bien
int OrdenamientoPorInsercion(int arrayDesordeando[],int tam)
{
    int retorno;
    int i;
    int j;
    int aux;

    for(i = 1;i<tam;i++)
    {
        aux = arrayDesordeando[i];
        j=i-1;
        while(j>=0 && aux<arrayDesordeando[j])
        {
            arrayDesordeando[j+1] = arrayDesordeando[j];
            j--;
        }
        arrayDesordeando[j+1]=aux;
    }
    retorno = -1;

    return retorno;
}

