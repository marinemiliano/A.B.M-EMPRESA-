#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "data_Warehouse.h"
#include "utn_biblioteca_InputsC.h"
#include "eEmpleado.h"
#include "eSector.h"
#include "informes.h"
#include "fecha.h"
#include "almuerzo.h"
#define TAM_SEXO 3

#define TAM_LISTA_EMPLEADOS 20
#define TAM_LISTA_SECTORES 10
#define TAM_LISTA_COMIDAS 10
#define TAM_LISTA_ALMUERZOS 50

#define  MIN_ID_EMPLEADO 1
#define  MAX_ID_EMPLEADO  10000

#define REINTENTOS 3

#define TAM_NOMBRE 50
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


int main()
{

        int opcion;
        char seguir;
        char salir;
        int retorno;
        int pNextID_Empleado;
        int pIdAlmuerzo;
        pIdAlmuerzo=4;
        pNextID_Empleado=12;

        eEmpleado listaEmpleados[TAM_LISTA_EMPLEADOS];
        eSector listaSectores[TAM_LISTA_SECTORES];
        eComida listaComidas[TAM_LISTA_COMIDAS];
        eAlmuerzo listaAlmuerzos[TAM_LISTA_ALMUERZOS];
        //int anioActual = 2024;

        utn_mostrarMensaje("\n EN ESTE PROGRAMA USTED PODRA DAR DE ALTA EL EMPLEADO DE UNA EMPRESA,DARLO DE BAJA E INCLUSO "
                           "MODIFICARLO. \n TAMBIEN PODRA DAR DE ALTA SUS ALMUERZOS, LAS COMIDAS QUE SE COMEN ETC. \n"
                           " \n PARA REALIZAR PRUEBAS SOBRE EL PROGRAMA ES QUE SE HA CREADO UNA PLANTILLA DE EMPLEADOS "
                           "POR DEFECTO, \n EL CUAL USTED OBSERVARA EN LA SECCION MOSTRAR EMPLEADOS DEL SIGUIENTE MENU. \n");


         EMPLEADO_pInicializaEstructuras_DeTam_(listaEmpleados,TAM_LISTA_EMPLEADOS);

         ALMUERZO_pInicializaAlmuerzos_DeTam_(listaAlmuerzos,TAM_LISTA_ALMUERZOS);

         SECTOR_pInicializaSectores_DeTam_(listaSectores,TAM_LISTA_SECTORES);

         //COMIDAS_pInicializaComidas_DeTam_(listaComidas,TAM_LISTA_COMIDAS);

         EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_UNO(listaEmpleados,TAM_LISTA_EMPLEADOS);

         COMIDA_pCargaComidasPorDefecto_DeTam_OPCION_UNO(listaComidas,TAM_LISTA_COMIDAS);

         SECTOR_pCargaSectoresPorDefecto_DeTam_OPCION_UNO(listaSectores,TAM_LISTA_SECTORES);

         ALMUERZO_pCargaAlmuerzosPorDefecto_DeTam_OPCION_UNO(listaAlmuerzos,TAM_LISTA_ALMUERZOS
                                                             ,listaSectores,TAM_LISTA_SECTORES
                                                             ,listaEmpleados,TAM_LISTA_EMPLEADOS
                                                             ,listaComidas,TAM_LISTA_COMIDAS);
    do
	{
                utn_pMenuOpciones_(&opcion
                                  ,"\n\n  MENU PRINCIPAL     \n"
                                   "\n 1.MENU ALTA \n"
                                   " 2.MENU BAJAS\n"
                                   " 3.MENU REINGRESOS\n"
                                   " 4.MENU MODIFICAR \n"
                                   " 5.MOSTRAR LISTADOS\n"
                                   " 6.SALIR\n"
                                   "\n INGRESAR UNA OPCION DEL 1 AL 6: "
                                  ,"\n ERROR AL INGRESAR LA OPCION \n"
                                   ,1,6,2);

                                  system("cls");
		switch(opcion)
		{

			case 1:

                        NEXO_pMenuAltas(listaEmpleados,TAM_LISTA_EMPLEADOS
                                         ,listaSectores,TAM_LISTA_SECTORES
                                        ,listaComidas,TAM_COMIDAS
                                        ,listaAlmuerzos,TAM_LISTA_ALMUERZOS
                                        ,&pNextID_Empleado,&pIdAlmuerzo);

                        seguir='s';
            break;

            case 2:

                        retorno= NEXO_pMenuBajas(listaEmpleados,TAM_LISTA_EMPLEADOS
                                               ,listaSectores,TAM_LISTA_SECTORES
                                               ,listaComidas,TAM_LISTA_COMIDAS
                                               ,listaAlmuerzos,TAM_LISTA_ALMUERZOS);

                        if(retorno==4)
                        {
                            seguir='n';
                        }
                        else
                        {
                            seguir='s';
                        }

                break;

               case 3:

                         retorno = NEXO_pMenuReingresos(listaEmpleados,TAM_LISTA_EMPLEADOS
                                                       ,listaSectores,TAM_LISTA_SECTORES
                                                       ,listaComidas,TAM_LISTA_COMIDAS
                                                       ,listaAlmuerzos,TAM_LISTA_ALMUERZOS);

                         if(retorno==4)
                         {
                             seguir='n';
                         }
                         else
                         {
                            seguir='s';
                         }

                break;

                case 4:

                            printf("\n     MODIFICAR EMPLEADO    \n");

                            NEXO_pMenuModificar(listaEmpleados,TAM_LISTA_EMPLEADOS
                                                ,listaSectores,TAM_LISTA_SECTORES
                                                ,listaComidas,TAM_LISTA_COMIDAS
                                                ,listaAlmuerzos,TAM_LISTA_ALMUERZOS);

                            seguir='s';
                break;

                case 5:

                            NEXO_pMenuMostrar(listaEmpleados,TAM_LISTA_EMPLEADOS
                                               ,listaSectores,TAM_LISTA_SECTORES
                                               ,listaComidas,TAM_LISTA_COMIDAS
                                               ,listaAlmuerzos,TAM_LISTA_ALMUERZOS);

                             seguir='s';

                break;

                case 6:

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n DESEA SALIR DEL PROGRAMA? \n"
                                                                                   "\n SI SALE DEL PROGRAMA LOS DATOS CARGADOS"
                                                                                   " NO QUEDARAN GUARDADOS "
                                                                                   "\n\n ELIJA UNA OPCION S/N: "
                                                                                   ,"\n HA OCURRIDO UN ERROR\n",2)
                               && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='n';
                            }
                            else
                            {
                                system("cls");
                                seguir='s';
                            }
                break;

                default:

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\nDESEA SALIR DEL PROGRAMA? \n"
                                                                                   "\n SI SALE DEL PROGRAMA LOS DATOS CARGADOS"
                                                                                   " NO QUEDA GUARDADOS "
                                                                                   "\n ELIJA UNA OPCION S/N: "
                                                                                   ,"\n HA OCURRIDO UN ERROR\n",2)

                        && salir == 'S' || salir == 's')

                        {

                                system("cls");
                                seguir='n';

                        }
                        else
                        {
                                system("cls");
                                seguir='s';
                        }
                break;

        }

    }while(seguir =='S'|| seguir == 's');

    return EXIT_SUCCESS;
}

