// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_CPP
#define PISTA_CPP
#include "Pista.hpp"
#include "../util/FilaEnc.cpp"

Pista::Pista(int tamanho, int velocidade) : FilaEnc() {
    this->tamanho = tamanho;
    this->velocidade = velocidade;
}

int Pista::pegaTamanho() {
    return this->tamanho;
}

int Pista::pegaVelocidade() {
    return this->velocidade;
}

#endif /* PISTA_CPP */
