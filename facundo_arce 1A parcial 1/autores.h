#ifndef autores_H_INCLUDE
#define autores_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int codigoDeAutor;
    char nombre[31];
    char apellido[31];
    int ocupado;

}eAutores;
/** \brief Toma una estructura autores y las muestra
 * \param array de estrucutura y tamaño
 */
void mostrarAutor(eAutores vec);
void mostrarAutores(eAutores vec[], int tam);

#endif // autores_H_INCLUDE


