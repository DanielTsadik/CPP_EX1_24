#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

// Test cases for the isConnected function
TEST_CASE("Test isConnected")
{
    ariel::Graph g;

    // Test 1: Graph with all vertices connected
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test 2: Graph with some vertices disconnected
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test 3: Weighted directed graph
    vector<vector<int>> graph3 = {
        {0, 2, 0},
        {3, 0, 1},
        {0, 4, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test 4: Weighted undirected graph
    vector<vector<int>> graph4 = {
        {0, 2, 3},
        {2, 0, 4},
        {3, 4, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test 5: Unconnected weighted undirected graph
    vector<vector<int>> graph5 = {
        {0, 5, 6, 0, 0},
        {5, 0, 7, 0, 0},
        {6, 7, 0, 8, 0},
        {0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

// Test cases for the shortestPath function
TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    // Test 1: Shortest path from 0 to 2 in a connected graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Test 2: No path from 0 to 4 in a disconnected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Test 3: Shortest path from 1 to 2 in a weighted directed graph
    vector<vector<int>> graph3 = {
        {0, 2, 0},
        {3, 0, 1},
        {0, 4, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "1->2");

    // Test 4: No path from 0 to 4 in a weighted undirected graph
    vector<vector<int>> graph4 = {
        {0, 2, 0, 0, 0},
        {2, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Test 5: Shortest path from 0 to 2 in an unweighted directed graph
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Test 6: Shortest path from 0 to 3 in a connected graph
    vector<vector<int>> graph6 = {
        {0, 5, 6, 0, 0},
        {5, 0, 7, 0, 0},
        {6, 7, 0, 8, 0},
        {0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");
}

// Test cases for the isContainsCycle function
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;

    // Test 1: No cycle in a connected graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test 2: Cycle in a connected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test 3: No cycle in a weighted undirected graph
    vector<vector<int>> graph3 = {
        {0, 2, 0, 0, 0},
        {2, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test 4: Cycle in an unweighted directed graph
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test 5: Cycle in an unweighted directed graph
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

// Test cases for the isBipartite function
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;

    // Test 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    // Test 2: Non-bipartite graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test 3: Non-bipartite graph
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Test 4: Bipartite graph with even number of vertices
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");

    // Test 5: Bipartite graph with disconnected components
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3, 5}");
}

// Test cases for the negativeCycle function
TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;

    // Test 1: Graph with no negative cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    // Test 2: Graph with negative cycle
    vector<vector<int>> graph2 = {
        {0, -1, 0, 0},
        {0, 0, -2, 0},
        {0, 0, 0, -3},
        {-4, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle: 0->1->2->3->0");

    // Test 3: Weighted directed graph with no negative cycles
    vector<vector<int>> graph3 = {
        {0, 2, 0, 0},
        {0, 0, -3, 0},
        {0, 0, 0, -1},
        {4, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    // Test 4: Graph with no edges
    vector<vector<int>> graph4 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    // Test 5: Graph with a negative cycle
    vector<vector<int>> graph5 = {
        {0, -1, 0, 0},
        {0, 0, -2, 0},
        {-5, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle: 0->1->2->0");
}

// Test case for invalid graph input
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;

    // Test 1: Invalid graph with mismatched dimensions
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
