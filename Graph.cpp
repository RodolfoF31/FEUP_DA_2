#include "Graph.h"
#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;



Graph::Graph() {
    Nodes = unordered_map<int, Node>();
    minCost = std::numeric_limits<double>::infinity();
}


void Graph::addNode_RWG(int id, double longitude, double latitude) {
    Nodes_RWG[id] = {longitude, latitude};
}

void Graph::addEdge_RWG(int origin, int destination, double distance) {
    edges.push_back({origin, destination, distance});
}

void Graph::tspBacktracking_RWG() {
    minCost = std::numeric_limits<double>::max();
    bestPath.clear();

    std::vector<int> path;
    std::vector<bool> visited(Nodes_RWG.size(), false);
    path.push_back(0); 
    visited[0] = true;
    backtrack(path, visited, 0, 0);

    bestPath.push_back(0);
}

void Graph::tspTriangularApproximation() {
    calculateGeographicDistances();

    numNodes = Nodes_RWG.size();
    vector<bool> visited(numNodes, false);

    int currentNode = 0;
    int numVisited = 1;
    visited[currentNode] = true;
    bestPath.clear();
    bestPath.push_back(currentNode);

    while (numVisited < numNodes) {
        double minDistance = numeric_limits<double>::infinity();
        int nextNode = -1;

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && distanceMatrix[currentNode][i] < minDistance) {
                minDistance = distanceMatrix[currentNode][i];
                nextNode = i;
            }
        }

        if (nextNode != -1) {
            visited[nextNode] = true;
            bestPath.push_back(nextNode);
            currentNode = nextNode;
            numVisited++;
        } else {
            break;
        }
    }

    bestPath.push_back(0);

    minCost = calculatePathCost(bestPath);
}


void Graph::backtrack(std::vector<int>& path, std::vector<bool>& visited, int current, double cost) {
    if (path.size() == Nodes_RWG.size()) {
        cost += calculateDistance(current, 0);

        if (cost < minCost) {
            minCost = cost;
            bestPath = path;
        }
    } else {
        for (const auto& edge : edges) {
            if (edge.origin == current && !visited[edge.destination]) {
                visited[edge.destination] = true;
                path.push_back(edge.destination);
                double newCost = cost + edge.distance;
                backtrack(path, visited, edge.destination, newCost);
                path.pop_back();
                visited[edge.destination] = false;
            }
        }
    }
}

double Graph::calculateDistance(int origin, int destination) {
    const double earthRadius = 6371000;

    double lat1 = Nodes_RWG.at(origin).latitude;
    double lon1 = Nodes_RWG.at(origin).longitude;
    double lat2 = Nodes_RWG.at(destination).latitude;
    double lon2 = Nodes_RWG.at(destination).longitude;

    double lat1Rad = toRadians(lat1);
    double lon1Rad = toRadians(lon1);
    double lat2Rad = toRadians(lat2);
    double lon2Rad = toRadians(lon2);

    double dlon = lon2Rad - lon1Rad;
    double dlat = lat2Rad - lat1Rad;
    double a = pow(sin(dlat / 2), 2) + cos(lat1Rad) * cos(lat2Rad) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = earthRadius * c;

    return distance;
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

void Graph::calculateGeographicDistances() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i == j) {
                distanceMatrix[i][j] = 0.0;
            } 
            else if (distanceMatrix[i][j] == -1.0) {

                double lat1 = Nodes_RWG[i].latitude;
                double lon1 = Nodes_RWG[i].longitude;
                double lat2 = Nodes_RWG[j].latitude;
                double lon2 = Nodes_RWG[j].longitude;
                double distance = calculateHaversineDistance(lat1, lon1, lat2, lon2);
                distanceMatrix[i][j] = distance;
            }
        }
    }
}





double Graph::toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}


double Graph::calculatePathCost(const vector<int>& path) {
    double cost = 0.0;

    for (int i = 0; i < path.size() - 1; i++) {
        int node1 = path[i];
        int node2 = path[i + 1];
        cost += distanceMatrix[node1][node2];
    }

    return cost;
}

double Graph::calculateHaversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double lat1Rad = lat1 * M_PI / 180.0;
    double lon1Rad = lon1 * M_PI / 180.0;
    double lat2Rad = lat2 * M_PI / 180.0;
    double lon2Rad = lon2 * M_PI / 180.0;

    double deltaLat = lat2Rad - lat1Rad;
    double deltaLon = lon2Rad - lon1Rad;

    double a = sin(deltaLat / 2.0) * sin(deltaLat / 2.0) +
               cos(lat1Rad) * cos(lat2Rad) *
               sin(deltaLon / 2.0) * sin(deltaLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    const double radius = 6371000.0;
    double distance = radius * c;

    return distance;
}
