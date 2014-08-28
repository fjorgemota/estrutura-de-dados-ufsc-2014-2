// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PILHA_CPP
#define PILHA_CPP

#include "Pilha.hpp"
#include "Lista.cpp"

template<typename T>
Pilha<T>::Pilha(int t) {
    this->lista = new Lista<T>(t);
}

template<typename T>
T Pilha<T>::topo() {
    return this->lista->pegaUltimo();
}

template<typename T>
bool Pilha<T>::PilhaVazia() {
    return this->lista->listaVazia();
}

template<typename T>
int Pilha<T>::getPosTopo() {
    return this->lista->pegaTamanho();
}

template<typename T>
void Pilha<T>::empilha(T dado) {
    this->lista->adicionar(dado);
}

template<typename T>
T Pilha<T>::desempilha() {
    T ultimo = this->lista->pegaUltimo();
    this->lista->removerUltimo();
    return ultimo;
}

template<typename T>
bool Pilha<T>::PilhaCheia() {
    return this->lista->listaCheia();
}

template<typename T>
void Pilha<T>::limparPilha() {
    this->lista->limpaLista();
}
#endif
