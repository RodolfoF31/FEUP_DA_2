#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

struct Edge {

    int destino;
    double distancia;

};


struct Node {

    int id;
    vector<Edge> adj;
    bool visited;

};

struct Node_RWG {
    double longitude;
    double latitude;
};

struct Edge_RWG {
    int origin;
    int destination;
    double distance;
};

class Graph {
public:
    Graph();
    /**
     * Adds a node to the graph for Real World Graphs.
     * @param id The ID of the node to add.
     * @param longitude The longitude of the node's location.
     * @param latitude The latitude of the node's location.
     * @note Time complexity -> O(1)
     */
    void addNode_RWG(int id, double longitude, double latitude);
    /**
     * Adds an edge to the graph for Real World Graphs.
     * @param origin The ID of the origin node of the edge.
     * @param destination The ID of the destination node of the edge.
     * @param distance The distance associated with the edge.
     * @note Time complexity -> O(1)
     */
    void addEdge_RWG(int origin, int destination, double distance);
    /**
     * @brief Adds an edge to the graph.
     * @param origin The ID of the origin node of the edge.
     * @param destination The ID of the destination node of the edge.
     * @param distance The distance associated with the edge.
     * @note Time complexity -> O(1)
     */
    void addEdge(int origem, int destino, double distancia);
    /**
     * @brief Returns the minimum cost of the best path found.
     * @return The minimum cost of the best path.
     * @note Time complexity -> O(1)
     */
    double getMinCost() const;
    /**
     * @brief Returns the distance between two nodes in the graph.
     * @param source The ID of the source node.
     * @param destination The ID of the destination node.
     * @return The distance between the source and destination nodes.
     * @note Time complexity -> O(1)
     */
    double getDistance(int source, int destination);
    /**
     * @brief Returns the best path found in the graph.
     * @return The best path as a vector of node IDs.
     */
    vector<int> getBestPath() const;
    /**
     * @brief Solves TSP using backtracking.
     * @note Time complexity -> O(n!)
     */
    void tspBacktracking();
    /**
     * @brief Utility function for the backtracking algorithm
     * @param currNode The current node being visited.
     * @param depth The current depth of the recursion.
     * @param currCost The current cost of the path being explored.
     * @note Time complexity -> O(n!)
     */
    void tspBacktrackingUtil(int currNode, int depth, double currCost);
    /**
     * @brief Solves TSP for a real-world graph using backtracking.
     * @note It finds the optimal Hamiltonian cycle in the graph using a backtracking approach.
     * @note Time complexity -> O(n)
     */
    void tspBacktracking_RWG();
    /**
     * @brief Solves TSP for a real-world graph using a triangular approximation.
     * This function solves the TSP for a real-world graph represented by the Nodes_RWG structure using a triangular approximation approach.
     * It calculates the geographic distances between nodes and builds a distance matrix.
     * The function starts from node 0 and iteratively selects the next unvisited node with the shortest distance.
     * It continues this process until all nodes are visited, forming a Hamiltonian cycle.
     * The resulting path is stored in the bestPath vector, and the minimum cost is calculated based on this path.
     * @note Time complexity -> O(n^2)
     */
    void tspTriangularApproximation();
    /**
     * @brief This function performs backtracking to find the optimal Hamiltonian cycle (TSP solution).
     * The algorithm explores all possible paths starting from node 0 and visiting each unvisited node exactly once.
     * The function updates the minimum cost (minCost) and the best path (bestPath) whenever a better solution is found.
     * @param path A vector representing the current path being explored.
     * @param visited A vector indicating whether each node has been visited or not.
     * @param current The current node being visited.
     * @param cost The cost of the current path.
     * @note Time complexity -> O(n!)
     */
    void backtrack(vector<int>& path, vector<bool>& visited, int current, double cost);
    /**
     * @brief Calculate the cost of a given path in the graph.
     * @param path A vector representing the path for which to calculate the cost.
     * @return The cost of the path.
     * @note Time complexity -> O(n)
     */
    double calculateCost(const std::vector<int>& path);
    /**
     * @brief Reset the visited flag for all nodes in the graph.
     * @note Time complexity -> O(n)
     */
    void resetVisited();
    /**
     * @brief Calculate the distance between two nodes using their geographic coordinates.
     * It uses the Haversine formula to compute the great-circle distance between the two points on the Earth's surface.
     * @param origin The ID of the origin node.
     * @param destination The ID of the destination node.
     * @return The distance between the origin and destination nodes in meters.
     * @note Time complexity -> O(1)
     */
    double calculateDistance(int origin, int destination);
    /**
     * @brief Calculate the geographic distances between nodes and populate the distance matrix.
     * @note Time complexity -> O(n^2)
     */
    void calculateGeographicDistances();
    /**
     * @brief Calculate the cost of a given path in the graph.
     * @param path The path for which to calculate the cost.
     * @return The cost of the path.
     * @note Time complexity -> O(n)
     */
    double calculatePathCost(const vector<int>& path);
    /**
     * @brief Calculate the Haversine distance between two geographic coordinates.
     * @param lat1 Latitude of the first point in degrees.
     * @param lon1 Longitude of the first point in degrees.
     * @param lat2 Latitude of the second point in degrees.
     * @param lon2 Longitude of the second point in degrees.
     * @return The Haversine distance between the two points in meters.
     * @note Time complexity -> O(1)
     */
    double calculateHaversineDistance(double lat1, double lon1, double lat2, double lon2);
    /**
     * @brief Convert degrees to radians.
     * @param degrees Angle in degrees.
     * @return Angle in radians.
     * @note Time complexity -> O(1)
     */
    double toRadians(double degrees);


private:
    unordered_map<int, Node_RWG> Nodes_RWG;
    unordered_map<int, Node> Nodes;
    double minCost;
    vector<int> currentPath;
    vector<int> bestPath;
    double currentCost;
    vector<Edge_RWG> edges;
    unordered_map<int, unordered_map<int, double>> distanceMatrix;
    int numNodes;
};

#endif