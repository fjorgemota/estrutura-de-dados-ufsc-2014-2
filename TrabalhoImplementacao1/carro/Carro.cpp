// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef CARRO_CPP
#define CARRO_CPP
#include "Car.hpp"

Carro::Carro(int tamanho) {
    this->tamanho = tamanho;
}

int Carro::pegaTamanho() {
    return 1 + this->tamanho + 2;
}

#endif /* CARRO_CPP */
