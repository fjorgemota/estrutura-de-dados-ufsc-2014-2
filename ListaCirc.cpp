// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTACIRC_CPP
#define LISTACIRC_CPP

#include <stdlib.h>

#include "ListaCirc.hpp"
#include "Elemento.hpp"

template <typename T>
ListaCirc<T>::ListaCirc() {
    this->head = new Elemento<T>(NULL, NULL);
    this->head->setProximo(this->head);
    this->size = 0;
}

template <typename T>
ListaCirc<T>::~ListaCirc() {
    this->destroiLista();
}


template <typename T>
void ListaCirc<T>::adiciona(const T& dado) {
    if (this->listaVazia()) {
        return this->adicionaNoInicio(dado);
    }
    int i, max;
    Elemento<T> *temporario = this->head;
    max = this->size-1;
    for (i = 0; i < max; i++) {
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "Temporario foi detectado como nulo na posicao "+i;
        }
    }
    Elemento<T> *sentinela = temporario->getProximo();
    Elemento<T> *novo = new Elemento<T>(dado, sentinela);
    temporario->setProximo(novo);
    this->size++;
}

template <typename T>
void ListaCirc<T>::adicionaNoInicio(const T& dado) {
    Elemento<T> *novo = new Elemento<T>(dado, this->head);
    this->head = novo;
    this->size++;
    int i, max;
    Elemento<T> *sentinela = this->head;
    max = this->size;
    for (i = 0; i < max; i++) {
        sentinela = sentinela->getProximo();
        if (sentinela == NULL) {
            throw "Temporario foi detectado como nulo na posicao "+i;
        }
    }
    sentinela->setProximo(this->head);
}

template <typename T>
T ListaCirc<T>::retiraDoInicio() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    int i, max;
    Elemento<T> *inicio = this->head;
    T valor = inicio->getInfo();
    this->head = inicio->getProximo();
    this->size--;
    Elemento<T> *sentinela = this->head;
    max = this->size;
    for (i = 0; i < max; i++) {
        sentinela = sentinela->getProximo();
    }
    sentinela->setProximo(this->head);
    delete inicio;
    return valor;
}

template <typename T>
void ListaCirc<T>::eliminaDoInicio() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    int i, max;
    Elemento<T> *inicio = this->head;
    this->head = inicio->getProximo();
    this->size--;
    Elemento<T> *sentinela = this->head;
    max = this->size;
    for (i = 0; i < max; i++) {
        sentinela = sentinela->getProximo();
    }
    sentinela->setProximo(this->head);
    delete inicio;
}

template <typename T>
T ListaCirc<T>::mostra(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw "Posição inválida";
    }
    int i;
    Elemento<T> *temporario = this->head;
    for (i = 0; i < pos; i++) {
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "Temporario foi detectado como nulo na posicao "+i;
        }
    }
    return temporario->getInfo();
}

template <typename T>
int ListaCirc<T>::verUltimo() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    return this->size - 1;
}

template <typename T>
void ListaCirc<T>::destroiLista() {
    int i, max;
    Elemento<T> *sentinela = this->head;
    max = this->size + 1;
    for (i = 0; i < max; i++) {
        sentinela = sentinela->getProximo();
    }
    ListaEnc<T>::destroiLista();
    this->head = sentinela;
    this->head->setProximo(this->head);
}

#endif /* LISTACIRC_CPP */
