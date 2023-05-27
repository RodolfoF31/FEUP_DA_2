//
// Created by rodolfo on 27/05/23.
//

#ifndef UNTITLED_SHIPPING_H
#define UNTITLED_SHIPPING_H


class Shipping {
private:

    int origem;
    int destino;
    float distancia;

public:

    Shipping();
    Shipping(int origem, int destino, float distancia);
    void setOrigem(int n);
    void setDestino(int n);
    void setDistancia(float distancia);
    int getOrigem();
    int getDestino();
    float getDistancia();

};


#endif //UNTITLED_SHIPPING_H
