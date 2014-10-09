// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_CPP
#define GERADOR_SEMAFORO_CPP
#include "GeradorSemaforo.hpp"
#include "../util/ListaDupla.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../eventos/FuturoPeriodicoSemaforo.cpp"
#include "../relogio/Relogio.cpp"

GeradorSemaforo::GeradorSemaforo(Relogio *relogio) {
    this->relogio = relogio;
    this->semO1leste = new Semaforo("O1Leste", relogio);
    this->semN1sul = new Semaforo("N1Sul", relogio);
    this->semN2sul = new Semaforo("N2Sul", relogio);
    this->semS1norte = new Semaforo("S1Norte", relogio);
    this->semS2norte = new Semaforo("S2Norte", relogio);
    this->semC1oeste = new Semaforo("C1Oeste", relogio);
    this->semC1leste = new Semaforo("C1Leste", relogio);
    this->semL1oeste = new Semaforo("L1Oeste", relogio);
}

GeradorSemaforo::~GeradorSemaforo() {
    delete this->semO1leste;
    delete this->semN1sul;
    delete this->semN2sul;
    delete this->semS1norte;
    delete this->semS2norte;
    delete this->semC1oeste;
    delete this->semC1leste;
    delete this->semL1oeste;
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

void GeradorSemaforo::agendaSemaforosS1(int intervalo) {
    ListaDupla<Semaforo*> *semaforos = this->pegaSemaforosS1();
    this->relogio->agenda(new FuturoPeriodicoSemaforo(semaforos, intervalo));
}


void GeradorSemaforo::agendaSemaforosS2(int intervalo) {
    ListaDupla<Semaforo*> *semaforos = this->pegaSemaforosS2();
    this->relogio->agenda(new FuturoPeriodicoSemaforo(semaforos, intervalo));
}

ListaDupla<Semaforo*>* GeradorSemaforo::pegaSemaforosS1() {
    ListaDupla<Semaforo*> *semaforos = new ListaDupla<Semaforo*>();
    semaforos->adicionaDuplo(this->pegaSemN1sul());
    semaforos->adicionaDuplo(this->pegaSemC1oeste());
    semaforos->adicionaDuplo(this->pegaSemS1norte());
    semaforos->adicionaDuplo(this->pegaSemO1leste());
    return semaforos;
}

ListaDupla<Semaforo*>* GeradorSemaforo::pegaSemaforosS2() {
    ListaDupla<Semaforo*> *semaforos = new ListaDupla<Semaforo*>();
    semaforos->adicionaDuplo(this->pegaSemN2sul());
    semaforos->adicionaDuplo(this->pegaSemL1oeste());
    semaforos->adicionaDuplo(this->pegaSemS2norte());
    semaforos->adicionaDuplo(this->pegaSemC1leste());
    return semaforos;
}
#endif /* GERADOR_SEMAFORO_CPP */
