// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_SEMAFORO_CPP
#define FUTURO_PERIODICO_SEMAFORO_CPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"
#include "FuturoPeriodicoSemaforo.hpp"

FuturoPeriodicoSemaforo::FuturoPeriodicoSemaforo(Semaforo *semaforo) : FuturoPeriodico(
    semaforo->pegaIntervalo()) {
    this->semaforo = semaforo;
}

void FuturoPeriodicoSemaforo::executa() {
    if (this->semaforo->estaAberto()) {
        this->semaforo->fecha();
    } else {
        this->semaforo->abre();
    }
}

#endif /* FUTURO_PERIODICO_SEMAFORO_CPP */
