#include <iostream>
#include "Graph.h"
#include "TSP.h"
#include "Utils/MenuMan.h"

TSP tsp;

void test(){ // will be taken off later just to check if all things are working alright
    std::vector<int> path = tsp.solve();

    std::cout << "Minimum cost: " << tsp.getMinCost() << std::endl;
    std::cout << "Path: ";
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

void displayMainMenu(){
    while(true){
        int choice = MenuMan::createMenu("\nSelect the graph: ", {"shipping.csv", "stadiums.csv", "tourism.csv", "Exit"});
        switch(choice){
            case 1:
                tsp.loadGraph("../data/Toy_Graphs/Toy-Graphs/shipping.csv");
                test();
                break;
            case 2:
                tsp.loadGraph("../data/Toy_Graphs/Toy-Graphs/stadiums.csv");
                test();
                break;
            case 3:
                tsp.loadGraph("../data/Toy_Graphs/Toy-Graphs/tourism.csv");
                test();
                break;
            case 4:
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
