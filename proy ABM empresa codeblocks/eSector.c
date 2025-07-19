

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>


#define TAM_LISTA_EMPLEADOS 20
#define TAM_LISTA_SECTORES 10
#define TAM_LISTA_COMIDAS 10
#define TAM_LISTA_ALMUERZOS 50


#define  MIN_ID_EMPLEADO 1
#define  MAX_ID_EMPLEADO  10000

#define REINTENTOS 3

#define TAM_NOMBRE 20
#define NOMBRE_SECTOR 20

#define  MIN_LISTA_SECTORES 500
#define  MAX_LISTA_SECTORES 504

#define  TAM_NOMBRE_EMPLEADO 60
#define  TAM_APELLLIDO_EMPLEADO 60

#define   NO_FULL 0
#define   FULL 1
#define  EMPTY 0
#define  NO_EMPTY 0

#define  LA_POSICION_NUNCA_FUE_CARGADA 0

//NOS AVISA QUE LA POSICION ALGUNA VEZ SE CARGO
//ES UNA BANDERA QUE ES IMPORTANTE PARA DAR DE ALTA
//EMPLEADOS DADOS DE BAJA Y QUE SE RESPETEN SUS POSICIONES
//DENTRO DE LA LISTA
#define  LA_POSICION_ESTUVO_CARGADA 1

#include "data_Warehouse.h"
#include "eEmpleado.h"
#include "eSector.h"
#include "almuerzo.h"

int SECTOR_pInicializaSectores_DeTam_(eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    retorno=0;

        if(listaSectores != NULL && tamListaSectores > 0)
        {

            for(int i=0; i < tamListaSectores; i++)
            {

                SECTOR_pInicializaUnSector(listaSectores + i);
                retorno = 1;
            }
        }
        else
        {
            printf("\n OCURRIO UN ERROR AL INICIALIZAR SECTOR \n");
        }

    return retorno;
}


int SECTOR_pInicializaUnSector(eSector* unSector)
{
    int retorno;
    retorno=0;

    if( unSector != NULL )
    {
        unSector->is_Sector_Empty= EMPTY;
        retorno = 1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INICIALIZAR SECTOR \n");
    }

    return retorno;

}

int SECTOR_pCargaSectoresPorDefecto_DeTam_OPCION_UNO(eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    retorno=0;

    if(listaSectores != NULL && tamListaSectores > 0)
    {

        eSector auxSectores[5]={ {500,"COBRANZAS",FULL}
                                 ,{501,"RRHH",FULL}
                                 ,{502,"SISTEMAS",FULL}
                                 ,{503,"LEGALES",FULL}
                                 ,{504,"VENTAS",FULL}};

	    for(int i=0;i<5;i++)
		{
			*(listaSectores + i)= *(auxSectores+i);
            retorno = 1;
		}
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL CARGAR LAS COMIDAS \n");

    }

    return retorno;
}


int funcion_MostrarSectores(eSector* listaSectores,int tamListaSectores)
{
	int i;
	int retorno;
	int flag;
	flag=0;

	if(listaSectores != NULL && tamListaSectores > 0)
	{

        printf("\n                               LISTA DE SECTORES                                    \n\n");

        puts("-----------------------------------------------------------------------------------------");
        printf( "               ID SECTOR               |                   SECTOR                      ");
        puts("\n-----------------------------------------------------------------------------------------");

        for (i = 0; i < tamListaSectores ; i++)
        {
            //SI ES FULL 1 Y NO ESTA VACIO ENTRA   !(0) ES DOBLE NEGATIVO INGRESA
            if( SECTOR_pEstaSector_DadoDeAlta_(listaSectores+i))
            {
                SECTOR_MuestraUnSector_( listaSectores + i);
                puts("-----------------------------------------------------------------------------------------|");
                flag=1;
                retorno=1;
            }

             if(!flag)
             {
                printf("\n OCURRIO UN ERROR AL MOSTRAR LOS SECTORES \n");
             }

          }
    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR INESPERADO \n");
        retorno=0;
    }

    return retorno;
}


void funcion_MostrarUnSector(eSector unSector)
{
	printf("%d %s \n",unSector.ID_Sector,unSector.descripcion);
}

int SECTOR_MuestraUnSector_(eSector* unSector)
{
     int retorno;
     retorno=0;

    if(unSector != NULL)
    {
        printf("\n     %17d     %40s    \n", unSector->ID_Sector, unSector->descripcion);
        retorno=1;
    }

    return retorno;
}


int SECTOR_pBuscaNombre_DelSector_enListaSectores_DeTam_(eSector* listaSectores
                                                          ,int tamListaSectores
                                                          ,int* auxIDSector,char* auxNombreSectorEmpleado)
{
	int retorno;
	retorno = 0;



	for(int i =0; i < tamListaSectores ;i++)
	{
		if( SECTOR_pEstaSector_DadoDeAlta_(listaSectores+i) && (listaSectores + i)->ID_Sector == *(auxIDSector))
		{

                                                //CHAR NO HACE FALTA PASARLE LA DIR DE MEMORIA  YA ASI LO PASAS POR REFERENCIA
            SECTOR_pRetornaNombreSectorDelEmpleado(auxNombreSectorEmpleado, (listaSectores + i)->descripcion);
			retorno=1;
			break;
		}
	}

	return retorno;
}


