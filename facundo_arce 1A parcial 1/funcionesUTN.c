#include <stdio.h>
#include <string.h>

void metodoBurbujeo(char vector[]){
    int i, j, aux;
    //ordenar
    //printf("%d ", strlen(vector)-2);
    for(i=0; i<strlen(vector)-2; i++){// strlen(vector)-2 = n-2 cantidad de iteraciones
        for(j=i+1; j<strlen(vector)-1; j++){
            if(vector[i] > vector[j]){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
    //mosttrar
    for(i=0; i<strlen(vector)-1; i++){
        printf("%c ", vector[i]);
    }
}

int esSoloLetras(char cadena[]){
    int i=0;

    while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if((cadena[i]!=' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') ){
            return 0;
        }
      i++;
    }
    return 1;
}

int esNumerico(char cadena[]){
    int i=0;

    while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if(cadena[i] < '0' || cadena[i] > '9'){
            return 0;
        }
      i++;
    }
    return 1;
}

int esAlfanumerico(char cadena[]){
    int i=0;

    while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if((cadena[i]!=' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i]<'0' || cadena[i]>'9')){
            return 0;
        }
      i++;
    }
    return 1;
}

int esTelefono(char cadena[]){
    int i=0, contadorDeGuiones=0;

    while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if((cadena[i]!=' ') && (cadena[i]!='-') && (cadena[i]<'0' || cadena[i]>'9')){
            return 0;
        }
        if(cadena[i]=='-'){
            contadorDeGuiones++;
        }
      i++;
    }
    if (contadorDeGuiones==1){
        return 1;
    }
    return 0;
}

int numeroMayor(int vector[], int tam){

    int i, flag=0, mayor;

    for(i=0; i<tam; i++){

       if(flag==0 || vector[i]>mayor)
        mayor=vector[i];
        flag++;
    }
    //printf("Numero mayor : %d\n", mayor);
    return mayor;
}

int numeroMenor(int vector[], int tam){

    int i, flag=0, menor;

    for(i=0; i<tam; i++){

       if(flag==0 || vector[i]<menor)
        menor=vector[i];
        flag++;
    }
    //printf("\nNumero menor : %d\n", menor);
    return menor;
}

float promedioArray(int vector[], int tam){
    int i, promedio;

   for(i=0; i<tam; i++)
    promedio+=vector[i];

   //printf("\nEl promedio es : %d\n", promedio);
   return promedio/tam;

}

int esGenero(char genero){

    if(tolower(genero) == 'm' || tolower(genero) == 'f'){
        return 1;
    }

    return 0;
}

int esEmail(char cadena[]){
    int i=0, contadorDeArobas=0;

    /*while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if((cadena[i]!='@') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') ){
            return 0;
        }
        if(cadena[i]=='@'){
            contadorDeArobas++;
        }
      i++;
    }
    if (contadorDeArobas==1){
        return 1;
    }*/
    return 1;
}
