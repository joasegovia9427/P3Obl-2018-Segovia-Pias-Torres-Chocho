#include "String.h"

void StringCrear(String &s)
{
    s = new char[1];
    s[0] = '\0';
}

//devuelve el largo de un string dinamico
int StringLargo(String s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void StringCopiar(String &s1, String s2)
{
    int i = 0;
    int largo = StringLargo(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void StringScan (String &s)
{
    String aux = new char[MAX];
    int i=0;
    char c;
    scanf("%c", &c);
    while((c!= '\n') && (i < MAX-1))
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StringCopiar(s,aux);
}

void StringSwap(String &s1, String &s2)
{
    String aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void StringPrint(String s)
{
    fflush(stdin);
    int i = 0;
    while(s[i]!= '\0')
    {
        fflush(stdout);
        printf("%c", s[i]);
        i++;
    }
}

bool StringMenor(String s1, String s2)
{
    int i = 0;
    bool encontre = false;
    bool menor = false;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = true;
        if (s1[i] < s2[i])
            menor = true;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = true;
    return menor;
}

bool StringEqual(String s1, String s2)
{
    int i = 0;
    bool iguales = true;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = false;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = false;
    return iguales;
}

void StringDelete(String s)
{
    delete [] s;
    s = NULL;
}

void crearNombresAsignaturas(String &as1, String &as2, String &as3, String &as4, String &as5, String &as6, String &as7, String &as8, String &as9, String &as10, String &as11, String &as12)
{
    StringCrear(as1);
    StringCrear(as2);
    StringCrear(as3);
    StringCrear(as4);
    StringCrear(as5);
    StringCrear(as6);
    StringCrear(as7);
    StringCrear(as8);
    StringCrear(as9);
    StringCrear(as10);
    StringCrear(as11);
    StringCrear(as12);

    as1[0] = 'I';
    as1[1] = 'G';
    as1[2] = '\0';

    as2[0] = 'C';
    as2[1] = 'G';
    as2[2] = '1';
    as2[3] = '\0';

    as3[0] = 'N';
    as3[1] = 'P';
    as3[2] = '1';
    as3[3] = '\0';

    as4[0] = 'C';
    as4[1] = 'G';
    as4[2] = '2';
    as4[3] = '\0';

    as5[0] = 'P';
    as5[1] = 'G';
    as5[2] = '1';
    as5[3] = '\0';

    as6[0] = 'C';
    as6[1] = '1';
    as6[2] = '\0';

    as7[0] = 'C';
    as7[1] = 'G';
    as7[2] = '3';
    as7[3] = '\0';

    as8[0] = 'E';
    as8[1] = 'B';
    as8[2] = '1';
    as8[3] = '\0';

    as9[0] = 'C';
    as9[1] = '2';
    as9[2] = '\0';

    as10[0] = 'C';
    as10[1] = 'G';
    as10[2] = '4';
    as10[3] = '\0';

    as11[0] = 'N';
    as11[1] = 'P';
    as11[2] = '2';
    as11[3] = '\0';

    as12[0] = 'P';
    as12[1] = 'G';
    as12[2] = '2';
    as12[3] = '\0';

}

//retorna el int y con el signo en el caso de tenerlo...
int StringToNumeric(String s1)
{
    int cantUnidades, nroParseado = 0;
    int i=0, j=0, n=0, x=0, y=0;
    bool isNegativo = false;
    if (s1[0] == '-')//por la logia del isNumeric, se que solo tengo que validar el [0]=='-', si es negativo levanto flag para hacer 0 - num al final, ademas nunca leo se - en el for
    {
        isNegativo = true;
        StringQuitarSimboloSignoNeg(s1);
    }
    cantUnidades = StringLargo(s1);
    for (i=0; i<cantUnidades; i++)
    {
        n = s1[cantUnidades - (i+1)] - '0';
        x = n;
        y = i;
        for (j=0; j<y; j++)
        {
            x *= 10;
        }
        nroParseado = nroParseado + x;
    }

    if (isNegativo == true)
    {
        nroParseado =  0-nroParseado;
        return nroParseado;
    }
    else
    {
        return nroParseado;
    }
}

void StringQuitarSimboloSignoNeg(String &s1)
{
    int i = 1;
    while (   (s1[i] != '\0')  )
    {
        s1[i-1] = s1[i];
        i++;
    }
    s1[i-1] = '\0';
}

//Funcion que verifica si el string contiene al menos un caracter numerico.
bool StringContieneNumeros(String s1)
{

    int i = 0;
    bool hayNumeros = false;
    while (!hayNumeros  && (s1[i] != '\0'))
    {
        if ((s1[i] >= 48) && (s1[i] <= 57))
            hayNumeros  = true;
        i++;
    }
    return hayNumeros;
}


//valida que el s1 sea igual a un numero entero
bool StringEqualNumeroEntero(String s1)
{
    String s;
    StringCrear(s);
    StringCopiar(s,s1);
    bool isNumero = true;

    if ( (StringLargo(s) == 1) && (s[0]=='-') ) //si al ver si los caracteres son numeros, si es justo el primero y ademas es igual a '-', significa que es un numero negativo, el strToInt tiene que validar seguro que si se da el caso, solo el [0] contendra un -, en ese caso se ara 0 menos el numero antes de retornarlo y se retornara la diferencia
    {
        isNumero = false;
    }
    else if (  (StringLargo(s) >= 2) && (s[0]=='-')  )
    {
        StringQuitarSimboloSignoNeg(s);
    }

    int i = 0;
    while((isNumero) && (s[i] != '\0'))
    {
        if( (s[i] != '0') &&
                (s[i] != '1') &&
                (s[i] != '2') &&
                (s[i] != '3') &&
                (s[i] != '4') &&
                (s[i] != '5') &&
                (s[i] != '6') &&
                (s[i] != '7') &&
                (s[i] != '8') &&
                (s[i] != '9')  )
        {
            isNumero = false;
        }
        else
        {
            i++;
        }
    }
    return isNumero;
}

bool StringContieneSoloLetras(String s1)
{
    int i = 0;
    bool hayOtrosCaracteres = false;
    while (!hayOtrosCaracteres  && (s1[i] != '\0'))
    {
        if ((s1[i]<65)&&(s1[i]>90))
        {
            if ((s1[i]<97)&&(s1[i]>122))
            {
                hayOtrosCaracteres  = true;
            }
        }
        i++;
    }
    return hayOtrosCaracteres;
}
