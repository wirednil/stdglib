#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "toha.h"

struct IRG::Vertice{
    IRG::Nodo* nodo;
    char * etiqueta;
    IRG::VertexId vertexId;
    IRG::Adyacencias adyacencias;
};

stdgraph::Grafo::Grafo(char * nombre, IRG::TipoGrafo tipo){
    switch(tipo){
        case IRG::Dirigido:
            CrearGrafoDirigido(nombre);
            break;
        case IRG::NoDirigido:
            CrearGrafoNoDirigido(nombre);
            break;
        default:
            fprintf(stderr,"Tipo de grafo no reconocido\n");
            ASSERT
    }
}

void stdgraph::Grafo::CrearGrafoNoDirigido(char* nombre){
    this->nombre = nombre;
    this->tipo = IRG::NoDirigido;
    this->cantidadVertices = 0;
}

void stdgraph::Grafo::CrearGrafoDirigido(char* nombre){
    this->nombre = nombre;
    this->tipo = IRG::Dirigido;
    this->cantidadVertices = 0;
}

IRG::Status stdgraph::Grafo::AgregarNodo(IRG::Nodo* nuevoNodo, IRG::VertexId id){
    if(nuevoNodo != NULL){
        this->vertices.push_back(CrearVertice(nuevoNodo,id));
        cantidadVertices++;
        return IRG::Ok;
    }
    return IRG::Error;
}

IRG::Nodo* stdgraph::Grafo::ObtenerNodo(IRG::VertexId id){
    int sizeVertex = vertices.size();
    IRG::Vertice* verticeActual = ObtenerVertice(id);
    return (verticeActual ? verticeActual->nodo : NULL);
}

char* stdgraph::Grafo::ObtenerNombre(){
    return this->nombre;
}

void stdgraph::Grafo::EstablecerNombre(char * nombre){
    if(this->nombre==NULL) this->nombre = nombre;
}

char* stdgraph::Grafo::ObtenerIdentificador(){
    //ASSERT
    //return "";
}	

