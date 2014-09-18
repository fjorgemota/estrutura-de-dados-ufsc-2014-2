// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PILHAENC_CPP
#define PILHAENC_CPP
#include "ListaEnc.hpp"
#include "PilhaEnc.hpp"

template <typename T>
PilhaEnc<T>::PilhaEnc() {
    this->pilhaEnc = new ListaEnc<T>();
}

template <typename T>
void PilhaEnc<T>::empilha(const T& dado) {
    this->pilhaEnc->adicionaNoInicio(dado);
}

template <typename T>
T PilhaEnc<T>::desempilha() {
    return this->pilhaEnc->retiraDoInicio();
}

template <typename T>
bool PilhaEnc<T>::contem(const T& dado) {
    return this->pilhaEnc->contem(dado);
}

template <typename T>
bool PilhaEnc<T>::pilhaVazia() {
    return this->pilhaEnc->listaVazia();
}

#endif
