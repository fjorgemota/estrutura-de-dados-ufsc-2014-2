// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_ENCADEADA_CPP
#define LISTA_ENCADEADA_CPP
#include "ListaEnc.hpp"
#include <stdlib.h>

template <typename T>
ListaEnc<T>::ListaEnc() {
    this->head = NULL;
    this->size = 0;
}

template <typename T>
ListaEnc<T>::~ListaEnc() {
    this->destroiLista();
}

template <typename T>
bool ListaEnc<T>::listaVazia() const {
    return this->size == 0;
}

template <typename T>
void ListaEnc<T>::adicionaNoInicio(const T& valor) {
    Elemento<T> *ult = this->head;
    this->head = new Elemento<T>(valor, ult);
    this->size++;
}


template <typename T>
void ListaEnc<T>::adiciona(const T& valor) {
    Elemento<T> *temporario = this->head;
    if (temporario == NULL) {
        return this->adicionaNoInicio(valor);
    }
    while (temporario->getProximo() != NULL) {
        temporario = temporario->getProximo();
    }
    temporario->setProximo(new Elemento<T>(valor, NULL));
    this->size++;
}

template <typename T>
void ListaEnc<T>::adicionaNaPosicao(const T& valor, int posicao) {
    if (posicao == 1 || this->head == NULL) {
        this->adicionaNoInicio(valor);
    } else {
        Elemento<T> *temporario = this->head;
        Elemento<T> *novo;
        posicao = posicao - 1;
        int h;
        for (h = 0; h < posicao; h++) {
            temporario = temporario->getProximo();
            if (temporario == NULL) {
                throw "Posição inválida ou lista cheia";
            }
        }
        novo = temporario->getProximo();
        temporario->setProximo(new Elemento<T>(valor, novo));
        this->size++;
    }
}


template <typename T>
void ListaEnc<T>::adicionaEmOrdem(const T& dado) {
    Elemento<T> *temporario = this->head;
    if (temporario == NULL) {
        return this->adicionaNoInicio(dado);
    }
    int posicao;
    if (this->listaVazia()) {
        this->adicionaNoInicio(dado);
    }
    posicao = 1;
    while (temporario->getProximo() != NULL &&
            maior(dado, temporario->getInfo())) {
        temporario = temporario->getProximo();
        posicao++;
    }
    if (maior(dado, temporario->getInfo())) {
        this->adicionaNaPosicao(dado, posicao+1);
    } else {
        this->adicionaNaPosicao(dado, posicao);
    }
}

template <typename T>
void ListaEnc<T>::destroiLista() {
    Elemento<T> *atual = this->head;

    while (atual != NULL) {
        Elemento<T> *anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    this->head = NULL;
    this->size = 0;
}

template <typename T>
T ListaEnc<T>::retiraDaPosicao(int posicao) {
    if (posicao == 0) {
        return this->retiraDoInicio();
    }
    Elemento<T> *anterior = this->head;
    Elemento<T> *eliminar;
    int h;
    if (posicao < 0 || posicao >= this->size) {
        throw "Posicao invalida";
    }
    posicao = posicao - 1;
    for (h = 0; h < posicao; h++) {
        anterior = anterior->getProximo();
        if (anterior == NULL) {
            throw "Posiçao invalida";
        }
    }
    eliminar = anterior->getProximo();
    if (eliminar == NULL) {
        throw "Impossível pegar o próximo";
    }
    anterior->setProximo(eliminar->getProximo());
    this->size--;
    return eliminar->getInfo();
}

template <typename T>
T ListaEnc<T>::retiraEspecifico(T dado) {
    int posicao = this->posicao(dado);
    return this->retiraDaPosicao(posicao);
}

template <typename T>
int ListaEnc<T>::posicao(const T& dado) {
    Elemento<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista esta vazia";
    }
    int posicao = 0;
    do {
        if (temporario->getInfo() == dado) {
            return posicao;
        }
        posicao++;
    } while ((temporario = temporario->getProximo()) != NULL);
    throw "O valor não pertence à lista";
}


template <typename T>
T* ListaEnc<T>::posicaoMem(const T& dado) const {
    Elemento<T> *temporario = this->head;
    int posicao = this->size;
    do {
        posicao--;
        if (temporario->getInfo() == dado) {
            T valor = temporario->getInfo();
            return &valor;
        }
    } while ((temporario = temporario->getProximo()) != NULL);
    throw "O valor não pertence à lista";
}


template <typename T>
T ListaEnc<T>::retiraDoInicio() {
    Elemento<T> *ult = this->head;
    if (ult == NULL) {
       throw "A lista está vazia";
    }
    this->head = ult->getProximo();
    this->size--;
    return ult->getInfo();
}

template <typename T>
T ListaEnc<T>::retira() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    Elemento<T> *ult = this->head;
    T valor;
    if (ult->getProximo() == NULL) {
        valor = ult->getInfo();
        this->size--;
        this->head = NULL;
        delete ult;
        return valor;
    }
    for (int i = 0; i < this->size-2; i++) {
        ult = ult->getProximo();
    }
    valor = ult->getProximo()->getInfo();
    delete ult->getProximo();
    ult->setProximo(NULL);
    this->size--;
    return valor;
}

template <typename T>
void ListaEnc<T>::eliminaDoInicio() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    Elemento<T> *ult = this->head;
    if (ult->getProximo() == NULL) {
        delete ult;
        this->head = NULL;
        this->size--;
    }
    for (int i = 0; i < this->size-2; i++) {
        ult = ult->getProximo();
    }
    delete ult->getProximo();
    ult->setProximo(NULL);
    this->size--;
}

template <typename T>
bool ListaEnc<T>::contem(const T& dado) {
    Elemento<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista está vazia";
    }
    do {
        if (temporario->getInfo() == dado) {
            return true;
        }
    } while ((temporario = temporario->getProximo()) != NULL);
    return false;
}

template <typename T>
T ListaEnc<T>::topo() {
    Elemento<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista está vazia";
    }
    return temporario->getInfo();
}

template <typename T>
bool ListaEnc<T>::igual(T dado1, T dado2) {
    if (dado1 == dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaEnc<T>::maior(T dado1, T dado2) {
    if (dado1 > dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaEnc<T>::menor(T dado1, T dado2) {
    if (dado1 < dado2) {
        return true;
    }
    return false;
}

#endif
