// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_CPP
#define LISTA_CPP
#include "Lista.hpp"
#define PRIMEIRO_ELEMENTO 0

template <typename T>
Lista<T>::Lista(int tamanhoMaximo) {
    if (tamanhoMaximo < 1) {
        throw "Impossivel criar lista com menos de 1 elemento";
    }
    this->topo = -1;
    this->arranjo = new T[tamanhoMaximo];
    this->tamanhoMaximo = tamanhoMaximo;
}

template <typename T>
void Lista<T>::adicionar(T obj) {
    if (this->topo >= this->tamanhoMaximo) {
        throw "Nao e possivel adicionar mais valores: Tamanho maximo excedido";
    }
    this->topo += 1;
    this->arranjo[this->topo] = obj;
}

template <typename T>
bool Lista<T>::listaCheia() {
    return this->pegaTamanho() == this->tamanhoMaximo;
}

template <typename T>
bool Lista<T>::listaVazia() {
    return this->pegaTamanho() == PRIMEIRO_ELEMENTO;
}

template <typename T>
int Lista<T>::pegaTamanho() {
    return  this->topo + 1;
}

template <typename T>
void Lista<T>::removerUltimo() {
    this->remover(this->topo);
}

template <typename T>
void Lista<T>::removerPrimeiro() {
    this->remover(PRIMEIRO_ELEMENTO);
}

template <typename T>
T Lista<T>::pegaPrimeiro() {
    return this->pegaValor(PRIMEIRO_ELEMENTO);
}

template <typename T>
T Lista<T>::pegaUltimo() {
    return this->pegaValor(this->topo);
}

template <typename T>
T Lista<T>::pegaValor(int posicao) {
    if (posicao < 0 || posicao > topo) {
        throw "Posicao invalida: A posicao esta fora dos limites da lista";
    }
    return this->arranjo[posicao];
}

template <typename T>
void Lista<T>::remover(int posicao) {
    if (topo == -1) {
        throw "Nao ha elementos para remover: A lista esta vazia";
    }
    for (int a = posicao; a <= topo; a++) {
        this->arranjo[a] = this->arranjo[a+1];
    }
    this->topo -= 1;
}

template <typename T>
void Lista<T>::troca(int posicao1, int posicao2) {
    int aux = this->pegaValor(posicao1);
    this->arranjo[posicao1] = this->pegaValor(posicao2);
    this->arranjo[posicao2] = aux;
}

template <typename T>
void Lista<T>::limpaLista() {
    this->topo -= 1;
}
#endif
