#pragma once

#include "Types.h"
#include "node.hpp"

#include <vector>
#include <list>
#include <cstring>
#include <string>
#include <iostream>

/** @brief A directed graph or digraph is a 
 * type of graph in which the edges 
 * have a defined meaning. 
 */
const int DIRECTED_GRAPH = 1;

/**
 * @brief A non-directed graph is a type of 
 * graph in which the edges are symmetrical 
 * relationships and do not point in any direction. 
 */
const int NON_DIRECTED_GRAPH = 0;

namespace toha {

/**
 * @class Grafo
 *
 * @brief The Grafo class represents a graph data structure.
 *
 * This class provides methods to create and manipulate a graph.
 * @author: J. Diógenes Cristaldo Cañiza.
 * @version: 12/10/2023
 */
template<class T> 
class graph
{
private:
  std::string name;                 ///< The name of the graph.
  std::string GUID;                 ///< Globally Unique Identifier
  const int type;                   ///< The type of the graph (DIRECTED_GRAPH or NON_DIRECTED_GRAPH).
  std::vector< Node<T>* > vertices; ///< Vector to store graph vertices.

  Node<T>* search(const T& val);
public:

  /**
   * @brief Constructor for creating a graph with a single vertex.
   *
   * @param val The value of the initial vertex.
   */
  graph(const T& val);

  /**
   * @brief Constructor for creating a graph with a name and type.
   *
   * @param val The value of the initial vertex.
   * @param name The name of the graph.
   * @param type The type of the graph (DIRECTED_GRAPH or NON_DIRECTED_GRAPH).
   */
  graph(const T& val, const std::string &name, const int &type);

  /**
   * @brief Add a vertex to the graph.
   *
   * @param value The value of the vertex to add.
   * @return The index of the added vertex.
   */
  int add(const T& value);
  
  /**
   * @brief Show the vertices of the graph.
   */
  void showVertices(); 

  /**
   * @brief Show the connections (edges) between vertices in the graph.
   */
  void showConnections();
  
  /**
   * @return The name of the graph.
   */
  std::string getName();
  
  /**
   * @brief Set the name of the graph.
   *
   * If the graph already has a name, it will be overwritten.
   *
   * @param name The new name for the graph.
   */
  void setName(std::string name);

  /**
   * @brief Establishes an adjacency relationship between nodes in the graph.
   *
   * If the graph is of type NON_DIRECTED_GRAPH, a commutative adjacency relationship is established between srcNode and destNode (srcNode is adjacent to destNode and vice versa).
   * If the graph is of type DIRECTED_GRAPH, an adjacency relationship is established from srcNode to destNode (srcNode is adjacent to destNode).
   * If srcNode or destNode do not belong to the graph, no action is taken.
   *
   * @param srcNode The source node.
   * @param destNode The destination node.
   *
   * @return Return code (Ok or Error) indicating the success of the operation.
   */
  int connect(const T &srcNode, const T &destNode);

  /**
   * @brief Remove a node from the graph.
   *
   * @param node The node to remove.
   * @return Return code (Ok or Error) indicating the success of the operation.
   */
  int removeNode(const T& node);

  /**
   * @brief Remove an edge from the graph.
   *
   * @param srcNode The source node.
   * @param destNode The destination node.
   * @return Return code (Ok or Error) indicating the success of the operation.
   */
  int removeEdge(const T& srcNode, const T& destNode);

  /**
   * @brief Get a list of all nodes in the graph.
   *
   * @return A list of nodes in the graph.
   */
  std::vector<Node<T>*> getNodes();

  /**
   * @brief Get a list of all edges in the graph.
   *
   * @return A list of edges in the graph.
   */
  std::list<Node<T>*> getEdges();

  /**
   * @brief Check if a node is in the graph.
   *
   * @param node The node to check.
   * @return True if the node is in the graph, false otherwise.
   */
  bool isNodeInGraph(const T& node);

  /**
   * @brief Check if an edge is in the graph.
   *
   * @param srcNode The source node.
   * @param destNode The destination node.
   * @return True if the edge is in the graph, false otherwise.
   */
  bool isEdgeInGraph(const T& srcNode, const T& destNode);

  /**
   * @brief Get a list of neighbor nodes for a given node.
   *
   * @param node The node for which to find neighbors.
   * @return A list of neighbor nodes.
   */
  std::list<Node<T>*> getNeighbors(const T& node);

  /**
   * @brief Check if the graph is empty (has no nodes).
   *
   * @return True if the graph is empty, false otherwise.
   */
  bool isEmpty();

  /**
   * @brief Clear the graph, removing all nodes and edges.
   */
  void clear();

  /**
   * @brief Get the number of nodes in the graph.
   *
   * @return The number of nodes in the graph.
   */
  size_t size();

  /**
   * @brief Perform Depth-First Search (DFS) traversal on the graph starting from a given node.
   *
   * @param startNode The starting node for DFS traversal.
   * @return A list of nodes visited in the order of traversal.
   */
  std::list<Node<T>*> DFS(const T& startNode);

  /**
   * @brief Perform Breadth-First Search (BFS) traversal on the graph starting from a given node.
   *
   * @param startNode The starting node for BFS traversal.
   * @return A list of nodes visited in the order of traversal.
   */
  std::list<Node<T>*> BFS(const T& startNode);

  /**
   * @brief Check if the graph is connected (all nodes are reachable from any node).
   *
   * @return True if the graph is connected, false otherwise.
   */
  bool isConnected();

