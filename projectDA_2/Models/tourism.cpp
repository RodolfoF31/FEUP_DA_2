//
// Created by rodolfo on 27/05/23.
//

#include "tourism.h"

Tourism::Tourism() =  default;

Tourism::Tourism(int origem, int destino, float distancia, string labelorigem, string labeldestino) {

    this->origem = origem;
    this->destino = destino;
    this->distancia = distancia;
    this->labelorigem = labelorigem;
    this->labeldestino = labeldestino;

}

void Tourism::setOrigem(int n) {
    origem = n;
}

void Tourism::setDestino(int n) {
    destino = n;
}

void Tourism::setDistancia(float n) {
    distancia = n;
}

void Tourism::setlabeldestino(std::string n) {
    labeldestino = n;
}

void Tourism::setlabelorigem(std::string n) {
    n = origem;
}

int Tourism::getOrigem() {
    return origem;
}

int Tourism::getDestino() {
    return destino;
}

float Tourism::getDistancia() {
    return distancia;
}

string Tourism::getlabelorigem() {
    return labelorigem;
}

string Tourism::getlabeldestino() {
    return labeldestino;
}