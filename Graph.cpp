#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace ariel {

    Graph::Graph() : vertices(0), edges(0) {}

    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
        // Check if the graph is a square matrix
        size_t size = graph.size(); // Change int to size_t
        for (size_t i = 0; i < size; ++i) { // Change int to size_t
            if (graph[i].size() != size) { // Change int to size_t
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        // Load the graph
        adjacencyMatrix = graph;
        vertices = size;

        // Calculate the number of edges
        edges = 0;
        for (size_t i = 0; i < size; ++i) { // Change int to size_t
            for (size_t j = i + 1; j < size; ++j) { // Change int to size_t
                if (adjacencyMatrix[i][j] != 0) {
                    edges++;
                }
            }
        }
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << vertices << " vertices and " << edges << " edges." << std::endl;
    }

    int Graph::getVertices() const { // Change return type to size_t
        return vertices; // Change return type to size_t
    }

    int Graph::getEdges() const { // Change return type to size_t
        return edges; // Change return type to size_t
    }

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

} // namespace ariel
