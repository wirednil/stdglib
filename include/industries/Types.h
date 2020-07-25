#ifndef _TYPES_H_
#define _TYPES_H_

#include <vector>
#include <list>

/**
 * @brief Industries Repository Graph
 */
namespace IRG
{
	struct Nodo;

	struct Vertice;
	
	enum TipoGrafo
	{
		/** @brief A directed graph or digraph is a 
		 * type of graph in which the edges 
		 * have a defined meaning. */
		Dirigido   = (1<<1),

		/**
		 * @brief A non-directed graph is a type of 
		 * graph in which the edges are symmetrical 
		 * relationships and do not point in any direction. */
		NoDirigido = (1<<2)
	};

	enum TipoEtiqueta
	{
		Simple	=	(1 << 3),
		Propia	=	(1 << 4)
	};

	enum Status{
		Ok 		=  1,
		Error 	= -1
	};

	typedef unsigned long long VertexId;
	typedef std::vector<Vertice*> Vertices;
	typedef std::list<VertexId> Adyacencias;
}

#endif /*_TYPES_H_*/
