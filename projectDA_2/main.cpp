#include <iostream>
#include <vector>
#include "fileman.h"
#include "shipping.cpp"
#include "graph.h"
#include "graph.cpp"
#include "fileman.cpp"
#include "stadiums.h"
#include "tourism.h"

using namespace std;

int main() {

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
                        fileman.loadShipping();
                        fileman.graph.calculateMinCost();

                        minCost = fileman.graph.getMinCost();
                        minPath = fileman.graph.getMinPath();

                        cout << "Minimum cost: " << minCost << endl;

                    }
                    break;

                case 2:
                    {
                        fileman = Fileman();
                        fileman.loadStadiums();
                        fileman.graph.calculateMinCost();

                        minCost = fileman.graph.getMinCost();
                        minPath = fileman.graph.getMinPath();

                        cout << "Minimum cost: " << minCost << endl;


                    }
                    break;
            }

            break;
        }

    } while(option != 9);

    return 0;
    
}