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
    void addNode_RWG(int id, double longitude, double latitude);
    void addEdge_RWG(int origin, int destination, double distance);
    void addEdge(int origem, int destino, double distancia);
    double getMinCost() const;
    double getDistance(int source, int destination);
    vector<int> getBestPath() const;
    void tspBacktracking();
    void tspBacktrackingUtil(int currNode, int depth, double currCost);
    void tspBacktracking_RWG();
    void tspTriangularApproximation();
    void backtrack(vector<int>& path, vector<bool>& visited, int current, double cost);
    double calculateCost(const std::vector<int>& path);
    void resetVisited();
    double calculateDistance(int origin, int destination);
    void calculateGeographicDistances();
    double calculatePathCost(const vector<int>& path);
    double calculateHaversineDistance(double lat1, double lon1, double lat2, double lon2);
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