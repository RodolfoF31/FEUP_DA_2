#include <iostream>
#include <vector>
#include <chrono>

#include "Fileman.h"
#include "Graph.h"
#include "MenuMan.h"

using namespace std;

Fileman fileman;
int option;
int option2;
double minCost;
vector<int> minPath;

void displayToy(){
    while(true){
        int choice = MenuMan::createMenu("\nSelect the toy graph: ", {"shipping.csv", "stadiums.csv", "tourism.csv"});
        Graph shippingGraph, stadiumsGraph, tourismGraph;
        std::chrono::time_point<std::chrono::high_resolution_clock> start1, end1;
        std::chrono::milliseconds::rep duration1;
        switch (choice) {
            case 1:
                fileman = Fileman();
                fileman.loadShipping("../Toy_Graphs/Toy-Graphs/shipping.csv");

                shippingGraph = fileman.getGraph();

                start1 = chrono::high_resolution_clock::now();
                shippingGraph.tspBacktracking();
                end1 = chrono::high_resolution_clock::now();

                duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

                minCost = shippingGraph.getMinCost();
                minPath = shippingGraph.getBestPath();

                cout << "Minimum Cost: " << minCost << endl;
                cout << "Best Path: ";
                for (int node : minPath) {
                    cout << node << " ";
                }
                cout << endl;

                cout << "Execution Time = " << duration1 << "ms" << endl;
                cout << endl;
                return;
            case 2:
                fileman = Fileman();
                fileman.loadStadiums("../Toy_Graphs/Toy-Graphs/stadiums.csv");

                stadiumsGraph = fileman.getGraph();

                start1 = chrono::high_resolution_clock::now();
                stadiumsGraph.tspBacktracking();
                end1 = chrono::high_resolution_clock::now();

                duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

                minCost = stadiumsGraph.getMinCost();
                minPath = stadiumsGraph.getBestPath();

                cout << "Minimum Cost: " << minCost << endl;
                cout << "Best Path: ";
                for (int node : minPath) {
                    cout << node << " ";
                }

                cout << endl;

                cout << "Execution Time = " << duration1 << "ms" << endl;
                cout << endl;
                return;
            case 3:
                fileman = Fileman();
                fileman.loadTourism("../Toy_Graphs/Toy-Graphs/tourism.csv");

                tourismGraph = fileman.getGraph();

                start1 = chrono::high_resolution_clock::now();
                tourismGraph.tspBacktracking();
                end1 = chrono::high_resolution_clock::now();

                duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

                minCost = tourismGraph.getMinCost();
                minPath = tourismGraph.getBestPath();

                cout << "Minimum Cost: " << minCost << endl;
                cout << "Best Path: ";
                for (int node : minPath) {
                    cout << node << " ";
                }

                cout << endl;

                cout << "Execution Time = " << duration1 << "ms" << endl;
                cout << endl;
                return;
            default:
                std::cout << "\nPlease, select a valid option!" << endl;
                break;
        }
    }
}

void displayRWG(){
    while(true){
        int choice = MenuMan::createMenu("\nSelect the real world graph: ", {"graph1", "graph2", "graph3"});
        Graph graph1, graph2, graph3;
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::milliseconds::rep duration;
        switch (choice) {
            case 1:
                fileman = Fileman();
                fileman.loadGraph_RWG("../Real_World_Graphs/Real-World-Graphs/graph1/edges.csv", "Real_World_Graphs/Real-World Graphs/graph1/nodes.csv");

                graph1 = fileman.getGraph();

                start = chrono::high_resolution_clock::now();
                graph1.tspTriangularApproximation();
                end = chrono::high_resolution_clock::now();

                duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                minCost = graph1.getMinCost();

                if (minCost == numeric_limits<double>::infinity()) {
                    cout << "No valid path found." << endl;
                }

                else {
                    cout << "Minimum Cost: " << minCost << " meters" << endl;
                }

                cout << "Execution Time = " << duration << "ms" << endl;
                cout << endl;
                return;
            case 2:
                fileman = Fileman();
                fileman.loadGraph_RWG("../Real_World_Graphs/Real-World Graphs/graph2/edges.csv", "Real_World_Graphs/Real-World Graphs/graph2/nodes.csv");

                graph2 = fileman.getGraph();

                start = chrono::high_resolution_clock::now();
                graph2.tspTriangularApproximation();
                end = chrono::high_resolution_clock::now();

                duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                minCost = graph2.getMinCost();

                if (minCost == numeric_limits<double>::infinity()) {
                    cout << "No valid path found." << endl;
                }

                else {
                    cout << "Minimum Cost: " << minCost << " meters" << endl;
                }

                cout << "Execution Time = " << duration << "ms" << endl;
                cout << endl;
                return;
            case 3:
                fileman = Fileman();
                fileman.loadGraph_RWG("../Real_World_Graphs/Real-World Graphs/graph3/edges.csv", "Real_World_Graphs/Real-World Graphs/graph3/nodes.csv");

                graph3 = fileman.getGraph();

                start = chrono::high_resolution_clock::now();
                graph3.tspTriangularApproximation();
                end = chrono::high_resolution_clock::now();

                duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                minCost = graph3.getMinCost();

                if (minCost == numeric_limits<double>::infinity()) {
                    cout << "No valid path found." << endl;
                }

                else {
                    cout << "Minimum Cost: " << minCost << " meters" << endl;
                }

                cout << "Execution Time = " << duration << "ms" << endl;
                cout << endl;
                return;
            default:
                std::cout << "\nPlease, select a valid option!" << endl;
                break;
        }
    }
}

void displayMainMenu(){
    while(true){
        int choice = MenuMan::createMenu("\nSelect the graph type: ", {"Toy Graphs", "Real World Graphs", "Exit"});
        switch(choice){
            case 1:
                displayToy();
                break;
            case 2:
                displayRWG();
                break;
            case 3:
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
