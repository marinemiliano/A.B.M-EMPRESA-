#ifndef EEMPLEADO_H_INCLUDED
#define EEMPLEADO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>


#include "data_Warehouse.h"
#include "utn_biblioteca_InputsC.h"
#include "eSector.h"
#include "fecha.h"
#include "almuerzo.h"

#define TAM_NOMBRE 20
#define TAM_SEXO 3
#define NOMBRE_SECTOR 20

#define TAM_LISTA_EMPLEADOS 20
#define TAM_LISTA_SECTORES 10
#define TAM_LISTA_COMIDAS 10
#define TAM_LISTA_ALMUERZOS 50

typedef struct{

	int legajo;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	eFecha fecha_Nacimiento_Empleado;
	int edad;
	char sexo[TAM_SEXO];
	float sueldo;
	eFecha fecha_Ingreso_Empleado;
	int ID_Sector;
	int is_Empleado_Full;
	int is_Empleado_Empty;
	int is_PosicionLista;

}eEmpleado;


int EMPLEADO_pInicializaEstructuras_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras);

int EMPLEADO_pInicializaUnaEstructura_(eEmpleado* pUnaEstructura);


int NEXO_pMenuAltas(eEmpleado* listaEmpleados,int tamListaEmpleados
                     ,eSector* listaSectores,int tamListaSectores
                     ,eComida* listaComidas,int tamListaComidas
                     ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                     ,int* pNextID_Empleado,int* pNextID_Almuerzo);

int NEXO_pAltaEstructura_DeTam_DOS(eEmpleado* listaEmpleados,int tamListaEmpleados
                                   ,eSector* listaSectores,int tamListaSectores,int* pID);

eEmpleado NEXO_CargaDatosDeLaEstructura_(eSector* listaSectores,int tamListaSectores,int* pRetorno,int* pID);


 int NEXO_pMenuMostrar(eEmpleado* listaEmpleados,int tamListaEmpleados
                        ,eSector* listaSectores,int tamListaSectores
                       ,eComida* listaComidas,int tamListaComidas
                       ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int NEXO_pMuestraEstructuras_DeTam_DOS(eEmpleado* listaEmpleados,int tamListaEmpleados
								      ,eSector* listaSectores,int tamListaSectores);


int NEXO_MuestraUnaEstructura_DOS(eEmpleado* unEmpleado,eSector* listaSectores,int tamListaSectores);


int NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(eEmpleado* unEmpleado,eSector* listaSectores,int tamListaSectores);

int NEXO_pMuestraEmpleados_DadosDeBaja_DOS(eEmpleado* listaEmpleados,int tamListaEmpleados
                                            ,eSector* listaSectores,int tamListaSectores);


int NEXO_pMuestraEmpleados_DadosDeDeBaja_EnUnSector(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector);

int EMPLEADO_pHayEmpleados_DeLaLista_DadosDeBaja_EnElSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector);

int EMPLEADO_pEstaEmpleado_DadoDeBaja_Y_PerteneceAlSector_(eEmpleado* unEmpleado,int* pAuxIdSector);




///1) 2217

