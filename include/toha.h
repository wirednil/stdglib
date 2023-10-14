#include <stdlib.h>
#include <assert.h>
#include <string>

#define logprint(fmt, ...)\
        fprintf(stdout,"[ %s %d (%s) ]\t",__FILE__,__LINE__,__func__);\
        fprintf(stdout,fmt"\n",##__VA_ARGS__);

#define ASSERT { logprint("sin implementar...");assert(0); }

namespace toha 
{

    /**
     * @brief Generates a unique global identifier.
     * @return A string representing the unique global identifier.
     */
    std::string getGloballyUniqueIdentifier(void);
}
