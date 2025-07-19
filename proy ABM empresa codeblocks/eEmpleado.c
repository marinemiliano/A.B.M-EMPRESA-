
#include <stdio.h>
#include <stdlib.h>

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

#include "data_Warehouse.h"
#include "eEmpleado.h"
#include "eSector.h"
#include "almuerzo.h"

#define   FULL 1
#define  EMPTY 0

#define   NO_FULL 0
#define  NO_EMPTY 0

#define  LA_POSICION_NUNCA_FUE_CARGADA 0

//NOS AVISA QUE LA POSICION ALGUNA VEZ SE CARGO
//ES UNA BANDERA QUE ES IMPORTANTE PARA DAR DE ALTA
//EMPLEADOS DADOS DE BAJA Y QUE SE RESPETEN SUS POSICIONES
//DENTRO DE LA LISTA
#define  LA_POSICION_ESTUVO_CARGADA 1

int EMPLEADO_pInicializaEstructuras_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras)
{
    int retorno;
    retorno= 0;

    for(int i =0; i < tamListaDeEstructuras ; i++)
    {
        EMPLEADO_pInicializaUnaEstructura_( (listaDeEstructuras + i) );
        retorno=1;
    }

    return retorno;
}

//INICIALIZA LAS POSICIONES DE TODOS ELEMENTOS DEL ARRAY
//LA INICIALIZACION DEBE ESTAR PORQUE PODEMOS TENER LISTAS PARA 100 EMPLEADOS
//Y QUE SOLO ESTEN CARGADOS 10, DEBEMOS INICIALIZAR LOS 90 RESTANTES TAMBIEN
//POR PROTECCION SI EN ESOS 90 TENEMOS BASURA JUSTO DA LA CASUALIDAD DE QUE
//ES UN 1 O UN 0


//el no empty se creo para dar de baja un empleado y que este
//aparezca en la lista filtrando los demas elementos que si no estuviese
//esa bandera se mostraria basura
int EMPLEADO_pInicializaUnaEstructura_(eEmpleado* pUnaEstructura)
{
    int retorno;
    retorno=0;

    if(pUnaEstructura != NULL)
    {
        pUnaEstructura->is_Empleado_Full=  NO_FULL;
        pUnaEstructura->is_Empleado_Empty= EMPTY;
        (*(pUnaEstructura)).is_PosicionLista = LA_POSICION_NUNCA_FUE_CARGADA;

        retorno=1;
    }

    return retorno;
}


int NEXO_pMenuAltas(eEmpleado* listaEmpleados,int tamListaEmpleados
                     ,eSector* listaSectores,int tamListaSectores
                     ,eComida* listaComidas,int tamListaComidas
                     ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                     ,int* pNextID_Empleado,int* pNextID_Almuerzo)
{

    int opcion;
    char seguir;
    char salir;
    int retorno;
    retorno=0;
    int aux_Empleado_ID;
    int aux_Almuerzo_ID;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0
            && pNextID_Empleado != NULL)
    {

        do
        {
            utn_pMenuOpciones_(&opcion
                               ,"\n\n  MENU ALTAS   \n"
                                "\n 1.DAR DE ALTA UN EMPLEADO \n"
                                "\n 2.DAR DE ALTA ALMUERZO DE EMPLEADO\n"
                                "\n 3. SALIR \n"
                                "\n ELIJA UNA OPCION DEL 1 AL 2: "
                               ,"\n ERROR AL INGRESAR EL NUMERO \n",1,2,2);

            system("cls");

            switch(opcion)
            {
              case 1:

                    //IMPORTANTE!! SE NECESITA HACER ESTE PASAJE DE ASIGNACION CON AUXLIARES SINO NO
                    //SE PUEDEN PASAR ELEMENTOS VIA PUNTEROS DESDE UNA FUNCION HACIA OTRA
                    aux_Empleado_ID = *(pNextID_Empleado);
                    utn_mostrarMensaje("\n  ALTA EMPLEADO \n");

                    //la funcion es 1 entra al if 0 NO ENTRA Y sale por el else
                    // si es false (0) entonces doble negacion y sale por el else
                    system("cls");

                    if(!NEXO_pAltaEstructura_DeTam_DOS(listaEmpleados,tamListaEmpleados
                                                       ,listaSectores,tamListaSectores,&aux_Empleado_ID))
                    {

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU ALTAS? S/N: "
                                ,"\n HA OCURRIDO UN ERROR\n",2)
                                && salir == 'S' || salir == 's')

                        {
                            system("cls");
                            seguir='s';
                        }
                        else
                        {
                            system("cls");
                            seguir='n';
                        }
                    }
                    else
                    {

                         retorno=1;

                        *(pNextID_Empleado) = aux_Empleado_ID;

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                ,"\n DESEA VOLVER AL MENU ALTAS?  S/N: "
                                ,"\n HA OCURRIDO UN ERROR\n",2)
                                && salir == 'S' || salir == 's')

                        {
                            system("cls");
                            seguir='s';
                        }
                        else
                        {
                            system("cls");
                            seguir='n';
                        }

                    }
              break;

              case 2:

                         //IMPORTANTE!! SE NECESITA HACER ESTE PASAJE DE ASIGNACION CON AUXLIARES SINO NO
                        //SE PUEDEN PASAR ELEMENTOS VIA PUNTEROS DESDE UNA FUNCION HACIA OTRA

                        aux_Almuerzo_ID = *(pNextID_Almuerzo);
                        utn_mostrarMensaje("\n  ALTA ALMUERZO \n");

                        //la funcion es 1 entra al if 0 NO ENTRA Y sale por el else
                        // si es false (0) entonces doble negacion y sale por el else
                        system("cls");

                        if(!utn_pCargaAltaAlmuerzo(listaAlmuerzos,tamListaAlmuerzos
                                                  ,listaComidas,tamListaComidas
                                                  ,listaEmpleados,tamListaEmpleados
                                                  ,listaSectores,tamListaSectores
                                                  ,&aux_Almuerzo_ID))
                        {

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU ALTAS? S/N: "
                                ,"\n HA OCURRIDO UN ERROR\n",2)
                                && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                system("cls");
                                seguir='n';
                            }

                        }
                        else
                        {
                            retorno=1;

                            *(pNextID_Almuerzo) = aux_Almuerzo_ID;

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                ,"\n DESEA VOLVER AL MENU ALTAS?  S/N: "
                                ,"\n HA OCURRIDO UN ERROR\n",2)
                                && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                system("cls");
                                seguir='n';
                            }
                        }
              break;

              case 3:

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: ",
                                "HA OCURRIDO UN ERROR\n",2)
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
                        printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR DEL MENU ACTUAL? S/N: ",
                                "HA OCURRIDO UN ERROR\n",2)
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

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        retorno=-1;
    }

    return retorno;

}


int NEXO_pAltaEstructura_DeTam_DOS(eEmpleado* listaEmpleados,int tamListaEmpleados
                                   ,eSector* listaSectores,int tamListaSectores,int* pID)
{

    eEmpleado auxEmpleado;
    int retorno;
    retorno=0;
    int posicionLibre;
    int auxID;


    //MIENTRAS NO HAYA OCURRIDO ALGO QUE NO SEA ESTO,si no ocurrio nada invalido entro
    //y hago las cosas.
    //if(!(arrayEmpleados == NULL || tamEmpleados <= 0 || pId == NULL))

    if( listaEmpleados != NULL && tamListaEmpleados > 0 &&
            listaSectores != NULL && tamListaSectores && pID != NULL)
    {
        printf("\n\n    ALTA EMPLEADOS      \n");

        EMP_BuscaPosicionLibreEnLista_DeTam_(listaEmpleados,tamListaEmpleados,&posicionLibre);

        if(posicionLibre != -1) //o sea que va desde el 0 hasta el infinito y hay lugar en el array
        {
            auxID = *pID;
            printf("\n  LEGAJO A ASIGNARSE:  %d\n",auxID);

            auxEmpleado=NEXO_CargaDatosDeLaEstructura_(listaSectores,tamListaSectores,&retorno,&auxID);

            if(!retorno)
            {
                printf("\n  OCURRIO UN ERROR AL DAR DE ALTA EL EMPLEADO ");
                //retorno=-1;
            }
            else
            {
                system("cls");

                printf("\n      ALTA DE EMPLEADO EXITOSA    \n");

                (*(listaEmpleados + posicionLibre)) = auxEmpleado;

                //a lo que le voy a hacer ++ es justamente al resultado de hacer *pId
                //el resultado del parentesis es el valor en esa direccion de memoria.

                *pID = auxID;
                (*pID)++;

                //otra opcion
                //*pId= (*pId) + 1;

                retorno=1;

                //NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(auxEmpleado,listaSectores,tamListaSectores);
            }
        }
        else
        {
            printf("\n ERROR AL ASIGNAR EL ID NUMERO %d  "
                   "\n\n NO SE ENCONTRO ESPACIO PARA CARGAR EMPLEADO NUEVO \n",*(pID));
        }

    }

    return retorno;

}


eEmpleado NEXO_CargaDatosDeLaEstructura_(eSector* listaSectores,int tamListaSectores,int* pRetorno,int* pID)
{

    eEmpleado auxEmpleado;
    int auxRetorno;
    auxRetorno=0;
    int edadLimite;
    edadLimite = 120;


    if(listaSectores != NULL && tamListaSectores > 0 && pID != NULL && pRetorno != NULL)
    {

        if( utn_pIngresoDeLaCadena_DeTam_(auxEmpleado.nombre, sizeof(auxEmpleado.nombre), "\n  NOMBRE DEL EMPLEADO A INGRESAR: ", "ERROR EL INGRESAR NOMBRE \n", 2) &&

                utn_pIngresoDeLaCadena_DeTam_(auxEmpleado.apellido, sizeof(auxEmpleado.apellido), "\n APELLIDO DEL EMPLEADO A INGRESAR: ", "ERROR AL INGRESAR APELLIDO \n", 2) &&

                utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Nacimiento_Empleado.dia, "\n DIA DE NACIMIENTO: ", "\n ERROR AL INGRESAR DIA DE NACIMIENTO \n", 0, 31, 2) &&

                utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Nacimiento_Empleado.mes, "\n MES DE NACIMIENTO: ", "\n ERROR AL INGRESAR MES DE NACIMIENTO \n",0, 12, 2) &&

                utn_pIngresoDeAnioTipoEntero_(&auxEmpleado.fecha_Nacimiento_Empleado.anio,"  DE NACIMIENTO ","\n ERROR AL INGRESAR ANIO DEL NACIMIENTO \n",1900,2024, 2) &&

                utn_pIngresoDeAnioTipoEntero_(&auxEmpleado.edad," EDAD DEL EMPLEADO ","\n ERROR AL INGRESAR LA EDAD DEL EMPLEADO \n",18,100, 2) &&

                utn_pIngresoDeSexoF_M_oNoBinario_DeTam_(&auxEmpleado.sexo, sizeof(auxEmpleado.sexo), "\n SEXO DEL EMPLEADO A INGRESAR: MASCULINO (M), FEMENINO (F), NO BINARIO (NB): "
                        , "ERROR AL INGRESAR EL SEXO DEL EMPLEADO \n", 2) &&

                utn_pIngresoDeElementoTipoFlotante_(&auxEmpleado.sueldo, "\n SUELDO DEL EMPLEADO A INGRESAR: ", "\n ERROR AL INGRESAR EL SUELDO DEL EMPLEADO \n", 0, 500000, 2) &&

                utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Ingreso_Empleado.dia, "\n DIA DE INGRESO DEL EMPLEADO A LA EMPRESA: ", "\n ERROR AL INGRESAR DIA DE INGRESO A LA EMPRESA \n", 0, 31, 2) &&

                utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Ingreso_Empleado.mes, " MES DE INGRESO DEL EMPLEADO A LA EMPRESA: ", "\n ERROR AL INGRESAR MES DE INGRESO A LA EMPRESA \n",0, 12, 2) &&

                utn_pIngresoDeAnioTipoEntero_(&auxEmpleado.fecha_Ingreso_Empleado.anio," DE INGRESO ENTRE : 1990 / 2025 ","\n ERROR AL INGRESAR ANIO DE INGRESO A LA EMPRESA \n",1990, 2025, 2) &&

                funcion_MostrarSectores(listaSectores,tamListaSectores) &&

                utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.ID_Sector, "\n INGRESE SECTOR AL CUAL PERTENECE EL EMPLEADO: ", "\n ERROR AL INGRESAR UN NUMERO DE SECTOR \n", 500, 504, 2))

        {
            auxEmpleado.is_Empleado_Full=FULL;
            auxEmpleado.is_Empleado_Empty=NO_EMPTY;
            auxEmpleado.is_PosicionLista=LA_POSICION_ESTUVO_CARGADA;
            auxEmpleado.legajo= *pID;
            auxRetorno = 1;
            *pRetorno=auxRetorno;
        }
        else
        {
            *pRetorno = auxRetorno;

        }
    }
    return auxEmpleado;

    //printf("ingrese fecha dd/mm/aaaa: n")

    //OTRA FORMA DE GENERAR UNA FECHA

    //printf("ingrese fecha dd/mm/aaaa: n");
    //scanf("%d/%d/%d",&auxEmpleado->fecha_Ingreso_Empleado.dia,&(auxEmpleado)->fecha_Ingreso_Empleado.mes,&auxEmpleado.fecha_Ingreso_Empleado.anio);

}


int NEXO_pMenuMostrar(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* listaSectores,int tamListaSectores
                       ,eComida* listaComidas,int tamListaComidas,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int opcion;
    char seguir;
    char salir;
    int retorno;
    retorno=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {

            utn_pMenuOpciones_(&opcion
                              ,"\n\n  MENU MOSTRAR    \n"
                               "\n INGRESE UNA OPCION: \n"
                               " 1.MOSTRAR EMPLEADOS DADOS DE ALTA\n"
                               " 2.MOSTRAR EMPLEADOS DADOS DE BAJA\n"
                               " 3.MOSTRAR SECTORES \n"
                               " 4.MOSTRAR COMIDAS \n"
                               " 5.MOSTRAR ALMUERZOS \n"
                               " 6.SALIR \n"
                               "\n ELIJA UNA OPCION DEL 1 AL 5: "
                               ,"\n ERROR AL INGRESAR EL NUMERO \n",1,6,2);

            system("cls");

            switch(opcion)
            {
                case 1:

                    utn_mostrarMensaje("\n  MOSTRAR EMPLEADOS \n");

                    //la funcion es 1 entra al if, 0 NO ENTRA Y sale por el else
                    // si es false (0) entonces doble negacion y sale por el else

                    system("cls");

                    if(!NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores))
                    {

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SEGUIR EN EL MENU MOSTRAR? S/N: "
                                ,"\n HA OCURRIDO UN ERROR\n",2)
                                && salir == 'S' || salir == 's')

                        {

                            system("cls");
                            seguir='s';

                        }
                        else
                        {
                            system("cls");
                            seguir='n';
                        }

                    }
                    else
                    {
                        retorno=1;

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                    }

                break;

                case 2:

                         system("cls");

                         utn_mostrarMensaje("\n  MOSTRAR SECTORES \n");

                         if(!NEXO_pMuestraEmpleados_DadosDeBaja_DOS(listaEmpleados,tamListaEmpleados
                                                                    ,listaSectores,tamListaSectores))
                          {

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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

                          }
                          else
                          {

                             retorno=1;

                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                          }


                break;

                case 3:

                         system("cls");

                         utn_mostrarMensaje("\n  MOSTRAR SECTORES \n");

                         if(!funcion_MostrarSectores(listaSectores,tamListaSectores))
                         {

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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

                          }
                          else
                          {

                             retorno=1;

                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                          }

            break;

            case 4:

                    utn_mostrarMensaje("\n  MOSTRAR COMIDAS \n");

                    //la funcion es 1 entra al if 0 NO ENTRA Y sale por el else
                    // si es false (0) entonces doble negacion y sale por el else.

                    if(!COMIDA_pMuestraListaDeComidas_DeTam_(listaComidas,TAM_COMIDAS))
                    {

                          if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                     }
                     else
                     {
                        retorno=1;

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                      }
            break;

            case 5:

                    utn_mostrarMensaje("\n  MOSTRAR ALMUERZOS \n");

                    if(!NEXO_MuestraListaDeAlmuerzos_DeTam_(listaAlmuerzos,tamListaAlmuerzos
                                                           ,listaSectores,tamListaSectores
                                                           ,listaEmpleados,tamListaEmpleados
                                                           ,listaComidas,tamListaComidas))
                    {

                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                    }
                    else
                    {
                        retorno=1;

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                    }
            break;

            case 6:

                    if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR VOLVER AL MENU PRINCIPAL? S/N: ",
                            "HA OCURRIDO UN ERROR\n",2)
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

                    printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                    if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR DEL MENU ACTUAL? S/N: ",
                            "HA OCURRIDO UN ERROR\n",2)
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

        }
        while(seguir =='S'|| seguir == 's');

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        retorno=0;
    }

    return retorno;

}



int NEXO_pMuestraEstructuras_DeTam_DOS(eEmpleado* listaEmpleados,int tamListaEmpleados
                                       ,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    int i;
    retorno= 0;
    int flag;
    flag=1;
    int contadorEmpleadosSinInicializar;
    contadorEmpleadosSinInicializar=0;

    int contadorEmpleadosDadosDeBaja;
    contadorEmpleadosDadosDeBaja=0;


    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0)
    {
        for(i=0; i < tamListaEmpleados; i++)
        {
            //O SEA QUE SI LA POSICION ES IGUAL A 0 ENTRA Y SUMA POSICIONES LIBRES Y VACIAS
            //SI EL CONTADOR DE DE ELEMENTOS ES IGUAL A EL TAM DE EMPLEADOS
            //QUIERE DECIR QUE NO HAY EMPLEADOS CARGADOS. TODA LA LISTA ESTA LIBRE
            if( (listaEmpleados + i)->is_PosicionLista != LA_POSICION_ESTUVO_CARGADA)
            {
                contadorEmpleadosSinInicializar++;

            }
        }

        if(contadorEmpleadosSinInicializar == tamListaEmpleados)
        {
            printf(" NUNCA SE CARGARON EMPLEADOS, LA LISTA ESTA VACIA \n");
            flag=0;
            retorno=0;
        }

        for(i=0; i < tamListaEmpleados; i++)
        {
            //O SEA QUE SI LA POSICION ES IGUAL A 0 EL EMPLEADO
            //FUE DADO DE BAJA, RESTA SABER SI ESE ESPACIO NUNCA FUE INICIALIZADO
            if( !(listaEmpleados + i)->is_Empleado_Full)
            {
                contadorEmpleadosDadosDeBaja++;
            }
        }

        //esto significa que nunca entro al if que cambio a 0 el flag SI NO se
        //cambio a flag 0 es porque la lista nunca estuvo vacia
        if(contadorEmpleadosDadosDeBaja == tamListaEmpleados && flag)
        {

            printf("\n ATENCION: NO EXISTEN EMPLEADOS EN LA LISTA, TODOS FUERON DADOS DE BAJA. \n");

        }
        else
        {
            printf("\n                                                          LISTA DE EMPLEADOS                                                           \n\n");

            puts("--------------------------------------------------------------------------------------------------------------------------------------------");
            printf( "LEGAJO   | NOMBRE    | APELLIDO    | SEXO    |   FECHA DE NACIMIENTO   |    EDAD  |   SUELDO    | FECHA DE INGRESO  | ID SECTOR     | SECTOR ");
            puts("\n-------------------------------------------------------------------------------------------------------------------------------------------");

            for (i = 0; i < tamListaEmpleados ; i++)
            {

                //SI ES FULL 1 Y NO ESTA VACIO ENTRA   !(0) ES DOBLE NEGATIVO INGRESA
                if( (listaEmpleados + i)->is_Empleado_Full &&
                    !(listaEmpleados + i)->is_Empleado_Empty &&
                    (listaEmpleados + i)->is_PosicionLista)
                {

                    NEXO_MuestraUnaEstructura_DOS((listaEmpleados + i),listaSectores,tamListaSectores);
                    puts("---------------------------------------------------------------------------------------------------------------------------------------|");
                    flag=1;
                    retorno=1;
                }
            }

        }

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR INESPERADO \n");
    }


    return retorno;
}


