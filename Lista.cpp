// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_CPP
#define LISTA_CPP
#include "Lista.hpp"
#define PRIMEIRO_ELEMENTO 0

template <typename T>
Lista<T>::Lista() {
    this->topo = -1;
    this->arranjo = new T[TAMANHO_MAXIMO_LISTA];
    this->tamanhoMaximo = TAMANHO_MAXIMO_LISTA;
}

template <typename T>
Lista<T>::Lista(int tamanhoMaximo) {
    if (tamanhoMaximo < 1) {
        throw "Impossível criar lista com menos de 1 elemento";
    }
    this->topo = -1;
    this->arranjo = new T[tamanhoMaximo];
    this->tamanhoMaximo = tamanhoMaximo;
}

template <typename T>
void Lista<T>::adiciona(T obj) {
    this->topo += 1;
    if (this->topo >= this->tamanhoMaximo) {
        throw "Não é possível adicionar mais valores: Tamanho máximo excedido";
    }
    this->arranjo[this->topo] = obj;
}

template <typename T>
void Lista<T>::adicionaNaPosicao(T dado, int destino) {
    if (destino >= this->tamanhoMaximo || destino < 0) {
        throw "Não é possível adicionar o valor na posição especificada";
    }
    int posicao;
    this->topo += 1;
    for (posicao = topo; posicao > destino; posicao--) {
        this->arranjo[posicao] = this->arranjo[posicao-1];
    }
    this->arranjo[destino] = dado;
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
T Lista<T>::retira() {
    if (this->listaVazia()) {
        throw "Não há elementos para remover, a lista está vazia";
    }
    this->topo -= 1;
    return this->arranjo[this->topo + 1];
}

template <typename T>
T Lista<T>::retiraDoInicio() {
    T valor = this->retiraDaPosicao(PRIMEIRO_ELEMENTO);
    return valor;
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
        throw "Posição inválida: A posição está fora dos limites da lista";
    }
    return this->arranjo[posicao];
}

template <typename T>
T Lista<T>::retiraDaPosicao(int posicao) {
    if (this->listaVazia()) {
        throw "Não há elementos para remover: A lista está vazia";
    } else if (posicao > topo || posicao < 0) {
        throw "Impossivel remover valores: posiçao invalida";
    }
    int fonte;
    T valor;
    valor = this->arranjo[posicao];
    fonte = posicao;
    for (int a = fonte; a <= topo; a++) {
        this->arranjo[a] = this->arranjo[a+1];
    }
    this->topo -= 1;
    return valor;
}

template <typename T>
void Lista<T>::adicionaNoInicio(T dado) {
    if (this->listaCheia()) {
        throw "Lista Cheia, não é possível adicionar mais elementos";
    }
    this->adicionaNaPosicao(dado, PRIMEIRO_ELEMENTO);
}

template <typename T>
void Lista<T>::adicionaEmOrdem(T dado) {
    if (this->listaCheia()) {
        throw "A lista está cheia";
    }
    this->insertionSort();
    int posicao = 0;
    while (posicao <= this->topo &&
           dado > this->arranjo[posicao]) {
        posicao++;
    }
    this->adicionaNaPosicao(dado, posicao);
}

template <typename T>
void Lista<T>::insertionSort() {
    int h, posicao;
    T valorAux;
    for (h = 1; h <= this->topo; h++) {
        valorAux = this->arranjo[h];
        posicao = h - 1;
        while (posicao > -1 && this->arranjo[posicao] > valorAux) {
            this->arranjo[posicao + 1] = this->arranjo[posicao];
            posicao -= 1;
        }
        this->arranjo[posicao + 1] = valorAux;
    }
}

template <typename T>
T Lista<T>::retiraEspecifico(T dado) {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    } else if (!this->contem(dado)) {
        throw "O dado não pertence à lista";
    }
    int h;
    h = this->posicao(dado);
    return this->retiraDaPosicao(h);
}

template <typename T>
void Lista<T>::troca(int posicao1, int posicao2) {
    int aux = this->pegaValor(posicao1);
    this->arranjo[posicao1] = this->pegaValor(posicao2);
    this->arranjo[posicao2] = aux;
}

template <typename T>
void Lista<T>::destroiLista() {
    this->topo = -1;
}

template <typename T>
bool Lista<T>::contem(T dado) {
    int h;
    for (h = 0; h <= topo; h++) {
        if (this->arranjo[h] == dado) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Lista<T>::posicao(T dado) {
    int a;
    for (a = 0; a<= topo; a++) {
        if (this->arranjo[a] == dado) {
            return a;
        }
    }
    throw "O dado não pertence à lista";
}

template <typename T>
int Lista<T>::pegaTopo() {
    return this->topo;
}

template <typename T>
bool Lista<T>::igual(T dado1, T dado2) {
    if (dado1 == dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::maior(T dado1, T dado2) {
    if (dado1 > dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::menor(T dado1, T dado2) {
    if (dado1 < dado2) {
        return true;
    }
    return false;
}
#endif
