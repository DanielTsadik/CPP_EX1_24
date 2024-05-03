#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel {

    /**
     * @brief A class representing a graph using an adjacency matrix.
     */
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix; ///< Adjacency matrix representing the graph
        int vertices; ///< Number of vertices in the graph
        int edges; ///< Number of edges in the graph

    public:
        /**
         * @brief Default constructor for the Graph class.
         * Initializes the graph with zero vertices and edges.
         */
        Graph();

        /**
         * @brief Loads a graph from the given adjacency matrix.
         * @param graph The adjacency matrix representing the graph.
         * @throw std::invalid_argument if the input matrix is not square.
         */
        void loadGraph(const std::vector<std::vector<int>>& graph);

        /**
         * @brief Prints information about the graph.
         */
        void printGraph() const;

        /**
         * @brief Gets the number of vertices in the graph.
         * @return The number of vertices.
         */
        int getVertices() const;

        /**
         * @brief Gets the number of edges in the graph.
         * @return The number of edges.
         */
        int getEdges() const;

        /**
         * @brief Gets the adjacency matrix of the graph.
         * @return The adjacency matrix.
         */
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
    };

}

#endif // GRAPH_HPP
