// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ROAD_CPP
#define ROAD_CPP
#include "pista/Pista.hpp"
#include "util/FilaEnc.cpp"

Pista::Pista(int tamanho, int velocidade) {
    this->tamanho = tamanho;
    this->velocidade = velocidade;
}

int Pista::pegaTamanho() {
    return this->tamanho;
}

int Pista::pegaVelocidade() {
    return this->velocidade;
}

#endif /* ROAD_CPP */
