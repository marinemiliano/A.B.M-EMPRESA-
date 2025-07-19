

/*
int utn_pCargaListaDeEstructuras_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras, int anioActual)
{
    int retorno;
    retorno= 0;

    for(int i = 0; i < tamListaDeEstructuras ; i++)
    {

        utn_pCargaUnaEstructura_( listaDeEstructuras + i, anioActual );
        retorno = 1;
    }



    return retorno;

}
*/


//la diferencia con la funcion  utn_pCargaUnaEstructura_ es que esta retorna la estructura por retorno
//y no por referencia solo recibe el id por referencia

/*
eEmpleado EMP_pedirDatosEmpleados(int* idAsignado)	//modificar parametros y recibir //la lista de sectores
{
	eEmpleado auxEmpleado;
	auxEmpleado.legajo= *idAsignado;

	if(utn_pIngresoDeLaCadena_DeTam_(&auxEmpleado->nombre, sizeof(auxEmpleado->nombre) , " ingrese un nombre: ", "error", 2) &&
       utn_pIngresoDeLaCadena_DeTam_(&auxEmpleado->Apellido, sizeof(auxEmpleado->apellido) , " ingrese un Apellido: ", "error", 2)
        utn_pIngresoDeElementoTipoFlotante_(&(*unaEstructura).sueldo, " ingrese sueldo: ", "error", 0 , 500000, 2) )
    {
        aux.isEmpty=CARGADO;
    }

	//aca deberia de mostrar la lista de sectores

	aux.sector=ing_pedirEnteroRango("seleccione el id del sector: ", -1000, 10000);


	return aux;
}
*/


/*
int utn_pCargaUnaEstructura_(eEmpleado* unaEstructura, int anioActual,eSector* unaListaDeEstructuras,int tamUnaListaDeEstructuras)
{
    int retorno;
    retorno= 0;
    int edadLimite;
    edadLimite = 120;

	//utn_pIngresoDeElementoTipoEntero_(&unaEstructura->legajo, "ingrese legajo", "error", 0 , 100, 2);

	if(utn_pIngresoDeLaCadena_DeTam_(&unaEstructura->nombre, sizeof(unaEstructura->nombre) , "\n NOMBRE DEL EMPLEADO A INGRESAR: ", "error", 2) &&

        utn_pIngresoDeLaCadena_DeTam_(&unaEstructura->apellido, sizeof(unaEstructura->apellido) , "\n APELLIDO DEL EMPLEADO A INGRESAR: ", "error", 2) &&

        utn_pIngresoDeElementoTipoEntero_( &unaEstructura->fecha_Nacimiento_Empleado.dia, "\n DIA DE NACIMIENTO: ", "\n ERROR", 0, 31, 2) &&

	    utn_pIngresoDeElementoTipoEntero_( &(unaEstructura)->fecha_Nacimiento_Empleado.mes, "\n MES DE NACIMIENTO: ", "\n ERROR",0 , 12, 2) &&

	    utn_pIngresoDeAnioTipoEntero_(&(unaEstructura)->fecha_Nacimiento_Empleado.anio ," DE NACIMIENTO " ,"\n ERROR" ,1900 ,2024 , 2) &&

	    utn_calcularEdad(anioActual, (*(unaEstructura)).fecha_Nacimiento_Empleado.anio, &unaEstructura->edad,18 ,120 ) &&

        utn_pIngresoDeSexoF_M_oNoBinario_DeTam_(unaEstructura->sexo, sizeof(unaEstructura->sexo) , "\n SEXO DEL EMPLEADO A INGRESAR: MASCULINO (M), FEMENINO (F), NO BINARIO (NB): ", "error", 2) &&

        utn_pIngresoDeElementoTipoFlotante_(&(unaEstructura)->sueldo, "\n SUELDO DEL EMPLEADO A INGRESAR: ", "\n ERROR", 0 , 500000, 2) &&

	    utn_pIngresoDeElementoTipoEntero_( &unaEstructura->fecha_Ingreso_Empleado.dia, "\n DIA DE INGRESO DEL EMPLEADO A LA EMPRESA: ", "\n ERROR", 0, 31, 2) &&

	    utn_pIngresoDeElementoTipoEntero_( &(unaEstructura)->fecha_Ingreso_Empleado.mes, " MES DE INGRESO DEL EMPLEADO A LA EMPRESA: ", "\n ERROR",0 , 12, 2) &&

	    utn_pIngresoDeAnioTipoEntero_(&(unaEstructura)->fecha_Ingreso_Empleado.anio," DE INGRESO " ,"\n ERROR" ,0 , 5000, 2) &&

        SECTOR_pMuestraListaSectores_DeTam_UNO(unaListaDeEstructuras,tamUnaListaDeEstructuras) &&

        utn_pIngresoDeElementoTipoEntero_( &unaEstructura->ID_Sector, "\n INGRESE SECTOR AL CUAL PERTENECE EL EMPLEADO: ", "\n ERROR", 500, 504, 2))

    {
             //(*unaEstructura).flag = FLAGOCUPADO;
             (*unaEstructura).is_Empleado_Full = FULL;
             retorno = 1;
    }
    else
    {
        retorno = 0;
    }

	//printf("ingrese fecha dd/mm/aaaa: n")
	/*
	printf("ingrese fecha dd/mm/aaaa: n");
    scanf("%d/%d/%d",&unaEstructura->fecha_Ingreso_Empleado.dia,&(unaEstructura)->fecha_Ingreso_Empleado.mes,&auxEmpleado.fecha_Ingreso_Empleado.anio);
	*/

	//return retorno;
