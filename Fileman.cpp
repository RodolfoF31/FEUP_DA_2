#include "fileman.h"

using namespace std;


Fileman::Fileman() = default;

void Fileman::loadShipping(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the shipping file.");
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string originStr, destinationStr, distanceStr;
        std::getline(ss, originStr, ',');
        std::getline(ss, destinationStr, ',');
        std::getline(ss, distanceStr, ',');

        int origin = std::stoi(originStr);
        int destination = std::stoi(destinationStr);
        double distance = std::stod(distanceStr);

        graph.addEdge(origin, destination, distance);
    }
}


void Fileman::loadStadiums(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the stadiums file.");
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string originStr, destinationStr, distanceStr;
        std::getline(ss, originStr, ',');
        std::getline(ss, destinationStr, ',');
        std::getline(ss, distanceStr, ',');

        int origin = std::stoi(originStr);
        int destination = std::stoi(destinationStr);
        double distance = std::stod(distanceStr);

        graph.addEdge(origin, destination, distance);
    }
}


void Fileman::loadTourism(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the stadiums file.");
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string originStr, destinationStr, distanceStr;
        std::getline(ss, originStr, ',');
        std::getline(ss, destinationStr, ',');
        std::getline(ss, distanceStr, ',');

        int origin = std::stoi(originStr);
        int destination = std::stoi(destinationStr);
        double distance = std::stod(distanceStr);

        graph.addEdge(origin, destination, distance);
    }
}

Graph Fileman::getGraph() {
    return graph;
}
