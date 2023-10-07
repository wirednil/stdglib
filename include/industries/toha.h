#include <stdlib.h>
#include <assert.h>

#define logprint(fmt, ...)\
        fprintf(stdout,"[ %s %d (%s) ]\t",__FILE__,__LINE__,__func__);\
        fprintf(stdout,fmt"\n",##__VA_ARGS__);

#define ASSERT { logprint("sin implementar...");assert(0); }

