// Daniel Tsadik	
// ID: 209307727	
// Mail: tsadik88@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel
{
    /**
     * @brief Represents a graph data structure.
     */
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix; /**< Adjacency matrix of the graph. */
        bool isDirected; /**< Indicates whether the graph is directed. */
        bool isWeighted; /**< Indicates whether the graph is weighted. */
        size_t vertices; /**< Number of vertices in the graph. */
        int matrixsize; /**< Size of the adjacency matrix. */

    public:
        /**
         * @brief Checks if a given matrix is symmetric.
         * 
         * @param matrix The matrix to check for symmetry.
         * @return true if the matrix is symmetric, false otherwise.
         */
        bool isSimetric(std::vector<std::vector<int>> &matrix) const;

        /**
         * @brief Loads the graph from a given adjacency matrix.
         * 
         * @param matrix The adjacency matrix representing the graph.
         */
        void loadGraph(std::vector<std::vector<int>> &matrix);

        /**
         * @brief Prints the adjacency matrix of the graph.
         */
        void printGraph() const;

        /**
         * @brief Returns whether the graph is directed.
         * 
         * @return true if the graph is directed, false otherwise.
         */
        bool getIsDirected() const;

        /**
         * @brief Returns whether the graph is weighted.
         * 
         * @return true if the graph is weighted, false otherwise.
         */
        bool getIsWeighted() const;

        /**
         * @brief Checks if two vertices are adjacent.
         * 
         * @param vertex1 The first vertex.
         * @param vertex2 The second vertex.
         * @return true if the vertices are adjacent, false otherwise.
         */
        bool isAdjacent(size_t vertex1, size_t vertex2) const;

        /**
         * @brief Returns the number of vertices in the graph.
         * 
         * @return The number of vertices.
         */
        size_t getnumVertices() const;

        /**
         * @brief Returns a constant reference to the adjacency matrix of the graph.
         * 
         * @return A constant reference to the adjacency matrix.
         */
        const std::vector<std::vector<int>> &getAdjacencyMatrix() const;
    };
}

#endif // GRAPH_HPP
