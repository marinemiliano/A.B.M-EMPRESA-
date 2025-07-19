#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
#include "utn_biblioteca_InputsC.h"


/*
(int* opcion,char* mensajeBienvenida,char* mensajeIngresoALaOpcion,char* mensajeDetalleCantidadItemsASeleccionar
                              ,char* mensajeError,int rangoMinimo,int rangoMaximo,int reintentos,char* itemUno,char* itemDos,char* itemTres,char* itemCuatro,char* itemQuinto
                                ,char* itemSexto,char* itemSeptimo,char* itemOctavo,char* itemNoveno)


	do
	{
	    if(utn_MenuIngresarLaOpcion_(&opcion
                                    ,"\n\n******MODIFICAR EMPLEADO********\n"
                                    ,"",
                                    ,"QUE ITEM DESEA MODIFICAR?\n INGRESE OPCION DE 1 AL 8: "
                                    ,"ERROR\n",1,8,2
                                    ,"\n1.NOMBRE\n","2.EDAD\n"
                                    ,"3.SEXO\n","4.SUELDO\n"
                                    ,"5.DIA DE INGRESO DEL EMPLEADO A LA EMPRESA\n"
                                    ,"6.MES DE INGRESO DEL EMPLEADO A LA EMPRESA\n"
                                    ,"7.ANIO DE INGRESO DEL EMPLEADO A LA EMPRESA\n"
                                    ,"8.SALIR\n"
                                    ,"") )

*/

int utn_pMenuOpciones_(int* opcion,char* opcionesDelMenu,char* mensajeError,int rangoMinimo,int rangoMaximo,int reintentos)
{
    int retorno;
	retorno=0;
	int auxOpcion;
	int resultado;

	if(opcion != NULL && rangoMinimo <= rangoMaximo && mensajeError != NULL && reintentos >= 0)
    {
        utn_mostrarMensaje(opcionesDelMenu);

        if(utn_pIngresoDeElementoTipoEntero_(&auxOpcion,"",mensajeError,rangoMinimo,rangoMaximo,reintentos))
        {
            retorno = 1;
            *opcion = auxOpcion;
        }
    }

	return retorno;
}

int utn_MenuIngresarLaOpcion_(int* opcion,char* mensajeBienvenida,char* mensajeIngresoALaOpcion,char* mensajeDetalleCantidadItemsASeleccionar
                              ,char* mensajeError,int rangoMinimo,int rangoMaximo,int reintentos,char* itemUno,char* itemDos,char* itemTres,char* itemCuatro,char* itemQuinto
                              ,char* itemSexto,char* itemSeptimo,char* itemOctavo,char* itemNoveno)
{
	int retorno;
	retorno=0;
	int auxOpcion;
	int resultado;

	if(opcion != NULL)
    {
        printf("%s", mensajeBienvenida);

        printf("%s",itemUno);
        printf("%s",itemDos);
        printf("%s",itemTres);
        printf("%s",itemCuatro);
        printf("%s",itemQuinto);
        printf("%s",itemSexto);
        printf("%s",itemSeptimo);
        printf("%s",itemOctavo);
        printf("%s",itemNoveno);
        printf("%s",mensajeIngresoALaOpcion);

        if(utn_pIngresoDeElementoTipoEntero_(&auxOpcion,mensajeDetalleCantidadItemsASeleccionar,mensajeError,rangoMinimo,rangoMaximo,reintentos))
        {
            retorno = 1;
            *opcion = auxOpcion;
        }
    }

	return retorno;
}


int utn_pMenuContinuarSiEsLetraS_ONoSiEsN_DeTam_(char* unChar,char* mensaje,char* mensajeError,int reintentos)
{

	int retorno = 0;
    char auxChar;

	if(unChar != NULL )
	{

            if(utn_pIngresoDeCaracterBooleanoS_O_N_DeTam_(&auxChar,sizeof(auxChar),mensaje, mensajeError, reintentos))
            {
                            *unChar=auxChar;
                             retorno = 1;
            }
            else
            {
                printf("\n OCURRIO UN ERROR NO SE INGRESO LA LETRA S NI LA N \n");

                retorno=0;
            }

    }

	return retorno;
}



