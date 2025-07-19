#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "eEmpleado.h"
#include "eSector.h"
#define   NO_FULL 0
#define   FULL 1
#define  EMPTY 1
#define  NO_EMPTY 0

#define  LA_POSICION_NUNCA_FUE_CARGADA 0

//NOS AVISA QUE LA POSICION ALGUNA VEZ SE CARGO
//ES UNA BANDERA QUE ES IMPORTANTE PARA DAR DE ALTA
//EMPLEADOS DADOS DE BAJA Y QUE SE RESPETEN SUS POSICIONES
//DENTRO DE LA LISTA
#define  LA_POSICION_ESTUVO_CARGADA 1

int NEXO_menuInformes_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,eSector* listaSectores,int tamListaSectores
                     ,eEmpleado* listaEmpleados,int tamListaEmpleados,eComida* listaComidas,int tamListaComidas);

int utn_Sector_ConMejorSueldo(eSector* listaDeSectores,int tamListaDeSectores
                                        ,eEmpleado* listaDeEmpleados,int tamListaEmpleados);

int utn_CantidadElementosQueHayDe_EnUnaDeLasEstructurasDe_(eEmpleado* listaDeEstructuras
                                                           ,int tamListaDeEstructuras
                                                           ,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras);

int utn_actualizarElementosDeLaLista_SegunPorcentaje(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras
                                                     ,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras);


int utn_incrementaElemento_ConElPorcentaje_(float* elementoAIncrementarPorPorcentaje, float pPorcentaje);

int utn_TotalElementosEn_PorSector_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras
                                    ,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras);


int utn_mayorElementoDeLaEstructura_(eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras
                                     ,eEmpleado* listaDeEstructuras,int tamListaDeEstructuras);


//estos dos hacen lo mismo pero estan programados de forma diferente
int utn_pMayorElementoTipoFlotanteDeVector_ConTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante
                                                   ,float* pMayorElemento,eSector* otraListaDeEstructuras
                                                   ,float* auxSectoresConMayorSueldo ,char auxDescripcionSectoresMayorSueldo[][20]);

int utn_SectorDe_ConMejorSueldo_DeTam_(eSector* listaDeSectores,int tamListaDeSectores
                                        ,eEmpleado* listaDeEmpleados,int tamListaEmpleados);


int utn_estaEmpleado_EnSectorConId_(eEmpleado* unEmpleado ,int idSector);

int utn_estaEmpleado_Activo(eEmpleado* unEmpleado);

int utn_estaEmpleado_Vacio(eEmpleado* unEmpleado);

int utn_totalGastosEnComidasPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                      ,eComida* listaDeComidas, int tamListaComidas);


int utn_cantidadDeAlmuerzosPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados);


 int utn_cantidadDeEmpleadosPorSector_(eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados);




int utn_comidaPreferidaDelSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                  ,eSector* listaDeSectores,int tamListaDeSectores
                                  ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                  ,eComida* listaDeComidas, int tamListaComidas);


int utn_pMayorCantidadDeUnTipoDeComidaQueSeComeEnUnSector_ConTam_( int* auxlistaDeComidas
                                                                   ,int tamAuxListaDeComidas
                                                ,int* mayorCantidadTipoDeComida
                                                ,eComida* listaDeComidas
                                                ,char auxDescripcionComidasAcargar[][20]);

 int utn_sectorQueMasEligeLaComidaSeleccionada_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                              ,eSector* listaDeSectores,int tamListaDeSectores
                                              ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                              ,eComida* listaDeComidas, int tamListaComidas);


int utn_sectorEnELCualSeComeMasLaComida_(int* auxlistaDeUnTipoDeComidaPorSector,int tamAuxListaDeSectores
                                        ,eSector* listaDeSectores,int* pMayorCantidadComidaEnUnSector
                                        ,char auxVectorCargarNombresDeSectores[][20]);


int utn_cantidadDeComidasPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                      ,eComida* listaDeComidas,int tamListaComidas);

#endif // INFORMES_H_INCLUDED
