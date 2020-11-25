#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "toha.h"

/**
 ** @brief Espacio de nombre para la Biblioteca Estandar de Grafos
 **/
namespace stdgraph {  
  /**
   ** @brief Define una clase grafo que puede ser: 
   ** Dirigido o no dirigido.
   ** Con vertices y aristas
   ** 
   ** @author: J. Diógenes Cristaldo Cañiza.
   ** @version: 09/06/2020
   **/
  class Grafo
  {
  private:
    char* nombre;
    char* identificadorUnico;
    int   cantidadVertices;
    char* etiqueta;
    IRG::TipoGrafo tipo;
    IRG::Vertices vertices;

    IRG::Vertice* CrearVertice(IRG::Nodo* nuevoNodo, IRG::VertexId id);
    IRG::Vertice* ObtenerVertice(IRG::VertexId id);
    bool Contiene(IRG::Vertice* vertice, IRG::VertexId verticeAdyacente);
    bool EsNoDirigido(){ return tipo == IRG::NoDirigido; }

  public:
    Grafo(char* nombre, IRG::TipoGrafo tipo);
    ~Grafo();

    /**
     ** @brief Se define al grafo como Dirigido
     ** 
     ** @param nombre Es un tipo de dato puntero a char, con el cual se define el nombre del
     ** grafo actual.
     **/
    void CrearGrafoDirigido(char* nombre);

    /**
     ** @brief Se define al grafo como NoDirigido
     ** 
     ** @param nombre Es un tipo de dato puntero a char, con el cual se define el nombre del
     ** grafo actual.
     **/
    void CrearGrafoNoDirigido(char* nombre);

    /**
     ** @brief Se agrega Nodo como vertice del grafo
     ** 
     ** @param nuevoNodo 
     ** Nodo creado por las primitivas creaciones del programador.
     ** 
     ** @param id   
     ** numero de vertice id asignado a criterio del programador.  
     ** 
     ** @return 
     ** IRG::Ok si nuevoNodo es una instancia válida.
     ** IRG::Error: Si nuevoNodo no es una instancia válida.
     **/
    IRG::Status AgregarNodo(IRG::Nodo* nuevoNodo, IRG::VertexId id);

    IRG::Nodo* ObtenerNodo(IRG::VertexId vertexId);

    /**
     ** @return nombre del grafo. 
     **/
    char* ObtenerNombre();
    
    /**
     ** @brief se asigna un nombre al grafo. Si ya tenía un nombre definido, se sobreescribe.
     ** 
     ** @param nombre tipo de dato puntero a char válido.
     **/
    void EstablecerNombre(char* nombre);
    
    /** 
     ** @return identificador unico global
     **/
    char* ObtenerIdentificador();
    
    /**
     ** @brief Si es un grafo NoDirigido, se agrega una relacion de adyacencia conmutativa entre
     ** verticeOrigen y verticeDestino (verticeOrigen es adyacente a verticeDestino y viceversa).  
     ** Si es un grafo Dirigido, se agrega una relacion de adyacencia de verticeOrigen y verticeDestino
     ** (verticeOrigen es adyacente a verticeDestino).
     ** Si verticeOrigen o verticeDestino no pertenece al grafo no realiza ninguna accion
     ** 
     ** @param verticeOrigen
     ** 
     ** @param verticeDestino
     **/
    IRG::Status Conectar(IRG::VertexId verticeOrigen, IRG::VertexId verticeDestino);
    
    /**
     ** @return true si verticeOrigen es adyacente a verticeDestino.
     ** Caso contrario devuelve false
     **/
    bool SonAdyacentes(IRG::VertexId verticeOrigen, IRG::VertexId verticeAdyacente);

    /**
     ** @return Devuelve la cantidad de vertices de grafo
     **/
    int ObtenerCantidadVertices();

    /**
     ** TODO: Debe estar en otro fuente que trabaje con grafos.
     ** Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
     ** Postcondiciones: Devuelve una instancia nueva del Grafo que es el complemento de @grafo
     **/
    Grafo* ObtenerGrafoComplementario(const Grafo* grafo);

    /**
     ** @return true si @grafo es un grafo completo. Caso contrario devuelve false
     **/
    bool EsCompleto(const Grafo* grafo);

