// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_CPP
#define FUTURO_PERIODICO_CPP

#include <string>
#include "FuturoPeriodico.hpp"

using std::string;

FuturoPeriodico::FuturoPeriodico(int interv, string desc) : Futuro(
    interv, desc) {}

FuturoPeriodico::FuturoPeriodico(int intervalo) : Futuro(intervalo) {}

FuturoPeriodico::FuturoPeriodico(string descricao) : Futuro(descricao) {}

FuturoPeriodico::FuturoPeriodico() : Futuro() {}

FuturoPeriodico::~FuturoPeriodico() {}

bool FuturoPeriodico::podeExecutar(int agora) {
    int horaEvento = this->pegaSegundo();
    if (horaEvento == 0) {
        throw "O intervalo periódico não pode ser zero";
    }
    return horaEvento != -1 && (agora % horaEvento) == 0;
}

bool FuturoPeriodico::podeRemover() {
    return false;
}

#endif /* FUTURO_PERIODICO_CPP */
