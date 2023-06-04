#ifndef FILEMAN_H
#define FILEMAN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Graph.h"



class Fileman {

    public:
        Fileman();

        /**
         * @brief Loads shipping information from a file.
         * @param filename The name of the file to load.
         * @throws runtime_error If the file fails to open.
         * @note Time complexity -> O(n)
         */
        void loadShipping(const std::string& filename);
        /**
         * @brief Loads stadium information from a file.
         * @param filename The name of the file to load.
         * @throws runtime_error If the file fails to open.
         * @note Time complexity -> O(n)
         */
        void loadStadiums(const std::string& filename);
        /**
         * @brief Loads tourism information from a file.
         * @param filename  The name of the file to load.
         * @throws runtime_error If the file fails to open.
         * @note Time complexity -> O(n)
         */
        void loadTourism(const std::string& filename);
        /**
         * @brief Loads graph data from edges/nodes files for Real World Graphs
         * @param edgesFile The name of the file containing the edges.
         * @param nodesFile The name of the file containing the nodes.
         * @note Time complexity -> O(2 * n)
         */
        void loadGraph_RWG(const std::string& edgesFile, const std::string& nodesFile);
        /**
         * @brief Getter for the graph.
         * @return The loaded graph.
         * @note Time complexity -> O(1)
         */
        Graph getGraph();

    private:
        Graph graph;
        
};


#endif 
