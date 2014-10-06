// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_SUMIDOURA_CPP
#define PISTA_SUMIDOURA_CPP
#include "Pista.cpp"
#include "../eventos/FuturoPistaSumidoura.cpp"
#include "PistaSumidoura.hpp"

PistaSumidoura::PistaSumidoura(Relogio *relogio, Semaforo *semaforo,
    int tamanho, int velocidade, ListaDupla<T> pistas) : Pista(
    relogio, semaforo, tamanho, velocidade, pistas) {}

void PistaSumidoura::agendaCarro() {
    int veloc = this->velocidade/3.6;
    int tempo = this->tamanho / veloc;
    this->relogio->agendaDaquiA(new IntervaloPistaSumidoura(
        this, this->semaforo, intervalo));
}

#endif /* PISTA_SUMIDOURA_CPP */
