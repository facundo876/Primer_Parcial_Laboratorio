#include "socios.h"
#include "funcionesUTN.h"
#include "prestamos.h"

void altaSocios(eSocios vec[], int tam){
    int indice;
    int legajo;
    int esta;
    int flag;
    char telefono[31];
    char email[31];

    system("cls");
    printf("\n  *** Alta Socio ***\n\n");
    indice = buscarLibre(vec, tam);
    if(indice == -1)
    {
        printf("\nNo hay lugar\n\n");
    }
    else
    {
        //Codigo
        printf("Ingresar codigo de Socio (Ej:1234) : ");
        //scanf("%d", &legajo);
        IngresarCodigo(&legajo);

        esta = buscarSocio(vec, tam, legajo);

    if(esta == -1){
        vec[indice].codigoDeSocio = legajo;

        //nombre;
        printf("Ingresar Nombre : ");
        do{
                    flag=0;
                    fflush(stdin);
                if( esSoloLetras(gets(vec[indice].nombre)) != 1){
                    printf("\n Error! Ingrese nombre : ");
                    flag=1;
                }
            }while(flag != 0);
            vec[indice].nombre[0] = toupper(vec[indice].nombre[0]);

         //apellido
         printf("Ingresar Apellido : ");
            do{
                    flag=0;
                    fflush(stdin);
                if( esSoloLetras(gets(vec[indice].apellido)) != 1){
                    printf("\n Error! Ingrese apellido : ");
                    flag=1;
                }
            }while(flag != 0);
            vec[indice].apellido[0] = toupper(vec[indice].apellido[0]);
           //sexo
           printf("Ingrese sexo: ");
            fflush(stdin);
            //verificar
            do{
                flag=0;
                scanf("%c", &vec[indice].sexo);

                if( esGenero(vec[indice].sexo) != 1){
                    fflush(stdin);
                    printf("\n Error! Ingrese sexo : ");
                    flag=1;
                }

            }while(flag != 0);

            vec[indice].sexo = tolower(vec[indice].sexo);
            //Fin sexo
            //telefono
           printf("Ingrese Telefono (Ej:123-456): ");
            fflush(stdin);
            //verificar
            do{
                flag=0;
                gets(telefono);
                if( esTelefono(telefono) != 1){
                    fflush(stdin);
                    printf("\n Error! Ingrese telefono : ");
                    flag=1;
                }

            }while(flag != 0);
            strcpy(vec[indice].telefono, telefono);

            printf("Ingresar Email : ");
            fflush(stdin);
            gets(email);
            //verificar
            /*do{
                flag=0;
                gets(email);
                if( esTelefono(email) != 1){
                    fflush(stdin);
                    printf("\n Error! Ingrese email : ");
                    flag=1;
                }

            }while(flag != 0);*/
            strcpy(vec[indice].email, email);
            //Ocupado
            vec[indice].ocupado = 1;

            //fecha de Asociados
            printf("Ingresar Fecha de nacimiento: ");

            printf("\nDia : ");
            do{
                flag = 0;
                scanf("%d", &vec[indice].fechaAsociado.dia);
                if(vec[indice].fechaAsociado.dia < 1 || vec[indice].fechaAsociado.dia > 31){
                    printf("\n Error! Ingrese Dia : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nMes : ");
            do{
                flag = 0;
                scanf("%d", &vec[indice].fechaAsociado.mes);
                if(vec[indice].fechaAsociado.mes < 1 || vec[indice].fechaAsociado.mes > 12){
                    printf("\n Error! Ingrese Mes : ");
                    flag = 1 ;
                }
            }while(flag != 0);

            printf("\nAnio : ");
            do{
                flag = 0;
                scanf("%d", &vec[indice].fechaAsociado.anio);
                if(vec[indice].fechaAsociado.anio < 1920 || vec[indice].fechaAsociado.anio > 2100){
                    printf("\n Error! Ingrese Año : ");
                    flag = 1 ;
                }
            }while(flag != 0);
            //Fin fecha de asosacion

            printf("\nEl Socio ha sido registrado con exito!!!\n\n");
         }//if esta
         else{
            printf("Ya existe un socio con el codigo %d\n", legajo);

            mostrarSocio(vec[esta]);
         }

         }
}


int buscarLibre(eSocios vec[], int tam)
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

int buscarSocio(eSocios vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].codigoDeSocio == legajo && (vec[i].ocupado == 1 || vec[i].ocupado == 0))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarSocios(eSocios vec[], int tam)
{
    int cont= 0;
    //ordenar
    //ordenarNombre(vec, tam);
    printf("\n\n Codigo  Nombre Apellido  sexo  telefono   email    Fecha Nac   \n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarSocio(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay Socios que mostrar\n\n");
    }
}