int utn_pIngresoDeCaracterBooleanoS_O_N_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos)
{
	char auxiliarString[4096];
	int retorno = 0;

	if(mensaje != NULL &&  mensajeError != NULL
                && tamStringIngresado > 0 && pResultadoStringIngresado != NULL && reintentos >= 0)
	{

		do
		{
			printf("%s",mensaje);

			if(utn_obtenerString(auxiliarString, sizeof(auxiliarString))
                                            && utn_esCaracterS_O_N(auxiliarString, sizeof(auxiliarString))
                                                                && strnlen(auxiliarString, sizeof(auxiliarString)) == 1  )
			{
				strncpy(pResultadoStringIngresado,auxiliarString,tamStringIngresado);
				retorno = 1;
				break;
			}

           utn_cantDeReintentos(&reintentos,mensajeError);
           reintentos--;

		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_esCaracterS_O_N(char* cadena, int tamCadena)
{
	int i = 0;
	int retorno = 0;

	if(cadena != NULL && tamCadena > 0)
	{
		for(i = 0 ; cadena[i] != '\0' && i < tamCadena; i++)
		{
			if(cadena[i]== 32)
			{
				continue;
			}
				if( cadena[i] == 'n' || cadena[i] == 's' ||  cadena[i] == 'S' || cadena[i] == 'N' )
				{
					retorno = 1;
					break;
				}
		}
	}
	return retorno;
}



int utn_pRespuestaBooleanaSiUno_NoCero(char* mensaje, char* mensajeError,int reintentos)
{

	int retorno;
	retorno= 0;
    char auxChar;


            if(utn_pIngresoDeCaracterBooleanoS_O_N_DeTam_(&auxChar,sizeof(auxChar),
                                                        mensaje, mensajeError, reintentos)

                                                          && (auxChar == 's' || auxChar == 'S' ) )
            {

                            retorno = 1;
            }
            else
            if(auxChar == 'n' || auxChar == 'N' )
            {

                retorno=0;

            }
            else
            {
                 system("cls");
                 printf("\n OCURRIO UN ERROR NO SE CARGARON LAS LETRAS S O N \n");
            }

	return retorno;
}





// ALFANUMERICO

int utn_pIngresoAlfaNumerico_DeTam_(char* pResultadoAlfaNumericoIngresado,int tamAlfaNumericoIngresado, char* mensaje, char* mensajeError, int rangoMinimo,int rangoMaximo, int reintentos)
{
    int retorno = 0;
    char auxiliarString[4096]; //en ingles bufferString

    if(mensaje != NULL && mensajeError != NULL && tamAlfaNumericoIngresado > 0
                            && pResultadoAlfaNumericoIngresado != NULL
                                            && reintentos >= 0 && rangoMinimo < rangoMaximo)
	{
    	do
    	{
			printf("%s",mensaje);

			if(utn_copiaElementoTipoCadenaEn_DeTam_(auxiliarString,sizeof(auxiliarString))
                        && utn_esAlfanumerico(auxiliarString, sizeof(auxiliarString))
                                && strnlen(auxiliarString,sizeof(auxiliarString)) < tamAlfaNumericoIngresado
                                            && strnlen(auxiliarString,sizeof(auxiliarString)) >= rangoMinimo
                                                        && strnlen(auxiliarString,sizeof(auxiliarString)) <= rangoMaximo)
			{
				strncpy(pResultadoAlfaNumericoIngresado,auxiliarString,tamAlfaNumericoIngresado);
				retorno = 1;
				break;
			}

           utn_cantDeReintentos(&reintentos,mensajeError);
           reintentos--;

    	}while(reintentos >= 0);
	}

    return retorno;
}


int utn_esAlfanumerico(char* cadena, int tamCadena)
{
	int retorno;
	retorno=1;
	int i;

	if(cadena != NULL && tamCadena > 0)
	{
		for(i = 0; i < tamCadena && cadena[i] != '\0'; i++)
		{
			if( (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] < 'A' || cadena[i] > 'Z')
			   && (cadena[i] < 'a' || cadena[i] > 'z') )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



//STRING

int utn_pIngresoDeSexoF_M_oNoBinario_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos)
{
	char auxiliarString[4096];
	int retorno = 0;

	if(mensaje != NULL &&  mensajeError != NULL
                && tamStringIngresado > 0 && pResultadoStringIngresado != NULL && reintentos >= 0)
	{

		do
		{
			printf("%s",mensaje);

			if(utn_obtenerString(auxiliarString, sizeof(auxiliarString))
                                            && utn_esSexoF_M_oNoBinarioDeTam_(auxiliarString, sizeof(auxiliarString))
                                                                        && strnlen(auxiliarString, sizeof(auxiliarString)) <= 2  )
			{
				strncpy(pResultadoStringIngresado,auxiliarString,tamStringIngresado);
				retorno = 1;
				break;
			}

           utn_cantDeReintentos(&reintentos,mensajeError);
           reintentos--;

		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_esSexoF_M_oNoBinarioDeTam_(char* cadena, int tamCadena)
{
	int retorno = 0;

	if(cadena != NULL && tamCadena > 0)
	{
        if(utn_esFemenino_O_MasculinoDeTam_(cadena,tamCadena) || utn_esSexo_NoBinarioDeTam_(cadena,tamCadena) )
        {
            retorno = 1;
        }

	}

	return retorno;
}

int utn_esFemenino_O_MasculinoDeTam_(char* cadena, int tamCadena)
{
    int retorno;
    retorno = 0;

    if(cadena != NULL && tamCadena > 0 && strlen(cadena) == 1 )
	{
		for(int i = 0 ; cadena[i] != '\0' && i < tamCadena ; i++)
		{
				if( cadena[0] == 'f' || cadena[0] == 'm' || cadena[0] == 'F' || cadena[0] == 'M')
                {
					retorno = 1;
					break;
                }
		}
	}

    return retorno;
}


int utn_esSexo_NoBinarioDeTam_(char* cadena, int tamCadena)
{
    int retorno;
    retorno = 0;

    for(int i = 0 ; cadena[i] != '\0' && i < tamCadena; i++)
    {
        if (  (cadena[0] == 'n' || cadena[0] == 'N') && (cadena[1] == 'b' || cadena[1] == 'B')  )
        {
            retorno = 1;
            break;
        }
    }

    return retorno;

}

int utn_pIngresoDeCaracter_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos)
{
	char auxiliarString[4096];
	int retorno = 0;

	if(mensaje != NULL &&  mensajeError != NULL
                && tamStringIngresado > 0 && pResultadoStringIngresado != NULL && reintentos >= 0)
	{

		do
		{
			printf("%s",mensaje);

			if(utn_obtenerString(auxiliarString, sizeof(auxiliarString))
                                        && strnlen(auxiliarString, sizeof(auxiliarString)) == 1  )
			{
				strncpy(pResultadoStringIngresado,auxiliarString,tamStringIngresado);
				retorno = 1;
				break;
			}

           utn_cantDeReintentos(&reintentos,mensajeError);
           reintentos--;

		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_pIngresoDeLaCadena_DeTam_(char* pResultadoStringIngresado,int tamStringIngresado, char* mensaje, char* mensajeError, int reintentos)
{
	char auxiliarString[4096];
	int retorno = 0;

	if(mensaje != NULL &&  mensajeError != NULL
                && tamStringIngresado > 0 && pResultadoStringIngresado != NULL && reintentos >= 0)
	{

		do
		{
			printf("%s",mensaje);

			if(utn_obtenerString(auxiliarString, sizeof(auxiliarString))
                                        && strnlen(auxiliarString, sizeof(auxiliarString)) < tamStringIngresado)
			{
				strncpy(pResultadoStringIngresado,auxiliarString,tamStringIngresado);
				retorno = 1;
				break;
			}

           utn_cantDeReintentos(&reintentos,mensajeError);
           reintentos--;

		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_obtenerString(char* cadena, int tamCadena)
{
    int retorno = 0;
    char bufferString[4096];

	if(cadena != NULL && tamCadena > 0)
	{
		if( utn_copiaElementoTipoCadenaEn_DeTam_(bufferString,sizeof(bufferString))
                                        && utn_esCadena(bufferString, sizeof(bufferString))
                                                    && strnlen(bufferString,sizeof(bufferString)) < tamCadena)
		{
			strncpy(cadena,bufferString,tamCadena);
			retorno = 1;
		}
	}

    return retorno;
}


int utn_esCadena(char* cadena, int tamCadena)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && tamCadena > 0)
	{
		for(i = 0 ; cadena[i] != '\0' && i < tamCadena; i++)
		{
			if(cadena[i]== 32)
			{
				continue;
			}
				if( (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') )
				{
					retorno = 0;
					break;
				}
		}
	}

	return retorno;
}




int utn_stringCompletoDeApellido_Ynombre_(char* pNombre,int tamNombre,char* pApellido,int tamApellido ,char* pCompleto, int tamCompleto)
{
	int retorno;
	retorno = 0;

	if(pNombre != NULL && pApellido != NULL && tamNombre > 0 && tamApellido > 0 && tamCompleto > 0)
    {

        if(utn_pIngresoDeLaCadena_DeTam_(pNombre,tamNombre, "ingrese nombre", "error", 3) &&
           utn_pIngresoDeLaCadena_DeTam_(pApellido,tamApellido, "ingrese apellido", "error", 3) )
        {

                //utn_colocaMayusculaAPrimerLetraDe_(pNombre,tamNombre);

                //utn_colocaMayusculaAPrimerLetraDe_(pApellido,tamApellido);

                utn_stringModeladoNombre_YApellido_(pNombre,pApellido,pCompleto);

                strlwr(pCompleto);

                utn_colocaMayusculaEnPrimeraLetraDelNombre_yAPellido_(pCompleto,strlen(pCompleto));

                retorno=1;
        }
        else
        {
            printf("no se pudo cargar");
            retorno = 0;
        }

    }

	return retorno;
}


int utn_stringModeladoNombre_YApellido_(char* pNombre,char* pApellido,char* pCompleto)
{
    int retorno;
    retorno=0;

    if(pNombre != NULL && pApellido != NULL)
    {
        strcat(pApellido, ",");

        strcat(pApellido, " ");

        strcat(pApellido,pNombre);

        strcpy(pCompleto,pApellido);

        retorno = 1;
    }

    return retorno;
}


int utn_colocaMayusculaEnPrimeraLetraDelNombre_yAPellido_(char* pCompleto, int tamCompleto)
{
    int retorno;
    retorno = 0;

    if(pCompleto != NULL && tamCompleto > 0)
    {
            //*(pCompleto + 0) = toupper(*(pCompleto + 0) );
            utn_colocaMayusculaAPrimerLetraDe_( pCompleto + 0);

        for(int i= 0; i < tamCompleto ;i++)
        {

            if(isspace( *(pCompleto + i)  ))
            {
                  //(*(pCompleto + (i + 1) )) = toupper(*(pCompleto + (i + 1) )) ; primera opcion sin funcion
                  //utn_colocaMayusculaAPrimerLetraDe_( (pCompleto + (i + 1) ));  segunda opcion con funcion


                  //otra opcion mas limpia, suma la iteracion y pasa la direccion de memoria
                  i++;
                  utn_colocaMayusculaAPrimerLetraDe_(pCompleto + i );

            }
        }

        retorno = 1;
    }

    return retorno;
}


int utn_colocaMayusculaAPrimerLetraDe_(char* pPalabra)
{
    int retorno;
    retorno=0;

    if(pPalabra != NULL)
    {
        //pNombre[0] = toupper(pNombre[0]); //vectorial

         *(pPalabra + 0) = toupper(*(pPalabra + 0) ) ; //aritmeitica de punteros

        retorno = 1;
    }


    return retorno;
}




int utn_contarPalabrasDe_ConTam_(char* cadenaIngresada,int* pResultadoCadena)
{
    int retorno;
    retorno=0;
    int contadorPalabras;
    contadorPalabras=1;

    if(cadenaIngresada != NULL && pResultadoCadena != NULL && strlen(cadenaIngresada) > 0)
    {
        for(int i=0; i < strlen(cadenaIngresada);i++)
        {
            if(isspace(  *(cadenaIngresada + i) ) && !isdigit( *(cadenaIngresada + (i + 1) ) )    )
            {
                contadorPalabras++; //(*(pCompleto + (i + 1) ))
            }
            retorno=1;

        }
    }
    *pResultadoCadena=contadorPalabras++;

    return retorno;
}



int utn_contarLetrasDe_ConTam_(char* cadenaIngresada,int* pResultadoCadena)
{
    int retorno;
    retorno=0;
    int contadorLetras;
    contadorLetras=0;

    if(cadenaIngresada != NULL && pResultadoCadena != NULL && strlen(cadenaIngresada) > 0)
    {
        for(int i=0; i < strlen(cadenaIngresada);i++)
        {
            if(isspace( *(cadenaIngresada + i)  ))
            {
                continue;
            }
            contadorLetras++;
            retorno=1;
        }
    }

    *pResultadoCadena=contadorLetras++;

    return retorno;
}


int utn_strLenDeCadena_(char* cadena,int* pContador)
{
    int contador;
    contador=0;
    int retorno;
    retorno = 0;

    if(cadena != NULL)
    {
        for(int i = 0; *(cadena + i) != '\0'; i++)
        {
            contador++;
            retorno = 1;
        }
    }

    *pContador = contador;

    return retorno;
}

int utn_pasarCadena_AMayuscula(char* cadena)
{

    int retorno;
    retorno=0;

    if(cadena != NULL)
    {
        for(int i = 0; *(cadena + i) != '\0'; i++)
        {
            if(cadena >= 97 && cadena[i] <= 122 )
            {
                *(cadena + i) = *(cadena + i) - 32;
                  retorno=1;
            }
        }
                //cadena[i] - 32;
    }

    return retorno;
}



int utn_reemplazarCaracter_PorCaracter_EnVectorDeCaracter_DeTam_(char* nuevoCaracter, char caracterAReemplazar ,char* pListaDeCaracteres, int tamListaDeCaracteres)
{

    int retorno;
    retorno=0;

    if(pListaDeCaracteres != NULL && tamListaDeCaracteres > 0)
    {
        for(int i = 0; i < tamListaDeCaracteres ; i++)
        {
            if( *(pListaDeCaracteres + i) ==  caracterAReemplazar)
            {
                *(pListaDeCaracteres + i) = *nuevoCaracter;
                 retorno=1;
            }
        }
    }

    return retorno;
}




int utn_pVerificaCaracter_En_ConTam_(char* caracterABuscar, char* pListaDeCaracteres, int tamListaDeCaracteres)
{

    int retorno;
    retorno = 0;

    if(pListaDeCaracteres != NULL && tamListaDeCaracteres > 0)
    {
        for(int i = 0; i < tamListaDeCaracteres ; i++)
        {
            if( *(pListaDeCaracteres + i) == caracterABuscar  )
            {
               retorno = 1;
                break;
            }
        }
    }

    return retorno;
}



int utn_pMuestraVector_ElementosTipoCadenaOCaracterDeTam_(char* pListaDeElementos, int tamListaDeElementos)
{
    int retorno;
    retorno=0;


    if( pListaDeElementos != NULL && tamListaDeElementos > 0 )
    {
        for(int i = 0; i < tamListaDeElementos ; i++)
        {
             //printf("%c", *(pListaDeElementos + i) );
             retorno=1;
             utn_pMuestraUnElementoTipoCadenaOCaracter_(pListaDeElementos + i);
        }
    }

    return(retorno);

}


int utn_pMuestraUnElementoTipoCadenaOCaracter_(char* unElementoTipoCaracter)
{
    int retorno;
    retorno=0;

    if( unElementoTipoCaracter != NULL )
    {
            printf("%c", *unElementoTipoCaracter );
            retorno=1;
    }

    return retorno;
}





int utn_pActivarFlag_(int* pFlag)
{
    int retorno;
    retorno=0;

    if(pFlag != NULL)
    {
        *pFlag = 1;
        retorno=1;
    }

    return(retorno);
}

int utn_pResetFlag(int* pFlag)
{
    int retorno;
    retorno=0;

    if(pFlag != NULL)
    {
        *pFlag = 0;
        retorno=1;
    }

    return(retorno);
}



//FLOTANTES


int utn_pInicializaVector_ElementosTipoFlotanteDeTam_(float* pVectorElementosTipoFlotante,int tamVectorElementosTipoFlotante)
{
	int retorno;
	retorno=0;

	if(pVectorElementosTipoFlotante != NULL && tamVectorElementosTipoFlotante > 0)
	{
		for(int i=0; i < tamVectorElementosTipoFlotante ;i++)
		{
			utn_pInicializaUnElementoTipoFlotante_(pVectorElementosTipoFlotante + i);
            retorno=1;
		}
	}

	return retorno;
}


int utn_pInicializaUnElementoTipoFlotante_(float* pUnElementoTipoFlotante)
{
	int retorno;
	retorno=0;

	if(pUnElementoTipoFlotante != NULL)
    {
        *pUnElementoTipoFlotante = 0 ;
        retorno=1;
    }

	return retorno;
}


int utn_pCargaVector_ElementosTipoFlotanteConTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante)
{
	int retorno;
	retorno = 0;

	if( pListaElementosTipoFlotante != NULL && tamListaElementosTipoFlotante > 0)
	{

		for(int i=0; i < tamListaElementosTipoFlotante ; i++)
		{
           utn_pIngresoDeElementoTipoFlotante_( pListaElementosTipoFlotante + i ,"ingrese un numero", "error\n",0, 100, 1);
           retorno=1;
		}
	}

	return retorno;
}

int utn_pMuestraVector_ElementoTipoFlotanteConTam_(float* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante)
{
	int retorno;
	retorno=0;

	if( pListaElementosTipoFlotante != NULL && tamListaElementosTipoFlotante > 0 )
	{
	    printf("***Array Cargado***\n");

		for(int i=0; i< tamListaElementosTipoFlotante ; i++)
		{

            if(!utn_esElemento_TipoFlotanteElementoInicializador( pListaElementosTipoFlotante + i ) )
            {
                 utn_pMuestraUnElemento_TipoFlotanteConTam_(pListaElementosTipoFlotante + i);
                 retorno = 1;
            }
            else
            {
                 printf(" error posicion %d no inicializada, no hay numero\n", i + 1 );
            }
		}
	}

    return retorno;
}


int utn_pMuestraUnElemento_TipoFlotanteConTam_(float* pUnElementoTipoFlotante)
{
	int retorno;
	retorno=0;

         printf(" numero: %f \n" ,*(pUnElementoTipoFlotante) );

    return retorno;
}


int utn_esElemento_TipoFlotanteElementoInicializador(float* pUnElementoTipoFlotante)
{
    int retorno;
    retorno = 0;

    if( *pUnElementoTipoFlotante == 0)
    {
        retorno = 1;
    }

    return retorno;
}


int utn_pPromedioVectorElementosTipoFlotante_DeTam_(float* pListaElementosTipoFlotante,
                                                            int tamListaElementosTipoFlotante,
                                                                            float* pResultadoPromedio)
{
    int retorno;
    retorno=0;
    float acumulador;
    acumulador=0;
    int contadorElementosIngresados;
    contadorElementosIngresados=0;

    if( pListaElementosTipoFlotante != NULL && pResultadoPromedio!= NULL && tamListaElementosTipoFlotante > 0)
    {
         for(int i=0; i < tamListaElementosTipoFlotante ; i++ )
        {
            if( !utn_esElemento_TipoFlotanteElementoInicializador( pListaElementosTipoFlotante + i) )
            {
                utn_pAgregaElementoFlotante_EnELAcumulador_( pListaElementosTipoFlotante + i, &acumulador);
                contadorElementosIngresados++;
                retorno=1;
            }
        }
    }

    *pResultadoPromedio = acumulador / contadorElementosIngresados;

    return( retorno);
}


int utn_pAgregaElementoFlotante_EnELAcumulador_(float* pUnElementoTipoFlotante,float* pAcumulador)
{
	int retorno;
	retorno=0;

	if( pAcumulador != NULL && pUnElementoTipoFlotante != NULL)
	{
	    *pAcumulador += *pUnElementoTipoFlotante;
	    retorno = 1;
	}

    return retorno;
}


int utn_pAcumuladorDeVector_ElementoTipoFlotanteDeTam_(int* pListaElementosTipoFlotante,int tamListaElementosTipoFlotante,float* pAcumulador)
{
	int retorno;
	retorno=0;

	if( pListaElementosTipoFlotante != NULL && tamListaElementosTipoFlotante > 0 && pAcumulador != NULL)
	{
	    for(int i=0; i < tamListaElementosTipoFlotante ; i++ )
        {

             utn_pAgregaElementoFlotante_EnELAcumulador_( pListaElementosTipoFlotante + i, pAcumulador);
             retorno=1;
        }
	}

    return retorno;
}



int utn_pIngresoDeElementoTipoFlotante_(float* pUnElementoTipoFlotante,char* pMensaje, char* pMensajeError,int rangoMinimo,int rangoMaximo, int reintentos)
{
	int retorno = 0;
	float auxiliarFlotante; //bufferFloat

	if( pMensaje != NULL && rangoMinimo < rangoMaximo && pMensajeError != NULL && pUnElementoTipoFlotante != NULL && reintentos > 0)
	{
		do
		{
			printf("%s", pMensaje);

			if( utn_pObtieneElementoTipoFlotante_(&auxiliarFlotante)&& pUnElementoTipoFlotante != NULL && pMensaje != NULL && pMensajeError != NULL
					&& reintentos >= 0 && auxiliarFlotante >= rangoMinimo && auxiliarFlotante <= rangoMaximo)
			{
				retorno = 1;
				*pUnElementoTipoFlotante = auxiliarFlotante;
				break;
			}

           utn_cantDeReintentos(&reintentos,pMensajeError);
           reintentos--;

		}while(reintentos >= 0);
	}

	return retorno;
}


int utn_pObtieneElementoTipoFlotante_(float* pElementoFlotante)
{
	int retorno = 0;
	char auxiliarString[4096];

	if(pElementoFlotante != NULL && utn_copiaElementoTipoCadenaEn_DeTam_(auxiliarString, sizeof(auxiliarString))
                                        && utn_esElemento_Flotante(auxiliarString, sizeof(auxiliarString)) )
	{
		*pElementoFlotante = atof(auxiliarString);
		retorno = 1;
	}
	return retorno;
}


int utn_esElemento_Flotante(char* pUnElementoTipoCadena, int tamElementoTipoCadena)
{
	int retorno = 1;
	int contadorPuntos = 0;

	/*
        3.31 "+31.8"  "-5.8"  ".56"  "-.562"

        "+.89"

        // esta mal "31562." "-4586."
	*/

	if(pUnElementoTipoCadena != NULL && tamElementoTipoCadena > 0)
	{
		for(int i = 0; i < tamElementoTipoCadena && pUnElementoTipoCadena[i] != '\0'; i++)
		{
			if(i == 0 && ( *(pUnElementoTipoCadena + i) == '-' || *(pUnElementoTipoCadena + i) == '+' ) )
            {
                continue;
            }
			if( *(pUnElementoTipoCadena + i) < '0' || *(pUnElementoTipoCadena + i) > '9' )
			{
                if(*(pUnElementoTipoCadena + i) == '.' && contadorPuntos == 0 )
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno=0;
                    break;
                }
             }
		}
	}

	return retorno;
}





//ENTEROS



int utn_pInicializaVector_ElementosTipoEnteroDeTam_(int* pVectorElementosTipoEntero,int tamVectorElementosTipoEntero)
{
	int retorno;
	retorno=0;

	if(pVectorElementosTipoEntero != NULL && tamVectorElementosTipoEntero > 0)
	{
		for(int i=0; i < tamVectorElementosTipoEntero ;i++)
		{
			utn_pInicializaUnElementoTipoEntero_(pVectorElementosTipoEntero + i);
            retorno=1;
		}
	}

	return retorno;
}



int utn_pInicializaUnElementoTipoEntero_(int* pUnElementoTipoEntero)
{
	int retorno;
	retorno=0;

	if(pUnElementoTipoEntero != NULL)
    {
        *pUnElementoTipoEntero = 0;
        retorno=1;
    }

	return retorno;
}


int utn_pCargaVector_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
	int retorno;
	retorno = 0;

	if(pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0)
	{

		for(int i=0;i < tamListaElementosTipoEntero ; i++)
		{
           utn_pIngresoDeElementoTipoEntero_( (pListaElementosTipoEntero + i) ,"ingrese un entero", "error\n",-1000, 1000, 3);
           retorno=1;
		}
	}

	return retorno;
}


int utn_pMuestraVector_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
	int retorno;
	retorno=0;

	if(pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0 )
	{
	    printf("***Lista de Elementos Enteros***\n");

		for(int i=0; i< tamListaElementosTipoEntero; i++)
		{
		    if(!utn_esElemento_TipoEnteroElementoInicializador( pListaElementosTipoEntero + i ) )
            {
                 utn_pMuestraUnElemento_TipoEnteroConTam_(pListaElementosTipoEntero + i);
                 retorno = 1;
            }
            else
            {
                 printf(" error posicion no inicializada\n");
            }
		}

	}

    return retorno;
}



int utn_pCargaAleatoriaVector_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
    int retorno;
    retorno = 0;
	int i;
	char seguir;
	seguir='s';
	int numero;

	do
	{
        utn_pIngresoDeElementoTipoEntero_(&numero,"ingrese numero entre -50 y 75: ", "error, reingrese un numero ", -50 ,75, 3);

         utn_pIngresoDeElementoTipoEntero_(&i,"ingrese un numero de indice del 1 al 3: ","error, reingrese un numero ", 1,3, 3);

        pListaElementosTipoEntero[i-1] = numero;

        printf("desea seguir ingresando numeros si (s) o no (n)");
        fflush(stdin);
        scanf("%c",&seguir);
        retorno=1;

	}while(seguir!='n');

    return retorno;

}

int utn_pMuestraVectorAleatorio_ElementosTipoEnteroConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
    int retorno;
    retorno = 0;

    printf("***Lista de Numeros***\n");

    for(int i=0; i < tamListaElementosTipoEntero ; i++)
    {
        if(!utn_esElemento_TipoEnteroElementoInicializador( pListaElementosTipoEntero + i ))
        {
           utn_pMuestraUnElemento_TipoEnteroConTam_( pListaElementosTipoEntero + i );
           retorno=1;
        }
    }

    return retorno;
}


int utn_pMuestraUnElemento_TipoEnteroConTam_(int* pUnElementoTipoEntero)
{
   int retorno;
   retorno=0;

        if(pUnElementoTipoEntero != NULL )
        {
            printf(" %d \n",*(pUnElementoTipoEntero) );
            retorno = 1;
        }

    return retorno;
}


int utn_esElemento_TipoEnteroElementoInicializador(int* pUnElementoTipoEntero)
{
    int retorno;
    retorno = 0;

    if(*pUnElementoTipoEntero == 0)
    {
        retorno = 1;
    }

    return retorno;
}




int utn_pIngresoDeAnioTipoEntero_(int* pUnElementoTipoEntero,char* mensaje ,char* pMensajeError, int rangoMinimo,int rangoMaximo, int reintentos)
{
	int retorno = 0;
	int auxiliarEntero;

	if( rangoMinimo <= rangoMaximo && pMensajeError != NULL && pUnElementoTipoEntero != NULL && reintentos >= 0)
	{
		do
		{

            printf("\n\n A%cO %s",165,mensaje);


			if(utn_pObtieneElementoTipoEntero_(&auxiliarEntero) && pUnElementoTipoEntero != NULL && pMensajeError != NULL
				&& reintentos >= 0 && auxiliarEntero >= rangoMinimo && auxiliarEntero <= rangoMaximo && rangoMinimo <= rangoMaximo)
			{
				retorno = 1;

				*pUnElementoTipoEntero = auxiliarEntero;

				break;
			}

           utn_cantDeReintentos(&reintentos,pMensajeError);
           reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}



int utn_pIngresoDeElementoTipoEntero_(int* pUnElementoTipoEntero,char* pMensaje, char* pMensajeError,int rangoMinimo,int rangoMaximo, int reintentos)
{
	int retorno = 0;
	int auxiliarEntero;

	if(pMensaje != NULL && rangoMinimo <= rangoMaximo && pMensajeError != NULL && pUnElementoTipoEntero != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);

			if(utn_pObtieneElementoTipoEntero_(&auxiliarEntero) && pUnElementoTipoEntero != NULL && pMensaje != NULL && pMensajeError != NULL
				&& reintentos >= 0 && auxiliarEntero >= rangoMinimo && auxiliarEntero <= rangoMaximo && rangoMinimo <= rangoMaximo)
			{
				retorno = 1;

				*pUnElementoTipoEntero = auxiliarEntero;

				break;
			}

           utn_cantDeReintentos(&reintentos,pMensajeError);
           reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}


int utn_pObtieneElementoTipoEntero_(int* pUnElementoTipoEntero)
{
	int retorno = 0;
	char auxiliarCadena[4096];

	if(pUnElementoTipoEntero != NULL && utn_copiaElementoTipoCadenaEn_DeTam_(auxiliarCadena, sizeof(auxiliarCadena))
                                                    && utn_esElemento_Numerico(auxiliarCadena,sizeof(auxiliarCadena)) )

    {
        *pUnElementoTipoEntero = atoi(auxiliarCadena);
        retorno = 1;
    }

	return retorno;
}


int utn_copiaElementoTipoCadenaEn_DeTam_(char* pUnElementoTipoCadena, int tamElementoTipoCadena)
{
	int retorno = 0;
	//char auxiliarString[4096];
	char auxiliarCadena[4096];

	if(pUnElementoTipoCadena != NULL && tamElementoTipoCadena > 0)
	{
		fflush(stdin);

		if(fgets(auxiliarCadena,sizeof(auxiliarCadena),stdin) != NULL)
		{
			if(auxiliarCadena[strlen(auxiliarCadena)-1] == '\n')
			{
				auxiliarCadena[strlen(auxiliarCadena)-1] = '\0';
			}

			if(strlen(auxiliarCadena) <= tamElementoTipoCadena)
			{
				strncpy(pUnElementoTipoCadena ,auxiliarCadena,tamElementoTipoCadena);
				retorno = 1;
			}
		}
	}

	return retorno;
}



//ME FALTO ARREGLAR QUE PASA SI INGRESARMOS UN - Y LUEGO COLOCAMOS EL ENTER

int utn_esElemento_Numerico(char* pUnElementoTipoCadena, int tamElementoTipoCadena)
{
	int retorno = 1;

	if(pUnElementoTipoCadena != NULL && tamElementoTipoCadena > 0)
	{
		for(int i = 0; i < tamElementoTipoCadena && *(pUnElementoTipoCadena + i) != '\0'; i++)
		{
			if(i == 0 && ( *(pUnElementoTipoCadena + i) == '-' || *(pUnElementoTipoCadena + i) == '+' ))
			{
				continue;
			}

			if(i == 0 && ( *(pUnElementoTipoCadena + 0) == '-' &&  *(pUnElementoTipoCadena + 1) == '-' ) ||

                 (*(pUnElementoTipoCadena + 0) == '+' && *(pUnElementoTipoCadena +  1) == '-' )  )
			{
				retorno=0;
			}

            if(*(pUnElementoTipoCadena + i) < '0' || *(pUnElementoTipoCadena + i) > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief describe una cantidad de reintentos y devuelve un
            mensaje deteminado dependiendo del mensaje que sea.
 *
 * \param reintentos TIPO DIRECCION DE MEMORIA ENTERO se le pasa la
                     cantidad de reintentos
 * \param char mensajeError DIRECCION DE MEMORIA STRING
 * \return
 */
int utn_cantDeReintentos(int* reintentos,char* mensajeError)
{
    int reintentosRestantes;
    reintentosRestantes = *reintentos;

    switch(*(reintentos))
    {
        case 0:

                if(*reintentos > 0)
                {
                    printf("\n INTENTOS FINALIZADOS \n");
                }

        break;

        case 1:
                printf("%s",mensajeError);
                printf("\n ULTIMO REINTENTO: ");
        break;

        default:

                printf("%s",mensajeError);
                printf("\n MENU REINTENTOS \n");
                printf("\n SUS INTENTOS RESTANTES SON: %d ",reintentosRestantes);
                reintentosRestantes--;
        break;
    }

    return(0);
}


int utn_calcularEdad(int anioActual ,int anioNacimientoEmpleado ,int* pEdad,int* edadMinima,int* edadLimite)
{
    int retorno;
    retorno=0;
    int auxEdad;

    if( pEdad != NULL && anioActual > anioNacimientoEmpleado && edadMinima != NULL )
    {
        if(  (anioActual - anioNacimientoEmpleado) > edadLimite )
        {
            printf("\n ERROR, EL A%cO DE NACIMIENTO INGRESADO DEL EMPLEADO SUPERA LOS 120 A%cOS \n",165,165);
             retorno = 0;

        }
        if((anioActual - anioNacimientoEmpleado) < edadMinima)
        {
            printf("OCURRIO UN ERROR, EL EMPLEADO ES MENOR DE EDAD, ");

            retorno = 0;
        }
        else
        {
                    auxEdad =  anioActual - anioNacimientoEmpleado;
                    retorno=1;
                    *pEdad = auxEdad;
        }
    }
    else
    {
            printf("\n ERROR, EL A%cO DE NACIMIENTO INGRESADO ES MAYOR QUE ESTE A%cO\n",165,165);
    }

    return retorno;
}


//INFORMES

int utn_CantidadElementosTipoEnteroPositivos_Y_NegativosEn_ConTam_(int* pListaElementosTipoEntero,
                                                                   int tamListaElementosTipoEntero,
                                                                   int* cantidadNegativos,
                                                                   int* cantidadPositivos)
{
    int retorno;
    retorno=0;
    int contadorNegativos;
    int contadorPositivos;
    contadorNegativos=0;
    contadorPositivos=0;

    for(int i=0;i<tamListaElementosTipoEntero;i++)
    {

        switch(utn_pSignoDelNumeroEntero_( pListaElementosTipoEntero + i ))
        {

            case 1:
							contadorPositivos++;
                            retorno = 1;
            break;

            case 0:
							contadorNegativos++;
                            retorno = -1;
            break;

         }
    }

     *cantidadNegativos = contadorNegativos;
     *cantidadPositivos = contadorPositivos;

    return retorno;
}



int utn_CantidadElementosTipoEnteroNegativosEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,
                                                                                               int* cantidadNegativos)
{
     int retorno;
	 retorno = 0;
	 int contadorNegativos;
	 contadorNegativos=0;

	 if(pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0)
     {
        for(int i = 0; i < tamListaElementosTipoEntero ;i++)
        {


            if(*(pListaElementosTipoEntero + i) == 0)
            {
                 continue;
            }


            if(!utn_pSignoDelNumeroEntero_(pListaElementosTipoEntero + i)  )
            {
                contadorNegativos++;
                retorno=1;
            }
        }
	 }

    *cantidadNegativos = contadorNegativos;

    return retorno;
}


int utn_CantidadElementosTipoEnteroPositivosEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,
                                                                                                   int* cantidadPositivos)
{
     int retorno;
	 retorno = 0;
	 int contadorPositivos;
	 contadorPositivos=0;

	 if(pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0)
     {
        for(int i = 0; i < tamListaElementosTipoEntero ; i++)
        {


            if(*(pListaElementosTipoEntero + i) == 0)
            {
                 continue;
            }


            if(utn_pSignoDelNumeroEntero_(pListaElementosTipoEntero + i)  )
            {
                contadorPositivos++;
                retorno=1;
            }
        }
	 }

    *cantidadPositivos = contadorPositivos;

    return retorno;
}


int utn_pSignoDelNumeroEntero_(int* pUnElementoTipoEntero)
{
	int retorno;
	retorno=0;

	if( *pUnElementoTipoEntero > 0)
	{
		retorno = 1;
	}

	return retorno;
}


int utn_pSumatoriaElementosParesDelVector_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* sumatoriaPares)
{
     int retorno;
     retorno=0;
	 int acumuladorElementosPares;
	 acumuladorElementosPares= 0;

	 for(int i = 0; i < tamListaElementosTipoEntero ;i++)
	 {
	 	  if(utn_esElemento_Par(pListaElementosTipoEntero + i) )
	 	  {
                //*sumatoriaImpares += *arrayNumeros; //TAMBIEN SE PUEDE DE ESTA FORMA

                utn_pAgregaElementoEntero_EnELAcumulador_(pListaElementosTipoEntero + i, &acumuladorElementosPares);
                retorno=1;
          }
	  }

     *sumatoriaPares += acumuladorElementosPares;

	 return retorno;
}

int utn_pAgregaElementoEntero_EnELAcumulador_(int* pUnElementoTipoEntero,int* acumulador)
{
	int retorno;
	retorno=0;

	if(acumulador != NULL && pUnElementoTipoEntero != NULL)
	{
	    *acumulador += *pUnElementoTipoEntero;
	}

    return retorno;
}


int utn_pMayorElementoEnteroImparDe_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pMaximoImpar)
{
    int retorno;
    retorno=0;
    int flag;
    flag=0;
    int auxMaximoImpar;

	  for(int i=0; i < tamListaElementosTipoEntero; i++)
	  {
		  if(!utn_esElemento_Par(pListaElementosTipoEntero + i))
		  {

                if(flag ==0 || *(pListaElementosTipoEntero + i) > auxMaximoImpar )
                {
                    auxMaximoImpar = *(pListaElementosTipoEntero + i);
                    flag = 1;
                    retorno=1;
                }
		  }
	  }

    *pMaximoImpar = auxMaximoImpar;

    return retorno;
}


int utn_esElemento_Par(int* unElementoEntero)
{
	int retorno;
	retorno = 0;


	if( *unElementoEntero % 2 == 0 )
	{
		retorno = 1;
	}

	return retorno;
}

int utn_pMayorElementoTipoEnteroDeVector_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pMayorElemento)
{
	int retorno;
	retorno=0;
	int flag;
	flag = 0;
    int auxMayorElemento;

        if(pListaElementosTipoEntero != NULL && pMayorElemento != NULL && tamListaElementosTipoEntero > 0 )
        {
            for(int i=0; i<tamListaElementosTipoEntero; i++)
            {
                if(flag ==0 || *(pListaElementosTipoEntero + i) > auxMayorElemento )
                {
                    auxMayorElemento = *(pListaElementosTipoEntero + i);
                    flag = 1;
                    retorno=1;
                }
            }
        }

        *pMayorElemento = auxMayorElemento;


      return retorno;
}

int utn_pMenorElementoTipoEnteroDeVector_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pMenorElemento)
{
	int retorno;
	retorno=0;
	int flag;
	flag = 0;
    int auxMenorElemento;

        if(pListaElementosTipoEntero != NULL && pMenorElemento != NULL && tamListaElementosTipoEntero > 0 )
        {
            for(int i=0; i < tamListaElementosTipoEntero; i++)
            {
                if(flag ==0 || *(pListaElementosTipoEntero + i) < auxMenorElemento )
                {
                    auxMenorElemento = *(pListaElementosTipoEntero + i);
                    flag = 1;
                    retorno=1;
                }

                *pMenorElemento = auxMenorElemento;
            }
        }

	return retorno;
}


int utn_pMuestraDeElementosTipoEnteroPar_ConTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
	int retorno;
	retorno=0;

	if( pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0 )
	{
	    printf(" los numeros pares del array son:\n");

		for(int i=0; i< tamListaElementosTipoEntero ; i++)
		{
		    if(!utn_esElemento_TipoEnteroElementoInicializador(pListaElementosTipoEntero + i) && utn_esElemento_Par(pListaElementosTipoEntero + i) )
            {
                 printf(" posicion: %d numero: %d \n", i + 1 ,*(pListaElementosTipoEntero + i ) );
                 retorno = 1;
            }
            else
            {
                printf("  no se ingresaron numeros pares en esta posicion\n");
            }
		}
	}

    return retorno;
}


int utn_pPosicionDeElementosTipoEnteroParEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
      int retorno;
      retorno=0;
	  int flag;
	  flag=0;

	  	 for(int i=0; i < tamListaElementosTipoEntero ;i++)
	  	 {
	  	 	  if( utn_esElemento_Par( &i ) )
	  	 	  {
                    utn_pMuestraUnElemento_TipoEntero( pListaElementosTipoEntero + i, "posicion par, numero: \n" );
                    flag=1;
                    retorno=1;
	  	 	  }
	  	  }

	  	 if(flag==0)
	  	 {
	  		 printf("no se ingresaron numeros impares\n");
	  	 }


    return retorno;

}


int utn_posicionesDeVector_DondeSeEncuentraElElementoMayor(int* plistaElementosTipoEntero, int tamListaElementosTipoEntero, int* pMayorElemento)
{
    if(plistaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0)
    {
        printf("posiciones del array en donde se encuentra el mayor: \n");
        for(int i = 0; i < tamListaElementosTipoEntero; i++)
        {
            //acumulador= acumulador + numeros[i]);

            if( *(plistaElementosTipoEntero + i) == *(pMayorElemento) )
            {
                printf("posiciones en donde se encuentra el elemento mayor: %d \n", i+1);
            }
        }
    }


    return 0;
}



int utn_pMuestraUnElemento_TipoEntero(int* unElementoTipoEntero,char* mensaje)
{

    int retorno;
    retorno=0;

    if( unElementoTipoEntero != NULL && mensaje != NULL)
    {
        printf("%s",mensaje);
        printf("%d\n", *unElementoTipoEntero);
        retorno = 1;
    }

    return retorno;
}



int utn_pMostrarVector_TipoCaracterDeTam_(char* pListaDeCaracteres, int tamListaDeCaracteres)
{
    int retorno;
    retorno=0;

    if( pListaDeCaracteres != NULL && tamListaDeCaracteres > 0 )
    {
        for(int i = 0; i < tamListaDeCaracteres ; i++)
        {
            utn_pMostrarUnCaracter_(pListaDeCaracteres + i);
            retorno=1;
        }
    }

    return(retorno);
}


int utn_pMostrarUnCaracter_(char* unCaracter)
{
    int retorno;
    retorno=0;

    if( unCaracter != NULL )
    {
            printf("%c\n", *unCaracter );
            retorno=1;
    }

    return retorno;
}


int utn_pPosicionDeElementosTipoEnteroImparEn_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero)
{
      int retorno;
      retorno=0;
	  int flag;
	  flag=0;

	  	 for(int i=0; i < tamListaElementosTipoEntero ;i++)
	  	 {
	  	 	  if( !utn_esElemento_Par( &i ) )
	  	 	  {
                    utn_pMuestraUnElemento_TipoEnteroConTam_( pListaElementosTipoEntero + i );
                    flag=1;
                    retorno=1;
	  	 	  }
	  	  }

	  	 if(flag==0)
	  	 {
	  		 printf("no se ingresaron numeros impares\n");
	  	 }


    return retorno;

}


int utn_pPromedioVectorElementosTipoEntero_DeTam_(int* pListaElementosTipoEntero,
                                                            int tamListaElementosTipoEntero,
                                                                            float* pResultadoPromedio)
{
    int retorno;
    retorno=0;
    int acumulador;
    acumulador=0;
    int contadorElementosIngresados;
    contadorElementosIngresados=0;

        if( pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0 && pResultadoPromedio!= NULL)
        {
            for(int i=0; i < tamListaElementosTipoEntero ; i++ )
            {
                if( *(pListaElementosTipoEntero + i) != 0 )
                {
                     utn_pAgregaElementoEntero_EnELAcumulador_( (pListaElementosTipoEntero + i) , &acumulador);
                     contadorElementosIngresados++;
                     retorno=1;
                }
            }
        }

    *pResultadoPromedio =  (float) acumulador / contadorElementosIngresados ;

    return retorno;
}

int utn_pAcumuladorDeVector_ElementoTipoEnteroDeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero ,int* pAcumulador)
{
	int retorno;
	retorno=0;


	if( pListaElementosTipoEntero != NULL && pAcumulador != NULL && tamListaElementosTipoEntero > 0 )
	{
	    for(int i=0; i < tamListaElementosTipoEntero ; i++ )
        {
             utn_pAgregaElementoEntero_EnELAcumulador_( (pListaElementosTipoEntero + i), pAcumulador);
             retorno=1;
        }
	}

    return retorno;
}


int utn_calculaElMayorEntreElemento_y_(int* unElemento,int* otroElemento,int* pResultado)
{
    int retorno;
    retorno=-1;

    if( unElemento != NULL && otroElemento != NULL && pResultado != NULL )
    {
        if( *unElemento == *otroElemento)
        {
            retorno = 0;
        }
        else
        {
             retorno = 1;
            if(*unElemento > *otroElemento)
            {
                *pResultado = *unElemento;
            }
            else
            {
                *pResultado = *otroElemento;
            }
        }
    }

    return retorno;
}



int utn_retornarNumeroDeCuil(char* pResultadoCuilIngresado,
                                                int tamCuilIngresado,
                                                                char* mensaje,
                                                                        char* mensajeError,int reintentos)
{
    int retorno = 0;
	char auxCadena[4096];

    if(pResultadoCuilIngresado!= NULL
                && tamCuilIngresado > 0
                            && mensaje != NULL && mensajeError != NULL && reintentos > 0)
    {
        printf("%s",mensaje);

        do
        {
            if( utn_copiaElementoTipoCadenaEn_DeTam_(auxCadena, sizeof(auxCadena) )
                                            && utn_validarCuil(auxCadena, sizeof(auxCadena) ) )
            {




                if( strlen(auxCadena) == 10 )
                {
                    utn_pasarCadenaCon10Caracteres_ACuil(auxCadena,sizeof(auxCadena) );


                }
                else
                {
                        if( strlen(auxCadena) == 11 )
                        {

                            utn_pasarCadenaCon11Caracteres_ACuil(auxCadena,sizeof(auxCadena) );

                        }

                }

                 strncpy(pResultadoCuilIngresado,auxCadena,tamCuilIngresado);
                 retorno = 1;
                 break;



            }
             else
            {
                    utn_cantDeReintentos(&reintentos,mensajeError);
                    reintentos--;
            }


		}while(reintentos>=0);
    }

    return retorno;
}



int utn_validarCuil(char* cadena,int tamCadena)
{
    int retorno;
    retorno = 0;

    if(cadena != NULL )
    {
        if( utn_esElemento_Numerico(cadena,tamCadena)  )
        {
                retorno=1;
        }
        else
        {
            printf("usted ingreso caracteres que no son numericos \n");
        }

        if( strlen(cadena) <  10 ||  strlen(cadena) >  11 )
        {
            printf("error usted no ingreso la cantidad de numeros pedidos \n");
            retorno = 0;
        }

    }

    return retorno;
}


int utn_pasarCadenaCon10Caracteres_ACuil(char* cadena,int tamCadena)
{
    int retorno;
    retorno=0;
    char auxCadena[14];
    int largoCadena = strlen(cadena);
    int j;
    char aux;
    char auxTres;
    j=0;

    printf("el largo es %d",largoCadena);

    for(int i=0; i < largoCadena ; i++)
    {

        if(i == 9)
        {
            printf("el numero es %d", *(cadena + 9));

            aux = *(cadena + 9);
            *(auxCadena + j) = '-';
            j++;
            *(auxCadena + j)= aux;

            break;
        }


        if(i != 2)
        {
            auxCadena[j] = cadena[i];
            j++;
        }
        else
        {
           *(auxCadena + i) = '-';
            j++;
            aux = *(cadena + 2);

            *(auxCadena + 3) = aux;
            j++;
        }

       retorno=1;
    }

     strncpy(cadena,auxCadena,tamCadena);

    return retorno;

}



int utn_pasarCadenaCon11Caracteres_ACuil(char* cadena,int tamCadena)
{
    int retorno;
    retorno=0;
    char auxCadena[14];
    int largoCadena = strlen(cadena);
    int j;
    char aux;
    char auxDos;
    j=0;

    printf("el largo es%d",largoCadena);
    for(int i=0; i < largoCadena ; i++)
    {
        if(i == 10 )
        {

            aux = *(cadena + 10);
            *(auxCadena + j) = '-';
            j++;
            *(auxCadena + j)= aux;
            break;
        }

        if(i != 2)
        {
            auxCadena[j] = cadena[i];
            j++;
        }
        else
        {
           *(auxCadena + i) = '-';
            j++;
            aux = *(cadena + 2);

            *(auxCadena + 3) = aux;
            j++;
        }

       retorno=1;
    }

     strncpy(cadena,auxCadena,tamCadena);

    return retorno;

}




int utn_retornarTelefonoDeLinea(char* pResultadoTelefonoIngresado,
                                                int tamTelefonoIngresado,
                                                                char* mensaje,
                                                                        char* mensajeError,int reintentos)
{
    int retorno = 0;
	char auxTelParticular[4096];

    if(pResultadoTelefonoIngresado!= NULL
                && tamTelefonoIngresado > 0
                            && mensaje != NULL && mensajeError != NULL && reintentos > 0)
    {
        printf("%s",mensaje);

        do
        {
            if( utn_copiaElementoTipoCadenaEn_DeTam_(auxTelParticular, sizeof(auxTelParticular) )
                                && utn_validarTelefonoDeLinea(auxTelParticular, sizeof(auxTelParticular))
                                            && utn_formatearTelefono(auxTelParticular,sizeof(auxTelParticular),4 ) )
            {

                     strncpy(pResultadoTelefonoIngresado,auxTelParticular,tamTelefonoIngresado);
                    retorno = 1;
                    break;
            }
            else
            {
                utn_cantDeReintentos(&reintentos,mensajeError);
                reintentos--;
            }

		}while(reintentos>=0);
    }

    return retorno;
}


int utn_retornarTelefonoCelular(char* pResultadoTelefonoIngresado,
                                                int tamTelefonoIngresado,
                                                                char* mensaje,
                                                                        char* mensajeError,int reintentos)
{
    int retorno = 0;
	char auxTelCelular[4096];

    if(pResultadoTelefonoIngresado!= NULL
                && tamTelefonoIngresado > 0
                            && mensaje != NULL && mensajeError != NULL && reintentos > 0)
    {
        printf("%s",mensaje);

        do
        {
            if( utn_copiaElementoTipoCadenaEn_DeTam_(auxTelCelular, sizeof(auxTelCelular) )
                                            && utn_validarTelefonoCelular(auxTelCelular,sizeof(auxTelCelular))
                                                                && utn_formatearTelefono(auxTelCelular,sizeof(auxTelCelular),2 )  )
            {
                     strncpy(pResultadoTelefonoIngresado,auxTelCelular,tamTelefonoIngresado);
                     retorno = 1;
                     break;
            }
            else
            {
                utn_cantDeReintentos(&reintentos,mensajeError);
                reintentos--;
            }

		}while(reintentos>=0);
    }

    return retorno;
}



int utn_validarTelefonoDeLinea(char* cadena,int tamCadena)
{
    int retorno;
    retorno = 0;

    if(cadena != NULL )
    {
        if( utn_esElemento_Numerico(cadena,tamCadena)  )
        {
            if( *(cadena + 0) == '4' )
            {
                retorno=1;
            }
            else
            {
                if( *(cadena + 0) != '4')
                {
                    printf("error usted ingreso un numero que no es 4 como primero numero\n");
                    retorno = 0;
                }
            }

            if( strlen(cadena) >  8 ||  strlen(cadena) <  8 )
            {
                printf("error usted no ingreso la cantidad de numeros pedidos \n");
                retorno = 0;
            }

        }
    }

    return retorno;
}



int utn_validarTelefonoCelular(char* cadena,int tamCadena)
{
    int retorno;
    retorno = 0;

    if(cadena != NULL )
    {
        if( utn_esElemento_Numerico(cadena,tamCadena)  )
        {
            if( *(cadena + 0) == '1' && *(cadena + 1) == '1' || *(cadena + 0) == '1' && *(cadena + 1) == '5' )
            {
                retorno=1;
            }
            else
            {
                    printf("error usted ingreso los dos primeros numeros de forma equivocada \n");
                    retorno = 0;
            }

            if( strlen(cadena) >  10 ||  strlen(cadena) <  10 )
            {
                printf("error usted no ingreso la cantidad de numeros pedidos \n");
                retorno = 0;
            }

        }
    }

    return retorno;
}



int utn_formatearTelefono(char* cadena,int tamCadena,int posDondeVaElGuion)
{
    int retorno;
    retorno=0;
    char auxCadena[9];
    int largoCadena = strlen(cadena);
    int j;
    char aux;
    j=0;

    for(int i=0; i < largoCadena; i++)
    {
        if(i != posDondeVaElGuion)
        {
            auxCadena[j] = cadena[i];
            j++;
        }
        else
        {
           *(auxCadena + i) = '-';
            j++;
            aux = *(cadena + posDondeVaElGuion);

            *(auxCadena + (posDondeVaElGuion + 1) ) = aux;
            j++;
        }

        retorno=1;
    }

    strncpy(cadena,auxCadena,tamCadena);

    return retorno;
}



int utn_obtenerEmail(char* correo,int tamStringCorreo,char* mensaje, char* mensajeError, int reintentos)
{

	int retorno;
	retorno=0;
	char auxiliarMail[4026];

	if(mensaje != NULL && mensajeError != NULL && correo != NULL && tamStringCorreo > 0 && reintentos >= 0)
	{

	   do{
            printf("%s",mensaje);
            fflush(stdin);

            if(utn_copiaElementoTipoCadenaEn_DeTam_(auxiliarMail,sizeof(auxiliarMail))
                                          && utn_esMail(auxiliarMail,sizeof(auxiliarMail))
                                                    && strnlen(auxiliarMail,sizeof(auxiliarMail)) < tamStringCorreo)
            {
                strncpy(correo, auxiliarMail,tamStringCorreo);
                retorno=1;
                reintentos = -1;
            }
            else
            {
                utn_cantDeReintentos(&reintentos,mensajeError);
                reintentos--;
            }

		 }while(reintentos>=0);
	}

	return retorno;
}


int utn_esMail(char* auxMail, int tamCadena)
{
    int retorno;
	retorno=0;
    int contArrobas;
    int contPuntos;
	contPuntos=0;
	contArrobas=0;
	//int reintentosMail;

    for(int i = 0; i < 200; i++)
    {
				if(auxMail[i] == 64)
				{
					contArrobas++;

				}
				if(auxMail[i] == 46)
				{
					contPuntos++;

				}
    }

			if(contArrobas == 1 && contPuntos > 0)
			{
				retorno=1;

			}
			else
			{
				contArrobas=0;
				contPuntos=0;
				retorno=0;
			}

    return retorno;
}





// ORDENAMIENTOS - SWAPEOS


int utn_pSwapeoDeValoresEntre_Y_(int* unaVariable, int* otraVariable)
{
    int aux;
    int retorno;
    retorno=0;

    if(unaVariable != NULL && otraVariable != NULL)
    {
        aux = *unaVariable;
        *unaVariable = *otraVariable;
        *otraVariable = aux;
        printf("valor del auxiliar es: %d\n",aux);
        retorno = 1;
    }

    return(retorno);
}

//SERIA ASI LA INVOCACION 5 IGUAL a "TAM"
//utn_pOrdenarVector_TipoCaracterDeTam_(caracteres, 5, &criterio);
int utn_pOrdenarVector_TipoCaracterDeTam_(char* pListaDeCaracteres, int tamListaDeCaracteres, int* pCriterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;
    int aux;
    int auxCriterioCrecienteDecreciente;

    utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente,"ingrese criterio 1 para creciente / 0 para decreciente ", "error",0,1,3);

    if(pListaDeCaracteres != NULL && tamListaDeCaracteres > 0 && (auxCriterioCrecienteDecreciente >= 0 && auxCriterioCrecienteDecreciente <= 1) )
    {
        for(int i=0; i < tamListaDeCaracteres - 1; i++)
        {
            for(int j = i + 1; j < tamListaDeCaracteres; j++ )
            {
                    if(  *(pListaDeCaracteres + i) > *(pListaDeCaracteres + j) && auxCriterioCrecienteDecreciente  ||

                                                   *(pListaDeCaracteres + i) < *(pListaDeCaracteres + j) && !auxCriterioCrecienteDecreciente  )

                    {
                        aux= *(pListaDeCaracteres + i);
                        *(pListaDeCaracteres + i)= *(pListaDeCaracteres + j);
                        *(pListaDeCaracteres + j)=aux;
                    }

              }
         }
               retorno = 1;
               *pCriterioCrecienteDecreciente= auxCriterioCrecienteDecreciente;
      }

    return(retorno);
}


int utn_pMostrarVectorOrdenadoCrecienteODecreciente_TipoCaracterDeTam_(char* pListaDeCaracteres, int tamListaDeCaracteres,int criterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;

    if( pListaDeCaracteres != NULL && tamListaDeCaracteres > 0 && (criterioCrecienteDecreciente || !criterioCrecienteDecreciente ) )
    {
        for(int i = 0; i < tamListaDeCaracteres ; i++)
        {
            utn_pMostrarUnCaracter_(pListaDeCaracteres + i);
            retorno=1;
        }
    }

    return(retorno);
}


int utn_pOrdenarElVector_DeElementoTipoEnteroDeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int* pCriterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;
    int aux;
    int auxCriterioCrecienteDecreciente;

    utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente,"ingrese criterio 1 para creciente / 0 para decreciente ", "error",0,1,3);

    if( pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0
                                            && auxCriterioCrecienteDecreciente >= 0 && auxCriterioCrecienteDecreciente <= 1 )
    {
        for(int i=0; i < tamListaElementosTipoEntero - 1; i++)
        {
            for(int j = i + 1; j < tamListaElementosTipoEntero; j++ )
            {

                if( *(pListaElementosTipoEntero + i) > *(pListaElementosTipoEntero + j) && auxCriterioCrecienteDecreciente

                             || *(pListaElementosTipoEntero + i) < *(pListaElementosTipoEntero + j) && !auxCriterioCrecienteDecreciente)

                {
                        aux= *(pListaElementosTipoEntero + i);
                        *(pListaElementosTipoEntero + i)= *(pListaElementosTipoEntero + j);
                        *(pListaElementosTipoEntero + j)=aux;
                }
            }
        }

             retorno = 1;
            *pCriterioCrecienteDecreciente= auxCriterioCrecienteDecreciente;
    }

    return(retorno);
}


