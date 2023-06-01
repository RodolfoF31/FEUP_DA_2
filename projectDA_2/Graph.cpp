#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Graph::Graph() {}

void Graph::addNode(const std::string& name) {
    if (nodeIndexMap.find(name) == nodeIndexMap.end()) {
        int index = nodeIndexMap.size();
        nodeIndexMap[name] = index;

        for(auto &r : adjacencyMatrix)
            r.resize(index + 1, 0.0);

        adjacencyMatrix.resize(index + 1, std::vector<double>(index + 1, 0.0));
    }
}

void Graph::addNodeRealGraph(int id, double longitude, double latitude) {

    string name = to_string(id);

    if (nodeIndexMap.find(name) == nodeIndexMap.end()) {
        int index = nodeIndexMap.size();
        nodeIndexMap[name] = index;

        for (auto& row : adjacencyMatrix)
            row.resize(index + 1, 0.0);
        adjacencyMatrix.resize(index + 1, std::vector<double>(index + 1, 0.0));

        longitudeMap[name] = longitude;
        latitudeMap[name] = latitude;
    }
}


void Graph::addEdge(const std::string& origem, const std::string& destino, double distancia) {
    int fromIndex = nodeIndexMap[origem];
    int toIndex = nodeIndexMap[destino];
    adjacencyMatrix[fromIndex][toIndex] = distancia;
}

int Graph::getNumNodes() const {
    return nodeIndexMap.size();
}

double Graph::getDistancia(int origem, int destino) const {
    return adjacencyMatrix[origem][destino];
}

double Graph::getDistancia(const std::string& origem, const std::string& destino) const {
    int origemIndex = nodeIndexMap.at(origem);
    int destinoIndex = nodeIndexMap.at(destino);
    return adjacencyMatrix[origemIndex][destinoIndex];
}

void Graph::loadGraphFromCSV(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << std::endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        string from, to;
        double distance;
        getline(iss, from, ',');
        getline(iss, to, ',');
        iss >> distance;
        if (nodeIndexMap.find(from) == nodeIndexMap.end()) {
            addNode(from);
        }
        if (nodeIndexMap.find(to) == nodeIndexMap.end()) {
            addNode(to);
        }
        addEdge(from, to, distance);
    }
    file.close();
}

void Graph::loadRealWorldGraphFromCSV(const std::string &nodesFile, const std::string &edgesFile) {
    ifstream file(nodesFile);

    if(!file){
        cout << "Error opening file: " << nodesFile << std::endl;
        return;
    }

    string line;
    getline(file, line);

    while(getline(file, line)){
        istringstream iss(line);
        string idStr, longitudeStr, latitudeStr;
        getline(iss, idStr, ',');
        getline(iss, longitudeStr, ',');
        getline(iss, latitudeStr, ',');

        int id = stoi(idStr);
        double longitude = stod(longitudeStr);
        double latitude = stod(latitudeStr);

        addNodeRealGraph(id, longitude, latitude);

    }
    file.close();

    ifstream file2(edgesFile);

    if(!file2){
        cout << "Error opening file: " << edgesFile << std::endl;
        return;
    }

    getline(file2, line);

    while(getline(file2, line)){
        istringstream iss(line);
        string from, to;
        double distance;
        getline(iss, from, ',');
        getline(iss, to, ',');
        iss >> distance;
        addEdge(from, to, distance);
    }
    file2.close();
}
