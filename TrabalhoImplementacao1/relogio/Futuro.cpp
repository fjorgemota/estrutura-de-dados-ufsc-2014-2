// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_CPP
#define FUTURO_CPP
#include "Futuro.hpp"

Futuro::Futuro(int intervalo, char* desc) : Evento(
    intervalo,
    EVENTO_FUTURO,
    desc) {
    this->remover = false;
}

Futuro::Futuro(int intervalo) : Evento(intervalo, EVENTO_FUTURO) {
    this->remover = false;
}

bool Futuro::podeExecutar(int now) {
    bool resultado = this->pegaHora() == now;
    if (resultado) {
        this->remover = true;
    }
    return resultado;
}

bool Futuro::podeRemover() {
    return this->remover;
}
#endif /* FUTURO_CPP */