int utn_pMostrarVectorOrdenadoCrecienteODecreciente_DeTipoElementoEntero_DeTam_(int* pListaElementosTipoEntero,int tamListaElementosTipoEntero,int criterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;

    if(pListaElementosTipoEntero != NULL && tamListaElementosTipoEntero > 0 && ( criterioCrecienteDecreciente == 0 || criterioCrecienteDecreciente == 1 )  )
    {
        for(int i = 0; i < tamListaElementosTipoEntero ; i++)
        {
            utn_pMuestraUnElemento_TipoEnteroConTam_(pListaElementosTipoEntero + i);
            retorno=1;
        }
    }

    return(retorno);
}


//VECTORES PARALELOS


//NO HACE FALTA COLOCAR EL ITEM FILAS CON EL ITEM COLUMNA YA ESTA BIEN.

int utn_utnMostrarVectorParalelo_ElementoTipoCadena_(char pListaDeElementosCadena[][COLUMNAS], int tamListaDeElementosCadena)
{
    int retorno;
    retorno=0;

    for(int i=0; i < tamListaDeElementosCadena; i++)
    {
        for(int j=0; j < COLUMNAS ; j++)
        {
           utn_utnMostrarUnElementoVectorParalelo_TipoCadena_( (&pListaDeElementosCadena[i][j]) );

        }
        printf("\n");
    }
    printf("\n");

    return retorno;
}


