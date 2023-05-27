#include <iostream>
#include "Graph.h"
#include "TSP.h"

int main() {
    TSP tsp;

    tsp.loadGraph("shipping.csv");

    std::vector<int> path = tsp.solve();

    std::cout << "Minimum cost: " << tsp.getMinCost() << std::endl;
    std::cout << "Path: ";
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
