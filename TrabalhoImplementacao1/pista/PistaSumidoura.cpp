// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_SUMIDOURA_CPP
#define PISTA_SUMIDOURA_CPP
#include "Pista.cpp"
#include "PistaSumidoura.hpp"
#include "../eventos/FuturoPistaSumidoura.cpp"

PistaSumidoura::PistaSumidoura(Relogio *relogio,
    int tamanho, int velocidade) : Pista(
    relogio, NULL, tamanho, velocidade, NULL) {}

void PistaSumidoura::agendaNovoCarro() {
    int veloc = this->velocidade/3.6;
    int intervalo = this->tamanhoMaximo / veloc;
    this->relogio->agendaDaquiA(new FuturoPistaSumidoura(
        this), intervalo);
}

#endif /* PISTA_SUMIDOURA_CPP */