int utn_utnMostrarUnElementoVectorParalelo_TipoCadena_(char* pListaDeElementosCadena[])
{
    int retorno;
    retorno=0;

            printf("%c ", *(pListaDeElementosCadena) );

    return retorno;
}


//DEBERIA DE FUNCIONAR IGUAL QUE LA FUNCION DE ARRIBA PERO NO FUNCIONA
int utn_pMuestraUnElementoTipoCadenaEnVectorParalelo_(char* unElementoTipoCadena[][COLUMNAS] )
{
    int retorno;
    retorno=0;

    if( unElementoTipoCadena != NULL )
    {
            printf("%s\n", *unElementoTipoCadena );
            retorno=1;
    }

    return retorno;
}






int utn_ingresoVectorParalelo_ElementosTipoCadenaDeTam_(char pListaDeElementos[][COLUMNAS],int tam)
{
    int retorno;
    retorno=0;

    char auxCad[100];


    for(int i=0; i < tam; i++)
    {

      utn_pIngresoDeLaCadena_DeTam_( pListaDeElementos + i, COLUMNAS, "ingrese un nombre", "error", 2);

         retorno=1;
        /*
        printf("ingrese un nombre \n");
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad) >= COLUMNAS )
        {
            printf("nombre demasiado largo, reingrese\n");
            fflush(stdin);
            gets(auxCad);
        }

        strcpy( *(pListaDeElementos + i) ,auxCad );
        */
    }

    return retorno;
}


