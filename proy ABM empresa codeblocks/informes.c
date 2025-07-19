
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
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

#include "data_Warehouse.h"
#include "eEmpleado.h"
#include "eSector.h"
#include "informes.h"
#include "almuerzo.h"
/*
int NEXO_pMenu_CargaListaEmpleados_O_InicializaListaEmpleadosVacia(eEmpleado* listaEmpleados,int tamListaEmpleados
                                                                   ,eSector* listaSectores,int tamlistaSectores)

{
    int opcion;
    char seguir;
    char salir;
    int retorno;
    retorno=-1;

    if( listaEmpleados != NULL && tamListaEmpleados > 0 && listaSectores != NULL && tamListaSectores > 0)
    {

    do
    {

        utn_MenuIngresarLaOpcion_(&opcion
                                  ,"\n\n CARGA DE EMPLEADOS POR DEFECTO O CARGA DE LISTA VACIA    \n"
                                  ,"\n INGRESE UNA OPCION: "
                                  ," "
                                  ,"ERROR AL INGRESAR EL NUMERO \n",1,3,2
                                  ,"\n 1.CARGAR LISTA VACIA \n"
                                  ," 2.CARGAR LISTA CON EMPLEADOS POR DEFECTO \n"
                                  ," 3.SALIR "
                                  ," "
                                  ," "
                                  ," "
                                  ," ","","");

                                  system("cls");

        switch(opcion)
        {
            case 1:

                        utn_mostrarMensaje("\n  CREAR LISTA VACIA DE EMPLEADOS \n");

                    //la funcion es 1 entra al if 0 NO ENTRA Y sale por el else
                    // si es false (0) entonces doble negacion y sale por el else.
                    if(!utn_pRespuestaBooleanaSiUno_NoCero("\n\n CREAR LISTA VACIA DE EMPLEADOS PRESIONE S \n "
                                                            "\n  CANCELAR LA ACCION PRESIONE N \n"
                                                            "\n INGRESE UNA OPCION S/N: "
                                                            ,"\n HA OCURRIDO UN ERROR \n",2))
                    {
                        system("cls");

                        retorno=-1;

                        utn_mostrarMensaje("\n\n ACCION CANCELADA: NO SE HA CREADO LA LISTA VACIA \n");

                         if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR DEL MENU ACTUAL? S/N: "
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

                        system("cls");

                         utn_mostrarMensaje("\n LISTA VACIA DE EMPLEADOS CREADA \n");

                         utn_pInicializarEstructuras_DeTam_(listaEmpleados,tamListaEmpleados);

                           if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR DEL MENU ACTUAL? S/N: "
                                                                                ,"\n HA OCURRIDO UN ERROR \n",2)
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

                            utn_mostrarMensaje("\n CARGA DE LISTA DE EMPLEADOS PREDETERMINADA \n");

                            //la funcion es 1 entra al if 0 NO ENTRA Y sale por el else
                            // si es false (0) entonces doble negacion y sale por el else.
                            if(!utn_pRespuestaBooleanaSiUno_NoCero("\n\n CREAR LISTA DE EMPLEADOS PREDETERMINADA PRESIONE S \n "
                                                                    "\n VOLVER AL MENU ANTERIOR PRESIONE N \n"
                                                                    "\n INGRESE UNA OPCION S/N: "
                                                                    ,"\n HA OCURRIDO UN ERROR \n",2))
                            {

                                 retorno=-1;

                                 system("cls");

                                utn_mostrarMensaje("\n NO SE HA CARGADO LA LISTA PREDETERMINADA \n");

                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR DEL MENU ACTUAL? S/N: "
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

                                 system("cls");

                                 utn_pCargaEmpleadosPorDefecto_DeTam_OPCION_UNO(listaEmpleados,tamListaEmpleados);


                                 utn_mostrarMensaje("\n LISTA CARGADA CON EXITO \n\n");

                                 NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados
                                                               ,listaSectores,tamlistaSectores);


                                if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n\n DESEA SALIR DEL MENU ACTUAL? S/N: "
                                                                                ,"\n HA OCURRIDO UN ERROR \n",2)
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

                            printf("\n  ****     SALIR     ****   \n");

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
    }

    return retorno;

}
*/

