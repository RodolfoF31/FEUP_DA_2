//
// Created by rodolfo on 27/05/23.
//

#include "stadiums.h"

Stadiums::Stadiums() = default;

Stadiums::Stadiums(int origem, int destino, float distancia) {

    this->origem = origem;
    this->destino = destino;
    this->distancia = distancia;

}

void Stadiums::setDestino(int n) {
    destino = n;
}

void Stadiums::setOrigem(int n) {
    origem = n;
}

void Stadiums::setDistancia(float n) {
    distancia = n;
}

int Stadiums::getOrigem() {
    return origem;
}

int Stadiums::getDestino() {
    return destino;
}

float Stadiums::getDistancia() {
    return distancia;
}