//}



/*

//
int utn_bajaUnaEstructuraConId_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,int auxIdEstructura)
{
	int retorno;
	retorno=0;
	int auxIndice;
	int flag;
	flag=0;


	if( listaDeEstructuras != NULL && tamListaDeEstructuras > 0)
	{

        printf("\n\n BAJA DE EMPLEADOS \n");

            system("cls");

            if(utn_BuscarElemento_EnListaDeEstructura_DeTam_(auxIdEstructura, listaDeEstructuras, tamListaDeEstructuras,&auxIndice))
            {
                    flag=1;
            }
            else
            {
                    printf("\n EL NUMERO DE LEGAJO INGRESADO NO EXISTE \n");
                    retorno=0;
            }


            if(flag)
            {
                  utn_MuestraUnaEstructura_( listaDeEstructuras + auxIndice, "\n                    EMPLEADO SELECCIONADO       \n"
                                                                        ,"| LEGAJO  |"
                                                                        , "NOMBRE   |"
                                                                        , "APELLIDO  |"
                                                                        , " FECHA DE NACIMIENTO |"
                                                                        , "EDAD  |","SEXO  |"
                                                                        ,"SUELDO  |"
                                                                        ,"FECHA DE INGRESO     |"
                                                                        ,"" );


                    if(utn_pRespuestaBooleanaSiUno_NoCero("\n\n\n DESEA ELIMINAR EMPLEADO? S/N "," , ERROR \n",2))
                    {
                        (*(listaDeEstructuras + auxIndice)).is_Empleado_Full = NO_FULL;
                        retorno = 1;

                    }
                    else
                    {
                        printf("\n EL EMPLEADO NO FUE ELIMINADO \n");
                        retorno=0;
                    }
            }

        return retorno;
	  }


}
*/





