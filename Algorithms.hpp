// Algorithms.hpp
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"
#include <vector>
#include <string>
#include <stack>


namespace ariel {
    class Algorithms {
        private:
            static void DFS(const Graph& g, size_t v, std::vector<bool>& visited);
            static bool DFSCycle(const Graph& g, size_t v, std::vector<bool>& visited, std::vector<size_t>& parent, std::deque<int>& cycle); // Change stack to deque
            static bool isBipartiteUtil(const Graph& g, size_t v, std::vector<int>& color);
            static std::string negativeCycleUtil(const Graph& g, size_t source);

        public:
            static bool isConnected(Graph& g);
            static std::string shortestPath(Graph& g, size_t source, size_t destination);
            static bool isContainsCycle(Graph& g);
            static std::string isBipartite(Graph& g);
            static std::string negativeCycle(Graph& g);

    };
}

#endif 