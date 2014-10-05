// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_PISTA_FONTE_CPP
#define INTERVALO_PISTA_FONTE_CPP
#include <cstdlib>
#include "./pista/PistaFonte.cpp"
#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../carro/Carro.cpp"

IntervaloPistaFonte::IntervaloPistaFonte(PistaFonte *pista,  Relogio *relogio, int intervaloMinimo, int intervaloMaximo) : FuturoPeriodico() {
    this->pista = pista;
    this->relogio = relogio;
    this->intervaloMinimo = intervaloMinimo;
    this->intervaloMaximo = intervaloMaximo;
}

void IntervaloPistaFonte::agenda(){
    int intervalo = (int) this->intervaloMinimo + (rand(NULL)*(this->intervaloMaximo - this->intervaloMinimo));
    this->configuraHora(this->relogio->pegaHoraAtual() + intervalo);
}

void IntervaloPistaFonte::executa() {
    Carro *carro = new Carro();
    this->pista->adiciona(carro);
    this->agenda();
}

#endif /* INTERVALO_PISTA_FONTE_CPP */