int pMuestraVectorParalelo_ElementosTipoEnteroDeTam_(int* pListaDeElementos[][COLUMNAS],int filas)
{
    int retorno;
    retorno=0;

    for(int i=0; i < filas; i++)
    {
        for(int j=0; j < COLUMNAS ;j++)
        {

             printf("%d ", *(&pListaDeElementos [i][j]));// mat[i][j]
             retorno = 1;
        }
        printf("\n");
    }

    return retorno;
}


int utn_pMenuOrdenarVectorParalelo_PorCriterioCrecienteODecreciente_(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam)
{
    int retorno;
    retorno=0;
    char confirma;
    char seguir;
    seguir = 's';
    int numDeItemPorElCualOrdenar;
    int criterioDeOrdenamiento;
    int criterio;

    //ordenar por criterio legajo nombre sexo
    // asc ascendente 1 descendente 0


    if( notas1 != NULL && notas2 != NULL && legajos != NULL && sexo != NULL &&  tam > 0 )
    {


        do
        {
            //system("cls");

            printf("***BIENVENIDO AL MENU DE OPCIONES DEL CRITERIO DE ORDENAMIENTO\n");
            printf("ingrese 1 para ordenar por legajo\n");
            printf("ingrese 2 para ordenar por nombre\n");
            printf("ingrese 3 para ordenar por promedio\n");
            printf("ingrese 4 para salir\n");
            fflush(stdin);
            scanf("%d",&criterioDeOrdenamiento);
            //fgets(criterioDeOrdenamiento,sizeof(criterioDeOrdenamiento),stdin);
            //gets(criterioDeOrdenamiento);

            switch(criterioDeOrdenamiento)
            {
                case 1:

                        utn_ordenarVector_PorLegajo(nombres,notas1,notas2,legajos,sexo,promedios,tam,&criterio);

                        retorno=1;
                break;

                case 2:

                        utn_ordenarVector_PorNombre(nombres ,notas1 , notas2, legajos, sexo ,promedios ,tam,&criterio);

                        retorno=1;

                break;

                case 3:
                        utn_ordenarVector_PorPromedio(nombres,notas1,notas2,legajos,sexo,promedios,tam, &criterio);

                        retorno=1;
                break;

                case 4:

                        printf("desea salir?\n");
                        fflush(stdin);
                        confirma=getchar();
                        if(confirma == 's')
                        {
                            seguir= 'n';
                        }
                        retorno=1;
                break;

            }

        }while(seguir=='s');

    }

    return retorno;
}