int NEXO_pMenuBajas(eEmpleado* listaEmpleados,int tamListaEmpleados
                     ,eSector* listaSectores,int tamListaSectores
                    ,eComida* listaComidas,int tamListaComidas
                    ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int NEXO_pMenuBajaEmpleados(eEmpleado* listaEmpleados,int tamListaEmpleados
                            ,eSector* listaSectores,int tamListaSectores
                            ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


char menuRetornoBajaEmpleados(int* pAuxRetorno);


int NEXO_pIngreso_A_BajaEmpleado_Y_Sus_Almuerzos(listaEmpleados,tamListaEmpleados
                                               ,listaSectores,tamListaSectores
                                              ,listaAlmuerzos,tamListaAlmuerzos);


char menuRetornosBajaUnEmpleadoYSusAlmuerzos(int* pAuxRetornoMenu);


int NEXO_pCargaIdEmpleadoEn_DeLaLista_(int* pAuxIdEmpleado
                                       ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                       ,eSector* listaSectores,int tamListaSectores);


int EMPLEADO_pRetorna_UNO_SiElEmpleado_EstaDadoDeAlta_EnLista_CERO_SINO(eEmpleado* unEmpleado,eEmpleado* listaEmpleados
                                                                        ,int tamListaEmpleados);


int EMPLEADO_pEstaElEmpleado_DadoDeAlta_Y_EsElEmpleado_(eEmpleado* unEmpleado,int* pAuxIdEmpleado);


int EMPLEADO_pBuscaLaPosicion_DelEmpleado_DadoDeAlta_EnLaLista_(int* pAuxPosicion,eEmpleado* unEmpleado
                                                               ,eEmpleado* listaEmpleados,int tamListaEmpleados);

//busca la posicion del empleado y la retorna
int EMPLEADO_pRetornaLaPosicion_DeUnEmpleado_DadoDeAlta_EnLaLista_(int* pAuxPosicion,eEmpleado* unEmpleado
                                                                   ,eEmpleado* listaEmpleados,int tamListaEmpleados);


eEmpleado EMP_pRetornaElEmpleado_ConElId_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                          ,int* pRetorno ,int* pAuxIdEmpleado);


int NEXO_pBajaUnEmpleado_Y_SusAlmuerzosDeLaLista_(eEmpleado* unEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleado
                                                  ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int EMPLEADO_pBajaUnEmpleado_DeLaLista_(eEmpleado* unEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados);

int EMPLEADO_pBajaUnEmpleado_(eEmpleado* unEmpleado);

int EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(eEmpleado* unEmpleado);




char menu_RetornoMenuPrincipal(int switchMenuPrincipal
                               ,int switchSegundoMenuElementos,int* pAuxRetornoMenuTercerNivel);


char menu_RetornoMenuBajaEmpleados(int switchMenuBajaEmpleados,int* pAuxRetornoMenu);


char menu_RetornoMenuReingresosEmpleado(int switchMenuReingresoElementos,int* pAuxRetornoMenu);


char menu_RetornoParaItemsConUnEmpleado(char* caseCero,char* caseUno,char* caseDos,char* caseTres
                                        ,char* caseCuatro,char* caseCinco,char* caseSeis,char* caseSiete
                                        ,char* caseOcho,char* caseNueve,char* menuParaAQueMenuDeseaVolver
                                        ,char* mensajeMenuContinuar,char* mensajeError,
                                        int* pAuxRetornoMenu);

char menuRetornos_BajaTodosLosEmpleadosDeLaEmpresa(char* caseCero,char* caseUno,char* caseDos,char* caseTres
                                                    ,char* caseCuatro,char* menuParaAQueMenuDeseaVolver
                                                    ,char* mensajeMenuContinuar,char* mensajeError,
                                                    int* pAuxRetornoMenu);


char menu_aQueMenuDeseaVolver(char* eleccionDeOpciones,int* pAuxRetornoMenu);



///2) 1410

int NEXO_pIngreso_A_BajaTodosEmpleados_Y_Almuerzos_DeUnSector_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                              ,eSector* listaSectores,int tamListaSectores
                                                              ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int NEXO_pCargaIdSectorEn_DeLaLista_(int* pAuxIdSector,eEmpleado* listaEmpleados,int tamListaEmpleados
                                    ,eSector* listaSectores,int tamListaSectores);

 int NEXO_pMuestraEmpleados_DadosDeAlta_PorSectores(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                    ,eSector* listaSectores,int tamListaSectores);

int NEXO_pSiElSector_EstaDadoDeAlta_MuestraLosEmpleados(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector);


int NEXO_pMuestraEmpleados_DadosDeDeAlta_EnUnSector(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                    ,eSector* unSector);

void NEXO_pMuestraUnEmpleado_DelSector_(eEmpleado* unEmpleado,eSector* unSector);


int NEXO_pBajaTodosLosEmpleados_DeUnSector_Y_SusAlmuerzos_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                            ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                            ,eSector* unSector);

int EMPLEADO_pHayEmpleados_DeLaLista_DadosDeAlta_EnElSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector);


int NEXO_pEliminaEmpleado_Y_SusAlmuerzos_DeLaLista_Si_EmpleadoPerteneceAlSector_(eEmpleado* unEmpleado,eAlmuerzo* listaAlmuerzos
                                                                                ,int tamListaAlmuerzos,eEmpleado* listaEmpleados
                                                                                ,int tamListaEmpleado,eSector* unSector);

int EMPLEADO_pEstaEmpleado_DadoDeAlta_Y_PerteneceAlSector_(eEmpleado* unEmpleado,int* pAuxIdSector);

int EMPLEADO_pEstaEmpleado_DadoDeAlta_(eEmpleado* unEmpleado);



///3 1969

int NEXO_pIngreso_A_BajaTodosEmpleadosDeLaLista_Y_SusAlmuerzos_(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores
                                                                ,listaAlmuerzos,tamListaAlmuerzos);

int EMPLEADO_pBajaTodosLosEmpleadosDeLaLista_Y_SusAlmuerzosDe_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);




///4  2017

