#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
using namespace std;
namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        bool isDirected;
        bool isWeighted;
        size_t vertices;
        int matrixsize;

    public:
        bool isSimetric(std::vector<std::vector<int>> &matrix) const;
        void loadGraph(std::vector<std::vector<int>> &matrix);
        void printGraph() const;
        bool getIsDirected() const;
        bool getIsWeighted() const;
        bool isAdjacent(size_t vertex1, size_t vertex2) const;
        size_t getnumVertices() const;
        const std::vector<std::vector<int>> &getAdjacencyMatrix() const;
    };
}
#endif // GRAPH_HPP