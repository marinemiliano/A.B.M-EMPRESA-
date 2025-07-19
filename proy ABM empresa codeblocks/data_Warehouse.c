
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>


#include "data_Warehouse.h"
#include "eEmpleado.h"
#include "almuerzo.h"
#include "fecha.h"
#define   NO_FULL 0
#define   FULL 1
#define  EMPTY 0
#define  NO_EMPTY 0

#define  NUNCA_LA_POSICION_FUE_CARGADA 0

//NOS AVISA QUE LA POSICION ALGUNA VEZ SE CARGO
//ES UNA BANDERA QUE ES IMPORTANTE PARA DAR DE ALTA
//EMPLEADOS DADOS DE BAJA Y QUE SE RESPETEN SUS POSICIONES
//DENTRO DE LA LISTA
#define  SI_LA_POSICION_ESTUVO_CARGADA 1

#define TAM_NOMBRE 20
#define TAM_SEXO 3
#define NOMBRE_SECTOR 20

#define TAM_LISTA_EMPLEADOS 20
#define TAM_LISTA_SECTORES 10
#define TAM_LISTA_COMIDAS 10
#define TAM_LISTA_ALMUERZOS 50


eFecha fechaDeAlmuerzo[13]={
							{8,2,1999},
							{17,1,2005},
							{20,7,1994},
							{2,18,2014},
							{4,4,2018},
							{5,10,2019},
							{8,12,1985},
							{7,2,1989},
							{16,4,2008},
							{1,6,1991},
							{28,4,2011},
							{12,5,2022},
							{12,5,2017}
	                   };


char nombres[10][TAM_NOMBRE]=
{
	"Donato",
	"German",
	"Gunda",
	"Carmen",
	"Daniela",
	"Maria",
	"Alex",
	"Damian",
	"Gaston",
	"Santiago"
};

char apellidos[10][TAM_NOMBRE]=
{
	"marin",
	"gonzales",
	"martinez",
	"spagnolo",
	"palumbo",
	"correa",
	"mastantuono",
	"perez",
	"Gutierrez",
	"oribe"
};

char sexos[10][TAM_SEXO]={"m","nb","f","f","f","nb","m","m","m","nb"};
int edades[10]={56,50,42,72,26,18,35,47,25,45};
float sueldos[10]={5000.25,1000,2000,2000,3000,3000,5000,5000,5000,5000};

eFecha fechasDeNacimiento[10]={
                                {9,9,1985},
                                {15,11,1992},
                                {20,7,1990},
                                {2,11,1992},
                                {16,4,1981},
                                {5,9,2000},
                                {2,4,1980},
                                {17,14,1981},
                                {11,3,1997},
                                {1,6,1970} };


eFecha fechasDeIngreso[10]={
                            {9,10,2001},
                            {15,11,2000},
                            {20,7,2013},
                            {2,11,2015},
                            {16,4,2014},
                            {5,9,2018},
                            {25,3,2012},
                            {17,6,2020},
                            {11,5,2023},
                            {1,1,2012} };


int idSectores[10]={504, 504, 500, 500, 504, 502, 503, 503, 502, 504};

int idComida[13]={1000,1002,1001,1003,1000,1004,1001,1002,1001,1001,1001,1002,1004};

	char nombreComida[13][20]=
	{
			"milanesa",
			"fideos",
			"churrasco",
			"ensalada",
			"pescado",
			"fideos",
			"fideos",
			"churrasco",
			"ensalada",
			"churrasco",
			"fideos",
			"churrasco",
			"pescado",
	};


int legEmpleado[13]={2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010,2011,2012};


