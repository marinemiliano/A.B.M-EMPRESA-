#ifndef DATA_WAREHOUSE_H_INCLUDED
#define DATA_WAREHOUSE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "eEmpleado.h"
#include "almuerzo.h"


int EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_UNO(eEmpleado* listaEmpleados,int tamListaEmpleados);

int EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_DOS(eEmpleado* listaEmpleados,int tamlistaEmpleados
                                                    ,int cantElementosACargarEnVector,int* pLegajo);

int EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_TRES(eEmpleado* listaEmpleados,int tamlistaEmpleados
                                                        ,int cantElementosACargarEnVector,int* pLegajo);

int SECTOR_pCargaSectoresPorDefecto_DeTam_OPCION_UNO(eSector* listaSectores,int tamListaSectores);


int COMIDA_pCargaComidasPorDefecto_DeTam_OPCION_UNO(eComida* listaComidas,int tamListaComidas);

int utn_CreaListaDeEstructuras_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,int cantElementosACargarEnVector,int* pLegajo);

int ALMUERZOS_HarcodearAlmuerzos(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos,int cantElementosACargar ,int* pIdAlmuerzo);

int ALMUERZO_pCargaAlmuerzosPorDefecto_DeTam_OPCION_UNO(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                        ,eSector* listaSectores,int tamListaSectores
                                                        ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                        ,eComida* listaComidas, int tamListaComidas);

int utn_pCargaEmpleadosPorDefecto_DeTam_(eEmpleado* listaEmpleados,int tamlistaEmpleados,int cantElementosACargarEnVector,int* pLegajo);

#endif // DATA_WAREHOUSE_H_INCLUDED