int NEXO_MuestraUnaEstructura_DOS(eEmpleado* unEmpleado,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    eSector auxSector;

    auxSector = SECTOR_pRetorna_ElSectorDelEmpleado_(listaSectores,tamListaSectores,&retorno,&(unEmpleado)->ID_Sector);

    if(retorno)
    {

        printf("\n %2d    %10s     %10s   %10s  %02d/%02d/%02d       %5d       %.2f         %02d/%02d/%02d         %5d             %s  \n"
               ,unEmpleado->legajo
               ,unEmpleado->nombre
               ,(*(unEmpleado)).apellido
               ,unEmpleado->sexo
               ,(*(unEmpleado)).fecha_Nacimiento_Empleado.dia
               ,(*unEmpleado).fecha_Nacimiento_Empleado.mes
               ,(*unEmpleado).fecha_Nacimiento_Empleado.anio
               ,(*unEmpleado).edad
               ,(*unEmpleado).sueldo
               ,unEmpleado->fecha_Ingreso_Empleado.dia
               ,(*(unEmpleado)).fecha_Ingreso_Empleado.mes
               ,unEmpleado->fecha_Ingreso_Empleado.anio
               ,auxSector.ID_Sector
               ,auxSector.descripcion);

    }
    else
    {

        printf("HUBO UN PROBLEMA CON LA DESCRIPCION DEL SECTOR \n");

    }

    return retorno;
}



//MUESTRA SOLO UNA ESTRUCTURA TIENE ENCABEZADO PROPIO

int NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(eEmpleado* unEmpleado,eSector* listaSectores,int tamListaSectores)
{

    int retorno;
    eSector auxSector;

     printf("\n\n                                                                  EMPLEADO ELEGIDO                                                              \n\n");

    puts("------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("    LEGAJO  |   NOMBRE    |   APELLIDO  |    FECHA DE NACIMIENTO   |    EDAD   |    SEXO   |   SUELDO   |   FECHA DE INGRESO  |   ID SECTOR   |    SECTOR   ");
    puts("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");


    auxSector = SECTOR_pRetorna_ElSectorDelEmpleado_(listaSectores,tamListaSectores,&retorno,&(unEmpleado)->ID_Sector);

    if(retorno)
    {
        printf("\n    %d         %s      %s          %02d/%02d/%02d         %d      %s         %.2f            %02d/%02d/%02d    %10d  %10s \n\n\n"
           ,unEmpleado->legajo,
           unEmpleado->nombre,
           unEmpleado->apellido,
           (*(unEmpleado)).fecha_Nacimiento_Empleado.dia,
           unEmpleado->fecha_Nacimiento_Empleado.mes,
           unEmpleado->fecha_Nacimiento_Empleado.anio,
           (*(unEmpleado)).edad,
           (*(unEmpleado)).sexo,
           (*unEmpleado).sueldo,
           unEmpleado->fecha_Ingreso_Empleado.dia,
           unEmpleado->fecha_Ingreso_Empleado.mes,
           unEmpleado->fecha_Ingreso_Empleado.anio,
           auxSector.ID_Sector,
           auxSector.descripcion);
    }
    else
    {
        printf(" \n OCURRIO UN ERROR AL MOSTRAR EL EMPLEADO \n");
    }

    return retorno;
}


int NEXO_pMuestraEmpleados_DadosDeBaja_DOS(eEmpleado* listaEmpleados,int tamListaEmpleados
                                           ,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    int i;
    retorno= 0;
    int flag;
    flag=-1;
    int contadorEstructurasVacias;
    contadorEstructurasVacias=0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0)
    {

        for(i=0; i < tamListaEmpleados; i++)
        {
            if(EMPLEADO_pEstaEmpleado_DadoDeBaja_(listaEmpleados + i) )
            {
                contadorEstructurasVacias++;
                break;
            }
        }

        if(contadorEstructurasVacias == 0)
        {
            //printf("\n\n NO HAY EMPLEADOS DADOS DE BAJA \n\n");
        }
        else
        {
            printf("\n                                                 LISTA DE EMPLEADOS DADOS DE BAJA                                                                         \n");

            puts("------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n ID EMPLEADO  | NOMBRE    | APELLIDO      | SEXO      |   FECHA DE NACIMIENTO   |     EDAD  |   SUELDO   |  FECHA DE INGRESO  |   ID SECTOR   | SECTOR \n");
            puts("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");

            for (i = 0; i < tamListaEmpleados ; i++)
            {
                //SI NO ESTA FULL (0), SI ESTA EMPTY 0
                //Y SI ALGUNA VEZ ESTUVO CARGADO (1) ESO
                //SIGNIFICA QUE EL EMPLEADO ESTA DADO DE BAJA
                if( EMPLEADO_pEstaEmpleado_DadoDeBaja_(listaEmpleados + i) )
                {
                    NEXO_MuestraUnaEstructura_DOS((listaEmpleados + i),listaSectores,tamListaSectores);
                    puts("---------------------------------------------------------------------------------------------------------------------------------------|");
                    flag=1;
                    retorno=1;
                }
            }

            if(!flag)
            {
                utn_mostrarMensaje("\n  ERROR AL MOSTRAR EMPLEADOS ELIMINADOS \n");
            }
        }

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR INESPERADO AL MOSTRAR EMPLEADOS ELIMINADOS \n");
    }

    return retorno;
}


int NEXO_pMuestraEmpleados_DadosDeDeBaja_EnUnSector(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector)
{
    int retorno;
    retorno=0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && unSector != NULL)
    {

        if(EMPLEADO_pHayEmpleados_DeLaLista_DadosDeBaja_EnElSector_(listaEmpleados,tamListaEmpleados,unSector))
        {

            printf("\n\n                                                              %s \n\n\n",unSector->descripcion                                                                        );

            puts("------------------------------------------------------------------------------------------------------------------------------------------------------------");
            puts("    LEGAJO  |   NOMBRE    |   APELLIDO  |    FECHA DE NACIMIENTO   |    EDAD   |    SEXO   |   SUELDO   |   FECHA DE INGRESO  |   ID SECTOR   |    SECTOR   ");
            puts("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");


            for(int i = 0; i < tamListaEmpleados; i++)
            {
                if(EMPLEADO_pEstaEmpleado_DadoDeBaja_Y_PerteneceAlSector_(listaEmpleados + i
                                                                            ,&(unSector)->ID_Sector))
                {

                   NEXO_pMuestraUnEmpleado_DelSector_(listaEmpleados + i,unSector);
                   retorno=1;

                }

            }

        }
        //else
        //{
          //printf("\n ATENCION: NO EXISTEN EMPLEADOS DADOS DE BAJA EN EL SECTOR \n");
        //}
     }
     else
      {
          printf("\n OCURRIO UN ERROR AL INGRESAR A LA FUNCION \n");
      }



    return retorno;

}


int EMPLEADO_pHayEmpleados_DeLaLista_DadosDeBaja_EnElSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector)
{

    int retorno;
    retorno=0;

     if( listaEmpleados != NULL && tamListaEmpleados > 0 && unSector != NULL)
    {
         for(int i = 0; i < tamListaEmpleados; i++)
        {

            if(EMPLEADO_pEstaEmpleado_DadoDeBaja_Y_PerteneceAlSector_(listaEmpleados+i,&(unSector)->ID_Sector))
            {
                retorno=1;
                break;
            }
        }
    }

    return retorno;
}



int EMPLEADO_pEstaEmpleado_DadoDeBaja_Y_PerteneceAlSector_(eEmpleado* unEmpleado,int* pAuxIdSector)
{

    int auxIdSector;
    auxIdSector=*pAuxIdSector;

    if(unEmpleado != NULL && pAuxIdSector != NULL)
    {

        return(EMPLEADO_pEstaEmpleado_DadoDeBaja_(unEmpleado) &&

                            GENERICA_pEsElNumero_IgualQueElNumero_(&(unEmpleado)->ID_Sector,&auxIdSector));

    }
}


int NEXO_pRetornaUnAlmuerzo_DeLaListaAlmuerzos_SiEsDelEmpleado_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                                    ,eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;
    eAlmuerzo auxAlmuerzo;
    int auxIdEmpleado;
    auxIdEmpleado=*pAuxIdEmpleado;

    if(NEXO_pRetornaUnAlmuerzo_SiEsDelEmpleado_(listaAlmuerzos,tamListaAlmuerzos
                                                ,&auxAlmuerzo,&auxIdEmpleado))
    {
        *unAlmuerzo=auxAlmuerzo;
        retorno=1;
    }

    return retorno;
}


int NEXO_pRetornaUnAlmuerzo_SiEsDelEmpleado_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                               ,eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;

    int auxIdEmpleado;
    auxIdEmpleado=*pAuxIdEmpleado;

      //printf("\n ID EMPLEADO \n", un);

    if(listaAlmuerzos != NULL && tamListaAlmuerzos > 0 && pAuxIdEmpleado != NULL)
    {

        for(int i= 0; i < tamListaAlmuerzos; i++ )
        {

            if( EMPLEADO_pEstaEmpleado_EnElAlmuerzo_(listaAlmuerzos + i,&auxIdEmpleado ) )
            {

                *unAlmuerzo=*(listaAlmuerzos + i);
                 retorno =1;

            }

        }
        if(!retorno)
        {
            printf("\n NO SE PUDO DAR DE BAJA EL ALMUERZO \n");
        }
        else
        {
            printf("\n ALMUERZO DADO DE BAJA EXITOSAMENTE \n");
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR A LA FUNCION BAJA UN ALMUERZO \n");
    }

    return retorno;
}


int EMPLEADO_pEstaEmpleado_EnElAlmuerzo_(eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado)
{
    int auxIdEmpleado;
    auxIdEmpleado=*pAuxIdEmpleado;

    if(unAlmuerzo != NULL && pAuxIdEmpleado != NULL)
    {

        GENERICA_pEsElNumero_IgualQueElNumero_(&(unAlmuerzo)->leg_Empleado,auxIdEmpleado);

    }
}






int EMPLEADO_pBajaTodosEmpleados_DelSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* pAuxIdSector)
{
    int retorno;
    retorno=0;
    int auxIdSector;
    auxIdSector=*pAuxIdSector;

     if(listaEmpleados != NULL && tamListaEmpleados > 0 && pAuxIdSector != NULL)
     {
         for(int i=0; i < tamListaEmpleados;i++)
         {

             if(EMPLEADO_pBajaUnEmpleado_DelSector_(listaEmpleados + i,&auxIdSector) )
             {
                 *pAuxIdSector=auxIdSector;
                 retorno = 1;
             }
         }
     }
     else
     {
             puts("\n OCURRIO UN ERROR AL INGRESAR A DAR DE BAJA TODOS LOS EMPLEADOS DEL SECTOR \n");
     }

    return retorno;
}


int EMPLEADO_pBajaUnEmpleado_DelSector_(eEmpleado* unEmpleado, int* pAuxIdSector)
{
    int retorno;
    retorno=0;
    int auxIdSector;
    auxIdSector=*pAuxIdSector;


     if(unEmpleado != NULL && pAuxIdSector != NULL)
     {
        if( EMPLEADO_pEstaEmpleado_DadoDeAlta_Y_PerteneceAlSector_(unEmpleado,&auxIdSector))

        {
            //LO DOY DE BAJA AL EMPLEADO DE ESE SECTOR
                                                                          //auxUnEmpleado
             EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(unEmpleado);
             retorno=1;
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO SE HA PODIDO DAR DE BAJA EL EMPLEADO \n");
        }
        else
        {
            printf("\n EMPLEADO DADO DE BAJA CON EXITO \n");
        }

     }
     else
     {
             puts("\n OCURRIO UN ERROR AL INGRESAR A DAR DE BAJA TODOS LOS EMPLEADOS DEL SECTOR \n");
     }

    return retorno;
}


int NEXO_pBajaUnEmpleado_Y_SusAlmuerzosDeLaLista_(eEmpleado* unEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                  ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{

    int retorno;
    retorno=0;

    if(unEmpleado != NULL && listaAlmuerzos != NULL && tamListaAlmuerzos > 0 &&  unEmpleado != NULL )
    {
        /// SI BAJA EL EMPLEADO Y BAJAR TODOS LOS ALMUERZOS DEL EMPLEADO DA OK: ENTONCES DEVUELVE 1
        ///PUDO DAR DE BAJA TODO. BAJA EL EMPLEADO LO HACE YA EN LA FUNCION BAJA EMPLEADO
        ///DEVUELVE 1 Y LUEGO SI NO TIENE ALMUERZOS EL EMPLEADO DEVUELVE 0 LA FUNCION
        ///PERO LO IMPORTANTE ES QUE EL EMPLEADO LO DA DE BAJA SI TIENE QUE HACERLO INDEPENDIENTEMENTE DE QUE SI
        ///TENGA ALMUERZOS O NO EL EMPLEADO

        if(EMPLEADO_pBajaUnEmpleado_DeLaLista_(unEmpleado,listaEmpleados,tamListaEmpleados)

                                &&

                            ALMUERZO_pBajaTodosAlmuerzos_DeEmpleado_(listaAlmuerzos,tamListaAlmuerzos,unEmpleado))
        {
            retorno=1;
        }
        else
        {
            if(EMPLEADO_pBajaUnEmpleado_DeLaLista_(unEmpleado,listaEmpleados,tamListaEmpleados)

                                &&

                            !ALMUERZO_pBajaTodosAlmuerzos_DeEmpleado_(listaAlmuerzos,tamListaAlmuerzos,unEmpleado))
            {
                retorno=2;
            }
        }

    }

    return retorno;
}


int EMPLEADO_pBajaUnEmpleado_DeLaLista_(eEmpleado* unEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados)
{
    int auxIdEmpleado;

    for(int i=0; i < tamListaEmpleados;i++)
    {
        if(GENERICA_pEsElNumero_IgualQueElNumero_( &(listaEmpleados+i)->legajo, &(unEmpleado)->legajo ))
        {
            EMPLEADO_pBajaUnEmpleado_(listaEmpleados + i);
        }
    }
}


int EMPLEADO_pBajaUnEmpleado_(eEmpleado* unEmpleado)
{
//

    if( unEmpleado != NULL )
    {

        printf("\n\n EMPLEADO %s %s ID %d HA SIDO DADO DE BAJA  \n",unEmpleado->nombre,unEmpleado->apellido,unEmpleado->legajo);
            //ESTO FUNCIONA BIEN ASI NO ENTIENDO POR QUE, LE DEBERIA DE PASAR ASI: "&unEmpleado"
            //YA QUE ESTA FUNCION ESPERA RECIBIR UN PARAMETRO POR REFERENCIA "eEmpleado *unEmpleado
        return(EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(unEmpleado));

    }

}


int EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(eEmpleado* unEmpleado)
{
    int retorno;
    retorno=0;

    if(unEmpleado != NULL)
    {
        ///NO PUEDO MANDAR TODO ESTO AL RETURN PORQUE ME SALTA ERROR
        (unEmpleado)->is_Empleado_Full  = NO_FULL;
        (unEmpleado)->is_Empleado_Empty = EMPTY;
        (unEmpleado)->is_PosicionLista = LA_POSICION_ESTUVO_CARGADA;

         retorno = 1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL DAR DE BAJA EL EMPLEADO  \n");
    }


    return retorno;
}


int NEXO_pIngreso_A_BajaTodosEmpleados_Y_Almuerzos_DeUnSector_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                              ,eSector* listaSectores,int tamListaSectores
                                                              ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    eSector auxSector;
    int retornoMenu;
    int auxIdSector;
    char salir;
    char seguir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
       && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {
         do
         {
            system("cls");

             if(!EMPLEADO_pHayEmpleadosDadosDe_Alta(listaEmpleados,tamListaEmpleados))
             {

                    retornoMenu=2;

                    seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

             }
             else
             {
                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DAR DE BAJA TODOS LOS EMPLEADOS DE UN SECTOR. \n"
                                                            "\n\n SE ELIMINARAN TAMBIEN TODOS LOS ALMUERZOS DE SUS EMPLEADOS. \n"
                                                            "\n DAR DE BAJA TODOS LOS EMPLEADOS? S/N: "
                                                            ,"\n HA OCURRIDO UN ERROR\n",2)

                    &&

                    salir == 'S' || salir == 's')
                {

                    /// ME TRAIGO EL ID DEL SECTOR Y LUEGO EN BASE A ESE ID ME TRAIGO TODA LA ESTRUCTURA
                    ///ESTO VA EN UNA FUNCION SOLA QUE NUCLEA A LAS DOS FUNCIONES
                    ///NO PUEDO COLOCAR LA FUNCION QUE ME RETORNA TODA LA ESTRUCTURA PORQUE ROMPE
                    ///DEBO COLOCAR ESA FUNCION MAS ABAJO
                    retornoMenu = NEXO_pCargaIdSectorEn_DeLaLista_(&auxIdSector
                                                                   ,listaEmpleados,tamListaEmpleados
                                                                   ,listaSectores,tamListaSectores);

                    if(retornoMenu != 1)
                    {

                         system("cls");

                         ///NO PUEDO COLOCAR UN INGRESO DE UN VALOR Y LUEGO CON EL && USARLO EN OTRA FUNCION
                         /// "esta el empleado de alta.. PORQUE ROMPE"
                         printf("%d PRIMER RETORNO \n",retornoMenu);

                         seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

                    }
                    else
                    {

                         system("cls");

                         ///LO VOLVEMOS A COLOCAR EN CERO PARA USARLO NUEVAMENTE
                         retornoMenu = 0;

                         SECTOR_pInicializaUnSector(&auxSector);

                         ///NECESITO PASARLE EL ID EMPLEADO QUE OBTUVE EN LA BUSQUEDA DEL LEGAJO A LA VARIABLE
                         /// DE LA ESTRUCTURA auxLegajo.Legajo PORQUE si bien nosotros le pasamos la estructura
                         /// LA FUNCION EMPLEADO_pRetorna  luego necesitara el ID del legajo para el funcionamiento
                         ///de la funcion
                         auxSector.ID_Sector = auxIdSector;

                         if(SECTOR_pRetorna_UNO_SiElSector_EstaDadoDeAlta_EnLista_CERO_SINO(&auxSector,listaSectores
                                                                                            ,tamListaSectores))
                         {

                            auxSector = SECTOR_pRetornaElSector_ConElId_(listaSectores,tamListaSectores
                                                                        ,&retornoMenu,&auxIdSector);

                            if(!retornoMenu)
                            {

                                retornoMenu=5;

                                seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

                            }
                            else
                            {
                                if(EMPLEADO_pHayEmpleados_DeLaLista_DadosDeAlta_EnElSector_(listaEmpleados,tamListaEmpleados,&auxSector))
                                {

                                      NEXO_pMuestraEmpleados_DadosDeDeAlta_EnUnSector(listaEmpleados,tamListaEmpleados,&auxSector);

                                      if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_
                                                        (&salir,"\n DESEA DAR DE BAJA TODOS LOS EMPLEADOS DEL SECTOR? \n"
                                                                "\n SE ELIMINARAN TAMBIEN TODOS LOS ALMUERZOS DE SUS EMPLEADOS.\n"
                                                                "\n DAR DE BAJA EMPLEADOS DEL SECTOR: S/N: "
                                                                ,"\n HA OCURRIDO UN ERROR\n",2)

                                            &&

                                            salir == 'S' || salir == 's')
                                    {


                                        retornoMenu = NEXO_pBajaTodosLosEmpleados_DeUnSector_Y_SusAlmuerzos_(listaAlmuerzos
                                                                                                            ,tamListaAlmuerzos,
                                                                                                            listaEmpleados
                                                                                                            ,tamListaEmpleados
                                                                                                            ,&auxSector);

                                        if(retornoMenu==0)
                                        {

                                            retornoMenu=7;

                                            seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

                                        }
                                        else
                                        {
                                                if(retornoMenu == 2)
                                                {

                                                   retornoMenu=8;

                                                   seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);
                                                }
                                                else
                                                {
                                                    seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

                                                }
                                        }

                                    }
                                    else
                                    {

                                            system("cls");

                                            retornoMenu=9;

                                            seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

                                     }

                                }
                                else
                                {
                                    retornoMenu=6;

                                    seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);
                                }

                            }

                        }
                        else
                        {

                            retornoMenu=4;

                            seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);

                        }

                  }

              }
              else
              {
                    system("cls");

                    retornoMenu=9;

                    seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);
              }

           }

        }while(seguir == 'S' || seguir == 's');

      }
      else
      {

            system("cls");

            retornoMenu=0;

            seguir = menu_RetornoMenuPrincipal(3,2,&retornoMenu);
      }

      return retornoMenu;

}

