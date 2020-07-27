# Standard graph library repository.

### Library installation:
`make intall`
`export LD_LIBRARY_PATH=/path/to/stdglib/SHSG:$LD_LIBRARY_PATH`

### Import the library
```cpp
#include <toha.h>
using namespace stdgraph;
```

### You can create a tuple 'Node' to create a vertex in the graph.
```cpp

struct IRG::Nodo{
    char* firstName;
    char* lastName
	int edad;
};

IRG::Nodo* CreateNode(char * firstName, char * lastName, int edad){
    IRG::Nodo* newNode = new IRG::Nodo;
    nuevoNodo->nombre = name;
    nuevoNodo->edad   = edad;
    return nuevoNodo;
}
```
### Once the functions for the initialization of our node have been created.
#### We will proceed to use the Network class to insert it.
```cpp
int main(){
	//It is entered by parameter:
	//Network name
	//Network type: Direct (Dirigido) or non-direct (NoDirigido)
    Grafo* graph = new Grafo("Graph A", Dirigido);
	
	//We use the id for the graph vertex.
	VertexId id = 1;
	
	//We use the CreateNode function and then the 
	//AgregarNodo (add node) method.
	graph->AgregarNodo(CreateNode("Diogenes","Cristaldo",28), id);
```