int ALMUERZOS_HarcodearAlmuerzos(eAlmuerzo* listaDeAlmuerzos,int tamListaDeAlmuerzos,int cantElementosACargar ,int* pIdAlmuerzo)
{
	int retorno;
	retorno=1;

	if(listaDeAlmuerzos != NULL && tamListaDeAlmuerzos > 0 &&  cantElementosACargar >= 0
                                    && cantElementosACargar <= tamListaDeAlmuerzos &&  pIdAlmuerzo != NULL)
	{

		for(int i = 0; i < cantElementosACargar ; i++)
		{
                    (*(listaDeAlmuerzos + i)).id_Almuerzo = *(pIdAlmuerzo);

                    (*pIdAlmuerzo)++;

                    (*(listaDeAlmuerzos + i)).leg_Empleado = *(legEmpleado + i);

                    strcpy( (*(listaDeAlmuerzos + i)).apellido_Empleado ,(*(apellidos + i)) );

                    strcpy( (*(listaDeAlmuerzos + i)).nombre_Empleado ,(*(nombres + i)) );

                     (*(listaDeAlmuerzos + i)).id_Comida = (*(idComida + i));

                    (*(listaDeAlmuerzos + i)).fecha_De_Almuerzo = (*(fechaDeAlmuerzo + i));


                    /*
                        (listaDeAlmuerzos + i)->fechaDeAlmuerzo.dia  = (*(fechaAlmuerzos + i)).dia &&
                        (listaDeAlmuerzos + i)->fechaDeAlmuerzo.mes  = (*(fechaAlmuerzos + i)).mes &&
                        (listaDeAlmuerzos + i)->fechaDeAlmuerzo.anio = (*(fechaAlmuerzos + i)).anio )
                    */

                        // O se puede escribir de esta manera

                            (*(listaDeAlmuerzos + i)).is_Almuerzo_Full = FULL;
                            retorno=1;
		}
	}
    else
    {
        printf("\n OCURRIO UN ERROR AL CARGAR LAS COMIDAS \n");

    }

	return retorno;
}


