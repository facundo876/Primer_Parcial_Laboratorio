#include "prestamos.h"
#include "funcionesUTN.h"
#include "libros.h"
#include "socios.h"

void altaPrestamos(ePrestamos vec[], int tam, eLibros vecLibros[],int tamLibros, eSocios vecSocio[], int tamSocio){

    int indice;
    int CodigoLibro;
    int existeLibro;
    int flag;
    int codigoSocio;
    int existeS;

    indice = prestamoLibre(vec, tam);

    system("cls");
    printf("\n   *** Registro de Prestamos ***\n");//Titulo
    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

            //Codigo de prestamo
            vec[indice].codigoDePrestamo=indice+1;

            //Libro
            printf("\nIngresar Codigo de libro : ");//codigo Libro

            do{
            IngresarCodigo(&CodigoLibro);
                flag=0;
                existeLibro = buscarLibro(vecLibros, tamLibros, CodigoLibro);//busca si existe un libro con ese codigo
                if(existeLibro == -1)
                {
                    printf("\nError! El libro no existe. \nIngrese codigo de libro : ");
                    flag=1;
                }
            }while(flag != 0);
            vec[indice].codigoDeLibro = CodigoLibro;
            //Fin Libro

            //Socio
             printf("Ingresar Codigo de Socio : ");//codigo socio

            do{
            IngresarCodigo(&codigoSocio);
                flag=0;
                existeS = existeSocio(vecSocio, tamSocio, codigoSocio);
                if(existeS == -1)
                {
                    printf("\nError! El socio no existe. \nIngrese codigo de socio : ");
                    flag=1;
                }
            }while(flag != 0);
            vec[indice].codigoDeSocio = codigoSocio;
            //Fin Socio

            //Fecha de Prestamo
            printf("Ingresar Fecha de Pestamo : ");//codigo socio
                fechaDePrestamo(vec, indice);
            //Fin fecha de Prestamo

            //Ocupado
            vec[indice].ocupado = 1;

            printf("\n\nRegistrado con Existo !\n");

    }

}

int buscarPrestamo(ePrestamos vec[], int tam, int codigo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].codigoDePrestamo == codigo && (vec[i].ocupado == 1 || vec[i].ocupado == 0))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int prestamoLibre(ePrestamos vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPrestamos(ePrestamos vec[], int tam)
{
    int cont= 0;

    printf("\n\n Codigo Prestamo  codigo libro        codigo socio \n\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarPrestamo(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay Prestamos que mostrar\n\n");
    }
}

void mostrarPrestamo(ePrestamos vec){

        printf(" %03d   %10d  %10d   %10d/%d/%d \n", vec.codigoDePrestamo, vec.codigoDeLibro, vec.codigoDeSocio, vec.fechaDePrestamo.dia, vec.fechaDePrestamo.mes, vec.fechaDePrestamo.anio);
}

int buscarLibro(eLibros vec[], int tam, int codigoDeLibro){

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].codigoDeLibro == codigoDeLibro)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

