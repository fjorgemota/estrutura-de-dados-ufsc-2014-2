// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_CPP
#define GERADOR_SEMAFORO_CPP
#include "GeradorSemaforo.hpp"

GeradorSemaforo::GeradorSemaforo(int intervalo) {
    this->intervalo = intervalo;
}

Semaforo* GeradorSemaforo::geraSemO1leste() {
    Semaforo *O1leste = new Semaforo(this->intervalo);
    return O1leste;
}

Semaforo* GeradorSemaforo::geraSemN1sul() {
    Semaforo *N1sul = new Semaforo(this->intervalo);
    return N1sul;
}

Semaforo* GeradorSemaforo::geraSemS1norte() {
    Semaforo *S1norte = new Semaforo(this->intervalo);
    return S1norte;
}

Semaforo* GeradorSemaforo::geraSemN2sul() {
    Semaforo *N2sul = new Semaforo(this->intervalo);
    return N2sul;
}

Semaforo* GeradorSemaforo::geraSemS2norte() {
    Semaforo *S2norte = new Semaforo(this->intervalo);
    return S2norte;
}

Semaforo* GeradorSemaforo::geraSemC1leste() {
    Semaforo *C1leste = new Semaforo(this->intervalo);
    return C1leste;
}

Semaforo* GeradorSemaforo::geraSemC1oeste() {
    Semaforo *C1oeste = new Semaforo(this->intervalo);
    return C1oeste;
}

Semaforo* GeradorSemaforo::geraSemL1oeste() {
    Semaforo *L1oeste = new Semaforo(this->intervalo);
    return L1oeste;
}

#endif 
