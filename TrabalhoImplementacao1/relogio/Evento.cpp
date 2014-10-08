// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef EVENTO_CPP
#define EVENTO_CPP
#include <string>
#include "Evento.hpp"

using std::string;

Evento::Evento(int segundo, int tipo, string descricao) {
    this->segundo = segundo;
    this->tipo = tipo;
    this->descricao = descricao;
}

Evento::Evento(int segundo, int tipo) {
    this->segundo = segundo;
    this->tipo = tipo;
    this->descricao = "Sem descrição";
}

Evento::Evento(int tipo, string descricao) {
    this->segundo = -1;
    this->tipo = tipo;
    this->descricao = descricao;
}

Evento::Evento(string descricao) {
    this->segundo = -1;
    this->tipo = EVENTO_LOG;
    this->descricao = descricao;
}

Evento::~Evento() {}

int Evento::pegaSegundo() {
    return this->segundo;
}

void Evento::configuraSegundo(int segundo) {
    this->segundo = segundo;
}

int Evento::pegaTipo() {
    return this->tipo;
}

string Evento::pegaDescricao() {
    return this->descricao;
}
#endif /* EVENTO_CPP */