int utn_ordenarVector_PorPromedio(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam,int* pCriterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;
    float auxPromedio;
    int aux1;
    char auxSexo;
    char auxCad[COLUMNAS];
    int auxCriterioCrecienteDecreciente;

    utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente,"ingrese criterio 1 para promedios crecientes / 0 para decrecientes ", "error",0,1,3);

    if( notas1 != NULL && notas2 != NULL && legajos != NULL && sexo != NULL &&  tam > 0 && auxCriterioCrecienteDecreciente >= 0 && auxCriterioCrecienteDecreciente <= 1 )
    {

        for(int i=0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++ )
            {

                    if( promedios[i] > promedios[j] && auxCriterioCrecienteDecreciente || promedios[i] < promedios[j] && !auxCriterioCrecienteDecreciente  )
                    {

                     auxPromedio= *(promedios + i);
                    *(promedios + i) = *(promedios + j);
                    *(promedios + j) = auxPromedio;

                    aux1 =  *(notas1 + i);
                    *(notas1 + i) = *(notas1 + j);
                    *(notas1 + j)=aux1;


                    //EL AUX SE RENUEVA SE PUEDE USAR NUEVAMENTE

                    aux1 =  *(notas2 + i);
                    *(notas2 + i) = *(notas2 + j);
                    *(notas2 + j)=aux1;

                     aux1 =  *(legajos + i);
                    *(legajos + i) = *(legajos + j);
                    *(legajos + j)=aux1;


                    auxSexo =  *(sexo + i) ;
                    *(sexo + i) = *(sexo + j) ;
                    *(sexo + j) = auxSexo;

                    strcpy( auxCad, *(nombres + i) );
                    strcpy( *(nombres + i), *(nombres + j) );
                    strcpy( *(nombres + j), auxCad);
                    retorno = 1;
                    *pCriterioCrecienteDecreciente= auxCriterioCrecienteDecreciente;

                }
            }
        }
    }


    return retorno;
}



