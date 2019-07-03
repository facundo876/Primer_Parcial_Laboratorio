
#ifndef libros_H_INCLUDE
#define libros_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int codigoDeLibro;
    char TituloLibro[51];
    int codigoDeAutor;
    int ocupado;
    int cantPrestamos;

}eLibros;
/** \brief Toma una estructura libros y las muestra
 * \param array de estrucutura y tamaño
 */
void mostrarLibro(eLibros vec);
void mostrarLibros(eLibros vec[], int tam);

//Listas


#endif // libros_H_INCLUDE
