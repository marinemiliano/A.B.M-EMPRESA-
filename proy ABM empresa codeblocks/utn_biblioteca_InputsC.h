#ifndef UTN_BIBLIOTECA_INPUTSC_H_INCLUDED
#define UTN_BIBLIOTECA_INPUTSC_H_INCLUDED
#define COLUMNAS 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include "data_Warehouse.h"
#include "eEmpleado.h"
#include "eSector.h"
#include "fecha.h"

int utn_pMenuOpciones_(int* opcion,char* opcionesDelMenu,char* mensajeError,int rangoMinimo,int rangoMaximo,int reintentos);

int utn_MenuIngresarLaOpcion_(int* opcion,char* mensajeBienvenida,char* mensajeIngresoALaOpcion,char* mensajeDetalleCantidadItemsASeleccionar,
                              char* mensajeError,int rangoMinimo,int rangoMaximo,int reintentos,char* itemUno,char* itemDos,char* itemTres,char* itemCuatro,char* itemQuinto
                              ,char* itemSexto,char* itemSeptimo,char* itemOctavo,char* itemNoveno);

int utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(char* unChar,char* mensaje,char* mensajeError,int reintentos);

int utn_pIngresoDeCaracterBooleanoS_O_N_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos);

int utn_esCaracterS_O_N(char* cadena, int tamCadena);

int utn_pRespuestaBooleanaSiUno_NoCero(char* mensaje, char* mensajeError,int reintentos);

//FECHA


int utn_pIngresoDeAnioTipoEntero_(int* pUnElementoTipoEntero,char* mensaje ,char* pMensajeError, int rangoMinimo,int rangoMaximo, int reintentos);


//ALFANUMERICO

int utn_pIngresoAlfaNumerico_DeTam_(char* pResultadoAlfaNumericoIngresado,int tamAlfaNumericoIngresado, char* mensaje, char* mensajeError, int rangoMinimo,int rangoMaximo, int reintentos);
int utn_esAlfanumerico(char* cadena, int tamCadena);


//STRINGS

int utn_pIngresoDeSexoF_M_oNoBinario_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos);
int utn_esSexoF_M_oNoBinarioDeTam_(char* cadena, int tamCadena);
int utn_esFemenino_O_MasculinoDeTam_(char* cadena, int tamCadena);
int utn_esSexo_NoBinarioDeTam_(char* cadena, int tamCadena);

int utn_pIngresoDeCaracter_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos);
int utn_pIngresoDeLaCadena_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos);
int utn_obtenerString(char* cadena, int tamCadena);
int utn_esCadena(char* cadena, int tamCadena);

int utn_stringCompletoDeApellido_Ynombre_(char* pNombre,int tamNombre,char* pApellido,int tamApellido ,char* pCompleto, int tamCompleto);
int utn_stringModeladoNombre_YApellido_(char* pNombre,char* pApellido,char* pCompleto);
int utn_colocaMayusculaEnPrimeraLetraDelNombre_yAPellido_(char* pCompleto, int tamCompleto);
int utn_colocaMayusculaAPrimerLetraDe_(char* pPalabra);

int utn_pMostrarVector_TipoCaracterDeTam_(char* pListaDeCaracteres, int tamListaDeCaracteres);
int utn_pMostrarUnCaracter_(char* unCaracter);


int utn_contarPalabrasDe_ConTam_(char* cadenaIngresada,int* pResultadoCadena);
int utn_contarLetrasDe_ConTam_(char* cadenaIngresada,int* pResultadoCadena);
int utn_strLenDeCadena_(char* cadena,int* pContador);
int utn_pasarCadena_AMayuscula(char* cadena);
int utn_reemplazarCaracter_PorCaracter_EnVectorDeCaracter_DeTam_(char* nuevoCaracter, char caracterAReemplazar ,char* pListaDeCaracteres, int tamListaDeCaracteres);
int utn_pVerificaCaracter_En_ConTam_(char* caracterABuscar, char* pListaDeCaracteres, int tamListaDeCaracteres);

int utn_pMuestraVector_ElementosTipoCadenaOCaracterDeTam_(char* pListaDeElementos, int tamListaDeElementos);
int utn_pMuestraUnElementoTipoCadenaOCaracter_(char* unElementoTipoCaracter);

int utn_pActivarFlag_(int* pFlag);
int utn_pResetFlag(int* pFlag);


