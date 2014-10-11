// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef CARRO_CPP
#define CARRO_CPP
#include "../util/NumeroAleatorio.hpp"
#include "Carro.hpp"
#define CARRO_TAMANHO_MINIMO 2
#define CARRO_TAMANHO_MAXIMO 6

Carro::Carro() {
    this->tamanho = SORTEIA(CARRO_TAMANHO_MINIMO, CARRO_TAMANHO_MAXIMO);
}

Carro::~Carro() {}

int Carro::pegaTamanho() {
    return 1 + this->tamanho + 2;
}

#endif /* CARRO_CPP */
