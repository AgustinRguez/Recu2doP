/*
 * cartel.c
 *
 *  Created on: 30 jul. 2020
 *      Author: Ezequiel
 */

#include "cartel.h"
eCartel* Cartel_nuevoCartel()
{
    eCartel* unCartel=(eCartel*)malloc(sizeof(eCartel));
    return unCartel;
}
int Cartel_borrarCartel(eCartel* cartel)
{
    int seLibero=0;
    if(cartel!=NULL)
    {
        free(cartel);
        seLibero=1;
    }
    return seLibero;
}
int Cartel_setIdCartel(eCartel* cartel,int idCartel)
{
    int retorno=0;
    if((cartel!=NULL) && (idCartel > 0))
    {
        cartel->idCartel=idCartel;
        retorno=1;
    }
    return retorno;
}
int Cartel_setTipo(eCartel* cartel,int tipo)
{
    int retorno=0;
    if((cartel!=NULL) && (tipo > 0))
    {
        cartel->tipo=tipo;
        retorno=1;
    }
    return retorno;
}
int Cartel_setEstadoId(eCartel* cartel,int idEstado)
{
    int retorno=0;
    if((cartel!=NULL) && (idEstado > 0))
    {
        cartel->estadoId=idEstado;
        retorno=1;
    }
    return retorno;
}
int Cartel_setDomicilio(eCartel* cartel,char* Ddomicilio)
{
    int retorno=0;
    if((cartel!=NULL) && (strlen(Ddomicilio) > 0))
    {
        strcpy(cartel->domicilio,Ddomicilio);
        retorno=1;
    }
    return retorno;
}
int Cartel_setLocalidad(eCartel* cartel,char* Llocalidad)
{
    int retorno=0;
    if((cartel!=NULL) && (strlen(Llocalidad) > 0))
    {
        strcpy(cartel->localidad,Llocalidad);
        retorno=1;
    }
    return retorno;
}
int Cartel_setMedida(eCartel* cartel,int medida)
{
    int retorno=0;
    if((cartel!=NULL) && (medida > 0))
    {
        cartel->medida=medida;
        retorno=1;
    }
    return retorno;
}

