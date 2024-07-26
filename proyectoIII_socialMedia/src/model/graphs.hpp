#ifndef GRAF_H
#define GRAF_H

#include <iostream>
#include <climits>
#include "queve.hpp"

using namespace std;

template <class T>
class Graph {
private:
    int numVertices; // número de vértices del grafo
    int** adjMatrix; // matriz de adyacencia del grafo
    T* vertices;
    int currentVertexCount;

public:
    Graph(int numVertices);
    ~Graph();
    void addVertex(T vertex);
    T getVertex(int index);
    int getIndex(T vertex);
    void addEdge(int start, int end, int weight);
    void removeEdge(int start, int end);
    int* shortestPath(int start, int end, int &pathLength);
};

#endif