int NEXO_pCargaIdSectorEn_DeLaLista_(int* pAuxIdSector,eEmpleado* listaEmpleados,int tamListaEmpleados
                                    ,eSector* listaSectores,int tamListaSectores)
{

    int retorno;
    retorno=0;
    int auxIdSector;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && pAuxIdSector != NULL)
    {
            //system("cls");

            //SECTOR_pMuestraListaSectores_DeTam_UNO(listaSectores,tamListaSectores);

            retorno = utn_pIngresoDeElementoTipoEntero_(&auxIdSector,"\n INGRESE SECTOR PARA DE BAJA A TODOS SUS EMPLEADOS \n"
                                                        "\n NUMERO A ELEGIR 500 - 504: ","\n ERROR, REINGRESE ID DEL SECTOR: "
                                                        ,MIN_LISTA_SECTORES,MAX_LISTA_SECTORES, REINTENTOS);

            if(retorno != 1)
            {
                 retorno=0;

            }
            else
            {
                *pAuxIdSector=auxIdSector;
                 retorno=1;

            }
    }
    else
    {
        puts("\n OCURRIO UN ERROR AL INGRESAR A BAJA UN EMPLEADO \n");
    }

    return retorno;
}


int NEXO_pMuestraEmpleados_DadosDeAlta_PorSectores(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                    ,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    retorno=0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0)
    {
             if(SECTOR_pHaySectoresDadosDe_Alta(listaSectores,tamListaSectores))
            {
                for(int i = 0; i < tamListaSectores; i++)
                {

                    if(NEXO_pSiElSector_EstaDadoDeAlta_MuestraLosEmpleados(listaEmpleados,tamListaEmpleados,listaSectores +i))
                    {
                        retorno=1;
                    }

                }
            }
            else
            {
                printf("\n ATENCION: NO SE ENCUENTRAN SECTORES DADOS DE ALTA \n");
            }
    }
    else
    {
        printf("\n ATENCION: NO SE PUDO INGRESAR A MOSTRAR EMPLEADOS POR SECTOR \n");
    }

    return retorno;
}


int NEXO_pSiElSector_EstaDadoDeAlta_MuestraLosEmpleados(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector)
{

    return(SECTOR_pEstaSector_DadoDeAlta_(unSector) &&
                                    NEXO_pMuestraEmpleados_DadosDeDeAlta_EnUnSector(listaEmpleados,tamListaEmpleados
                                                                                    ,unSector));
}


int NEXO_pMuestraEmpleados_DadosDeDeAlta_EnUnSector(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector)
{
    int retorno;
    retorno=0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && unSector != NULL)
    {
        ///SI HAY EMPLEADOS DADOS DE ALTA EN EL SECTOR ENTRA A RECORRER SINO SALE
        /// E IMPRIME QUE EN ESE SECTOR NO HAY EMPLEADOS PARA MOSTRAR
         if(EMPLEADO_pHayEmpleados_DeLaLista_DadosDeAlta_EnElSector_(listaEmpleados,tamListaEmpleados,unSector))
         {



            printf("\n\n                                                              %s \n\n\n",unSector->descripcion                                                                        );

            puts("------------------------------------------------------------------------------------------------------------------------------------------------------------");
            puts("    LEGAJO  |   NOMBRE    |   APELLIDO  |    FECHA DE NACIMIENTO   |    EDAD   |    SEXO   |   SUELDO   |   FECHA DE INGRESO  |   ID SECTOR   |    SECTOR   ");
            puts("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");



            for(int i = 0; i < tamListaEmpleados; i++)
            {
                if(EMPLEADO_pEstaEmpleado_DadoDeAlta_Y_PerteneceAlSector_(listaEmpleados + i
                                                                            ,&(unSector)->ID_Sector))
                {

                   NEXO_pMuestraUnEmpleado_DelSector_(listaEmpleados + i,unSector);
                   retorno=1;

                }

            }

            /// SI HUBIERA COLOCADO LA FUNCION hayEMpleadosdadosDeAlta? tendria QUE HABER HECHO ESTO:

            ///EN ESTA PARTE DEL PROGRAMA,TENDRIA QUE COLOCAR QUE SI EL RETORNO ES 0 ENTONCES NINGUN
            ///EMPLEADO DE LA LISTA PERTENECE AL SECTOR DETERMINADO, O SEA NUNCA ENTRA AL IF

            ///TAMBIEN QUEDARIA VACIO EL PRINT "SECTOR" QUEDA RARO.


          }
          //else
          //{
            //  printf("\n ATENCION: NO HAY EMPLEADOS DADOS DE ALTO PARA MOSTRAR EN EL SECTOR:%s ",unSector->descripcion);
          //}

     }
     else
      {
          printf("\n OCURRIO UN ERROR AL INGRESAR A LA FUNCION \n");
      }



    return retorno;

}



void NEXO_pMuestraUnEmpleado_DelSector_(eEmpleado* unEmpleado,eSector* unSector)
{

     printf("\n\n                                                                  EMPLEADO ELEGIDO                                                              \n\n");

    puts("------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("    LEGAJO  |   NOMBRE    |   APELLIDO  |    FECHA DE NACIMIENTO   |    EDAD   |    SEXO   |   SUELDO   |   FECHA DE INGRESO  |   ID SECTOR   |    SECTOR   ");
    puts("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");

        printf("\n    %d         %s      %s          %02d/%02d/%02d         %d      %s         %.2f            %02d/%02d/%02d    %10d  %10s \n\n\n"
           ,unEmpleado->legajo,
           unEmpleado->nombre,
           unEmpleado->apellido,
           (*(unEmpleado)).fecha_Nacimiento_Empleado.dia,
           unEmpleado->fecha_Nacimiento_Empleado.mes,
           unEmpleado->fecha_Nacimiento_Empleado.anio,
           (*(unEmpleado)).edad,
           (*(unEmpleado)).sexo,
           (*unEmpleado).sueldo,
           unEmpleado->fecha_Ingreso_Empleado.dia,
           unEmpleado->fecha_Ingreso_Empleado.mes,
           unEmpleado->fecha_Ingreso_Empleado.anio,
           unSector->ID_Sector,
           unSector->descripcion);

}


int NEXO_pBajaTodosLosEmpleados_DeUnSector_Y_SusAlmuerzos_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                            ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                            ,eSector* unSector)
{
    int retorno;
    retorno=0;
    int contadorRetorno1;
    contadorRetorno1=0;

    int auxIdSector;
    auxIdSector = unSector->ID_Sector;


    if(listaAlmuerzos != NULL && tamListaAlmuerzos > 0 && listaEmpleados != NULL && tamListaEmpleados > 0 && unSector != NULL)
    {
        ///SI HAY EMPLEADOS EN EL SECTOR ENTRA SINO NO TIENE SENTIDO ENTRAR A ITERAR SI NO EXISTEN EMPLEADOS
        ///EN EL SECTOR NO TIENE SENTIDO

        printf("\n\n\n ELIMINACION DE TODOS LOS EMPLEADOS DEL SECTOR %s Y SUS ALMUERZOS. \n\n",unSector->descripcion);

        for(int i = 0; i < tamListaEmpleados; i++)
        {

                ///SI EL EMPLEADO PERTENECE A ESE SECTOR LO DA DE BAJA UNA VEZ QUE LO DA DE BAJA
                ///ESE EMPLEADO SE MUEVE HACIA LA LISTA DE ALMUERZOS PARA CHEQUEAR SI TIENE ALMUERZOS
                ///CARGADOS PARA DARLOS DE BAJA TAMBIEN. SE RETORNA LA ESTRUCTURA ALMUERZO DEL EMPLEADO
                ///PARA DARLO DE BAJA SI SE CUMPLEN ESAS CONDICIONES.
            //if( (listaEmpleados + i)->ID_Sector == auxIdSector)
            if(EMPLEADO_pEstaEmpleado_DadoDeAlta_Y_PerteneceAlSector_(listaEmpleados + i,&(unSector)->ID_Sector))
            {

                if(EMPLEADO_pBajaUnEmpleado_DeLaLista_(listaEmpleados + i,listaEmpleados,tamListaEmpleados)

                                &&

                            ALMUERZO_pBajaTodosAlmuerzos_DeEmpleado_(listaAlmuerzos,tamListaAlmuerzos,listaEmpleados + i))
                {
                    contadorRetorno1++;
                }
                else
                {
                    if(EMPLEADO_pBajaUnEmpleado_DeLaLista_(listaEmpleados + i,listaEmpleados,tamListaEmpleados)

                                        &&

                                    !ALMUERZO_pBajaTodosAlmuerzos_DeEmpleado_(listaAlmuerzos,tamListaAlmuerzos,listaEmpleados + i))
                    {

                        retorno=2;
                    }
                }

            }

        }

            //ESTA SOLUCION SE DEBE A QUE PASA SI TENGO 3 EMPLEADOS EN EL SECTOR
            // 1 ALMORZO
            // 2 ALMORZO
            // 3 Y EL ULTIMO NO ALMORZO ENTONCES ME VA A DEVOLVER 2 Y VA A SALIR CON EL RETORNO
            //NO SE DIO DE BAJA NINGUN ALMUERZO DE NINGUN EMPLEADO POR QUE NO HABIA LO CUAL ES ERRONEO
            //si el contador retorno 1 es mayor o igual a 1 entonces quiere decir que al menos
            //hay un empleado con almuerzos que se pudo dar de baja
            if(contadorRetorno1 >= 1 )
            {
                    retorno=1;
            }
            else
            {
                        retorno=2;
            }

            /*
             if(NEXO_bajaEmpleado_SiPerteneceAlSector_(listaEmpleados + i,unSector)
                                            &&  NEXO_bajaAlmuerzoDelEmpleado_(listaEmpleados + i,listaAlmuerzos
                                                                              ,tamListaAlmuerzos)

            {
                Retorno=1
            }
            else
            {
                     if(NEXO_bajaEmpleado_SiPerteneceAlSector_(listaEmpleados + i,unSector)
                                            && !NEXO_bajaAlmuerzoDelEmpleado_(listaEmpleados + i,listaAlmuerzos
                                                                              ,tamListaAlmuerzos)

                    {
                        Retorno=2
                    }

            }

        }
        */

    }
    else
    {
        puts("\n OCURRIO UN ERROR AL INGRESAR \n");
    }


    return retorno;

}


int EMPLEADO_pHayEmpleados_DeLaLista_DadosDeAlta_EnElSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* unSector)
{

    int retorno;
    retorno=0;

     if( listaEmpleados != NULL && tamListaEmpleados > 0 && unSector != NULL)
    {
         for(int i = 0; i < tamListaEmpleados; i++)
        {

            if(EMPLEADO_pEstaEmpleado_DadoDeAlta_Y_PerteneceAlSector_(listaEmpleados+i,&(unSector)->ID_Sector))
            {
                retorno=1;
                break;
            }
        }
    }

    return retorno;
}


int EMPLEADO_pEstaEmpleado_DadoDeAlta_Y_PerteneceAlSector_(eEmpleado* unEmpleado,int* pAuxIdSector)
{

    int auxIdSector;
    auxIdSector=*pAuxIdSector;

    if(unEmpleado != NULL && pAuxIdSector != NULL)
    {

        return(EMPLEADO_pEstaEmpleado_DadoDeAlta_(unEmpleado) &&

                            GENERICA_pEsElNumero_IgualQueElNumero_(&(unEmpleado)->ID_Sector,&auxIdSector));

    }
}

//DEBO HACER LA VERSION DE EMPLEADOS DADOS DE ALTA PARA BUSQUEDAS
//EN CUANTO ENCUENTRA UN EMPLEADO DADO DE ALTA ME CERCIORO DE QUE
//HAY AUNQUE SEA UN EMPLEADO DADO DE ALTA PARA PODER DAR DE BAJA
//POR EJEMPLO
int EMPLEADO_pEstaEmpleado_DadoDeAlta_(eEmpleado* unEmpleado)
{

    int retorno;
    retorno=0;

    if(unEmpleado != NULL)
    {
        if((unEmpleado)->is_Empleado_Full && !(unEmpleado)->is_Empleado_Empty && (unEmpleado)->is_PosicionLista)
        {
            retorno=1;
        }

    }

    return retorno;
}


///

int NEXO_pIngreso_A_BajaTodosEmpleadosDeLaLista_Y_SusAlmuerzos_(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores
                                                                ,listaAlmuerzos,tamListaAlmuerzos)
{
     char salir;
     char seguir;
     int retornoMenu;
     retornoMenu=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0)
    {
        system("cls");

        if(!EMPLEADO_pHayEmpleadosDadosDe_Alta(listaEmpleados,tamListaEmpleados))
        {

            retornoMenu=3;

            seguir = menu_RetornoMenuPrincipal(3,3,&retornoMenu);

        }
        else
        {

            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA TODOS LOS EMPLEADOS DE LA EMPRESA?.\n"
                                                            "\n SE ELIMINARAN TAMBIEN TODOS LOS ALMUERZOS. \n"
                                                            "\n DAR DE BAJA TODOS LOS EMPLEADOS S/N: "
                                                            ,"\n HA OCURRIDO UN ERROR\n",2)

                &&

                salir == 'S' || salir == 's')
            {

                   retornoMenu = EMPLEADO_pBajaTodosLosEmpleadosDeLaLista_Y_SusAlmuerzosDe_(listaEmpleados,tamListaEmpleados
                                                                                            ,listaAlmuerzos,tamListaAlmuerzos);

                   if(!retornoMenu)
                   {
                      retornoMenu=4;

                      seguir = menu_RetornoMenuPrincipal(3,3,&retornoMenu);
                   }
                   else
                   {
                      retornoMenu=1;

                      seguir = menu_RetornoMenuPrincipal(3,3,&retornoMenu);
                   }


           }
           else
           {

                system("cls");

                retornoMenu=2;

                seguir = menu_RetornoMenuPrincipal(3,3,&retornoMenu);

           }

        }
    }
    else
    {

        system("cls");

        retornoMenu=0;

        seguir = menu_RetornoMenuPrincipal(3,3,&retornoMenu);
    }

    return retornoMenu;
}


int EMPLEADO_pReingresaTodosEmpleadosDeLaLista_Y_SusAlmuerzosDe_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0)
    {
            for(int i=0; i < tamListaEmpleados; i++)
            {
                ///PODRIA PREGUNTAR ESTO PERO YO YA ASUMO QUE ESTA DADO DE ALTA LO PREGUNTE
                ///EN FUNCIONES ANTERIORES SINO ESTARIA PROGRAMANDO A LA DEFENSIVA
                //EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i)
                if(NEXO_pBajaUnEmpleado_Y_SusAlmuerzosDeLaLista_(listaEmpleados+i
                                                                 ,listaEmpleados,tamListaEmpleados
                                                                 ,listaAlmuerzos,tamListaAlmuerzos))
                {

                   retorno = 1;
                }
            }

            if(!retorno)
            {
                printf("\n ATENCION: NO SE PUDO DAR DE BAJA NINGUN EMPLEADO. \n"
                       "TODOS LOS EMPLEADOS DE LA EMPRESA ESTAN DADOS DE BAJA. \n");
            }
            //else
            //{
              //  printf("\n TODOS LOS EMPLEADOS FUERON DADOS DE BAJA CON EXITO \n");
            //}
    }
    else
    {
        puts("\n OCURRIO UN ERROR AL INGRESAR A DAR DE BAJA TODOS LOS EMPLEADOS \n");
    }

    return retorno;
}


int EMPLEADO_pBajaTodosLosEmpleadosDeLaLista_Y_SusAlmuerzosDe_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0)
    {
            for(int i=0; i < tamListaEmpleados; i++)
            {
                ///PODRIA PREGUNTAR ESTO PERO YO YA ASUMO QUE ESTA DADO DE ALTA LO PREGUNTE
                ///EN FUNCIONES ANTERIORES SINO ESTARIA PROGRAMANDO A LA DEFENSIVA
                //EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i)
                if(NEXO_pBajaUnEmpleado_Y_SusAlmuerzosDeLaLista_(listaEmpleados+i
                                                                 ,listaEmpleados,tamListaEmpleados
                                                                 ,listaAlmuerzos,tamListaAlmuerzos))
                {

                   retorno = 1;
                }
            }

            //if(!retorno)
            //{
              //  printf("\n ATENCION: NO SE PUDO DAR DE BAJA NINGUN EMPLEADO. \n"
                //       "TODOS LOS EMPLEADOS DE LA EMPRESA ESTAN DADOS DE BAJA. \n");
            //}
            //else
            //{
              //  printf("\n TODOS LOS EMPLEADOS FUERON DADOS DE BAJA CON EXITO \n");
            //}
    }
    else
    {
        puts("\n OCURRIO UN ERROR AL INGRESAR A DAR DE BAJA TODOS LOS EMPLEADOS \n");
    }

    return retorno;
}



///

int NEXO_pMenuReingresos(eEmpleado* listaEmpleados,int tamListaEmpleados
                        ,eSector* listaSectores,int tamListaSectores
                        ,eComida* listaComidas,int tamListaComidas
                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;
    char seguir;
    int opcion;
    char salir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {
                system("cls");
                utn_pMenuOpciones_(&opcion
                                   ,"\n\n  MENU REINGRESOS \n"
                                   "\n 1.REINGRESAR EMPLEADOS \n"
                                   " 2.SALIR \n"
                                   "\n ELEGIR UNA OPCION DEL 1 o 2: "
                                   ,"\n ERROR AL INGRESAR LA OPCION: ",1,2,2);

            switch(opcion)
            {

                case 1:
                        system("cls");
                        retorno = NEXO_pMenuReingreso_Empleados(listaEmpleados,tamListaEmpleados
                                                               ,listaSectores,tamListaSectores
                                                               ,listaComidas,tamListaComidas
                                                               ,listaAlmuerzos,tamListaAlmuerzos);

                        if(retorno == 2)
                        {

                            seguir='s';

                        }
                        else
                        {

                            seguir='n';
                        }

                break;

                case 2:

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                            printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                            ,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
                                                                            ,"HA OCURRIDO UN ERROR\n",2)
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


        }while(seguir == 's' || seguir == 'S');

    }
    else
    {
        printf("\n OCURRIO UN ERROR EN EL INGRESO AL MENU \n");
    }

    return retorno;
}


int NEXO_pMenuReingreso_Empleados(eEmpleado* listaEmpleados,int tamListaEmpleados
                                 ,eSector* listaSectores,int tamListaSectores
                                 ,eComida* listaComidas,int tamListaComidas
                                 ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;
    int opcion;
    char seguir;
    char salir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {
            system("cls");
            utn_pMenuOpciones_(&opcion
                               ,"\n\n  MENU REINGRESO DE EMPLEADOS  \n"
                               "\n 1.REINGRESAR UN EMPLEADO \n"
                               " 2.REINGRESAR EMPLEADOS DE UN SECTOR \n"
                               " 3.REINGRESAR EMPLEADOS DE TODOS LOS SECTORES \n"
                               " 4.SALIR \n"
                               "\n ELEGIR UNA OPCION DEL 1 AL 4: "
                               ,"\n ERROR AL INGRESAR LA OPCION: ",1,4,2);

            switch(opcion)
            {
                case 1:

                             retorno = NEXO_pIngreso_A_ReingresaEmpleado_Y_SusAlmuerzos_(listaEmpleados,tamListaEmpleados
                                                                                         ,listaSectores,tamListaSectores
                                                                                         ,listaAlmuerzos,tamListaAlmuerzos);

                             seguir = menuRetornoBajaEmpleados(&retorno);

                break;

                case 2:

                            retorno = NEXO_pIngreso_A_ReingresaTodosLosEmpleados_Y_SusAlmuerzos_DeUnSector
                                                                                            (listaEmpleados,tamListaEmpleados
                                                                                            ,listaAlmuerzos,tamListaAlmuerzos
                                                                                            ,listaSectores,tamListaSectores);

                            seguir = menuRetornoBajaEmpleados(&retorno);

                break;

                case 3:

                            retorno = NEXO_pIngreso_A_pReingresaTodosLosEmpleados_Y_SusAlmuerzosDe_TodosLosSectores(
                                                                                                    listaEmpleados,tamListaEmpleados
                                                                                                    ,listaSectores,tamListaSectores
                                                                                                    ,listaAlmuerzos,tamListaAlmuerzos);

                            seguir = menuRetornoBajaEmpleados(&retorno);

                break;

                case 4:

                            system("cls");

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                         ,"\n DESEA SALIR DEL MENU REINGRESAR EMPLEADO? S/N: "
                                                                         ,"HA OCURRIDO UN ERROR\n",2)
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

                            printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                            ,"\n DESEA SALIR DEL MENU REINGRESO DE EMPLEADOS? S/N: "
                                                                            ,"HA OCURRIDO UN ERROR\n",2)
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

        }while(seguir == 's' || seguir == 'S');

    }
    else
    {
        printf("\n OCURRIO UN ERROR EN EL INGRESO AL MENU \n");
    }

  return retorno;

}


