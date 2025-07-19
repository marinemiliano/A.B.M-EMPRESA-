#ifndef ESECTOR_H_INCLUDED
#define ESECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "data_Warehouse.h"
#include "utn_biblioteca_InputsC.h"
#include "eEmpleado.h"

#define TAM_NOMBRE 20
#define NOMBRE_SECTOR 20
#define TAM_LISTA_SECTORES 100
#define TAM_COMIDAS 10
#define TAM_ALMUERZOS 30


typedef struct
{
	int ID_Sector;
	char descripcion[NOMBRE_SECTOR];
	int is_Sector_Empty;

}eSector;


int SECTOR_pInicializaSectores_DeTam_(eSector* listaSectores,int tamListaSectores);

int SECTOR_pInicializaUnSector(eSector* unSector);

int SECTOR_pCargaSectoresPorDefecto_DeTam_OPCION_UNO(eSector* listaSectores,int tamListaSectores);

int funcion_MostrarSectores(eSector* listaSectores,int tamListaSectores);

int SECTOR_MuestraUnSector_(eSector* unSector);

int SECTOR_pBuscaSiElSector_EstaDadoDeAlta(eSector* listaSectores, int tamListaSectores,int* auxIdSector);

int SECTOR_pEstaSector_DadoDeAlta_(eSector* unSector);

int SECTOR_pHaySectoresDadosDe_Alta(eSector* listaSectores,int tamListaSectores);

int SECTOR_pEstaSector_DadoDeAlta_Y_EmpleadoPerteneceAlSector_(eSector* unSector,int* pAuxIdEmpleado);


int SECTOR_pRetorna_UNO_SiElSector_EstaDadoDeAlta_EnLista_CERO_SINO(eSector* unSector,eSector* listaSectores
                                                                        ,int tamListaSectores);

int SECTOR_pEstaElSector_DadoAlta_Y_IdSector_EsIgualA_AuxIdSector_(eSector* unSector,int* pAuxIdSector);


int SECTOR_pRetornaNombreSectorDelEmpleado(char* auxNombreSectorEmpleado,char* nombreSector);

char SECTOR_retornaDescripcion_DeUnSector_(eSector* unSector);

eSector SECTOR_pRetornaElSector_ConElId_(eSector* listaSectores,int tamListaSectores,int* pRetorno,int* pAuxIdSector);



int SECTOR_pBuscaNombre_DelSector_enListaSectores_DeTam_(eSector* listaSectores
                                                          ,int tamListaSectores
                                                          ,int* auxIDSector,char* auxNombreSectorEmpleado);

int utn_buscarSectorEnListaDe_DeTam_(eSector* listaDeSectores,int tamListaDeSectores,int auxIdComida,int* pAuxIndiceSector);

int utn_ValidarSector(int id,eSector listaSectores[],int tamListaSectores);



void funcion_MostrarUnSector(eSector unSector);

int funcion_MostrarSectores(eSector arraySectores[], int tamSectores);



#endif // ESECTOR_H_INCLUDED
