#pragma once

#include "Types.h"
#include "Node.h"

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
 * @brief Define una clase grafo que puede ser: 
 * Dirigido o no dirigido.
 * Con vertices y aristas
 * 
 * @author: J. Diógenes Cristaldo Cañiza.
 * @version: 09/06/2020
 */
template<class T> 
class Grafo
{
private:
  std::string name;
  const int type;
  std::vector< Node<T>* > vertices;

  Node<T>* search(const T& val);
public:
  Grafo(const T& val);
  Grafo(const T& val, const std::string &name, const int &type);
  int add(const T& value);
  
  void showVertices(); 

  void showConnections();
  
  /**
   * @return nombre del grafo. 
   */
  std::string getName();
  
  /**
   * @brief se asigna un nombre al grafo. Si ya tenía un nombre definido, se sobreescribe.
   * 
   * @param nombre tipo de dato puntero a string válido.
   */
  void setName(std::string name);
  
  /** 
   * @return identificador unico global
   */
  // std::string ObtenerIdentificador();
  
  /**
   * @brief Si es un grafo NON_DIRECTED_GRAPH, se agrega una relacion de adyacencia conmutativa entre
   * dest y verticeDestino (dest es adyacente a verticeDestino y viceversa).  
   * Si es un grafo Dirigido, se agrega una relacion de adyacencia de dest y verticeDestino
   * (dest es adyacente a verticeDestino).
   * Si dest o verticeDestino no pertenece al grafo no realiza ninguna accion
   * 
   * @param dest
   * 
   * @param verticeDestino
   */
  int connect(const T &dest, const T &src);
  
  /**
   * @return true si dest es adyacente a verticeDestino.
   * Caso contrario devuelve false
   */
  // bool SonAdyacentes(VertexId dest, VertexId verticeAdyacente);

  /**
   * @return Devuelve la cantidad de vertices de grafo
   */
  // int ObtenerCantidadVertices();

  /**
   * TODO: Debe estar en otro fuente que trabaje con grafos.
   * Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve una instancia nueva del Grafo que es el complemento de @grafo
   */
  // Grafo* ObtenerGrafoComplementario(const Grafo* grafo);

  /**
   * @return true si @grafo es un grafo completo. Caso contrario devuelve false
   */
  // bool EsCompleto(const Grafo* grafo);

  /**
   * Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Si @grafo es un grafo no dirigido devuelve el grado del vertice @vertice. 
   * Si es un grafo dirigido, devuelve el grado de salida de @vertice
   */
  // int ObtenerGrado(VertexId vertice);

  // int ObtenerTipo();

  /**
   * Precondiciones: @grafo1 y @grafo2 son instancias validas creadas con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve una instancia nueva de Grafo que es la union de conjuntos de los vertices
   * y aristas de @grafo1 y @grafo2
   */
  // Grafo* ObtenerUnion(const Grafo* grafo1, const Grafo* grafo2);

  /**
   *Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve los vertices en un registro en formato CSV donde cada campo es un vertice.
   * Si los vertices tienen etiquetas devuelve las etiquetas en lugar del numero de vertice.
   */
  // std::string ObtenerVertices();

  /**
   * Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve las aristas en formato de etiquetas.
   * El formato de etiquetas para un grafo no dirigido es el siguiente: 1-4 2-3 0-1
   * Donde nos dice que el conjunto E del grafo es: {(1,4), (2,3), (0,1)}
   * El formato de etiquetas para un grafo dirigido es el siguiente: 1-4 2-3 4-1
   * Donde nos dice que el conjunto E del grafo es: {(1,4), (2,3), (0,1), (4,1)}
   *
   * Vemos que en ambos casos son las adyacencias separadas por espacio.
   * Para el caso de los grafos no dirigidos no hay que duplicar las relaciones conmutativas.
   * Si los vertices tienen etiquetas devuelve las etiquetas en lugar del numero de vertice
   */
  // std::string ObtenerAristas(const Grafo* grafo);

  // int ObtenerAdyacencia(Grafo* grafo, int dest, int indiceAdyacencia);

  /**
   * Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Libera todos los recursos asociados a @grafo
   */
  // void DestruirGrafo(Grafo* grafo);

  /**
   * Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
   * Postcondiciones: Devuelve la sucesion grafica de @grafo separados por coma
   */
  // std::string ObtenerSucesionGrafica();
  // bool ContieneAdyacencia(int dest, int verticeAdyacente);
  // std::string ObtenerEtiqueta(int vertice);
  // std::string ObtenerEtiquetaOClave(int verticeABuscar);
  // bool ExisteVertice(VertexId vertice);

  /**
   * @brief Se asocia el vertice actual como etiqueta de dicho vertice del grafo. 
   * Si ya tenia etiqueta se la sobre escribe.
   * 
   * @param verticeId
   * es un vertice del grafo y se le asigna como etiqueta del mismo.
   * 
   * @return
   * Ok: Si el vertice existe retorna.
   * Error: Si el vertice no existe.
   */
  // int AgregarEtiqueta(VertexId verticeId);

  /**
   * @brief Se asocia al vertice actual del grafo una etiqueta específicada por el programador. 
   * 
   * @param verticeId
   * Es un vertice del grafo.
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

}; /*Grafo*/

}

#include "../../src/grafos/Grafos.tpp"