//FLOTANTE

int utn_pInicializaVector_ElementosTipoFlotanteDeTam_(float* pVectorElementosTipoFlotante,int tamVectorElementosTipoFlotante);
int utn_pInicializaUnElementoTipoFlotante_(float* pUnElementoTipoFlotante);
int utn_pCargaVector_ElementosTipoFlotanteConTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante);
int utn_pMuestraVector_ElementoTipoFlotanteConTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante);
int utn_pMuestraUnElemento_TipoFlotanteConTam_(float* pUnElementoTipoFlotante);
int utn_esElemento_TipoFlotanteElementoInicializador(float* pUnElementoTipoFlotante);
int utn_pPromedioVectorElementosTipoFlotante_DeTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante,float* pResultadoPromedio);
int utn_pAgregaElementoFlotante_EnELAcumulador_(float* pUnElementoTipoFlotante,float* pAcumulador);
int utn_pAcumuladorDeVector_ElementoTipoFlotanteDeTam_(int* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante,float* pAcumulador);
int utn_pIngresoDeElementoTipoFlotante_(float* pUnElementoTipoFlotante,char* pMensaje, char* pMensajeError,int rangoMinimo,int rangoMaximo, int reintentos);
int utn_pObtieneElementoTipoFlotante_(float* pElementoFlotante);
int utn_esElemento_Flotante(char* pUnElementoTipoCadena, int tamElementoTipoCadena);


//ENTEROS

int utn_pInicializaVector_ElementosTipoEnteroDeTam_(int* pVectorElementosTipoEntero,int tamVectorElementosTipoEntero);
int utn_pInicializaUnElementoTipoEntero_(int* pUnElementoTipoEntero);
int utn_pCargaVector_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_pMuestraVector_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_pCargaAleatoriaVector_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_pMuestraVectorAleatorio_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_pMuestraUnElemento_TipoEnteroConTam_(int* pUnElementoTipoEntero);
int utn_esElemento_TipoEnteroElementoInicializador(int* pUnElementoTipoEntero);
//int utn_pIngresoDeElementoTipoEntero_(int* pUnElementoTipoEntero,char* pMensaje, char* pMensajeError,int caracterAnio, int rangoMinimo,int rangoMaximo, int reintentos);
int utn_pIngresoDeElementoTipoEntero_(int* pUnElementoTipoEntero,char* pMensaje, char* pMensajeError,int rangoMinimo,int rangoMaximo, int reintentos);
int utn_pObtieneElementoTipoEntero_(int* pUnElementoTipoEntero);
int utn_copiaElementoTipoCadenaEn_DeTam_(char* pUnElementoTipoCadena, int tamElementoTipoCadena);

int utn_esElemento_Numerico(char* pUnElementoTipoCadena, int tamElementoTipoCadena);//ME FALTO ARREGLAR QUE PASA SI INGRESARMOS UN - Y LUEGO COLOCAMOS EL ENTER

int utn_cantDeReintentos(int* reintentos,char* mensajeError);


int utn_calcularEdad(int anioActual ,int anioNacimientoEmpleado ,int* pEdad,int* edadMinima,int* edadLimite);


//INFORMES

int utn_CantidadElementosTipoEnteroPositivos_Y_NegativosEn_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* cantidadNegativos,int* cantidadPositivos);
int utn_CantidadElementosTipoEnteroNegativosEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* cantidadNegativos);
int utn_CantidadElementosTipoEnteroPositivosEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* cantidadPositivos);

int utn_pSignoDelNumeroEntero_(int* pUnElementoTipoEntero);
int utn_pSumatoriaElementosParesDelVector_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* sumatoriaPares);
int utn_pAgregaElementoEntero_EnELAcumulador_(int* pUnElementoTipoEntero,int* acumulador);
int utn_pMayorElementoEnteroImparDe_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pMaximoImpar);
int utn_esElemento_Par(int* unElementoEntero);
int utn_pMayorElementoTipoEnteroDeVector_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pMayorElemento);
int utn_pMenorElementoTipoEnteroDeVector_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pMenorElemento);
int utn_pMuestraDeElementosTipoEnteroPar_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_pPosicionDeElementosTipoEnteroParEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_posicionesDeVector_DondeSeEncuentraElElementoMayor(int* plistaElementosTipoEntero, int tamListaElementosTipoEntero, int* pMayorElemento);
int utn_pMuestraUnElemento_TipoEntero(int* unElementoTipoEntero,char* mensaje);
int utn_pPosicionDeElementosTipoEnteroImparEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero);
int utn_pPromedioVectorElementosTipoEntero_DeTam_(int* pListaElementosTipoEntero,
                                                            int tamListaElementosTipoEntero,
                                                                            float* pResultadoPromedio);
