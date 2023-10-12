#pragma once
#include <cstring>


namespace toha {

template<class T>
Node<T>::Node(const T& value) : value(value) {}


template<class T>
void Node<T>::connect(Node<T>* node) {
    adjacent.push_back(node);
}

template<class T>
T Node<T>::getValue() const {
    return value;
}

template<class T>
std::list<Node<T>*> Node<T>::getAdjacentNodes() const {
    return adjacent;
}

template<class T>
std::string Node<T>::getAdjacentNodeRepresentations() {
  std::string nodes = "";
  for (Node<T>* n: this->adjacent) {
    nodes += "(";
    nodes += std::to_string(this->value);
    nodes += ", ";
    nodes += std::to_string(n->getValue());
    nodes += ")";
    if (n != adjacent.back()) {
      nodes += ", ";
    }
  }
  return nodes;
}

template <class T>
bool Node<T>::isEqual(const Node<T>* otherNode, size_t size) {
    // Comprueba que los punteros no sean nulos y que el tamaño sea válido
    if (otherNode == nullptr) {
        return false;
    }

    // Compara los bloques de memoria byte a byte
    return std::memcmp(this, otherNode, size) == 0;
}
}