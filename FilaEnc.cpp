// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FILAENC_CPP
#define FILAENC_CPP

#include "FilaEnc.hpp"

template <typename T>
FilaEnc<T>::FilaEnc() {
    this->listaEnc = new ListaEnc<T>();
}

template <typename T>
void FilaEnc<T>::adiciona(T dado) {
    this->listaEnc->adicionaNoInicio(dado);
}

template <typename T>
T FilaEnc<T>::retira() {
    return this->listaEnc->retira();
}

template <typename T>
T FilaEnc<T>::retiraDoInicio() {
    return this->listaEnc->retiraDoInicio();
}

#endif
