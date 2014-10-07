// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_TRANSFERE_CARRO_CPP
#define FUTURO_TRANSFERE_CARRO_CPP
#include "../pista/Pista.cpp"
#include "../carro/Carro.cpp"
#include "../semaforo/Semaforo.cpp"
#include "FuturoTransfereCarro.cpp"

FuturoTransfereCarro::FuturoTransfereCarro(Pista* pista,
    Semaforo* semaforo, int intervalo) : Futuro(intervalo) {
    this->pista = pista;
    this->semaforo = semaforo;
}

void FuturoTransfereCarro::executar() {
    Pista* destino = this->pista->sorteiaPista();
    Carro* ultimo = this->pista->ultimo();
    if (destino->estaCheia(ultimo) && this->semaforo->estaAberto()) {
        ultimo = this->pista->sairDaPista();
        destino->adiciona(ultimo);
        this->semaforo->acrescentaContador();
    }
}

#endif /* FUTURO_TRANSFERE_CARRO_CPP */
