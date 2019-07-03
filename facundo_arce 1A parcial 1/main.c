#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "socios.h"
#include "autores.h"
#include "libros.h"
#include "prestamos.h"
#include "listar.h"

#define TAM 20 //TAM_SOCIO
#define TAM_LIBROS 20
#define TAM_AUTORES 20
#define TAM_PRESTAMOS 20

int main()
{

    eAutores autores[TAM_AUTORES]={ {1001, "Facundo", "arce",1},
                                    {1002, "Juan", "arce",1},
                                    {1003, "Emilio", "arce",1},
                                    {1004, "Jose", "arce",1},
                                    {1005, "Ana", "arce",1}

                        };

    eLibros libros[TAM_LIBROS]={ {101, "Cuento de aventura", 1001,1},
                                 {102, "Cuento de terror", 1002,1},
                                 {103, "Novela Grafica", 1005,1},
                                 {104, "Matematias I", 1003,1},
                                 {105, "Novela Romantica", 1004,1},
                                 {106, "Aventuras de Piratas", 1006,1}
                            };

    eSocios socios[TAM]= {//codigo, nombre,apellido sexo, telefono,email, estado, fechaNaci.
                            {1234, "Juan","Arce", 'm', "444-444","juan@gamil.com", 1, {(18),(8),(1999)}},
                            {1333, "Ana","Aguirre", 'f', "555-555","ana@gamil.com", 1, {(15),(12),(1990)}},
                            {1200, "Jorge","Arce", 'm', "666-666","jorge@gamil.com", 1, {(2),(5),(1995)}},
                            {1214, "Hernan","Cortez", 'm', "429-444","hernan@gamil.com", 1, {(2),(8),(1991)}},
                            {1294, "Maria","Aquino", 'f', "434-434","maria@gamil.com", 1, {(25),(1),(2000)}},
                            {1284, "Soledad","Gonzalez", 'f', "345-424","Soledad@gamil.com", 1, {(11),(11),(1990)}},
                            {1274, "Nicolas","Barrera", 'm', "222-422","nicolas@gamil.com", 1, {(29),(11),(1998)}},
                            {1254, "Emilio","Gonzalez", 'm', "424-422","emilio@gamil.com", 1, {(20),(11),(1989)}},
                            {1255, "Camila","Gonzalez", 'f', "211-422","camila@gamil.com", 1, {(19),(1),(1988)}},
                            {1211, "Nicolas","Cortez", 'm', "222-422","nicolas98@gamil.com", 1, {(28),(9),(1998)}}

                          };
                        // codPrestamo codLibro CodSocio fechaDePRESTAMO
    ePrestamos prestamos [TAM_PRESTAMOS] ={ {1, 103, 1234, {(8),(8),(2018)},1},
                                            {2, 103, 1333, {(8),(8),(2018)},1},
                                            {3, 105, 1200, {(10),(8),(2018)},1},
                                            {4, 104, 1200, {(10),(8),(2018)},1},
                                            {5, 102, 1200, {(18),(8),(2018)},1},
                                            {6, 102, 1333, {(18),(8),(2018)},1},
                                            {7, 104, 1234, {(19),(8),(2018)},1},
                                            {8, 101, 1214, {(19),(8),(2018)},1},
                                            {9, 103, 1211, {(20),(8),(2019)},1},
                                            {10, 103, 1255, {(21),(8),(2018)},1},
                                            {11, 102, 1234, {(21),(8),(2018)},1},
                                            {12, 101, 1274, {(21),(8),(2018)},1}

                                };

    char seguir = 's';
    char confirma;

    do
    {
        switch(menuPrincipal())
        {

        case 1:
            altaSocios(socios,TAM);
            system("pause");
            break;

        case 2:
            modificarSocio(socios, TAM);
            system("pause");
            break;

        case 3:
            bajaSocio(socios, TAM);
            system("pause");
            break;

        case 4:
            ordenarNombre(socios, TAM);
            mostrarSocios(socios, TAM);
            system("pause");
            break;

        case 5:
            mostrarAutores(autores, TAM_AUTORES);
            system("pause");
            break;

        case 6:
            mostrarLibros(libros, TAM_LIBROS);
            system("pause");
            break;
        case 7:
            //printf("Prestamos");
            altaPrestamos(prestamos, TAM_PRESTAMOS, libros, TAM_LIBROS, socios, TAM);
            system("pause");
            break;
        case 8:
            //lisrtar prestamo
            mostrarPrestamos(prestamos, TAM_PRESTAMOS);
            system("pause");
            break;
        case 9:
            //lisrtar
            informarListas(prestamos, TAM_PRESTAMOS, libros, TAM_LIBROS, socios, TAM);
            system("pause");
            break;

        case 10:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();//getche detecta la primera leta ingresada

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

