// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "Pilha.hpp"
#include "Lista.hpp"

Pilha::Pilha(int t) {
    this->lista = new Lista(t);
}

int Pilha::topo() {
    return this->lista->pegaUltimo();
}

bool Pilha::PilhaVazia() {
    return this->lista->listaVazia();
}

int Pilha::getPosTopo() {
    return this->lista->pegaTamanho();
}

void Pilha::empilha(int dado) {
    this->lista->adicionar(dado);
}

int Pilha::desempilha() {
    this->lista->removerUltimo();
}

bool Pilha::PilhaCheia() {
    return this->lista->listaCheia();
}

void Pilha::limparPilha() {
    this->lista->limpaLista();
}
