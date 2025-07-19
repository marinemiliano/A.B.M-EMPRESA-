#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;


#endif // FECHA_H_INCLUDED

/*
int NEXO_pReingresaEmpleado_YSusAlmuerzos_(eEmpleado* listaEmpleados,int tamListaEmpleados
                                          ,eSector* listaSectores,int tamListaSectores
                                          ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
    eEmpleado auxEmpleado;
    int retorno;
    retorno=0;
    int posicionLibre;
    int auxIdEmpleado;
    int seguir;
    char salir;
    int auxIndiceEmpleado;

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
       && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
   {

            do
            {
                 system("cls");

                 if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n DESEA REINGRESAR UN EMPLEADO?"
                                                                 "\n SI REINGRESA EL EMPLEADO TAMBIEN SE REINGRESARAN SUS ALMUERZOS."
                                                                 "\n\n REINGRESAR EMPLEADO S/N: "
                                                                 ,"\n HA OCURRIDO UN ERROR\n",2)

                  && salir == 'S' || salir == 's')

                 {
                     system("cls");
                     if(!NEXO_pReingesaEmpleado_DadoDeDeBaja(listaEmpleados,tamListaEmpleados
                                                            ,listaSectores,tamListaSectores
                                                           ,&auxIdEmpleado))
                     {

                          printf("\n OCURRIO UN ERROR AL REINGRESAR EL ID DEL EMPLEADO,"
                                 "ID FUERA DEL RANGO \n");

                          printf("\n ATENCION: EL EMPLEADO ELEGIDO ESTA DADO DE ALTA \n");

                          printf("\n ATENCION: EL EMPLEADO NO HA SIDO REINGRESADO \n");


                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                            ,"\n DESEA REINGRESAR OTRO EMPLEADO? S/N: "
                                                            ,"HA OCURRIDO UN ERROR\n",2)

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

                         if(!ALMUERZO_pReingresaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos
                                                                                ,&auxIdEmpleado))
                         {

                                 if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                ,"\n DESEA REINGRESAR OTRO EMPLEADOUUUU? S/N: "
                                                                ,"HA OCURRIDO UN ERROR\n",2)

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

                              printf("\n EMPLEADO Y SUS ALMUERZOS REINGRESADOS CON EXITO \n");

                              if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                            ,"\n DESEA REINGRESAR OTRO EMPLEADO? S/N: "
                                                            ,"HA OCURRIDO UN ERROR\n",2)

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
                     seguir='n';
                  }

             }while(seguir == 's' || seguir == 'S');
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;
}


int NEXO_pReingesaEmpleado_DadoDeDeBaja(eEmpleado* listaEmpleados,int tamListaEmpleados
                                        ,eSector* listaSectores,int tamListaSectores
                                        ,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;
    int posicionLibre;
    int auxIdEmpleado;
    int seguir;
    char salir;
    int auxIndiceEmpleado;

    //MIENTRAS NO HAYA OCURRIDO ALGO QUE NO SEA ESTO,si no ocurrio nada invalido entro
    //y hago las cosas.

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0)
    {

         //if(!EMPLEADO_pHayEmpleadosDadosDe_Alta(listaEmpleados,tamListaEmpleados))
         if(EMPLEADO_pHayEmpleadosDadosDe_Baja(listaEmpleados,tamListaEmpleados))
         {

            do
            {
            //o sea que va desde el 0 hasta el infinito y hay lugar en el array

                if(NEXO_pMuestraEmpleados_DadosDeBaja_DOS(listaEmpleados,tamListaEmpleados
                                                        ,listaSectores,tamListaSectores))
                {

                    if(!utn_pIngresoDeElementoTipoEntero_(&auxIdEmpleado, "\n INGRESE EL ID DEL EMPLEADO A REINGRESAR "
                                                          , "\n ERROR AL INGRESAR EL ID DEL EMPLEADO \n"
                                                          , MIN_ID_EMPLEADO, MAX_ID_EMPLEADO, 2))
                    {

                        seguir='n';

                    }
                    else
                    {
                          system("cls");
                          /// ACA BUSCO EL INDICE EN EL CUAL ESTA EL EMPLEADO PARA PODER MOSTRARLO EN LA FUNCION QUE LE SIGUE
                          EMP_pBuscaPosicionDelEmpleado_EnListaEmpleados_PorId_(listaEmpleados,tamListaEmpleados
                                                                                ,&auxIndiceEmpleado,&auxIdEmpleado);

                          /// ACA PUEDE IR UNA FUNCION QUE MUESTRE ESE EMPLEADO DADO DE BAJA
                          ///SIRVE PARA MOSTRARLO SI ESTA DADO DE ALTA TAMBIEN POR SI LAS DUDAS
                          NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(listaEmpleados+auxIndiceEmpleado
                                                                      ,listaSectores,tamListaSectores);

                          if(!NEXO_pBuscaEmpleado_SiEstaDadoDeBaja_ConID_(listaEmpleados,tamListaEmpleados,&auxIdEmpleado))
                          {

                                    /// SI SE INGRESA UN ID EMPLEADO QUE CUMPLE EL RANGO PERO QUE NO APARECE
                                    ///EN MOSTRAR EMPLEADOS DADOS DE BAJA, ENTONCES ESTA DADO DE ALTA
                                    ///ENTONCES PARAMOS EL PROGRAMA Y DECIMOS QUE EL EMPLEADO BUSCADO
                                    ///NO ESTA DADO DE  BAJA

                                    seguir='n';
                          }
                          else
                          {

                                system("cls");
                                if(EMPLEADO_pReingresaEmpleado_DadoDeBaja_ConID_(listaEmpleados,tamListaEmpleados
                                                                                 ,&auxIdEmpleado))
                                {

                                     retorno=1;
                                     *pAuxIdEmpleado=auxIdEmpleado;
                                     seguir='n';

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

                        system("cls");
                        printf("\n OCURRIO UN ERROR AL MOSTRAR EMPLEADOS DADOS DE BAJA. \n");

                        //OPCION SALIR SI O SI
                   }

            }
            while(seguir == 's' ||seguir == 'S');

        }
        else
        {

            system("cls");
            printf("\n ATENCION: NO EXISTEN EMPLEADOS PARA REINGRESAR. \n"
                   "\n TODOS LOS EMPLEADOS DE LA EMPRESA SE ENCUENTRAN DADOS DE ALTA \n");

            //MENU DE SALIR SI O SI AQUI
        }
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;
}

*/