/*
int NEXO_menuInformes_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,eSector* listaSectores,int tamListaSectores
                     ,eEmpleado* listaEmpleados,int tamListaEmpleados,eComida* listaComidas,int tamListaComidas)
{
   int retorno;
   char salir;
   retorno = -1;
   int opcion;
   char seguir;

   do{
        utn_MenuIngresarLaOpcion_(&opcion
                                  ,"\n\n MENU PRINCIPAL GESTION DE EMPLEADOS     \n"
                                  ,""
                                  ,"\n INGRESE OPCION DEL 1 AL 6: "
                                  ," OCURRIO UN ERROR \n"
                                  ,1,9,2
                                  ,"\n 1.ALTA EMPLEADO\n"
                                  ," 2.BAJA EMPLEADO\n"
                                  ," 3.MODIFICAR EMPLEADO\n"
                                  ," 4.LISTAR EMPLEADO\n"
                                  ," 5.INFORMES EMPLEADO\n"
                                  ," 6.OTROS \n"
                                  ," "
                                  ,"9.SALIR"
                                  ,"");

                              system("cls");

        switch(opcion)
        {
            case 1:
                    utn_TotalElementosEn_PorSector_(listaEmpleados,tamListaEmpleados
                                                    ,listaSectores,tamListaSectores);

                     utn_SectorDe_ConMejorSueldo_DeTam_(listaSectores,tamListaSectores
                                                        ,listaEmpleados,tamListaEmpleados);

                    utn_actualizarElementosDeLaLista_SegunPorcentaje(listaEmpleados,tamListaEmpleados
                                                                     ,listaSectores,tamListaSectores);

                    utn_mayorElementoDeLaEstructura_(listaSectores,tamListaSectores
                                                     ,listaEmpleados,tamListaEmpleados);

            break;

            case 2:

                    utn_totalGastosEnComidasPorSector_(listaAlmuerzos,tamListaAlmuerzos,listaSectores,tamListaSectores
                                                        ,listaEmpleados,tamListaEmpleados,listaComidas,tamListaComidas);

            break;

            case 3:

                    utn_cantidadDeEmpleadosPorSector_(listaSectores,tamListaSectores,listaEmpleados,tamListaEmpleados);

            break;

            case 4:

                    utn_cantidadDeAlmuerzosPorSector_(listaAlmuerzos,tamListaAlmuerzos,
                                                      listaSectores,tamListaSectores
                                                      ,listaEmpleados,tamListaEmpleados);

            break;

            case 5:

                    utn_descontarAlmuerzoAEmpleado(listaAlmuerzos,tamListaAlmuerzos,listaSectores,tamListaSectores
                                                   ,listaEmpleados,tamListaEmpleados,listaComidas,tamListaComidas);

            break;

            case 6:

                    utn_sectorQueMasEligeLaComidaSeleccionada_(listaAlmuerzos,tamListaAlmuerzos
                                                               ,listaSectores,tamListaSectores
                                                               ,listaEmpleados,tamListaEmpleados
                                                               ,listaComidas,tamListaComidas);

            break;

            case 7:

                    utn_totalGastosEnComidasPorSector_(listaAlmuerzos,tamListaAlmuerzos,listaSectores,tamListaSectores
                                                        ,listaEmpleados,tamListaEmpleados,listaComidas,tamListaComidas);

                    utn_comidaPreferidaDelSector_(listaAlmuerzos,tamListaAlmuerzos,listaSectores,tamListaSectores
                                                 ,listaEmpleados,tamListaEmpleados,listaComidas,tamListaComidas);


                    utn_cantidadDeComidasPorSector_(listaAlmuerzos,tamListaAlmuerzos,listaSectores,tamListaSectores
                                                    ,listaEmpleados,tamListaEmpleados,listaComidas,tamListaComidas);
            break;

            case 8:
                        printf("\n  ****     SALIR     ****   \n");

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&salir,"\n DESEA SALIR? s/n ",
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

                        printf("\n OPCION INVALIDA \n");

                        if(utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(&seguir,"\n DESEA PERMANECER EN EL MENU PRINCIPAL? s/n "
                                                                        ,"\n HA OCURRIDO UN ERROR \n",2))
                        {

                            system("cls");
                            seguir=toupper(seguir);

                        }
                        else
                        {

                            seguir='n';
                        }
            break;

        }

    }while(seguir =='S'|| seguir == 's');



	 return retorno;
}




int utn_CantidadElementosQueHayDe_EnUnaDeLasEstructurasDe_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras)
{
	int retorno;
	int i;
	int auxSector;
	int contSectores;
	char descripcion[20];
	contSectores=0;
	retorno = 0;

	if( listaDeEstructuras != NULL && tamListaDeEstructuras > 0 && otraListaDeEstructuras != NULL && tamListaDeEstructuras > 0)
	{

        SECTOR_pMuestraSectores_DeTam_UNO(otraListaDeEstructuras,tamOtraListaDeEstructuras);

		utn_pIngresoDeElementoTipoEntero_( &auxSector, "\n INGRESE SECTOR DEL CUAL DESEA OBTENER LA CANTIDAD DE EMPLEADOS: ", "\n ERROR", 500, 504, 2);

		utn_DescripcionDeLaEstructuraConElId_enLista_DeTam_(auxSector,otraListaDeEstructuras,tamOtraListaDeEstructuras,descripcion);

		for(i=0; i < tamListaDeEstructuras; i++)
		{
			if( (listaDeEstructuras + i)->ID_Sector == auxSector && (listaDeEstructuras + i)->is_Empleado_Full == FULL)
			{
				contSectores++;
				retorno=1;
			}
		}

		if(contSectores > 0)
		{
			printf("\n EL SECTOR %d ES: %s\n\n CANTIDAD DE EMPLEADOS EN EL SECTOR: %d",auxSector,descripcion,contSectores);
		}
		else
		{
			printf("\n EL SECTOR %d ES: %s. \n\n NO EXISTEN EMPLEADOS EN EL SECTOR.\n\n",auxSector,descripcion);
		}

	}

	return retorno;
}
*/

/*
int utn_actualizarElementosDeLaLista_SegunPorcentaje(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras)
{
    int retorno;
    retorno=0;
    int auxSector;
    float porcentajeAIncrementar;

    SECTOR_pMuestraListaSectores_DeTam_UNO(otraListaDeEstructuras,tamOtraListaDeEstructuras);

    utn_pIngresoDeElementoTipoEntero_( &auxSector, "\n INGRESE SECTOR EL SECTOR AL CUAL SE LE INCREMENTAN LOS SUELDOS: ", "\n ERROR", 500, 504, 2);

    utn_pIngresoDeElementoTipoFlotante_( &porcentajeAIncrementar, "\n INGRESE EL INCREMENTO PORCENTUAL QUE DESEA INCREMENTAR DE 1 A 100: ", "\n ERROR", 1, 100, 2);

        for(int i = 0; i < tamListaDeEstructuras; i++)
		{
			if( (*(listaDeEstructuras + i)).ID_Sector == auxSector && (listaDeEstructuras + i)->is_Empleado_Full == FULL)
			{
				utn_incrementaElemento_ConElPorcentaje_( &(listaDeEstructuras + i)->sueldo, porcentajeAIncrementar);
				retorno=1;
			}
		}



		NEXO_pMuestraEstructuras_DeTam_DOS(listaDeEstructuras,tamListaDeEstructuras,otraListaDeEstructuras,tamOtraListaDeEstructuras );

    return retorno;
}
*/


int utn_incrementaElemento_ConElPorcentaje_(float* elementoAIncrementarPorPorcentaje,float pPorcentaje)
{
    int retorno;
    retorno=0;
    float incremento;

    if(elementoAIncrementarPorPorcentaje != NULL)
    {
        incremento = ( ((*elementoAIncrementarPorPorcentaje) * pPorcentaje)  / 100  ) +  (*elementoAIncrementarPorPorcentaje);

        *elementoAIncrementarPorPorcentaje = incremento;

        retorno = 1;
    }

    return retorno;
}


int utn_TotalElementosEn_PorSector_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras)
{
	int retorno;
	retorno=0;
    float totalSector;
	float total;
	total=0;

	printf("\n INFORME DE SUELDOS POR SECTOR Y TOTAL DE SUELDOS \n");

	for(int i=0; i < tamOtraListaDeEstructuras ;i++)
	{
		printf("\n SECTOR %s", (*(otraListaDeEstructuras + i)).descripcion);
		totalSector=0;

		for(int j=0; j < tamListaDeEstructuras; j++)
		{
			if( (*(listaDeEstructuras + j)).is_Empleado_Full == FULL
                                    && (otraListaDeEstructuras + i)->ID_Sector == (*(listaDeEstructuras + j)).ID_Sector)
			{
				totalSector+= (*(listaDeEstructuras + j)).sueldo;
				retorno=1;
			}
		}

		if(totalSector > 0)
		{
			printf("\n SUELDO TOTAL DEL SECTOR %s:  %.2f\n", (*(otraListaDeEstructuras + i)).descripcion, totalSector);
			total+=totalSector;
		}
		else
		{
			printf("\n NO SE PUDO CALCULAR EL SUELDO, NO EXISTEN EMPLEADOS. \n");
		}

	}

	printf("\n SUELDO TOTAL DE TODOS LOS SECTORES: %.2f\n",total);

	return retorno;
}

