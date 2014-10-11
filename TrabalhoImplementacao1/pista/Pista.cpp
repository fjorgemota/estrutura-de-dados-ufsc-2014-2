// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_CPP
#define PISTA_CPP
#include <cstdlib>
#include "Pista.hpp"
#include "../util/FilaEnc.cpp"
#include "../util/NumeroAleatorio.hpp"
#include "../eventos/FuturoTransfereCarro.cpp"

Pista::Pista(Relogio *relogio, Semaforo *semaforo, int tamanhoMaximo,
    int velocidade, ListaDupla<Pista*> *pistasSaida) : FilaEnc() {
    this->relogio = relogio;
    this->semaforo = semaforo;
    this->tamanhoMaximo = tamanhoMaximo;
    this->velocidade = velocidade;
    this->tamanhoDisponivel = tamanhoMaximo;
    this->pistasSaida = pistasSaida;
}

Pista::~Pista() {
    this->limparFila();
    if (this->pistasSaida != NULL) {
        delete this->pistasSaida;
    }
}

int Pista::pegaTamanhoMaximo() {
    return this->tamanhoMaximo;
}

int Pista::pegaVelocidade() {
    return this->velocidade;
}

void Pista::agendaNovoCarro() {
    int veloc = this->velocidade/3.6;
    int intervalo = this->tamanhoMaximo / veloc;
    this->relogio->agendaDaquiA(new FuturoTransfereCarro(
        this, this->semaforo, this->relogio), intervalo);
}

bool Pista::adiciona(Carro* carro) {
    if (this->estaCheia(carro)) {
        return false;
    }
    this->inclui(carro);
    this->agendaNovoCarro();
    this->tamanhoDisponivel -= carro->pegaTamanho();
    return true;
}

Carro* Pista::sairDaPista() {
    Carro* carro = this->retira();
    this->tamanhoDisponivel += carro->pegaTamanho();
    return carro;
}

Carro* Pista::ultimoCarro() {
    return this->ultimo();
}

Pista* Pista::sorteiaPista() {
    int sorteio = SORTEIA(0, this->pistasSaida->verUltimo());
    return this->pistasSaida->mostra(sorteio);
}

bool Pista::estaCheia(Carro* carro) {
    int temporario = this->tamanhoDisponivel - carro->pegaTamanho();
    return temporario < 0;
}

#endif /* PISTA_CPP */