int utn_pAcumuladorDeVector_ElementoTipoEnteroDeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero ,int* pAcumulador);
int utn_calculaElMayorEntreElemento_y_(int* unElemento,int* otroElemento,int* pResultado);


int utn_retornarNumeroDeCuil(char* pResultadoCuilIngresado,int tamCuilIngresado,char* mensaje,char* mensajeError,int reintentos);
int utn_validarCuil(char* cadena,int tamCadena);
int utn_pasarCadenaCon10Caracteres_ACuil(char* cadena,int tamCadena);
int utn_pasarCadenaCon11Caracteres_ACuil(char* cadena,int tamCadena);


int utn_retornarTelefonoDeLinea(char* pResultadoTelefonoIngresado,int tamTelefonoIngresado,char* mensaje,char* mensajeError,int reintentos);
int utn_retornarTelefonoCelular(char* pResultadoTelefonoIngresado,int tamTelefonoIngresado,char* mensaje,char* mensajeError,int reintentos);
int utn_validarTelefonoDeLinea(char* cadena,int tamCadena);
int utn_validarTelefonoCelular(char* cadena,int tamCadena);
int utn_formatearTelefono(char* cadena,int tamCadena,int posDondeVaElGuion);

int utn_obtenerEmail(char* correo,int tamStringCorreo,char* mensaje, char* mensajeError, int reintentos);
int utn_esMail(char* auxMail, int tamCadena);


//ORDENAMIENTOS Y SWAPEOS

int utn_pSwapeoDeValoresEntre_Y_(int* unaVariable, int* otraVariable);
int utn_pOrdenarVector_TipoCaracterDeTam_(char* pListaDeCaracteres, int tamListaDeCaracteres, int* pCriterioCrecienteDecreciente);
int utn_pMostrarVectorOrdenadoCrecienteODecreciente_TipoCaracterDeTam_(char* pListaDeCaracteres, int tamListaDeCaracteres,int criterioCrecienteDecreciente);

int utn_pOrdenarElVector_DeElementoTipoEnteroDeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pCriterioCrecienteDecreciente);
int utn_pMostrarVectorOrdenadoCrecienteODecreciente_DeTipoElementoEntero_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int criterioCrecienteDecreciente);


//VECTORES PARALELOS

int utn_utnMostrarVectorParalelo_ElementoTipoCadena_(char pListaDeElementosCadena[][COLUMNAS], int tamListaDeElementosCadena);
int utn_utnMostrarUnElementoVectorParalelo_TipoCadena_(char* pListaDeElementosCadena[]);

int utn_pMuestraUnElementoTipoCadenaEnVectorParalelo_(char* unElementoTipoCadena[][COLUMNAS] ); //NO FUNCIONA CREO

int pMuestraVectorParalelo_ElementosTipoEnteroDeTam_(int* pListaDeElementos[][COLUMNAS],int filas);
int utn_ingresoVectorParalelo_ElementosTipoCadenaDeTam_(char pListaDeElementos[][COLUMNAS],int tam);

int utn_pMenuOrdenarVectorParalelo_PorCriterioCrecienteODecreciente_(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam);
int utn_ordenarVector_PorPromedio(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam,int* pCriterioCrecienteDecreciente);
int utn_ordenarVector_PorLegajo(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam,int* pCriterioCrecienteDecreciente);
int utn_ordenarVector_PorNombre(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam,int* pCriterioCrecienteDecreciente);

int utn_calcularPromedioDeNotas_Y_(int* notas1, int* notas2,float* pPromedio);
int utn_pAcumuladorVectorParalelo_ElementosTipoEnteroDeTam_(int pListaDeElementos[][COLUMNAS],int filas);

int utn_ordenamientoDobleCriterio(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam);
int  utn_mostrarVectoresParalelos_Y_(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam);

#endif // UTN_BIBLIOTECA_INPUTSC_H_INCLUDED
