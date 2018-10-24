#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "builder.h"

int main()
{
    FILE *pArchivo;
    int cantidad,i;
    char aux[1000];
    char arrayRead[10][50];
    char header[100];
    char campo[100];
    char nombreFCampo[100];
    char tipoPuntero[100];
    //int longitud;
    /** pArchivo= fopen("estructura.c","w");
    if(pArchivo==NULL){
        printf("\nHubo un problema al abrir el archivo");
    }else{
        printf("\nTodo ok");
        //carga de variables
        strcpy(header,"cliente");
        strcpy(campo,"nombre");
        strcpy(nombreFCampo,campo);
        strcpy(tipoPuntero,header);
              //capital case para el tipo y nombre de funcion
        nombreFCampo[0]=toupper(nombreFCampo[0]);
        tipoPuntero[0]=toupper(tipoPuntero[0]);

        buil_malloc(header,tipoPuntero,pArchivo);
        buil_campoChar(header,nombreFCampo,campo,tipoPuntero,pArchivo);

    }
    fclose(pArchivo);
    */
    i=0;
    pArchivo=fopen("estructura.h","r+");
    if(pArchivo==NULL){
        printf("\nHubo un problema al abrir el archivo");
    }else{
        buil_buscarCamposYTipos(pArchivo,&cantidad,arrayRead);


    }

    fclose(pArchivo);
    return 0;
}

