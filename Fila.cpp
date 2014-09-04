// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FILA_CPP
#define FILA_CPP

#include "Fila.hpp"
#include "Lista.cpp"

template <typename T>
Fila<T>::Fila() {
    this->lista = new Lista<T>(TAMANHO_MAXIMO_FILA);
}

template <typename T>
Fila<T>::Fila(int tamanhoMaximo) {
    this->lista = new Lista<T>(tamanhoMaximo);
}

template <typename T>
bool Fila<T>::filaCheia() {
    return this->lista->ListaCheia();
}

template <typename T>
bool Fila<T>::filaVazia() {
    return this->lista->ListaVazia();
}

template <typename T>
void Fila<T>::inclui(T dado) {
    this->lista->Adiciona(dado);
}

template <typename T>
T Fila<T>::retira() {
    return this->lista->RetiraDoInicio();
}

template <typename T>
T Fila<T>::ultimo() {
    return this->lista->pegaUltimo();
}

template <typename T>
int Fila<T>::getUltimo() {
    return this->lista->pegaTopo();
}

template <typename T>
void Fila<T>::inicializaFila() {
    this->lista->DestroiLista();
}
#endif
