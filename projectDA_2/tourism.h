//
// Created by rodolfo on 27/05/23.
//

#ifndef UNTITLED_TOURISM_H
#define UNTITLED_TOURISM_H

#include <string>
using namespace std;

class Tourism {
private:

    int origem;
    int destino;
    double distancia;
    string labelorigem;
    string labeldestino;
public:

    Tourism();
    Tourism(int origem, int destino, double distancia, string labelorigem, string labeldestino);
    void setOrigem(int n);
    void setDestino(int n);
    void setDistancia(double n);
    void setlabelorigem(string n);
    void setlabeldestino(string n);
    int getOrigem();
    int getDestino();
    double getDistancia();
    string getlabelorigem();
    string getlabeldestino();

};


#endif //UNTITLED_TOURISM_H