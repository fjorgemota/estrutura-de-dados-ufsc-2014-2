// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_CPP
#define FUTURO_PERIODICO_CPP
#include "FuturoPeriodico.hpp"

FuturoPeriodico::FuturoPeriodico(int interv, char* desc):Futuro(interv, desc) {}

FuturoPeriodico::FuturoPeriodico(int interval) : Futuro(interval) {}

bool FuturoPeriodico::podeExecutar(int now) {
    return (now % this->pegaHora()) == 0;
}

bool FuturoPeriodico::podeRemover() {
    return false;
}
#endif
