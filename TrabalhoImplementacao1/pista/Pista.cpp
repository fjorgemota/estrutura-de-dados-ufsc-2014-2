// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_CPP
#define PISTA_CPP
#include "Pista.hpp"
#include "../util/FilaEnc.cpp"

Pista::Pista(int tamanho, int velocidade, ListaDupla<T> pistas) : FilaEnc() {
    this->tamanho = tamanho;
    this->velocidade = velocidade;
    this->tamanhoDisponivel = velocidade;
    this->pistasSaida = pistas;
}

int Pista::pegaTamanho() {
    return this->tamanho;
}

int Pista::pegaVelocidade() {
    return this->velocidade;
}

bool Pista::adiciona(Carro* carro) {
    if (this->estaCheia(carro)) {
        return false;
    }
    int tempo = this->tamanho / this->velocidade;
    this->inclui(carro);
    this->tamanhoDisponivel -= carro->pegaTamanho();
    return true;
}

Carro Pista::sairDaPista() {
    Carro* carro = this->retira();
    this->tamanhoDisponivel += carro->pegaTamanho();
    return carro;
}

void Pista::transfere() {
    Carro* ultimo = this->ultimo();
    Pista destino = this->sorteiaPista();
    if (destino->estaCheia(ultimo)) {
        ultimo = this->sairDaPista();
        destino->adiciona(ultimo);
    }
}

Pista Pista::sorteiaPista() {
    int sorteio = rand() % 100;
    return this->pistasSaida->mostra(sorteio);
}

bool Pista::estaCheia(Carro* carro) {
    int temporario = this->tamanhoDisponivel - carro->pegaTamanho();
    return temporario >= 0;
}

#endif /* PISTA_CPP */
