#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "utn_biblioteca_InputsC.h"
#include "eEmpleado.h"
#include "eSector.h"
#include "almuerzo.h"

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

#define  NO_FULL 0
#define   FULL 1
#define  EMPTY 0
#define  NO_EMPTY 0
#define  TAM_APELLLIDO_EMPLEADO 60

#define  LA_POSICION_NUNCA_FUE_CARGADA 0

//NOS AVISA QUE LA POSICION ALGUNA VEZ SE CARGO
//ES UNA BANDERA QUE ES IMPORTANTE PARA DAR DE ALTA
//EMPLEADOS DADOS DE BAJA Y QUE SE RESPETEN SUS POSICIONES
//DENTRO DE LA LISTA
#define  LA_POSICION_ESTUVO_CARGADA 1

int utn_pMuestraListaDeComidas_DeTam_ConNombreDeEmpleado(eComida* listaComidas,int tamListaComidas
                                                        ,eAlmuerzo* listaAlmuerzos,int tamlistaAlmuerzos)
{
	int retorno;
	retorno= 0;
	int flag;
	flag=-1;
	int i;
	int cantidad;
	int contadorEstructurasVacias;
	contadorEstructurasVacias=0;

	if( listaComidas != NULL && tamListaComidas > 0 && listaAlmuerzos != NULL && tamlistaAlmuerzos > 0)
	{

        for(i=0; i < tamListaComidas; i++)
        {
            if(COMIDA_pEstaComida_DadoDeAlta((listaComidas + i)))
            {
                contadorEstructurasVacias++;
            }
        }

		for (int i = 0; i < tamListaComidas ; i++)
		{
                  //listaDeEstructuras + i)->isEmpty
			if( COMIDA_pEstaComida_DadoDeAlta(listaComidas + i) )
			{

                utn_pMuestraUnaComida_DeLaListaDeComidas_( listaComidas + i
                                                            ,listaAlmuerzos,tamlistaAlmuerzos);
				puts("---------------------------------------------------------------------------------------------------------------------------------------|");
				flag=1;
				retorno=1;
			}

        }
        if(!flag)
        {
          utn_mostrarMensaje("\n  ERROR AL MOSTRAR EMPLEADOS \n");
        }
    }
    else
    {
          utn_mostrarMensaje("\n OCURRIO UN ERROR INESPERADO \n");

    }

    return retorno;
}



int utn_pMuestraUnaComida_DeLaListaDeComidas_(eComida* unaEstructura,eAlmuerzo* listaDeAlmuerzos,int tamlistaDeAlmuerzos)
{

    int retorno;
    retorno=0;
    char auxNombreEmpleado[50];

    /*
    if(utn_DescripcionDelEmpleadoConElId_enLista_DeTam_( (*(unaEstructura)).id_Comida,listaDeAlmuerzos,tamlistaDeAlmuerzos, auxNombreEmpleado))
    {

        printf("\n %d   %s   %f     %s     \n"
                                                                                ,unaEstructura->id_Comida,
                                                                                unaEstructura->descripcion,
                                                                                (*(unaEstructura)).precio,
                                                                                 auxNombreEmpleado);
                                                                                retorno=1;
    }
	else
	{

		printf("              HUBO UN PROBLEMA CON LA DESCRIPCION DEL EMPLEADO \n");

	}
    */


    return retorno;
}


int COMIDA_pMuestraListaDeComidas_DeTam_(eComida* listaComidas,int tamListaComidas)
{
	int retorno;
	retorno= 0;
	int flag;
	flag=0;
	int i;
	int cantidad;
	int contadorEstructurasVacias;
	contadorEstructurasVacias=0;

	if( listaComidas != NULL && tamListaComidas > 0 )
	{
         puts("-----------------------------------------------------------");
        printf( "  ID COMIDA    |    NOMBRE COMIDA    |   PRECIO COMIDA   |");
        puts("\n----------------------------------------------------------");

        for (int i = 0; i < tamListaComidas ; i++)
        {
                  //listaDeEstructuras + i)->isEmpty
            if( COMIDA_pEstaComida_DadoDeAlta(listaComidas + i))
            {

                COMIDA_MuestraUnaComida_( listaComidas + i);
                puts("---------------------------------------------------------|");
                flag=1;
                retorno=1;
            }

        }
        if(!flag)
        {
          utn_mostrarMensaje("\n  ERROR AL MOSTRAR COMIDAS \n");
        }
    }
    else
    {
          utn_mostrarMensaje("\n OCURRIO UN ERROR INESPERADO \n");
    }

    return retorno;
}


