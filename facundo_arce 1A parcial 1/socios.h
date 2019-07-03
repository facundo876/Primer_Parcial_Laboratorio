
#ifndef employee_H_INCLUDE
#define employee_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoDeSocio;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char email[31];
    int ocupado;
    eFecha fechaAsociado;
    int cantPrestamos;

} eSocios;

//Main
int buscarLibre(eSocios vec[], int tam);
void altaSocios(eSocios socios[], int tam);
int buscarSocio(eSocios vec[], int tam, int legajo);
void mostrarSocios(eSocios vec[], int tam);
void mostrarSocio(eSocios emp);
void bajaSocio(eSocios vec[], int tam);
//Modificar
int menuModificar(eSocios vec[], int indice);
void modificarSocio(eSocios vec[], int tam);
void modificarNombre(eSocios vec[], int indice);
void modificarApellido(eSocios vec[], int indice);
void modificarSexo(eSocios vec[], int indice);
void modificarTelefono(eSocios vec[], int indice);
void modificarEmail(eSocios vec[], int indice);
//Ordenar
void ordenarNombre(eSocios emp[], int tam);
//Menu Principal
int menuPrincipal();
int menu2();
void subMenu();

#endif // employee_H_INCLUDE