int existeSocio(eSocios vec[], int tam, int codigoDeSocio){

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].codigoDeSocio == codigoDeSocio && vec[i].ocupado != 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void fechaDePrestamo(ePrestamos vec[], int indice){

    int flag;
    printf("\nDia : ");
            do{
                flag = 0;
                scanf("%d", &vec[indice].fechaDePrestamo.dia);
                if(vec[indice].fechaDePrestamo.dia < 1 || vec[indice].fechaDePrestamo.dia > 31){
                    printf("\n Error! Ingrese Dia : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nMes : ");
            do{
                flag = 0;
                scanf("%d", &vec[indice].fechaDePrestamo.mes);
                if(vec[indice].fechaDePrestamo.mes < 1 || vec[indice].fechaDePrestamo.mes > 12){
                    printf("\n Error! Ingrese Mes : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nAnio : ");
            do{
                flag = 0;
                scanf("%d", &vec[indice].fechaDePrestamo.anio);
                if(vec[indice].fechaDePrestamo.anio < 1920 || vec[indice].fechaDePrestamo.anio > 2100){
                    printf("\n Error! Ingrese Año : ");
                    flag = 1 ;
                }
            }while(flag != 0);
}

void IngresarCodigo(int *codigo){
    char numero[10];
    int flag;

        do{
            fflush(stdin);
                flag=0;
            if( esNumerico(gets(numero)) != 1){
                printf("\n Error! Ingrese nuevamente : ");
                flag=1;
            }
        }while(flag != 0);

    *codigo = atoi(numero);

}

int menuListas(){

    int opcion;
    system("cls");// limpia el menu

    printf("\n  *** Informes ***\n\n");// Titulo
    printf("1- A)Total general y promedio diarion\n");
    printf("2- B)cantidad de Dias que no pasaron el promedio\n");
    printf("3- C)Libros por socios\n");
    printf("4- D)Socios por Libros\n");
    printf("5- E)Libros menos solicitados\n");
    printf("6- F)Socios con mas Solicitudes\n");
    printf("7- G)Libros por Fecha Determinada\n");
    printf("8- H)Prestamos por Fecha Determinada\n");
    printf("9- I)Lista Titulos por Burbujeo mas eficiente\n");
    printf("10- J)Listar Socios por Metodo insercion\n");
    printf("11- Atras\n");
    printf("\n\nIngresar Opcion : ");
    scanf("%d", &opcion);

    return opcion;
}

void informarListas(ePrestamos vec[], int tam, eLibros vecLibros[], int tamLibros, eSocios vecSocios[], int tamSocios){
    int atras=0;
     do{
            switch(menuListas()){

                case 1://total
                    totalGeneral(vec, tam);
                    system("pause");
                    break;
                case 2:
                    diasNoPasaronPromdeio(vec, tam);
                    system("pause");
                    break;
                case 3:
                    librosXsocios(vec, tam, vecLibros, tamLibros, vecSocios, tamSocios);
                    system("pause");
                    break;
                case 4:
                    sociosXlibros(vec, tam, vecLibros, tamLibros, vecSocios, tamSocios);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    printf("\n  ***Lista de libros menos solicitados***\n\n");
                    librosMenosSolicitados(vec, tam, vecLibros, tamLibros);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    printf("\n  ***Lista de socios con mas solicitudes***\n\n");
                    sociosMasSolicitudes(vecSocios, tamSocios, vec, tam);
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    printf("\n  ***Libros por Fecha Determinada***\n\n");
                    librosXfecha(vec, tam);
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    printf("\n  ***Prestamos por Fecha Determinada***\n\n");
                    prestamosXfecha(vec, tam, vecSocios, tamSocios);
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    burbujeMasEficiente(vecLibros, tamLibros);
                    mostrarLibros(vecLibros, tamLibros);
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    printf("\n  ***Listar por Apellido (ascendente)***\n");
                    metodoDeInsecion(vecSocios, tamSocios);
                    mostrarSocios(vecSocios, tamSocios);
                    system("pause");
                    break;
                case 11:
                    atras=1;
                    break;

                default:
                    printf("\n Opcion invalida\n\n");
                    system("pause");
                    break;
            }
        }while(atras == 0);

}

void totalGeneral(ePrestamos vec[], int tam){
    int total=0;
    int promedioDiario;
    int totalDias=0;
    int flag =0;

    system("cls");

    for(int i=0; i<tam; i++){

        if(vec[i].ocupado == 1){
            total++;

        }
    }

    for(int i=0; i<tam; i++){

        int primerDia;

        if(flag == 0){
            flag =1;
            primerDia = vec[i].fechaDePrestamo.dia;
        }

        if(primerDia == vec[i].fechaDePrestamo.dia ){

        }
        else{
            if(vec[i].ocupado == 1){

             primerDia = vec[i].fechaDePrestamo.dia;
            totalDias++;
            }
        }

    }
    promedioDiario = total/totalDias;




    printf("Total general : %d \n", total);
    //printf("cantidad de dias %d\n", totalDias);
    printf("Promedio Diario : %d \n", promedioDiario);

}

void librosXsocios(ePrestamos vecPrestamo[], int tamPrestamo, eLibros vecLibros[], int tamLibros, eSocios vecSocios[], int tamSocios){
    system("cls");
    printf("\n  *** Libros por socios ***\n\n");

    for(int i=0; i<tamLibros; i++)
    {
        if(vecLibros[i].ocupado == 1)
        {
            printf("\n");
            printf(" %s :", vecLibros[i].TituloLibro);
            printf("\n");

            for(int j=0; j<tamPrestamo; j++)
            {
                if(vecPrestamo[j].codigoDeLibro == vecLibros[i].codigoDeLibro)
                {
                    for(int k=0; k<tamSocios; k++)
                    {
                        if(vecSocios[k].codigoDeSocio == vecPrestamo[j].codigoDeSocio)
                        {
                            mostrarSocio(vecSocios[k]);
                        }

                    }

                }

            }
        }

    }
}
void diasNoPasaronPromdeio(ePrestamos vec[], int tamPrestamo)
{
    int total=0;
    int promedioDiario;
    int totalDias=0;
    int flag =0;
    int primerDia;
    int contador1=0;
    int dia1 = 0;
    int contDias=0;


    system("cls");

    for(int i=0; i<tamPrestamo; i++){

        if(vec[i].ocupado == 1){
            total++;

        }
    }

    for(int i=0; i<tamPrestamo; i++)
    {
        if(flag == 0){
            flag =1;
            primerDia = vec[i].fechaDePrestamo.dia;
        }

        if(primerDia != vec[i].fechaDePrestamo.dia )
        {
            if(vec[i].ocupado == 1)
            {
                primerDia = vec[i].fechaDePrestamo.dia;
                totalDias++;

            }
        }

    }
    promedioDiario = total/totalDias;
    printf("\n PROMEDIO DIARIO: %d\n", promedioDiario);

    //NO superaron

    printf("\n DIAS QUE NO SUPERARON EL PROMEDIO DIARIO:\n\n");
    for(int i=0; i<tamPrestamo; i++){

       if(vec[i].fechaDePrestamo.dia !=0 && vec[i].fechaDePrestamo.dia != dia1){

            dia1 = vec[i].fechaDePrestamo.dia;
            //printf("dia %d", vec[i].fechaDePrestamo.dia);
            for(int j=0; j<tamPrestamo; j++){

                if(dia1 == vec[j].fechaDePrestamo.dia){
                contador1++;
                }
            }
            if(contador1 < promedioDiario){
                printf(" *Dia %d/%d/%d no paso el promedio diario\n", dia1, vec[i].fechaDePrestamo.mes, vec[i].fechaDePrestamo.anio);
                contDias++;
            }
            contador1=0;
       }
    }

    printf("\n\n CANTIDAD DE DIAS QUE NO SUPERARON EL PROMEDIO: %d\n\n", contDias);

}
void sociosXlibros(ePrestamos vecPrestamo[], int tamPrestamo, eLibros vecLibros[], int tamLibros, eSocios vecSocios[], int tamSocios){
    int legajo;
    int esta;


    printf("\nIngrese legajo: ");
    //scanf("%d", &legajo);
    IngresarCodigo(&legajo);

    esta = buscarSocio( vecSocios, tamSocios, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
            system("cls");
            printf("\n");
            mostrarSocio(vecSocios[esta]);
            printf("\n");
            printf("  Titulo | cod de Prestamo | cod de Libro | dia/mes/anio\n\n");
            for(int i=0; i<tamPrestamo; i++){

                if(vecPrestamo[i].codigoDeSocio == legajo && vecPrestamo[i].ocupado==1){

                    //printf("%d\n", vecPrestamo[i].codigoDeLibro);

                    for(int j=0; j<tamLibros; j++){

                        if(vecPrestamo[i].codigoDeLibro == vecLibros[j].codigoDeLibro && vecLibros[j].ocupado==1){
                            printf("  %s :   %d   %d   %d/%d/%d\n\n",vecLibros[j].TituloLibro,vecPrestamo[j].codigoDePrestamo, vecPrestamo[j].codigoDeLibro, vecPrestamo[j].fechaDePrestamo.dia, vecPrestamo[j].fechaDePrestamo.mes, vecPrestamo[j].fechaDePrestamo.anio);

                        }
                    }
                }
            }
    }
}

void burbujeMasEficiente (eLibros libros[],int tamLibros)
{
     eLibros aux;
     int flagNoEstaOrdenado = 1;
     while (flagNoEstaOrdenado==1)
     {
         flagNoEstaOrdenado = 0;

         for (int j = 1; j < tamLibros; j++)
         {
             if ((strcmp(libros[j].TituloLibro, libros[j - 1].TituloLibro))>0)
             {
                 aux = libros[j];
                 libros[j] = libros[j - 1];
                 libros[j - 1] = aux;
                 flagNoEstaOrdenado = 1;
             }
         }
     }
}

void metodoDeInsecion(eSocios vecSocio[],int tamSocio)
{
     int j;
     eSocios temp;

     for(int i=1;i<tamSocio;i++)
     {
        temp = vecSocio[i];
        j=i-1;

        while(((strcmp(vecSocio[i].apellido,vecSocio[j].apellido))<0) && j>=0) // temp<vecSocio[j] o temp>vecSocio[j]
        {
             vecSocio[j+1] = vecSocio[j];
             j--;
        }
        vecSocio[j+1]=temp; // inserción
     }
}

void librosMenosSolicitados(ePrestamos vecPrestamos[], int tamPrestamos, eLibros vecLibros[], int tamLibros){

int contador=0;
    for(int i=0; i<tamLibros; i++){
        if(vecLibros[i].ocupado == 1)
        {
            contador=0;
            for(int j=0; j<tamPrestamos; j++)
            if(vecLibros[i].codigoDeLibro == vecPrestamos[j].codigoDeLibro)
            {
               contador++;
            }
            //printf("  Libro: %20s : Cant de Solcitudes : %d\n", vecLibros[i].TituloLibro,contador);
            //ordenar

            vecLibros[i].cantPrestamos = contador;
        }
    }
    ordenarLibros(vecLibros, tamLibros);
    for(int i=0; i<tamLibros; i++){
        if(vecLibros[i].ocupado==1){
           printf("  Libro: %20s : Cant de Solcitudes : %d\n", vecLibros[i].TituloLibro,vecLibros[i].cantPrestamos);
        }
    }
}
void ordenarLibros (eLibros libros[],int tamLibros)
{
     eLibros aux;
     int flagNoEstaOrdenado = 1;
     while (flagNoEstaOrdenado==1)
     {
         flagNoEstaOrdenado = 0;

         for (int j = 1; j < tamLibros; j++)
         {
             if (libros[j].cantPrestamos < libros[j - 1].cantPrestamos)
             {
                 aux = libros[j];
                 libros[j] = libros[j - 1];
                 libros[j - 1] = aux;
                 flagNoEstaOrdenado = 1;
             }
         }
     }
}

void sociosMasSolicitudes(eSocios vecSocios[], int tamSocios, ePrestamos vecPrestamos[], int tamPrestamos){

    int contador=0;
    for(int i=0; i<tamSocios; i++){
        if(vecSocios[i].ocupado == 1)
        {
            contador=0;
            for(int j=0; j<tamPrestamos; j++)
            if(vecSocios[i].codigoDeSocio == vecPrestamos[j].codigoDeSocio)
            {
               contador++;
            }
            //ordenar
            vecSocios[i].cantPrestamos = contador;
            //printf("  Socio: %d : Cant de Solcitudes : %d\n", vecSocios[i].codigoDeSocio,vecSocios[i].cantPrestamos);

        }
    }
    ordenarSocios(vecSocios, tamSocios);
    for(int i=0; i<tamSocios; i++){
        if(vecSocios[i].ocupado==1){
           printf("  Socio: %d : Cant de Solcitudes : %d\n", vecSocios[i].codigoDeSocio,vecSocios[i].cantPrestamos);
        }
    }
}

void ordenarSocios(eSocios socios[],int tamSocios)
{
     eSocios aux;
     int flagNoEstaOrdenado = 1;
     while (flagNoEstaOrdenado==1)
     {
         flagNoEstaOrdenado = 0;

         for (int j = 1; j < tamSocios; j++)
         {
             if (socios[j].cantPrestamos > socios[j - 1].cantPrestamos)
             {
                 aux = socios[j];
                 socios[j] = socios[j - 1];
                 socios[j - 1] = aux;
                 flagNoEstaOrdenado = 1;
             }
         }
     }
}

void librosXfecha(ePrestamos vecPrestamos[], int tamPrestamos){
    int dia;
    int mes;
    int anio;
    int flag=0;
    printf("Ingresar Fecha\n\nIngresar Dia: ");
   /*     scanf("%d", &dia);
    printf("Ingresar Mes: ");
        scanf("%d", &mes);
    printf("Ingresar Anio: ");
    fflush(stdin);
        scanf("%d", &anio);*/

            printf("\nDia : ");
            do{
                flag = 0;
                scanf("%d", &dia);
                if(dia < 1 || dia > 31){
                    printf("\n Error! Ingrese Dia : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nMes : ");
            do{
                flag = 0;
                scanf("%d", &mes);
                if(mes < 1 || mes > 12){
                    printf("\n Error! Ingrese Mes : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nAnio : ");
            do{
                flag = 0;
                scanf("%d", &anio);
                if(anio < 1920 || anio > 2100){
                    printf("\n Error! Ingrese Año : ");
                    flag = 1 ;
                }
            }while(flag != 0);

    printf("\nCodPrestamo - CodLibro - CodSocio - Fecha de Prestamo\n");

    for(int i=0; i<tamPrestamos; i++){

        if(vecPrestamos[i].fechaDePrestamo.dia == dia && vecPrestamos[i].fechaDePrestamo.mes == mes && vecPrestamos[i].fechaDePrestamo.anio == anio){

            mostrarPrestamo(vecPrestamos[i]);
            flag=1;
        }

    }
    if(flag==0){
        printf("\n    No hay registros para esa facha\n\n");
    }
}

void prestamosXfecha(ePrestamos vecPrestamos[], int tamPrestamos, eSocios vecSocios[], int tamSocios){

    int dia;
    int mes;
    int anio;
    int flag=0;
    printf("Ingresar Fecha\n");
            printf("\nDia : ");
            do{
                flag = 0;
                scanf("%d", &dia);
                if(dia < 1 || dia > 31){
                    printf("\n Error! Ingrese Dia : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nMes : ");
            do{
                flag = 0;
                scanf("%d", &mes);
                if(mes < 1 || mes > 12){
                    printf("\n Error! Ingrese Mes : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nAnio : ");
            do{
                flag = 0;
                scanf("%d", &anio);
                if(anio < 1920 || anio > 2100){
                    printf("\n Error! Ingrese Año : ");
                    flag = 1 ;
                }
            }while(flag != 0);

    printf("\nCodSocio - Nombre - Apellido - Sexo - Telefono - Email - Estado - FechaNaci.\n\n");

    for(int i=0; i<tamPrestamos; i++){

        if(vecPrestamos[i].fechaDePrestamo.dia == dia && vecPrestamos[i].fechaDePrestamo.mes == mes && vecPrestamos[i].fechaDePrestamo.anio == anio){
            for(int j=0; j<tamSocios; j++){
                if(vecPrestamos[i].codigoDeSocio == vecSocios[j].codigoDeSocio){
                    mostrarSocio(vecSocios[j]);
                    flag=1;
                }
            }

        }

    }
    if(flag==0){
        printf("    No hay registros para esa facha\n");
    }
printf("\n");
}

