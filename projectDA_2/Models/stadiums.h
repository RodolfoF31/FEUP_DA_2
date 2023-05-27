//
// Created by rodolfo on 27/05/23.
//

#ifndef UNTITLED_STADIUMS_H
#define UNTITLED_STADIUMS_H


class Stadiums{
private:

    int origem;
    int destino;
    float distancia;

public:

    Stadiums();
    Stadiums(int origem, int destino, float distancia);
    void setOrigem(int n);
    void setDestino(int n);
    void setDistancia(float distancia);
    int getOrigem();
    int getDestino();
    float getDistancia();

};


#endif //UNTITLED_STADIUMS_H
