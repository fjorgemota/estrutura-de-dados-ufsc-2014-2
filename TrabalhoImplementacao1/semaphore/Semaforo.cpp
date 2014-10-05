// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef Semaforo_CPP
#define SEMAPHORE_CPP
#include "Semaforo.hpp"

Semaforo::Semaforo(int intervalo) {
    this->intervalo = intervalo;
    this->input = ListaEnc<Estrada*>();
    this->output = ListaEnc<Estrada*>();
}

int Semaforo::getintervalo() {
    return this->intervalo;
}

#endif