int NEXO_pMenuReingresos(eEmpleado* listaEmpleados,int tamListaEmpleados
                        ,eSector* listaSectores,int tamListaSectores
                        ,eComida* listaComidas,int tamListaComidas
                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int NEXO_pMenuReingreso_Empleados(eEmpleado* listaEmpleados,int tamListaEmpleados
                                ,eSector* listaSectores,int tamListaSectores
                                ,eComida* listaComidas,int tamListaComidas
                                ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int NEXO_pIngreso_A_ReingresaEmpleado_Y_SusAlmuerzos_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                      ,eSector* listaSectores,int tamListaSectores
                                                      ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int NEXO_pReingresaEmpleado_Y_SusAlmuerzos(eEmpleado* unEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados
                                           ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int NEXO_pCargaIdEmpleado_AReingresar_(int* pAuxIdEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados
                                        ,eSector* listaSectores,int tamListaSectores);

int EMPLEADO_pReingresaEmpleado_DadoDeBaja_ConID_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* pAuxIdEmpleado);


///



/// 5

int NEXO_pIngreso_A_ReingresaTodosLosEmpleados_Y_SusAlmuerzos_DeUnSector(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                                        ,eSector* listaSectores,int tamListaSectores);


int NEXO_pCargaIdSector_(int* pAuxIdSector,eSector* listaSectores,int tamListaSectores);

int NEXO_pReingresa_TodosEmpleados_Y_SusAlmuerzos_DelSector_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                             ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                              ,int* pAuxIdSector);

int NEXO_pReingresa_Empleado_Y_SusAlmuerzos_SiEstaDadoDeAlta_Y_SiPerteneceAlSector_(eEmpleado* unEmpleado,int* pAuxIdSector
                                                                                  ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                                  ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int EMPLEADO_pHayEmpleadosDadosDe_Baja(eEmpleado* listaEmpleados,int tamListaEmpleados);

int EMPLEADO_pEstaEmpleado_DadoDeBaja_(eEmpleado* unEmpleado);





/// 6

int NEXO_pIngreso_A_pReingresaTodosLosEmpleados_Y_SusAlmuerzosDe_TodosLosSectores(
                                                                                  eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                                  ,eSector* listaSectores,int tamListaSectores
                                                                                  ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


int EMPLEADO_pReingresaTodosLosEmpleados_Y_SusAlmuerzosDe_TodosLosSectores(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);


///


eSector SECTOR_pRetorna_ElSectorDelEmpleado_(eSector* listaSectores,int tamlistaSectores,int* pRetorno,int* pAuxIdSector);


int GENERICA_pEsElNumero_IgualQueElNumero_(int*unNumero,int* otroNumero);








int EMPLEADO_pBajaTodosEmpleados_DelSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* pAuxIdSector);


int EMPLEADO_pBajaUnEmpleado_DelSector_(eEmpleado* unEmpleado, int* pAuxIdSector);


int EMPLEADO_pBajaTodosLosEmpleados_DeLaLista_(eEmpleado* listaEmpleados,int tamListaEmpleados);


int NEXO_pIngresaIdSector_ParaDarDeBaja_TodosSusEmpleados_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                            ,eSector* listaSectores,int tamListaSectores
                                                            ,int* pAuxIdSector);







int EMPLEADO_pAltaEmpleado_CambiaLasBanderasAEmpleado_DadoDeAlta_(eEmpleado* unEmpleado);


int EMPLEADO_pHayEmpleadosDadosDe_Alta(eEmpleado* listaEmpleados,int tamListaEmpleados);


//RETORNA EL INDICE POR REFERENCIA
int EMP_BuscaPosicionLibreEnLista_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,int* pIndice);



int NEXO_pRetornaUnAlmuerzo_DeLaListaAlmuerzos_SiEsDelEmpleado_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                                    ,eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado);

int NEXO_pRetornaUnAlmuerzo_SiEsDelEmpleado_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                               ,eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado);



int EMPLEADO_pEstaEmpleado_EnElAlmuerzo_(eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado );


int NEXO_pBuscaEmpleado_SiEstaDadoDeBaja_ConID_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* auxIDEmpleado);



int NEXO_pEstaElEmpleado_EstaDadoDeAlta_EnLista_(int* auxIDEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados);


int EMPLEADO_pBuscaNombreEmpleado_EnListaEmpleados_DeTam_(eEmpleado* listaDeEmpleados,int tamListaDeEmpleados
                                                              ,char* auxNombreEmpleado,int* auxIdEmpleado);


int EMPLEADO_pRetornaNombreDelEmpleado(char* auxNombreEmpleado ,char* nombreEmpleado);


int EMPLEADO_pBuscaApellidoEmpleado_EnListaEmpleados_DeTam_(eEmpleado* listaDeEmpleados,int tamListaDeEmpleados
                                                            ,int* IdEmpleado,char* auxApellidoEmpleado);


int EMPLEADO_pRetornaApellidoDelEmpleado_(char* auxApellidoEmpleado,char* apellidoEmpleado);


