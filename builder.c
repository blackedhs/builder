#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int buil_buscarCamposYTipos(char* aux,int len,char* pBuffer){
    int i;
    int j=0;
    int retorno=-1;
    if (aux != NULL && pBuffer!= NULL && len>0){
        retorno=0;
        for(i=0;i<len;i++){
            if(aux[i]=="c" && aux[i+1]=="h"&&aux[i+2]=="a"&&aux[i+3]=="r"){
                i+=5;
                strcpy(pBuffer[j],"char");
                j++;
            }else if(aux[i]=="i"&&aux[i+1]=="n"&&aux[i+2]=="t"){
                i+=4;
                strcpy(pBuffer[j],"int");
                j++;
            }else if(aux[i]=="f"&&aux[i+1]=="l"&&aux[i+2]=="o"&&aux[i+3]=="a"&&aux[i+4]=="t"){
                i+=6;
                strcpy(pBuffer[j],"float");
                j++;
            }
        }
    return retorno;
    }

}
