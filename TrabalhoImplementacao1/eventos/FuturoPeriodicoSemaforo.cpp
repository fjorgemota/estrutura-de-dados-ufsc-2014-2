// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_SEMAFORO_CPP
#define FUTURO_PERIODICO_SEMAFORO_CPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"
#include "FuturoPeriodicoSemaforo.hpp"

FuturoPeriodicoSemaforo::FuturoPeriodicoSemaforo(
    ListaDupla<Semaforo*> *semaforo, int intervalo) : FuturoPeriodico(
        intervalo) {
    this->semaforoEscolhido = semaforo->verUltimo();
    this->semaforo = semaforo;
}

void FuturoPeriodicoSemaforo::executa() {
    Semaforo *semaforoAtual, semaforoAnterior;
    semaforoAnterior = this->semaforo->mostra(this->semaforoEscolhido);
    this->semaforoEscolhido++;
    if(this->semaforoEscolhido > this->semaforo->verUltimo()) {
        this->semaforoEscolhido = 0;
    }
    semaforoAtual = this->semaforo->mostra(this->semaforoEscolhido);
    semaforoAnterior->fecha();
    semaforoAtual->abre();
}

#endif /* FUTURO_PERIODICO_SEMAFORO_CPP */