IRG::Status stdgraph::Grafo::Conectar(IRG::VertexId verticeOrigen, IRG::VertexId verticeDestino){
    IRG::Vertice* vOrigen = ObtenerVertice(verticeOrigen);
    IRG::Vertice* vDestino = ObtenerVertice(verticeDestino);
    if(vOrigen!=NULL){
        if(vDestino!=NULL){
			if(!Contiene(vOrigen, verticeDestino)){
				vOrigen->adyacencias.push_back(verticeDestino);
				if(EsNoDirigido() && !Contiene(vDestino, verticeOrigen)){
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

bool stdgraph::Grafo::SonAdyacentes(IRG::VertexId verticeOrigen, IRG::VertexId verticeAdyacente){
    IRG::Vertice* vOrigen = ObtenerVertice(verticeOrigen);
    return vOrigen ? Contiene(vOrigen, verticeAdyacente) : false;
}

int stdgraph::Grafo::ObtenerCantidadVertices(const Grafo* grafo){
    return cantidadVertices;
}

//GeneradorGrafos(?)
stdgraph::Grafo* stdgraph::Grafo::ObtenerGrafoComplementario(const Grafo* grafo){
    char *nombre = new char;
    sprintf(nombre,"Grafo Complementario %s", ObtenerNombre());
    Grafo *grafoComplementario = new Grafo(nombre, ObtenerTipo());
    for(int origen = 0; origen < cantidadVertices; origen++){
        IRG::Adyacencias adyacencias = vertices[origen]->adyacencias;
        IRG::VertexId vertexId = vertices[origen]->vertexId;
    }
    return NULL;
}

bool stdgraph::Grafo::EsCompleto(const Grafo* grafo){
    int cantidadComplementaria =  (cantidadVertices*(cantidadVertices-1))/2;
    int contadorAristas=0;
	for(int i=0; i<cantidadVertices; ++i){
		contadorAristas += vertices[i]->adyacencias.size();
	}
	return contadorAristas == cantidadComplementaria;
}

int stdgraph::Grafo::ObtenerGrado(IRG::VertexId vertice){
    IRG::Vertice *verticeActual = ObtenerVertice(vertice);
    int grado = verticeActual->adyacencias.size();
    return (tipo == IRG::NoDirigido ? grado * 2 : grado);
}

IRG::TipoGrafo stdgraph::Grafo::ObtenerTipo(){
    return this->tipo;
}

//GeneradorGrafos
stdgraph::Grafo* stdgraph::Grafo::ObtenerUnion(const Grafo* grafo1, const Grafo* grafo2){
    ASSERT
}

char * stdgraph::Grafo::ObtenerVertices(){
    char *sucesionGrafica = new char;
	for(int i=0; i<cantidadVertices; ++i)	{
        IRG::Vertice *verticeActual = ObtenerVertice(this->vertices[i]->vertexId);
		if(verticeActual!=NULL && i==0) {
            sprintf(sucesionGrafica, "%s",verticeActual->etiqueta);
        }else{
            sprintf(sucesionGrafica, "%s,%s",sucesionGrafica,verticeActual->etiqueta);
        }
	}
	return sucesionGrafica;
}

char * stdgraph::Grafo::ObtenerAristas(const Grafo* grafo){
    ASSERT
    return "";
}

int stdgraph::Grafo::ObtenerAdyacencia(Grafo* grafo, int verticeOrigen, int indiceAdyacencia){
    ASSERT
    return -1;
}

void stdgraph::Grafo::DestruirGrafo(Grafo* grafo){
    ASSERT
}

char * stdgraph::Grafo::ObtenerSucesionGrafica(){
    ASSERT
    return "";
}

bool stdgraph::Grafo::ContieneAdyacencia(int verticeOrigen, int verticeAdyacente){
    ASSERT
    return false;
}

char * stdgraph::Grafo::ObtenerEtiqueta(int vertice){
    ASSERT
    return "";
}

char * stdgraph::Grafo::ObtenerEtiquetaOClave(int verticeABuscar){
    ASSERT
    return "";
}

bool stdgraph::Grafo::ExisteVertice(IRG::VertexId vertice){
    IRG::Vertice *v = ObtenerVertice(vertice);
    return v != NULL;
}


//Funciones privadas:

IRG::Vertice* stdgraph::Grafo::CrearVertice(IRG::Nodo* nuevoNodo, IRG::VertexId id){
    IRG::Vertice* nuevoVertice = new IRG::Vertice;
    nuevoVertice->vertexId  = id;
    nuevoVertice->nodo      = nuevoNodo;
    nuevoVertice->etiqueta  = IRG::VertexIdToChar(id);
    return nuevoVertice;
}

IRG::Vertice* stdgraph::Grafo::ObtenerVertice(IRG::VertexId id){
    int cantidadVertices = vertices.size();
    for(int verticeActual = 0; verticeActual<cantidadVertices; verticeActual++) {
        if(vertices[verticeActual]->vertexId == id){
            return vertices[verticeActual];
        }
    }
    return NULL;
}

bool stdgraph::Grafo::Contiene(IRG::Vertice* vertice, IRG::VertexId verticeAdyacente){
    if(vertice->adyacencias.empty()) return false;
    IRG::Adyacencias::const_iterator iterador = vertice->adyacencias.begin();
    bool contiene = false;
    while(iterador != vertice->adyacencias.end() && !contiene){
        contiene = *iterador == verticeAdyacente;
        iterador++;
    }
    return contiene;
}

IRG::Status stdgraph::Grafo::AgregarEtiqueta(IRG::VertexId etiqueta){
    ASSERT
    return IRG::Error;
}

IRG::Status stdgraph::Grafo::AgregarEtiqueta(IRG::VertexId verticeId, IRG::TipoEtiqueta etiquetado, char * etiqueta){
    ASSERT
    return IRG::Error;
}
