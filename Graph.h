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

class Graph {
public:
    Graph();
    void addEdge(int origem, int destino, double distancia);
    double getMinCost() const;
    double getDistance(int source, int destination);
    vector<int> getBestPath() const;
    void tspBacktracking();
    void tspBacktrackingUtil(int currNode, int depth, double currCost);
    double calculateCost(const std::vector<int>& path);
    void resetVisited();

private:
    unordered_map<int, Node> Nodes;
    double minCost;
    vector<int> currentPath;
    vector<int> bestPath;
    double currentCost;
};

#endif