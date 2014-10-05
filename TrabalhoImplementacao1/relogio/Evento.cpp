// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef EVENTO_CPP
#define EVENTO_CPP
#include "Evento.hpp"

Evento::Evento(int hora, int tipo, char* descricao) {
    this->hora = hora;
    this->tipo = tipo;
    this->descricao = descricao;
}

Evento::Evento(int hora, int tipo) {
    this->hora = hora;
    this->tipo = tipo;
    this->descricao = const_cast<char*>("Sem descrição");
}

Evento::Evento(int tipo, char* descricao) {
    this->hora = -1;
    this->tipo = tipo;
    this->descricao = descricao;
}

Evento::Evento(char* descricao) {
    this->hora = -1;
    this->tipo = EVENTO_LOG;
    this->descricao = descricao;
}

int Evento::pegaHora() {
    return this->hora;
}

void Evento::configuraHora(int hora) {
    this->hora = hora;
}

int Evento::pegaTipo() {
    return this->tipo;
}

char* Evento::pegaDescricao() {
    return this->descricao;
}
#endif