  /**
   * @brief Check if the graph contains a cycle.
   *
   * @return True if the graph contains a cycle, false otherwise.
   */
  bool isCyclic();

  /**
   * @brief Perform a topological sort on the directed graph.
   *
   * @return A list of nodes in topological order.
   */
  std::list<Node<T>*> topologicalSort();

  /**
   * @brief Find the shortest path between two nodes in the graph.
   *
   * @param srcNode The source node.
   * @param destNode The destination node.
   * @return A list of nodes representing the shortest path.
   */
  std::list<Node<T>*> shortestPath(const T& srcNode, const T& destNode);

  /**
   * @brief Find the minimum spanning tree of the graph using a suitable algorithm (e.g., Prim's or Kruskal's).
   *
   * @return A list of edges forming the minimum spanning tree.
   */
  std::list<Node<T>*> minimumSpanningTree();


  //<! TODO: refactor  
 
  /**
   * @return true si dest es adyacente a verticeDestino.
   * Caso contrario devuelve false
   */
  // bool SonAdyacentes(VertexId dest, VertexId verticeAdyacente);

  /**
   * @return Devuelve la cantidad de vertices de graph
   */
  // int ObtenerCantidadVertices();

  /**
   * TODO: Debe estar en otro fuente que trabaje con grafos.
   * Precondiciones: @graph es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve una instancia nueva del graph que es el complemento de @graph
   */
  // graph* ObtenerGrafoComplementario(const graph* graph);

  /**
   * @return true si @graph es un graph completo. Caso contrario devuelve false
   */
  // bool EsCompleto(const graph* graph);

  /**
   * Precondiciones: @graph es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Si @graph es un graph no dirigido devuelve el grado del vertice @vertice. 
   * Si es un graph dirigido, devuelve el grado de salida de @vertice
   */
  // int ObtenerGrado(VertexId vertice);

  // int ObtenerTipo();

  /**
   * Precondiciones: @grafo1 y @grafo2 son instancias validas creadas con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve una instancia nueva de graph que es la union de conjuntos de los vertices
   * y aristas de @grafo1 y @grafo2
   */
  // graph* ObtenerUnion(const graph* grafo1, const graph* grafo2);

  /**
   *Precondiciones: @graph es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve los vertices en un registro en formato CSV donde cada campo es un vertice.
   * Si los vertices tienen etiquetas devuelve las etiquetas en lugar del numero de vertice.
   */
  // std::string ObtenerVertices();

  /**
   * Precondiciones: @graph es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve las aristas en formato de etiquetas.
   * El formato de etiquetas para un graph no dirigido es el siguiente: 1-4 2-3 0-1
   * Donde nos dice que el conjunto E del graph es: {(1,4), (2,3), (0,1)}
   * El formato de etiquetas para un graph dirigido es el siguiente: 1-4 2-3 4-1
   * Donde nos dice que el conjunto E del graph es: {(1,4), (2,3), (0,1), (4,1)}
   *
   * Vemos que en ambos casos son las adyacencias separadas por espacio.
   * Para el caso de los grafos no dirigidos no hay que duplicar las relaciones conmutativas.
   * Si los vertices tienen etiquetas devuelve las etiquetas en lugar del numero de vertice
   */
  // std::string ObtenerAristas(const graph* graph);

  // int ObtenerAdyacencia(graph* graph, int dest, int indiceAdyacencia);

  /**
   * Precondiciones: @graph es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Libera todos los recursos asociados a @graph
   */
  // void DestruirGrafo(graph* graph);

  /**
   * Precondiciones: @graph es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve la sucesion grafica de @graph separados por coma
   */
  // std::string ObtenerSucesionGrafica();
  // bool ContieneAdyacencia(int dest, int verticeAdyacente);
  // std::string ObtenerEtiqueta(int vertice);
  // std::string ObtenerEtiquetaOClave(int verticeABuscar);
  // bool ExisteVertice(VertexId vertice);

  /**
   * @brief Se asocia el vertice actual como etiqueta de dicho vertice del graph. 
   * Si ya tenia etiqueta se la sobre escribe.
   * 
   * @param verticeId
   * es un vertice del graph y se le asigna como etiqueta del mismo.
   * 
   * @return
   * Ok: Si el vertice existe retorna.
   * Error: Si el vertice no existe.
   */
  // int AgregarEtiqueta(VertexId verticeId);

  /**
   * @brief Se asocia al vertice actual del graph una etiqueta específicada por el programador. 
   * 
   * @param verticeId
   * Es un vertice del graph.
   * 
   * @param etiquetado
   * Es el tipo de etiqueta a asignar al vertice.
   * Si es etiquetado Simple, se ignora la etiqueta parametrizada y se le asigna el vertice como etiqueta.
   * Si es etiquetado Propio, se asigna la etiqueta parametrizada al vertice actual.  
   * 
   * @param etiqueta
   * Es string puntero válido definido por el programador. Si el string está vacio
   * se asigna el verticeId como etiqueta actual.
   * 
   * @return  
   * Ok: si el vertice asociado al verticeId actual existe.
   * Error: Si el vertice asociado al verticeId actual no existe    
   */
  // int AgregarEtiqueta(VertexId verticeId, TipoEtiqueta etiquetado, std::string etiqueta);

}; /*graph*/

}

#include "../../src/grafos/graph.tpp"