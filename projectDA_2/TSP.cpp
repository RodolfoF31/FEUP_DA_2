//
// Created by user on 27/05/2023.
//

#include "TSP.h"
#include <limits>
#include <algorithm>


TSP::TSP() : minCost(std::numeric_limits<double>::max()) {}

void TSP::loadGraph(const std::string& filename) {
    graph.loadGraphFromCSV(filename);
}

void TSP::loadRealWorldGraph(const std::string &nodesFile, const std::string &edgesFile) {
    graph.loadRealWorldGraphFromCSV(nodesFile, edgesFile);
}

void TSP::backtrack(int current, double cost, std::vector<bool>& visited_nodes) {
    int n = graph.getNumNodes();
    if(visited_nodes[current])
        return;

    visited_nodes[current] = true;
    if(std::count(visited_nodes.begin(), visited_nodes.end(), true) == n){
        if(graph.getDistancia(current, 0) != 0)
            return;

        cost += graph.getDistancia(current, 0);
        if(cost < minCost){
            minCost = cost;
            path[n] = current;
        }
        visited_nodes[current] = false;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!visited_nodes[i] && graph.getDistancia(current, i) > 0){
            path[std::count(visited_nodes.begin(), visited_nodes.end(), true)] = true;
            backtrack(i, cost + graph.getDistancia(current, i), visited_nodes);
        }
    }
    visited_nodes[current] = false;
}



vector<int> TSP::solve() {
    int n = graph.getNumNodes();
    path.resize(n + 1, -1);  // Initialize path with size n + 1
    path[0] = 0;
    std::vector<bool> visited_nodes(n, false);
    visited_nodes[0] = true;
    backtrack(0, 0.0, visited_nodes);
    return path;
}


double TSP::getMinCost() {
    return minCost;
}

/*
std::vector<int> TSP::triangularApproximation() {
    int numNodes = graph.getNumNodes();

    // Create a vector to store the tour
    std::vector<int> tour;
    tour.reserve(numNodes);

    // Start the tour at node with the zero-identifier label
    int current = 0;
    tour.push_back(current);

    // Keep track of visited nodes
    std::vector<bool> visited(numNodes, false);
    visited[current] = true;

    while (tour.size() < numNodes) {
        int nearestNode = -1;
        double minDistance = std::numeric_limits<double>::max();

        // Find the nearest unvisited node using the triangular inequality
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i] && graph.getDistancia(current, i) < minDistance) {
                nearestNode = i;
                minDistance = graph.getDistancia(current, i);
            }
        }

        // Add the nearest node to the tour
        tour.push_back(nearestNode);
        visited[nearestNode] = true;
        current = nearestNode;
    }

    // Return the completed tour
    return tour;
}
*/



std::vector<int> TSP::triangularApproximation() {
    int n = graph.getNumNodes();
    std::vector<int> path_(n);
    std::vector<bool> visited(n, false);

    int current = 0;  // Starting from node 0
    visited[current] = true;
    path_[0] = current;

    for (int i = 1; i < n; ++i) {
        int next = -1;
        double minDist = std::numeric_limits<double>::max();

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && graph.getDistancia(current, j) < minDist && satisfiesTriangularInequality(current, j)) {
                next = j;
                minDist = graph.getDistancia(current, j);
            }
        }

        if (next == -1) {
            // If no node satisfies the triangular inequality, find the closest unvisited node
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && graph.getDistancia(current, j) < minDist) {
                    next = j;
                    minDist = graph.getDistancia(current, j);
                }
            }
        }

        path_[i] = next;
        visited[next] = true;
        current = next;
    }

    return path_;
}

bool TSP::satisfiesTriangularInequality(int node1, int node2) {
    double dist1 = graph.getDistancia(0, node1);
    double dist2 = graph.getDistancia(0, node2);
    double dist12 = graph.getDistancia(node1, node2);

    return (dist12 <= dist1 + dist2);
}