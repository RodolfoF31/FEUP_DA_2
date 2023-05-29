#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>

using namespace std;

struct Edge {

    int destino;
    double distancia;

};


struct Node {

    int id;
    vector<Edge> adj;

};

class Graph {
public:
    Graph();
    void addEdge(int origem, int destino, double distancia);
    const unordered_map<int, Node> getAdjacencyList() const;
    double getMinCost() const;
    vector<int> getMinPath() const;
    void calculateMinCost();
    void backtracking(int currNode, double cost, vector<int>& path, vector<int>& visited);

private:
    unordered_map<int, Node> adjacencyList;
    double minCost;
};

#endif