int ALMUERZO_pCargaAlmuerzosPorDefecto_DeTam_OPCION_UNO(eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                                                        ,eSector* listaSectores,int tamListaSectores
                                                        ,eEmpleado* listaEmpleados,int tamListaEmpleados
                                                        ,eComida* listaComidas, int tamListaComidas)
{
    int retorno;
    retorno=0;

    //NEXO_pMuestraEstructuras_DeTam_DOS(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores);
    //SECTOR_pMuestraListaSectores_DeTam_UNO(listaSectores,tamListaSectores);
    //COMIDA_pMuestraListaDeComidas_DeTam_(listaComidas,TAM_COMIDAS);

    if(listaAlmuerzos != NULL && tamListaAlmuerzos > 0)
    {

        eAlmuerzo auxAlmuerzos[3]={ {1,1,"emiliano","marin",1003,{9,9,1991},FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                   ,{2,1,"emiliano","marin",1003,{9,4,1990},FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                   ,{3,2,"maria","gutierrez",1001,{9,5,1995},FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }};
	    for(int i=0;i<3;i++)
		{
			*(listaAlmuerzos + i)= *(auxAlmuerzos + i);
            retorno = 1;
		}
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL CARGAR LAS COMIDAS \n");
    }

    return retorno;
}


//CARGA TODA LA ESCTRUCTURA HARCODEADA EN LA LISTA PASADA POR PARAMETRO
int EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_UNO(eEmpleado* listaEmpleados,int tamListaEmpleados)
{
    int retorno;
    retorno=0;

    if(listaEmpleados != NULL && tamListaEmpleados > 0)
    {
                //PUEDE SER TAMBIEN TAM_LISTA_EMPLEADOS EN VEZ DE 11 PERO ITERA EL TAM EN ESTE
                //CASO SERIA 100 VECES
            eEmpleado  auxEmpleado[11]={{ 1,"emiliano","marin",{9,9,1985},39,"M",570,{9,9,1985},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , { 2,"maria","gutierrez" ,{1,11,1970},54,"F",570,{15,11,2000},501,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , { 3,"gustavo","arbeloa" ,{18,2,1996},28,"NB",500,{20,7,1998},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 4,"zonzalo","spirito", {20,2,1930},94,"NB",256,{2,11,1458},502,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 5,"angela", "ochoa" ,{3,4,2003},21,"F",50,{16,4,2014},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 6,"emiliano","marin",{9,9,1985},39,"M",570,{9,9,1985},501,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 7,"maria","gutierrez" ,{1,11,1970},54,"F",570,{15,11,2000},503,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 8,"gustavo","arbeloa" ,{18,5,1996},28,"NB",500,{20,7,1998},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 9,"zonzalo","spirito", {20,2,1930},94,"NB",256,{2,11,1458},502,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 10,"angela", "ochoa" ,{3,4,2003},21,"F",50,{16,4,2014},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 11,"FEDE", "palermo" ,{3,4,2003},21,"F",50,{16,4,2014},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }};

	    for(int i=0 ; i<11 ; i++)
		{
			*(listaEmpleados + i)= *(auxEmpleado+i);
            retorno = 1;
		}
    }

    return retorno;
}


int EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_DOS(eEmpleado* listaEmpleados,int tamlistaEmpleados
                                                    ,int cantElementosACargarEnVector,int* pLegajo)

{
	int retorno;
	int anioActual;
	anioActual=2024;
	retorno = 0;

	if(listaEmpleados != NULL && tamlistaEmpleados > 0 && cantElementosACargarEnVector >= 0
                                            && cantElementosACargarEnVector <= tamlistaEmpleados &&  pLegajo != NULL)
	{
                   //PUEDE SER TAMBIEN TAM_LISTA_EMPLEADOS EN VEZ DE 10
	     eEmpleado  auxEmpleado[10]={ {1,"emiliano","marin",{9,9,1985},39,"M",570,{9,9,1985},501,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , {  2,"maria","gutierrez" ,{1,11,1970},54,"F",570,{15,11,2000},503,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , { 3,"gustavo","arbeloa" ,{18,25,1996},28,"NB",500,{20,7,1998},504,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA }
                                      , {4,"zonzalo","spirito", {20,2,1930},94,"NB",256,{2,11,1458},502,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , { 5,"angela", "ochoa" ,{3,4,2003},21,"F",50,{16,4,2014},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , {6,"emiliano","marin",{9,9,1985},39,"M",570,{9,9,1985},501,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , { 7,"maria","gutierrez" ,{1,11,1970},54,"F",570,{15,11,2000},503,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , { 8,"gustavo","arbeloa" ,{18,25,1996},28,"NB",500,{20,7,1998},504,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , {9,"zonzalo","spirito", {20,2,1930},94,"NB",256,{2,11,1458},502,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}
                                      , { 10,"angela", "ochoa" ,{3,4,2003},21,"F",50,{16,4,2014},500,FULL,NO_EMPTY,SI_LA_POSICION_ESTUVO_CARGADA}};


		for(int i = 0; i < cantElementosACargarEnVector ; i++)
		{
		    // aqui podriamos validar todo con un if como sucede en la
		    //funcion utn_DescripcionDeLaEstructuraConElId_enLista_DeTam_
		    // si esta todo ok devuelve 1 sino devuelve 0

			(*(listaEmpleados + i)).legajo= *pLegajo;
			(*pLegajo)++;

		    strcpy( (*(listaEmpleados + i)).nombre, (*(auxEmpleado+i)).nombre );
			strcpy( (*(listaEmpleados + i)).apellido, auxEmpleado[i].apellido) ;

			 (listaEmpleados + i)->fecha_Nacimiento_Empleado = auxEmpleado[i].fecha_Nacimiento_Empleado;

			listaEmpleados->edad = (*(auxEmpleado + i)).edad;

			 strcpy( (*(listaEmpleados + i)).sexo,(*(auxEmpleado + i)).sexo) ;

			(*(listaEmpleados + i)).sueldo = auxEmpleado[i].sueldo;


			(*(listaEmpleados + i)).ID_Sector = (*(auxEmpleado + i)).ID_Sector;

			(*(listaEmpleados + i)).is_Empleado_Full = (*(auxEmpleado + i)).is_Empleado_Full;

			(*(listaEmpleados + i)).fecha_Ingreso_Empleado  = (*(auxEmpleado + i)).fecha_Ingreso_Empleado;

        /*
            (*(listaEmpleados + i).fecha_Ingreso_Empleado.dia  = fechasDeIngreso + i.dia;
			(*(listaEmpleados + i).fecha_Ingreso_Empleado.mes  = fechasDeIngreso + i.mes;
			(*(listaEmpleados + i)).fecha_Ingreso_Empleado.anio = fechasDeIngreso + i.anio
            */
		}

	}
	else
    {
            printf("ERROR, NO SE PUDO DAR DE ALTA A LOS EMPLEADOS \n");
    }

	return retorno;
}


//PARA ESTA OPCION NECESITAMOS MATRICES COMO LAS QUE SE ENCUENTRAN EN ESTA BIBLIOTECA
//EJ EDADES, SEXOS ETC
int EMPLEADO_pCargaEmpleadosPorDefecto_DeTam_OPCION_TRES(eEmpleado* listaEmpleados,int tamlistaEmpleados
                                                        ,int cantElementosACargarEnVector,int* pLegajo)

{
	int retorno;
	int anioActual;
	anioActual=2024;
	retorno = 0;

	if(listaEmpleados != NULL && tamlistaEmpleados > 0 && cantElementosACargarEnVector >= 0
                                            && cantElementosACargarEnVector <= tamlistaEmpleados &&  pLegajo != NULL)
	{


		for(int i = 0; i < cantElementosACargarEnVector ; i++)
		{
		    // aqui podriamos validar todo con un if como sucede en la funcion utn_DescripcionDeLaEstructuraConElId_enLista_DeTam_
		    // si esta todo ok devuelve 1 sino devuelve 0

            (*(listaEmpleados + i)).legajo= *pLegajo;
			(*pLegajo)++;

            strcpy( (*(listaEmpleados + i)).nombre,(*(nombres + i)) );
			strcpy( (*(listaEmpleados + i)).apellido,(*(apellidos + i)) );

			(*(listaEmpleados + i)).fecha_Nacimiento_Empleado = (*(fechasDeNacimiento + i)) ;
             strcpy( (*(listaEmpleados + i)).sexo,(*(sexos + i)) );
			(*(listaEmpleados + i)).sueldo = (*(sueldos + i));
			(listaEmpleados+i)->edad = (*(edades + i));
            (*(listaEmpleados + i)).ID_Sector = (*(idSectores + i));

			(*(listaEmpleados + i)).is_Empleado_Full = FULL;

            //(listaEmpleados+i)->fecha_Ingreso_Empleado = (*(fechasDeIngreso + i));

            retorno=1;


            (listaEmpleados + i)->fecha_Ingreso_Empleado.dia  = (*(fechasDeIngreso + i)).dia;
			(listaEmpleados + i)->fecha_Ingreso_Empleado.mes  = (*(fechasDeIngreso + i)).mes;
			(listaEmpleados + i)->fecha_Ingreso_Empleado.anio = (*(fechasDeIngreso + i)).anio;
		}
	}
	else
    {
        printf("ERROR, NO SE PUDO DAR DE ALTA A LOS EMPLEADOS \n");
    }

	return retorno;
}

//CARGA TODA LA ESCTRUCTURA HARCODEADA EN LA LISTA PASADA POR PARAMETRO
int COMIDA_pCargaComidasPorDefecto_DeTam_OPCION_UNO(eComida* listaComidas,int tamListaComidas)
{
    int retorno;
    retorno=0;

    if(listaComidas != NULL && tamListaComidas > 0)
    {
        eComida auxComidas[5]={{1000, "MILANESA",200,FULL},
                                {1001,"FIDEOS",150,FULL},
                                {1002,"CHURRASCO",100,FULL},
                                {1003,"ENSALADA",50,FULL},
                                {1004,"PESCADO",10,FULL} };

	    for(int i=0;i<5;i++)
		{
			*(listaComidas + i)= *(auxComidas+i);
            retorno = 1;
		}
    }
    else
    {
        printf("\n OCURRIO UN ERROR AL CARGAR LAS COMIDAS \n");

    }

    return retorno;
}
