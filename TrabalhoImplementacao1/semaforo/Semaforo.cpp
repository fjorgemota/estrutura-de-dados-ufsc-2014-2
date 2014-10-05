// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAFORO_CPP
#define SEMAFORO_CPP
#include "Semaforo.hpp"

Semaforo::Semaforo(int intervalo) {
    this->intervalo = intervalo;
    this->entrada = ListaEnc<Estrada*>();
    this->saida = ListaEnc<Estrada*>();
}

int Semaforo::pegaIntervalo() {
    return this->intervalo;
}

#endif