int NEXO_pIngreso_A_ReingresaEmpleado_Y_SusAlmuerzos_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                      ,eSector* listaSectores,int tamListaSectores
                                                      ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    eEmpleado auxEmpleado;
    int retornoMenu;
    retornoMenu=0;
    int auxIdEmpleado;
    char seguir;
    char salir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
       && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
   {

      do
      {
           system("cls");

          //SI NO HAY NINGUN EMPLEADO DADO DE BAJA ENTONCES NO HAY NINGUNO
          //DADO DE ALTA ENTONCES NO SE PUEDE REINGRESAR NINGUNO
          if(!EMPLEADO_pHayEmpleadosDadosDe_Baja(listaEmpleados,tamListaEmpleados))
          {
              retornoMenu=2;

              seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

          }
          else
          {

             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n REINGRESAR EMPLEADO \n"
                                                             "\n SI REINGRESA EL EMPLEADO TAMBIEN SE REINGRESARAN SUS ALMUERZOS."
                                                             "\n\n REINGRESAR EMPLEADO? S/N: "
                                                             ,"\n HA OCURRIDO UN ERROR\n",2)

              && salir == 'S' || salir == 's')

             {
                 //system("cls");

                 retornoMenu = NEXO_pCargaIdEmpleado_AReingresar_(&auxIdEmpleado,listaEmpleados,tamListaEmpleados
                                                                 ,listaSectores,tamListaSectores);

                 if(retornoMenu != 1)
                 {

                     seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                 }
                 else
                 {

                     ///NECESITO PASARLE EL ID EMPLEADO QUE OBTUVE EN LA BUSQUEDA DEL LEGAJO A LA VARIABLE
                     /// DE LA ESTRUCTURA auxLegajo.Legajo PORQUE si bien nosotros le pasamos la estructura
                     /// LA FUNCION EMPLEADO_pRetorna  luego necesitara el ID del legajo para el funcionamiento
                     ///de la funcion
                     auxEmpleado.legajo = auxIdEmpleado;

                     auxEmpleado = EMP_pRetornaElEmpleado_ConElId_(listaEmpleados,tamListaEmpleados
                                                                   ,&retornoMenu,&auxIdEmpleado);

                    if(retornoMenu)
                    {

                         ///SI EL EMPLEADO NO ESTA DADO DE BAJA RETORNA 0 ENTONCES NEGADO (!) + 0
                         ///ENTRA AL IF Y AVISA QUE EL EMPLEADO ESTA DADO DE ALTA
                         if(!EMPLEADO_pEstaEmpleado_DadoDeBaja_(&auxEmpleado) )
                         {

                              retornoMenu=4;
                              seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                          }
                          else
                          {

                            if(NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores))
                            {

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA REINGRESAR EL EMPLEADO?\n"
                                                                        "\n SE REINGRESARAN TODOS SUS ALMUERZOS. \n"
                                                                        "\n\n ELIJA UNA OPCION S/N: "
                                                                        ,"\n HA OCURRIDO UN ERROR\n",2)

                                        && salir == 'S' || salir == 's')

                                {

                                    retornoMenu = NEXO_pReingresaEmpleado_Y_SusAlmuerzos(&auxIdEmpleado
                                                                                 ,listaEmpleados,tamListaEmpleados
                                                                                 ,listaAlmuerzos,tamListaAlmuerzos);

                                    if(retornoMenu==0)
                                    {

                                        retornoMenu=5;

                                        seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                                    }
                                    else
                                    {

                                        if(retornoMenu == 2)
                                        {

                                           retornoMenu=8;

                                           seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                                        }
                                        else
                                        {
                                            seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                                        }

                                    }

                                  }
                                  else
                                  {

                                        retornoMenu=9;

                                        seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);
                                  }

                             }
                             else
                             {

                                retornoMenu=6;

                                seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                             }

                        }

                    }
                    else
                    {
                        retornoMenu=5;

                        seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

                    }
                }

            }
            else
            {
                retornoMenu=9;

                seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

            }

          }

      }while(seguir == 's' || seguir == 'S');

    }
    else
    {
            system("cls");

            retornoMenu=0;

            seguir = menu_RetornoMenuPrincipal(4,1,&retornoMenu);

    }

    return retornoMenu;
}


int NEXO_pReingresaEmpleado_Y_SusAlmuerzos(eEmpleado* unEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados
                                           ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;

    if(unEmpleado != NULL && listaAlmuerzos != NULL && tamListaAlmuerzos > 0 &&  unEmpleado != NULL )
    {
        if(EMPLEADO_pReingresaEmpleado_DadoDeBaja_ConID_(listaEmpleados,tamListaEmpleados,&(unEmpleado)->legajo)

                && ALMUERZO_pReingresaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos,&(unEmpleado)->legajo))
        {

            retorno=1;

        }
        else
        {
            if(EMPLEADO_pReingresaEmpleado_DadoDeBaja_ConID_(listaEmpleados,tamListaEmpleados,&(unEmpleado)->legajo)
                                &&
                    !ALMUERZO_pReingresaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos,&(unEmpleado)->legajo))
            {
                retorno=2;
            }
        }

    }
    return retorno;
}


int  NEXO_pCargaIdEmpleado_AReingresar_(int* pAuxIdEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados
                                        ,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    retorno=0;
    int auxIdEmpleado;
    int seguir;
    char salir;

    //MIENTRAS NO HAYA OCURRIDO ALGO QUE NO SEA ESTO,si no ocurrio nada invalido entro
    //y hago las cosas.

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0)
    {
        do
        {
            system("cls");

            NEXO_pMuestraEmpleados_DadosDeBaja_DOS(listaEmpleados,tamListaEmpleados
                                                  ,listaSectores,tamListaSectores);

            retorno = utn_pIngresoDeElementoTipoEntero_(&auxIdEmpleado, "\n INGRESE EL ID DEL EMPLEADO A REINGRESAR: "
                                                        , "\n ERROR AL INGRESAR EL ID DEL EMPLEADO \n"
                                                        ,MIN_ID_EMPLEADO, MAX_ID_EMPLEADO, 2);

            if(!retorno)
            {

                retorno=3;
                seguir='n';

            }
            else
            {
                  system("cls");
                  /// ACA BUSCO EL INDICE EN EL CUAL ESTA EL EMPLEADO PARA PODER MOSTRARLO EN LA FUNCION QUE LE SIGUE
               //   EMPLEADO_pEstaElEmpleadoDadoDeAlta_EnListaEmpleados_(listaEmpleados,tamListaEmpleados
                 //                                                                 ,&auxIndiceEmpleado,&auxIdEmpleado)


                  *pAuxIdEmpleado=auxIdEmpleado;
                   retorno=1;
                   seguir='n';

            }



        }while(seguir == 's' ||seguir == 'S');

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
        retorno=0;
        seguir='n';

    }

    return retorno;
}


int EMPLEADO_pReingresaEmpleado_DadoDeBaja_ConID_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;
    int auxIdEmpleado;

    if( listaEmpleados!= NULL && tamListaEmpleados > 0 && pAuxIdEmpleado != NULL)
    {

        auxIdEmpleado = *pAuxIdEmpleado;

        for(int i =0 ; i < tamListaEmpleados ; i++)
        {
            if(GENERICA_pEsElNumero_IgualQueElNumero_(&(listaEmpleados + i)->legajo,&auxIdEmpleado))
            {

                EMPLEADO_pAltaEmpleado_CambiaLasBanderasAEmpleado_DadoDeAlta_(listaEmpleados + i);
                retorno = 1;
                break;

            }
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO SE HA REINGRESADO NINGUN EMPLEADO \n");
        }
        else
        {
            printf("\n EMPLEADO REINGRESADO EXITOSAMENTE \n");
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR EN EL INGRESO A LA OPCION \n");
    }

    return retorno;
}


int NEXO_pIngreso_A_ReingresaTodosLosEmpleados_Y_SusAlmuerzos_DeUnSector(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                                        ,eSector* listaSectores,int tamListaSectores)
{
    eSector auxSector;
    int retornoMenu;
    retornoMenu=0;
    int auxIdSector;
    char seguir;
    char salir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
       && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
   {

      do
      {
          system("cls");

          if(!EMPLEADO_pHayEmpleadosDadosDe_Baja(listaEmpleados,tamListaEmpleados))
          {

              retornoMenu=1;

              seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

          }
          else
          {

             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n DESEA REINGRESAR TODOS LOS EMPLEADOS DE UN SECTOR? \n"
                                                         "\n SI REINGRESA LOS EMPLEADOS TAMBIEN SE REINGRESARAN SUS ALMUERZOS."
                                                         "\n\n REINGRESAR EMPLEADO S/N: "
                                                         ,"\n HA OCURRIDO UN ERROR\n",2)

                && salir == 'S' || salir == 's')

              {

                 system("cls");

                 retornoMenu = NEXO_pCargaIdSectorEn_DeLaLista_(&auxIdSector,listaEmpleados,tamListaEmpleados

                                                                ,listaSectores,tamListaSectores);

                  system("cls");

                 if(!retornoMenu)
                 {
                     retornoMenu=3;

                     seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

                 }
                 else
                 {

                     system("cls");

                     SECTOR_pInicializaUnSector(&auxSector);

                     ///NECESITO PASARLE EL ID SECTOR QUE OBTUVE EN LA BUSQUEDA DEL LEGAJO A LA VARIABLE
                     /// DE LA ESTRUCTURA auxLegajo.Legajo PORQUE si bien nosotros le pasamos la estructura
                     /// LA FUNCION EMPLEADO_pRetorna  luego necesitara el ID del legajo para el funcionamiento
                     ///de la funcion
                     auxSector.ID_Sector = auxIdSector;

                     auxSector = SECTOR_pRetornaElSector_ConElId_(listaSectores,tamListaSectores
                                                                  ,&retornoMenu,&auxIdSector);

                     if(!EMPLEADO_pHayEmpleados_DeLaLista_DadosDeBaja_EnElSector_(listaEmpleados,tamListaEmpleados,&auxSector))
                     {

                              retornoMenu=5;

                              seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

                      }
                      else
                      {

                            if(NEXO_pMuestraEmpleados_DadosDeDeBaja_EnUnSector(listaEmpleados,tamListaEmpleados,&auxSector))
                            {

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_
                                                    (&salir,"\n DESEA REINGRESAR TODOS LOS EMPLEADOS AL SECTOR? \n"
                                                    "\n SE REINGRESARAN TAMBIEN TODOS LOS ALMUERZOS DE SUS EMPLEADOS.\n"
                                                    "\n REINGRESAR EMPLEADOS DEL SECTOR: S/N: "
                                                    ,"\n HA OCURRIDO UN ERROR\n",2)

                                        &&

                                        salir == 'S' || salir == 's')
                                {


                                    retornoMenu = NEXO_pReingresa_TodosEmpleados_Y_SusAlmuerzos_DelSector_(listaEmpleados,tamListaEmpleados
                                                                             ,listaAlmuerzos,tamListaAlmuerzos
                                                                             ,&auxIdSector);

                                    system("cls");
                                    if(!retornoMenu)
                                    {

                                        retornoMenu=7;

                                        seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

                                    }
                                    else
                                    {

                                        system("cls");

                                        retornoMenu=8;

                                        seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

                                    }
                                }
                                else
                                {
                                        system("cls");

                                        retornoMenu=9;

                                        seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

                                }

                            }
                            else
                            {
                                        retornoMenu=6;

                                        seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

                        }

                    }

                }

            }
            else
            {
                retornoMenu=2;

                seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);
            }

        }

      }while(seguir== 's' || seguir == 'S');

    }
    else
    {
            system("cls");

            retornoMenu=0;

            seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);
    }

    return retornoMenu;
}



int NEXO_pCargaIdSector_(int* pAuxIdSector,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    retorno=0;
    int auxIdSector;
    int seguir;
    char salir;

    //MIENTRAS NO HAYA OCURRIDO ALGO QUE NO SEA ESTO,si no ocurrio nada invalido entro
    //y hago las cosas.

    if( listaSectores != NULL && tamListaSectores > 0 && pAuxIdSector != NULL)
    {

            do
            {
            //o sea que va desde el 0 hasta el infinito y hay lugar en el array

                if(SECTOR_pHaySectoresDadosDe_Alta(listaSectores,tamListaSectores))
                {



                         if(utn_pIngresoDeElementoTipoEntero_(&auxIdSector
                                                              ,"\n\n\n INGRESE EL ID DEL SECTOR PARA REINGRESAR"
                                                               " A TODOS SUS EMPLEADOS: "
                                                              ,"\n ERROR, REINGRESE ID DEL SECTOR PARA REINGRESAR"
                                                               " A TODOS SUS EMPLEADOS: ",
                                                                MIN_LISTA_SECTORES,MAX_LISTA_SECTORES, REINTENTOS))
                        {

                           retorno=1;
                           *pAuxIdSector = auxIdSector;
                           seguir= 'n';

                        }
                        else
                        {
                            system("cls");
                            seguir= 'n';
                            retorno=0;
                            puts("\n OCURRIO UN ERROR AL INGRESAR EL ID DE SECTOR, NUMERO INGRESADO FUERA DE RANGO. \n");
                        }

                }
                else
                {

                    puts("\n OCURRIO UN ERROR, NO EXISTEN SECTORES CARGADOS \n");
                    seguir='n';
                }
            }
            while(seguir == 's' ||seguir == 'S');

        }
        else
        {
            printf("\n OCURRIO UN ERROR AL INGRESAR \n");
        }

    return retorno;
}


int NEXO_pReingresa_TodosEmpleados_Y_SusAlmuerzos_DelSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,
                                                             eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,
                                                              int* pAuxIdSector)
{
    int retorno;
    retorno = 0;

    int auxIdSector;

      if(listaEmpleados != NULL && tamListaEmpleados > 0 &&  pAuxIdSector != NULL && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
     {
            auxIdSector=*pAuxIdSector;

            if(EMPLEADO_pHayEmpleadosDadosDe_Baja(listaEmpleados,tamListaEmpleados))
            {
                for(int i = 0; i < tamListaEmpleados; i++)
                {
                   if(NEXO_pReingresa_Empleado_Y_SusAlmuerzos_SiEstaDadoDeAlta_Y_SiPerteneceAlSector_
                                                                                      (listaEmpleados + i,&auxIdSector
                                                                                      ,listaEmpleados,tamListaEmpleados
                                                                                      ,listaAlmuerzos,tamListaAlmuerzos))
                   {
                            retorno=1;
                   }
                }
            }
            else
            {
                printf("\n NO HAY EMPLEADOS DADOS DE BAJA PARA REINGRESAR \n");
            }

     }

    return retorno;
}


int NEXO_pReingresa_Empleado_Y_SusAlmuerzos_SiEstaDadoDeAlta_Y_SiPerteneceAlSector_(eEmpleado* unEmpleado,int* pAuxIdSector
                                                                                  ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                                  ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int auxIdSector;

    if(unEmpleado != NULL && listaEmpleados != NULL && tamListaEmpleados > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0
       && pAuxIdSector != NULL)
    {
            auxIdSector=*pAuxIdSector;

            return(EMPLEADO_pEstaEmpleado_DadoDeBaja_Y_PerteneceAlSector_(unEmpleado,&auxIdSector)

                                                                            &&

                                            NEXO_pReingresaEmpleado_Y_SusAlmuerzos(&(unEmpleado)->legajo
                                                                                   ,listaEmpleados,tamListaEmpleados
                                                                                    ,listaAlmuerzos,tamListaAlmuerzos));

    }

}


int NEXO_pIngreso_A_pReingresaTodosLosEmpleados_Y_SusAlmuerzosDe_TodosLosSectores(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                                 ,eSector* listaSectores,int tamListaSectores
                                                                                 ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
     char salir;
     char seguir;
     int retornoMenu;
     retornoMenu=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0)
    {
        system("cls");

        do
        {
            if(!EMPLEADO_pHayEmpleadosDadosDe_Baja(listaEmpleados,tamListaEmpleados))
            {

               retornoMenu=1;

               seguir = menu_RetornoMenuPrincipal(4,3,&retornoMenu);

            }
            else
            {

                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA REINGRESAR TODOS LOS EMPLEADOS DE LA EMPRESA? \n"
                                                                "\n SE REINGRESARAN TAMBIEN TODOS SUS ALMUERZOS. \n"
                                                                "\n REINGRESAR TODOS LOS EMPLEADOS S/N: "
                                                                ,"\n HA OCURRIDO UN ERROR\n",2)

                    &&

                    salir == 'S' || salir == 's')
               {

                   retornoMenu = EMPLEADO_pReingresaTodosLosEmpleados_Y_SusAlmuerzosDe_TodosLosSectores(listaEmpleados,tamListaEmpleados
                                                                                                        ,listaAlmuerzos,tamListaAlmuerzos);

                   if(!retornoMenu)
                   {
                       retornoMenu = 6;

                       seguir = menu_RetornoMenuPrincipal(4,3,&retornoMenu);

                   }
                   else
                   {

                       retornoMenu = 8;


                       seguir = menu_RetornoMenuPrincipal(4,3,&retornoMenu);

                   }
               }
               else
               {

                    system("cls");

                    retornoMenu = 2;

                    seguir = menu_RetornoMenuPrincipal(4,3,&retornoMenu);

               }

          }

        }while(seguir== 's' || seguir== 'S');

    }
    else
    {

        system("cls");

        retornoMenu=0;

        seguir = menu_RetornoMenuPrincipal(4,2,&retornoMenu);

    }

    return retornoMenu;
}


int EMPLEADO_pReingresaTodosLosEmpleados_Y_SusAlmuerzosDe_TodosLosSectores(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;

    if(EMPLEADO_pHayEmpleadosDadosDe_Baja(listaEmpleados,tamListaEmpleados))
    {
        if(listaEmpleados != NULL && tamListaEmpleados > 0)
        {
                for(int i=0; i < tamListaEmpleados; i++)
                {
                    if(EMPLEADO_pEstaEmpleado_DadoDeBaja_(listaEmpleados + i) )
                    {

                        NEXO_pReingresaEmpleado_Y_SusAlmuerzos(listaEmpleados + i,listaEmpleados,tamListaEmpleados
                                                               ,listaAlmuerzos,tamListaAlmuerzos);

                       retorno = 1;
                    }
                }

                if(!retorno)
                {
                    printf("\n ATENCION: NO SE PUDO REINGRESAR NINGUN EMPLEADO. \n");
                }
                //else
                //{
                    //printf("\n TODOS LOS EMPLEADOS DADOS DE BAJA DE LA EMPRESA FUERON REINGRESADOS CON EXITO \n");
                //}
        }
        //else
        //{
             //puts("\n ATENCION: NO EXISTEN EMPLEADOS DADOS DE BAJA \n");
        //}

    }
    else
    {

        printf("\n NO EXISTEN EMPLEADOS DADOS DE BAJA \n");

    }

    return retorno;
}




int EMPLEADO_pEstaEmpleado_DadoDeBaja_(eEmpleado* unEmpleado)
{

    int retorno;
    retorno=0;

    if(unEmpleado != NULL)
    {
        if( (unEmpleado)->is_Empleado_Full == NO_FULL
                                    && (unEmpleado)->is_Empleado_Empty == EMPTY &&
                                                    (unEmpleado)->is_PosicionLista == LA_POSICION_ESTUVO_CARGADA )
        {

                retorno = 1;
        }
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL VALIDAR EL ALTA DEL EMPLEADO  \n");
    }

    return retorno;
}





///











eSector SECTOR_pRetorna_ElSectorDelEmpleado_(eSector* listaSectores,int tamlistaSectores,int* pRetorno,int* pAuxIdSector)
{
	int retorno;
	retorno=0;
	eSector auxSector;

	int auxIdSector;
	auxIdSector = *pAuxIdSector;

	if( listaSectores != NULL && tamlistaSectores > 0 && pRetorno != NULL )
	{
		for(int i=0;i<tamlistaSectores;i++)
		{
			if(SECTOR_pEstaSector_DadoDeAlta_Y_EmpleadoPerteneceAlSector_(listaSectores + i,&auxIdSector))
			{
				auxSector = *(listaSectores + i);
				retorno=1;
				*pRetorno = retorno;
				break;
			}
		}
	}

	return auxSector;
}


int GENERICA_pEsElNumero_IgualQueElNumero_(int*unNumero,int* otroNumero)
{

    if(unNumero != NULL && otroNumero != NULL)
    {

        return (*unNumero == *otroNumero);
    }
}














