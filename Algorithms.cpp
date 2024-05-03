#include "Algorithms.hpp"
#include <iostream>
#include <queue>
#include <limits>
#include <sstream>

namespace ariel {

    bool Algorithms::isConnected(const Graph& graph) {
        const std::vector<std::vector<int>>& adjMatrix = graph.getAdjacencyMatrix();
        int size = graph.getVertices(); // Change int to size_t

        std::vector<bool> visited(size, false);
        std::queue<int> q;

        q.push(0); // Start from vertex 0
        visited[0] = true;

        while (!q.empty()) {
            int current_vertex = q.front();
            q.pop();

            // Visit all neighbors of the current vertex
            for (size_t neighbor = 0; neighbor < size; ++neighbor) { // Change int to size_t
                if (adjMatrix[current_vertex][neighbor] != 0 && !visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        // Check if all vertices are visited
        for (bool v : visited) {
            if (!v) return false; // Graph is not connected
        }

        return true; // Graph is connected
    }

    std::string Algorithms::shortestPath(const Graph& graph, int start, int end) {
        const std::vector<std::vector<int>>& adjMatrix = graph.getAdjacencyMatrix();
        size_t size = graph.getVertices();

        std::vector<int> dist(size, std::numeric_limits<int>::max());
        std::vector<int> pred(size, -1);

        dist[start] = 0;

        for (size_t i = 0; i < size - 1; ++i) { // Change int to size_t
            for (size_t u = 0; u < size; ++u) { // Change int to size_t
                for (size_t v = 0; v < size; ++v) { // Change int to size_t
                    if (adjMatrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() &&
                        dist[u] + adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjMatrix[u][v];
                        pred[v] = u;
                    }
                }
            }
        }

        for (size_t u = 0; u < size; ++u) { // Change int to size_t
            for (size_t v = 0; v < size; ++v) { // Change int to size_t
                if (adjMatrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    std::cout << "Negative cycle detected" << std::endl;
                    return "-1";
                }
            }
        }

        std::vector<int> path;
        for (int i = end; i != -1; i = pred[i]) {
            path.push_back(i);
        }

        if (dist[end] == std::numeric_limits<int>::max()) {
            return "-1";
        }

        std::stringstream result;
        for (int i = path.size() - 1; i > 0; --i) {
            result << path[i] << " -> ";
        }
        result << path[0];

        return result.str();
    }

    // bool Algorithms::isContainsCycle(const Graph& graph) {
    //     const std::vector<std::vector<int>>& adjMatrix = graph.getAdjacencyMatrix();
    //     size_t size = graph.getVertices();

    //     std::vector<bool> visited(size, false);
    //     std::vector<bool> recStack(size, false);

    //     for (size_t i = 0; i < size; ++i) { // Change int to size_t
    //         if (!visited[i] && isCyclicUtil(i, visited, recStack, adjMatrix)) {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    // bool Algorithms::isCyclicUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack, const std::vector<std::vector<int>>& adjMatrix) {
    //     if (!visited[v]) {
    //         visited[v] = true;
    //         recStack[v] = true;

    //         for (size_t i = 0; i < adjMatrix.size(); ++i) { // Change int to size_t
    //             if (adjMatrix[v][i] != 0) {
    //                 if (!visited[i] && isCyclicUtil(i, visited, recStack, adjMatrix)) {
    //                     return true;
    //                 } else if (recStack[i]) {
    //                     std::cout << "Cycle detected: ";
    //                     for (int j = i; j != v; j = pred[j]) {
    //                         std::cout << j << " <- ";
    //                     }
    //                     std::cout << v << std::endl;
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     recStack[v] = false;
    //     return false;
    // }

    std::string Algorithms::negativeCycle(const Graph& graph) {
        const std::vector<std::vector<int>>& adjMatrix = graph.getAdjacencyMatrix();
        size_t size = graph.getVertices();

        std::vector<int> dist(size, std::numeric_limits<int>::max());
        std::vector<int> pred(size, -1);

        dist[0] = 0;

        for (size_t i = 0; i < size - 1; ++i) { // Change int to size_t
            for (size_t u = 0; u < size; ++u) { // Change int to size_t
                for (size_t v = 0; v < size; ++v) { // Change int to size_t
                    if (adjMatrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() &&
                        dist[u] + adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjMatrix[u][v];
                        pred[v] = u;
                    }
                }
            }
        }

        for (size_t u = 0; u < size; ++u) { // Change int to size_t
            for (size_t v = 0; v < size; ++v) { // Change int to size_t
                if (adjMatrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    std::stringstream cycle;
                    cycle << "Negative cycle detected: ";
                    int temp = v;
                    while (!cycle.str().find(std::to_string(temp))) {
                        cycle << temp << " <- ";
                        temp = pred[temp];
                    }
                    cycle << temp;
                    return cycle.str();
                }
            }
        }

        return "No negative cycle found.";
    }

    std::string Algorithms::isBipartite(const Graph& graph) {
        const std::vector<std::vector<int>>& adjMatrix = graph.getAdjacencyMatrix();
        size_t size = graph.getVertices();

        std::vector<int> color(size, -1); // Initialize all vertices as uncolored
        std::queue<int> q;

        // Start BFS from vertex 0
        q.push(0);
        color[0] = 1; // Color first vertex with first color

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Find all non-colored adjacent vertices and color them
            for (size_t v = 0; v < size; ++v) { // Change int to size_t
                if (adjMatrix[u][v] != 0 && color[v] == -1) {
                    color[v] = 1 - color[u]; // Assign alternate color to this adjacent vertex
                    q.push(v);
                } else if (adjMatrix[u][v] != 0 && color[u] == color[v]) {
                    // If adjacent vertices have the same color, the graph is not bipartite
                    std::stringstream result;
                    result << "The graph is not bipartite: Cycle detected with vertices " << u << " and " << v;
                    return result.str();
                }
            }
        }

        // If BFS is complete without any odd cycle, the graph is bipartite
        std::vector<int> groupA, groupB;
        for (size_t i = 0; i < size; ++i) { // Change int to size_t
            if (color[i] == 0) {
                groupA.push_back(i);
            } else {
                groupB.push_back(i);
            }
        }

        std::stringstream result;
        result << "The graph is bipartite: A={";
        for (size_t i = 0; i < groupA.size(); ++i) { // Change int to size_t
            result << groupA[i];
            if (i != groupA.size() - 1) {
                result << ", ";
            }
        }
        result << "}, B={";
        for (size_t i = 0; i < groupB.size(); ++i) { // Change int to size_t
            result << groupB[i];
            if (i != groupB.size() - 1) {
                result << ", ";
            }
        }
        result << "}";
        return result.str();
    }

} // namespace ariel