/*

    case 2:

                              if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA TODOS LOS EMPLEADOS "
                                                                         "DE UN SECTOR DETERMINADO? S/N: "
                                                                        ,"\n HA OCURRIDO UN ERROR\n",2)
                                                                        && salir == 'S' || salir == 's')
                            {

                                    system("cls");
                                    if(!NEXO_pBajaTodosEmpleados_DeUnSector_DOS(listaEmpleados,tamListaEmpleados
                                                                               ,listaSectores,tamListaSectores))
                                    {

                                      {
                                         if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                    ,"\n\n DESEA VOLVER AL MENU BAJA EMPLEADO? S/N: "
                                                                                    ,"\n HA OCURRIDO UN ERROR\n",2)
                                            && salir == 'S' || salir == 's')

                                            {
                                                system("cls");
                                                seguir='S';
                                            }
                                            else
                                            {
                                                system("cls");
                                                seguir='n';
                                            }

                                      }

                                    }
                                    else
                                    {
                                        printf("\n EMPLEADOS DADOS DE BAJA EXITOSAMENTE  \n");
                                        retorno=1;

                                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                        ,"\n\n DESEA VOLVER AL MENU BAJA EMPLEADO? S/N: "
                                                                                        ,"\n HA OCURRIDO UN ERROR\n",2)
                                                && salir == 'S' || salir == 's')

                                        {
                                            system("cls");
                                            seguir='S';
                                        }
                                        else
                                        {
                                            system("cls");
                                            seguir='n';
                                        }
                                      }

                             }
                              else
                             {
                                system("cls");
                                seguir='s';
                             }
                break;

                case 3:

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA TODOS LOS EMPLEADOS "
                                                                         "DE LA EMPRESA? S/N: "
                                                                        ,"\n HA OCURRIDO UN ERROR\n",2)
                                                                        && salir == 'S' || salir == 's')
                            {
                                system("cls");
                                if(!EMPLEADO_pBajaTodosLosEmpleados_DeTodosLosSectores(listaEmpleados,tamListaEmpleados))
                                {

                                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                        ,"\n DESEA VOLVER AL MENU BAJA EMPLEADO? S/N: "
                                                                                        ,"\n HA OCURRIDO UN ERROR\n",2)
                                        && salir == 'S' || salir == 's')

                                        {
                                            system("cls");
                                            seguir='S';
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

                                    if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                    ,"\n DESEA VOLVER AL MENU BAJA EMPLEADO? S/N: "
                                                                                    ,"\n HA OCURRIDO UN ERROR\n",2)
                                        && salir == 'S' || salir == 's')

                                    {
                                        system("cls");
                                        seguir='S';
                                    }
                                    else
                                    {
                                        system("cls");
                                        seguir='n';
                                    }
                                }

                            }
                            else
                            {

                                system("cls");
                                seguir='S';

                            }
                break;

                case 4:

                             system("cls");

                             NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados
                                                                ,listaSectores,tamListaSectores);

                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                            ,"\n DESEA VOLVER AL MENU BAJA EMPLEADO? S/N: "
                                                                            ,"\n HA OCURRIDO UN ERROR\n",2)
                                                && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='S';
                                }
                                else
                                {
                                    system("cls");
                                    seguir='n';
                                }
                break;

                case 5:

                                system("cls");

                                 NEXO_pMuestraEmpleados_DadosDeBaja_DOS(listaEmpleados,tamListaEmpleados
                                                                     ,listaSectores,tamListaSectores);

                                 if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                                ,"\n DESEA VOLVER AL MENU BAJA EMPLEADO? S/N: "
                                                                                ,"\n HA OCURRIDO UN ERROR\n",2)
                                        && salir == 'S' || salir == 's')

                                {
                                    system("cls");
                                    seguir='S';
                                }
                                else
                                {
                                    system("cls");
                                    seguir='n';
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

*/

