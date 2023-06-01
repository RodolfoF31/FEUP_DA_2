#include <iostream>
#include "Graph.h"
#include "TSP.h"
#include "Utils/MenuMan.h"

TSP tsp;

void backtrack(){ // will be taken off later just to check if all things are working alright
    std::vector<int> path = tsp.solve();

    std::cout << "Minimum cost: " << tsp.getMinCost() << std::endl;
    std::cout << "Path: ";
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

void displayAlgorithms(){
    while(true){
        int choice = MenuMan::createMenu("\nSelect the algorithm: ", {"backtrack", "triangular aproximation"});
        switch (choice) {
            case 1:
                backtrack();
                return;
            case 2:
                tsp.triangularApproximation();
                return;
            default:
                std::cout << "\nPlease, select a valid option!" << endl;
                break;
        }
    }
}

void displayMainMenu(){
    while(true){
        int choice = MenuMan::createMenu("\nSelect the graph: ", {"shipping.csv", "stadiums.csv", "tourism.csv", "graph1", "graph2", "graph3", "Exit"});
        switch(choice){
            case 1:
                tsp.loadGraph("../data/Toy_Graphs/Toy-Graphs/shipping.csv");
                displayAlgorithms();
                break;
            case 2:
                tsp.loadGraph("../data/Toy_Graphs/Toy-Graphs/stadiums.csv");
                displayAlgorithms();
                break;
            case 3:
                tsp.loadGraph("../data/Toy_Graphs/Toy-Graphs/tourism.csv");
                displayAlgorithms();
                break;
            case 4:
                tsp.loadRealWorldGraph("../data/Real_World_Graphs_/Real-world-Graphs/graph1/nodes.csv", "../data/Real_World_Graphs_/Real-world-Graphs/graph1/edges.csv");
                displayAlgorithms();
                break;
            case 5:
                tsp.loadRealWorldGraph("../data/Real_World_Graphs_/Real-world-Graphs/graph2/nodes.csv", "../data/Real_World_Graphs_/Real-world-Graphs/graph2/edges.csv");
                displayAlgorithms();
                break;
            case 6:
                tsp.loadRealWorldGraph("../data/Real_World_Graphs_/Real-world-Graphs/graph3/nodes.csv", "../data/Real_World_Graphs_/Real-world-Graphs/graph3/edges.csv");
                displayAlgorithms();
                break;
            case 7:
                return;
            default:
                std::cout << "\nPlease, select a valid option!" << endl;
        }
    }
}

int main() {
    displayMainMenu();
    return 0;
}
