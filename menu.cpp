#include "menu.h"

void MenuInicial()
{
    int opcion;
    bool isOP1Cargada = false, isSalir=false;

    //CREACION DE ESTRUCTURAS EN MEMORIA
    Asignaturas asignaturasDeAcademia;
    makeAsignaturas(asignaturasDeAcademia);

    PreviaturasIndex PreviaturasIndexDeAcademia;
    makePreviaturasIndex(PreviaturasIndexDeAcademia);

    Alumnos alumnosDeAcademia;
    makeAlumnos(alumnosDeAcademia);

    do
    {
        fflush(stdin);
        isOP1Cargada = isAllLoadedAignaturas(asignaturasDeAcademia);
        MenuPrincipal(opcion, isOP1Cargada);
        if (!isOP1Cargada)
        {
            switch (opcion)
            {
            case 1:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nRegistrar manualmente 12 nombres de Asignaturas\n");
                cargarAsignaturasManualmente(asignaturasDeAcademia);
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 2:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nRegistrar autom%sticamente los 12 nombres de Asignaturas\n",LETRA_a);
                cargarAsignaturasAutomaticamente(asignaturasDeAcademia);
                printf("\nDesea cargar las previaturas autom%sticamente tambi%sn?",LETRA_a,LETRA_e);
                bool isCargarPrevsAuto = false;
                OpcionCarga(isCargarPrevsAuto);
                if (isCargarPrevsAuto)
                    cargarPreviaturasAutomaticamente(PreviaturasIndexDeAcademia);
                else
                    printf("\nNo se cargo ninguna previatura, usted deber%s cargarlas manualmente",LETRA_a);
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 0:
            {
                printf("\n***Opci%sn %d - Est%s seguro que desea salir?***", LETRA_o,opcion, LETRA_a);
                isSalir = false;
                OpcionCarga(isSalir);
                if (!isSalir)
                {
                    opcion = 99;//opcion=1;
                    // system(LIMPIAR);
                }
                else
                {
                    system(LIMPIAR);
                    opcion=0;
                    MensajeSalida();
                }
                // LimpiarYPausa();
            }
            break;
            default:
                system(LIMPIAR);
                printf("\n***Error, reintente con un car%scter v%slido.***", LETRA_a,LETRA_a);
                LimpiarYPausa();
                opcion = 99;
                break;
            }
        }
        else
        {
            switch (opcion)
            {
            case 1:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nListado de n%smero y nombre de las Asignaturas\n",LETRA_u);
                listAllAsignaturas(asignaturasDeAcademia);
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 2:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nAgregar previatura entre dos materias\n");
                int a1,a2;
                printf("\nIngrese el ID de la primer asignatura, que ser%s previatura de la segunda: ", LETRA_a);
                scanf("%d",&a1);
                if (a1<N && a1>=0)
                {
                    printf("\nIngrese el ID de la segunda asignatura, la cual requiere de la anterior ingresada: ");
                    scanf("%d",&a2);
                    if (a2<N && a2>=0)
                    {
                        if ( a1 == a2 )
                        {
                            printf("\n***Error, no se puede ingresar previatura como si misma a una asignatura");
                        }
                        else
                        {
                            int isErrorPorPertenenciaDirecta = 0;
                            bool puede = false;
                            puedeInsertarPreviatura(PreviaturasIndexDeAcademia, a1, a2, isErrorPorPertenenciaDirecta, puede);
                            if ( puede == true )
                            {
                                PreviaturasIndexInsertAristaGrafo(PreviaturasIndexDeAcademia, a1, a2); //se valida adentro tambien la no existencia de la misma previatura en la lista, que no se repita
                                printf("\nLa asignatura fue cargada correctamente");
                                Previaturas pvs;
                                pvs = NULL;
                                getAllPreviaturasByIDRec(PreviaturasIndexDeAcademia,a2,pvs);
                                MostrarDatosAsignatura(asignaturasDeAcademia[a2]);
                                printf("\nPreviaturas: ");
                                listAllPreviaturasByID(pvs,asignaturasDeAcademia);
                                printf("\n\n");
                            }
                            else
                            {
                                printf("\n***Error, no se puede ingresar previatura entre estas dos asignaturas");
                                if (isErrorPorPertenenciaDirecta == 1)
                                {
                                    printf("\nLa asignatura de ID: %d, ya est%s ingresada como previatura directa de la asignatura con ID: %d",a1,LETRA_a,a2);
                                }
                                else if (isErrorPorPertenenciaDirecta == 2)
                                {
                                    printf("\nLa asignatura de ID: %d, est%s ingresada como previatura directa de la asignatura con ID: %d",a2,LETRA_a,a1);
                                }
                                else
                                {
                                    if ( isErrorPorPertenenciaDirecta == 3 )
                                    {
                                        printf("\nLa asignatura de ID: %d, est%s ingresada como previatura indirectamente de la asignatura con ID: %d",a2,LETRA_a,a1);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\n***Error, el ID de asignatura no es v%slido\nEl rango de ID va desde 0 a %d (inclusive)",LETRA_a,N-1);
                    }
                }
                else
                {
                    printf("\n***Error, el ID de asignatura no es valido\nEl rango de ID va desde 0 a %d (inclusive)",N-1);
                }
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 3:
            {
                fflush(stdin);
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nListar todas las previas, directas e indirectas, de una asignatura\n");
                int a1;
                printf("\nIngrese el ID de la asignatura la cual quiere consultar sus previaturas directas e indirectas: ");
                scanf("%d",&a1);
                if (a1<N && a1>=0)
                {
                    if ( tieneAlgunaPreviatura(PreviaturasIndexDeAcademia, a1) )
                    {
                        MostrarDatosAsignatura(asignaturasDeAcademia[a1]);
                        printf("\nPreviaturas:\n");
                        bool visitados[N];
                        for (int i=0; i<N ; i++ )
                        {
                            visitados[i] = false;
                        }
                        Previaturas pvs;
                        makePreviaturas(pvs);
                        getAllPreviaturasByID(PreviaturasIndexDeAcademia, a1, pvs, visitados );
                        listAllPreviaturasByID(pvs, asignaturasDeAcademia);
                    }
                    else
                    {
                        printf("\n***Error, esta asignatura no tiene previaturas");
                    }
                }
                else
                {
                    printf("\n***Error, el ID de asignatura no es valido\nEl rango de ID va desde 0 a %d (inclusive)",N-1);
                }
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 4:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nIngresar un Alumno a la academia\n");
                int ci;
                String auxCI;
                StringCrear(auxCI);
                String auxTel;
                StringCrear(auxTel);
                fflush(stdin);
                printf("\nIngrese CI de alumno: ");
                StringScan(auxCI);
                if (!StringEqualNumeroEntero(auxCI))
                {
                    printf("\n***Error, la CI solo puede ser n%smeros positivos",LETRA_u);
                }
                else
                {
                    ci = StringToNumeric(auxCI);
                    if(ci < 0)
                    {
                        printf("\n***Error, el telefono solo puede ser n%smeros positivos",LETRA_u);
                    }
                    else if (memberAlumnosByCI(alumnosDeAcademia, ci) )
                    {
                        printf("\n***Error, el telefono solo puede ser n%smeros positivos",LETRA_u);
                    }
                    else
                    {
                        fflush(stdin);
                        int telefono;
                        String nombre, apellido, domicilio;
                        StringCrear(nombre);
                        StringCrear(apellido);
                        StringCrear(domicilio);
                        Alumno nuevoAlumno;
                        printf("\nIngrese nombre de alumno: ");
                        StringScan(nombre);
                        if (StringContieneNumeros(nombre))
                        {
                            printf("\n***Error, el nombre de alumno no puede contener n%smeros",LETRA_u);
                        }
                        else
                        {
                            printf("\nIngrese apellido de alumno: ");
                            StringScan(apellido);
                            if (StringContieneNumeros(apellido))
                            {
                                printf("\n***Error, el apellido de alumno no puede contener n%smeros",LETRA_u);
                            }
                            else
                            {
                                printf("\nIngrese domicilio de alumno: ");
                                StringScan(domicilio);
                                printf("\nIngrese tel%sfono de alumno: ",LETRA_e);
                                StringScan(auxTel);
                                if (!StringEqualNumeroEntero(auxTel))
                                {
                                    printf("\n***Error, el telefono solo puede ser n%smeros positivos",LETRA_u);
                                }
                                else
                                {
                                    telefono = StringToNumeric(auxTel);
                                    if (telefono < 0)
                                    {
                                        printf("\n***Error, el telefono solo puede ser n%smeros positivos",LETRA_u);
                                    }
                                    else
                                    {
                                        CargaAlumno(nuevoAlumno, ci, nombre, apellido, domicilio, telefono);
                                        StringDelete(nombre);
                                        StringDelete(apellido);
                                        StringDelete(domicilio);
                                        printf("\n\nLos datos ingresados de alumno fueron: \n");
                                        MostrarDatosAlumno(nuevoAlumno);
                                        insertAlumnos(alumnosDeAcademia,nuevoAlumno);
                                    }
                                }
                            }
                        }
                    }
                }
                StringDelete(auxCI);
                StringDelete(auxTel);
                LimpiarYPausa();
                //fflush(stdin);
                opcion = 99;
            }
            break;
            case 5:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nListado de datos b%ssicos de todos los Alumnos\n",LETRA_a);
                if (IsVacioAlumnos(alumnosDeAcademia))
                {
                    printf("\n***Error, no hay alumnos ingresados en el sistema");
                }
                else
                {
                    listAllAlumnos(alumnosDeAcademia);
                }
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 6:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nIngresar aprobaci%sn a Escolaridad de un Alumno\n", LETRA_o);
                int ci;
                String auxCI;
                StringCrear(auxCI);
                fflush(stdin);
                printf("\nIngrese CI de alumno para agregarle una escolaridad: ");
                StringScan(auxCI);
                if (!StringEqualNumeroEntero(auxCI))
                {
                    printf("\n***Error, la CI solo puede ser n%smeros positivos",LETRA_u);
                }
                else
                {
                    ci = StringToNumeric(auxCI);
                    if(ci < 0)
                    {
                        printf("\n***Error, la CI solo puede ser n%smeros positivos",LETRA_u);
                    }
                    else if (!memberAlumnosByCI(alumnosDeAcademia, ci) )
                    {
                        printf("\n***Error, esta CI no esta ingresada en el sistema");
                    }
                    else
                    {
                        int id;
                        printf("\nIngrese ID de asignatura para agregarle a la escolaridad del alumno: ");
                        scanf("%d",&id);
                        if (id<N && id>=0)
                        {
                            if ( memberEscolaridades(DarAprobacionesAlumno(findAlumnos(alumnosDeAcademia,ci)), id) )
                            {
                                printf("\n***Error, esta ID de asignatura ya esta ingresada como previatuira del alumno");
                            }
                            else
                            {
                                if (! tieneTodasLasPreviaturas( DarAprobacionesAlumno(findAlumnos(alumnosDeAcademia,ci)), id, PreviaturasIndexDeAcademia) )
                                {
                                    printf("\n***Error, el alumno no tiene aprobadas las asignaturas previas necesarias para ingresar esta aprobacion a su escolaridad");
                                    Previaturas prvsDirectas;
                                    crearPreviaturas(prvsDirectas);
                                    getSoloPreviaturasDirectasByID(PreviaturasIndexDeAcademia, id, prvsDirectas);
                                    printf("\nLas previas necesarias para la asignatura de ID: %d son:\n",id);
                                    listAllPreviaturasByID(prvsDirectas, asignaturasDeAcademia);
                                }
                                else
                                {
                                    Fecha fechaAprobacion;
                                    float notaAprobacion;
                                    bool isFechaValida;
                                    do
                                    {
                                        printf("\nIngrese una fecha de aprobacion: ");
                                        CargarFecha(fechaAprobacion);
                                        isFechaValida = false;
                                        if (IsValidFecha(fechaAprobacion))
                                            isFechaValida = true;
                                    }
                                    while(!isFechaValida);
                                    printf("\nIngrese una nota de aprobacion: ");
                                    scanf("%f", &notaAprobacion);
                                    Escolaridad nuevaAprobacion;
                                    CargarEscolaridad(nuevaAprobacion, id, fechaAprobacion, notaAprobacion);
                                    ModifyEscolaridadAlumnos(alumnosDeAcademia, ci, nuevaAprobacion);
                                }
                            }
                        }
                        else
                        {
                            printf("\n***Error, el ID de asignatura no es valido\nEl rango de ID va desde 0 a %d (inclusive)",N-1);
                        }
                    }

                }
                StringDelete(auxCI);
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 7:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nListado de Escolaridad de un Alumno (ordenado por fecha de aprobaci%sn)\n",LETRA_o);
                int ci;
                String auxCI;
                StringCrear(auxCI);
                fflush(stdin);
                printf("\nIngrese CI de alumno para listar su escolaridad: ");
                StringScan(auxCI);
                if (!StringEqualNumeroEntero(auxCI))
                {
                    printf("\n***Error, la CI solo puede ser n%smeros positivos",LETRA_u);
                }
                else
                {
                    ci = StringToNumeric(auxCI);
                    if(ci < 0)
                    {
                        printf("\n***Error, la CI solo puede ser n%smeros positivos",LETRA_u);
                    }
                    else if (!memberAlumnosByCI(alumnosDeAcademia, ci) )
                    {
                        printf("\n***Error, esta CI no esta ingresada en el sistema");
                    }
                    else
                    {
                        //SI NO TIENE ESCOLARIDAD ALGUNA, NO MOSTRAR NADA MAS QUE EL MENSAJE DE QUE NO TIENE
                        if (tieneAlgunaEscolaridad(DarAprobacionesAlumno(findAlumnos(alumnosDeAcademia,ci))) )
                        {
                            MostrarDatosAlumno(findAlumnos(alumnosDeAcademia,ci));
                            printf("\n\nAprobaciones del alumno:");
                            listarAllEscolaridades( DarAprobacionesAlumno(findAlumnos(alumnosDeAcademia,ci)) );
                        }
                        else
                        {
                            printf("\n***Error, este alumno no tiene aprobaciones ingresadas en el sistema");
                        }
                    }
                }
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 8:
            {
                printf("\n***Opci%sn %d***", LETRA_o,opcion);
                printf("\nListado de datos completo de Asignaturas con sus previaturas directas\n");
                Previaturas pvs;
                for(int i = 0; i<N; i++)
                {
                    pvs = NULL;
                    getAllPreviaturasByIDRec(PreviaturasIndexDeAcademia,i,pvs);
                    printf("\n================================================\n");
                    MostrarDatosAsignatura(asignaturasDeAcademia[i]);
                    printf("\nPreviaturas: ");
                    listAllPreviaturasByID(pvs,asignaturasDeAcademia);
                    printf("\n");
                    printf("\n\n");
                }
                LimpiarYPausa();
                opcion = 99;
            }
            break;
            case 0:
            {
                printf("\n***Opci%sn %d - Est%s seguro que desea salir?***", LETRA_o,opcion, LETRA_a);
                isSalir = false;
                OpcionCarga(isSalir);
                if (!isSalir)
                {
                    opcion = 99;//opcion=1;
                    // system(LIMPIAR);
                }
                else
                {
                    system(LIMPIAR);
                    opcion=0;
                    MensajeSalida();
                }
                // LimpiarYPausa();
            }
            break;
            default:
                system(LIMPIAR);
                printf("\n***Error, reintente con un car%scter valido.***", LETRA_a);
                LimpiarYPausa();
                opcion = 99;
                break;
            }
        }
    }
    while (opcion != 0);

    //DESTRUCCION DE ESTRUCTURAS EN MEMORIA
    deleteAllAsignaturas(asignaturasDeAcademia);
    deleteAllPreviaturasIndex(PreviaturasIndexDeAcademia);
    deleteAllAlumnos(alumnosDeAcademia);
}

void MenuPrincipal(int &opcion, bool &isOP1Cargada)
{
    fflush(stdin);
    printf("\n****************************Men%s de Opciones Principales************************\n\n", LETRA_u);
    printf("Seleccione un n%smero como opci%sn del men%s:\n", LETRA_u, LETRA_o, LETRA_u);
    if (!isOP1Cargada)
    {
        printf("\n1- Registrar manualmente 12 nombres de Asignaturas");
        printf("\n2- Registrar automatic%smente los 12 nombres de Asignaturas",LETRA_a);
    }
    else
    {
        printf("\n1- Listado de n%smero y nombre de las Asignaturas",LETRA_u);
        printf("\n2- Agregar previatura entre dos asignaturas");
        printf("\n3- Listar todas las previas, directas e indirectas, de una asignatura");
        printf("\n4- Ingresar un Alumno a la academia");
        printf("\n5- Listado de datos b%ssicos de todos los Alumnos (ordenados por CI de menor a mayor)",LETRA_a);
        printf("\n6- Ingresar aprobaci%sn a Escolaridad de un Alumno",LETRA_o);
        printf("\n7- Listado de Escolaridad de un Alumno (ordenado por fecha de aprobaci%sn)", LETRA_o);
        printf("\n8- Listado de datos completo de Asignaturas con sus previaturas directas");
    }
    printf("\n\n0- Para terminar el programa");//op0
    printf("\n\nOpci%sn: ", LETRA_o);
    scanf("%d",&opcion);
}

void MensajeErrorAlumnosVacios()
{
    fflush(stdin);
    printf("\n***Error, para esta opci%sn debe tener cargado algun Alumno previamente.***", LETRA_o);
    LimpiarYPausa();
}

void LimpiarYPausa()
{
    char limpiar;
    fflush(stdin);
    printf("\n\nPresione enter para continuar ");
    scanf("%c",&limpiar);
    system(LIMPIAR);
}

void OpcionCarga(bool &booleanoAcargar)
{
    char opcion;
    do
    {
        fflush(stdin);
        printf("\nIngrese una opci%sn:\nSI: S o 1\nNO: N o 0\n-> ", LETRA_o);
        scanf("%c",&opcion);
        switch (opcion)
        {
        case 's':
            booleanoAcargar=true;
            break;
        case 'S':
            booleanoAcargar=true;
            break;
        case '1':
            booleanoAcargar=true;
            break;
        case '0':
            booleanoAcargar=false;
            break;
        case 'n':
            booleanoAcargar=false;
            break;
        case 'N':
            booleanoAcargar=false;
            break;
        default:
            printf("\nError al leer dato, reintente...");
            break;
        }
    }
    while (opcion != 'S' && opcion != 's' && opcion != '1' && opcion != '0' && opcion != 'N' && opcion != 'n');
}

void MensajeSalida()
{
    int i,j;
    printf("\n\n*******<<<________FIN DEL PROGRAMA ACADEMIA________>>>*******\n\n");
    printf("\n*******<<<*******************************************>>>*******\n");
    for (j=176; j<179; j++)
    {
        printf("\n");
        for (i=0; i<80 ; i++ )
            printf("%c",j);
    }
    printf("\n%c",201);
    for (i=0; i<78 ; i++ )
        printf("%c",205);
}

void logo()
{
    printf("\n     _                 _                _         ____          ____           _                        ");
    printf("\n    / %c   ___ __ _  __| | ___ _ __ ___ (_) __ _  |  _ %c  ___   / ___|___   ___(_)_ __   __ _          ",92,92);
    printf("\n   / _ %c / __/ _` |/ _` |/ _ %c '_ ` _ %c| |/ _` | | | | |/ _ %c | |   / _ %c / __| | '_ %c / _` |     ",92,92,92,92,92,92);
    printf("\n  / ___ %c (_| (_| | (_| |  __/ | | | | | | (_| | | |_| |  __/ | |__| (_) | (__| | | | | (_| |          ",92);
    printf("\n /_/   %c_%c___%c____|%c__,_|%c___|_| |_| |_|_|%c__,_| |____/ %c___|  %c____%c___/ %c___|_|_| |_|%c__,_|  ",92,92,92,92,92,92,92,92,92,92,92);
    printf("\n                                                                                                        ");
}