int generica_SectorQueMasCobra(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante
                                ,float* pMayorElemento,eSector* otraListaDeEstructuras
                                ,float* auxSectoresConMayorSueldo ,char auxDescripcionSectoresMayorSueldo[][20])

{


}

int utn_pMayorElementoTipoFlotanteDeVector_ConTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante
                                                   ,float* pMayorElemento,eSector* otraListaDeEstructuras
                                                   ,float* auxSectoresConMayorSueldo ,char auxDescripcionSectoresMayorSueldo[][20])
{
	int retorno;
	retorno=0;
	int flag;
	flag = 0;
    float auxMayorElemento;

        if(pListaElementosTipoFlotante != NULL && pMayorElemento != NULL && tamListaElementosTipoFlotante > 0 )
        {
            for(int i=0; i<tamListaElementosTipoFlotante; i++)
            {
                if(flag ==0 || *(pListaElementosTipoFlotante + i) >= auxMayorElemento )
                {
                    auxMayorElemento = *(pListaElementosTipoFlotante + i);

                    *(auxSectoresConMayorSueldo + i) = auxMayorElemento;
                    strcpy( *(auxDescripcionSectoresMayorSueldo + i) ,(*(otraListaDeEstructuras + i)).descripcion);

                    flag = 1;
                    retorno=1;
                }
            }
        }

        *pMayorElemento = auxMayorElemento;


      return retorno;
}




//ESTOS DOS "utn_mayorElementoDeLaEstructura_" Y "utn_SectorDe_ConMejorSueldo_DeTam_" HACEN LO MISMO PERO ESTAN PROGRAMADOS DE FORMA DIFERENTE

int utn_mayorElementoDeLaEstructura_(eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras,eEmpleado* listaDeEstructuras,int tamListaDeEstructuras)
{

	int retorno;
	retorno=0;

	float auxListaSueldoSectores[TAM_LISTA_SECTORES + 1];
	char auxDescripcionSectores[tamOtraListaDeEstructuras][20];
	float mayorElemento;


	float auxListaMayorSueldoVaciaParaCargar[tamOtraListaDeEstructuras];
	char auxListaDescripcionMayorSueldoVaciaParaCargar[tamOtraListaDeEstructuras][20];

	if(listaDeEstructuras != NULL && tamListaDeEstructuras > 0 && otraListaDeEstructuras != NULL && tamOtraListaDeEstructuras > 0)
	{
		printf("\n TOTAL A PAGAR \n");

		for(int i = 0; i < tamListaDeEstructuras ; i++ )
		{
			for(int j = 0; j < tamOtraListaDeEstructuras ; j++)
			{
				if( (*(listaDeEstructuras + i)).ID_Sector == (*(otraListaDeEstructuras + j)).ID_Sector && (*(listaDeEstructuras + i)).is_Empleado_Full == FULL)
				{

					switch( (*(otraListaDeEstructuras + j)).ID_Sector)
					{

						case 500:

									*(auxListaSueldoSectores + 0) += (listaDeEstructuras + i)->sueldo;
									//funcion_CargarDescripcion(arraySectores, tamSectores, arrayEmpleados[i].sector,auxDescripcion[0], 500, 504);

									 strcpy( auxDescripcionSectores + 0, (*(otraListaDeEstructuras + j)).descripcion);

						break;

						case 501:

									*(auxListaSueldoSectores + 1) += (*(listaDeEstructuras + i)).sueldo;

									strcpy(auxDescripcionSectores + 1, (otraListaDeEstructuras + j)->descripcion);

						break;

						case 502:

									(*(auxListaSueldoSectores + 2)) += (*(listaDeEstructuras + i)).sueldo;

                                    strcpy( (*(auxDescripcionSectores + 2)), (otraListaDeEstructuras + j)->descripcion);

						break;

						case 503:

									(*(auxListaSueldoSectores + 3)) += (listaDeEstructuras + i)->sueldo;

									strcpy( (*(auxDescripcionSectores + 3)), (otraListaDeEstructuras + j)->descripcion);

						break;

						case 504:

									(*(auxListaSueldoSectores + 4)) += (*(listaDeEstructuras + i)).sueldo;

									strcpy( (auxDescripcionSectores + 4), (otraListaDeEstructuras + j)->descripcion);

						break;

					}

					(*(auxListaSueldoSectores + 5)) += (*(listaDeEstructuras + i)).sueldo;
				}

			}

		}

	}


        for(int x = 0; x < TAM_LISTA_SECTORES ; x++)
        {
            printf("\n SECTOR: %s \n VALOR EN CADA ELEMENTO: %.2f\n", auxDescripcionSectores + x ,*(auxListaSueldoSectores + x));
        }

        printf("\n CANTIDAD TOTAL DE VALORES EN TODOS LOS ELEMENTOS: %.2f\n", *(auxListaSueldoSectores + 5));



        utn_pMayorElementoTipoFlotanteDeVector_ConTam_(auxListaSueldoSectores,TAM_LISTA_SECTORES
                                                          ,&mayorElemento,otraListaDeEstructuras
                                                          ,auxListaMayorSueldoVaciaParaCargar,auxListaDescripcionMayorSueldoVaciaParaCargar);

        for(int i = 0; i < tamOtraListaDeEstructuras; i++)
        {
                if( mayorElemento  ==  *(auxListaMayorSueldoVaciaParaCargar + i) )
                {
                     printf("\n EL SECTOR QUE MAS COBRA ES: %s MONTO: %.2f \n",
                                                                        *(auxListaDescripcionMayorSueldoVaciaParaCargar+i)
                                                                        ,mayorElemento);

                    retorno=1;
                }
        }


	return retorno;
}

/*
int utn_Sector_ConMejorSueldo(eSector* listaDeSectores,int tamListaDeSectores
                                        ,eEmpleado* listaDeEmpleados,int tamListaEmpleados)
{

    int retorno;
    retorno = 0;
    int i;
    i=0;
    float auxSectorMayorSueldo;
    float totalSueldoPorSector[tamListaDeSectores];
    char auxNombreSector[20];

    NEXO_pMuestraEstructuras_DeTam_DOS(listaDeEmpleados,tamListaEmpleados,listaDeSectores,tamListaDeSectores);
    for(i = 0; i < tamListaDeSectores; i++ )
    {
            totalSueldoPorSector[i]=0;
            for(int j = 0; j < tamListaEmpleados;j++)
            {
                if(listaDeEmpleados[j].is_Empleado_Full == FULL &&
                        listaDeSectores[i].ID_Sector == listaDeEmpleados[j].ID_Sector)
                {

                       totalSueldoPorSector[i] += listaDeEmpleados[j].sueldo;
                       retorno=1;
                }

                 if(i == 0 || auxSectorMayorSueldo < totalSueldoPorSector[i] )
                {
                 auxSectorMayorSueldo = totalSueldoPorSector[i];
                }

            }
    }

    for(i = 0; i < tamListaDeSectores; i++)
    {
        if(auxSectorMayorSueldo == totalSueldoPorSector[i] )
        {
               //utn_DescripcionDeLaEstructuraConElId_enLista_DeTam_((i+500),listaDeSectores,tamListaDeSectores,auxNombreSector);
               printf("%s :%.2f\n",listaDeSectores[i].descripcion,auxSectorMayorSueldo);
        }
    }

    return retorno;

}
*/


