// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_PISTA_FONTE_CPP
#define FUTURO_PERIODICO_PISTA_FONTE_CPP
#include "./pista/PistaFonte.cpp"
#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../carro/Carro.cpp"

FuturoPeriodicoPistaFonte::FuturoPeriodicoPistaFonte(PistaFonte *pista,
    Relogio *relogio, int intervaloMinimo,
    int intervaloMaximo) : FuturoPeriodico() {
    this->pista = pista;
    this->relogio = relogio;
    this->intervaloMinimo = intervaloMinimo;
    this->intervaloMaximo = intervaloMaximo;
}

void FuturoPeriodicoPistaFonte::agenda() {
    int intervalo = SORTEIA(this->intervaloMinimo, this->intervaloMaximo);
    this->configuraHora(this->relogio->pegaHoraAtual() + intervalo);
}

void FuturoPeriodicoPistaFonte::executa() {
    Carro *carro = new Carro();
    this->pista->adiciona(carro);
    this->agenda();
}

#endif /* FUTURO_PERIODICO_PISTA_FONTE_CPP */
