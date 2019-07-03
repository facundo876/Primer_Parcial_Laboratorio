
#ifndef prestamos_H_INCLUDE
#define prestamos_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "socios.h"

#include "libros.h"
#include "socios.h"

typedef struct
{
    int codigoDePrestamo;
    int codigoDeLibro;
    int codigoDeSocio;
    eFecha fechaDePrestamo;
    int ocupado;
    int ventaDelDia;
    int codigo;


}ePrestamos;

void altaPrestamos(ePrestamos vec[], int tam, eLibros vecLibros[],int tamLibros, eSocios vecSocio[], int tamSocio);
//mostrar
void mostrarPrestamo(ePrestamos vec);
void mostrarPrestamos(ePrestamos vec[], int tam);
int prestamoLibre(ePrestamos vec[], int tam);
int buscarPrestamo(ePrestamos vec[], int tam, int codigo);
int buscarLibro(eLibros vec[], int tam, int codigoDeLibro);
int existeSocio(eSocios vec[], int tam, int codigoDeSocio);
void fechaDePrestamo(ePrestamos vec[], int indice);

//Ingreso de datos
/** \brief toma entero por puntero y lo cargar con esNumero
 * \return
 */
void IngresarCodigo(int *codigo);
//informes
void informarListas(ePrestamos vec[], int tam, eLibros vecLibros[], int tamLibros, eSocios vecSocios[], int tamSocios);
int menuListas();
void totalGeneral(ePrestamos vec[], int tam);
void librosXsocios(ePrestamos vec[], int tam, eLibros vecLibros[], int tamLibros, eSocios vecSocios[], int tamSocios);
void nombresPorInsercion(eSocios vec[],int tam);
void diasNoPasaronPromdeio(ePrestamos vec[], int tamPrestamo);
void sociosXlibros(ePrestamos vecPrestamo[], int tamPrestamo, eLibros vecLibros[], int tamLibros, eSocios vecSocios[], int tamSocios);
void burbujeMasEficiente (eLibros libros[],int tamLibros);
void metodoDeInsecion(eSocios vecSocio[],int tamSocio);
void librosMenosSolicitados(ePrestamos vecPrestamos[], int tamPrestamos, eLibros vecLibros[], int tamLibros);
void ordenarLibros (eLibros libros[],int tamLibros);
void sociosMasSolicitudes(eSocios vecSocios[], int tamSocios, ePrestamos vecPrestamos[], int tamPrestamos);
void ordenarSocios(eSocios socios[],int tamSocios);
void librosXfecha(ePrestamos vecPrestamos[], int tamPrestamos);
void prestamosXfecha(ePrestamos vecPrestamos[], int tamPrestamo, eSocios vecSocios[], int tamSocios);
#endif // prestamos_H_INCLUDE
