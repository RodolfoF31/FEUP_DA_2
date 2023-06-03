#include "Graph.h"
#include <limits>
#include <algorithm>

using namespace std;



Graph::Graph() {
    Nodes = unordered_map<int, Node>();
    minCost = std::numeric_limits<double>::infinity();
}


void Graph::addEdge(int origin, int destination, double distance) {

    Nodes[origin].id = origin;
    Nodes[destination].id = destination;
    Nodes[origin].adj.push_back({ destination, distance });
    Nodes[destination].adj.push_back({ origin, distance });
    
}



double Graph::getMinCost() const {
    return minCost;
}

double Graph::getDistance(int source, int destination) {
    const Node& node = Nodes.at(source);
    for (const Edge& edge : node.adj) {
        if (edge.destino == destination) {
            return edge.distancia;
        }
    }
    return numeric_limits<double>::infinity();
}

vector<int> Graph::getBestPath() const {
    return bestPath;
}

void Graph::tspBacktracking() {
    resetVisited();
    currentPath.clear();
    bestPath.clear();
    minCost = numeric_limits<double>::infinity();

    tspBacktrackingUtil(0, 1, 0.0);

    bestPath.push_back(0);
}

void Graph::tspBacktrackingUtil(int currNode, int depth, double currCost) {
    Nodes[currNode].visited = true;
    currentPath.push_back(currNode);

    if (depth == Nodes.size()) {
        currCost += getDistance(currNode, 0);

        if (currCost < minCost) {
            bestPath = currentPath;
            minCost = currCost;
        }

        currCost -= getDistance(currNode, 0);
    } else {
        for (const Edge& edge : Nodes[currNode].adj) {
            int nextNode = edge.destino;
            if (!Nodes[nextNode].visited) {
                tspBacktrackingUtil(nextNode, depth + 1, currCost + edge.distancia);
            }
        }
    }

    Nodes[currNode].visited = false;
    currentPath.pop_back();
}

double Graph::calculateCost(const vector<int>& path) {
    double cost = 0.0;
    int size = path.size();
    for (int i = 0; i < size - 1; ++i) {
        int source = path[i];
        int destination = path[i + 1];
        cost += getDistance(source, destination);
    }
    return cost;
}

void Graph::resetVisited() {
    for (auto& pair : Nodes) {
        pair.second.visited = false;
    }
}