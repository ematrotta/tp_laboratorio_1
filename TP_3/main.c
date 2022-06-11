#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	setbuf(stdout,NULL);
    int option = 0;
    char salida;
    int flagGuardado;
    int flagModificacionlista;
    int retorno;
    retorno = -1;

    flagGuardado = 0;
    flagModificacionlista = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaVuelos = ll_newLinkedList();

    controller_loadFromTextFlyght("dataFlyghts.csv", listaVuelos);

    do
    {

        puts("\nMenu:\n");
        puts("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
        puts("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).");
        puts("3. Alta de pasajero");
        puts("4. Modificar datos de pasajero");
        puts("5. Baja de pasajero");
        puts("6. Listar pasajeros");
        puts("7. Ordenar pasajeros");
        puts("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)");
        puts("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).");
        puts("10. Salir");
        if(!Utn_GetNumeroInt(&option, "OPCIÓN", "Debe ser entre 1 y 10", 10, 1, 3))
        {
        	switch(option)
        	{
        	case 1:
        		//CARGAR PASAJEROS DESDE ARCHIVO CSV
        		if(!controller_loadFromText("data.csv", listaPasajeros))
        		{
        			//BANDERA DE MODIFICACION EN LA LISTA
        			flagModificacionlista = 1;
        			puts("\nCARGA EXITOSA\n");
        		}
        		else
        		{
        			puts("\nNO SE PUDO CARGAR\n");
        		}
        		break;
        	case 2:
        		//ARCHIVO BINARIO
        		if(!controller_loadFromBinary("data.bin", listaPasajeros))
        		{
        			flagModificacionlista = 1;
        			puts("\nCARGA EXITOSA\n");
        		}
        		else
        		{
        			puts("\nNO SE PUDO CARGAR\n");
        		}
        		break;
        	case 3:
        		//AGREGAR PASAJERO A LA LISTA
        		//SE AGREGA SOLO SI EL ID DE VUELO ES CORRECTO ADEMÁS DE LAS OTRAS VALIDACIONES
        		if(!controller_addPassenger(listaPasajeros, listaVuelos))
        		{
        			puts("\nALTA EXITOSA\n");
        			flagModificacionlista = 1;
        		}
        		break;
        	case 4:
        		//MODIFIAR PASAJEROS SI HAY UNA MODIFICACION EN LA LISTA AL MENOS
        		if(flagModificacionlista == 1)
        		{
        			//LISTAR PASAJEROS
        			controller_ListPassenger(listaPasajeros);
            		if(!controller_editPassenger(listaPasajeros, listaVuelos))
            		{
            			puts("\nMODIFIACIÓN EXITOSA\n");
            			flagModificacionlista = 1;
            		}
            		else
            		{
            			puts("\nNO SE PUDO MODIFICAR\n");
            		}
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}
        		break;
        	case 5:
        		//DAR DE BAJA PASAJERO (SOLO SI HAY UN ALTA AL MENOS)
        		if(flagModificacionlista == 1)
        		{
            		controller_ListPassenger(listaPasajeros);
            		if(!controller_removePassenger(listaPasajeros))
            		{
            			puts("\nBAJA EXITOSA\n");
            			flagModificacionlista = 1;
            		}
            		else
            		{
            			puts("\nNO SE PUDO DAR DE BAJA");
            		}
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}

        		break;
        	case 6:
        		if(flagModificacionlista == 1)
        		{
        			//LISTAR PASAJEROS. SOLO SI HAY UNA MODIFICACION EN A LISTA
        			controller_ListPassenger(listaPasajeros);
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}
        		break;
        	case 7:
        		//ORDENAR PASAJEROS
        		if(flagModificacionlista == 1)
        		{
        			if(controller_sortPassenger(listaPasajeros) == -2)
        			{
        				puts("\nERROR en la funcion de ordenar");
        			}
        			else
        			{
        				if(controller_ListPassenger(listaPasajeros))
        				{
        					puts("\nERROR EN LA FUNCION DE IMPRESION\n");
        				}
        				else
        				{
        					//VUELO A ORDENAR LOS PASAJEROS POR ID
        					controller_sortPassengerById(listaPasajeros);
        				}
        			}
        		}
        		else
        		{
        			puts("\nPRIMERO DEBE REALIZAR UN ALTA AL MENOS");
        		}

        		break;
        	case 8:
        		//SE VOLVERA A GUARDAR UNA ARCHIVO SOLO SI HUBO MODIFICACIONES
        		if(flagModificacionlista == 1)
        		{
            		if(!controller_saveAsText("data.csv",listaPasajeros))
            		{
            			flagGuardado = 1;
            			puts("\nGUARDADO EXITOSO\n");
            		}
            		else
            		{
            			puts("\nERROR al guardar el nuevo archivo\n");
            		}
        		}
        		else
        		{
        			puts("\nNo hubo modificaciones\n");
        			flagGuardado = 1;
        		}


        		break;
        	case 9:
        		//GUARDADO EN BINARIO
        		if(flagModificacionlista == 1)
        		{
            		if(!controller_saveAsBinary("data.bin", listaPasajeros))
            		{
            			//ACEPTO LA CARGA DEL ARCHIVO
            			puts("\nGUARDADO EXITOSO\n");
            			flagGuardado = 1;
            		}
            		else
            		{
            			puts("\nERROR al guardar el nuevo archivo\n");
            		}
        		}
        		else
        		{
        			//HAGO UN GUARDADO PERO NO MODIFICO EL ARCHIVO
        			puts("\nNo hubo modificaciones\n");
        			flagGuardado = 1;
        		}
        		flagGuardado = 1;

        		break;
        	case 10:
        		if(flagGuardado == 0)
        		{
        			puts("\nAntes de salir Debe seleccionar la opcion 8 o 9 para guardar el archivo\n");
        			option = 0;
        		}
        		else
        		{
            		if(!GetCharacter2Options(&salida, "Desea Salir? S/N", "ERROR. Ingrese S (si) / N (no)", 'S', 'N', 3))
            		{
            			if(salida == 's' || salida == 'S')
            			{
                			ll_deleteLinkedList(listaPasajeros);
                			ll_deleteLinkedList(listaVuelos);
            			}
            			else
            			{
            				option = 0;
            			}

            		}
        		}

        		break;
        	}

        	retorno = 0;
        }


    }while(option!= 10);
    return retorno;
}

