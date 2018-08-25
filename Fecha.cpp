#include "Fecha.h"

bool IsValidFecha(Fecha fecha)
{
    bool isValid = false;
    switch (fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (fecha.dia>=1 && fecha.dia<=31)
            isValid=true;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (fecha.dia>=1 && fecha.dia<=30)
            isValid=true;
        break;
    case 2:
        if (fecha.anio%4 == 0)
        {
            if (fecha.dia>=1 && fecha.dia<=29)
                isValid=true;
        }
        else
        {
            if (fecha.dia>=1 && fecha.dia<=28)
                isValid=true;
        }
        break;
    }
    return isValid;
}

void CargarFecha(Fecha &fecha)
{
    printf("\nIngrese d%sa: ", LETRA_i);
    scanf("%d",&fecha.dia);
    printf("\nIngrese mes: ");
    scanf("%d",&fecha.mes);
    printf("\nIngrese a%so: ", LETRA_n);
    scanf("%d",&fecha.anio);
}

void PreCargarFecha(Fecha &fecha, int dia, int mes, int anio)
{
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;
}

void ImprimirFecha(Fecha fecha)
{
    printf("%d/%d/%d",fecha.dia,fecha.mes,fecha.anio);
}

int CompararFechas(Fecha fecha1, Fecha fecha2)
{
    /**
    función comparaFecha, devuelve:
     -1 si fecha1 < fecha2
      0 si fecha1 = fecha2 //bien
      1 si fecha1 > fecha2 //bien
    **/
    int val;
    if ( fecha1.anio < fecha2.anio )
        val = -1;
    else if ( fecha1.anio > fecha2.anio )
        val = 1;
    else   // año igual
    {
        if ( fecha1.mes < fecha2.mes )
            val = -1;
        else if ( fecha1.mes > fecha2.mes )
            val = 1;
        else   // mes igual
        {
            if ( fecha1.dia < fecha2.dia )
                val = -1;
            else if ( fecha1.dia > fecha2.dia )
                val = 1;
            else // dia igual
                val = 0;
        }
    }
    return val;
}

int DarDia(Fecha fecha)
{
    return fecha.dia;
}

int DarMes(Fecha fecha)
{
    return fecha.mes;
}

int DarAnio(Fecha fecha)
{
    return fecha.anio;
}
