// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_PISTA_SUMIDOURA_HPP
#define INTERVALO_PISTA_SUMIDOURA_HPP
#include "TrabalhoImplementacao1/eventos/IntervaloPistaSumidoura.hpp"

IntervaloPistaSumidoura::IntervaloPistaSumidoura(PistaSumidoura* pista) {
    this->pista = pista;
}

void IntervaloPistaSumidoura::executa() {
    Carro* ultimo = this->pista->sairDaPista();
    delete ultimo;
}

#endif
