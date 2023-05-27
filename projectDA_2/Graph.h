#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>

struct Edge {
    int origem;
    int destino;
    double distancia;

    Edge(int f, int t, double d) : origem(f), destino(t), distancia(d) {}
};

class Graph {
private:
    std::vector<std::vector<double>> adjacencyMatrix;
    std::unordered_map<std::string, int> nodeIndexMap;

public:
    Graph();
    void addNode(const std::string& name);
    void addEdge(const std::string& origem, const std::string& destino, double distancia);
    int getNumNodes() const;
    double getDistancia(int origem, int destino) const;
    double getDistancia(const std::string& origem, const std::string& destino) const;
    void loadGraphFromCSV(const std::string& filename);
};

#endif  // GRAPH_H
