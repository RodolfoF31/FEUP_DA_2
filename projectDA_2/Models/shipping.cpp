//
// Created by rodolfo on 27/05/23.
//

#include "shipping.h"

Shipping::Shipping() = default;

Shipping::Shipping(int origem, int destino, float distancia) {

    this->origem = origem;
    this->destino = destino;
    this->distancia = distancia;

}

void Shipping::setDestino(int n) {
    destino = n;
}

void Shipping::setOrigem(int n) {
    origem = n;
}

void Shipping::setDistancia(float n) {
    distancia = n;
}

int Shipping::getOrigem() {
    return origem;
}

int Shipping::getDestino() {
    return destino;
}

float Shipping::getDistancia() {
    return distancia;
}
