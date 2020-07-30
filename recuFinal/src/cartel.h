/*
 * cartel.h
 *
 *  Created on: 30 jul. 2020
 *      Author: Ezequiel
 */

#ifndef CARTEL_H_
#define CARTEL_H_
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "utn.h"
typedef struct
{
	int idCartel;
	int tipo;
	char domicilio[50];
	char localidad[50];
	int estadoId;
	int medida;
}eCartel;

eCartel* Cartel_nuevoCartel();
int Cartel_borrarCartel(eCartel* cartel);
int Cartel_setIdCartel(eCartel* cartel,int idCartel);
int Cartel_setTipo(eCartel* cartel,int tipo);
int Cartel_setEstadoId(eCartel* cartel,int idEstado);
int Cartel_setDomicilio(eCartel* cartel,char* Ddomicilio);
int Cartel_setLocalidad(eCartel* cartel,char* Llocalidad);
int Cartel_setMedida(eCartel* cartel,int medida);
int Cartel_getIdCartel(eCartel* cartel,int* idCartel);
int Cartel_getTipo(eCartel* cartel,int* tipo);
int Cartel_getEstadoId(eCartel* cartel,int* idEstado);
int Cartel_getDomicilio(eCartel* cartel,char* Ddomicilio);
int Cartel_getLocalidad(eCartel* cartel,char* Llocalidad);
int Cartel_getMedida(eCartel* cartel,int* medida);
eCartel* Cartel_nuevoCartelParametros(char* idCartel,char* tipo,char* domicilio,char* localidad,char* idEstado, char* medida);
int Cartel_cargarDatosModoTexto(FILE* archivo,LinkedList* listaCartel);
int Cartel_funcionCriterio(void* itemUno, void* itemDos);
void Cartel_mostrarListaCartel(LinkedList* listaCartel);
int Cartel_mostrarUnCartel(eCartel* unCartel);
int Cartel_calcularCartelOfrecido(eCartel* unCartel);
int Cartel_calcularCartelOfrecidoDos(void* unCartel);
int Cartel_calcularCartelAlquiladoVendidoDos(void* unCartel);
int Cartel_calcularCartelAlquiladoVendido(eCartel* unCartel);
int Cartel_guardarDatosMapeo(FILE* archivo,LinkedList* listaCartel);
int Cartel_MedidaMayora100(void* pElement);
int Cartel_CantidaddeCartelesOfrecidos(void* pElement);
#endif /* CARTEL_H_ */
