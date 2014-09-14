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
bool ListaEnc<T>::listaVazia() const {
    return this->size == 0;
}

template <typename T>
void ListaEnc<T>::adiciona(const T& valor) {
    Elemento<T> *ult = this->head;
    this->head = new Elemento<T>(valor, ult);
    this->size++;
}


template <typename T>
void ListaEnc<T>::adicionaNoInicio(const T& valor) {
    Elemento<T> *temporario = this->head;
    while (temporario->getProximo() != NULL) {
        temporario = temporario->getProximo();
    }
    temporario->setProximo(new Elemento<T>(valor, NULL));
    this->size++;
}

template <typename T>
void ListaEnc<T>::destroiLista() {
    Elemento<T> *atual = this->head;

    while (atual != NULL) {
        Elemento<T> *anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    this->size = 0;
}

template <typename T>
void ListaEnc<T>::adicionaNaPosicao(const T& valor, int posicao) {
    if (posicao == 0) {
        this->adicionaNoInicio(valor);
    } else {
        Elemento<T> *temporario = this->head;
        Elemento<T> *novo;
        posicao = this->size - posicao - 1;
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

/*
template <typename T>
T ListaEncadeada<T>::retiraDaPosicao(int posicao) {
    Nodo<T> temporario = this->head;
    Nodo<T> *temp2;
    int h;
    for (h = 0; h < posicao - 1; h++) {
        temporario = temporario.getProximo();
        if (temporario == NULL) {
            throw "Posiçao invalida";
        }
    }
    temp2 = temporario.getProximo();
    if (temp2 == NULL) {
        throw "Impossível pegar o próximo";
    }
    temporario.setProximo(temp2->getProximo());
    this->size--;
}

template <typename T>
T ListaEncadeada<T>::retiraEspecifico(T dado) {
    int posicao = this->posicao(dado);
    return this->retiraDaPosicao(posicao);
}

template <typename T>
T ListaEncadeada<T>::retiraDoInicio() {
    Nodo<T> temporario = this->head;
    Nodo<T> temp2 = temporario.getProximo();
    if (temp2 == NULL) {
        throw "Não há valores para retirar";
    }
    temporario.setProximo(temp2);
    this->size--;
    return temp2;
}
*/
template <typename T>
int ListaEnc<T>::posicao(const T& dado) {
    int posicao;
    Elemento<T> *temporario = this->head;
    for (posicao = 0; posicao <= this->size; posicao++) {
        if (temporario->getInfo() == dado) {
            return this->size - posicao - 1;
        }
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "Impossível acessar o próximo valor";
        }
    }
    throw "O valor não pertence à lista";
}


template <typename T>
T* ListaEnc<T>::posicaoMem(const T& dado) const {
    int posicao;
    Elemento<T> *temporario = this->head;
    for (posicao = 0; posicao <= this->size; posicao++) {
        if (temporario->getInfo() == dado) {
            return &(temporario->getInfo());
        }
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "Impossível acessar o próximo valor";
        }
    }
    throw "O valor não pertence à lista";
}


template <typename T>
T ListaEnc<T>::retira() {
    Elemento<T> *ult = this->head;
    if (ult == NULL) {
       throw "A lista está vazia";
    }
    this->head = ult->getProximo();
    this->size--;
    return ult->getInfo();
}

template <typename T>
T ListaEnc<T>::retiraDoInicio() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    Elemento<T> *ult = this->head;
    T valor;
    if (ult->getProximo() == NULL) {
        this->head = NULL;
        valor = ult->getInfo();
        this->size--;
        return valor;
    }
    for (int i = 0; i < this->size-2; i++) {
        ult = ult->getProximo();
    }
    valor = ult->getProximo()->getInfo();
    ult->setProximo(NULL);
    this->size--;
    return valor;
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