int COMIDA_MuestraUnaComida_(eComida* unaComida)
{

    int retorno;
    retorno=0;

            printf("\n %7d   %18s   %19.2f          \n"
                                                                                ,unaComida->id_Comida,
                                                                                unaComida->descripcion,
                                                                                (*(unaComida)).precio);
                                                                                retorno=1;

    return retorno;
}


int COMIDAS_pInicializaComidas_DeTam_(eComida* listaComidas,int tamListaComidas)
{
    int retorno;
    retorno=0;

        if(listaComidas != NULL && tamListaComidas > 0)
        {

            for(int i=0; i < listaComidas; i++)
            {

                COMIDAS_pInicializaUnaComida_(listaComidas + i);
                retorno = 1;
            }
        }
        else
        {
            printf("\n OCURRIO UN ERROR AL INICIALIZAR LAS COMIDAS \n");
        }

    return retorno;
}

int COMIDAS_pInicializaUnaComida_(eComida* pUnaComida)
{
    int retorno;
    retorno=0;

    if( pUnaComida != NULL )
    {
        pUnaComida->is_Comida_Empty = EMPTY;
        retorno = 1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INICIALIZAR LA COMIDA \n");
    }

    return retorno;

}

int ALMUERZO_pInicializaAlmuerzos_DeTam_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
	int retorno;
	retorno= 0;

		for(int i = 0; i < tamListaAlmuerzos ; i++)
		{
			ALMUERZO_pInicializaUnAlmuerzo_( (listaAlmuerzos + i) );
			retorno=1;
		}

	return retorno;
}


int ALMUERZO_pInicializaUnAlmuerzo_(eAlmuerzo* pUnAlmuerzo)
{
	int retorno;
	retorno=0;

	if(pUnAlmuerzo != NULL)
    {
       (*(pUnAlmuerzo)).is_Almuerzo_Full = NO_FULL;
        pUnAlmuerzo->is_Almuerzo_Empty = EMPTY;
        (*(pUnAlmuerzo)).is_PosicionLista = LA_POSICION_NUNCA_FUE_CARGADA;

        retorno=1;
    }

	return retorno;
}



