#include "fileman.h"

using namespace std;


Fileman::Fileman() = default;

void Fileman::loadShipping() {

    ifstream theshipping;
    theshipping.open("Toy_Graphs/Toy-Graphs/shipping.csv");

    string line;
    getline(theshipping, line);

    while (getline(theshipping, line)) {

        stringstream input(line);

        string origem, destino, distancia;

        getline(input, origem, ',');
        getline(input, destino, ',');
        getline(input, distancia, ',');

        graph.addEdge(stoi(origem), stoi(destino), stod(distancia));

    }
}

void Fileman::loadStadiums() {

    ifstream theshipping;
    theshipping.open("Toy_Graphs/Toy-Graphs/stadiums.csv");

    string line;
    getline(theshipping, line);

    while (getline(theshipping, line)) {

        stringstream input(line);

        string origem, destino, distancia;

        getline(input, origem, ',');
        getline(input, destino, ',');
        getline(input, distancia, ',');

        graph.addEdge(stoi(origem), stoi(destino), stod(distancia));
    }
}