//BAJASSS

/*
{

    eEmpleado auxEmpleado;
    int retorno;
    retorno=0;
    int indice;
    indice=-1;
    int auxID;
    auxID=-1;
    int flag;
    flag=0;
    char salir;
    char seguir;

    system("cls");

    if(listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0
            && listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        do
        {

           if(NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores))
           {

                 //se llama nuevamente. es por el printf que si no hay
                //empleados si lo coloco antes del if aparece igual

                ///BANDERA EN 1 SI HAY ESTRUCTURAS DADAS DE ALTA PARA LISTAR
                flag = 1;
           }
           if(flag)
           {

                utn_pIngresoDeElementoTipoEntero_(&auxID,"\n INGRESE EL LEGAJO DEL EMPLEADO A DAR DE BAJA:  "
                                                  ,"\n ERROR, REINGRESE ID DEL EMPLEADO A DAR DE BAJA: ",
                                                  MIN_ID_EMPLEADO, MAX_ID_EMPLEADO, REINTENTOS);

                EMP_pBuscaPosicionDelEmpleado_EnListaEmpleados_PorId_(listaEmpleados,tamListaEmpleados,&indice,&auxID);

                if(indice == -1)
                {
                    system("cls");

                    puts("\n NO EXISTE EMPLEADO CON ESE ID EN LA LISTA DE EMPLEADOS ");
                     retorno=0;

                    if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir
                                                                    ,"\n DESEA SALIR ? S/N ",
                                                                    "\n HA OCURRIDO UN ERROR\n",2)

                            &&

                            (salir == 'S' || salir == 's') )

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
                    system("cls");

                    //CON ESTA FUNCION INTENTE ENCONTRAR LA ESTRUCTURA Y RETORNARLA PARA MOSTRARLA PERO NO FUNCIONO
                    //auxEmpleado = EMP_retornaEstructuraPorID_(listaEmpleados,tamListaEmpleados,&retorno, auxID);

                    printf("\n  EMPLEADO SELECCIONADO \n");

                    //UTILICÉ PASAR LA ESTRUCTURA ENCONTRADA CON SU INDICE Y FUNCIONÓ
                    NEXO_pMuestraUnaEstructura_ENCABEZADO_PROPIO(listaEmpleados+indice,listaSectores,tamListaSectores);

                    if(utn_pRespuestaBooleanaSiUno_NoCero("\n\n   DESEA ELIMINAR EMPLEADO? \n"
                                                          "\n   SI ELIMINA AL EMPLEADO SUS ALMUERZOS TAMBIEN SE ELIMINARAN \n"
                                                          "\n   ELIJA UNA OPCION: S/N "
                                                          , " HA OCURRIDO UN ERROR \n",2))
                    {
                        system("cls");

                        ///IMPORTANTE!! PARA QUE LAS DOS FUNCIONES DEN BIEN TIENEN QUE ESTAR ASI, SIN NEGAR LAS FUNCIONES
                        /// ASI SE RESPETA EL && ENTRE LAS FUNCIONES DEVUELVE RETORNO 1 Y 1 Y SINO SALE POR EL ELSE

                        if( (ALMUERZO_pBajaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos,&auxID)
                           && EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(listaEmpleados+indice)))
                        {


                            puts("\n  SE HA DADO DE BAJA EL EMPLEADO Y SUS ALMUERZOS \n");

                            //EMPLEADO_pBajaEmpleado_CambiaLasBanderasAEmpleado_DadoDeBaja_(listaEmpleados+indice);

                            //ALMUERZO_pBajaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos,&auxID);

                            auxID=-1;
                            indice=-1;
                            retorno = 1;
                            flag = 0;

                            if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA OTRO EMPLEADO? S/N: ",
                                                                            "HA OCURRIDO UN ERROR\n",2)
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
                            printf("\n OCURRIO UN ERROR AL DAR DE BAJA EL EMPLEADO \n");
                            retorno=0;

                             if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA OTRO EMPLEADO? S/N: ",
                                "HA OCURRIDO UN ERROR\n",2)
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

                    }
                    else
                    {
                        system("cls");

                        printf("\n  EL EMPLEADO NO FUE ELIMINADO \n");
                        retorno=0;

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE BAJA OTRO EMPLEADO? S/N: ",
                                "HA OCURRIDO UN ERROR\n",2)
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
                }

            }
            else
            {

                retorno=0;
                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n PRESIONE LA LETRA S PARA SALIR: ",
                        "/n HA OCURRIDO UN ERROR\n",2)

                        &&

                 (salir == 'S' || salir == 's'))

                {
                    system("cls");
                    seguir='n';
                }
                else
                {
                    system("cls");
                    seguir='n';
                }
            }

        }
        while(seguir == 'S' || seguir == 's');
    }

    return retorno;
}

 ////

 /*
                int EMPLEADO_pMenuReingesar_EmpleadosDadosDeBaja(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                ,eSector* listaSectores,int tamListaSectores
                                                ,listaAlmuerzos,tamListaAlmuerzos)

                if(!NEXO_pReingresa_EmpleadoDadoDeBaja_DOS(listaEmpleados,tamListaEmpleados
                        ,listaSectores,tamListaSectores))
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
                }
                else
                {
                    if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA DAR DE ALTA OTRO EMPLEADO? S/N: "
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
                */


