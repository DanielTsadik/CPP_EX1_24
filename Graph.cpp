// Graph.cpp
#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel
{
    bool isSimetric(std::vector<vector<size_t>> &matrix)
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

    

    void Graph::printGraph() const
    {
        int edges = 0;
        for (size_t i = 0; i < this->adjacencyMatrix.size(); i++)
        {
            for (size_t j = 0; j < this->adjacencyMatrix[i].size(); j++)
            {
                if (this->adjacencyMatrix[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        if (this->isDirected)
        {
            cout << "The graph is directed " << this->vertices << " vertices and " << edges << " edges." << endl;
        }
        else
        {
            cout << "The graph is not directed " << this->vertices << " vertices and " << edges / 2 << " edges." << endl;
        }
    }

    bool Graph::getIsDirected() const
    {
        return this->isDirected;
    }

    bool Graph::getIsWeighted() const
    {
        return this->isWeighted;
    }

    size_t Graph::getnumVertices() const
    {
        return this->vertices;
    }

    const std::vector<std::vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return this->adjacencyMatrix;
    }

    bool Graph::isAdjacent(size_t vertex1, size_t vertex2) const
    {
        if (vertex1 < 0 || vertex1 >= this->vertices || vertex2 < 0 || vertex2 >= this->vertices)
        {
            throw invalid_argument("Invalid vertex: The vertex is out of range.");
        }
        return this->adjacencyMatrix[vertex1][vertex2] != 0;
    }

}