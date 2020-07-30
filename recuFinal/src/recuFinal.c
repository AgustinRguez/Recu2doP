/*
 ============================================================================
 Name        : recuFinal.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "cartel.h"
int main(void) {
		setbuf(stdout,NULL);
			FILE* archivoTexto=NULL;
			LinkedList* listaCartel=ll_newLinkedList();
			int opcionMenu;
			int max=0;
			int i;
			int variable;
			int variableDos;
			char continuarMenu='s';
			    do
			    {
			        printf("1-Leer un archivo(modo texto)\n");
			        printf("2-Ordenar Localidad Ascendente\n");
			        printf("3-Imprimir Por pantalla\n");
			        printf("4-Funcion map con agregado de medidas (ambos)\n");
			        printf("5-Generar archivo con los 2 descuentos de map-\n");
			        printf("6-Informe medida mayor a 100\n");
			        printf("7-Informe carteles ofrecidos\n");
			        printf("8-Salir\n");
			        opcionMenu=getInt("\nIngrese una opcion: ");
			                switch(opcionMenu)
			                {
			                    case 1:
			                        Cartel_cargarDatosModoTexto(archivoTexto,listaCartel);
			                        break;
			                    case 2:
			                        ll_sort(listaCartel,Cartel_funcionCriterio,1);
			                        break;
			                    case 3:
			                    	Cartel_mostrarListaCartel(listaCartel);
			                        break;
			                    case 4:
			                        mapeo(listaCartel,(void*)Cartel_calcularCartelOfrecido);
			                    	mapeo(listaCartel,(void*)Cartel_calcularCartelAlquiladoVendido);
			                        break;
			                    case 5:
			                    	Cartel_guardarDatosMapeo(archivoTexto,listaCartel);
			                        break;
			                    case 6:
			                        variableDos=ll_count(listaCartel,(void*)Cartel_MedidaMayora100,&max);
			                        printf("\nLa cantidad de carteles cuya medida es mayor a 100 es: %d\n",variableDos);
			                        break;
			                    case 7:
			                    	variable=ll_count(listaCartel,(void*)Cartel_CantidaddeCartelesOfrecidos,&i);
			                    	printf("\nLa cantidad de carteles ofrecidos es: %d\n",variable);
			                    	break;
			                    case 8:
			                    	 continuarMenu='n';
			                    	 break;
			                    default:
			                        printf("\nOpcion ingresada no valida\n");
			                }
			                system("pause");
			                system("cls");
			    }while(continuarMenu=='s');
			    ll_deleteLinkedList(listaCartel);
	return 0;
}
