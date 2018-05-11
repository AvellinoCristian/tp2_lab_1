#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 10

int main()
{
    char seguir='s';
    int opcion=0,m18=0,e18y35=0,m35=0;
    ePersona persona[TAM];

inicializarEstado(persona,TAM);


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

               if (!altaPersona(persona,TAM,&m18,&e18y35,&m35))
               {
                printf("\t\nAlta exitosa!\n\n");
                system("pause");
               }
               else
               {
                printf("\t\nAlta Cancelada!\n\n");
                system("pause");
               }
                break;
            case 2:

                if ( bajaPersona(persona,TAM) != -1)
                    {
                printf("\t\nBaja exitosa!\n\n");
                system("pause");
               }
               else
               {
                printf("\t\nBaja Cancelada!\n\n");
                system("pause");
               }

                break;
            case 3:

                ordenarUsuarios(persona,TAM);
                system("pause");

                break;
            case 4:


                graficoDeEdades(m18,e18y35,m35);
                system("pause");

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
