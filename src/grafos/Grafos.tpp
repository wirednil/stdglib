
#pragma once
#include <iostream>
#include "Types.h"

namespace toha {

template <class T>
Node<T>* create_new_node(const T& val) {
  Node<T>* newNode = new Node<T>;
  if (newNode) {
    memcpy(&newNode->val, &val, sizeof(val));
  }
  return newNode;
}

template<class T> 
Grafo<T>::Grafo(const T& val) 
 { this->add(val); }

template<class T> 
Grafo<T>::Grafo(const T& val, const std::string &name, const int &type) :
  name(name), type(type) {
  this->add(val);
}


template<class T> 
int Grafo<T>::add(const T& value) {
    this->vertices.push_back(create_new_node(value));
    return this->vertices.size() - 1; 
}

template<class T> 
void Grafo<T>::showVertices() {
  std::string V = "V = {";
  for (Node<T>* a : vertices) {
    V.append(std::to_string(a->val));
    if (a != vertices.back()) {
      V.append(", ");
    } 
  }
  V.append("}");
  std::cout << V << std::endl;
}

template<class T> 
std::string Grafo<T>::getName() {
  return this->name;
}

template<class T> 
void Grafo<T>::setName(std::string name) {
  if (this->name.empty()) this->name = name;
}

template<class T> 
int Grafo<T>::connect(const T &dest, const T &src) {
  Node<T>* destNode = this->search(dest);
  Node<T>* srcNode  = this->search(src);
  if (destNode && srcNode) {
    srcNode->connect(destNode);
    if (type == NON_DIRECTED_GRAPH) {
      destNode->connect(srcNode);
    }
    return toha::Ok;
  }
  return toha::Error;
}

template <typename T>
Node<T>* Grafo<T>::search(const T& val) {
  for (Node<T>* node : this->vertices) {
    if (node->getValue() == val) return node;
  }
  return nullptr;
}
/*

IRG::Nodo* Grafo<T>::ObtenerNodo(IRG::VertexId id) {
  int sizeVertex = vertices.size();
  IRG::Vertice* verticeActual = ObtenerVertice(id);
  return (verticeActual ? verticeActual->nodo : NULL);
}
template<class T> 
std::string Grafo<T>::ObtenerIdentificador() {
  ASSERT
  return std::string("");
}	

template<class T> 
IRG::Status Grafo<T>::Conectar(IRG::VertexId verticeOrigen, IRG::VertexId verticeDestino) {
  IRG::Vertice* vOrigen  = ObtenerVertice(verticeOrigen);
  IRG::Vertice* vDestino = ObtenerVertice(verticeDestino);
  if (vOrigen!=NULL) {
    if (vDestino!=NULL) {
      if (!Contiene(vOrigen, verticeDestino)) {
        vOrigen->adyacencias.push_back(verticeDestino);
        if (EsNON_DIRECTED_GRAPH() && !Contiene(vDestino, verticeOrigen)) {
          vDestino->adyacencias.push_back(verticeOrigen);
        }
      }
      return IRG::Ok;
    }else{
      logprint("No es posible encontrar el vertice destino: %d", verticeDestino);
      return IRG::Error;
    }
  }else{
    logprint("No es posible encontrar el vertice origen: %d", verticeOrigen);
    return IRG::Error;
  }
}

template<class T> 
bool Grafo<T>::SonAdyacentes(IRG::VertexId verticeOrigen, IRG::VertexId verticeAdyacente) {
  IRG::Vertice* vOrigen = ObtenerVertice(verticeOrigen);
  return vOrigen ? Contiene(vOrigen, verticeAdyacente) : false;
}

template<class T> 
int Grafo<T>::ObtenerCantidadVertices() {
  return cantidadVertices;
}

//GeneradorGrafos(?)
template<class T> 
Grafo* Grafo<T>::ObtenerGrafoComplementario(const Grafo* grafo) {
  std::string name;
  name.append("Grafo Complementario ");
  name.append(ObtenerNombre());
  Grafo* grafoComplementario = new Grafo(name, ObtenerTipo());
  for (int origen = 0; origen < cantidadVertices; origen++) {
    IRG::Adyacencias adyacencias = vertices[origen]->adyacencias;
    IRG::VertexId vertexId       = vertices[origen]->vertexId;
  }
  return NULL;
}

template<class T> 
bool Grafo<T>::EsCompleto(const Grafo* grafo) {
  int cantidadComplementaria =  (cantidadVertices*(cantidadVertices-1))/2;
  int contadorAristas=0;
  for (int i=0; i<cantidadVertices; ++i) {
    contadorAristas += vertices[i]->adyacencias.size();
  }
  return contadorAristas == cantidadComplementaria;
}

template<class T> 
int Grafo<T>::ObtenerGrado(IRG::VertexId vertice) {
  IRG::Vertice *verticeActual = ObtenerVertice(vertice);
  int grado = verticeActual->adyacencias.size();
  return (tipo == IRG::NON_DIRECTED_GRAPH ? grado * 2 : grado);
}

template<class T> 
IRG::TipoGrafo Grafo<T>::ObtenerTipo() {
  return this->tipo;
}

//GeneradorGrafos
template<class T> 
Grafo* Grafo<T>::ObtenerUnion(const Grafo* grafo1, const Grafo* grafo2) {
  ASSERT
}

template<class T> 
std::string Grafo<T>::ObtenerVertices() {
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
std::string Grafo<T>::ObtenerAristas(const Grafo* grafo) {
  ASSERT
  return std::string("");
}

template<class T> 
int Grafo<T>::ObtenerAdyacencia(Grafo* grafo, int verticeOrigen, int indiceAdyacencia) {
  ASSERT
  return -1;
}

template<class T> 
void Grafo<T>::DestruirGrafo(Grafo* grafo) {
  ASSERT
}

template<class T> 
std::string Grafo<T>::ObtenerSucesionGrafica() {
  ASSERT
  return std::string("");
}

template<class T> 
bool Grafo<T>::ContieneAdyacencia(int verticeOrigen, int verticeAdyacente) {
  ASSERT
  return false;
}

template<class T> 
std::string Grafo<T>::ObtenerEtiqueta(int vertice) {
  ASSERT
  return std::string("");
}

template<class T> 
std::string Grafo<T>::ObtenerEtiquetaOClave(int verticeABuscar) {
  ASSERT
  return std::string("");

}

template<class T> 
bool Grafo<T>::ExisteVertice(IRG::VertexId vertice) {
  IRG::Vertice *v = ObtenerVertice(vertice);
  return v != NULL;
}


//Funciones privadas:

template<class T> 
IRG::Vertice* Grafo<T>::CrearVertice(IRG::Nodo* nuevoNodo, IRG::VertexId id) {
  IRG::Vertice* nuevoVertice = new IRG::Vertice;
  nuevoVertice->vertexId  = id;
  nuevoVertice->nodo      = nuevoNodo;
  nuevoVertice->etiqueta  = IRG::VertexIdToChar(id);
  return nuevoVertice;
}

template<class T> 
IRG::Vertice* Grafo<T>::ObtenerVertice(IRG::VertexId id) {
  int cantidadVertices = vertices.size();
  for (int verticeActual = 0; verticeActual<cantidadVertices; verticeActual++) {
    if (vertices[verticeActual]->vertexId == id) {
      return vertices[verticeActual];
    }
  }
  return NULL;
}

template<class T> 
bool Grafo<T>::Contiene(IRG::Vertice* vertice, IRG::VertexId verticeAdyacente) {
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
IRG::Status Grafo<T>::AgregarEtiqueta(IRG::VertexId etiqueta) {
  ASSERT
  return IRG::Error;
}

template<class T> 
IRG::Status Grafo<T>::AgregarEtiqueta(IRG::VertexId verticeId, IRG::TipoEtiqueta etiquetado, std::string etiqueta) {
  ASSERT
  return IRG::Error;
}
*/
}