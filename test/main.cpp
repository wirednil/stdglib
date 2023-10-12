#include "Grafos.h"

int main() {
    
    std::string as = "Grafoa";
    toha::Grafo<int> g(25, "Grafo-a", DIRECTED_GRAPH);
    g.add(1);
    g.add(2);
    g.add(3);
    g.add(4);
    g.add(26);
    g.add(27);

    g.connect(1,2);
    g.connect(1,4);
    g.connect(1,25);
    g.connect(1,26);
    g.connect(1,27);

    g.showConnections();
    return 0;
}