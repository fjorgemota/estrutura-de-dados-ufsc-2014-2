// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAFORO_CPP
#define SEMAFORO_CPP
#include "Semaforo.hpp"

Semaforo::Semaforo(int intervalo) {
    this->intervalo = intervalo;
    this->aberto = SEMAFORO_LIBERADO;
    this->contador = 0;
}

int Semaforo::pegaIntervalo() {
    return this->intervalo;
}

int Semaforo::pegaContador() {
    return this->contador;
}

void Semaforo::acrescentaContador() {
    this->contador++;
}

bool Semaforo::estaAberto() {
    return this->aberto == SEMAFORO_ABERTO;
}

bool Semaforo::estaFechado() {
    return this->aberto == SEMAFORO_FECHADO;
}

void Semaforo::abre() {
    this->aberto = SEMAFORO_ABERTO;
}

void Semaforo::fecha() {
    this->aberto = SEMAFORO_FECHADO;
}
#endif /* SEMAFORO_CPP */