int EMPLEADO_pBusca_IDSectorDelEmpleadoEn_ListaEmpleados_DeTam_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                ,int* pIDEmpleado,int* pAuxIDSector);

int EMPLEADO_pRetornaIDSectorDelEmpleado(int* auxIDSector,int* IdSector);

int EMPLEADO_pBuscaNombre_DelEmpleado_DeLaLista_DeTam_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                       ,int* auxIDEmpleado,char* auxNombreEmpleado);

int EMPLEADO_pRetornaNombreDelEmpleado(char* auxNombreEmpleado,char* nombreEmpleado);


int NEXO_pMenuModificar(eEmpleado* listaEmpleados,int tamListaEmpleados
                          ,eSector* listaSectores,int tamListaSectores
                          ,eComida* listaComidas,int tamListaComidas
                          ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);



int NEXO_pModificaEmpleados_CUATRO(eEmpleado* listaEmpleados,int tamListaEmpleados
                                  ,eSector* listaSectores,int tamListaSectores
                                  ,eComida* listaComidas,int tamListaComidas
                                  ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

eEmpleado NEXO_pModificaUnEmpleado_CUATRO(eEmpleado* unEmpleado
                                          ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                          ,eSector* listaSectores,int tamListaSectores
                                          ,eComida* listaComidas,int tamListaComidas
                                          ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,int* pRetorno);


eEmpleado NEXO_pMenu_ModificaFecha_Nacimiento_Empleado_(eEmpleado* unEmpleado,int* listaSectores
                                                        ,int tamListaSectores,int* pRetorno);


eEmpleado NEXO_pMenu_ModificaFecha_Ingreso_Empleado_(eEmpleado* unEmpleado,int* listaSectores
                                                     ,int tamListaSectores,int* pRetorno);


int NEXO_pReingresaAlmuerzos_DeEmpleado_DadoDeBaja_ConID(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                         ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                         ,int* pAuxIdEmpleado);


int EMPLEADO_pEstaEmpleado_EnSector_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                     ,int* auxIdEmpleado,int* auxIdSector);


 int utn_CargarNombreEmpleadoDeLaLista_ConLegajo_EnLaVariable_(eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                                              ,int* auxIdEmpleado,char auxNombreEmpleado);

int utn_pCargaComidasPorDefecto_DeTam_OPCION_UNO(eComida* listaComidas,int tamListaComidas);


int NEXO_bajaAlmuerzoEmpleado(eEmpleado* listaEmpleados,int tamListaEmpleados
                             ,eSector* listaSectores,int tamListaSectores
                             ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int utn_pCargaListaDeEstructuras_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras);


int utn_pCargaUnaEstructura_(eEmpleado* unaEstructura, int anioActual
                             ,eSector* unaListaDeEstructuras,int tamUnaListaDeEstructuras);

int utn_AltaEstructura_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,int* pID);


int utn_BajaEstructura_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras);

int utn_bajaUnaEstructuraConId_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,int auxIdEstructura);

int utn_ModificaEstructura_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras);

int utn_ModificaUnaEstructura_(eEmpleado* unEmpleado);


int utn_MuestraUnaEstructura_(eEmpleado* unaEstructura,char* mensajeBienvenida,char* itemUno,char* itemDos
                              ,char* itemTres,char* itemCuatro,char* itemQuinto
                              ,char* itemSexto,char* itemSeptimo,char* itemOctavo,char* itemNoveno);

 int utn_pMuestraListaDeEmpleados_DeTam_UNO(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras);

int utn_MuestraUnEmpleado_UNO(eEmpleado* unaEstructura);



int utn_pCargaAltaAlmuerzo(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                            ,eComida* listaComidas, int tamListaComidas
                            ,eEmpleado* listaEmpleados,int tamListaEmpleados
                            ,eSector* listaSectores,int tamListaSectores
                            ,int* pIdAlmuerzo);


eAlmuerzo utn_pCargaUnAlmuerzo_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                ,eComida* listaComidas, int tamListaComidas
                                ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                ,eSector* listaSectores,int tamListaSectores
                                ,int* auxRetorno,int* pAuxIDAlmuerzo);

 int NEXO_MuestraListaDeAlmuerzos_DeTam_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                       ,eSector* listaSectores,int tamListaSectores
                                       ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                       ,eComida* listaComidas,int tamListaComidas);


int NEXO_MuestraUnAlmuerzo_DeLaListaDeAlmuerzos_(eAlmuerzo* unAlmuerzo
                                                ,eSector* listaSectores,int tamListaSectores
                                                ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                ,eComida* listaComidas,int tamListaComidas);


void utn_mostrarMensaje(char mensaje[]);


int ALMUERZO_pBajaTodosAlmuerzos_DeEmpleado_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                             ,eEmpleado* unEmpleado);




#endif // EEMPLEADO_H_INCLUDED








