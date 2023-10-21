#pragma once
#include <iostream>
#include <algorithm>    // std::find
#include "Types.h"

namespace toha {

template <class T>
std::string getAdjacentNodeRepresentations(const T& node, std::list<Node<T>*> adjacent) {
  std::string nodes = "";
  for (Node<T>* n: adjacent) {
    nodes += "(";
    nodes += std::to_string(node);
    nodes += ", ";
    nodes += std::to_string(n->val);
    nodes += ")";
    if (n != adjacent.back()) nodes += ", ";
  }
  return nodes;
}

template<class T>
graph<T>::graph(const T& val)
 { this->add(val); }

template<class T>
graph<T>::graph(const T& val, const std::string &name, const int &type) :
  name(name), type(type) {
  this->add(val);
}

template<class T>
int graph<T>::add(const T& value) {
  this->vertices.push_back(new Node<T>(value));
  return this->vertices.size() - 1;
}

template<class T>
std::string graph<T>::getName() {
  return this->name;
}

template<class T>
void graph<T>::setName(std::string name) {
  this->name = name;
}

template<class T>
int graph<T>::connect(const T &dest, const T &src) {
  Node<T>* destNode = this->search(dest);
  Node<T>* srcNode  = this->search(src);
  if (destNode && srcNode) {
    destNode->connect(srcNode);
    if (type == NON_DIRECTED_GRAPH) {
      srcNode->connect(destNode);
    }
    return toha::Ok;
  }
  return toha::Error;
}

template <class T>
Node<T>* graph<T>::search(const T& val) {
  for (Node<T>* node : this->vertices) {
    if (node->getValue() == val) return node;
  }
  return nullptr;
}

template<class T>
void graph<T>::showVertices() {
  std::string V = "V = {";
  for (Node<T>* a : vertices) {
    V.append(std::to_string(a->getValue()));
    if (a != vertices.back()) {
      V.append(", ");
    }
  }
  V.append("}");
  std::cout << V << std::endl;
}

template<class T>
void graph<T>::showConnections() {
  std::string edges = "E = {";
  for (Node<T>* node : vertices) {
    std::string adjacentNodes = node->getAdjacentNodeRepresentations();
    if (!adjacentNodes.empty()) {
      edges.append(adjacentNodes);
    }
  }
  edges.append("}");
  std::cout << edges << std::endl;
}

template<class T>
size_t graph<T>::size() {
  return vertices.size();
}

template<class T>
int graph<T>::removeNode(const T& node) {
  if (!vertices.empty()) {
    auto it = std::find(vertices.begin(), vertices.end(), 
                  this->search(node));
    vertices.erase(it);
  }
  return 0;
}
/*

template<class T>
bool graph<T>::SonAdyacentes(IRG::VertexId verticeOrigen, IRG::VertexId verticeAdyacente) {
  IRG::Vertice* vOrigen = ObtenerVertice(verticeOrigen);
  return vOrigen ? Contiene(vOrigen, verticeAdyacente) : false;
}

template<class T>
int graph<T>::ObtenerCantidadVertices() {
  return cantidadVertices;
}

//GeneradorGrafos(?)
template<class T>
graph* graph<T>::ObtenerGrafoComplementario(const graph* grafo) {
  std::string name;
  name.append("graph Complementario ");
  name.append(ObtenerNombre());
  graph* grafoComplementario = new graph(name, ObtenerTipo());
  for (int origen = 0; origen < cantidadVertices; origen++) {
    IRG::Adyacencias adyacencias = vertices[origen]->adyacencias;
    IRG::VertexId vertexId       = vertices[origen]->vertexId;
  }
  return NULL;
}

template<class T>
bool graph<T>::EsCompleto(const graph* grafo) {
  int cantidadComplementaria =  (cantidadVertices*(cantidadVertices-1))/2;
  int contadorAristas=0;
  for (int i=0; i<cantidadVertices; ++i) {
    contadorAristas += vertices[i]->adyacencias.size();
  }
  return contadorAristas == cantidadComplementaria;
}

template<class T>
int graph<T>::ObtenerGrado(IRG::VertexId vertice) {
  IRG::Vertice *verticeActual = ObtenerVertice(vertice);
  int grado = verticeActual->adyacencias.size();
  return (tipo == IRG::NON_DIRECTED_GRAPH ? grado * 2 : grado);
}

template<class T>
IRG::TipoGrafo graph<T>::ObtenerTipo() {
  return this->tipo;
}

//GeneradorGrafos
template<class T>
graph* graph<T>::ObtenerUnion(const graph* grafo1, const graph* grafo2) {
  ASSERT
}

template<class T>
std::string graph<T>::ObtenerVertices() {
  std::string sucesionGrafica;
  for (int i=0; i<cantidadVertices; ++i) {
    IRG::Vertice *verticeActual = ObtenerVertice(this->vertices[i]->vertexId);
    if (verticeActual!=NULL && i==0) {
      sucesionGrafica.append(verticeActual->etiqueta);
    } else {
      sucesionGrafica.append(sucesionGrafica);
      sucesionGrafica.append(verticeActual->etiqueta);
    }
  }
  return sucesionGrafica;
}

template<class T>
std::string graph<T>::ObtenerAristas(const graph* grafo) {
  ASSERT
  return std::string("");
}

template<class T>
int graph<T>::ObtenerAdyacencia(graph* grafo, int verticeOrigen, int indiceAdyacencia) {
  ASSERT
  return -1;
}

template<class T>
std::string graph<T>::ObtenerSucesionGrafica() {
  ASSERT
  return std::string("");
}

template<class T>
bool graph<T>::ContieneAdyacencia(int verticeOrigen, int verticeAdyacente) {
  ASSERT
  return false;
}

template<class T>
bool graph<T>::ExisteVertice(IRG::VertexId vertice) {
  IRG::Vertice *v = ObtenerVertice(vertice);
  return v != NULL;
}


//Funciones privadas:

template<class T>
IRG::Vertice* graph<T>::CrearVertice(IRG::Nodo* nuevoNodo, IRG::VertexId id) {
  IRG::Vertice* nuevoVertice = new IRG::Vertice;
  nuevoVertice->vertexId  = id;
  nuevoVertice->nodo      = nuevoNodo;
  nuevoVertice->etiqueta  = IRG::VertexIdToChar(id);
  return nuevoVertice;
}

template<class T>
IRG::Vertice* graph<T>::ObtenerVertice(IRG::VertexId id) {
  int cantidadVertices = vertices.size();
  for (int verticeActual = 0; verticeActual<cantidadVertices; verticeActual++) {
    if (vertices[verticeActual]->vertexId == id) {
      return vertices[verticeActual];
    }
  }
  return NULL;
}

template<class T>
bool graph<T>::Contiene(IRG::Vertice* vertice, IRG::VertexId verticeAdyacente) {
  if (vertice->adyacencias.empty()) return false;
  IRG::Adyacencias::const_iterator iterador = vertice->adyacencias.begin();
  bool contiene = false;
  while (iterador != vertice->adyacencias.end() && !contiene) {
    contiene = *iterador == verticeAdyacente;
    iterador++;
  }
  return contiene;
}

template<class T>
IRG::Status graph<T>::AgregarEtiqueta(IRG::VertexId etiqueta) {
  ASSERT
  return IRG::Error;
}

template<class T>
IRG::Status graph<T>::AgregarEtiqueta(IRG::VertexId verticeId, IRG::TipoEtiqueta etiquetado, std::string etiqueta) {
  ASSERT
  return IRG::Error;
}
*/
}
