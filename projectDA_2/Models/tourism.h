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
    float distancia;
    string labelorigem;
    string labeldestino;
public:

    Tourism();
    Tourism(int origem, int destino, float distancia, string labelorigem, string labeldestino);
    void setOrigem(int n);
    void setDestino(int n);
    void setDistancia(float n);
    void setlabelorigem(string n);
    void setlabeldestino(string n);
    int getOrigem();
    int getDestino();
    float getDistancia();
    string getlabelorigem();
    string getlabeldestino();

};


#endif //UNTITLED_TOURISM_H
