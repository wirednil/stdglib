#include <stdlib.h>
#include <assert.h>

#include "industries/Types.h"
#include "grafos/Grafos.h"

#define logprint(fmt, ...)\
        fprintf(stdout,"[ %s %d (%s) ]\t",__FILE__,__LINE__,__func__);\
        fprintf(stdout,fmt"\n",##__VA_ARGS__);

#define ASSERT { logprint("sin implementar...");assert(0); }

namespace IRG{

    void copiar(char *destino, const char *origen);

    void concatenar(char *destino, char *origen);

    char * VertexIdToChar(IRG::VertexId vertexId);
}