int utn_SectorDe_ConMejorSueldo_DeTam_(eSector* listaDeSectores,int tamListaDeSectores
                                        ,eEmpleado* listaDeEmpleados,int tamListaEmpleados)
{

    int retorno;
	retorno = 0;
	float auxListaSueldoSectores[tamListaDeSectores];
	float auxFloat;
    float auxMayorSueldo;


	char auxDescripcionSectoresMayorSueldo[tamListaDeSectores][20];
	float auxSectoresConMayorSueldo[tamListaDeSectores];
	float mayorElementoFlotante;

    utn_TotalElementosEn_PorSector_(listaDeEmpleados,tamListaEmpleados,listaDeSectores,tamListaDeSectores);

	for(int i = 0; i < tamListaDeSectores; i++)
	{
		auxFloat=0;

		//(*(listaDeSectores + i)).IdSector;

		for(int j = 0; j < tamListaEmpleados; j++)
		{
			if(utn_estaEmpleado_Activo(listaDeEmpleados + j)
                            && utn_estaEmpleado_EnSectorConId_( listaDeEmpleados + j , (*(listaDeSectores + i)).ID_Sector) )
			{

				auxFloat  += (*(listaDeEmpleados + j)).sueldo;
			}

			(*(auxListaSueldoSectores + i)) = auxFloat;
		}

	}


        utn_pMayorElementoTipoFlotanteDeVector_ConTam_(auxListaSueldoSectores,tamListaDeSectores
                                                      ,&mayorElementoFlotante,listaDeSectores
                                                      ,auxSectoresConMayorSueldo,auxDescripcionSectoresMayorSueldo);

        for(int i = 0; i < tamListaDeSectores; i++)
        {
                if( mayorElementoFlotante  ==  *(auxSectoresConMayorSueldo + i) )
                {
                     printf("\n EL SECTOR QUE MAS COBRA ES: %s MONTO: %.2f \n", (*(listaDeSectores)).descripcion
                                                                                //(listaDeSectores+i)->descripcion
                                                                                //*(auxDescripcionSectoresMayorSueldo+i)
                                                                                    ,mayorElementoFlotante);

                    retorno=1;
                }
        }

    return retorno;

}


int utn_estaEmpleado_EnSectorConId_(eEmpleado* unEmpleado ,int idSector)
{
	int retorno;
	retorno = 0;

	if( (*(unEmpleado)).ID_Sector == idSector)
	{
		retorno = 1;
	}

	return retorno;
}

/*
int utn_estaEmpleado_EnSectorConId_(eEmpleado* unEmpleado ,int idSector)
{
	return (*(unEmpleado)).sector == idSector;
}

int utn_estaEmpleado_Activo(eEmpleado* unEmpleado)
{

	return (*(unEmpleado)).isEmpty);
}


int utn_estaEmpleado_Vacio(eEmpleado* unEmpleado)
{

	return !(*(unEmpleado)).isEmpty);//si es distinto de ocupado
                                 //entonces esta libre
}

*/


int utn_estaEmpleado_Activo(eEmpleado* unEmpleado)
{
	int retorno;
	retorno=0;

	if( (*(unEmpleado)).is_Empleado_Full == FULL)
	{
		retorno=1;
	}

	return retorno;
}


int utn_estaEmpleado_Vacio(eEmpleado* unEmpleado)
{
	int retorno;
	retorno=0;

	if( !(*(unEmpleado)).is_Empleado_Full)//si es distinto de ocupado
                                 //entonces esta libre
	{
		retorno=1;
	}

	return retorno;
}



int utn_totalGastosEnComidasPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                      ,eComida* listaDeComidas, int tamListaComidas)
{


    //ESTAS VARIABLES FORMAN PARTE DE OTRO TIPO DE RESOLUCION
    //float auxTotal;
	//int flag;
	//flag=0;

	float auxTotalComidasXSector[tamListaDeSectores];

	printf("\n TOTAL GASTOS DE OOMIDAS POR SECTOR:\n");

	for(int i=0; i < tamListaDeSectores;i++)
	{

		(*(auxTotalComidasXSector + i)) = 0;

		//auxTotal = 0; //ESTAS VARIABLES FORMAN PARTE DE OTRO TIPO DE RESOLUCION

			for(int j=0; j < tamListaEmpleados ; j++)
			{
				if( (*(listaDeEmpleados + j)).is_Empleado_Full == FULL && (*(listaDeEmpleados + j)).ID_Sector == (*(listaDeSectores + i)).ID_Sector)
				{
					for(int x=0; x < tamListaDeAlmuerzos ; x++ )
					{

						if( ( (*(listaDeAlmuerzos + x)).is_Almuerzo_Full == FULL && (*(listaDeEmpleados + j)).is_Empleado_Full ) == FULL
                                                    && (*(listaDeAlmuerzos + x)).leg_Empleado == (*(listaDeEmpleados + j)).legajo)
						{

							for(int h=0; h < tamListaComidas ; h++)
							{
								if( (*(listaDeAlmuerzos + x)).is_Almuerzo_Full == FULL
                                                    && (*(listaDeAlmuerzos + x)).id_Comida == (*(listaDeComidas + h)).id_Comida)
								{
									(*(auxTotalComidasXSector + i)) += (*(listaDeComidas + h)).precio;

                                    //flag=1;//ESTAS VARIABLES FORMAN PARTE DE OTRO TIPO DE RESOLUCION
								}

							}

						 }

					 }

				  }

	          }

	          //ESTAS VARIABLES FORMAN PARTE DE OTRO TIPO DE RESOLUCION
	          /*
	          if(flag)
              {
                  printf("SECTOR %s: GASTOS EN COMIDA POR SECTOR: %.2f \n", (*(listaDeSectores + i)).descripcion , (*(auxTotalComidasXSector + i)) );
              }
              else
              {
                  printf("\n OCURRIO UN ERROR \n");
              }
              */

	 }


	 //CORREGIR QUIZAS. PUEDE QUE NO SE HAYA COMPRADO NADA NINGUN EMPLEADO
	 //Y QUE EL GASTO EN COMIDA DE ESE SECTOR SEA EQUIVALENTE A CERO 0

	for(int i = 0; i< tamListaDeSectores;i++)
	{
		if( (*(auxTotalComidasXSector + i)) >= 0  )
		{
			printf("SECTOR %s: GASTOS EN COMIDA POR SECTOR: %.2f \n", (*(listaDeSectores + i)).descripcion , (*(auxTotalComidasXSector + i)) );
		}
		else
		{
			printf("NO EXISTEN EMPLEADOS EN EL SECTOR: %s\n",(*(listaDeSectores + i)).descripcion );
		}
	}


}


int utn_cantidadDeAlmuerzosPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados)
{

	int contadorAlmuerzosPorSector[tamListaDeSectores];


	printf("\n TOTAL GASTOS DE COMIDA POR SECTOR:\n");

	for(int i=0; i < tamListaDeSectores;i++)
	{
		  *(contadorAlmuerzosPorSector + i) = 0 ;

			for(int j=0; j < tamListaEmpleados ; j++)
			{

				if( (*(listaDeEmpleados + j)).is_Empleado_Full == FULL && (*(listaDeEmpleados + j)).ID_Sector == (*(listaDeSectores + i)).ID_Sector)
				{
					for(int x=0; x < tamListaDeAlmuerzos ; x++ )
					{
						if( ( (*(listaDeAlmuerzos + x)).is_Almuerzo_Full && (*(listaDeEmpleados + j)).is_Empleado_Full ) == FULL
                                                    && (*(listaDeAlmuerzos + x)).leg_Empleado == (*(listaDeEmpleados + j)).legajo)
						{

                               (*(contadorAlmuerzosPorSector + i))++;

                             //(*(contadorAlmuerzosPorSector + i)) = *(contadorAlmuerzosPorSector + i) + 1;

						 }

					 }

                }

	          }


	 }

	for(int i = 0; i< tamListaDeSectores;i++)
	{
		if(   *(contadorAlmuerzosPorSector + i) > 0  )
		{
			printf("\nCANTIDAD DE ALMUERZOS EN EL SECTOR %s: %d \n", (*(listaDeSectores + i)).descripcion , *(contadorAlmuerzosPorSector + i) );
		}
		else
		{
			printf("NO EXISTEN EMPLEADOS EN EL SECTOR: %s\n",(*(listaDeSectores + i)).descripcion );
		}
	}



}




int utn_cantidadDeEmpleadosPorSector_(eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados)
{

	int contadorEmpleadosPorSector[tamListaDeSectores];

	printf("\n TOTAL GASTOS DE COMIDA POR SECTOR:\n");

	for(int i=0; i < tamListaDeSectores;i++)
	{

		  *(contadorEmpleadosPorSector + i) = 0;

			for(int j=0; j < tamListaEmpleados ; j++)
			{
				if( (*(listaDeEmpleados + j)).is_Empleado_Full == FULL
                                    && (*(listaDeEmpleados + j)).ID_Sector == (*(listaDeSectores + i)).ID_Sector)
				{
                        (*(contadorEmpleadosPorSector + i))++;

                        //(*(contadorEmpleadosPorSector + i)) = *(contadorEmpleadosPorSector + i) + 1;
                }

            }
    }



	for(int i = 0; i< tamListaDeSectores;i++)
	{
		if(   *(contadorEmpleadosPorSector + i) > 0  )
		{
			printf("\nCANTIDAD DE EMPLEADOS EN EL SECTOR %s: %d \n", (*(listaDeSectores + i)).descripcion , *(contadorEmpleadosPorSector + i) );
		}
		else
		{
			printf("NO EXISTEN EMPLEADOS EN EL SECTOR: %s\n",(*(listaDeSectores + i)).descripcion );
		}
	}



}













/*
int utn_comidaPreferidaDelSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                  ,eSector* listaDeSectores,int tamListaDeSectores
                                  ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                  ,eComida* listaDeComidas, int tamListaComidas)
{
    int retorno;
    retorno=0;

    char auxNombreSector[20];
    char auxDescripcionComidasAcargar[tamListaComidas][20];
    int mayorCantidadTipoDeComida;

    int auxComidasElegidasEnSector[tamListaComidas];
    int auxSector;
    int auxIndiceComida;

    SECTOR_pMuestraListaSectores_DeTam_UNO(listaDeSectores,tamListaDeSectores);

    utn_pIngresoDeElementoTipoEntero_( &auxSector, "\n INGRESE EL SECTOR PARA CONTAR LA MAYOR"
                                                    " CANTIDAD DE COMIDAS QUE SE COMEN DE"
                                                    "UN TIPO DETERMINADO EN ESE SECTOR: "
                                                                        , "\n ERROR", 500, 504, 2);

    SECTOR_pRetornaNombreDelSector_enListaSectores_DeTam_(listaDeSectores,tamListaDeSectores
                                                         ,auxNombreSector,auxSector);

    //utn_pInicializarEstructuras_DeTam_(auxComidasElegidasEnSector,tamListaComidas);

      for(int i=0; i < tamListaEmpleados; i++  )
      {
            (*(auxComidasElegidasEnSector + i)) = 0;
      }


        for(int j=0; j < tamListaEmpleados; j++  )
        {
            if( (*(listaDeEmpleados + j)).is_Empleado_Full == FULL
                                        && (*(listaDeEmpleados + j)).ID_Sector == auxSector )
            {

                for(int h=0; h < tamListaDeAlmuerzos ; h++ )
                {

                    if( ( (*(listaDeAlmuerzos + h)).is_Almuerzo_Full && (*(listaDeEmpleados + j)).is_Empleado_Full ) == FULL
                                            && (*(listaDeEmpleados + j)).legajo == (*(listaDeAlmuerzos + h)).leg_Empleado )
                    {



                        //PRIMERA OPCION: BUSCAR SI EL ID COMIDA DE ALMUERZOS ES IGUAL AL ID COMIDA DE COMIDAS
                        //LA FUNCION DEVUELVE LA POSCIION, EL NUMERO DEL INDICE EN EL CUAL ESTA EL ID COMIDA

                        //SE INCRUSTA EL INDICE EN EL ARRAY DE AUXCOMIDAS
                        //SE UTILIZA EL NUMERO DEL INDICE PARA QUE EN ESA POSICION SE SUME UNO,(SUMAR UNA COMIDA)

                        COMIDA_pBuscaIndiceComidaEnListaComidas_DeTam_(listaDeComidas,tamListaComidas
                                                        ,(*(listaDeAlmuerzos + h)).id_Comida,&auxIndiceComida);

                        (*(auxComidasElegidasEnSector + auxIndiceComida))++;



                        //SEGUNDA OPCION ESTA TAMBIEN FUNCIONA ES ENTRAR EN LA LISTA DE COMIDAS E ITERAR

                      //  for(int x = 0; x < tamListaComidas ; x++ )
                        //{
                          //  if( (*(listaDeComidas + x)).isEmpty == OCUPADO &&
                            //                (*(listaDeAlmuerzos + h)).id_Comida == (*(listaDeComidas + x)).id_Comida )
                            //{
                              //  (*(auxComidasElegidasEnSector + x))++;
                                //retorno=1;

                            //}
                        //}

                   }

              }

          }

      }


       utn_pMayorCantidadDeUnTipoDeComidaQueSeComeEnUnSector_ConTam_(auxComidasElegidasEnSector,tamListaComidas
                                                                    ,&mayorCantidadTipoDeComida,listaDeComidas
                                                                    ,auxDescripcionComidasAcargar);


       for(int i; i < tamListaComidas; i++ )
       {

            printf("\n  SECTOR: %s \n CANTIDAD DE PEDIDOS: %d \n",auxNombreSector, (*(auxComidasElegidasEnSector + i)) );

       }


    //QUE PASARIA SI HAY DOS COMIDAS IGUALES? CREO QUE ACA SE SOLUCIONA

    for(int i; i < tamListaComidas; i++ )
    {
        if(  *(auxComidasElegidasEnSector + i) == mayorCantidadTipoDeComida)
        {
            printf("\n  SECTOR: %s \n  COMIDA MAS PEDIDA EN EL SECTOR: %s \n  CANTIDAD DE PEDIDOS: %d \n\n"
                                                                    ,auxNombreSector
                                                                    ,*(auxDescripcionComidasAcargar + i)
                                                                    ,mayorCantidadTipoDeComida);
        }

    }

    return retorno;
}
*/


