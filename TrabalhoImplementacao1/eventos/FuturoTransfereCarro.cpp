// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_TRANSFERE_CARRO_CPP
#define FUTURO_TRANSFERE_CARRO_CPP
#include "../pista/Pista.cpp"
#include "../carro/Carro.cpp"
#include "../relogio/Evento.cpp"
#include "../semaforo/Semaforo.cpp"
#include "FuturoTransfereCarro.hpp"


FuturoTransfereCarro::FuturoTransfereCarro(FuturoTransfereCarro *futuro) {
    this->pista = futuro->pista;
    this->semaforo = futuro->semaforo;
    this->relogio = futuro->relogio;
    this->tentativa = true;
}


FuturoTransfereCarro::FuturoTransfereCarro(Pista* pista,
    Semaforo* semaforo, Relogio *relogio) : Futuro() {
    this->pista = pista;
    this->semaforo = semaforo;
    this->relogio = relogio;
    this->tentativa = false;
}

void FuturoTransfereCarro::executar() {
    Pista* destino = this->pista->sorteiaPista();
    Carro* ultimo = this->pista->ultimoCarro();
    if(this->tentativa == false) {
        Evento *evento = new Evento(EVENTO_CARRO_CHEGA_SEMAFORO,
                                        "O carro chegou ao semáforo");
        this->relogio->registra(evento);
    }
    if (destino->estaCheia(ultimo) == false && this->semaforo->estaAberto()) {
        ultimo = this->pista->sairDaPista();
        destino->adiciona(ultimo);
        this->semaforo->acrescentaContador();
        Evento *evento1 = new Evento(EVENTO_TROCA_PISTA,
                                    "O carro trocou de pista");
        this->relogio->registra(evento1);
    } else {
        // Tenta executar de novo no próximo loop
        this->relogio->agendaDaquiA(new FuturoTransfereCarro(
            this), 1);
    }
    
}

#endif /* FUTURO_TRANSFERE_CARRO_CPP */
