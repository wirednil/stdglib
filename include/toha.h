#include <stdlib.h>
#include <assert.h>

#include "industries/Types.h"
#include "grafos/Grafos.h"

#define logprint(fmt, ...)\
        fprintf(stdout,"[ %s %d (%s) ]\t",__FILE__,__LINE__,__func__);\
        fprintf(stdout,fmt"\n",##__VA_ARGS__);

#define ASSERT { logprint("sin implementar...");assert(0); }

namespace IRG{

    /**
     * @brief realiza una copia de caracteres
     * @param destino puntero a char donde se realizará la copia
     * @param origen cadena de caracteres válida a copiar.
     */
    void copiar(char *destino, const char *origen);

    /**
     * @brief realiza concatenación de caracteres
     * 
     * @param destino puntero a char donde se realizará la concatenación
     * @param origen cadena de caracter válida a concatenar.
     */
    void concatenar(char *destino, char *origen);

    /**
     * @brief Se realiza una conversión del tipo de dato VertexId a puntero char.
     * 
     * @param vertexId tipo de dato a convertir a puntero a char.
     * @return vertexId en tipo de puntero a char
     */
    char * VertexIdToChar(IRG::VertexId vertexId);
}