int utn_pMayorCantidadDeUnTipoDeComidaQueSeComeEnUnSector_ConTam_( int* auxlistaDeComidas,int tamAuxListaDeComidas
                                                            ,int* mayorCantidadTipoDeComida,eComida* listaDeComidas
                                                            ,char auxDescripcionComidasAcargar[][20])
{
	int retorno;
	retorno=0;
	int flag;
	flag = 0;
    int auxMayorCantidadDeTipoComida;

    if(auxlistaDeComidas != NULL && mayorCantidadTipoDeComida != NULL && tamAuxListaDeComidas > 0 )
    {
        for(int i=0; i < tamAuxListaDeComidas ; i++)
        {
            if(flag ==0 || *(auxlistaDeComidas + i) >= auxMayorCantidadDeTipoComida )
            {
                auxMayorCantidadDeTipoComida = *(auxlistaDeComidas + i);

                strcpy( (*(auxDescripcionComidasAcargar + i)), (*(listaDeComidas + i)).descripcion );
                flag = 1;
                retorno=1;
            }
        }
    }

    *mayorCantidadTipoDeComida = auxMayorCantidadDeTipoComida;

    return retorno;
}


/*
int utn_sectorQueMasEligeLaComidaSeleccionada_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                              ,eSector* listaDeSectores,int tamListaDeSectores
                                              ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                              ,eComida* listaDeComidas, int tamListaComidas)
{

    int retorno;
    retorno = 0;

	int auxCantComidaElegidaPorSector[tamListaDeSectores];
	char auxVectorCargarNombresDeSectores[tamListaDeSectores][20];

	int aux_Id_Comida;
	char pAuxNombreComida[20];

	int pAuxIndiceSector;
	int flag;
	flag=0;

	int mayorCantidadDeLaComidaElegida;

	for(int i = 0; i < tamListaDeSectores ;i++)
	{

		(*(auxCantComidaElegidaPorSector+ i))=0;

	}

	 COMIDA_pMuestraListaDeComidas_DeTam_(listaDeComidas,tamListaComidas );

	 utn_pIngresoDeElementoTipoEntero_(&aux_Id_Comida, "\n INGRESE EL ID DE LA COMIDA PARA CHEQUEAR CUAL"
                                                     "ES EL SECTOR EN EL QUE SE COME MAS ESA COMIDA : ", "\n ERROR"
                                                                                    , 1000, 1004, 2);

     utn_cargaNombreDeLaComida_(listaDeComidas,tamListaComidas,aux_Id_Comida,pAuxNombreComida);

		for(int i =0; i < tamListaDeAlmuerzos ; i++)
		{

			if( (*(listaDeAlmuerzos + i)).is_Almuerzo_Full == FULL
                                        && (*(listaDeAlmuerzos + i)).id_Comida == aux_Id_Comida)
			{

				for(int j=0; j < tamListaEmpleados; j++)
				{

					if( (*(listaDeEmpleados + j)).is_Empleado_Full == FULL
                                    && (*( listaDeAlmuerzos + i)).leg_Empleado == (*(listaDeEmpleados + j)).legajo )
					{


                        //PRIMERA OPCION: BUSCAR SI EL ID COMIDA DE ALMUERZOS ES IGUAL AL ID COMIDA DE COMIDAS
                        //LA FUNCION DEVUELVE LA POSCIION, EL NUMERO DEL INDICE EN EL CUAL ESTA EL ID COMIDA

                        //SE INCRUSTA EL INDICE EN EL ARRAY DE AUXCOMIDAS
                        //SE UTILIZA EL NUMERO DEL INDICE PARA QUE EN ESA POSICION SE SUME UNO,(SUMAR UNA COMIDA)


                        utn_buscarSectorEnListaDe_DeTam_(listaDeSectores,tamListaDeSectores
                                                                    ,(*(listaDeEmpleados + j)).ID_Sector,&pAuxIndiceSector);

                        (*(auxCantComidaElegidaPorSector + pAuxIndiceSector))++;
                        retorno = 1;

					}

				}

			}

		}

		for(int i=0; i < tamListaDeSectores ;i++)
		{
				printf("\n NOMBRE DE LA COMIDA:  %s\nNOMBRE SECTOR: %s CANTIDAD: %d \n ",pAuxNombreComida
                                                ,(*(listaDeSectores + i)).descripcion,(*(auxCantComidaElegidaPorSector + i)) );
		}


		utn_sectorEnELCualSeComeMasLaComida_(auxCantComidaElegidaPorSector,tamListaDeSectores
                                            ,listaDeSectores,&mayorCantidadDeLaComidaElegida
                                            ,auxVectorCargarNombresDeSectores);

        for(int i=0; i < tamListaDeSectores ; i++)
        {
             if( *(auxCantComidaElegidaPorSector + i) == mayorCantidadDeLaComidaElegida )
            {

                 printf("\n COMIDA: %s  \n",pAuxNombreComida);

                 printf("\n SECTOR DONDE SE ELIGE MAS:  %s \n", *(auxVectorCargarNombresDeSectores + i) );

                 printf("\n CANTIDAD %d \n",mayorCantidadDeLaComidaElegida);
            }
        }

    return retorno;
}

*/


