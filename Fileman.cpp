#include "Fileman.h"

using namespace std;


Fileman::Fileman() = default;

void Fileman::loadShipping(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open the shipping file.");
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string originStr, destinationStr, distanceStr;
        getline(ss, originStr, ',');
        getline(ss, destinationStr, ',');
        getline(ss, distanceStr, ',');

        int origin = stoi(originStr);
        int destination = stoi(destinationStr);
        double distance = stod(distanceStr);

        graph.addEdge(origin, destination, distance);
    }
}


void Fileman::loadStadiums(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open the stadiums file.");
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string originStr, destinationStr, distanceStr;
        getline(ss, originStr, ',');
        getline(ss, destinationStr, ',');
        getline(ss, distanceStr, ',');

        int origin = stoi(originStr);
        int destination = stoi(destinationStr);
        double distance = stod(distanceStr);

        graph.addEdge(origin, destination, distance);
    }
}


void Fileman::loadTourism(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open the tourism file.");
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string originStr, destinationStr, distanceStr;
        getline(ss, originStr, ',');
        getline(ss, destinationStr, ',');
        getline(ss, distanceStr, ',');

        int origin = stoi(originStr);
        int destination = stoi(destinationStr);
        double distance = stod(distanceStr);

        graph.addEdge(origin, destination, distance);
    }
}

void Fileman::loadGraph_RWG(const string& edgesFile, const string& nodesFile) {
    ifstream nodesStream(nodesFile);
    string nodeLine;


    getline(nodesStream, nodeLine);

    while (getline(nodesStream, nodeLine)) {
        istringstream nodeStream(nodeLine);
        string nodeId, longitude, latitude;

        getline(nodeStream, nodeId, ',');
        getline(nodeStream, longitude, ',');
        getline(nodeStream, latitude, ',');

        double lon = stod(longitude);
        double lat = stod(latitude);

        graph.addNode_RWG(stoi(nodeId), lon, lat);
    }

    nodesStream.close();

    ifstream edgesStream(edgesFile);
    string edgeLine;

    getline(edgesStream, edgeLine);

    while (getline(edgesStream, edgeLine)) {
        istringstream edgeStream(edgeLine);
        string origin, destination, distance;

        getline(edgeStream, origin, ',');
        getline(edgeStream, destination, ',');
        getline(edgeStream, distance, ',');

        double dist = stod(distance);

        graph.addEdge_RWG(stoi(origin), stoi(destination), dist);
    }

    edgesStream.close();
}



Graph Fileman::getGraph() {
    return graph;
}