int EMPLEADO_pBajaUnEmpleado_ConID_CambiaBandera_Inactivo(eEmpleado* unEmpleado,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;

    eEmpleado auxUnEmpleado;

    auxUnEmpleado = *unEmpleado;

    if( unEmpleado != NULL && pAuxIdEmpleado != NULL)
    {
        if(EMPLEADO_pEstaEmpleado_DadoDeAlta_(&auxUnEmpleado) && unEmpleado->legajo == *(pAuxIdEmpleado) )
        {

            //ESTO FUNCIONA BIEN ASI NO ENTIENDO POR QUE, LE DEBERIA DE PASAR ASI: "&unEmpleado"
            //YA QUE ESTA FUNCION ESPERA RECIBIR UN PARAMETRO POR REFERENCIA "eEmpleado *unEmpleado
            EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(unEmpleado);
            retorno = 1;
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO SE HA DADO DE BAJA EL EMPLEADO \n");
        }
        else
        {
            printf("\n EMPLEADO DADO DE BAJA EXITOSAMENTE \n");
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR EN EL INGRESO DE LA FUNCION CAMBIAR BANDERA DEL EMPLEADO A BAJA \n");
    }

    return retorno;
}


int EMPLEADO_pAltaEmpleado_CambiaLasBanderasAEmpleado_DadoDeAlta_(eEmpleado* unEmpleado)
{

    int retorno;
    retorno=0;

    if(unEmpleado != NULL)
    {
        (unEmpleado)->is_Empleado_Full  = FULL;
        (unEmpleado)->is_Empleado_Empty = NO_EMPTY;
        (unEmpleado)->is_PosicionLista = LA_POSICION_ESTUVO_CARGADA;

         retorno = 1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL DAR DE ALTA EL EMPLEADO  \n");
    }


    return retorno;
}


int EMPLEADO_pHayEmpleadosDadosDe_Alta(eEmpleado* listaEmpleados,int tamListaEmpleados)
{
   int retorno;
   retorno=0;

    if(listaEmpleados != NULL & tamListaEmpleados > 0)
    {

        for(int i = 0; i < tamListaEmpleados; i++)
        {
            if(EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i))
            {

                retorno=1;
                break;

            }
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO EXISTEN EMPLEADOS CARGADOS EN LA LISTA \n");
        }
        //7else
        //{
          //  printf("\n EXISTEN EMPLEADOS CARGADOS EN LA LISTA \n");
        //}
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;

}


//DEBO HACER LA VERSION DE EMPLEADOS DADOS DE BAJA PARA BUSQUEDAS
//EN CUANTO ENCUENTRA UN EMPLEADO DADO DE BAJA ME CERCIORO DE QUE
//HAY AUNQUE SEA UN EMPLEADO DADO DE BAJA PARA PODER REINGRESAR
//POR EJEMPLO
int EMPLEADO_pHayEmpleadosDadosDe_Baja(eEmpleado* listaEmpleados,int tamListaEmpleados)
{
   int retorno;
   retorno=0;

    if(listaEmpleados != NULL & tamListaEmpleados > 0)
    {

        for(int i = 0; i < tamListaEmpleados; i++)
        {
            if(EMPLEADO_pEstaEmpleado_DadoDeBaja_(listaEmpleados + i))
            {

                retorno=1;
                break;

            }
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO EXISTEN EMPLEADOS DADOS DE BAJA \n");
        }
       // else
        //{
         //   printf("\n EXISTEN EMPLEADOS DADOS DE BAJA \n");
        //}


    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;

}


//BUSCA UNA POSICION LIBRE QUE HAYA EN LA LISTA Y DEVUELVE ESE INDICE POR REFERENCIA
int EMP_BuscaPosicionLibreEnLista_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,int* pIndice)
{
    int i;
    int retorno;
    int auxIndice;
    auxIndice=-1;
    retorno=0;

    if( listaDeEstructuras!= NULL && tamListaDeEstructuras > 0)
    {
        for(i=0; i<tamListaDeEstructuras; i++)
        {
            //if(arrayEmpleados[i].isEmpty) ya al colocar asi sabemos que es LIBRE

            //SI NO ESTA CARGADO !FULL (0) Y ESTA VACIO (1) SIGNIFICA QUE LA POSICION NUNCA FUE UTILIZADA

            if( !(*(listaDeEstructuras + i)).is_PosicionLista )
            {
                retorno = 1;
                auxIndice = i;
                *pIndice= auxIndice;
                break;
            }
        }

        *pIndice=auxIndice;
    }
    return retorno;
}


///BAAAAAAAAAJASSSSSSSSSSSSSSSSSSSSS

int NEXO_pMenuBajas(eEmpleado* listaEmpleados,int tamListaEmpleados,eSector* listaSectores,int tamListaSectores
                     ,eComida* listaComidas,int tamListaComidas,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int opcion;
    char seguir;
    char salir;
    int retorno;
    retorno=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {
                system("cls");
                utn_pMenuOpciones_(&opcion
                                  ,"\n\n  MENU BAJAS   \n"
                                  "\n 1.BAJA EMPLEADOS DE LA EMPRESA \n"
                                  " 2.SALIR \n"
                                  "\n ELIJA UNA OPCION 1 o 2: "
                                  ,"\n ERROR AL INGRESAR EL NUMERO \n",1,2,2);

            switch(opcion)
            {
                case 1:

                        system("cls");
                        retorno = NEXO_pMenuBajaEmpleados(listaEmpleados,tamListaEmpleados
                                                         ,listaSectores,tamListaSectores
                                                         ,listaAlmuerzos,tamListaAlmuerzos);

                        if(retorno == 2)
                        {
                            seguir='s';

                        }
                        else
                        {
                            seguir='n';
                        }

                break;

                case 2:

                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                             ,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: ",
                                                                             "HA OCURRIDO UN ERROR\n",2)
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

                            printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                            ,"\n DESEA VOLVER AL MENU BAJA EMPLEADOS "
                                                                            " ,SECTORES, COMIDAS Y ALMUERZOS? S/N: "
                                                                            ,"HA OCURRIDO UN ERROR\n",2)
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

        }
        while(seguir =='S'|| seguir == 's');

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        retorno=-1;
    }

    return retorno;

}


int NEXO_pMenuBajaEmpleados(eEmpleado* listaEmpleados,int tamListaEmpleados
                            ,eSector* listaSectores,int tamListaSectores
                            ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    retorno=0;
    char seguir;
    int opcion;
    char salir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {
            utn_pMenuOpciones_(&opcion
                               ,"\n\n  MENU BAJA EMPLEADOS \n"
                               "\n 1.DAR DE BAJA UN EMPLEADO \n"
                               " 2.DAR DE BAJA TODOS LOS EMPLEADOS DE UN SECTOR \n"
                               " 3.DAR DE BAJA TODOS LOS EMPLEADOS DE LA EMPRESA \n"
                               " 4.SALIR \n"
                               "\n ELEGIR UNA OPCION DEL 1 AL 4: "
                               ,"\n ERROR AL INGRESAR LA OPCION: ",1,4,2);

            switch(opcion)
            {

                case 1:

                            retorno = NEXO_pIngreso_A_BajaEmpleado_Y_Sus_Almuerzos(listaEmpleados,tamListaEmpleados
                                                                                ,listaSectores,tamListaSectores
                                                                                ,listaAlmuerzos,tamListaAlmuerzos);

                            seguir = menuRetornoBajaEmpleados(&retorno);

                break;

                case 2:
                             system("cls");

                             retorno = NEXO_pIngreso_A_BajaTodosEmpleados_Y_Almuerzos_DeUnSector_(listaEmpleados,tamListaEmpleados
                                                                                             ,listaSectores,tamListaSectores
                                                                                             ,listaAlmuerzos,tamListaAlmuerzos);

                             seguir = menuRetornoBajaEmpleados(&retorno);
                break;

                case 3:

                        system("cls");

                        retorno = NEXO_pIngreso_A_BajaTodosEmpleadosDeLaLista_Y_SusAlmuerzos_(listaEmpleados,tamListaEmpleados
                                                                                              ,listaSectores,tamListaSectores
                                                                                              ,listaAlmuerzos,tamListaAlmuerzos);
                        seguir = menuRetornoBajaEmpleados(&retorno);

                break;

                case 4:

                        system("cls");

                         if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                         ,"\n DESEA SALIR DEL MENU BAJA EMPLEADO? S/N: "
                                                                         ,"HA OCURRIDO UN ERROR\n",2)
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

                        system("cls");

                        printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                        ,"\n DESEA SALIR DEL MENU BAJA EMPLEADO? S/N: "
                                                                        ,"HA OCURRIDO UN ERROR\n",2)
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


        }while(seguir == 's' || seguir == 'S');

    }
    else
    {
        printf("\n OCURRIO UN ERROR EN EL INGRESO AL MENU \n");
    }

    return retorno;
}


char menuRetornoBajaEmpleados(int* pAuxRetorno)
{
    char seguir;
    int auxRetorno;
    auxRetorno=*pAuxRetorno;

    switch(auxRetorno)
    {
        case 0:

        break;

        case 1:
                    seguir='n';
                    *pAuxRetorno=0;
        break;

        case 2:

                    *pAuxRetorno=2;
                    seguir='n';
        break;

        case 3:

                    seguir='s';
                    *pAuxRetorno=3;

        break;


        case 4:
                    seguir='n';
                    *pAuxRetorno=4;
        break;

        default:

        break;
    }

    return seguir;
}


int NEXO_pIngreso_A_BajaEmpleado_Y_Sus_Almuerzos(listaEmpleados,tamListaEmpleados
                                                 ,listaSectores,tamListaSectores
                                                 ,listaAlmuerzos,tamListaAlmuerzos)
{
    eEmpleado auxEmpleado;
    int auxIdEmpleado;
    int retornoMenu;
    retornoMenu = 0;
    int auxPosicion;
    char salir;
    char seguir;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {
             system("cls");

             //SI NO HAY AUNQUE SEA UN EMPLEADO DADO DE ALTA ENTONCES NO PUEDO DAR
             //DE BAJA NINGUNO ENTONCES NI SIQUIERA ENTRA
             if(!EMPLEADO_pHayEmpleadosDadosDe_Alta(listaEmpleados,tamListaEmpleados))
             {
                retornoMenu=2;

                seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

             }
             else
             {

                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DAR DE BAJA UN EMPLEADO  \n"
                                                                    "\n SE ELIMINARAN TAMBIEN TODOS LOS ALMUERZOS DEL EMPLEADO QUE ELIJA. \n"
                                                                    "\n\n ELIJA UNA OPCION S/N: "
                                                                    ,"\n HA OCURRIDO UN ERROR\n",2)
                    && salir == 'S' || salir == 's')
                {

                   system("cls");

                   ///NO PUEDO COLOCAR UN INGRESO DE UN VALOR Y LUEGO CON EL && USARLO EN OTRA FUNCION
                   /// "esta el empleado de alta.. PORQUE ROMPE"

                 retornoMenu = NEXO_pCargaIdEmpleadoEn_DeLaLista_(&auxIdEmpleado,listaEmpleados,tamListaEmpleados
                                                                    ,listaSectores,tamListaSectores);

                 if(retornoMenu != 1)
                 {

                     seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

                 }
                 else
                 {
                     system("cls");

                     ///LO VOLVEMOS A COLOCAR EN CERO PARA USARLO NUEVAMENTE
                     retornoMenu = 0;

                     EMPLEADO_pInicializaUnaEstructura_(&auxEmpleado);

                     auxEmpleado = EMP_pRetornaElEmpleado_ConElId_(listaEmpleados,tamListaEmpleados
                                                                  ,&retornoMenu,&auxIdEmpleado);


                        if(retornoMenu != 1)
                        {
                            retornoMenu=5;

                            seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);
                        }
                        else
                        {

                         ///SI EL EMPLEADO NO ESTA DADO DE ALTA RETORNA 0 ENTONCES NEGADO (!) + 0
                         ///ENTRA AL IF Y AVISA QUE EL EMPLEADO ESTA DADO DE BAJA

                         ///NO SE PUEDE DAR DE BAJA UN EMPLEADO QUE YA ESTA DADO DE BAJA
                         if(!EMPLEADO_pEstaEmpleado_DadoDeAlta_(&auxEmpleado))
                         {
                             retornoMenu=4;

                             ///LE PASO LOS ITEMS DEL MENU A DONDE VA A PARAR DENTRO DE LOS
                             ///SWITCH DE LOS OTROS MENUS
                             seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

                         }
                         else
                         {

                                if(NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores))
                                {

                                     if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA EL EMPLEADO?  \n"
                                                    "\n SE ELIMINARAN TAMBIEN TODOS SUS ALMUERZOS. \n"
                                                    "\n\n ELIJA UNA OPCION S/N: "
                                                    ,"\n HA OCURRIDO UN ERROR\n",2)

                                        && salir == 'S' || salir == 's')
                                    {

                                        system("cls");
                                        retornoMenu = NEXO_pBajaUnEmpleado_Y_SusAlmuerzosDeLaLista_(&auxEmpleado,listaEmpleados
                                                                                                    ,tamListaEmpleados
                                                                                                    ,listaAlmuerzos
                                                                                                    ,tamListaAlmuerzos);

                                        if(retornoMenu==0)
                                        {

                                            retornoMenu=7;

                                            seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

                                        }
                                        else
                                        {
                                                if(retornoMenu == 2)
                                                {

                                                   retornoMenu=8;

                                                   seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);
                                                }
                                                else
                                                {
                                                    seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

                                                }
                                        }

                                    }
                                    else
                                    {

                                        retornoMenu=9;

                                        seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

                                    }

                                }
                                else
                                {
                                    retornoMenu=6;

                                    seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);

                                }

                             }

                          }

                        }

                    }
                    else
                    {
                        retornoMenu=9;

                        seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);
                    }

                 }

        }while(seguir == 'S' || seguir == 's');

    }
    else
    {
            retornoMenu=0;

            seguir = menu_RetornoMenuPrincipal(3,1,&retornoMenu);
    }

    return retornoMenu;
}


char menu_RetornoMenuPrincipal(int switchMenuPrincipal
                               ,int switchSegundoMenuElementos,int* pAuxRetornoMenuTercerNivel)
{
    char seguir;
    int auxRetorno;
    auxRetorno = *pAuxRetornoMenuTercerNivel;

    switch(switchMenuPrincipal)
    {

        case 3:

                 seguir = menu_RetornoMenuBajaEmpleados(switchSegundoMenuElementos,&auxRetorno);

                 *pAuxRetornoMenuTercerNivel = auxRetorno;

        break;

        case 4:

                  seguir = menu_RetornoMenuReingresosEmpleado(switchSegundoMenuElementos,&auxRetorno);

                 *pAuxRetornoMenuTercerNivel = auxRetorno;

        break;

    }

   return seguir;

}


char menu_RetornoMenuBajaEmpleados(int switchMenuBajaEmpleados,int* pAuxRetornoMenu)
{
    char seguir;
    int auxRetorno;
    auxRetorno = *pAuxRetornoMenu;

    switch(switchMenuBajaEmpleados)
    {

        case 1:

                system("cls");

                seguir = menu_RetornoParaItemsConUnEmpleado
                                        ("\n ATENCION: OCURRIO UN ERROR AL INGRESAR.\n"
                                        ,"\n\n EL EMPLEADO ELEGIDO Y SUS ALMUERZOS HAN SIDO DADOS DE BAJA EXITOSAMENTE\n"
                                        ,"\n NO EXISTEN EMPLEADOS DADOS DE ALTA EN LISTA\n"
                                        "\n USTED VOLVERA AL MENU PRINCIPAL PARA SEGUIR PROBANDO EL PROGRAMA.\n"
                                        "\n USTED PODRA CARGAR EMPLEADOS YENDO AL MENU PRINCIPAL > MENU ALTA > ALTA EMPLEADO.\n"
                                        ,"\n FIN DE REINTENTOS, NO SE INGRESO NINGUN EMPLEADO.\n"
                                        ,"\n ATENCION: EL EMPLEADO YA FUE DADO DE BAJA ANTERIORMENTE.\n"
                                        ,"\n ATENCION: EL EMPLEADO NO EXISTE EN LA LISTA DE EMPLEADOS DE LA EMPRESA.\n"
                                        ,"\n ATENCION: OCURRIO UN ERROR AL MOSTRAR AL EMPLEADO. \n"
                                        ,"\n ATENCION: OCURRIO UN ERROR AL DAR DE BAJA EL EMPLEADO Y SUS ALMUERZOS.\n"
                                        ,"\n\n EL EMPLEADO ELEGIDO HA SIDO DADO DE BAJA EXITOSAMENTE.\n"
                                         "\n EL EMPLEADO NO TENIA ALMUERZOS PARA DAR DE BAJA.\n"
                                        ,"\n ATENCION: SE DECIDIO NO DAR DE BAJA NINGUN EMPLEADO.\n"
                                        ,"\n\n A QUE MENU DESEA VOLVER? \n"
                                        "\n 1. MENU PRINCIPAL \n"
                                        " 2. MENU BAJAS \n"
                                        " 3. MENU BAJA DE EMPLEADOS\n"
                                        " 4. SALIR DEL PROGRAMA \n"
                                        "\n  ELEGIR UNA OPCION DEL 1 AL 4: "
                                        ,"\n DESEA DAR DE BAJA OTRO EMPLEADO? S/N: "
                                        ,"HA OCURRIDO UN ERROR\n"
                                        ,&auxRetorno);

                *pAuxRetornoMenu = auxRetorno;

        break;

        case 2:

                 system("cls");

                 seguir = menu_RetornoParaItemsConUnEmpleado
                                          ("\n ATENCION: OCURRIO UN ERROR AL INGRESAR  \n"
                                          ,"\n\n LOS EMPLEADOS DEL SECTOR ELEGIDO HAN SIDO DADOS DE BAJA EXITOSAMENTE.\n"
                                            "\n TAMBIEN SE HAN DADO DE BAJA SUS ALMUERZOS.\n"
                                          ,"\n NO EXISTEN EMPLEADOS DADOS DE ALTA.\n"
                                          "\n USTED PODRA DAR DE ALTA SECTORES EN MENU PRINCIPAL > MENU ALTAS > ALTA SECTOR \n"
                                          ,"\n FIN DE REINTENTOS, NO SE ELIGIO NINGUN SECTOR DENTRO DEL RANGO A ELEGIR.\n"
                                          ,"\n ATENCION: EL SECTOR ELEGIDO NO EXISTE, FUE DADO DE BAJA.\n"
                                          ,"\n ATENCION: OCURRIO UN ERROR INESPERADO.\n "
                                          ,"\n ATENCION: NO EXISTEN EMPLEADOS DADOS DE ALTA EN EL SECTOR \n"
                                          ,"\n ATENCION: OCURRIO UN ERROR AL DAR DE BAJA LOS EMPLEADOS DEL SECTOR.\n"
                                          ,"\n\n LOS EMPLEADOS DEL SECTOR HAN SIDO DADOS DE BAJA EXITOSAMENTE.\n"
                                            "\n LOS EMPLEADOS NO TENIAN ALMUERZOS PARA DAR DE BAJA.\n"
                                          ,"\n ATENCION: SE DECIDIO NO DAR DE BAJA A LOS EMPLEADOS DEL SECTOR.\n"
                                          ,"\n\n A QUE MENU DESEA VOLVER? \n"
                                            "\n 1. MENU PRINCIPAL \n"
                                            " 2. MENU BAJAS \n"
                                            " 3. MENU BAJA DE EMPLEADOS\n"
                                            " 4. SALIR DEL PROGRAMA \n"
                                            "\n  ELEGIR UNA OPCION DEL 1 AL 4: "
                                          ,"\n DESEA DAR DE BAJA EMPLEADOS DE OTRO SECTOR? S/N: "
                                          ,"HA OCURRIDO UN ERROR\n"
                                          ,&auxRetorno);

                     *pAuxRetornoMenu = auxRetorno;
        break;

        case 3:

                 system("cls");

                 seguir = menuRetornos_BajaTodosLosEmpleadosDeLaEmpresa("\n ATENCION: OCURRIO UN ERROR AL INGRESAR  \n"
                                                                        ,"\n\n TODOS LOS EMPLEADOS DE LA EMPRESA HAN SIDO DADOS DE BAJA EXITOSAMENTE.\n"
                                                                         "\n USTED VOLVERA AL MENU PRINCIPAL PARA SEGUIR PROBANDO EL PROGRAMA \n"
                                                                        ,"\n SE DECIDIO NO DAR DE BAJA NINGUN EMPLEADO. \n"
                                                                        ,"\n NO EXISTEN EMPLEADOS PARA DAR DE BAJA. \n"
                                                                        "\n PARA DAR DE BAJA EMPLEADOS PRIMERO DEBE DARLOS DE ALTA. \n"
                                                                        "\n USTED PODRA CARGAR EMPLEADOS YENDO AL MENU PRINCIPAL > MENU ALTA > MENU ALTA EMPLEADO.\n"
                                                                        ,"\n ATENCION: OCURRIO UN ERROR AL DAR DE BAJA A TODOS LOS EMPLEADOS S/N: "

                                                                        ,"\n\n A QUE MENU DESEA VOLVER? \n"
                                                                        "\n 1. MENU PRINCIPAL \n"
                                                                        " 2. MENU BAJAS \n"
                                                                        " 3. MENU BAJA DE EMPLEADOS\n"
                                                                        " 4. SALIR DEL PROGRAMA \n"
                                                                        "\n  ELEGIR UNA OPCION DEL 1 AL 4: "
                                                                      ,"\n DESEA DAR DE BAJA ALGUN OTRO EMPLEADO? S/N: "
                                                                      ,"HA OCURRIDO UN ERROR\n"
                                                                        ,&auxRetorno);

                *pAuxRetornoMenu = auxRetorno;

        break;

    }

  return seguir;

}

