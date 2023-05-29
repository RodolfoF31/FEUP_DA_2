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
        void loadShipping();
        void loadTourism();
        void loadStadiums();
        Graph graph;

        
};


#endif // FILEMAN_H
