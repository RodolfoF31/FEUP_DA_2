#include "Graph.h"

using namespace std;

#include <limits>


Graph::Graph() {
    adjacencyList = unordered_map<int, Node>();
}



void Graph::addEdge(int origem, int destino, double distancia) {

    if (adjacencyList.find(origem) != adjacencyList.end()) {
        
        Edge anEdge = {destino, distancia};
        adjacencyList[origem].adj.push_back(anEdge);

    } else {

        Node newNode = {origem, {{destino, distancia}}};
        adjacencyList.insert({origem, newNode});

    }
}

const unordered_map<int, Node> Graph::getAdjacencyList() const {
    return adjacencyList;
}



double Graph::getMinCost() const {
    return minCost;
}

void Graph::calculateMinCost() {
    minCost = numeric_limits<double>::max();
    vector<int> visited(adjacencyList.size(), 0); 
    vector<int> path(adjacencyList.size(), 0); 
    backtracking(0, 0.0, path, visited); 
}

void Graph::backtracking(int currNode, double cost, vector<int>& path, vector<int>& visited) {
    visited[currNode] = 1;  

    bool allVisited = true;
    for (const auto& node : adjacencyList) {
        if (visited[node.first] == 0) {
            allVisited = false;
            break;
        }
    }

    if (allVisited) {
        if (cost < minCost) {
            minCost = cost;
            path.assign(visited.begin(), visited.end());
        }
    }

    for (const auto& edge : adjacencyList[currNode].adj) {
        if (visited[edge.destino] == 0) {
            backtracking(edge.destino, cost + edge.distancia, path, visited);
        }
    }

    visited[currNode] = 0;
}

vector<int> Graph::getMinPath() const {
    vector<int> path;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if (path[i] == 1) {
            path.push_back(i);
        }
    }
    return path;
}