char menu_RetornoMenuReingresosEmpleado(int switchMenuReingresoElementos,int* pAuxRetornoMenu)
{

    char seguir;
    int auxRetorno;
    auxRetorno = *pAuxRetornoMenu;

    switch(switchMenuReingresoElementos)
    {
        case 1:
                  system("cls");

                  printf("%d\n",auxRetorno);

                  seguir = menu_RetornoParaItemsConUnEmpleado
                                                    ("\n OCURRIO UN ERROR AL REINGRESAR.\n"
                                                    ,"\n EL EMPLEADO Y SUS ALMUERZOS HAN SIDO REINGRESADOS EXITOSAMENTE.\n"
                                                    ,"\n NO EXISTEN EMPLEADOS DADOS DE BAJA PARA REINGRESAR.\n"
                                                     "\n USTED VOLVERA AL MENU PRINCIPAL PARA SEGUIR PROBANDO EL PROGRAMA.\n"
                                                     "\n USTED PODRA DAR DE BAJA EMPLEADOS YENDO AL MENU PRINCIPAL > MENU BAJAS >"
                                                     " BAJA EMPLEADOS DE LA EMPRESA > DAR DE BAJA UN EMPLEADO \n\n"
                                                    ,"\n FIN DE REINTENTOS, NO SE REINGRESO NINGUN EMPLEADO.\n"
                                                    ,"\n ATENCION: EL EMPLEADO NO SE ENCUENTRA DADO DE BAJA PARA REINGRESARLO.\n"
                                                    ,"\n ATENCION: OCURRIO UN ERROR CON EL EMPLEADO ELEGIDO.\n"
                                                    ,"\n ATENCION: OCURRIO UN ERROR AL MOSTRAR EL EMPLEADO.\n"
                                                    ,""
                                                    ,"\n EL EMPLEADO HA SIDO REINGRESADOS EXITOSAMENTE.\n"
                                                       "\n EL EMPLEADO NO TENIA ALMUERZOS CARGADOS.\n"
                                                    ,"\n ATENCION: SE DECIDIO NO REINGRESAR NINGUN EMPLEADO Y SUS ALMUERZOS.\n"
                                                    ,"\n\n A QUE MENU DESEA VOLVER? \n"
                                                    "\n 1. MENU PRINCIPAL \n"
                                                    " 2. MENU REINGRESOS \n"
                                                    " 3. MENU REINGRESO DE EMPLEADOS\n"
                                                    " 4. SALIR DEL PROGRAMA \n"
                                                    "\n  ELEGIR UNA OPCION DEL 1 AL 4: "
                                                    ,"\n DESEA REINGRESAR ALGUN OTRO EMPLEADO? S/N: "
                                                    ,"HA OCURRIDO UN ERROR\n"
                                                    ,&auxRetorno);

                     *pAuxRetornoMenu = auxRetorno;
        break;

        case 2:

                   system("cls");

                  seguir =  menu_RetornoParaItemsConUnEmpleado
                                  ("\n OCURRIO UN ERROR INESPERADO  \n"
                                  ,"\n ATENCION: NO EXISTEN EMPLEADOS EN EL SECTOR PARA REINGRESAR. \n"
                                   "\n SI DESEA RINGRESAR EMPLEADOS PRIMERO DEBE DARLOS DE BAJA EN EL SECTOR. \n"
                                  ,"\n SE DECIDIO NO REINGRESAR NINGUN EMPLEADO DE NINGUN SECTOR \n"
                                  ,"\n FIN DE REINTENTOS, NO SE ELIGIO NINGUN SECTOR DENTRO DEL RANGO A ELEGIR \n"
                                  ,"\n ATENCION: ID DEL SECTOR INEXISTENTE  \n"
                                  ,"\n ATENCION: EL SECTOR NO TIENE EMPLEADOS DADOS DE BAJA PARA REINGRESAR \n"
                                  ,"\n ATENCION: OCURRIO UN ERROR AL MOSTRAR EMPLEADOS \n"
                                  ,"\n ATENCION: OCURRIO UN ERROR AL REINGRESAR A LOS LOS EMPLEADOS DEL SECTOR."
                                  ,"\n\n LOS EMPLEADOS Y LOS ALMUERZOS DEL SECTOR ELEGIDO HAN SIDO REINGRESADOS EXITOSAMENTE. \n"
                                  ,"\n ATENCION: SE DECIDIO NO DAR DE BAJA A LOS EMPLEADOS DEL SECTOR. \n"
                                  ,"\n\n A QUE MENU DESEA VOLVER? \n"
                                  "\n 1. MENU PRINCIPAL \n"
                                  " 2. MENU REINGRESOS \n"
                                  " 3. MENU REINGRESO DE EMPLEADOS\n"
                                  " 4. SALIR DEL PROGRAMA \n"
                                  "\n  ELEGIR UNA OPCION DEL 1 AL 4: "
                                  ,"\n DESEA VOLVER A INTENTAR REINGRESAR? S/N: "
                                 ,"HA OCURRIDO UN ERROR\n"
                                 ,&auxRetorno);

                 *pAuxRetornoMenu = auxRetorno;

        break;

        case 3:

                    system("cls");

                   printf("%d\n",auxRetorno);

                  seguir =  menu_RetornoParaItemsConUnEmpleado
                                  ("\n OCURRIO UN ERROR INESPERADO  \n"
                                  ,"\n NO EXISTEN EMPLEADOS DADOS DE BAJAS PARA REINGRESAR \n"
                                  ,"\n ATENCION: SE DECIDIO NO DAR DE BAJA A LOS EMPLEADOS DEL SECTOR. \n"
                                  ," "
                                  ," "
                                  ," "
                                  ,"\n ATENCION: OCURRIO UN ERROR AL REINGRESAR A LOS LOS EMPLEADOS DEL SECTOR."
                                  ," "
                                  ,"\n TODOS LOS EMPLEADOS Y SUS ALMUERZOS HAN SIDO REINGRESADOS EXITOSAMENTE. \n"
                                  ," "
                                  ,"\n\n A QUE MENU DESEA VOLVER? \n"
                                  "\n 1. MENU PRINCIPAL \n"
                                  " 2. MENU REINGRESOS \n"
                                  " 3. MENU REINGRESO DE EMPLEADOS\n"
                                  " 4. SALIR DEL PROGRAMA \n"
                                  "\n  ELEGIR UNA OPCION DEL 1 AL 4: "
                                  ,"\n DESEA PERMANECER EN ESTE MENU? S/N: "
                                 ,"HA OCURRIDO UN ERROR\n"
                                 ,&auxRetorno);

                 *pAuxRetornoMenu = auxRetorno;


        break;

    }

    return seguir;
}


char menu_RetornoParaItemsConUnEmpleado(char* caseCero,char* caseUno,char* caseDos,char* caseTres
                                        ,char* caseCuatro,char* caseCinco,char* caseSeis,char* caseSiete
                                        ,char* caseOcho,char* caseNueve,char* menuParaAQueMenuDeseaVolver
                                        ,char* mensajeMenuContinuar,char* mensajeError,
                                        int* pAuxRetornoMenu)
{

    char seguir;
    char salir;
    int auxRetorno;
    auxRetorno = *pAuxRetornoMenu;

    switch(auxRetorno)
    {
        case 0:
                 puts(caseCero);

                 seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver,&auxRetorno);

                 *pAuxRetornoMenu = auxRetorno;
        break;

        case 1:
                  printf(caseUno);

                  seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver,&auxRetorno);

                 *pAuxRetornoMenu = auxRetorno;
        break;

        case 2:
                  ///COMO NO HAY ELEMENTOS CON LOS CUALES TRABAJAR
                  ///TE REDIRIGE DIRECTO AL MENU PRINCIPAL
                  printf(caseDos);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {

                        system("cls");
                        seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                          ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }

        break;

        case 3:
                  printf(caseTres);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                 ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {
                     system("cls");
                     seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                       ,&auxRetorno);

                    *pAuxRetornoMenu = auxRetorno;

                  }
        break;

        case 4:

                  printf(caseCuatro);
                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {
                        system("cls");
                        seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                          ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

        case 5:

                  printf(caseCinco);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {
                        system("cls");
                        seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                          ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

        case 6:

                  printf(caseSeis);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {
                       system("cls");
                       seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                         ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

        case 7:

                  printf(caseSiete);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {
                       system("cls");
                       seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                        ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

        case 8:

                  printf(caseOcho);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {

                       system("cls");
                       seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                         ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

        case 9:
                    printf(caseNueve);

                    seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                      ,&auxRetorno);

                   *pAuxRetornoMenu = auxRetorno;
        break;
    }

    return seguir;
}


char menuRetornos_BajaTodosLosEmpleadosDeLaEmpresa(char* caseCero,char* caseUno,char* caseDos,char* caseTres
                                                    ,char* caseCuatro,char* menuParaAQueMenuDeseaVolver
                                                    ,char* mensajeMenuContinuar,char* mensajeError,
                                                    int* pAuxRetornoMenu)
{

    char seguir;
    char salir;
    int auxRetorno;
    auxRetorno = *pAuxRetornoMenu;

    switch(auxRetorno)
    {
        case 0:
                 puts(caseCero);

                 seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver,&auxRetorno);

                 *pAuxRetornoMenu = auxRetorno;
        break;

        case 1:
                  printf(caseUno);

                   if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {

                       system("cls");
                       seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                         ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

        case 2:
                  ///COMO NO HAY ELEMENTOS CON LOS CUALES TRABAJAR
                  ///TE REDIRIGE DIRECTO AL MENU PRINCIPAL
                  printf(caseDos);

                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {

                        system("cls");
                        seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                          ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }

        break;

        case 3:
                  printf(caseTres);

                  seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver,&auxRetorno);

                 *pAuxRetornoMenu = auxRetorno;
        break;

        case 4:

                  printf(caseCuatro);
                  if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,mensajeMenuContinuar
                                                                  ,mensajeError,2)

                                                    && salir == 'S' || salir == 's')
                  {
                        seguir='s';

                  }
                  else
                  {
                        system("cls");
                        seguir = menu_aQueMenuDeseaVolver(menuParaAQueMenuDeseaVolver
                                                          ,&auxRetorno);

                       *pAuxRetornoMenu = auxRetorno;
                  }
        break;

    }

    return seguir;
}


char menu_aQueMenuDeseaVolver(char* eleccionDeOpciones,int* pAuxRetornoMenu)
{

    char seguir;
    int opcion;

    utn_pMenuOpciones_(&opcion
                       ,eleccionDeOpciones
                       ,"\n ERROR AL INGRESAR LA OPCION: "
                       ,1,4,2);

        switch(opcion)
        {

            case 1:

                   system("cls");
                   seguir='n';
                   *pAuxRetornoMenu=1;

            break;

            case 2:

                    system("cls");
                    seguir='n';
                    *pAuxRetornoMenu=2;

            break;

            case 3:

                   system("cls");
                   seguir='n';
                   *pAuxRetornoMenu=3;

            break;

            case 4:
                   system("cls");
                   seguir='n';
                   *pAuxRetornoMenu=4;

            break;

            default:

                      printf("\n FIN DE REINTENTOS, USTED HA INGRESADO OPCIONES INVALIDAS");

            break;
        }

    return seguir;
}

int NEXO_pCargaIdEmpleadoEn_DeLaLista_(int* pAuxIdEmpleado,eEmpleado* listaEmpleados,int tamListaEmpleados
                                      ,eSector* listaSectores,int tamListaSectores)
{
    int retorno;
    retorno=0;
    int auxIdEmpleado;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && auxIdEmpleado != NULL)
    {
        system("cls");

        NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores);

        retorno = utn_pIngresoDeElementoTipoEntero_(&auxIdEmpleado,"\n INGRESE LEGAJO DEL EMPLEADO A DAR DE BAJA "
                                                    "ENTRE 1 - 10000:  "
                                                   ,"\n ERROR, REINGRESE ID DEL EMPLEADO: ",
                                                    MIN_ID_EMPLEADO, MAX_ID_EMPLEADO, REINTENTOS);
        if(retorno != 1)
        {

             retorno=3;

        }
        else
        {
            *pAuxIdEmpleado=auxIdEmpleado;
             retorno=1;

        }
    }
    else
    {
        puts("\n OCURRIO UN ERROR AL INGRESAR A BAJA UN EMPLEADO \n");
    }


    return retorno;
}

//busca empleado dado de ALTA por ID Y retorna 1 si lo encontro
int EMPLEADO_pRetorna_UNO_SiElEmpleado_EstaDadoDeAlta_EnLista_CERO_SINO(eEmpleado* unEmpleado,eEmpleado* listaEmpleados
                                                                        ,int tamListaEmpleados)
{
    int retorno;
    retorno=0;

    if( listaEmpleados!= NULL && tamListaEmpleados > 0)
    {
        for(int i =0 ; i < tamListaEmpleados ; i++)
        {
            if(EMPLEADO_pEstaElEmpleado_DadoDeAlta_Y_EsElEmpleado_(listaEmpleados + i,&(unEmpleado)->legajo))
            {
                retorno = 1;
                break;
            }
        }

        if(!retorno)
        {
            printf("\n NO SE ENCONTRO EL EMPLEADO DADO DE ALTA. \n");
        }
       // else
        //{
          //  printf("\n EMPLEADO ENCONTRADO CON EXITO \n");
        //}
    }

    return retorno;
}


int EMPLEADO_pEstaElEmpleado_DadoDeAlta_Y_EsElEmpleado_(eEmpleado* unEmpleado,int* pAuxIdEmpleado)
{

    int auxIdEmpleado;
    auxIdEmpleado=*pAuxIdEmpleado;

     if( unEmpleado != NULL && auxIdEmpleado != NULL)
    {

        return(EMPLEADO_pEstaEmpleado_DadoDeAlta_(unEmpleado) &&

                    GENERICA_pEsElNumero_IgualQueElNumero_( &(unEmpleado)->legajo, &auxIdEmpleado));
    }

}


int EMPLEADO_pBuscaLaPosicion_DelEmpleado_DadoDeAlta_EnLaLista_(int* pAuxPosicion,eEmpleado* unEmpleado
                                                                ,eEmpleado* listaEmpleados,int tamListaEmpleados)
{
    int retorno;
    retorno=0;

    int auxPosicion;
    auxPosicion;

    ///ASUMO QUE ESTA DADO DE ALTA SINO SI PREGNUNTO ESTOY PROGRAMANDO A LA DEFENSIVA

    if(unEmpleado != NULL && listaEmpleados != NULL && tamListaEmpleados > 0)
    {
               ///BUSCA LA POSICION DEL EMPLEADO DENTRO DE LA LISTA
               EMPLEADO_pRetornaLaPosicion_DeUnEmpleado_DadoDeAlta_EnLaLista_(&auxPosicion,unEmpleado
                                                                             ,listaEmpleados,tamListaEmpleados);

               if(auxPosicion == -1)
               {
                    //system("cls");
                    retorno=0;
                    puts("\n ATENCION: NO SE ENCONTRO LA POSICION DEL EMPLEADO EN LA LISTA \n");
               }
               else
               {
                   *pAuxPosicion=auxPosicion;
                   retorno = 1;
                   puts("\n SE ENCONTRO LA POSICION DEL EMPLEADO EN LA LISTA ");
               }
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR A BUSQUEDA DE LA POSICION DEL EMPLEADO DADO DE ALTA \n");
    }

    return retorno;
}


 int EMPLEADO_pRetornaLaPosicion_DeUnEmpleado_DadoDeAlta_EnLaLista_(int* pAuxPosicion,eEmpleado* unEmpleado
                                                                    ,eEmpleado* listaEmpleados,int tamListaEmpleados)
{
    int retorno;
    retorno=0;
    int auxPosicion;
    auxPosicion=-1;

    if(pAuxPosicion != NULL && unEmpleado != NULL && listaEmpleados != NULL && tamListaEmpleados > 0)
    {
        for(int i=0; i < tamListaEmpleados; i++)
        {
            if(GENERICA_pEsElNumero_IgualQueElNumero_(&(listaEmpleados + i)->legajo ,&(unEmpleado)->legajo))
            {
               auxPosicion=i;
               *pAuxPosicion=auxPosicion;
                retorno=1;
               auxPosicion=-1;

               break;
            }
        }
    }

    return retorno;
}


eEmpleado EMP_pRetornaElEmpleado_ConElId_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* pRetorno,int* pAuxIdEmpleado)
{
    eEmpleado auxEmpleado;
    int retorno;
    int auxIdEmpleado;
    auxIdEmpleado=*pAuxIdEmpleado;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && pAuxIdEmpleado != NULL && pRetorno != NULL)
    {
        for(int i=0; i<tamListaEmpleados; i++)
            //if(EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i)
        {
            if(GENERICA_pEsElNumero_IgualQueElNumero_(&(listaEmpleados + i)->legajo,&auxIdEmpleado))
            {

                auxEmpleado = *(listaEmpleados + i) ;
                 retorno = 1;
                *pRetorno = retorno;
                 break;
            }

        }


    }



    return auxEmpleado;
}


int NEXO_pMenuModificar(eEmpleado* listaEmpleados,int tamListaEmpleados
                         ,eSector* listaSectores,int tamListaSectores
                         ,eComida* listaComidas,int tamListaComidas
                         ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{

    int opcion;
    char seguir;
    char salir;
    int retorno;
    retorno=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {
        int opcion;
        char seguir;
        char salir;
        int retorno;
        retorno=0;

        do
        {
            system("cls");

            utn_pMenuOpciones_(&opcion
                                  ,"\n\n  MENU BAJAS   \n"
                                  "\n 1.MODIFICAR EMPLEADOS DE LA EMPRESA \n"
                                  " 2.SALIR \n"
                                  "\n ELIJA UNA OPCION DEL 1 AL 2: "
                                  ,"\n ERROR AL INGRESAR EL NUMERO \n",1,2,2);

            switch(opcion)
            {
                case 1:

                        system("cls");

                        //la funcion es 1 entra al if 0 NO ENTRA Y sale por el else
                        // si es false (0) entonces doble negacion y sale por el else

                        if(!NEXO_pModificaEmpleados_CUATRO(listaEmpleados,tamListaEmpleados
                                                           ,listaSectores,tamListaSectores
                                                           ,listaComidas,tamListaComidas
                                                           ,listaAlmuerzos,tamListaAlmuerzos))
                        {

                            retorno=0;

                        }
                        else
                        {

                            retorno=1;

                            system("cls");
                            seguir='s';

                        }
                        break;

                case 2:

                         if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAL? S/N: "
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
                        printf("\n\n OPCIONES INVALIDAS, SE TERMINARON SUS INTENTOS \n");

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU PRINCIPAR? S/N: ",
                                "HA OCURRIDO UN ERROR\n",2)
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

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        retorno=-1;
    }

    return retorno;

}



int NEXO_pModificaEmpleados_CUATRO(eEmpleado* listaEmpleados,int tamListaEmpleados
                                   ,eSector* listaSectores,int tamListaSectores
                                   ,eComida* listaComidas,int tamListaComidas
                                   ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    int retorno;
    int flag;
    int auxId;
    auxId=-1;
    int auxIndice;
    auxIndice=-1;
    int resultado;
    char seguir;
    char salir;
    eEmpleado auxEmpleado;
    flag=0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            &&  listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {
        do
        {
            if(NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores))
            {

                utn_pIngresoDeElementoTipoEntero_(&auxId, "\n\n INGRESE EL ID DEL EMPLEADO A MODIFICAR POR FAVOR: "
                                                  , "\n\n ERROR REINGRESE ID:  ",MIN_ID_EMPLEADO
                                                  ,MAX_ID_EMPLEADO,REINTENTOS);

               //EMPLEADO_pEstaElEmpleadoDadoDeAlta_EnListaEmpleados_(listaEmpleados,tamListaEmpleados,&auxIndice,&auxId);

                if(auxIndice == -1)
                {
                    system("cls");

                    puts("\n\n NO EXISTE EMPLEADO CON ESE ID EN LA LISTA DE EMPLEADOS ");

                    if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                            ,"\n\n DESEA SALIR DEL MENU MODIFICAR? S/N:  ",
                            "\n\n HA OCURRIDO UN ERROR \n",2)

                            && (salir == 'S' || salir == 's') )

                    {
                        system("cls");
                        seguir='n';
                    }
                    else
                    {
                        system("cls");
                        seguir='s';
                    }

                }
                else
                {

                    auxEmpleado = *(listaEmpleados + auxIndice);

                    auxEmpleado = NEXO_pModificaUnEmpleado_CUATRO( &auxEmpleado
                                                                  ,listaEmpleados,tamListaEmpleados
                                                                  ,listaSectores,tamListaSectores
                                                                  ,listaComidas,tamListaComidas
                                                                  ,listaAlmuerzos,tamListaAlmuerzos
                                                                  ,&retorno);

                    if(retorno)
                    {

                        system("cls");

                        *(listaEmpleados + auxIndice)= auxEmpleado;

                        auxId=-1;
                        auxIndice=-1;
                        retorno = 1;
                    }
                    else
                    {
                        system("cls");

                        printf("\n\n OCURRIO UN ERROR EL QUERER MODIFICAR EL EMPLEADO \n");

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&seguir,"\n DESEA MODIFICAR OTRO EMPLEADO? S/N: "
                                ,"\n HA OCURRIDO UN ERROR  ",2)

                                && salir == 'S' || salir == 's')

                        {
                            system("cls");
                            seguir='s';
                        }
                        else
                        {
                            seguir='n';

                        }
                    }
                }
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS PARA MODIFICAR, LISTA DE EMPLEADOS VACIA \n");
            }

        }
        while(seguir == 's' || seguir == 'S');
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR AL MENU MODIFICAR EMPLEADOS \n");
    }

    return retorno;
}


