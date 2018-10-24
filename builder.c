#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
static void buil_limpiarChar(char* pBuffer);

int buil_malloc(char* header, char* tipoPuntero,FILE* pArchivo){
    int retorno=-1;
    char palabra[1000];
    if (header != NULL && tipoPuntero != NULL && pArchivo != NULL){
        retorno=0;
        //hago los include
        strcpy(palabra,"#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n");
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        sprintf(palabra,"#include \"%s.h\"\n\n",header);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //funcion new
        sprintf(palabra,"%s* %s_new(){\n    return (%s*) malloc(sizeof(%s));\n}\n",tipoPuntero,header,tipoPuntero,tipoPuntero);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //funcion delete
        sprintf(palabra,"void %s_delete(%s* this){\n    free(this);\n}\n",header,tipoPuntero);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
    }
    return retorno;
}
int buil_campoChar(char* header,char* nombreFCampo,char* campo,char* tipoPuntero,FILE* pArchivo){
    int retorno=-1;
    char palabra[1000];
    if (header != NULL && tipoPuntero != NULL && pArchivo != NULL && nombreFCampo != NULL && campo != NULL){
        retorno=0;
        //abm de un tipo char
        //SET
        sprintf(palabra,"int %s_set%s(%s* this,char* %s){   \n    int retorno=-1;\n    if(this != NULL && %s_isValid%s(%s)){\n         strcpy(this->%s,%s);\n         retorno=0;\n     }\n     return retorno;\n}\n",header,nombreFCampo,tipoPuntero,campo,header,nombreFCampo,campo,campo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //GET
        sprintf(palabra,"int %s_get%s(%s* this,char* %s){   \n    int retorno=-1;\n    if(this != NULL && %s!=NULL){\n         strcpy(%s,this->%s);\n         retorno=0;\n     }\n     return retorno;\n}\n",header,nombreFCampo,tipoPuntero,campo,campo,campo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //ISVALID
        sprintf(palabra,"static int %s_isValid%s(char* %s){\n      return 1;\n}\n",header,nombreFCampo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
    }
    return retorno;
}
int buil_campoInt(char* header,char* nombreFCampo,char* campo,char* tipoPuntero,FILE* pArchivo){
    int retorno=-1;
    char palabra[1000];
    if (header != NULL && tipoPuntero != NULL && pArchivo != NULL && nombreFCampo != NULL && campo != NULL){
        retorno=0;
        //abm de un tipo char
        //SET
        sprintf(palabra,"int %s_set%s(%s* this,int %s){   \n    int retorno=-1;\n    if(this != NULL && %s_isValid%s(%s)){\n         this->%s%s;\n         retorno=0;\n     }\n     return retorno;\n}\n",header,nombreFCampo,tipoPuntero,campo,header,nombreFCampo,campo,campo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //GET
        sprintf(palabra,"int %s_get%s(%s* this,int* %s){   \n    int retorno=-1;\n    if(this != NULL && %s!=NULL){\n         %s,this->%s;\n         retorno=0;\n     }\n     return retorno;\n}\n",header,nombreFCampo,tipoPuntero,campo,campo,campo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //ISVALID
        sprintf(palabra,"static int %s_isValid%s(int %s){\n      return 1;\n}\n",header,nombreFCampo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
    }
    return retorno;
}
int buil_campoFloat(char* header,char* nombreFCampo,char* campo,char* tipoPuntero,FILE* pArchivo){
    int retorno=-1;
    char palabra[1000];
    if (header != NULL && tipoPuntero != NULL && pArchivo != NULL && nombreFCampo != NULL && campo != NULL){
        retorno=0;
        //abm de un tipo char
        //SET
        sprintf(palabra,"int %s_set%s(%s* this,float %s){   \n    int retorno=-1;\n    if(this != NULL && %s_isValid%s(%s)){\n         this->%s%s;\n         retorno=0;\n     }\n     return retorno;\n}\n",header,nombreFCampo,tipoPuntero,campo,header,nombreFCampo,campo,campo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //GET
        sprintf(palabra,"int %s_get%s(%s* this,float* %s){   \n    int retorno=-1;\n    if(this != NULL && %s!=NULL){\n         %s,this->%s;\n         retorno=0;\n     }\n     return retorno;\n}\n",header,nombreFCampo,tipoPuntero,campo,campo,campo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
        //ISVALID
        sprintf(palabra,"static int %s_isValid%s(float %s){\n      return 1;\n}\n",header,nombreFCampo,campo);
        fwrite(palabra,sizeof(char),strlen(palabra),pArchivo);
    }
    return retorno;
}
int buil_buscarCamposYTipos(FILE* pArchivo,int* lenPuntero,char pBuffer[]){
    int i=0;
    int retorno=-1;
    char* aux[2];
    if(pArchivo!= NULL && lenPuntero != NULL && pBuffer !=NULL){
        retorno=0;
        do{
            fscanf(pArchivo,"%s %s",aux[0],aux[1]);
            if(!strcmp(aux[0],"char")){
                buil_limpiarChar(aux[1]);
                i+=2;
            }else if(!strcmp(aux[0],"int")){
                buil_limpiarChar(aux[1]);
                i+=2;
            }else if(!strcmp(aux[0],"float")){
                buil_limpiarChar(aux[1]);
                strcpy(pBuffer[i],aux[0]);
                strcpy(pBuffer[i+1],aux[1]);
                i+=2;
            }
        }while(!feof(pArchivo));
        *lenPuntero=i;
        for(i=0;i<*lenPuntero;i+=2){
            printf("\n%s %s",pBuffer[i],pBuffer[i+1]);
        }
    }
    return retorno;
}
static void buil_limpiarChar(char* pBuffer){
    int i=0;
    do{
        if(pBuffer[i]=='[' || pBuffer[i]==';'){
            pBuffer[i]='\0';
            break;
        }
        i++;
    }while(1);
}
