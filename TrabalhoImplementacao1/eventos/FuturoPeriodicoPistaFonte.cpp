// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_PISTA_FONTE_CPP
#define FUTURO_PERIODICO_PISTA_FONTE_CPP
#include "../pista/PistaFonte.cpp"
#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../carro/Carro.cpp"
#include "FuturoPeriodicoPistaFonte.hpp"

FuturoPeriodicoPistaFonte::FuturoPeriodicoPistaFonte(PistaFonte *pista,
    Relogio *relogio, int intervaloMinimo,
    int intervaloMaximo) : FuturoPeriodico() {
    this->pista = pista;
    this->relogio = relogio;
    this->intervaloMinimo = intervaloMinimo;
    this->intervaloMaximo = intervaloMaximo;
}

void FuturoPeriodicoPistaFonte::agendar() {
    int intervalo = SORTEIA(this->intervaloMinimo, this->intervaloMaximo);
    this->configuraSegundo(this->relogio->pegaSegundoAtual() + intervalo);
}

void FuturoPeriodicoPistaFonte::executar() {
    Carro *carro = new Carro();
    bool sucesso = this->pista->adiciona(carro);
    if (sucesso == true) {
        Evento *evento = new Evento(EVENTO_CARRO_ENTRA_PISTA,
                                    "Um novo carro foi adicionado à pista");
        this->relogio->registra(evento);
    }
    this->agendar();
}

bool FuturoPeriodicoPistaFonte::podeExecutar(int segundoAtual) {
    return segundoAtual == this->pegaSegundo();
}

#endif /* FUTURO_PERIODICO_PISTA_FONTE_CPP */