eEmpleado NEXO_pModificaUnEmpleado_CUATRO(eEmpleado* unEmpleado
                                        ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                        ,eSector* listaSectores,int tamListaSectores
                                        ,eComida* listaComidas,int tamListaComidas
                                        ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,int* pRetorno)
{
    int opcion;
    char seguir;
    int seguirEnItemNacimiento;
    int auxAnio;
    auxAnio=2024;
    eEmpleado auxEmpleado;
    auxEmpleado=*(unEmpleado);
    int salir;
    int retorno;
    retorno=0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            &&  listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {
        do
        {
            system("cls");

            NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

            utn_pMenuOpciones_(&opcion
                               ,"\n\n\n 1.NOMBRE \n"
                               " 2.APELLIDO \n"
                               " 3.FECHA DE NACIMIENTO\n"
                               " 4.SUELDO \n"
                               " 5.SECTOR\n"
                               " 6.FECHA INGRESO \n"
                               " 7.SEXO \n"
                               " 8.EDAD \n"
                               " 9.SALIR \n"
                               "\n INGRESE OPCION DEL 1 AL 9: "
                               ,"\n ERROR AL INGRESAR MODIFICACIONES \n",1,9,2);

            switch(opcion)
            {

                    case 1:

                        if(utn_pIngresoDeLaCadena_DeTam_(auxEmpleado.nombre,20, "\n\n INGRESE NUEVO NOMBRE: "
                                                         ,"\n\n ERROR, REINGRESE DE NUEVO EL NOMBRE:  ", 2))
                        {

                            system("cls");

                            NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                             puts("\n\n NOMBRE MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS \n");

                            *(pRetorno)=1;

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                                                            ,"\n HA OCURRIDO UN ERROR \n",2)

                                    && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                        }
                        else
                        {
                            system("cls");

                            printf("\n OCURRIO UN ERROR EL INGRESAR EL NOMBRE DEL EMPLEADO \n");

                            *(pRetorno)=0;

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                    ,"\n HA OCURRIDO UN ERROR  \n",2)

                                    && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                seguir='n';

                            }

                        }
                break;

                case 2:

                        if(utn_pIngresoDeLaCadena_DeTam_(auxEmpleado.apellido,20, "\n\n INGRESE NUEVO APELLIDO: "
                                                         ,"\n ERROR, REINGRESE DE NUEVO EL APELLIDO: ",2))
                        {

                            system("cls");

                            NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                            puts("\n\n APELLIDO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS \n\n");

                            *(pRetorno)=1;

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                            ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N: "
                                                                            ,"\n HA OCURRIDO UN ERROR  ",2)

                                    && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                        }
                        else
                        {
                            system("cls");

                            printf("\n OCURRIO UN ERROR EL INGRESAR EL NOMBRE DEL EMPLEADO \n");

                            *(pRetorno)=0;

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                            ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                                                            ,"\n HA OCURRIDO UN ERROR  ",2)

                                    && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                        }
                break;

                case 3:


                            system("cls");

                            auxEmpleado = NEXO_pMenu_ModificaFecha_Nacimiento_Empleado_(&auxEmpleado
                                                                                        ,listaSectores
                                                                                        ,tamListaSectores
                                                                                        ,&pRetorno);

                        if(pRetorno)
                        {
                                system("cls");

                                puts("\n\n FECHA DE NACIMIENTO MODIFICADA CORRECTAMENTE, CAMBIOS GUARDADOS. \n\n");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                *(pRetorno)=1;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                                                                ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';

                                }
                        }
                        else
                        {
                            printf("\n OCURRIO UN ERROR AL MODIFICAR LA FECHA DE NACIMIENTO DEL EMPLEADO \n");
                        }

             break;

             case 4:

                            if(utn_pIngresoDeElementoTipoFlotante_(&auxEmpleado.sueldo,"\n INGRESE NUEVO SUELDO: "
                                                                   , "\n ERROR, REINGRESE DE NUEVO EL SUELDO:  "
                                                                   , 1, 10000000,2))
                            {
                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n SUELDO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS \n\n");

                                *(pRetorno)=1;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                                                                ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';

                                }
                            }
                            else
                            {
                                system("cls");

                                printf("\n OCURRIO UN ERROR AL INGRESAR EL SEXO DEL EMPLEADO \n");

                                *(pRetorno)=0;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N: "
                                                                                ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';
                                }
                            }
                break;

                case 5:

                            printf("\n\n SECTORES A ELEGIR \n\n");

                            system("cls");

                            NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                            funcion_MostrarSectores(listaSectores,tamListaSectores);

                            if(utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.ID_Sector
                                                                 , "\n\n COLOQUE EL NUMERO DEL NUEVO SECTOR A ELEGIR:  "
                                                                 , "\n ERROR AL REINGRESAR EL NUMERO DE SECTOR:  "
                                                                 ,MIN_LISTA_SECTORES,MAX_LISTA_SECTORES,2))
                            {

                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                 puts("\n\n SECTOR MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS \n\n");

                                *(pRetorno)=1;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                        ,"\n\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                        ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';
                                }

                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR LA EDAD DEL EMPLEADO \n");

                                *(pRetorno)=0;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                        ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                        ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';
                                }

                            }
                break;

                case 6:

                            auxEmpleado = NEXO_pMenu_ModificaFecha_Ingreso_Empleado_(&auxEmpleado
                                                                                     ,listaSectores,tamListaSectores
                                                                                     ,&pRetorno);
                            if(pRetorno)
                            {
                                system("cls");

                                puts("\n\n FECHA DE INGRESO MODIFICADA CORRECTAMENTE, CAMBIOS GUARDADOS \n\n");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                //*(pRetorno)=1;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N: "
                                                                                ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';

                                }

                            }
                            else
                            {

                                printf("\n OCURRIO UN ERROR AL MODIFICAR LA FECHA DE NACIMIENTO DEL EMPLEADO \n");

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                            ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                            ,"\n HA OCURRIDO UN ERROR  ",2)

                                            && salir == 'S' || salir == 's')

                                {
                                            system("cls");
                                            seguir='s';
                                }
                                else
                                {
                                            seguir='n';
                                }

                            }
                break;

                case 7:

                            if(utn_pIngresoDeSexoF_M_oNoBinario_DeTam_(&auxEmpleado.sexo,sizeof(unEmpleado->sexo),
                                    "\n\n INGRESE SEXO A MODIFICAR: MASCULINO (M), FEMENINO (F), NO BINARIO (NB): ",
                                    "HA OCURRIDO UN ERROR\n",2))
                            {
                                system("cls");

                                 NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                  puts("\n\n SEXO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS ");

                                *(pRetorno)=1;

                            }
                            else
                            {

                                system("cls");
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL SEXO DEL EMPLEADO \n");
                               *(pRetorno)=0;

                            }

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                        ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                        ,"\n HA OCURRIDO UN ERROR  ",2)

                            && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                            system("cls");

                break;

                case 8:

                            if(utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.edad,"\n\n INGRESE NUEVA EDAD PARA EL EMPLEADO:  "
                                                                   , "\n\n ERROR, REINGRESE NUEVA EDAD PARA EL EMPLEADO:  "
                                                                   , 1, 120,2))
                            {
                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                 puts("\n\n EDAD DEL EMPLEADO MODIFICADA CORRECTAMENTE, CAMBIOS GUARDADOS. \n\n");

                                *(pRetorno)=1;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N: "
                                                                                ,"\n HA OCURRIDO UN ERROR   ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';

                                }
                            }
                            else
                            {
                                system("cls");

                                printf("\n OCURRIO UN ERROR AL INGRESAR EL SEXO DEL EMPLEADO\n");

                                *(pRetorno)=0;

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA SEGUIR MODIFICANDO EL EMPLEADO? S/N:  "
                                                                                ,"\n HA OCURRIDO UN ERROR  ",2)

                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='s';
                                }
                                else
                                {
                                    seguir='n';
                                }
                            }
                            break;

                            system("cls");

                break;

                case 9:

                            system("cls");

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA VOLVER AL MENU MODIFICAR? S/N:  "
                                                                            ,"\n HA OCURRIDO UN ERROR\n",2)

                                    && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='n';
                            }
                            else
                            {
                                seguir='s';

                            }

                            system("cls");


                break;

                default:

                            system("cls");

                            printf("\n SE TERMINARON SUS INTENTOS, OPCIONES INGRESADAS INVALIDAS \n");

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                    ,"\n DESEA MODIFICAR AL EMPLEADO? S/N:  "
                                    ,"\n HA OCURRIDO UN ERROR\n",2)

                                    && salir == 'S' || salir == 's')

                            {
                                system("cls");
                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                            system("cls");
                            break;

          }


        }
        while(seguir == 'S' || seguir == 's');

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        *(pRetorno)=0;
    }

    return auxEmpleado;
}

eEmpleado NEXO_pMenu_ModificaFecha_Nacimiento_Empleado_(eEmpleado* unEmpleado,int* listaSectores,int tamListaSectores,int* pRetorno)
{

    eEmpleado auxEmpleado;
    auxEmpleado= *(unEmpleado);
    int opcion;
    int seguir;

    if( unEmpleado != NULL && listaSectores != NULL && tamListaSectores > 0 && pRetorno != NULL)
    {
        do
        {
            system("cls");

            printf("\n\n EMPLEADO ELEGIDO \n");

            NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

            utn_pMenuOpciones_(&opcion
                               ,"\n\n MENU FECHA DE NACIMIENTO \n"
                               " 1.DIA DE NACIMIENTO \n"
                               " 2.MES DE NACIMIENTO \n"
                               " 3.ANIO DE NACIMIENTO \n"
                               " 4.SALIR"
                               "\n INGRESE OPCION A MODIFICAR: "
                               ," ERROR AL INGRESAR FECHAS \n",1,4,2);

            switch(opcion)
            {
                case 1:


                            if(utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Nacimiento_Empleado.dia
                                                                  ,"\n\n INGRESE EL DIA DE NACIMIENTO DEL EMPLEADO: "
                                                                  ,"\n ERROR AL INGRESAR EL DIA DE NACIMIENTO DEL EMPLEADO"
                                                                  ,1,31,2))

                            {

                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n DIA DE NACIMIENTO DEL EMPLEADO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS. \n");

                                *(pRetorno)=1;
                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL DIA DE NACIMIENTO DEL EMPLEADO\n");

                                *(pRetorno)=0;

                            }

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA SEGUIR MODIFICANDO LA FECHA DE NACIMIENTO? S/N: "
                                                                  , "\n ERROR AL INGRESAR S O N \n",2))
                            {

                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                break;

                case 2:

                            if(utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Nacimiento_Empleado.mes
                                                                  , "\n\n INGRESE EL MES DE NACIMIENTO DEL EMPLEADO: "
                                                                  , "\n ERROR AL INGRESAR EL MES DE NACIMIENTO DEL EMPLEADO"
                                                                  ,1, 12, 2))
                            {

                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n MES DE NACIMIENTO DEL EMPLEADO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS. \n");

                                *(pRetorno)=1;
                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL MES DE NACIMIENTO DEL EMPLEADO \n");
                                 *(pRetorno)=0;

                            }

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA SEGUIR MODIFICANDO LA FECHA DE NACIMIENTO? S/N: "
                                                                  , "\n ERROR AL INGRESAR S O N \n"
                                                                  ,2))
                            {

                                seguir='s';
                            }
                            else
                            {

                                seguir='n';
                            }

                break;

                case 3:

                             if(utn_pIngresoDeAnioTipoEntero_( &auxEmpleado.fecha_Nacimiento_Empleado.anio
                                                              ," INGRESE ANIO DE NACIMIENTO DEL EMPLEADO: "
                                                              ,"\n ERROR EL INGRESAR EL ANIO DE NACIMIENTO DEL EMPLEADO \n"
                                                              ,1900,2024, 2))
                            {

                                system("cls");

                                //utn_calcularEdad(auxAnio, (*(unEmpleado)).fecha_Nacimiento_Empleado.anio,&unEmpleado->edad, 18, 120);

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n ANIO DE NACIMIENTO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS. \n");

                                *(pRetorno)=1;

                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL ANIO DE NACIMIENTO DEL EMPLEADO \n");
                                *(pRetorno)=0;
                            }

                            system("cls");

                break;

                case 4:

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA SALIR? S/N:  "
                                                              , "\n ERROR AL INGRESAR S O N \n",2))
                            {

                                seguir='n';
                            }
                            else
                            {
                                seguir='s';
                            }

                break;

                default:

                            printf("\n FIN DE INTENTOS, OPCIONES INVALIDAS. ");

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA TODAVIA MODIFICAR LAS FECHAS DE NACIMIENTO? S/N: "
                                                                  ,"\n ERROR AL INGRESAR S O N \n",2))
                            {

                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }
                break;

            }

        }while(seguir == 's' || seguir == 'S');
    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        *(pRetorno)=0;
    }


    return auxEmpleado;
}




eEmpleado NEXO_pMenu_ModificaFecha_Ingreso_Empleado_(eEmpleado* unEmpleado,int* listaSectores,int tamListaSectores,int* pRetorno)
{

    eEmpleado auxEmpleado;
    auxEmpleado= *(unEmpleado);
    int opcion;
    int seguir;

    if( unEmpleado != NULL && listaSectores != NULL && tamListaSectores > 0 && pRetorno != NULL)
    {
        do
        {
            system("cls");

            NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

            utn_pMenuOpciones_(&opcion
                               ,"\n\n MENU FECHA DE INGRESO \n\n"
                               " 1.DIA DE INGRESO \n"
                               " 2.MES DE INGRESO \n"
                               " 3.ANIO DE INGRESO \n"
                               " 4.SALIR \n"
                               "\n INGRESE OPCION A MODIFICAR: "
                               ," ERROR AL INGRESAR FECHAS \n",1,4,2);

            switch(opcion)
            {
                case 1:


                            if(utn_pIngresoDeElementoTipoEntero_( &auxEmpleado.fecha_Ingreso_Empleado.dia
                                                                  ,"\n\n INGRESE EL DIA DE INGRESO DEL EMPLEADO: "
                                                                  ,"\n ERROR AL INGRESAR EL DIA DE INGRESO DEL EMPLEADO "
                                                                  ,1,31,2))
                            {

                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n DIA DE INGRESO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS. \n");

                                *(pRetorno)=1;
                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL DIA\n");

                                 *(pRetorno)=0;

                            }

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA SEGUIR MODIFICANDO LA FECHA DE INGRESO? S/N: "
                                                                  , "\n ERROR AL INGRESAR S O N \n",2))
                            {

                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }

                break;

                case 2:

                            if(utn_pIngresoDeElementoTipoEntero_(&auxEmpleado.fecha_Ingreso_Empleado.mes
                                                                  , "\n\n INGRESE EL MES DE INGRESO DEL EMPLEADO: "
                                                                  , "\n ERROR AL INGRESAR EL MES DE INGRESO DEL EMPLEADO ",1, 12, 2))
                            {

                                system("cls");

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n MES DE INGRESO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS. \n");

                                *(pRetorno)=1;
                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL MES DE INGRESO DEL EMPLEADO \n");
                                 *(pRetorno)=0;

                            }

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA SEGUIR MODIFICANDO LA FECHA DE INGRESO? S/N: "
                                                                  , "\n ERROR AL INGRESAR S O N. \n",2))
                            {

                                seguir='s';
                            }
                            else
                            {

                                seguir='n';
                            }

                break;

                case 3:

                             if(utn_pIngresoDeAnioTipoEntero_(&auxEmpleado.fecha_Ingreso_Empleado.anio
                                                              ," INGRESE ANIO DE INGRESO DEL EMPLEADO: "
                                                              ,"\n ERROR EL INGRESAR EL ANIO DE INGRESO DEL EMPLEADO. "
                                                              ,1900,2024, 2))
                            {

                                system("cls");

                                //utn_calcularEdad(auxAnio, (*(unEmpleado)).fecha_Nacimiento_Empleado.anio,&unEmpleado->edad, 18, 120);

                                NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(&auxEmpleado,listaSectores,tamListaSectores);

                                puts("\n\n ANIO DE INGRESO DEL EMPLEADO MODIFICADO CORRECTAMENTE, CAMBIOS GUARDADOS. \n");

                                *(pRetorno)=1;

                            }
                            else
                            {
                                printf("\n OCURRIO UN ERROR AL INGRESAR EL ANIO DE INGRESO DEL EMPLEADO \n");
                                *(pRetorno)=0;
                            }

                            system("cls");
                break;

                case 4:

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n DESEA SALIR? S/N: "
                                                              , "\n ERROR AL INGRESAR S O N. \n",2))
                            {

                                seguir='n';
                            }
                            else
                            {
                                seguir='s';
                            }
                break;

                default:

                            printf("\n FIN DE INTENTOS, OPCIONES INVALIDAS. ");

                            if(utn_pRespuestaBooleanaSiUno_NoCero("\n\n DESEA TODAVIA MODIFICAR LAS FECHAS DE INGRESO ? S/N: "
                                                              , "\n ERROR AL INGRESAR S O N. \n",2))
                            {

                                seguir='s';
                            }
                            else
                            {
                                seguir='n';
                            }
                break;

            }

        }while(seguir == 's' || seguir == 'S');

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR \n");
        *(pRetorno)=0;
    }


    return auxEmpleado;
}



//busca empleado dado de baja por ID Y retorna 1 si lo encontro
int NEXO_pBuscaEmpleado_SiEstaDadoDeBaja_ConID_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* auxIDEmpleado)

{
    int retorno;
    retorno=0;

    if( listaEmpleados!= NULL && tamListaEmpleados > 0)
    {
        for(int i =0 ; i < tamListaEmpleados ; i++)
        {
            //SI NO ESTA DADO DE ALTA ENTONCES DOBLE NEGADO ENTRA
            if( !EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i)
                                            && (*(listaEmpleados + i)).legajo == *(auxIDEmpleado))
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}


int EMPLEADO_pBuscaNombreEmpleado_EnListaEmpleados_DeTam_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                            ,char* auxNombreEmpleado,int* auxIdEmpleado)
{
    int retorno;
    retorno = 0;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && auxNombreEmpleado != NULL )
    {
        for(int i =0; i < tamListaEmpleados ; i++)
        {
            if( EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i)
                                && (listaEmpleados + i)->legajo == *(auxIdEmpleado) )
            {

                EMPLEADO_pRetornaNombreDelEmpleado(auxNombreEmpleado,(listaEmpleados + i)->nombre);

                retorno=1;
            }
        }
    }

    return retorno;
}



int EMPLEADO_pBuscaApellidoEmpleado_EnListaEmpleados_DeTam_(eEmpleado* listaDeEmpleados,int tamListaDeEmpleados
                                                            ,int* IdEmpleado,char* auxApellidoEmpleado)
{
    int retorno;
    retorno = 0;

    if( listaDeEmpleados != NULL && tamListaDeEmpleados > 0 && auxApellidoEmpleado != NULL)
    {
        for(int i =0; i < tamListaDeEmpleados ; i++)
        {
            if( (listaDeEmpleados + i)->is_Empleado_Full && ( (*(listaDeEmpleados + i)).legajo == *(IdEmpleado))  )
            {

                EMPLEADO_pRetornaApellidoDelEmpleado_(auxApellidoEmpleado,(listaDeEmpleados + i)->apellido);

                retorno=1;
            }
        }
    }

    return retorno;
}


