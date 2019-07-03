#include "autores.h"

void mostrarAutores(eAutores vec[], int tam)
{
    int cont= 0;
    printf("\n  *** Lista de Autores ***");
    printf("\n\n Codigo autor   Nombre       Apellido \n\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarAutor(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay autores que mostrar\n\n");
    }
}

void mostrarAutor(eAutores vec){

    printf("  %d    %9s    %9s \n", vec.codigoDeAutor, vec.nombre, vec.apellido);
}
