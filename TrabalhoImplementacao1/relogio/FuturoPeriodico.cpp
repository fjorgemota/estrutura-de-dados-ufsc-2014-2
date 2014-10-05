// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_CPP
#define FUTURO_PERIODICO_CPP
#include "FuturoPeriodico.hpp"

FuturoPeriodico::FuturoPeriodico(int interv, char* desc) : Futuro(
    interv, desc) {}

FuturoPeriodico::FuturoPeriodico(int intervalo) : Futuro(intervalo) {}

FuturoPeriodico::FuturoPeriodico() : Futuro() {}

bool FuturoPeriodico::podeExecutar(int agora) {
    return (agora % this->pegaHora()) == 0;
}

bool FuturoPeriodico::podeRemover() {
    return false;
}

#endif /* FUTURO_PERIODICO_CPP */
