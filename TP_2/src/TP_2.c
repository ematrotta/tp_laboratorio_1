/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger_Flight.h"

#define PASAJEROS 4
#define VUELOS 3



int main(void){


	setbuf(stdout,NULL);
	//VALIDACION DE CONTINUIDAD EN EL BUCLE
	char salida;
	//ESPACIO PARA GUARDAR OPICIONES DE MENU Y SUBMENU
	int opcionMenus;
	//VALORES DE RETORNO DEL MAIN
	int retorno;
	//ID INGRESADO PARA REALIZAR ACCIONES
	int idSeleccionado;
	//RETORNO PARA VALIDAR LA CORRECTA MIDIFICACION DE UNA ENTIDAD
	int retornoModificacion;
	//CONTADOR PARA VERIFICAR QUE HAYA ESPACIO PARA CARGAR PASAJEROS
	int contadorAltas;
	//RETONTO PARA VALIDAD QUE SE INGRESO BIEN LA OPCION DEL SUBMENU DE "INFORMES"
	int retornoMenuInforme;
	//ACUMULADOR DE PREIOS DE PASAJES
	float totalPrecioPasajesActivos;
	//ACUMULADOR DE CANTIDAD DE VUELOS ACTIVOS
	float contadorVuelosActivos;
	float promedioVuelosActivos;
	int contadorPasajesQSuperanPrecioPromedio;
	//INDICE DE ITERACIONES INTERNAS
	int i;

	retorno = 0;
	contadorAltas = 0;
	totalPrecioPasajesActivos = 0;
	contadorVuelosActivos = 0;
	promedioVuelosActivos = 0;
	contadorPasajesQSuperanPrecioPromedio = 0;

	//AUXILIAR PARA CARGAR DATOS NO GENERICOS DE UN PASAJERO
	sPassenger auxiliar;
	//ARRAY DE PASAJEROS
	sPassenger listaPasajeros[PASAJEROS];
	//ARRAY DE VUELOS HARCODEADOS
	sFlyght vuelos[VUELOS]={{"ABC123456",ACTIVO},{"ZZ123456",REPROGRAMADO},{"ZZ1277889",CANCELADO}};



	//INICIALIZO TODOS LAS ENTIDADES DEL ARRAY DE PASAJEROS
	sPassenger_initPassenger(listaPasajeros, PASAJEROS);

	do
	{
		puts("\n\n\t*********TP 2********\n\tEmpresa de Aerolíneas"
				"\n\n1)Altas\n2)Modificar\n3)Baja\n4)Informar\n");

		//PIDO LA OPCION DEL MENU
		if(Utn_GetNumeroInt(&opcionMenus, "OPCION", "ERROR. Debe ser entre 1 y 4", 4, 1, 3) != 0)
		{
			retorno = -1;
			break;
		}

		switch(opcionMenus)
		{
			case 1:
				//ALTA
				//VERIFICO QUE HAYA LUGAR PARA CARGAR PASAJEROS
				if(contadorAltas<PASAJEROS)
				{
					//CARGO DE DATOS A UN AUXILIAR DE LA ENTIDAD
					//INGRESO LOS DATOS A UNA ENTIDAD DEL ARRAY SI ES QUE HAY ESPACIO LIBRE Y CAMBIO SU ESTADO
					if(sPassenger_InputsDataPassenger(&auxiliar,vuelos,VUELOS, "ERROR. No se pudo ingresar el pasajero") == 0 && sPassenger_addPassenger(listaPasajeros, PASAJEROS, auxiliar.id, auxiliar.name, auxiliar.lastName, auxiliar.price, auxiliar.typePassenger, auxiliar.flycode) == 0)
					{
						puts("\nCARGA EXITOSA");
						contadorAltas++;
					}
				}
				else
				{
					puts("\nERROR.No hay espacio para una nueva alta");
				}
				break;
			case 2:
				// MODIFICACION
				if(contadorAltas > 0)
				{
					//LISTO LOS ID OCUPADOS
					puts("\nLos ID disponibles son: ");
					if(sPassenger_printAllIdByInit(listaPasajeros, PASAJEROS, FALSE)!=0)
					{
						puts("\nNo hay IDs para modificar");
						break;
					}
					//PIDO UN ID
					puts("\nSeleccione el ID a modificar: ");
					GetIntegrer(&idSeleccionado);
					//TOMO EL RETORNO DE LA FUNCION MODIFICAR Y LISTO MENSAJES
					retornoModificacion = sPassenger_Modification(listaPasajeros, PASAJEROS,idSeleccionado,vuelos,VUELOS);
					switch(retornoModificacion)
					{
					case 0:
						puts("\nModificacion Exitosa!");
						break;
					case -1:
						puts("\nERROR. Faltan parámetros en la funcion");
						break;
					case -2:
						puts("\nERROR. El ID no se encontró");
						break;
					case -3:
						puts("\nERROR. No se ingreso la opcion correcta del menu");
						break;
					case -4:
						puts("\nERROR. No se pudo modificar");
						break;
					}
				}
				else
				{
					puts("\nDebe ingresar al menos 1 pasajero.");
				}
				break;
			case 3:
				//BAJA
				if(contadorAltas > 0)
				{
					//LISTO LOS ID ACTIVOS
					puts("\nLos ID disponibles son: ");
					// SI NO HAY IMPRIMO ERROR Y SALGO
					if(sPassenger_printAllIdByInit(listaPasajeros, PASAJEROS, FALSE)!=0)
					{
						puts("\nNo hay IDs para dar de baja");
						break;
					}
					//PIDO UN ID
					puts("\nSeleccione el ID a dar de baja: ");
					GetIntegrer(&idSeleccionado);
					//FUNCION REMOVE QUE CAMBIA EL ESTADO DE TRUE A LOW
					if(sPassenger_removePassenger(listaPasajeros,PASAJEROS,idSeleccionado)!=0)
					{
						puts("\nERROR. No se encontró el ID ");
					}
					else
					{
						puts("\nBaja exitosa!");
					}
				}
				else
				{
					puts("\nDebe ingresar al menos 1 pasajero.");
				}


				break;
			case 4:
				//INFORMAR SOLO SI SE REALIZÓ AL MENOS 1 ALTA
				if(contadorAltas > 0)
				{
					//LE COLOCO A TODOS LOS PASAJEROS SU ESTADO DE VUELO
					sPassenger_addPassengerFlyghtStatus(listaPasajeros,PASAJEROS,vuelos,VUELOS);
					//PIDO LA OPCION DE INFORME
					retornoMenuInforme = Utn_GetNumeroInt(&opcionMenus, "\n\t1)Listado de pasajeros ordenados alfabéticamente por apellido y tipo de pasajero\n\t"
							"2)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n\t"
							"3)Listado de los pasajeros por Código de vuelo y estados de vuelos ACTIVO\nOpción", "Debe ser entre 1 y 3", 3, 1, 3);
					if(retornoMenuInforme == 0)
					{
						switch(opcionMenus)
						{
						case 1:
							//ORDENO LOS APELLIDOS ALFABETICAMENTE Y POR TIPO DE TODOS LOS PASAJEROS
							sPassenger_sortPassengers(listaPasajeros, PASAJEROS, 1);
							printf("%-50s|%-50s|%-10s|%-6s|%-30s|%-20s|%-20s","NOMBRE","APELLIDO","PRECIO","ID","TIPO PASAJERO","CODIGO DE VUELO","ESTADO DE VUELO");
							//IMPRIMO SOLO LOS PASAJEROS QUE NO ESTEN LIBRES
							sPassenger_printPassengers(listaPasajeros, PASAJEROS);
							break;
						case 2:
							for(i = 0;i<PASAJEROS;i++)
							{
								//ACUMULO LOS TOTALES DE LOS PRECIOS DE LOS VUELOS Y LA CANTIDAD DE LOS PASAJEROS ACTIVOS
								if(listaPasajeros[i].isEmpty == FALSE)
								{
									totalPrecioPasajesActivos += listaPasajeros[i].price;
									contadorVuelosActivos++;
								}
							}
							//SI HAY VUELOS ACTIVOS
							if(contadorVuelosActivos>0)
							{
								//SACO EL PROMEDIO
								DividirFloat(totalPrecioPasajesActivos, contadorVuelosActivos, "\nERROR no se puede dividir por 0", &promedioVuelosActivos);
								//ACUMULO LA CANTIDAD DE PASAJES QUE SUPERAN EN PRECIO PROMEDIO
								for(i = 0;i<PASAJEROS;i++)
								{
									if(listaPasajeros[i].isEmpty == FALSE && listaPasajeros[i].price>promedioVuelosActivos)
									{
										contadorPasajesQSuperanPrecioPromedio++;
									}
								}
								//IMPRIMO RESULTADOS
								printf("\n1. El total de la suma de pasajes es: $ %.2f\n2. El precio promedio de los vuelos activos es: $ %.2f\n"
										"3. La cantidad de pasajeros que superan el precio promedio es: %d",totalPrecioPasajesActivos,promedioVuelosActivos,contadorPasajesQSuperanPrecioPromedio);

								//REINICIO TOTAL, CONTADORES Y PROMEDIO PARA UN PROXIMO INFORME
								totalPrecioPasajesActivos = 0;
								contadorVuelosActivos = 0;
								promedioVuelosActivos = 0;
								contadorPasajesQSuperanPrecioPromedio = 0;

							}
							else
							{
								// SI NO HAY VUELOS ACTIVOS
								puts("\nNo hay vuelos activos para mostrar este informe");
							}

							break;
						case 3:
							//ORDENO LOS PASAJEROS POR SU CODIGO DE VUELO Y ESTADO DE VUELO
							sPassenger_sortPassengersByCode(listaPasajeros, PASAJEROS, ACTIVO);
							//IMPRIMO SOLO LOS ACTIVOS
							if(sPassenger_printPassengerByStatus(listaPasajeros, PASAJEROS, ACTIVO)!=0)
							{
								puts("\nERROR. No se encontraron vuelos activos");
							}
							break;
						}
					}
					else
					{
						//SI EL RETORNO DE LA FUNCION PARA SOLICITAR SUBMENU ES ERRONEO
						puts("\nERROR.");
					}

				}
				else
				{
					puts("\nDebe ingresar al menos 1 pasajero.");
				}
				break;
		}

		//SOLICITO EN CADA ITEREACION SI EL USUARIO DESEA CONTINUAR
		if(GetCharacter2Options(&salida, "\n\nDesea Continuar?: S/N", "ERROR. No es la opcion correcta", 'S', 'N', 3)!= 0)
		{
			retorno = -2;
		}

	}while(salida == 'S');

	return retorno;
}
