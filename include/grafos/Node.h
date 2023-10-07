// #ifndef __NODE_H__
// #define __NODE_H__
// #include "Grafos.h"

// #include <iostream>
// #include <list>

// /**
//  * @brief Represents a node in a graph.
//  *
//  * This class represents a node in a graph. It stores a value of type T
//  * and can have edges (connections) to other nodes in the graph.
//  *
//  * @tparam T The type of value stored in the node.
//  */
// template <class T>
// class Node {
// public:

//     /**
//      * @brief Constructs a new Node with the specified value.
//      *
//      * @param value The value to be stored in the node.
//      */
//     Node(const T& value);

//     /**
//      * @brief connect to another node.
//      *
//      * @param node A pointer to the node to which an edge is added.
//      */
//     void connect(const Node<T>* node) ;

//     /**
//      * @brief Gets the value stored in the node.
//      *
//      * @return The value stored in the node.
//      */
//     T getValue() const;

//     /**
//      * @brief Gets a list of pointers to adjacent nodes.
//      *
//      * @return A list of pointers to nodes that are adjacent to this node.
//      */
//     std::list<Node<T>*> getAdjacentNodes() const ;

//     // static Node<T>* search(const T& val);

// private:
//     T value;                      ///< The value stored in the node.
//     std::list<Node<T>*> adjacent; ///< A list of pointers to adjacent nodes.
// };

// #endif //__NODE_H__