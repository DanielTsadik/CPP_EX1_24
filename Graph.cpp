// Daniel Tsadik	
// ID: 209307727	
// Mail: tsadik88@gmail.com

// Graph.cpp
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel
{
    /**
     * @brief Checks if a given matrix is symmetric.
     * 
     * @param matrix The matrix to check for symmetry.
     * @return true if the matrix is symmetric, false otherwise.
     */
    bool ariel::Graph::isSimetric(std::vector<std::vector<int>> &matrix) const
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * @brief Loads the graph from a given adjacency matrix.
     * 
     * @param matrix The adjacency matrix representing the graph.
     */
    void Graph::loadGraph(std::vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            throw invalid_argument("Invalid graph: The graph is empty.");
        }
        if (isSimetric(matrix))
        {
            this->isDirected = false;
        }
        else
        {
            this->isDirected = true;
        }
        // Check if the matrix is square
        for (size_t i = 0; i < matrix.size(); i++)
        {
            if (matrix.size() != matrix[i].size())
            {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        this->adjacencyMatrix = matrix;
        this->vertices = matrix.size();
    }

    /**
     * @brief Prints information about the graph.
     */
    void Graph::printGraph() const
    {
        int num_edges = 0;
        for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j)
            {
                if (this->adjacencyMatrix[i][j] != 0)
                {
                    if (!this->isDirected && i < j) // For undirected graphs, count each edge only once
                    {
                        ++num_edges;
                    }
                    else if (this->isDirected) // For directed graphs, count all edges
                    {
                        ++num_edges;
                    }
                }
            }
        }
        if (this->isDirected)
        {
            std::cout << "The graph is directed " << this->vertices << " vertices and " << num_edges << " edges." << std::endl;
        }
        else
        {
            std::cout << "The graph is not directed " << this->vertices << " vertices and " << num_edges << " edges." << std::endl;
        }
    }

    /**
     * @brief Returns whether the graph is directed.
     * 
     * @return true if the graph is directed, false otherwise.
     */
    bool Graph::getIsDirected() const
    {
        return this->isDirected;
    }

    /**
     * @brief Returns whether the graph is weighted.
     * 
     * @return true if the graph is weighted, false otherwise.
     */
    bool Graph::getIsWeighted() const
    {
        return this->isWeighted;
    }

    /**
     * @brief Returns the number of vertices in the graph.
     * 
     * @return The number of vertices.
     */
    size_t Graph::getnumVertices() const
    {
        return this->vertices;
    }

    /**
     * @brief Returns a constant reference to the adjacency matrix of the graph.
     * 
     * @return A constant reference to the adjacency matrix.
     */
    const std::vector<std::vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return this->adjacencyMatrix;
    }

    /**
     * @brief Checks if two vertices are adjacent.
     * 
     * @param vertex1 The first vertex.
     * @param vertex2 The second vertex.
     * @return true if the vertices are adjacent, false otherwise.
     */
    bool Graph::isAdjacent(size_t vertex1, size_t vertex2) const
    {
        if (vertex1 < 0 || vertex1 >= this->vertices || vertex2 < 0 || vertex2 >= this->vertices)
        {
            throw invalid_argument("Invalid vertex: The vertex is out of range.");
        }
        return this->adjacencyMatrix[vertex1][vertex2] != 0;
    }

}