int utn_ordenarVector_PorLegajo(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam,int* pCriterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;
    float auxPromedio;
    int aux1;
    char auxSexo;
    char auxCad[COLUMNAS];

     int auxCriterioCrecienteDecreciente;

     utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente,"ingrese criterio 1 para legajo crecientes / 0 para decrecientes ", "error",0,1,3);

    if( notas1 != NULL && notas2 != NULL && legajos != NULL && sexo != NULL &&  tam > 0 && auxCriterioCrecienteDecreciente >= 0 && auxCriterioCrecienteDecreciente <= 1)
    {

        for(int i=0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++ )
            {

                //if( *(promedio + i) < *(promedio + j) ) //&& CRECIENTE || *(numeros + i) < *(numeros + j) && !CRECIENTE)
                //{
                    if( *(legajos + i) > *(legajos + j) && auxCriterioCrecienteDecreciente
                                                            || *(legajos + i) < *(legajos + j) && !auxCriterioCrecienteDecreciente)
                    {

                     auxPromedio= *(promedios + i);
                    *(promedios + i) = *(promedios + j);
                    *(promedios + j) = auxPromedio;

                    aux1 =  *(notas1 + i);
                    *(notas1 + i) = *(notas1 + j);
                    *(notas1 + j)=aux1;


                    //EL AUX SE RENUEVA SE PUEDE USAR NUEVAMENTE

                    aux1 =  *(notas2 + i);
                    *(notas2 + i) = *(notas2 + j);
                    *(notas2 + j)=aux1;

                     aux1 =  *(legajos + i);
                    *(legajos + i) = *(legajos + j);
                    *(legajos + j)=aux1;


                    auxSexo =  *(sexo + i) ;
                    *(sexo + i) = *(sexo + j) ;
                    *(sexo + j) = auxSexo;

                    strcpy( auxCad, *(nombres + i) );
                    strcpy( *(nombres + i), *(nombres + j) );
                    strcpy( *(nombres + j), auxCad);
                    retorno = 1;

                    *pCriterioCrecienteDecreciente= auxCriterioCrecienteDecreciente;

                }
            }
        }
    }


    return retorno;
}




