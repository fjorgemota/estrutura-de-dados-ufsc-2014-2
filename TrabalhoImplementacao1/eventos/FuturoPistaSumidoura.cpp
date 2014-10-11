// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PISTA_SUMIDOURA_CPP
#define FUTURO_PISTA_SUMIDOURA_CPP
#include "FuturoPistaSumidoura.hpp"
#include "../pista/PistaSumidoura.cpp"
#include "../carro/Carro.cpp"

FuturoPistaSumidoura::FuturoPistaSumidoura(PistaSumidoura* pista) {
    this->pista = pista;
}

void FuturoPistaSumidoura::executar() {
    Carro* ultimo = this->pista->sairDaPista();
    delete ultimo;
}

#endif /* FUTURO_PISTA_SUMIDOURA_CPP */
