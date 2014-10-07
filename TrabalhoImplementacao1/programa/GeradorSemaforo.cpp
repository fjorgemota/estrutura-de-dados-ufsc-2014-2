// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_CPP
#define GERADOR_SEMAFORO_CPP
#include "GeradorSemaforo.hpp"
#include "../util/ListaDupla.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../eventos/FuturoPeriodicoSemaforo.cpp"
#inlude "../relogio/Relogio.cpp"

GeradorSemaforo::GeradorSemaforo(Relogio *relogio, int intervalo) {
    this->semO1leste = new Semaforo();
    this->semN1sul = new Semaforo();
    this->semN2sul = new Semaforo();
    this->semS1norte = new Semaforo();
    this->semS2norte = new Semaforo();
    this->semC1oeste = new Semaforo();
    this->semC1leste = new Semaforo();
    this->semL1oeste = new Semaforo();
    this->agendaSemaforosS1(relogio, intervalo);
    this->agendaSemaforosS2(relogio, intervalo);
}

Semaforo* GeradorSemaforo::pegaSemO1leste() {
    return this->semO1leste;
}

Semaforo* GeradorSemaforo::pegaSemN1sul() {
    return this->semN1sul;
}

Semaforo* GeradorSemaforo::pegaSemS1norte() {
    return this->semS1norte;
}

Semaforo* GeradorSemaforo::pegaSemN2sul() {
    return this->semN2sul;
}

Semaforo* GeradorSemaforo::pegaSemS2norte() {
    return this->semS2norte;
}

Semaforo* GeradorSemaforo::pegaSemC1leste() {
    return this->semC1leste;
}

Semaforo* GeradorSemaforo::pegaSemC1oeste() {
    return this->semC1oeste;
}

Semaforo* GeradorSemaforo::pegaSemL1oeste() {
    return this->semL1oeste;
}

void GeradorSemaforo::agendaSemaforosS1(Relogio *relogio, int intervalo) {
    ListaDupla<Semaforo*> *semaforos = new ListaDupla<Semaforo*>();
    semaforos->adicionaDuplo(this->pegaSemN1sul());
    semaforos->adicionaDuplo(this->pegaSemC1oeste());
    semaforos->adicionaDuplo(this->pegaSemS1norte());
    semaforos->adicionaDuplo(this->pegaSemO1leste());
    relogio->agenda(new FuturoPeriodicoSemaforo(semaforos, intervalo));
}


void GeradorSemaforo::agendaSemaforosS2(Relogio *relogio, int intervalo) {
    ListaDupla<Semaforo*> *semaforos = new ListaDupla<Semaforo*>();
    semaforos->adicionaDuplo(this->pegaSemN2sul());
    semaforos->adicionaDuplo(this->pegaSemL1oeste());
    semaforos->adicionaDuplo(this->pegaSemS2norte());
    semaforos->adicionaDuplo(this->pegaSemC1leste());
    relogio->agenda(new FuturoPeriodicoSemaforo(semaforos, intervalo));
}

#endif /* GERADOR_SEMAFORO_CPP */
