// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_CPP
#define PISTA_CPP
#include <cstdlib>
#include "Pista.hpp"
#include "../util/FilaEnc.cpp"
#include "../util/NumeroAleatorio.hpp"
#include "../eventos/IntervaloTransfereCarro.cpp"

Pista::Pista(Relogio *relogio, Semaforo *semaforo, int tamanho,
    int velocidade) : FilaEnc() {
    this->relogio = relogio;
    this->tamanho = tamanho;
    this->velocidade = velocidade;
    this->tamanhoDisponivel = velocidade;
    this->pistasSaida = ListaDupla<Pista>();
}

int Pista::pegaTamanho() {
    return this->tamanho;
}

int Pista::pegaVelocidade() {
    return this->velocidade;
}

void Pista::agendaNovoCarro() {
    int veloc = this->velocidade/3.6;
    int intervalo = this->tamanho / veloc;
    this->relogio->agendaDaquiA(new IntervaloTransfereCarro(
        this, this->semaforo, intervalo));
}

bool Pista::adiciona(Carro* carro) {
    if (!this->estaCheia(carro)) {
        return false;
    }
    this->inclui(carro);
    this->agendaNovoCarro();
    this->tamanhoDisponivel -= carro->pegaTamanho();
    return true;
}

Carro Pista::sairDaPista() {
    Carro* carro = this->retira();
    this->tamanhoDisponivel += carro->pegaTamanho();
    return carro;
}

Pista Pista::sorteiaPista() {
    int sorteio = SORTEIA(0, 99);
    return this->pistasSaida->mostra(sorteio);
}

bool Pista::estaCheia(Carro* carro) {
    int temporario = this->tamanhoDisponivel - carro->pegaTamanho();
    return temporario >= 0;
}

void Pista::adicionaPistaSaida(Pista* pista) {
    this->pistasSaida->adicionaDuplo(pista);
}

#endif /* PISTA_CPP */
