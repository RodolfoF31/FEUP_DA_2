#ifndef FILEMAN_H
#define FILEMAN_H

#include <iostream>
#include <vector>
#include "shipping.h"
#include "stadiums.h"
#include "tourism.h"
#include <fstream>
#include <sstream>
#include "Graph.h"



class Fileman {

    public:
        Fileman();
        void loadShipping(const std::string& filename);
        void loadTourism(const std::string& filename);
        void loadStadiums(const std::string& filename);
        void loadGraph_RWG(const std::string& edgesFile, const std::string& nodesFile);
        Graph getGraph();

    private:
        Graph graph;
        
};


#endif // FILEMAN_H