int utn_ordenarVector_PorNombre(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam,int* pCriterioCrecienteDecreciente)
{
    int retorno;
    retorno=0;
    float auxPromedio;
    int aux1;
    char auxSexo;
    char auxCad[COLUMNAS];

    int auxCriterioCrecienteDecreciente;

    utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente,"ingrese criterio 1 para nombres crecientes / 0 para decrecientes ", "error",0,1,3);


    if( notas1 != NULL && notas2 != NULL && legajos != NULL && sexo != NULL &&  tam > 0 && auxCriterioCrecienteDecreciente >= 0 && auxCriterioCrecienteDecreciente <= 1 )
    {

        for(int i=0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam ; j++ )
            {
                    if( strcmp(nombres[i], nombres[j]) > 0 && auxCriterioCrecienteDecreciente || strcmp(nombres[i], nombres[j]) < 0 && !auxCriterioCrecienteDecreciente)
                    {

                     auxPromedio= *(promedios + i);
                    *(promedios + i) = *(promedios + j);
                    *(promedios + j) = auxPromedio;

                    aux1 =  *(notas1 + i);
                    *(notas1 + i) = *(notas1 + j);
                    *(notas1 + j)=aux1;

                    //EL AUX SE RENUEVA SE PUEDE USAR NUEVAMENTE

                    aux1 =  *(notas2 + i);
                    *(notas2 + i) = *(notas2 + j);
                    *(notas2 + j)=aux1;

                     aux1 =  *(legajos + i);
                    *(legajos + i) = *(legajos + j);
                    *(legajos + j)=aux1;


                    auxSexo =  *(sexo + i) ;
                    *(sexo + i) = *(sexo + j) ;
                    *(sexo + j) = auxSexo;

                    strcpy( auxCad, *(nombres + i) );
                    strcpy( *(nombres + i), *(nombres + j) );
                    strcpy( *(nombres + j), auxCad);
                    retorno = 1;
                    *pCriterioCrecienteDecreciente= auxCriterioCrecienteDecreciente;
                }
            }
        }
    }


    return retorno;
}


int utn_calcularPromedioDeNotas_Y_(int* notas1, int* notas2,float* pPromedio)
{
    int retorno;
    retorno=0;

    if( notas1 != NULL &&  notas2 != NULL && *notas1 >= 0  &&  *notas2 >= 0  )
    {
        *pPromedio = ( (  (float) *notas1 + *notas2)  / 2 );

        retorno=1;
    }


   return retorno;
}

int utn_pAcumuladorVectorParalelo_ElementosTipoEnteroDeTam_(int pListaDeElementos[][COLUMNAS],int filas)
{
    int retorno;
    retorno=0;

    for(int i=0; i < filas -1 ;i++)
    {
        for(int j=0; j < COLUMNAS - 1 ;j++)
        {
           pListaDeElementos[i][COLUMNAS-1] += pListaDeElementos[i][j];
        }
    }

        for(int j=0; j < COLUMNAS ;j++)
        {
            for(int i=0; i < filas - 1 ; i++)
            {
                pListaDeElementos[filas - 1][j] += pListaDeElementos[i][j];
            }

            retorno = 1;
        }

    return retorno;
}



int utn_ordenamientoDobleCriterio(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam)
{
    int retorno;
    retorno=0;
    float auxPromedio;
    int aux1;
    char auxSexo;
    char auxCad[COLUMNAS];
    int auxCriterioCrecienteDecreciente;

    utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente,"ingrese criterio 1 para creciente / 0 para decreciente ", "error",0,1,3);

    for(int i=0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++ )
        {

            if( (*(sexo + i) < *(sexo + j) || ( *(sexo + i) == *(sexo + j) && strcmp(*(nombres + i), *(nombres + j) ) < 0 && auxCriterioCrecienteDecreciente == 1)

                || *(sexo + i) < *(sexo + j) || ( *(sexo + i) == *(sexo + j) && strcmp(*(nombres + i), *(nombres + j) ) > 0 && auxCriterioCrecienteDecreciente == 0) ))

                {

                     auxPromedio = *(promedios + i);
                    *(promedios + i) = *(promedios + j);
                    *(promedios + j) = auxPromedio;

                      aux1 =  *(notas1 + i);
                    *(notas1 + i) = *(notas1 + j);
                    *(notas1 + j)=aux1;

                    //EL AUX SE RENUEVA SE PUEDE USAR NUEVAMENTE

                    aux1 =  *(notas2 + i);
                    *(notas2 + i) = *(notas2 + j);
                    *(notas2 + j)=aux1;

                     aux1 =  *(legajos + i);
                    *(legajos + i) = *(legajos + j);
                    *(legajos + j)=aux1;


                    auxSexo =  *(sexo + i) ;
                    *(sexo + i) = *(sexo + j) ;
                    *(sexo + j) = auxSexo;

                    strcpy( auxCad, *(nombres + i) );
                    strcpy( *(nombres + i), *(nombres + j) );
                    strcpy( *(nombres + j), auxCad);
                    retorno = 1;

            }
                //else if (sexo[i] == sexo[j] && strcmp(nombres[i], nombres[j]) > 0)
                //y de nuevo todo lo de arriba

                //pero al ponerle un || lo que hacemos es elimina esto y hacer todo junto
                //arriba
        }
    }

    return retorno;
}


int  utn_mostrarVectoresParalelos_Y_(char nombres[][COLUMNAS],int* notas1,int* notas2,int* legajos,char* sexo,float* promedios, int tam)
{
    int retorno;
    retorno=0;

    //system("cls");
    printf("\n        ***listado de promedio de alumnos*** \n");
    printf("     \n  nombre          nota 1Parcial        nota 2Parcial       legajo        sexo          Promedio \n");
   for(int i = 0; i < tam ; i++  )
    {

        if( *(promedios + i) != -1  )                                                    //*(nombre + i) ,*(notas1 + i),*(notas2 + i), *(legajo + i), *(sexo + i) ,*(promedio + i)
        {
            printf("   %2s                  %2d                  %2d               %2d           %2c           %5.2f \n", nombres[i],*(notas1 + i),*(notas2 + i),*(legajos + i),*(sexo + i), *(promedios + i) );

            //printf("nota 1 del alumno: %d, nota 2 del alumno: %d promedio del alumno: %.2f \n", notas1 [i], notas2[i], promedio [i] );
        }
        else
        {
            printf("el promedio del alumno no se pudo mostrar, datos erroneos \n " );
        }
        retorno=1;
    }

    return retorno;

}
