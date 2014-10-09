// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PROBABILIDADES_CPP
#define GERADOR_PROBABILIDADES_CPP
#include "ListaDupla.cpp"
#include "GeradorProbabilidades.hpp"

template <typename T>
GeradorProbabilidades<T>::GeradorProbabilidades() {
    this->lista = new ListaDupla<T>();
}

template <typename T>
void GeradorProbabilidades<T>::adiciona(T dado, int porcentagem) {
    int ultimo;
    if (this->lista->listaVazia()) {
        ultimo = -1; // Não há elementos
    } else {
        ultimo = this->lista->verUltimo();
    }
    if (ultimo + porcentagem > 99) {
        throw "Porcentagem invalida "+(ultimo + porcentagem);
    }
    int i;
    for (i = 0; i < porcentagem; i++) {
        this->lista->adicionaDuplo(dado);
    }
}

template <typename T>
ListaDupla<T>* GeradorProbabilidades<T>::pegaLista() {
    if (this->lista->verUltimo() != 99) {
        throw "A lista não completa cem porcento como deveria";
    }
    return this->lista;
}

#endif /* GERADOR_PROBABILIDADES_CPP */