/*
int utn_MuestraListaEstructuras_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,
                                       eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras)
{
	int retorno;
	retorno= 0;
	int flag;
	flag=-1;
	int cantidad;

	if( listaDeEstructuras != NULL && tamListaDeEstructuras > 0)
	{

		for (int i = 0; i < tamListaDeEstructuras ; i++)
		{
                  //listaDeEstructuras + i)->isEmpty
			if( (*(listaDeEstructuras + i)).is_Empleado_Full )
			{

                utn_MuestraUnaEstructura_DeLaListaDeEstructuras_( listaDeEstructuras + i,
                                                                 otraListaDeEstructuras,tamOtraListaDeEstructuras);
				puts("---------------------------------------------------------------------------------------------------------------------------------------|");
				flag=1;
				retorno=1;
			}

        }

        if(!flag)
        {
            printf("ERROR \n");
        }
    }

    return retorno;
}
/*

/*
int utn_MuestraUnaEstructura_DeLaListaDeEstructuras_(eEmpleado* unaEstructura
                                                     ,eSector* otraListaDeEstructuras,int tamOtraListaDeEstructuras)
{

    int retorno;
    retorno=0;
    char cadena[50];

    if(utn_DescripcionDeLaEstructuraConElId_enLista_DeTam_( (*(unaEstructura)).ID_Sector,otraListaDeEstructuras
                                                                ,tamOtraListaDeEstructuras,cadena ))
    {
        printf("\n %2d    %10s     %10s     %02d/%02d/%02d       %5d      %10s     %.2f         %02d/%02d/%02d         %5d             %s\n"
                                                                                ,unaEstructura->legajo,
                                                                                unaEstructura->nombre,
                                                                                (*(unaEstructura)).apellido,
                                                                                (*(unaEstructura)).fecha_Nacimiento_Empleado.dia,
                                                                                unaEstructura->fecha_Nacimiento_Empleado.mes,
                                                                                unaEstructura->fecha_Nacimiento_Empleado.anio,
                                                                                (*(unaEstructura)).edad,
                                                                                (*(unaEstructura)).sexo,
                                                                                unaEstructura->fecha_Ingreso_Empleado.dia,
                                                                                (*unaEstructura).sueldo,
                                                                                (*(unaEstructura)).fecha_Ingreso_Empleado.mes,
                                                                                unaEstructura->fecha_Ingreso_Empleado.anio,
                                                                                unaEstructura->ID_Sector,
                                                                                cadena );
                                                                                retorno=1;
    }
	else
	{

		printf("              HUBO UN PROBLEMA CON LA DESCRIPCION DEL SECTOR , NO SE PUDO DAR DE ALTA EL EMPLEADO \n");

	}

    return retorno;
}
/*



/*
int utn_pMuestraListaDeEmpleados_DeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras,
                                       char* mensajeBienvenidaALMenu, char* mensajeError,
                                       char* mensajeEspecificoParaFuncionMuestraUnaEstructura,char* itemUno,
                                       char* itemDos,char* itemTres,char* itemCuatro,char* itemQuinto
                                       ,char* itemSexto,char* itemSeptimo,char* itemOctavo,char* itemNoveno)
{
	int retorno;
	retorno= 0;
	int flag;
	flag=-1;
	int cantidad;

	if( listaDeEstructuras != NULL && tamListaDeEstructuras > 0)
	{
	    /*
        for(int i=0; i < tamListaDeEstructuras; i++)
        {
            if( (*(listaDeEstructuras + i)).flag )
            {
                puts(mensajeBienvenidaALMenu);

                puts("--------------------------------------------------------------------------------------------------------------------------------------------");
                        printf("%s    %s %s%s   %s   %s     %s    %s    %s",itemUno, itemDos, itemTres, itemCuatro, itemQuinto,itemSexto,itemSeptimo,itemOctavo,itemNoveno);
                puts("\n-------------------------------------------------------------------------------------------------------------------------------------------");
                break;
            }
        }


		for (int i = 0; i < tamListaEstructuras ; i++)
		{
                  //listaDeEstructuras + i)->isEmpty
			if( (*(listaDeEstructuras + i)).is_Empleado_Full )
			{

                utn_MuestraUnEmpleado_( listaDeEstructuras + i,mensajeEspecificoParaFuncionMuestraUnaEstructura
                                        ,itemUno,itemDos,itemTres,itemCuatro,itemQuinto,itemSexto,itemSeptimo
                                        ,itemOctavo,itemNoveno);
				puts("---------------------------------------------------------------------------------------------------------------------------------------|");
				flag=1;
				retorno=1;
			}

        }
    }

            if(flag== -1)
            {
                printf("%s",mensajeError);
            }

        return retorno;
}
/*

/*
int utn_MuestraUnEmpleado_(eEmpleado* unaEstructura,char* mensajeBienvenida
                              ,char* itemUno,char* itemDos
                              ,char* itemTres,char* itemCuatro
                              ,char* itemQuinto,char* itemSexto
                              ,char* itemSeptimo,char* itemOctavo,char* itemNoveno)
{

    int retorno;
    retorno=0;

          printf("     %d         %s      %s          %02d/%02d/%02d         %d      %s         %.2f            %02d/%02d/%02d\n"
                                                                                ,unaEstructura->legajo,
                                                                                unaEstructura->nombre,
                                                                                unaEstructura->apellido,
                                                                                (*(unaEstructura)).fecha_Nacimiento_Empleado.dia,
                                                                                unaEstructura->fecha_Nacimiento_Empleado.mes,
                                                                                unaEstructura->fecha_Nacimiento_Empleado.anio,
                                                                                (*(unaEstructura)).edad,
                                                                                (*(unaEstructura)).sexo,
                                                                                (*unaEstructura).sueldo,
                                                                                unaEstructura->fecha_Ingreso_Empleado.dia,
                                                                                unaEstructura->fecha_Ingreso_Empleado.mes,
                                                                                unaEstructura->fecha_Ingreso_Empleado.anio);

    return retorno;
}
/*



/*
int utn_OrdenarEstructura_PorEdadDeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras)
{
    int retorno;
    retorno=0;
	eEmpleado auxEstructura;
	int auxCriterioCrecienteDecreciente;

     utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente," \n  INGRESE 1 PARA ORDENAR LAS EDADES DE LOS EMPLEADOS DE FORMA CRECIENTE.\n"
                                                                          "\n  INGRESE 0 PARA ORDENAR LAS EDADES DE LOS EMPLEADOS DE FORMA DECRECIENTE: ", "\n ERROR",0,1,3);


	for(int i=0; i < tamListaDeEstructuras -1 ; i++)
	{
		for(int j= i + 1; j < tamListaDeEstructuras ; j++)
		{
			if( (listaDeEstructuras + i) -> edad >  (*(listaDeEstructuras + j)).edad && auxCriterioCrecienteDecreciente

             || ( (listaDeEstructuras + i) -> edad <  (*(listaDeEstructuras + j)).edad && !auxCriterioCrecienteDecreciente)  )
			{
				auxEstructura = (*(listaDeEstructuras + i)) ;
				(*(listaDeEstructuras + i)) = (*(listaDeEstructuras + j));
				(*(listaDeEstructuras + j))=auxEstructura;
				retorno = 1;
			}
		}
	}

	return retorno;
}
/*

/*
int utn_OrdenarEstructuras_PorNombreDeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras)
{
    int retorno;
	retorno=0;
	eEmpleado auxEstructura;
	int auxCriterioCrecienteDecreciente;

     utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente," \n  INGRESE 1 PARA ORDENAR LOS NOMBRES DE LOS EMPLEADOS DE FORMA CRECIENTE.\n"
                                                                          "\n  INGRESE 0 PARA ORDENAR LOS NOMBRES DE LOS EMPLEADOS DE FORMA DECRECIENTE: ", "\n ERROR",0,1,3);


	for(int i =0; i < tamListaDeEstructuras -1 ; i++)
	{
		for(int j= i + 1; j < tamListaDeEstructuras ; j++)
		{

			if(strcmp( (*(listaDeEstructuras + i) ).nombre , (listaDeEstructuras + j) -> nombre ) > 0 && auxCriterioCrecienteDecreciente

            ||  strcmp( (*(listaDeEstructuras + i) ).nombre , (listaDeEstructuras + j) -> nombre ) < 0 && !auxCriterioCrecienteDecreciente)
			{
				auxEstructura = (*(listaDeEstructuras + i));
				(*(listaDeEstructuras + i)) = (*(listaDeEstructuras + j));
				(*(listaDeEstructuras + j)) = auxEstructura;
                retorno=1;
			}
		}
	}

	return retorno;
}
/*

/*
int utn_OrdenarEstructura_PorLegajoDeTam_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras)
{

	int retorno;
	retorno=0;
	eEmpleado auxEstructura;
	int auxCriterioCrecienteDecreciente;

     utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente," \n  INGRESE 1 PARA ORDENAR LOS LEGAJOS DE LOS EMPLEADOS DE FORMA CRECIENTE.\n"
                                                                          "\n  INGRESE 0 PARA ORDENAR LOS LEGAJOS DE LOS EMPLEADOS DE FORMA DECRECIENTE: ", "\n ERROR",0,1,3);


	for(int i=0; i < tamListaDeEstructuras -1 ; i++)
	{
		for(int j= i + 1; j < tamListaDeEstructuras ; j++)
		{
			if( (listaDeEstructuras + i)-> legajo > (*(listaDeEstructuras + j)).legajo && auxCriterioCrecienteDecreciente

            || ( (listaDeEstructuras + i)->legajo <  (*(listaDeEstructuras + j)).legajo && !auxCriterioCrecienteDecreciente)  )

			{
				auxEstructura = (*(listaDeEstructuras + i));
				(*(listaDeEstructuras + i)) = (*(listaDeEstructuras + j));
				(*(listaDeEstructuras + j)) = auxEstructura;
				retorno = 1;
			}
		}
	}

	return retorno;
}
/*

/*
int utn_OrdenamientoDobleCriterioEstructuras_DeTam_EntreUnCampoEntero_Y_(eEmpleado* listaDeEstructuras,int tamListaDeEstructuras)
{
	int retorno;
	retorno = 0;
	eEmpleado auxEstructura;

	int auxCriterioCrecienteDecreciente;

	puts("\n  EL PRIMER CRITERIO SERA LA EDAD, SI HAY EMPATE EN EDADES SE ORDENA POR LEGAJOS.\n");

    utn_pIngresoDeElementoTipoEntero_(&auxCriterioCrecienteDecreciente," \n  INGRESE 1 PARA ORDENAR LEGAJOS DE FORMA CRECIENTE EN CASO DE EMPATE EN LAS EDADES.\n"
                                                                          "\n  INGRESE 0 PARA ORDENAR LEGAJOS DE FORMA DECRECIENTE EN CASO DE EMPATE EN LAS EDADES: ", "\n ERROR",0,1,3);


	for(int i=0 ; i < tamListaDeEstructuras -1 ;i++)
	{
		for(int j= i+1; j < tamListaDeEstructuras ;j++)
		{

                    if( (  (*(listaDeEstructuras + i)).edad < (listaDeEstructuras + j)->edad
                            ||  (*(listaDeEstructuras + i)).edad == (listaDeEstructuras + j)->edad
                        && (listaDeEstructuras + i)->legajo > (*(listaDeEstructuras + j)).legajo
                                                                        && auxCriterioCrecienteDecreciente)

                            ||   (  (*(listaDeEstructuras + i)).edad < (listaDeEstructuras + j)->edad
                                ||  (*(listaDeEstructuras + i)).edad == (listaDeEstructuras + j)->edad
                                && (listaDeEstructuras + i)->legajo < (*(listaDeEstructuras + j)).legajo
                                                                                    && !auxCriterioCrecienteDecreciente  ))

			{
				auxEstructura = *(listaDeEstructuras + i) ;
				*(listaDeEstructuras + i) = *(listaDeEstructuras + j) ;
				*(listaDeEstructuras + j) = auxEstructura;
                retorno = 1;
			}
		}
	}

	return retorno;

}
/*



/*
//DOY DE BAJA A LOS ALMUERZOS DE ESE EMPLEADO
int NEXO_bajaAlmuerzoEmpleado(eEmpleado* listaEmpleados,int tamListaEmpleados
                             ,eSector* listaSectores,int tamListaSectores
                             ,eAlmuerzo* listaAlmuerzos,int tamListaAlmuerzos
                             ,eComida* lista_Comidas,int tamListaComidas)

{

        int retorno;
        retorno=0;
		int auxID_Empleado;
        int flag;
        flag = 0;

		flag = utn_MuestraListaEstructuras_DeTam_(listaEmpleados,tamListaEmpleados,listaSectores,tamListaSectores);



		if(!flag)
		{
			printf("\n NO EXISTEN EMPLEADOS \n");
			retorno=0;

		}
		else
		{

            utn_pIngresoDeElementoTipoEntero_(&auxID_Empleado, "\n INGRESE LEGAJO DEL EMPLEADO ", "\n ERROR", 2000, 3000, 2);

			for(int i=0; i < tamListaAlmuerzos ;i++)
			{

                ALMUERZO_bajaTodosAlmuerzos_DeEmpleadoConId_(listaAlmuerzos,tamListaAlmuerzos,&auxID_Empleado);
                retorno = 1;
			}
		}


        utn_MuestraListaDeAlmuerzos_DeTam_(listaAlmuerzos,tamListaAlmuerzos,listaSectores,tamListaSectores
                                            ,listaEmpleados,tamListaEmpleados,listaComidas,tamListaComidas
                                           ,"\n\n                                                    MENU ALMUERZOS ", "ERROR"
                                           , "ID ALMUERZO "," LEGAJO EMPLEADO "
                                           , " NOMBRE EMPLEADO "," APELLIDO EMPLEADO "
                                           , " ID COMIDA" , " NOMBRE COMIDA"
                                           , "FECHA DE ALMUERZO ", "SECTOR DEL EMPLEADO","","" );


        //printf("\n DESEA DAR DE BAJA AL EMPLEADO? 1 si / 0 no \n");
        //scanf("%d", &flag);

        if( utn_pRespuestaBooleanaSiUno_NoCero("\n\n\n DESEA ELIMINAR EMPLEADO? S/N "," , ERROR \n",2))
        {
            utn_bajaUnaEstructuraConId_DeTam_(listaDeEmpleados,tamListaEmpleados,auxIdEmpleado);
        }
         else
        {
            printf("\n EL EMPLEADO NO FUE ELIMINADO \n");
        }

        utn_MuestraListaEstructuras_DeTam_(listaDeEmpleados,tamListaEmpleados,listaDeSectores,tamListaDeSectores);

		return retorno;

}
*/


/*
    utn_MuestraUnAlmuerzo_DeLaListaDeAlmuerzos_(listaDeAlmuerzos + i
                                                        ,listaDeSectores,tamListaDeSectores
                                                        ,listaDeEmpleados,tamListaEmpleados
                                                        ,"\n\n                                                    MENU EMPLEADOS "
                                                        , " " , "ID ALMUERZO "," LEGAJO EMPLEADO "
                                                       , " NOMBRE EMPLEADO "," APELLIDO EMPLEADO "
                                                       , " ID COMIDA" , " NOMBRE COMIDA"
                                                       , "FECHA DE ALMUERZO ", "SECTOR DEL EMPLEADO");

*/

