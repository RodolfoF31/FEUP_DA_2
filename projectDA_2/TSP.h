//
// Created by user on 27/05/2023.
//

#ifndef UNTITLED2_TSP_H
#define UNTITLED2_TSP_H

#include "Graph.h"
#include <vector>

using namespace std;

class TSP {
private:
    Graph graph;
    vector<int> path;
    double minCost;

public:
    TSP();
    void loadGraph(const std::string& filename);
    void backtrack(int current, double cost, std::vector<bool>& visited_nodes);
    vector<int> solve();
    double getMinCost();
    std::vector<int> triangularApproximation();
    bool satisfiesTriangularInequality(int node1, int node2);



};


#endif //UNTITLED2_TSP_H