int Cartel_getIdCartel(eCartel* cartel,int* idCartel)
{
    int retorno=0;
    if(cartel!=NULL && idCartel!=NULL)
    {
        *idCartel=cartel->idCartel;
        retorno=1;
    }
    return retorno;
}
int Cartel_getTipo(eCartel* cartel,int* tipo)
{
    int retorno=0;
    if(cartel!=NULL && tipo!=NULL)
    {
        *tipo=cartel->tipo;
        retorno=1;
    }
    return retorno;
}
int Cartel_getEstadoId(eCartel* cartel,int* idEstado)
{
    int retorno=0;
    if(cartel!=NULL && idEstado!=NULL)
    {
        *idEstado=cartel->estadoId;
        retorno=1;
    }
    return retorno;
}
int Cartel_getDomicilio(eCartel* cartel,char* Ddomicilio)
{
    int retorno=0;
    if(cartel!=NULL && Ddomicilio!=NULL)
    {
        strcpy(Ddomicilio,cartel->domicilio);
        retorno=1;
    }
    return retorno;
}
int Cartel_getLocalidad(eCartel* cartel,char* Llocalidad)
{
    int retorno=0;
    if(cartel!=NULL && Llocalidad!=NULL)
    {
        strcpy(Llocalidad,cartel->localidad);
        retorno=1;
    }
    return retorno;
}
int Cartel_getMedida(eCartel* cartel,int* medida)
{
    int retorno=0;
    if(cartel!=NULL && medida!=NULL)
    {
        *medida=cartel->medida;
        retorno=1;
    }
    return retorno;
}
eCartel* Cartel_nuevoCartelParametros(char* idCartel,char* tipo,char* domicilio,char* localidad,char* idEstado, char* medida)
{
    eCartel* unCartel=NULL;
    if((idCartel!=NULL) && (tipo!=NULL) && (domicilio!=NULL) && (localidad!=NULL) && (idEstado!=NULL) && (medida!=NULL))
    {
        unCartel=Cartel_nuevoCartel();
        if(unCartel!=NULL)
        {
            if(!Cartel_setIdCartel(unCartel,atoi(idCartel))
            	|| !Cartel_setTipo(unCartel,atoi(tipo))
            	|| !Cartel_setDomicilio(unCartel,domicilio)
				|| !Cartel_setLocalidad(unCartel,localidad)
				|| !Cartel_setEstadoId(unCartel,atoi(idEstado))
				|| !Cartel_setMedida(unCartel,atoi(medida)))
            {
                Cartel_borrarCartel(unCartel);
                unCartel=NULL;
            }
        }
    }
    return unCartel;
}
int Cartel_cargarDatosModoTexto(FILE* archivo,LinkedList* listaCartel)
{
    char nombreArchivo[256];
    char auxIdCartel[256];
    char auxTipo[256];
    char auxDomicilio[256];
    char auxLocalidad[256];
    char auxIdEstado[256];
    char auxMedida[256];
    eCartel* auxDatos;
    int sePudo=-1;
    if(!utn_getLetrasYNumeros(nombreArchivo,256,"\nIngrese el nombre del archivo a cargar: "))
    {
        archivo=fopen(nombreArchivo,"r");
        if(archivo!=NULL)
        {
            ll_clear(listaCartel);
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdCartel,auxTipo,auxDomicilio,auxLocalidad,auxIdEstado,auxMedida);
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdCartel,auxTipo,auxDomicilio,auxLocalidad,auxIdEstado,auxMedida);
                auxDatos=Cartel_nuevoCartelParametros(auxIdCartel,auxTipo,auxDomicilio,auxLocalidad,auxIdEstado,auxMedida);
                ll_add(listaCartel,auxDatos);
                if(feof(archivo))
                {
                    break;
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int Cartel_funcionCriterio(void* itemUno, void* itemDos)
{
	 char bufferCartelA[100];
	 char bufferCartelB[100];
	 int result;
	 Cartel_getLocalidad(itemUno,bufferCartelA);
	 Cartel_getLocalidad(itemDos,bufferCartelB);
	    if(strcmp(bufferCartelA,bufferCartelB)<0)
	    {
	        result=-1;
	    }
	    	else if(strcmp(bufferCartelA,bufferCartelB)>0)
	    	{
	    		result=1;
	    	}
	    		else
	    		{
	    			result=0;
	    		}
	    return result;
}
void Cartel_mostrarListaCartel(LinkedList* listaCartel)
{
    eCartel* auxCartel;
    int i;
    int len=ll_len(listaCartel);
    if(listaCartel!=NULL)
    {
        if(listaCartel!=NULL && ll_isEmpty(listaCartel)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nIdCartel--Tipo--Domicilio-Localidad--Estado--Medida\n");
            for(i=0;i<len;i++)
            {
                auxCartel=(eCartel*)ll_get(listaCartel,i);
                Cartel_mostrarUnCartel(auxCartel);
            }
        }
    }
}
int Cartel_mostrarUnCartel(eCartel* unCartel)
{
    int idCartel;
    int tipo;
    char domicilio[256];
    char localidad[256];
    int idEstado;
    int medida;
    //char descripcion[50];

    Cartel_getIdCartel(unCartel,&idCartel);
    Cartel_getTipo(unCartel,&tipo);
    Cartel_getDomicilio(unCartel,domicilio);
    Cartel_getLocalidad(unCartel,localidad);
    Cartel_getEstadoId(unCartel,&idEstado);
    Cartel_getMedida(unCartel,&medida);
    int seMostro=0;
    if(unCartel!=NULL)
    {
        printf("\n%d",idCartel);
       // printf("%2d",tipo);
        switch(tipo)
               {
               	case 1:
               		if(tipo==1)
               		{
               			printf("        Venta |   ");
               		}
               			break;
               	case 2:
               		if(tipo==2)
               		{
               			printf("      Alquiler |   ");
               		}
              			break;
               }
        printf("%s |  ",domicilio);
        printf("%s |  ",localidad);
        //printf("%2d",idEstado);
        switch(idEstado)
        {
			case 1:
				if(idEstado==1)
				{
					printf("  Ofrecido | ");
				}
				break;
			case 2:
				if(idEstado==2)
				{
					printf("  Alquilado/Vendido | ");
				}
				break;
        }
        printf("%d\n",medida);
        seMostro=1;
    }
    return seMostro;
}
int Cartel_calcularCartelOfrecido(eCartel* unCartel)
{
	int retorno=-1;
    int medidaAux;
    int idEstado;
    if(unCartel!=NULL)
    {
        medidaAux=unCartel->medida; //precio-(precio*0.2);
        idEstado= unCartel->estadoId;
        if(medidaAux>=100 && idEstado==1)
        {
            unCartel->medida=medidaAux+10;
            retorno=0;
        }
    }
    return retorno;
}

/*int Cartel_calcularCartelOfrecidoDos(void* unCartel)
{
	int mapeo=0;
    int medida;
    int idEstado;
 	int medidaaux;
    eCartel* cartel=(eCartel*)unCartel;
    Cartel_getMedida(cartel,&medida);
    Cartel_getEstadoId(cartel,&idEstado);
    medidaaux=medida+10;
    if(medidaaux>=100 && idEstado==1)
    {
        mapeo=1;
    }
    return mapeo;
}
int Cartel_calcularCartelAlquiladoVendidoDos(void* unCartel)
{
	int mapeo=0;
    int medida;
    int idEstado;
 	int medidaaux;
    eCartel* cartel=(eCartel*)unCartel;
    Cartel_getMedida(cartel,&medida);
    Cartel_getEstadoId(cartel,&idEstado);
    medidaaux=medida+20;
    if(medidaaux<100 && idEstado==2)
    {
        mapeo=1;
    }
    return mapeo;
}*/
int Cartel_calcularCartelAlquiladoVendido(eCartel* unCartel)
{
	int retorno=-1;
	int medidaAux;
	int idEstado;
    if(unCartel!=NULL)
    {
        medidaAux=unCartel->medida; //precio-(precio*0.2);
        idEstado=unCartel->estadoId;
        	if(medidaAux<100 && idEstado==2)
        	{
        		unCartel->medida=medidaAux+20;
        		retorno=0;
        	}
    }
    return retorno;
}
int Cartel_guardarDatosMapeo(FILE* archivo,LinkedList* listaCartel)
{
    char nombreArchivo[256];
    char auxIdCartelsStr[256];
    char auxTipoStr[256];
    char auxDomicilioStr[256];
    char auxLocalidadStr[256];
    char auxEstadoIdStr[256];
    char auxMedidaStr[256];
    int auxIdCartels;
    int auxTipo;
    int auxEstadoId;
    int auxMedida;
    int sePudo=-1;
    LinkedList* nuevaLista;
    eCartel* auxDatos;
    int i;
    int len;
    if(listaCartel!=NULL && ll_isEmpty(listaCartel)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        if(getStrLetras("\nIngrese el nombre del nuevo archivo a crear: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
        {
            archivo=fopen(nombreArchivo,"w");
            if(archivo!=NULL)
            {
            	nuevaLista=mapeo(listaCartel,(void*)Cartel_calcularCartelOfrecido);
            	nuevaLista=mapeo(listaCartel,(void*)Cartel_calcularCartelAlquiladoVendido);
            	/*nuevaLista=mapeo(listaCartel,(void*)Cartel_calcularCartelOfrecidoDos);
            	nuevaLista=mapeo(listaCartel,(void*)Cartel_calcularCartelAlquiladoVendidoDos);*/
            	if(nuevaLista!=NULL)
            	{
                    len=ll_len(nuevaLista);
                    fprintf(archivo,"\nIdCartel--Tipo--Domicilio--Localidad--EstadoId--Medida\n");
                    for(i=0;i<len;i++)
                    {
                        auxDatos=(eCartel*)ll_get(nuevaLista,i);
                        Cartel_getIdCartel(auxDatos,&auxIdCartels);
                        itoa(auxIdCartels,auxIdCartelsStr,10);
                        Cartel_getTipo(auxDatos,&auxTipo);
                        itoa(auxTipo,auxTipoStr,10);
                        Cartel_getDomicilio(auxDatos,auxDomicilioStr);
                        Cartel_getLocalidad(auxDatos,auxLocalidadStr);
                        Cartel_getEstadoId(auxDatos,&auxEstadoId);
                        itoa(auxEstadoId,auxEstadoIdStr,10);
                        Cartel_getMedida(auxDatos,&auxMedida);
                        itoa(auxMedida,auxMedidaStr,10);

                        fprintf(archivo,"%s,%s,%s,%s,%s,%s\n",auxIdCartelsStr,auxTipoStr,auxDomicilioStr,auxLocalidadStr,auxEstadoIdStr,auxMedidaStr);
                    }
            	}
                fclose(archivo);
                printf("\nSe han guardado los datos\n");
                sePudo=1;
            }
        }
    }
    return sePudo;
}

int Cartel_MedidaMayora100(void* pElement)
{
    int retorno;
    int aux;
    if(pElement!=NULL){
        Cartel_getMedida(pElement,&aux);
        if(aux>100){
            retorno=1;
            Cartel_mostrarUnCartel((eCartel*)pElement);
        }else
            retorno=0;
    }
    return retorno;
}
int Cartel_CantidaddeCartelesOfrecidos(void* pElement)
{
	int retorno;
	int auxOfrecidos;
	if(pElement!=NULL)
	{
	    Cartel_getEstadoId(pElement,&auxOfrecidos);
	    if(auxOfrecidos==1)
	    {
	    	retorno=1;
	        Cartel_mostrarUnCartel((eCartel*)pElement);
	    }
	    else
	    {
	       retorno=0;
	    }
	}
	    return retorno;
}