int SECTOR_pRetornaNombreSectorDelEmpleado(char* auxNombreSectorEmpleado,char* nombreSector)
{
    int retorno;
    retorno=0;

    if(auxNombreSectorEmpleado!= NULL && nombreSector != NULL)
    {
                        //EL VALOR QUE ESTA DENTRO DE ESA DIRECCION DE MEMORIA
                        //SE LO PASAS AL VALOR DENTRO DE LA DIRECCION DE MEMORIA auxIDSector
        strcpy(auxNombreSectorEmpleado, nombreSector) ;
        retorno=1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR, VARIABLES NULL \n");
    }

    return retorno;
}

char SECTOR_retornaDescripcion_DeUnSector_(eSector* unSector)
{
	int i;

	if( unSector != NULL )
	{

        return(unSector->descripcion) ;

	}
}


/*
//BUSCA INDICE DEL SECTOR EN LA LISTA DE SECTORES
int utn_buscarSectorEnListaDe_DeTam_(eSector* listaDeSectores,int tamListaDeSectores
                                     ,int auxIdComida,int* pAuxIndiceSector)
{
	int retorno;
	retorno = 0;

	if( listaDeSectores != NULL && tamListaDeSectores > 0)
	{
		for(int i=0; i < tamListaDeSectores ;i++)
		{
			if( (*(listaDeSectores + i)).is_Sector_Full == FULL  && (*(listaDeSectores + i)).ID_Sector == auxIdComida)
			{

			    *pAuxIndiceSector=i;
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}
*/
/*
int utn_ValidarSector(int id,eSector listaSectores[],int tamListaSectores)
{
    int valido;
    valido=0;

    for(int i = 0; i < tamListaSectores; i++)
    {
        if(listaSectores[i].ID_Sector= id)
        {
            valido = 1;
            break;
        }
    }

    return valido;

}
*/


//busca empleado dado de ALTA por ID Y retorna 1 si lo encontro
int SECTOR_pRetorna_UNO_SiElSector_EstaDadoDeAlta_EnLista_CERO_SINO(eSector* unSector,eSector* listaSectores
                                                                        ,int tamListaSectores)
{
    int retorno;
    retorno=0;

    if( listaSectores!= NULL && tamListaSectores > 0)
    {
        for(int i =0 ; i < tamListaSectores ; i++)
        {
            if(SECTOR_pEstaElSector_DadoAlta_Y_IdSector_EsIgualA_AuxIdSector_(listaSectores + i,&(unSector)->ID_Sector))
            {
                retorno = 1;
                break;
            }
        }

        if(!retorno)
        {
            printf("\n NO SE ENCONTRO EL SECTOR DADO DE ALTA. \n");
        }
       // else
        //{
          //  printf("\n EMPLEADO ENCONTRADO CON EXITO \n");
        //}
    }

    return retorno;
}



int SECTOR_pEstaElSector_DadoAlta_Y_IdSector_EsIgualA_AuxIdSector_(eSector* unSector,int* pAuxIdSector)
{
    int auxIdSector;
    auxIdSector = *pAuxIdSector;

    if(unSector != NULL && pAuxIdSector != NULL)
    {

        return(SECTOR_pEstaSector_DadoDeAlta_(unSector)
                                && GENERICA_pEsElNumero_IgualQueElNumero_(&(unSector)->ID_Sector,&auxIdSector));

    }

}

int SECTOR_pEstaSector_DadoDeAlta_(eSector* unSector)
{

    int retorno;
    retorno=0;

    if(unSector != NULL)
    {
        if( (unSector)->is_Sector_Empty)
        {
            retorno=1;
        }

    }

    return retorno;
}


int SECTOR_pHaySectoresDadosDe_Alta(eSector* listaSectores,int tamListaSectores)
{
   int retorno;
   retorno=0;

    if(listaSectores != NULL & tamListaSectores > 0)
    {

        for(int i = 0; i < tamListaSectores; i++)
        {
            if(SECTOR_pEstaSector_DadoDeAlta_(listaSectores + i))
            {

                retorno=1;
                break;

            }
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;

}

int SECTOR_pEstaSector_DadoDeAlta_Y_EmpleadoPerteneceAlSector_(eSector* unSector,int* pAuxIdSector)
{

    int auxIdSector;
    auxIdSector=*pAuxIdSector;

    if(unSector != NULL && pAuxIdSector != NULL)
    {

        return(SECTOR_pEstaSector_DadoDeAlta_(unSector) &&

                            GENERICA_pEsElNumero_IgualQueElNumero_(&(unSector)->ID_Sector,&auxIdSector));

    }
}


eSector SECTOR_pRetornaElSector_ConElId_(eSector* listaSectores,int tamListaSectores,int* pRetorno,int* pAuxIdSector)
{
    eSector auxSector;
    int retorno;
    int auxIdSector;
    auxIdSector=*pAuxIdSector;
    retorno= 0;

    if( listaSectores != NULL && tamListaSectores > 0 && pAuxIdSector != NULL && pRetorno != NULL)
    {
        for(int i=0; i<tamListaSectores; i++)
        {
               //SECTOR_pEstaSector_DadoDeAlta_(listaSectores + i) &&
            if(GENERICA_pEsElNumero_IgualQueElNumero_(&(listaSectores + i)->ID_Sector,&auxIdSector))
            {

                auxSector = *(listaSectores + i) ;
                retorno = 1;
                *pRetorno = retorno;
                break;
            }
        }

        if(!retorno)
        {
            printf("\n NO SE PUDO RETORNAR EL SECTOR \n");
        }
    }

    *pRetorno = retorno;
    return auxSector;
}

