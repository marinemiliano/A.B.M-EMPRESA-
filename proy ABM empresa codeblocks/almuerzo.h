#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED


#include "fecha.h"
#include "eEmpleado.h"


typedef struct
{
	int id_Comida;
	char descripcion[20];
	float precio;
	int is_Comida_Empty;

}eComida;

typedef struct
{
	int id_Almuerzo;
	int leg_Empleado;
	char nombre_Empleado[20];
	char apellido_Empleado[20];
	int id_Comida;
	eFecha fecha_De_Almuerzo;
	int is_Almuerzo_Full;
	int is_Almuerzo_Empty;
	int is_PosicionLista;

}eAlmuerzo;


int utn_pMuestraListaDeComidas_DeTam_ConNombreDeEmpleado(eComida* listaDeEstructuras,int tamListaDeEstructuras
                                                        ,eAlmuerzo* listaDeAlmuerzos,int tamlistaDeAlmuerzos);


int utn_pMuestraUnaComida_DeLaListaDeComidas_(eComida* unaEstructura
                                              ,eAlmuerzo* listaDeAlmuerzos,int tamlistaDeAlmuerzos);


int COMIDA_pMuestraListaDeComidas_DeTam_(eComida* listaComidas,int tamListaComidas);

int COMIDA_MuestraUnaComida_(eComida* unaComida);

int COMIDAS_pInicializaComidas_DeTam_(eComida* listaComidas,int tamListaComidas);

int COMIDAS_pInicializaUnaComida_(eComida* pUnaComida);


int ALMUERZO_pInicializaAlmuerzos_DeTam_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int ALMUERZO_pInicializaUnAlmuerzo_(eAlmuerzo* pUnAlmuerzo);


int ALMUERZO_pBajaUnAlmuerzo_(eAlmuerzo* unAlmuerzo);


int ALMUERZO_pBajaAlmuerzo_CambiaLasBanderasAlmuerzo_DadoDeBaja_(eAlmuerzo* unAlmuerzo);


int ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(eAlmuerzo* unAlmuerzo);

int ALMUERZO_pReingresaTodosAlmuerzos_DeEmpleadoConId_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,int* pIDEmpleado);

int ALMUERZO_pReingresaUnAlmuerzo_DeUnEmpleado_(eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado);

int ALMUERZO_pAltaAlmuerzo_CambiaLasBanderas_ALMUERZO_DadoDeAlta_(eAlmuerzo* unAlmuerzo);

int ALMUERZO_pHayAlmuerzosDadosDe_Alta(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int ALMUERZO_pHayAlmuerzosDadosDe_Baja(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos);

int COMIDA_pEstaComida_DadoDeAlta(eComida* unaComida);


int COMIDA_pBuscaNombre_DeComida_EnListaComidas_DeTam_(eComida* listaDeComidas,int tamListaComidas
                                                        ,int* auxIdComida,char* auxDescripcionComida);

int COMIDA_pRetornaNombreDelEmpleado(char* auxNombreComida,char* nombreComida);




int COMIDA_pBuscaIndiceComidaEnListaComidas_DeTam_(eComida* listaDeComidas,int tamListaDeComidas,int auxIdComida,int* pAuxIndice);

int utn_cargaNombreDeLaComida_(eComida* listaDeComidas,int tamListaComidas,int auxIdComida,char* pAuxNombreComida);


int ALMUERZO_BuscaIndiceLibreEnListaDeAlmuerzos_DeTam_(eAlmuerzo* listaDeEstructuras,int tamListaDeEstructuras,int* pIndice);

int ALMUERZO_pBajaTodosAlmuerzos_DeEmpleadoConId_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,int* pIDEmpleado);




#endif // ALMUERZO_H_INCLUDED
