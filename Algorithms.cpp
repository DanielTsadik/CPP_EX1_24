// Algorithms.cpp
#include "Algorithms.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <deque>
#include <queue>

using namespace std;

namespace ariel
{
    void Algorithms::DFS(const Graph &g, size_t v, std::vector<bool> &visited)
    {
        visited[static_cast<std::vector<bool>::size_type>(v)] = true;
        const std::vector<std::vector<int>> &matrix = g.getAdjacencyMatrix();

        for (size_t i = 0; i < g.getnumVertices(); i++)
        {
            if (matrix[v][i] != 0 && !visited[i])
            {
                DFS(g, i, visited);
            }
        }
    }

    bool Algorithms::isConnected(Graph &g)
    {
        size_t vertices = g.getnumVertices();
        std::vector<bool> visited(vertices, false);

        DFS(g, 0, visited);

        for (size_t i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }

        if (g.getIsDirected())
        {
            for (size_t i = 1; i < vertices; i++)
            {
                visited = std::vector<bool>(vertices, false);
                DFS(g, i, visited);
                for (size_t j = 0; j < vertices; j++)
                {
                    if (!visited[j])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    string shortestPath(const Graph &g, size_t source, size_t destination)
    {
        size_t V = g.getnumVertices();
        vector<size_t> distances(V, INT_MAX);
        vector<size_t> parent(V, (size_t)-1);
        distances[source] = 0;

        for (size_t i = 1; i <= V - 1; i++)
        {
            for (size_t u = 0; u < V; u++)
            {
                for (size_t v = 0; v < V; v++)
                {
                    if (g.getAdjacencyMatrix()[u][v] != 0 && distances[u] != INT_MAX && distances[u] + (size_t)g.getAdjacencyMatrix()[u][v] < distances[v])
                    {
                        distances[v] = distances[u] + (size_t)g.getAdjacencyMatrix()[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        for (size_t u = 0; u < V; u++)
        {
            for (size_t v = 0; v < V; v++)
            {
                if (g.getAdjacencyMatrix()[u][v] != 0 && distances[u] != INT_MAX && distances[u] + (size_t)g.getAdjacencyMatrix()[u][v] < distances[v])
                {
                    cout << "Graph contains a negative-weight cycle" << endl;
                    return "-1";
                }
            }
        }

        if (distances[destination] == INT_MAX)
        {
            return "-1";
        }

        string path;
        for (size_t v = destination; v != -1; v = parent[v])
        {
            path = to_string(v) + (path.empty() ? "" : "->" + path);
        }

        return path;
    }

    bool Algorithms::DFSCycle(const Graph &g, size_t v, vector<bool> &visited, vector<size_t> &parent, deque<int> &cycle)
    {
        visited[v] = true;
        cycle.push_front(v);

        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        for (size_t u = 0; u < g.getnumVertices(); u++)
        {
            if (matrix[v][u] != 0)
            {
                if (!visited[u])
                {
                    parent[u] = v;
                    if (DFSCycle(g, u, visited, parent, cycle))
                    {
                        return true;
                    }
                }
                else if (parent[v] != u)
                {
                    // Found a cycle. Print the cycle.
                    string cycle_str = "";
                    for (int x : cycle)
                    {
                        cycle_str += "->" + to_string(x);
                    }
                    cycle_str = cycle_str.substr(2); // Remove the leading "->".
                    cout << "The cycle is: " + cycle_str << endl;
                    return true;
                }
            }
        }

        cycle.pop_front();
        return false;
    }

    bool Algorithms::isContainsCycle(Graph &g)
    {
        size_t V = g.getnumVertices();
        vector<bool> visited(V, false);
        vector<size_t> parent(V,(size_t)-1);
        deque<int> cycle;

        for (size_t v = 0; v < V; v++)
        {
            if (!visited[v] && DFSCycle(g, v, visited, parent, cycle))
            {
                cout << endl; // Print a newline character after printing the cycle.
                return true;
            }
        }

        return false;
    }

    bool Algorithms::isBipartiteUtil(const Graph& g, size_t v, std::vector<int>& color) {
        color[v] = 1; // Color first vertex as 1
        std::queue<size_t> q;
        q.push(v);

        while (!q.empty()) {
            size_t u = q.front();
            q.pop();

            // Self loop, not bipartite
            if (g.getAdjacencyMatrix()[u][u] != 0) {
                return false;
            }

            for (size_t v = 0; v < g.getnumVertices(); v++) {
                // An edge from u to v exists and destination v is not colored
                if (g.getAdjacencyMatrix()[u][v] && color[v] == -1) {
                    // Assign alternate color to this adjacent v of u
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                // An edge from u to v exists and destination v is colored with same color as u
                else if (g.getAdjacencyMatrix()[u][v] && color[v] == color[u]) {
                    return false;
                }
            }
        }

        return true;
    }

    std::string Algorithms::isBipartite(Graph& g) {
        std::vector<int> color(g.getnumVertices(), -1); // Initialize all vertices as not colored (-1)

        for (size_t i = 0; i < g.getnumVertices(); i++) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(g, i, color)) {
                    return "0";
                }
            }
        }

        std::string setA = "A={";
        std::string setB = "B={";
        for (size_t i = 0; i < color.size(); i++) {
            if (color[i] == 1) {
                setA += std::to_string(i) + ", ";
            } else {
                setB += std::to_string(i) + ", ";
            }
        }
        setA = setA.substr(0, setA.length() - 2) + "}";
        setB = setB.substr(0, setB.length() - 2) + "}";

        return "The graph is bipartite: " + setA + ", " + setB;
    }

    std::string Algorithms::negativeCycleUtil(const Graph& g, size_t source) {
        size_t numVertices = g.getnumVertices();
        std::vector<size_t> distance(numVertices, std::numeric_limits<int>::max());
        std::vector<size_t> predecessor(numVertices, (size_t)-1);
        distance[source] = 0;

        // Relax all edges numVertices - 1 times
        for (size_t i = 1; i <= numVertices - 1; i++) {
            for (size_t u = 0; u < numVertices; u++) {
                for (size_t v = 0; v < numVertices; v++) {
                    if (g.getAdjacencyMatrix()[u][v] && distance[u] != std::numeric_limits<int>::max() && distance[u] + (size_t)g.getAdjacencyMatrix()[u][v] < distance[v]) {
                        distance[v] = distance[u] + (size_t)g.getAdjacencyMatrix()[u][v];
                        predecessor[v] = u;
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (size_t u = 0; u < numVertices; u++) {
            for (size_t v = 0; v < numVertices; v++) {
                if (g.getAdjacencyMatrix()[u][v] && distance[u] != std::numeric_limits<int>::max() && distance[u] + (size_t)g.getAdjacencyMatrix()[u][v] < distance[v]) {
                    // Negative cycle found, construct cycle
                    std::vector<int> cycle;
                    for (size_t v = u; ; v = predecessor[v]) {
                        cycle.push_back(v);
                        if (v == u && cycle.size() > 1) {
                            break;
                        }
                    }
                    std::reverse(cycle.begin(), cycle.end());

                    std::string cycleStr = "Negative cycle: ";
                    for (int v : cycle) {
                        cycleStr += std::to_string(v) + " ";
                    }
                    return cycleStr;
                }
            }
        }

        return "No negative cycle";
    }

    std::string Algorithms::negativeCycle(Graph& g) {
        for (size_t i = 0; i < g.getnumVertices(); i++) {
            std::string result = negativeCycleUtil(g, i);
            if (result != "No negative cycle") {
                return result;
            }
        }
        return "No negative cycle";
    }
}