// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "Fila.hpp"
#include "Lista.cpp"

Fila::Fila(int tamanhoMaximo) {
    this->lista = new Lista<int>(tamanhoMaximo);
}

bool Fila::filaCheia() {
    return this->lista->listaCheia();
}

bool Fila::filaVazia() {
    return this->lista->listaVazia();
}

void Fila::inclui(int dado) {
    this->lista->adicionar(dado);
}

void Fila::retira() {
    this->lista->removerPrimeiro();
}

int Fila::ultimo() {
    return this->lista->pegaPrimeiro();
}
