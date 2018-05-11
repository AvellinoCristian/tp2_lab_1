#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarEstado(ePersona lista[],int tam)
{
    int i;
    for (i=0; i<tam; i++)
        lista[i].estado=-1;
}

int obtenerEspacioLibre(ePersona lista[],int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].estado == -1)
            return i;

    }
    return -1;
}


int buscarPorDni(ePersona lista[], int dni,int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].dni == dni)
            return i;

    }
    return -1;
}

int altaPersona(ePersona lista[],int tam,int* m18,int* e19y35,int* m35)
{
    int aux,lugarLibre;
    char auxNombre[50];
    system("cls");

    lugarLibre = obtenerEspacioLibre(lista,tam);

    if (lugarLibre== -1) //Memoria
    {
        printf("No queda memoria\n");
        return -1;
    }
    else //Alta de datos
    {
        aux=getString(auxNombre,"Nombre","El nombre es muy largo",1,10);

        if (aux)
        {
            return -1;
        }

        if (esSoloLetras(auxNombre)== -1)
        {
            printf("Solo se pueden ingresar letras\n");
            return -1;
        }

        strcpy(lista[lugarLibre].nombre,auxNombre);


        printf("Ingresar DNI\n");
        fflush(stdin);
        scanf("%[^\n]",auxNombre);




        if ( esSoloNumeros(auxNombre) == -1)
        {
            lista[lugarLibre].dni = atoi(auxNombre);
            return -1;
        }

        else
            lista[lugarLibre].dni = atoi(auxNombre);



        if (getInt(&aux,"Edad","Ingresar edad valida 0 - 100",0,100)==-1)
        {
            return -1;
        }

        lista[lugarLibre].edad = aux;

        if (aux<18)
            *m18 = *m18 + 1;
        if(aux <=35 && aux>= 19)
            *e19y35 = *e19y35 + 1;
        if(aux >35)
            *m35 = *m35+ 1;



    }

    lista[lugarLibre].estado = 0;
    return 0;
}


int esSoloNumeros(char cadena[])
{
    int i=0;
    while (cadena[i] != '\0')
    {
        if( cadena[i]< '0' || cadena[i] > '9')
            return -1;
        i++;

    }
    return 0;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{

    char aux[200];

    printf("%s\n",message);
    fflush(stdin);
    scanf("%[^\n]",aux);

    if (strlen(aux) >= lowLimit && strlen(aux) <= hiLimit )

    {
        strcpy(input,aux);
        return 0;
    }

    printf("%s\n",eMessage);
    return -1;

}


int esSoloLetras(char cadena[])
{
    int i=0;
    while (cadena[i] != '\0')
    {
        if( (cadena[i]!= ' ')&&(cadena[i]< 'a' || cadena[i] > 'z')&&(cadena[i] < 'A' || cadena[i] > 'Z'))
            return -1;
        i++;

    }
    return 0;
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;

    printf("%s\n",message);
    fflush(stdin);
    scanf("%d",&aux);

    if (aux >= lowLimit && aux <= hiLimit)
    {
        *input=aux;
        return 0;
    }

    printf("%s\n",eMessage);
    return -1;
}

int bajaPersona(ePersona lista[],int tam)
{

    int coincidencia,dni;

    printf("Ingresar DNI del usuario a borrar\n");
    fflush(stdin);
    scanf("%d",&dni);

    coincidencia = buscarPorDni(lista,dni,tam);

    if (coincidencia != -1)
    {
        lista[coincidencia].estado =-1;
        return 0;
    }

    printf("El usuario no existe\n");
    return -1;
}

void ordenarUsuarios (ePersona lista[],int tam)
{
    int i,j;
    char aux[50];
    printf("LISTA DE USUARIOS\n");
    fflush(stdin);

    for (i=0; i<tam-1; i++)
        for (j=i+1; j<tam; j++)
            if (strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                strcpy(aux,lista[i].nombre);
                strcpy(lista[i].nombre,lista[j].nombre);
                strcpy(lista[j].nombre,aux);
            }



    for(i=0; i<tam; i++)
        if (lista[i].estado != -1)
            printf("\t%s\n",lista[i].nombre);

}



void graficoDeEdades (int m18,int e19y35,int m35)
{
    char grafico[3][21];
    int i,j,maximo=0;


    if (m18 >= e19y35 && m18 >= m35)
    {
        maximo = m18;
    }
    else
    {
        if(e19y35 >= m35)
        {
            maximo=e19y35;

        }
        else
        {
            maximo=m35;
        }

    }

        for (j=0; j<20; j++)
        {
            grafico[0][j]=' ';
            grafico[1][j]=' ';
            grafico[2][j]=' ';
        }

        for (i=0; i<m18; i++)
        {
            grafico[0][i]='*';
        }
        for (i=0; i<e19y35; i++)
        {
            grafico[1][i]='*';
        }
        for (i=0; i<m35; i++)
        {
            grafico[2][i]='*';
        }

        for(j=maximo; j>=0; j--)
        {
            printf("%c    ",grafico[0][j]);
            printf("%c    ",grafico[1][j]);
            printf("%c  \n",grafico[2][j]);
        }


        printf("<18 19-35 >35\n");
}
