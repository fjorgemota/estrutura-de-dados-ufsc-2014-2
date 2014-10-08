// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_CPP
#define FUTURO_CPP
#include <string>
#include "Futuro.hpp"

using std::string;

Futuro::Futuro(int intervalo, string desc) : Evento(
    intervalo,
    EVENTO_FUTURO,
    desc) {
    this->remover = false;
}

Futuro::Futuro(int intervalo) : Evento(intervalo, EVENTO_FUTURO) {
    this->remover = false;
}

Futuro::Futuro(string desc) : Evento(-1, EVENTO_FUTURO, desc) {
    this->remover = false;
}


Futuro::Futuro() : Evento(-1, EVENTO_FUTURO) {
    this->remover = false;
}

Futuro::~Futuro() {}

bool Futuro::podeExecutar(int segundoAtual) {
    bool resultado = this->pegaSegundo() == segundoAtual;
    if (resultado) {
        this->remover = true;
    }
    return resultado;
}

bool Futuro::podeRemover() {
    return this->remover;
}
#endif /* FUTURO_CPP */
