#include "libros.h"

void mostrarLibros(eLibros vec[], int tam)
{
    int cont= 0;
    printf("\n  *** Lista de Libros ***");
    printf("\n\n Codigo Libro   Titulo        codigo Autor \n\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarLibro(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay Libros que mostrar\n\n");
    }
}

void mostrarLibro(eLibros vec){

    printf("  %d         %s      %04d  \n", vec.codigoDeAutor, vec.TituloLibro, vec.codigoDeAutor);
}


