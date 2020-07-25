#include <string.h>
#include <stdio.h>

#include "toha.h"

void IRG::copiar(char *dest, const char *ori){
    while(*dest++=*ori++);
}

void IRG::concatenar(char *destino, char *origen){
    char *aux = new char[strlen(destino) + strlen(origen)];
    sprintf(aux,"%s%s",destino,origen);
    destino = aux;
}

char * IRG::VertexIdToChar(IRG::VertexId vertexId){
    char * str = new char;
    sprintf(str,"%ld",vertexId);
    return str;
}