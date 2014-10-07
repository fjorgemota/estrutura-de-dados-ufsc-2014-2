// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_SEMAFORO_CPP
#define FUTURO_PERIODICO_SEMAFORO_CPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"
#include "FuturoPeriodicoSemaforo.hpp"

FuturoPeriodicoSemaforo::FuturoPeriodicoSemaforo(
    ListaDupla<Semaforo*> *semaforos, int intervalo) : FuturoPeriodico(
        intervalo, (char*) "Futuro Periodico Semaforo") {
    this->semaforoEscolhido = semaforos->verUltimo();
    this->fechaTodos = false;
    this->semaforos = semaforos;
}

void FuturoPeriodicoSemaforo::executar() {
    Semaforo *semaforoAtual, semaforoAnterior;
    semaforoAnterior = this->semaforos->mostra(this->semaforoEscolhido);
    this->semaforoEscolhido++;
    if(this->semaforoEscolhido > this->semaforos->verUltimo()) {
        this->semaforoEscolhido = 0;
    }
    semaforoAtual = this->semaforos->mostra(this->semaforoEscolhido);
    semaforoAnterior->fecha();
    if(this->fechaTodos == false) {
        semaforoAtual->abre();
    }
    this->fechaTodos = this->fechaTodos == false;
}

#endif /* FUTURO_PERIODICO_SEMAFORO_CPP */
