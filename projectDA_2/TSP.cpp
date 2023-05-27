//
// Created by user on 27/05/2023.
//

#include "TSP.h"
#include <limits>

TSP::TSP() : minCost(std::numeric_limits<double>::max()) {}

void TSP::loadGraph(const std::string& filename) {
    graph.loadGraphFromCSV(filename);
    int n = graph.getNumNodes();
}

void TSP::backtrack(int current, double cost, int visited) {
    int n = graph.getNumNodes();
    if (visited == (1 << n) - 1) {  // All nodes visited
        if (graph.getDistancia(current, 0) != 0) {
            return;
        }
        cost += graph.getDistancia(current, 0);
        if (cost < minCost) {
            minCost = cost;
            path[n] = current;  // Store the current node at the last index
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if ((visited & (1 << i)) == 0 && graph.getDistancia(current, i) != 0) {
            path[visited + 1] = current;  // Store the current node at the visited index
            backtrack(i, cost + graph.getDistancia(current, i), visited | (1 << i));
        }
    }
}



vector<int> TSP::solve() {
    int n = graph.getNumNodes();
    path.resize(n + 1, -1);  // Initialize path with size n + 1
    path[0] = 0;
    backtrack(0, 0.0, 1);
    return path;
}


double TSP::getMinCost() {
    return minCost;
}