void mostrarSocio(eSocios emp)
{
            //codigo, nombre,apellido sexo, telefono,email, estado, fechaNaci.
    printf("  %04d   %7s  %7s  %c   %s  %s  %02d / %02d / %d \n", emp.codigoDeSocio, emp.nombre, emp.apellido, emp.sexo, emp.telefono, emp.email, emp.fechaAsociado.dia,emp.fechaAsociado.mes,emp.fechaAsociado.anio);

}

void modificarSocio(eSocios vec[], int tam){

    int legajo;
    int esta;
    int atras=0;

    printf("\nIngrese legajo: ");
    //scanf("%d", &legajo);
    IngresarCodigo(&legajo);

    esta = buscarSocio( vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
            printf("\n");
            mostrarSocio(vec[esta]);
            printf("\n");
        do{
            switch(menuModificar(vec, esta)){

                case 1:
                    modificarNombre(vec, esta);
                    system("pause");
                    break;
                case 2:
                    modificarApellido(vec, esta);
                    system("pause");
                    break;
                case 3:
                    modificarSexo(vec, esta);
                    system("pause");
                    break;
                case 4:
                    modificarTelefono(vec, esta);
                    system("pause");
                    break;
                case 5:
                    modificarEmail(vec, esta);
                    system("pause");
                    break;
                case 6:
                    atras=1;
                    break;

                default:
                    printf("\n Opcion invalida\n\n");
                    system("pause");
                    break;
            }
        }while(atras == 0);

    }

}

int menuModificar(eSocios vec[], int indice){

    int opcion;
    system("cls");// limpia el menu

    printf("\n Codigo  Nombre  Apellido  sexo  telefono   email    Fecha asociado   \n");

    mostrarSocio(vec[indice]);

    printf("\n  *** Modificar ***\n\n");// Titulo
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar Sexo\n");
    printf("4- Modificar Telefo\n");
    printf("5- Modificar Email\n");
    printf("6- Atras\n");
    printf("\n\nIngresar Opcion : ");
    scanf("%d", &opcion);

    return opcion;
}

void modificarNombre(eSocios vec[], int indice){
        char confirma;
        char nuevoNombre [31];
        int flag;

        printf("\nQuiere cambiar el nombre? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo nombre: ");

            do{
                     flag=0;
                if( esSoloLetras(gets(nuevoNombre)) != 1){
                    printf("\n Error! Ingrese nombre : ");
                    flag=1;
                }
            }while(flag != 0);
            nuevoNombre[0]=toupper(nuevoNombre[0]);// faucndo = Facundo;

            //valido nombre
            strcpy(vec[indice].nombre, nuevoNombre);

            printf("\nNombre ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el nombre\n");
        }
}

void modificarApellido(eSocios vec[], int indice){
        char confirma;
        char nuevoApellido [31];
        int flag;

        printf("\nQuiere cambiar el Apellido? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo Apellido: ");

            do{
                     flag=0;
                if( esSoloLetras(gets(nuevoApellido)) != 1){
                    printf("\n Error! Ingrese Apellido : ");
                    flag=1;
                }
            }while(flag != 0);
            nuevoApellido[0]=toupper(nuevoApellido[0]);// faucndo = Facundo;

            //valido Apellido
            strcpy(vec[indice].apellido, nuevoApellido);

            printf("\nApellido ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el Apellido\n");
        }
}

