// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAFORO_CPP
#define SEMAFORO_CPP

#include <string>
#include "Semaforo.hpp"
#include "../relogio/Relogio.cpp"
#include "../relogio/Evento.cpp"

using std::string;

Semaforo::Semaforo(string descricao, Relogio *relogio) {
    this->descricao = descricao;
    this->relogio = relogio;
    this->aberto = SEMAFORO_FECHADO;
    this->contador = 0;
}

int Semaforo::pegaContador() {
    return this->contador;
}

string Semaforo::pegaDescricao() {
    return this->descricao;
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
    if (this->estaAberto()) {
        return;
    }
    this->aberto = SEMAFORO_ABERTO;
    string desc = "O semáforo " + this->pegaDescricao() + " está aberto";
    Evento *evento = new Evento(EVENTO_TROCA_ESTADO_SEMAFORO, desc);
    this->relogio->registra(evento);
}

void Semaforo::fecha() {
    if (this->estaFechado()) {
        return;
    }
    this->aberto = SEMAFORO_FECHADO;
    string desc = "O semáforo " + this->pegaDescricao() + " está fechado";
    Evento *evento = new Evento(EVENTO_TROCA_ESTADO_SEMAFORO, desc);
    this->relogio->registra(evento);
}

#endif /* SEMAFORO_CPP */
