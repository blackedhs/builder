#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cliente_new(){
    return (Cliente*) malloc(sizeof(Cliente));
}
void cliente_delete(Cliente* this){
    free(this);
}
int cliente_setNombre(Cliente* this,char* nombre){   
    int retorno=-1;
    if(this != NULL && cliente_isValidNombre(nombre)){
         strcpy(this->nombre,nombre);
         retorno=0;
     }
     return retorno;
}
int cliente_getNombre(Cliente* this,char* nombre){   
    int retorno=-1;
    if(this != NULL && nombre!=NULL){
         strcpy(nombre,this->nombre);
         retorno=0;
     }
     return retorno;
}
static int cliente_isValidNombre(char* nombre){
      return 1;
}