int utn_sectorEnELCualSeComeMasLaComida_(int* auxlistaDeUnTipoDeComidaPorSector,int tamAuxListaDeSectores
                                        ,eSector* listaDeSectores,int* pMayorCantidadComidaEnUnSector
                                        ,char auxVectorCargarNombresDeSectores[][20])
{
	int retorno;
	retorno=0;
	int flag;
	flag = 0;
    int auxMayorCantidadDeTipoComida;

    if(auxlistaDeUnTipoDeComidaPorSector != NULL &&  pMayorCantidadComidaEnUnSector != NULL && tamAuxListaDeSectores > 0)
    {
        for(int i=0; i < tamAuxListaDeSectores ; i++)
        {
            if(flag ==0 || *(auxlistaDeUnTipoDeComidaPorSector + i) >= auxMayorCantidadDeTipoComida )
            {
               auxMayorCantidadDeTipoComida = *(auxlistaDeUnTipoDeComidaPorSector + i);

               //ES LO MISMO QUE HACER (*(auxVectorCargarNombresDeSectores + i))

                strcpy( auxVectorCargarNombresDeSectores + i, (*(listaDeSectores + i)).descripcion );
                flag = 1;
                retorno=1;
            }
        }
    }

    *pMayorCantidadComidaEnUnSector = auxMayorCantidadDeTipoComida;

    return retorno;
}





/*
int utn_cantidadDeComidasPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                      ,eComida* listaDeComidas,int tamListaComidas)
{

	int contadorComidasPorSector[tamListaDeSectores];

	int auxVectorIdComidas[tamListaDeAlmuerzos];

	int auxVectorIdSectores[tamListaDeAlmuerzos];

	char auxDescripcionComidasPorSectores[tamListaDeAlmuerzos][20];

	char auxDescripcionSectores[tamListaDeAlmuerzos][20];


	printf("\n TOTAL GASTOS DE COMIDA POR SECTOR:\n");

	for(int i=0; i < tamListaDeSectores;i++)
	{
		  *(contadorComidasPorSector + i) = 0 ;

			for(int j=0; j < tamListaEmpleados ; j++)
			{

				if( (*(listaDeEmpleados + j)).is_Empleado_Full == FULL && (*(listaDeEmpleados + j)).ID_Sector == (*(listaDeSectores + i)).ID_Sector)
				{

					for(int x=0; x < tamListaDeAlmuerzos ; x++ )
					{

						if( ( (*(listaDeAlmuerzos + x)).is_Almuerzo_Full && (*(listaDeEmpleados + j)).is_Empleado_Full ) == FULL
                                                    && (*(listaDeAlmuerzos + x)).leg_Empleado == (*(listaDeEmpleados + j)).legajo)
						{


                                for(int z = 0; z  < tamListaComidas ; z++ )
                                {

                                    if( (*(listaDeComidas + z)).is_Comida_Full == FULL && (*(listaDeComidas + z)).id_Comida == (*(listaDeAlmuerzos + x)).id_Comida )
                                    {
                                        (*(contadorComidasPorSector + i))++;

                                         *(auxVectorIdComidas + x)= (*(listaDeAlmuerzos + x)).id_Comida;

                                         *(auxVectorIdSectores + x) = (*(listaDeSectores + i)).ID_Sector;

                                       COMIDA_cargarDescripcionDeComida(listaDeComidas,tamListaComidas, (*(listaDeAlmuerzos + x)).id_Comida ,auxDescripcionComidasPorSectores + x);

                                        utn_DescripcionDeLaEstructuraConElId_enLista_DeTam_( (*(listaDeSectores + i)).ID_Sector,listaDeSectores,tamListaDeSectores,auxDescripcionSectores + x);


                                        //(*(contadorAlmuerzosPorSector + i)) = *(contadorAlmuerzosPorSector + i) + 1;
                                    }

                                }

						 }

					 }

                }

	          }


	 }


	   for(int j=0; j < tamListaDeAlmuerzos; j++)
       {
           if( (*(listaDeAlmuerzos + j)).is_Almuerzo_Full == FULL )
           {
             printf("\nSECTOR: %s ID SECTOR %d ID COMIDAS: %d NOMBRE COMIDAS: %s \n",*(auxDescripcionSectores + j)
                                                                                    ,*(auxVectorIdSectores + j)
                                                                                    , *(auxVectorIdComidas + j)
                                                                        ,*(auxDescripcionComidasPorSectores + j));

           }

       }

	for(int i = 0; i < tamListaDeSectores;i++)
	{

        if( *(contadorComidasPorSector + i) > 0)
        {

             printf("\nCANTIDAD DE COMIDAS EN EL SECTOR: %s %d \n",(*(listaDeSectores + i)).descripcion
                                                                  , *(contadorComidasPorSector + i) );

            for(int j=0; j < tamListaDeAlmuerzos; j++)
            {
                if( *(auxVectorIdSectores + j) == (*(listaDeSectores + i)).ID_Sector)
                {

                    printf("\n ID COMIDAS: %d NOMBRE COMIDAS: %s \n",*(auxVectorIdComidas + j)
                                                                ,*(auxDescripcionComidasPorSectores + j));

                }
            }

        }
        else
        {
                printf("\n NO EXISTEN COMIDAS EN EL SECTOR: %s\n",(*(listaDeSectores + i)).descripcion );
        }

    }

}
*/














/*
int utn_pMayorCantidadDeUnTipoDeComidaQueSeComenEnUnSector_ConTam_( int* auxlistaDeComidas
                                                                   ,int tamAuxListaDeComidas
                                                ,int* mayorCantidadTipoDeComida
                                                ,eComida* listaDeComidas
                                                ,char auxDescripcionComidasAcargar[][20])
{
	int retorno;
	retorno=0;
	int flag;
	flag = 0;
    int auxMayorCantidadDeTipoComida;

    if(auxlistaDeComidas != NULL && mayorCantidadTipoDeComida != NULL && tamAuxListaDeComidas > 0 )
    {
        for(int i=0; i < TAMCOMIDAS ; i++)
        {
            if(flag ==0 || *(auxlistaDeComidas + i) >= auxMayorCantidadDeTipoComida )
            {
                auxMayorCantidadDeTipoComida = *(auxlistaDeComidas + i);

                strcpy( (*(auxDescripcionComidasAcargar + i)), (*(listaDeComidas + i)).descripcion );
                flag = 1;
                retorno=1;
            }
        }
    }

    *mayorCantidadTipoDeComida = auxMayorCantidadDeTipoComida;

    return retorno;
}
*/


