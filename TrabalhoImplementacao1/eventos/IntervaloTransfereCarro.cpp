// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_TRANSFERE_CARRO_CPP
#define INTERVALO_TRANSFERE_CARRO_CPP
#include "TrabalhoImplementacao1/eventos/IntervaloTransfereCarro.hpp"

IntervaloTransfereCarro::IntervaloTransfereCarro(Pista* pista,
    Semaforo* semaforo) {
    this->pista = pista;
    this->semaforo = semaforo;
}

void IntervaloTransfereCarro::executa() {
    Pista* destino = this->pista->sorteiaPista();
    Carro* ultimo = this->pista->ultimo();
    if (destino->estaCheia(ultimo) && this->semaforo->estaAberto()) {
        ultimo = this->pista->sairDaPista();
        destino->adiciona(ultimo);
        this->semaforo->acrescentaContador();
    }
}

#endif