int ALMUERZO_BuscaIndiceLibreEnListaDeAlmuerzos_DeTam_(eAlmuerzo* listaDeEstructuras,int tamListaDeEstructuras,int* pIndice)
{
	int i;
	int retorno;
	int auxIndice;
	auxIndice=-1;
	retorno=0;

	if( listaDeEstructuras!= NULL && tamListaDeEstructuras > 0)
	{
		for(i=0;i<tamListaDeEstructuras;i++)
		{
			//if(arrayEmpleados[i].isEmpty) ya al colocar asi sabemos que es LIBRE

			if( (*(listaDeEstructuras + i)).is_Almuerzo_Full == NO_FULL &&
                        (*(listaDeEstructuras + i)).is_Almuerzo_Empty == EMPTY &&
                                    (*(listaDeEstructuras + i)).is_PosicionLista == LA_POSICION_NUNCA_FUE_CARGADA )
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


int COMIDA_pBuscaNombre_DeComida_EnListaComidas_DeTam_(eComida* listaDeComidas,int tamListaComidas
                                                        ,int* auxIdComida,char* auxDescripcionComida)
{
    int retorno;
    retorno=0;

    if(listaDeComidas != NULL && tamListaComidas != NULL && auxDescripcionComida != NULL)
    {

        for(int i=0; i < tamListaComidas; i++)
        {
            if( COMIDA_pEstaComida_DadoDeAlta(listaDeComidas + i) && (listaDeComidas + i)->id_Comida == *(auxIdComida) )
            {

                COMIDA_pRetornaNombreDelEmpleado(auxDescripcionComida, (listaDeComidas + i)->descripcion);
                retorno=1;
                break;

            }
        }
    }

    return retorno;
}

int COMIDA_pRetornaNombreDelEmpleado(char* auxNombreComida,char* nombreComida)
{
    int retorno;
    retorno=0;

    if(auxNombreComida != NULL && nombreComida != NULL)
    {
        strcpy( auxNombreComida, nombreComida );
        retorno=1;
    }

    return retorno;
}

int COMIDA_pBuscaIndiceComidaEnListaComidas_DeTam_(eComida* listaDeComidas,int tamListaDeComidas,int auxIdComida,int* pAuxIndice)
{
	int retorno;
	retorno = 0;

	if( listaDeComidas != NULL && tamListaDeComidas > 0)
	{
		for(int i=0; i < tamListaDeComidas ;i++)
		{
			if( COMIDA_pEstaComida_DadoDeAlta(listaDeComidas + i) && (*(listaDeComidas + i)).id_Comida == auxIdComida)
			{

			    *pAuxIndice=i;
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}


int utn_cargaNombreDeLaComida_(eComida* listaDeComidas,int tamListaComidas,int auxIdComida,char* pAuxNombreComida)
{
	int retorno;
	retorno = 0;

	if( listaDeComidas != NULL && tamListaComidas > 0 && pAuxNombreComida != NULL)
	{
		for(int i=0; i < tamListaComidas ;i++)
		{
			if( COMIDA_pEstaComida_DadoDeAlta(listaDeComidas + i) && (*(listaDeComidas + i)).id_Comida == auxIdComida)
			{
				strcpy( pAuxNombreComida, (*(listaDeComidas + i)).descripcion);
				retorno=1;
				break;
			}
		}
	}

	return retorno;
}



int ALMUERZO_pBajaUnAlmuerzo_(eAlmuerzo* unAlmuerzo)
{
    if(unAlmuerzo != NULL)
    {

        return(ALMUERZO_pBajaAlmuerzo_CambiaLasBanderasAlmuerzo_DadoDeBaja_(unAlmuerzo));

    }
}


int ALMUERZO_pEstaAlmuerzo_DadoDeAlta_Y_PerteneceAlEmpleado_(eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado)
{

    int auxIdEmpleado;
    auxIdEmpleado= *pAuxIdEmpleado;

     if(unAlmuerzo != NULL && pAuxIdEmpleado != NULL)
     {

        return (ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(unAlmuerzo)
                                        && GENERICA_pEsElNumero_IgualQueElNumero_( &(unAlmuerzo)->leg_Empleado
                                                                                  ,&auxIdEmpleado));

     }
}


int ALMUERZO_pBajaAlmuerzo_CambiaLasBanderasAlmuerzo_DadoDeBaja_(eAlmuerzo* unAlmuerzo)
{
    int retorno;
    retorno=0;

    if(unAlmuerzo != NULL)
    {
        ///NO PUEDO COLOCAR ESTO EN EL RETURN PORQUE ME TIRA ERROR
       (unAlmuerzo)->is_Almuerzo_Full = NO_FULL;
       (unAlmuerzo)->is_Almuerzo_Empty = EMPTY;
       (unAlmuerzo)->is_PosicionLista = LA_POSICION_ESTUVO_CARGADA;

        retorno = 1;
    }


    return retorno;
}


int ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(eAlmuerzo* unAlmuerzo)
{
    int retorno;
    retorno=0;

    if(unAlmuerzo != NULL)
    {

        ///SI EL ALMUERZO FULL ES 1 , SI ES NEGADO (0+NEGADO =1) Y
        /// SI ES POSICION EN LA LISTA 1 ENTONCES DEVUELVE 1
        return((unAlmuerzo)->is_Almuerzo_Full
                    && !(unAlmuerzo)->is_Almuerzo_Empty
                                && (unAlmuerzo)->is_PosicionLista);

    }

}


int ALMUERZO_pReingresaTodosAlmuerzos_DeEmpleadoConId_(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;
    int auxIdEmpleado;

    auxIdEmpleado = *pAuxIdEmpleado;

    if(listaAlmuerzos != NULL && tamListaAlmuerzos > 0 && pAuxIdEmpleado != NULL )
    {
        //ALMUERZO_pHayAlmuerzosDadosDe_Baja(listaAlmuerzos,tamListaAlmuerzos);
         if(ALMUERZO_pHayAlmuerzosDadosDe_Baja(listaAlmuerzos,tamListaAlmuerzos))
         {

            for(int i = 0; i < tamListaAlmuerzos; i++)
            {
              //si no esta dado de alta devuelve cero y al estar negado da positivo
              // si el almuerzo no esta dado de alta y coincide el legajo del empleado del almuerzo
              //con el IdAuxiliar eso significa que este empleado tiene un almuerzo dado de baja y lo da de alta

                if(ALMUERZO_pReingresaUnAlmuerzo_DeUnEmpleado_((listaAlmuerzos + i),&auxIdEmpleado))


                {

                       ALMUERZO_pAltaAlmuerzo_CambiaLasBanderas_ALMUERZO_DadoDeAlta_(listaAlmuerzos + i);
                       retorno=1;
                }
            }

            if(!retorno)
            {

                printf("\n ATENCION: EL EMPLEADO NO TIENE ALMUERZOS PARA REINGRESAR. \n");
            }
            else
            {

                printf("\n ALMUERZOS DEL EMPLEADO REINGRESADOS EXITOSAMENTE  \n");
            }

        }
        else
        {

            printf("\n ATENCION: NO EXISTEN ALMUERZOS DADOS DE BAJA \n");
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL BAJAR LOS ALMUERZOS DEL EMPLEADO \n");
    }

    return retorno;
}

int ALMUERZO_pReingresaUnAlmuerzo_DeUnEmpleado_(eAlmuerzo* unAlmuerzo,int* pAuxIdEmpleado)
{
    int retorno;
    retorno=0;

    int auxIdEmpleado;
    auxIdEmpleado=*pAuxIdEmpleado;


    if(unAlmuerzo != NULL &&  pAuxIdEmpleado != NULL )
    {

        if(!ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(unAlmuerzo)
                                                && GENERICA_pEsElNumero_IgualQueElNumero_(&(unAlmuerzo)->leg_Empleado
                                                                                          ,&auxIdEmpleado))
        {

            retorno=1;

        }

    }

    return retorno;
}



int ALMUERZO_pAltaAlmuerzo_CambiaLasBanderas_ALMUERZO_DadoDeAlta_(eAlmuerzo* unAlmuerzo)
{

    int retorno;
    retorno=0;

    if(unAlmuerzo != NULL)
    {
        (unAlmuerzo)->is_Almuerzo_Full  = FULL;
        (unAlmuerzo)->is_Almuerzo_Empty = NO_EMPTY;
        (unAlmuerzo)->is_PosicionLista = LA_POSICION_ESTUVO_CARGADA;

         retorno = 1;
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL DAR DE ALTA EL EMPLEADO  \n");
    }


    return retorno;
}


int ALMUERZO_pHayAlmuerzosDadosDe_Alta(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
   int retorno;
   retorno=0;

    if(listaAlmuerzos != NULL & tamListaAlmuerzos > 0)
    {

        for(int i = 0; i < tamListaAlmuerzos; i++)
        {
            if(ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(listaAlmuerzos + i))
            {

                retorno=1;
                break;

            }
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO EXISTEN ALMUERZOS CARGADOS EN LA LISTA \n");
        }
        else
        {
            printf("\n EXISTEN ALMUERZOS CARGADOS EN LA LISTA \n");
        }

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
int ALMUERZO_pHayAlmuerzosDadosDe_Baja(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos)
{
   int retorno;
   retorno=0;

    if(listaAlmuerzos != NULL & tamListaAlmuerzos > 0)
    {

        for(int i = 0; i < tamListaAlmuerzos; i++)
        {
            if(!ALMUERZO_pEstaAlmuerzo_DadoDeAlta_(listaAlmuerzos + i))
            {

                retorno=1;
                break;

            }
        }

        if(!retorno)
        {
            printf("\n ATENCION: NO EXISTEN ALMUERZOS CARGADOS EN LA LISTA \n");
        }
        else
        {
            printf("\n EXISTEN ALMUERZOS DADOS DE BAJA \n");
        }

    }
    else
    {
        printf("\n OCURRIO UN ERROR AL INGRESAR \n");
    }

    return retorno;
}


int COMIDA_pEstaComida_DadoDeAlta(eComida* unaComida)
{

    int retorno;
    retorno=0;

    if(unaComida != NULL)
    {
        if((unaComida)->is_Comida_Empty == FULL)
        {
            retorno=1;
        }
    }

    return retorno;
}



/*
int utn_descontarAlmuerzoAEmpleado(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos
                                      ,eSector* listaDeSectores,int tamListaDeSectores
                                      ,eEmpleado* listaDeEmpleados,int tamListaEmpleados
                                      ,eComida* listaDeComidas,int tamListaComidas)
{

    int retorno;
    retorno = 0;
	int pAuxIndice;
	int auxIdEmpleado;
	float totalGastadoEnComida;
	totalGastadoEnComida=0;


    COMIDA_pMuestraListaDeComidas_DeTam_(listaDeComidas,tamListaComidas);


    NEXO_pMuestraEstructuras_DeTam_DOS(listaDeEmpleados,tamListaEmpleados,listaDeSectores,tamListaDeSectores );


    utn_pIngresoDeElementoTipoEntero_( &auxIdEmpleado, "\n INGRESE LEGAJO DEL EMPLEADO ", "\n ERROR", 2000, 3000, 2);

	for(int i = 0; i < tamListaDeAlmuerzos ;i++)
	{

		if( (*(listaDeAlmuerzos + i)).is_Almuerzo_Full == FULL && (*(listaDeAlmuerzos + i)).leg_Empleado == auxIdEmpleado )
		{

            COMIDA_pBuscaIndiceComidaEnListaComidas_DeTam_(listaDeComidas,tamListaComidas
                                             ,(*(listaDeAlmuerzos + i)).id_Comida,&pAuxIndice);

			totalGastadoEnComida += (*(listaDeComidas + pAuxIndice)).precio;

		}

	}


	EMP_pBuscaPosicionDelEmpleado_EnListaEmpleados_PorId_(listaDeEmpleados,tamListaEmpleados, auxIdEmpleado, &pAuxIndice);


	if( (*(listaDeEmpleados + pAuxIndice)).sueldo < totalGastadoEnComida )
	{

		printf("\n EL EMPLEADO: %s  %s DEBE PLATA\n. DINERO ADEUDADO %.2f:\n",(*(listaDeEmpleados + pAuxIndice)).nombre
                                                                        ,(*(listaDeEmpleados + pAuxIndice)).apellido
                                                                        ,(*(listaDeEmpleados + pAuxIndice)).sueldo - totalGastadoEnComida);

	}
	else
	{
		(*(listaDeEmpleados + pAuxIndice)).sueldo -= totalGastadoEnComida;

		printf("\n AL EMPLEADO: %s %s SE LE HA DESCONTADO LA COMIDA DEL SUELDO \n", (*(listaDeEmpleados + pAuxIndice)).nombre
                                                                                  ,(*(listaDeEmpleados + pAuxIndice)).apellido);

        NEXO_pMuestraEstructuras_DeTam_DOS(listaDeEmpleados,tamListaEmpleados,listaDeSectores,tamListaDeSectores );

	}


    return retorno;

}
*/



/*
int utn_bajaAlEmpleado_YSusAlmuerzos(eEmpleado* listaDeEmpleados,int tamListaEmpleados,eSector* listaDeSectores
                                    ,int tamListaDeSectores,eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos)
{
	char opcion;
	int retorno;
	retorno=0;

	int auxIdEmpleado;
	int indice;
	indice=-1;
	int flag;
	flag=-1;
	int i;
	i=3;

	if( listaDeEmpleados != NULL && tamListaEmpleados > 0)
	{


			flag=1;

	}
		else
		{
			printf("\n NO EXISTE NINGUN ELEMENTO \n");
			retorno=-3;

		}

		if(flag==1)
		{

			//i=3 en este caso, hay tres reintentos para resolver esto
			while((i > 0 && indice ==-1))
			{

				utn_pIngresoDeElementoTipoEntero_( &auxIdEmpleado, "\n INGRESE LEGAJO DEL EMPLEADO ", "\n ERROR", 2000, 3000, 2);

				indice= funcion_BuscarPosicionPorID( listaDeEmpleados, tamListaEmpleados, auxIdEmpleado);

				if(indice==-1)
				{
					printf("\n NO EXISTE EL EMPLEADO %d\n",auxIdEmpleado);
				}

				i--;
			}
			if(indice==-1)
			{
				retorno=-2;

			}

			if(indice != -1)
			{

				utn_MuestraListaEstructuras_DeTam_(nomina,TAM,"\n                               EMPLEADOS      \n"
                                                                        , "ERROR"
                                                                        ,""
                                                                        ,"| LEGAJO  |"
                                                                        , "NOMBRE   |"
                                                                        , "APELLIDO  |"
                                                                        , " FECHA DE NACIMIENTO |"
                                                                        , "EDAD  |","SEXO  |"
                                                                        ,"SUELDO  |"
                                                                        ,"FECHA DE INGRESO     |"
                                                                        ,"",sectoresEmpresa,TAM_ARRAYSECTORES)



				opcion=funcion_ContinuarIteracion("DESEA DAR DE BAJA A ESTE EMPLEADO s/n?\n", "ERROR PRESIONE s/n \n");

				if(opcion==1)
				{

					if(funcion_BajaAlmuerzosEmpleado(arrayAlmuerzos, tamAlmuerzos, id) > 0)
					{
						printf("\n LOS ALMUERZOS DEL EMPLEADO TAMBIEN FUERON DADOS DE BAJA CORRECTAMENTE\n");
					}
					else
					{
						printf("\n NO SE ENCONTRARON ALMUERZOS, EMPLEADO DADO DE BAJA \n");
					}


					(*(listaDeEmpleados + indice)).isEmpty = LIBRE;

					retorno=1;
				}
				else
				{
					retorno=-1;
				}

			}
		}
	}
	else
	{
		retorno=-4;
	}

	return retorno;
}
*/

