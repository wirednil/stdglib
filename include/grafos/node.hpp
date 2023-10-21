#pragma once

#include <iostream>
#include <list>

namespace toha {
/**
 * @brief Represents a node in a graph.
 *
 * This class represents a node in a graph. It stores a value of type T
 * and can have edges (connections) to other nodes in the graph.
 *
 * @tparam T The type of value stored in the node.
 */
template <class T>
class Node {
public:

    /**
     * @brief Constructs a new Node with the specified value.
     *
     * @param value The value to be stored in the node.
     */
    Node(const T& value);

    ~Node();

    /**
     * @brief connect to another node.
     *
     * @param node A pointer to the node to which an edge is added.
     */
    void connect(Node<T>* node) ;

    /**
     * @brief Gets the value stored in the node.
     *
     * @return The value stored in the node.
     */
    T getValue() const;

    /**
     * @brief Gets a list of pointers to adjacent nodes.
     *
     * @return A list of pointers to nodes that are adjacent to this node.
     */
    std::list<Node<T>*> getAdjacentNodes() const ;

    // static Node<T>* search(const T& val);
    std::string getAdjacentNodeRepresentations();

    bool isEqual(const Node<T>* otherNode, size_t size);

private:
    T value;                      ///< The value stored in the node.
    std::list<Node<T>*> adjacent; ///< A list of pointers to adjacent nodes.
};

}

#include "../../src/grafos/node.tpp"