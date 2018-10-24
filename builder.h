#ifndef BUILDER_H_INCLUDED
#define BUILDER_H_INCLUDED
int buil_malloc(char* header, char* tipoPuntero,FILE* pArchivo);
int buil_campoChar(char* header,char* nombreFCampo,char* campo,char* tipoPuntero,FILE* pArchivo);
int buil_campoFloat(char* header,char* nombreFCampo,char* campo,char* tipoPuntero,FILE* pArchivo);
int buil_campoInt(char* header,char* nombreFCampo,char* campo,char* tipoPuntero,FILE* pArchivo);
int buil_buscarCamposYTipos(FILE* pArchivo,int* lenPuntero,char pBuffer[]);

#endif // BUILDER_H_INCLUDED