    /**
     ** Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
     ** Postcondiciones: Si @grafo es un grafo no dirigido devuelve el grado del vertice @vertice. 
     ** Si es un grafo dirigido, devuelve el grado de salida de @vertice
     **/
    int ObtenerGrado(IRG::VertexId vertice);

    IRG::TipoGrafo ObtenerTipo();

    /**
     ** Precondiciones: @grafo1 y @grafo2 son instancias validas creadas con alguna de las primitivas creacionales
     ** Postcondiciones: Devuelve una instancia nueva de Grafo que es la union de conjuntos de los vertices
     ** y aristas de @grafo1 y @grafo2
     **/
    Grafo* ObtenerUnion(const Grafo* grafo1, const Grafo* grafo2);

    /**
     ** Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
     ** Postcondiciones: Devuelve los vertices en un registro en formato CSV donde cada campo es un vertice.
     ** Si los vertices tienen etiquetas devuelve las etiquetas en lugar del numero de vertice.
     **/
    char* ObtenerVertices();

    /**
     ** Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
     ** Postcondiciones: Devuelve las aristas en formato de etiquetas.
     ** El formato de etiquetas para un grafo no dirigido es el siguiente: 1-4 2-3 0-1
     ** Donde nos dice que el conjunto E del grafo es: {(1,4), (2,3), (0,1)}
     ** El formato de etiquetas para un grafo dirigido es el siguiente: 1-4 2-3 4-1
     ** Donde nos dice que el conjunto E del grafo es: {(1,4), (2,3), (0,1), (4,1)}
     **
     ** Vemos que en ambos casos son las adyacencias separadas por espacio.
     ** Para el caso de los grafos no dirigidos no hay que duplicar las relaciones conmutativas.
     ** Si los vertices tienen etiquetas devuelve las etiquetas en lugar del numero de vertice
     **/
    char* ObtenerAristas(const Grafo* grafo);

    int ObtenerAdyacencia(Grafo* grafo, int verticeOrigen, int indiceAdyacencia);

    /**
     ** Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
     ** Postcondiciones: Libera todos los recursos asociados a @grafo
     **/
    void DestruirGrafo(Grafo* grafo);

    /**
     ** Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
     ** Postcondiciones: Devuelve la sucesion grafica de @grafo separados por coma
     **/
    char* ObtenerSucesionGrafica();
    
    /**
     **
     **/
    bool ContieneAdyacencia(int verticeOrigen, int verticeAdyacente);

    /**
     **
     **/
    char* ObtenerEtiqueta(int vertice);
    
    /**
     **
     **/
    char* ObtenerEtiquetaOClave(int verticeABuscar);

    /**
     **
     **/
    bool ExisteVertice(IRG::VertexId vertice);

    /**
     ** @brief Se asocia el vertice actual como etiqueta de dicho vertice del grafo. 
     ** Si ya tenia etiqueta se la sobre escribe.
     ** 
     ** @param verticeId
     ** es un vertice del grafo y se le asigna como etiqueta del mismo.
     ** 
     ** @return
     ** Ok: Si el vertice existe retorna.
     ** Error: Si el vertice no existe.
     **/
    IRG::Status AgregarEtiqueta(IRG::VertexId verticeId);

    /**
     ** @brief Se asocia al vertice actual del grafo una etiqueta específicada por el programador. 
     ** 
     ** @param verticeId
     ** Es un vertice del grafo.
     ** 
     ** @param etiquetado
     ** Es el tipo de etiqueta a asignar al vertice.
     ** Si es etiquetado Simple, se ignora la etiqueta parametrizada y se le asigna el vertice como etiqueta.
     ** Si es etiquetado Propio, se asigna la etiqueta parametrizada al vertice actual.  
     ** 
     ** @param etiqueta
     ** Es un puntero a char válido definido por el programador. Si es un puntero a char vacío,
     ** se asigna el verticeId como etiqueta actual.
     ** 
     ** @return  
     ** Ok: si el vertice asociado al verticeId actual existe.
     ** Error: Si el vertice asociado al verticeId actual no existe    
     **/
    IRG::Status AgregarEtiqueta(IRG::VertexId verticeId, IRG::TipoEtiqueta etiquetado, char* etiqueta);

  }; /*Grafo*/
}

#endif /*_GRAFO_H_*/
