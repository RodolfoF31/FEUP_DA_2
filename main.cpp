#include <iostream>
#include <vector>
#include "fileman.h"
#include "shipping.cpp"
#include "graph.h"
#include "graph.cpp"
#include "fileman.cpp"
#include "stadiums.h"
#include "tourism.h"
#include <chrono>

using namespace std;

int main() {

    int originNode;
    Fileman fileman;
    int option;
    int option2;
    double minCost;
    vector<int> minPath;


    do {

        cout << "1 - Backtracking algorithm" << endl;
        cout << "9 - Quit" << endl;


        cin >> option;

        switch(option) {

            case 1:

                cout << "1 - Shippings" << endl;
                cout << "2 - Stadiums" << endl;
                cout << "3 - Tourism" << endl;

                cin >> option2;

            switch(option2) {
                case 1:
                    {
                        fileman = Fileman();
                        fileman.loadShipping("Toy_Graphs/Toy-Graphs/shipping.csv");

                        Graph shippingGraph = fileman.getGraph();

                        auto start = chrono::high_resolution_clock::now();
                        shippingGraph.tspBacktracking();
                        auto end = chrono::high_resolution_clock::now();

                        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                        minCost = shippingGraph.getMinCost();
                        minPath = shippingGraph.getBestPath();

                        cout << "Minimum Cost: " << minCost << endl;
                        cout << "Best Path: ";
                        for (int node : minPath) {
                            cout << node << " ";
                        }
                        cout << endl;

                        cout << "Execution Time = " << duration << "ms" << endl;
                        cout << endl;

                        break;
                    }

                case 2:
                    {
                        fileman = Fileman();
                        fileman.loadStadiums("Toy_Graphs/Toy-Graphs/stadiums.csv");

                        Graph stadiumsGraph = fileman.getGraph();

                        auto start = chrono::high_resolution_clock::now();
                        stadiumsGraph.tspBacktracking();
                        auto end = chrono::high_resolution_clock::now();

                        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                        minCost = stadiumsGraph.getMinCost();
                        minPath = stadiumsGraph.getBestPath();

                        cout << "Minimum Cost: " << minCost << endl;
                        cout << "Best Path: ";
                        for (int node : minPath) {
                            cout << node << " ";
                        }

                        cout << endl;

                        cout << "Execution Time = " << duration << "ms" << endl;
                        cout << endl;

                        break;
                    }
                case 3:
                    {
                        fileman = Fileman();
                        fileman.loadTourism("Toy_Graphs/Toy-Graphs/tourism.csv");

                        Graph tourismGraph = fileman.getGraph();

                        auto start = chrono::high_resolution_clock::now();
                        tourismGraph.tspBacktracking();
                        auto end = chrono::high_resolution_clock::now();

                        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                        minCost = tourismGraph.getMinCost();
                        minPath = tourismGraph.getBestPath();

                        cout << "Minimum Cost: " << minCost << endl;
                        cout << "Best Path: ";
                        for (int node : minPath) {
                            cout << node << " ";
                        }

                        cout << endl;

                        cout << "Execution Time = " << duration << "ms" << endl;
                        cout << endl;

                        break;
                    }
            }

            break;
        }

    } while(option != 9);

    return 0;
    
}