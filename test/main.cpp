#include "Grafos.h"

struct Point{
    int x;
    int y;
};

int main() {
    Point p;
    p.x=25;
    p.y=1;
    std::string as = "Grafoa";
    toha::Grafo<Point> g(p, "Grafo-a", NON_DIRECTED_GRAPH);

    std::cout<< "name: " << g.getName() << std::endl;

    return 0;
}