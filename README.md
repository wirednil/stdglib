# Graph Library

This C++ library provides a flexible implementation of directed and non-directed graphs, complete with vertices and edges. It allows you to work with graph data structures efficiently.

## Introduction

A graph is a mathematical structure that represents a collection of objects and the relationships between them. In this library, we provide two types of graphs:

1. **Directed Graph**: In a directed graph, edges have a defined direction, meaning they go from one vertex to another.

2. **Non-Directed Graph**: In a non-directed graph, edges represent symmetric relationships and do not have a specific direction.

## Usage

To use this library, follow the instructions below:

### Include the Library

```cpp
#include "graph.hpp"
```

### Create a Graph

You can create a graph object of your desired type (directed or non-directed) and specify a name for it:

```cpp
toha::graph<int> myGraph(0, "MyGraphName", NON_DIRECTED_GRAPH);
```

### Add Vertices

You can add vertices to your graph using the `add` method:

```cpp
int vertexValue = 42;
myGraph.add(vertexValue);
```

### Show Vertices

You can display the vertices of the graph using the `showVertices` method:

```cpp
myGraph.showVertices();
```

### Get and Set Graph Name

You can get the name of the graph using the `getName` method:

```cpp
std::string name = myGraph.getName();
```

You can also set a name for the graph using the `setName` method:

```cpp
myGraph.setName("NewGraphName");
```

### Author

This library was authored by J. Diógenes Cristaldo Cañiza on 09/06/2020.

### License

This code is provided under an open-source license. Feel free to use and modify it according to your needs.

Enjoy using the graph library! If you have any questions or encounter any issues, please feel free to create an issue on the GitHub repository.
