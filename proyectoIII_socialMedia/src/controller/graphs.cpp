#include "../model/graphs.hpp"

template <class T>
Graph<T>::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    vertices = new T[numVertices];
    currentVertexCount = 0;
}

template <class T>
Graph<T>::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] vertices;
}

template <class T>
void Graph<T>::addVertex(T vertex) {
    if (currentVertexCount < numVertices) {
        vertices[currentVertexCount++] = vertex;
    }
}

template <class T>
T Graph<T>::getVertex(int index) {
    if (index >= 0 && index < currentVertexCount) {
        return vertices[index];
    }
    return T();
}

template <class T>
int Graph<T>::getIndex(T vertex) {
    for (int i = 0; i < currentVertexCount; i++) {
        if (vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

template <class T>
void Graph<T>::addEdge(int start, int end, int weight) {
    if (start >= 0 && start < numVertices && end >= 0 && end < numVertices) {
        adjMatrix[start][end] = weight;
    }
}

template <class T>
void Graph<T>::removeEdge(int start, int end) {
    if (start >= 0 && start < numVertices && end >= 0 && end < numVertices) {
        adjMatrix[start][end] = 0;
    }
}

template <class T>
int* Graph<T>::shortestPath(int start, int end, int &pathLength) {
    int* dist = new int[numVertices];
    int* prev = new int[numVertices];
    bool* visited = new bool[numVertices];
    Queue<int> q;

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;
    q.push(start);

    while (!q.isEmpty()) {
        int u = q.pop();
        visited[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] != 0 && !visited[v]) {
                int alt = dist[u] + adjMatrix[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    q.push(v);
                }
            }
        }
    }

    // Reconstruir el camino
    int* path = new int[numVertices];
    pathLength = 0;
    for (int at = end; at != -1; at = prev[at]) {
        path[pathLength++] = at;
    }

    // Invertir el camino
    for (int i = 0; i < pathLength / 2; i++) {
        int temp = path[i];
        path[i] = path[pathLength - 1 - i];
        path[pathLength - 1 - i] = temp;
    }

    delete[] dist;
    delete[] prev;
    delete[] visited;

    return path;
}