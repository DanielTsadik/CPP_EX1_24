#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>

namespace ariel {

    /**
     * @brief Algorithms class containing functions for graph algorithms.
     */
    class Algorithms {
    public:
        /**
         * @brief Checks if a graph is connected.
         * 
         * @param graph The graph to be checked.
         * @return true if the graph is connected, otherwise false.
         */
        static bool isConnected(const Graph& graph);

        /**
         * @brief Finds the shortest path between two vertices in a graph.
         * 
         * @param graph The graph to search for the path.
         * @param start The starting vertex.
         * @param end The ending vertex.
         * @return A string representing the shortest path between the vertices.
         */
        static std::string shortestPath(const Graph& graph, int start, int end);

        /**
         * @brief Checks if a graph contains a cycle.
         * 
         * @param graph The graph to be checked.
         * @return true if the graph contains a cycle, otherwise false.
         */
        static bool isContainsCycle(const Graph& graph);

        /**
         * @brief Checks if a graph is bipartite.
         * 
         * @param graph The graph to be checked.
         * @return A string indicating whether the graph is bipartite or not.
         */
        static std::string isBipartite(const Graph& graph);

        /**
         * @brief Finds a negative cycle in a graph (if exists).
         * 
         * @param graph The graph to be checked.
         * @return A string representing the negative cycle path if found, otherwise a message indicating no negative cycle found.
         */
        static std::string negativeCycle(const Graph& graph);
    };

}

#endif // ALGORITHMS_HPP
