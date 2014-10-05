// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_SEMAFORO_CPP
#define INTERVALO_SEMAFORO_CPP
#include "../relogio/FuturoPeriodico.cpp"

IntervaloSemaforo::IntervaloSemaforo(Semaforo *semaforo) : FuturoPeriodico(
    semaforo->pegaIntervalo()) {
    this->semaforo = semaforo;
}

void IntervaloSemaforo::executa() {
    if (this->semaforo->estaAberto()) {
        this->semaforo->fecha();
    } else {
        this->semaforo->abre();
    }
}

#endif /* INTERVALO_SEMAFORO_CPP */