/*
void utn_sectorConMasMilanesasComidas(eEmpleado arrayEmpleados[], int tamEmpleados,
										eComida arrayComidas[], int tamComidas,
									    eSector arraySectores[], int tamSectores,
									    eAlmuerzo arrayAlmuerzos[], int tamAlmuerzos)
{

	int auxSectoresMilanesa[tamSectores];
	int i;
	int j;
	int k;
	int mayor;
	int flag;
	int auxMilanesa;
	char auxNombreComida[20];
	auxMilanesa=1000;
	flag=0;
	mayor=0;

	for(i=0; i < tamSectores; i++)
	{

		auxSectoresMilanesa[i]=0;

	}

	funcion_CargarDescripcionComidas2(arrayComidas, tamComidas, auxMilanesa, auxNombreComida, 1000, 1004);

	printf("milanesas comidas\n");

		for(i=0; i < tamAlmuerzos; i++)
		{

			if(arrayAlmuerzos[i].isEmpty == OCUPADO &&  arrayAlmuerzos[i].id_Comida==auxMilanesa)
			{

				for(j=0; j < tamEmpleados; j++)
				{

					if(arrayEmpleados[j].isEmpty == OCUPADO  && arrayAlmuerzos[i].leg_Empleado == arrayEmpleados[j].legajo)
					{

						for(k=0; k < tamSectores; k++)
						{

							if(arraySectores[k].isEmpty == OCUPADO && arrayEmpleados[j].sector == arraySectores[k].sector)
							{

								auxSectoresMilanesa[k]++;

							}

						}

					}

				}

			}

		}

		for(i=0; i < tamSectores; i++)
		{
			if(flag==0 || auxSectoresMilanesa[i] > mayor)
			{
				mayor=auxSectoresMilanesa[i];
				flag=1;
			}
		}

		for(i=0; i < tamSectores; i++)
		{
			if(auxSectoresMilanesa[i]==mayor)
			{
				printf("el sector que mas %s comio es: %s\n",auxNombreComida,arraySectores[i].descripcion);
			}
		}

}
*/







/*

FALTA RESOLVERLO DE OTRA FORMA QUIZAS CON MATRICES TANTO LA BUSQUEDA DE PRECIOS
COMO LA BUSQUEDA DE DESCRIPCIONES DE LOS EMPLEADOS


int utn_descripcionesDeEmpleadosPorSector_(eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados)
{


    //se puede arreglar colocando una estructura nombres quizas

	char descripcionEmpleadosPorSector[1][50];

	printf("\n TOTAL GASTOS DE COMIDA POR SECTOR:\n");

	for(int i=0; i < tamListaDeSectores;i++)
	{

			for(int j=0; j < tamListaEmpleados ; j++)
			{
				if( (*(listaDeEmpleados + j)).isEmpty == OCUPADO
                                    && (*(listaDeEmpleados + j)).sector == (*(listaDeSectores + i)).IdSector)
				{

                         strcpy( descripcionEmpleadosPorSector + i, (*(listaDeEmpleados + i)).apellido );


                }


            }


    }



	for(int i = 0; i< tamListaDeSectores;i++)
	{
		//if(   *(contadorEmpleadosPorSector + i) > 0  )
		//{
			printf("\nCANTIDAD DE EMPLEADOS EN EL SECTOR %s: %s \n", (*(listaDeSectores + i)).descripcion , *(descripcionEmpleadosPorSector + i) );
		//}
		//else
		//{
			//printf("NO EXISTEN EMPLEADOS EN EL SECTOR: %s\n",(*(listaDeSectores + i)).descripcion );
		//}
	}



}

*/







/*
int utn_totalGastosEnComidasPorSector_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                      ,eComida* listaDeComidas, int tamListaComidas)
{

    int retorno;
    retorno=0;
	float auxListaParaCargarComidasPorSector[TAM_ARRAYSECTORES]= {0} ;
	//char auxDescripcionSectores[tamSectores][20];

	printf("\n TOTAL DE GASTOS DE COMIDAS POR SECTOR:\n");

	for(int i=0; i < tamListaDeSectores; i++)
	{
            utn_buscarEmpleado_EnListaDeSectores_(listaDeAlmuerzos,tamListaDeAlmuerzos
                                                  ,listaDeSectores,tamListaDeSectores
                                                    ,listaDeEmpleados,tamListaEmpleados
                                                    ,listaDeComidas,tamListaComidas
                                                    ,(*(listaDeSectores + i)).IdSector
                                                    , auxListaParaCargarComidasPorSector + i );

    }

	for(int i=0; i< TAM_ARRAYSECTORES ;i++)
	{

        printf("SECTOR %s: COSTO EN ALMUERZOS: %.2f \n", (*(listaDeSectores + i)).descripcion
                                                                    ,(*(auxListaParaCargarComidasPorSector + i)) );

	}

    return retorno;
}


int utn_buscarEmpleado_EnListaDeSectores_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                            ,eSector* listaDeSectores,int tamListaDeSectores
                                            ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                            ,eComida* listaDeComidas, int tamListaComidas
                                            ,int auxIdSector,float* auxListaParaCargarComidasPorSector)
{
    int retorno;
    retorno=0;

    for(int i=0; i < tamListaEmpleados; i++)
    {

        if( (*(listaDeEmpleados + i)).isEmpty == OCUPADO &&
                                                (*(listaDeEmpleados + i)).sector == auxIdSector)
        {


            utn_buscarEmpleado_EnListaDeAlmuerzos_(listaDeAlmuerzos,tamListaDeAlmuerzos

                                        ,listaDeEmpleados,tamListaEmpleados
                                        ,listaDeComidas,tamListaComidas, (*(listaDeEmpleados)).legajo ,
                                        auxListaParaCargarComidasPorSector);


            retorno=1;
        }

    }

    return retorno;

}


int utn_buscarEmpleado_EnListaDeAlmuerzos_(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos

                                  ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                  ,eComida* listaDeComidas, int tamListaComidas,int auxLegajoEmpleado
                                  ,float* auxListaParaCargarComidasPorSector)
    {

    int retorno;
    retorno=0;

    for(int i=0; i < tamListaDeAlmuerzos; i++ )
    {

        if(  (*(listaDeAlmuerzos + i)).isEmpty  == OCUPADO && (*(listaDeAlmuerzos + i)).leg_Empleado == auxLegajoEmpleado )
        {

            utn_buscarComida_EnListaDeComidas(


                                              listaDeComidas,tamListaComidas,(*(listaDeAlmuerzos + i)).id_Comida
                                              ,auxListaParaCargarComidasPorSector);


            retorno=1;
        }
    }

    return retorno;

}


int utn_buscarComida_EnListaDeComidas(
                                      eComida* listaDeComidas, int tamListaComidas,int auxIdComida
                                      ,float* auxListaParaCargarComidasPorSector)
{

    int retorno;
    retorno=0;

    for(int i=0; i < tamListaComidas; i++ )
    {

        if(  (*(listaDeComidas + i)).isEmpty  == OCUPADO && (*(listaDeComidas + i)).id_Comida == auxIdComida )
        {

            (*(auxListaParaCargarComidasPorSector + i)) += (*(listaDeComidas + i)).precio;


            retorno=1;
        }
    }



    return retorno;
}

*/