void modificarSexo(eSocios vec[], int indice){
        char confirma;
        char nuevoSexo;
        int flag;

        printf("\nQuiere cambiar el Sexo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sexo: ");
            //scanf("%c", &nuevoSexo);
            //valido nombre
            do{
                flag=0;
                scanf("%c", &nuevoSexo);

                if( esGenero(nuevoSexo) != 1){
                    fflush(stdin);
                    printf("\n Error! Ingrese sexo : ");
                    flag=1;
                }
            }while(flag != 0);

            vec[indice].sexo = nuevoSexo;

            printf("\nSexo ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el sexo\n");
        }
}

void modificarTelefono(eSocios vec[], int indice){
        char confirma;
        char nuevoTelefono[31];
        int flag;

        printf("\nQuiere cambiar el Telefono? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo Telefono: ");

            do{
                     flag=0;
                if( esTelefono(gets(nuevoTelefono)) != 1){
                    printf("\n Error! Ingrese Telefono : ");
                    flag=1;
                }
            }while(flag != 0);
            nuevoTelefono[0]=toupper(nuevoTelefono[0]);// faucndo = Facundo;

            //valido Telefono
            strcpy(vec[indice].telefono, nuevoTelefono);

            printf("\nTelefono ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el Telefono\n");
        }
}

void modificarEmail(eSocios vec[], int indice){
        char confirma;
        char nuevoEmail[31];
        int flag;

        printf("\nQuiere cambiar el Email? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo Email: ");

            do{
                     flag=0;
                if( esEmail(gets(nuevoEmail)) != 1){
                    printf("\n Error! Ingrese Email : ");
                    flag=1;
                }
            }while(flag != 0);
            nuevoEmail[0]=toupper(nuevoEmail[0]);// faucndo = Facundo;

            //valido Email
            strcpy(vec[indice].email, nuevoEmail);

            printf("\nEmail ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el Email\n");
        }
}

void bajaSocio(eSocios vec[], int tam){

    int legajo;
    char confirma;
    int esta;
    printf("\n  *** Baja Socio ***\n\n");
    printf("Ingrese Codigo de socio: ");
    scanf("%d", &legajo);

    esta = buscarSocio(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarSocio(vec[esta]);

        printf("\nConfirma la eliminacion? s/n : ");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            vec[esta].ocupado = 0;
            printf("\n\nEl socio fue Eliminado");
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }
printf("\n\n");
}

void ordenarNombre(eSocios emp[], int tam)
{

    eSocios aux;//Auxiliar

     for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if((strcmp(emp[i].apellido, emp[j].apellido)) > 0)
            {// si strcmp devuelve menor a cero entra

                        aux=emp[i];
                        emp[i]=emp[j];         //la emp[j] pasa a ser la primera
                        emp[j]=aux;

            }//if
             else if ((strcmp(emp[i].apellido, emp[j].apellido)) == 0)
             {//En caso de que los apellidos sean iguales se ordena por en nombre

                    if( (strcmp(emp[i].apellido, emp[j].apellido)) > 0 )
                    {
                        aux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=aux;
                    }
             }
        }
    }
}

// menu
int menuPrincipal()
{
    int opcion;

    system("cls");// limpia el menu
    printf("  *** Menu Socios ***\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- listar\n");
    printf("5- Listar Autores\n");
    printf("6- Listar Libros\n");
    printf("7- Alta Prestamos\n");
    printf("8- Listar Prestamos\n");
    printf("9- Listar informar\n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void subMenu(){

    int atras = 0;
    do{
        switch(atras){

            case 1:
                //printf("\nOpcion Uno\n\n");
                system("pause");
                break;
            case 2:
                printf("\nOpcion Dos\n\n");
                system("pause");
                break;
            case 3:
                printf("\nOpcion Tres\n\n");
                system("pause");
                break;
            case 4:
                printf("\nOpcion Cuatro\n\n");
                system("pause");
                break;
            case 5:
                //printf("\nAtras\n\n");
                atras = 1;
                break;
        }
    }while(atras == 0);
}

