#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    //ESTRUCTURAS
    struct estruct_estados{               //Estructura para almacenar estados
        char nombre;                      // ..nombre
        char acept;                       // ..si es de aceptación
        int destinoA;                     // ..a dónde dirige con a
        int destinoB;                     // ..a dónde dirige con b
        };

    //VARIABLES
    int CantEstados,i=1,m;                //cantidad de estados y contadores 1 i,2 m
    struct estruct_estados estados[5];    //array para guardar los 5 estados
    char CadIng[21],EdoTemp;              //cadena ingresada y letra estado(aux)
    int EdoActual;                        //número estado(aux)

    //Introduccion y ingreso de cantidad de estados
    printf("   Bienvenido al AFD didactico v1.0\n\n");
    printf("Indique la cantidad de estados que tiene su automata (máx 5): ");
    scanf(" %d",&CantEstados);
    printf("Usted ingreso %d como la cantidad de estados\n",CantEstados);

    //Ingreso de estados (nombre, aceptación)
    printf("\nLlene los siguientes datos para cada estado\n");
    for(;i<=CantEstados;i++) {
        printf("Ingrese el identificador del estado numero %d:",i);
        scanf(" %c",&estados[i-1].nombre);                  //ingresa NOMBRE
        printf("¿El estado %c es de aceptacion?(s/n)",estados[i-1].nombre);
        scanf(" %c",&estados[i-1].acept);                   //ingresa ¿ACEPTACION?
    }

    //completar de estados (a donde redirijen los simbolos)
    printf("\nComplete los siguientes datos para cada estado\n");
    for(i=0;i<CantEstados;i++) {
        //redirección con 'a'...
        printf("¿A que otro estado lleva el estado %c con el simbolo 'a'?",estados[i].nombre);
        scanf(" %c",&EdoTemp);                              //carga estado..
        for(m=0;m<CantEstados;m++)
            if(EdoTemp==estados[m].nombre)                  //..lo busca..
                estados[i].destinoA=m;                      //..y a lo redirige
        //redirección con 'b'...
        printf("¿A que otro estado lleva el estado %c con el simbolo 'b'?",estados[i].nombre);
        scanf(" %c",&EdoTemp);                              //carga estado..
        for(m=0;m<CantEstados;m++)
            if(EdoTemp==estados[m].nombre)                  //..lo busca..
                estados[i].destinoB=m;                      //..y a lo redirige
    }

    //muestra el AFD
    printf("\nAUTOMATA AFD:\nEst| Nom acep? a b\n");
    for (i=0;i<CantEstados;++i)                             //recorre y muestra
        printf(" %d |  %c    %c   %d %d\n",i,estados[i].nombre,estados[i].acept,estados[i].destinoA,estados[i].destinoB);

    //Ingreso de la cadena
    printf("\nIngrese la cadena a evaluar (máx 20 caracteres, corte con enter, termine programa con *)\n");
    scanf("%s",CadIng);
    while (CadIng[0]!='*') {                                //salir prog con *

        //Recorre cadena
        i=EdoActual=0;                                      //reinicia i y est 1
        while(CadIng[i] != '\0') {                          //para cada símbolo..
            printf("Simbolo: %c   ",CadIng[i]);             //..mostrarlo..
            if(CadIng[i]=='a')                              //ir al estado apuntado
                EdoActual=estados[EdoActual].destinoA;
            else
                EdoActual=estados[EdoActual].destinoB;

            printf("Dirige a: %c\n",estados[EdoActual].nombre);//mostrar dónde se dirige
            i++;                                            //pasar al siguiente símbolo
            }

        //validar si el último estado es de aceptación
        if(estados[EdoActual].acept=='s')
            printf("\nLa cadena es aceptada\n");
        else
            printf("\nLa cadena es rechazada\n");

        //Ingresar otra cadena y continuar
        printf("\nIngrese la cadena a evaluar (máx 20 caracteres, corte con enter, termine programa con *)\n");
        scanf("%s",CadIng);
    }
}