int EMPLEADO_pRetornaApellidoDelEmpleado_(char* auxApellidoEmpleado,char* apellidoEmpleado)
{
    int retorno;
    retorno=0;

    if(auxApellidoEmpleado != NULL && apellidoEmpleado != NULL)
    {
        strcpy( auxApellidoEmpleado, apellidoEmpleado );
        retorno=1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL CARGAR EL APELLIDO DEL EMPLEADO \n");
    }

    return retorno;
}


int EMPLEADO_pBusca_IDSectorDelEmpleadoEn_ListaEmpleados_DeTam_(eEmpleado* listaEmpleados,int tamListaEmpleados,
                                                                  int* pIDEmpleado,int* pAuxIDSector)
{
    int retorno;
    retorno = 0;

    //NECESITO SI O SI TRABAJAR CON UN AUXILIAR Y PASARLO A LA OTRA FUNCION CUANDO MACHEE EL ID PARA
    //LUEGO ASIGNARLO Y PASARLO POR REFERECIA VIA pIDEmpleado. TRABAJANDO DIRECTO CON pIDEMPLEADO NO FUNCIONA
    int auxIDSector;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && pIDEmpleado != NULL && pAuxIDSector != NULL)
    {

        for(int i = 0; i < tamListaEmpleados; i++)
        {

            if(  (listaEmpleados + i)->is_Empleado_Full && (listaEmpleados + i)->legajo == *(pIDEmpleado) )
            {



                //*(auxIDSector) =  (listaEmpleados + i)->ID_Sector ;

                   //NO FUNCIONA
                 //LE PASO LAS DIRECCIONES DE MEMORIA PARA QUE LA FUNCION SE
                //ENCARGUE DE AGREGARLE EL VALOR

                EMPLEADO_pRetornaIDSectorDelEmpleado(&auxIDSector, &(listaEmpleados + i)->ID_Sector );

                *(pAuxIDSector) = auxIDSector;

                retorno = 1;
                break;

            }
        }
    }

    return retorno;
}


int EMPLEADO_pRetornaIDSectorDelEmpleado(int* auxIDSector,int* IdSector)
{
    int retorno;
    retorno=0;

    if(auxIDSector != NULL && IdSector != NULL)
    {
                        //EL VALOR QUE ESTA DENTRO DE ESA DIRECCION DE MEMORIA
                        //SE LO PASAS AL VALOR DENTRO DE LA DIRECCION DE MEMORIA auxIDSector

        *(auxIDSector) =  *(IdSector) ;
        retorno=1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR, VARIABLES NULL \n");
    }

    return retorno;
}


int EMPLEADO_pBuscaNombre_DelEmpleado_DeLaLista_DeTam_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                         ,int* auxIDEmpleado,char* auxNombreEmpleado)
{
    int retorno;
    retorno = 0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && auxIDEmpleado != NULL && auxNombreEmpleado != NULL)
    {

        for(int i = 0; i < tamListaEmpleados; i++)
        {

            if( (listaEmpleados + i)->is_Empleado_Full && (listaEmpleados + i)->legajo == *(auxIDEmpleado) )
            {


                EMPLEADO_pRetornaNombreDelEmpleado(auxNombreEmpleado,(listaEmpleados + i)->nombre);
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}

int EMPLEADO_pRetornaNombreDelEmpleado(char* auxNombreEmpleado,char* nombreEmpleado)
{
    int retorno;
    retorno=0;

    if(auxNombreEmpleado != NULL && nombreEmpleado != NULL)
    {
        strcpy( auxNombreEmpleado, nombreEmpleado );
        retorno=1;
    }

    return retorno;
}












int NEXO_pReingresaAlmuerzos_DeEmpleado_DadoDeBaja_ConID(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                         ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                         ,int* pAuxIdEmpleado)
{

    int retorno;
    retorno=0;

     if( listaEmpleados != NULL && tamListaEmpleados > 0 && pAuxIdEmpleado != NULL)
     {

         for(int i = 0; i > tamListaEmpleados; i++)
         {

            if(  !EMPLEADO_pEstaEmpleado_DadoDeAlta_(listaEmpleados + i)
                                                            && (listaEmpleados + i)->legajo == *(pAuxIdEmpleado) )
            {

                ALMUERZO_pReingresaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos,&pAuxIdEmpleado);
                retorno = 1;
            }

         }
     }
     else
     {
        printf("\n OCURRIO UN ERROR EN EL INGRESO A LA OPCION \n");
     }

    return retorno;
}


int EMPLEADO_pEstaEmpleado_EnSector_(eEmpleado* listaEmpleados,int tamListaEmpleados,int* pAuxIdEmpleado,int* pAuxIdSector)
{
    int retorno;
    retorno=0;

    int auxIdEmpleado;
    int auxIdSector;
    auxIdEmpleado= *pAuxIdEmpleado;
    auxIdSector= *pAuxIdSector;


    if(listaEmpleados != NULL && tamListaEmpleados > 0 && pAuxIdEmpleado != NULL && pAuxIdSector != NULL)
    {

        for(int i= 0 ; i < tamListaEmpleados; i++)
        {
             //NO IMPORTA SI ESTA DADO DE ALTA O DE BAJA, QUIERO SABER SI EL EMPLEADO PERTENECE A UN SECTOR DETERMINADO
             //SI ESTA DADO DE BAJA O DE ALTA NO IMPORTA APARECERÁ IGUAL

            if( GENERICA_pEsElNumero_IgualQueElNumero_(&(listaEmpleados+i)->legajo
                                                                  ,&auxIdEmpleado)

                        && GENERICA_pEsElNumero_IgualQueElNumero_(&(listaEmpleados+i)->ID_Sector
                                                                                    ,&auxIdSector))

            {
                retorno=1;
                break;
            }

        }

        if(!retorno)
        {
            printf("\n EL EMPLEADO NO ESTA EN EL SECTOR \n");
        }
        else
        {
            printf("\n EL EMPLEADO ESTA EN EL SECTOR \n");
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR A SECTOR\n");
    }

    return retorno;
}



int SECTOR_retornaSector_DelEmpleado_(eSector* listaSectores,int tamlistaSectores,eEmpleado* unEmpleado,eSector* unSector)
{
	eSector auxSector;
	int retorno;
	retorno=0;



	if( listaSectores != NULL && tamlistaSectores > 0)
	{
		for(int i=0;i<tamlistaSectores;i++)
		{

			if(SECTOR_pEstaSector_DadoDeAlta_Y_EmpleadoPerteneceAlSector_( (listaSectores + i) ,&(unEmpleado)->ID_Sector))
			{

				//(*(listaDeJugadores + posicionLibre))
				*unSector = *(listaSectores + i) ;
				retorno = 1;
				break;
			}
		}
	}


	return retorno;
}





int  utn_pCargaAltaAlmuerzo(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                            ,eComida* listaComidas, int tamListaComidas
                            ,eEmpleado* listaEmpleados,int tamListaEmpleados
                            ,eSector* listaSectores,int tamListaSectores
                            ,int* pIdAlmuerzo)
{
	int retorno;
	retorno=0;
	int auxIndice;
	eAlmuerzo auxAlmuerzo;
	int auxIdAlmuerzo;

	 printf("\n\n    ALTA EMPLEADOS      \n");

	//MIENTRAS NO HAYA OCURRIDO ALGO QUE NO SEA ESTO,si no ocurrio nada invalido entro
	//y hago las cosas.
	//if(!(arrayAlmuerzos == NULL || tamAlmuerzos <= 0 || pId == NULL))

	if(listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
	{
		printf("  ALTA ALMUERZO \n\n  ");

        ALMUERZO_BuscaIndiceLibreEnListaDeAlmuerzos_DeTam_(listaAlmuerzos,tamListaAlmuerzos,&auxIndice);

        if(auxIndice == -1)
        {
			printf("\n NO SE ENCONTRO ESPACIO PARA CARGAR UN ALMUERZO NUEVO \n");

			retorno=0;
        }
        else
        {

              auxIdAlmuerzo = *pIdAlmuerzo;

              printf("ID DEL ALMUERZO A ASIGNARSE: %d \n",auxIdAlmuerzo);

		       auxAlmuerzo = utn_pCargaUnAlmuerzo_(listaAlmuerzos,tamListaAlmuerzos
                                                  ,listaComidas,tamListaComidas,listaEmpleados
                                                  ,tamListaEmpleados,listaSectores,tamListaSectores
                                                  ,&retorno,&auxIdAlmuerzo);

              if(!retorno)
              {
                printf("\n  OCURRIO UN ERROR AL DAR DE ALTA EL ALMUERZO ");
                retorno= 0;
              }
              else
              {
                 printf("\n      ALTA ALMUERZO EXITOSA     \n");

                 printf("\n ID DE ALMUERZO ASIGNADO: %d",*pIdAlmuerzo);

                 (*(listaAlmuerzos + auxIndice)) = auxAlmuerzo;
                 (*pIdAlmuerzo)++;
                  retorno=1;

                  //otra opcion
                  //*pId= (*pId) + 1;

                //a lo que le voy a hacer ++ es justamente al resultado de hacer *pId
                //el resultado del parentesis es el valor en esa direccion de memoria.
                //(*pID)++;

                //otra opcion
                //*pId= (*pId) + 1;
               }

            }

        }
        else
        {

                printf(" OCURRIO UN ERROR AL DAR DE ALTA EL ALMUERZO ");
                retorno=0;
        }

	return retorno;
}



eAlmuerzo utn_pCargaUnAlmuerzo_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                        ,eComida* listaComidas, int tamListaComidas
                        ,eEmpleado* listaEmpleados,int tamListaEmpleados
                        ,eSector* listaSectores,int tamListaSectores
                        ,int* auxRetorno,int* pAuxIDAlmuerzo)
{
    int retorno;
    retorno= 0;
    int edadLimite;
    edadLimite = 120;
    eAlmuerzo auxAlmuerzo;
    int auxLeg_Empleado;

    NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores);

	if(utn_pIngresoDeElementoTipoEntero_(&auxLeg_Empleado, "\n INGRESE LEGAJO DEL EMPLEADO: ", "error",1,20, 2) &&

        COMIDA_pMuestraListaDeComidas_DeTam_(listaComidas,tamListaComidas) &&

        utn_pIngresoDeElementoTipoEntero_(&auxAlmuerzo.id_Comida, "\n INGRESE ID DE LA COMIDA: ", "error",1000,1004, 2)&&

	    utn_pIngresoDeElementoTipoEntero_(&auxAlmuerzo.fecha_De_Almuerzo.dia, "\n INGRESE DIA: ", "\n ERROR",1 , 31, 2) &&

	    utn_pIngresoDeElementoTipoEntero_(&auxAlmuerzo.fecha_De_Almuerzo.mes, "\n MES DEL ALMUERZO: ", "\n ERROR",1 , 12, 2) &&

	    utn_pIngresoDeAnioTipoEntero_(&auxAlmuerzo.fecha_De_Almuerzo.anio ," DEL ALMUERZO " ,"\n ERROR" ,1900 ,2030 , 2))

    {
             auxAlmuerzo.leg_Empleado = auxLeg_Empleado;
             auxAlmuerzo.id_Almuerzo = *pAuxIDAlmuerzo;

              EMPLEADO_pBuscaNombreEmpleado_EnListaEmpleados_DeTam_(listaEmpleados,tamListaEmpleados
                                                                   ,&auxAlmuerzo.nombre_Empleado,&auxLeg_Empleado);

              EMPLEADO_pBuscaApellidoEmpleado_EnListaEmpleados_DeTam_( listaEmpleados,tamListaEmpleados
                                                                      ,&auxLeg_Empleado,&auxAlmuerzo.apellido_Empleado);

              auxAlmuerzo.is_Almuerzo_Full = FULL;
              auxAlmuerzo.is_Almuerzo_Empty = EMPTY;
              auxAlmuerzo.is_PosicionLista = LA_POSICION_ESTUVO_CARGADA;

              retorno = 1;

              *auxRetorno = retorno;
    }
    else
    {

            printf(" OCURRIO UN ERROR AL DAR DE ALTA EL ALMUERZO ");
            retorno=0;

            *auxRetorno = retorno;
    }

	//printf("ingrese fecha dd/mm/aaaa: n")

	//printf("ingrese fecha dd/mm/aaaa: n");
    //scanf("%d/%d/%d",&unaEstructura->fechaIngreso.dia,&(unaEstructura)->fechaIngreso.mes,&auxEmpleado.fechaIngreso.anio);

	return auxAlmuerzo;
}


int NEXO_MuestraListaDeAlmuerzos_DeTam_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                      ,eSector* listaSectores,int tamListaSectores
                                      ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                      ,eComida* listaComidas,int tamListaComidas)
{
    int retorno;
    int i;
    retorno= 0;
    int flag;
    flag=1;
    int contadorAlmuerzosSinInicializar;
    contadorAlmuerzosSinInicializar=0;

    int contadorAlmuerzosDadosDeBaja;
    contadorAlmuerzosDadosDeBaja=0;


    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
        && listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {
        for(i=0; i < tamListaAlmuerzos; i++)
        {
            //O SEA QUE SI LA POSICION ES IGUAL A 0 ENTRA Y SUMA POSICIONES LIBRES Y VACIAS
            //SI EL CONTADOR DE DE ELEMENTOS ES IGUAL A EL TAM DE EMPLEADOS
            //QUIERE DECIR QUE NO HAY EMPLEADOS CARGADOS. TODA LA LISTA ESTA LIBRE
            if( (listaAlmuerzos + i)->is_PosicionLista != LA_POSICION_ESTUVO_CARGADA)
            {
                contadorAlmuerzosSinInicializar++;

            }
        }

        if(contadorAlmuerzosSinInicializar == tamListaAlmuerzos)
        {
            printf(" NUNCA SE CARGARON ALMUERZOS, LA LISTA ESTA VACIA \n");
            flag=0;
            retorno=0;
        }

        for(i=0; i < tamListaAlmuerzos; i++)
        {
            //O SEA QUE SI LA POSICION ES IGUAL A 0 ENTRA Y SUMA POSICIONES LIBRES Y VACIAS
            //SI EL CONTADOR DE DE ELEMENTOS ES IGUAL A EL TAM DE EMPLEADOS
            //QUIERE DECIR QUE NO HAY EMPLEADOS CARGADOS. TODA LA LISTA ESTA LIBRE
            if( !(listaAlmuerzos + i)->is_Almuerzo_Full)
            {
                contadorAlmuerzosDadosDeBaja++;
            }
        }
                                                    //esto significa que nunca entro al
                                                    //if que cambio a 0 el flag porque
                                                    //encontro empleados cargados
            if(contadorAlmuerzosDadosDeBaja == tamListaAlmuerzos && flag)
            {

                printf("\n ATENCION: NO EXISTEN ALMUERZOS EN LA LISTA, TODOS FUERON DADOS DE BAJA. \n");

            }
            else
            {

                puts("\n                                                       LISTA DE ALMUERZOS                                                                  \n");

                 puts("----------------------------------------------------------------------------------------------------------------------------------------------");
                printf("   ID ALMUERZO   |   ID LEGAJO   |   NOMBRE    |   APELLIDO    |    ID COMIDA   |    NOMBRE COMIDA   |   FECHA ALMUERZO   |   NOMBRE SECTOR  |");
                puts("\n----------------------------------------------------------------------------------------------------------------------------------------------");

                for (int i = 0; i < tamListaAlmuerzos ; i++)
                {
                          //listaDeEstructuras + i)->isEmpty
                    if( ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(listaAlmuerzos + i))

                    {
                            NEXO_MuestraUnAlmuerzo_DeLaListaDeAlmuerzos_( listaAlmuerzos + i,listaSectores,tamListaSectores
                                                                         ,listaEmpleados,tamListaEmpleados,listaComidas
                                                                         ,tamListaComidas);
                        puts("-------------------------------------------------------------------------------------------------------------------------------------------------|");
                        flag=1;
                        retorno=1;
                    }

                }

                if(!flag)
                {
                    utn_mostrarMensaje("\n  ERROR AL MOSTRAR EMPLEADOS \n");
                }
            }

    }
    else
    {
        utn_mostrarMensaje("\n OCURRIO UN ERROR INESPERADO \n");

    }

    return retorno;

}



int NEXO_MuestraUnAlmuerzo_DeLaListaDeAlmuerzos_(eAlmuerzo* unAlmuerzo
                                                ,eSector* listaSectores,int tamListaSectores
                                                ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                ,eComida* listaComidas,int tamListaComidas)

{
    int retorno;
    retorno=0;
    int auxIDSector;
    char auxNombreComida[20];
    char auxNombreSector[20];
    char auxNombreEmpleado[20];
    char auxApellidoEmpleado[20];

    //O PREGUNTO ASI POR SEPARADO O ME TRAIGO LAS CUATRO ESTRUCTURAS ANTES DEL IF POR SEPARADO

    if(unAlmuerzo != NULL && listaEmpleados != NULL && tamListaEmpleados > 0
       && listaSectores != NULL && tamListaSectores > 0 && listaComidas != NULL && tamListaComidas > 0)
    {

        if(EMPLEADO_pBusca_IDSectorDelEmpleadoEn_ListaEmpleados_DeTam_(listaEmpleados,tamListaEmpleados
                                                                     ,&(unAlmuerzo)->leg_Empleado,&auxIDSector)

           && SECTOR_pBuscaNombre_DelSector_enListaSectores_DeTam_(listaSectores,tamListaSectores
                                                                   ,&auxIDSector,auxNombreSector)

          && EMPLEADO_pBuscaNombre_DelEmpleado_DeLaLista_DeTam_(listaEmpleados,tamListaEmpleados
                                                             ,&(unAlmuerzo)->leg_Empleado,auxNombreEmpleado)

          && EMPLEADO_pBuscaApellidoEmpleado_EnListaEmpleados_DeTam_(listaEmpleados,tamListaEmpleados
                                                                    ,&(unAlmuerzo)->leg_Empleado,auxApellidoEmpleado)

           && COMIDA_pBuscaNombre_DeComida_EnListaComidas_DeTam_(listaComidas,tamListaComidas
                                                                ,&(unAlmuerzo)->id_Comida ,auxNombreComida) )
        {

            //FALTA BUSCAR PRECIO Y NOMBRE DEL SECTOR

            printf("\n %2d       %13d        %s   %s        %5d    %s          %02d/%02d/%02d              %d      %s\n"
                                                                                            ,unAlmuerzo->id_Almuerzo
                                                                                            ,unAlmuerzo->leg_Empleado
                                                                                            ,auxNombreEmpleado
                                                                                            ,auxApellidoEmpleado
                                                                                            ,unAlmuerzo->id_Comida
                                                                                            ,auxNombreComida
                                                                                            ,(*(unAlmuerzo)).fecha_De_Almuerzo.dia
                                                                                            ,unAlmuerzo->fecha_De_Almuerzo.mes
                                                                                            ,unAlmuerzo->fecha_De_Almuerzo.anio
                                                                                            ,auxIDSector
                                                                                            ,auxNombreSector);

            retorno=1;

        }
        else
        {

            printf("   ATENCION: OCURRIO UN ERROR NO SE PUEDE MOSTRAR EL ALMUERZO \n");

        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;

}


void utn_mostrarMensaje(char mensaje[])
{
	printf("%s",mensaje);
}


int ALMUERZO_pBajaTodosAlmuerzos_DeEmpleado_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,eEmpleado* unEmpleado)
{
    int retorno;
    retorno=0;


    if(listaAlmuerzos != NULL && tamListaAlmuerzos > 0 && unEmpleado != NULL )
    {
            for(int i = 0; i < tamListaAlmuerzos; i++)
            {
                if(ALMUERZO_pEstaAlmuerzo_DadoDeAlta_Y_PerteneceAlEmpleado_(listaAlmuerzos + i,&(unEmpleado)->legajo))
                {
                    ALMUERZO_pBajaUnAlmuerzo_( listaAlmuerzos + i);
                    retorno=1;

                }

            }

            if(retorno)
            {

                    printf("\n\n ALMUERZOS DEL EMPLEADO: %s %s CON ID: %d DADOS DE BAJA EXITOSAMENTE \n\n\n",unEmpleado->nombre
                                                                                                            ,unEmpleado->apellido
                                                                                                            ,unEmpleado->legajo);

            }
            else
            {

                    printf("\n\n ALMUERZOS DEL EMPLEADO: %s %s CON ID: %d \n\n NO TIENE ALMUERZOS CARGADOS \n\n\n"
                                                                               ,unEmpleado->nombre
                                                                               ,unEmpleado->apellido
                                                                               ,unEmpleado->legajo);
                     retorno=0;
            }
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR A LA OPCION ");
    }

    return retorno;
}


