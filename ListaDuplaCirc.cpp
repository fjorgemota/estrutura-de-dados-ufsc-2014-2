// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLACIRC_CPP
#define LISTADUPLACIRC_CPP

#include "ListaDuplaCirc.hpp"
#include "ElementoDuplo.hpp"

template <typename T>
ListaDuplaCirc<T>::ListaDuplaCirc() {
    ElementoDuplo<T> *sentinela = new ElementoDuplo<T>(NULL, 0, NULL);
    sentinela->setAnterior(sentinela);
    sentinela->setProximo(sentinela);
    this->head = sentinela;
    this->size = 0;
}

template <typename T>
ListaDuplaCirc<T>::~ListaDuplaCirc() {
    this->destroiListaDuplo();
}

template <typename T>
void ListaDuplaCirc<T>::adicionaDuplo(const T& dado) {
    if (this->listaVazia()) {
        return this->adicionaNoInicioDuplo(dado);
    }
    ElementoDuplo<T> *novo;
    ElementoDuplo<T> *sentinela = this->head->getAnterior();
    ElementoDuplo<T> *temporario = this->head;
    temporario = sentinela->getAnterior();
    novo = new ElementoDuplo<T>(temporario, dado, sentinela);
    temporario->setProximo(novo);
    sentinela->setAnterior(novo);
    this->size++;
}

template <typename T>
void ListaDuplaCirc<T>::adicionaNoInicioDuplo(const T& dado) {
    ElementoDuplo<T> *sentinela = this->head->getAnterior();
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(sentinela, dado, this->head);
    this->head = novo;
    this->size++;
    sentinela->setProximo(novo);
    novo->getProximo()->setAnterior(novo);
}

template <typename T>
T ListaDuplaCirc<T>::retiraDuplo() {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    T valor;
    ElementoDuplo<T> *sentinela = this->head->getAnterior();
    ElementoDuplo<T> *temporario = sentinela->getAnterior();
    if (this->size == 1) {
        return this->retiraDoInicioDuplo();
    }
    valor = temporario->getInfo();
    temporario->getAnterior()->setProximo(sentinela);
    sentinela->setAnterior(temporario->getAnterior());
    delete temporario;
    this->size--;
    return valor;
}

template <typename T>
T ListaDuplaCirc<T>::retiraDoInicioDuplo() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    T valor;
    ElementoDuplo<T> *sentinela = this->head->getAnterior();
    ElementoDuplo<T> *temporario = this->head;
    temporario->getProximo()->setAnterior(sentinela);
    valor = temporario->getInfo();
    if (temporario->getProximo() != NULL) {
        temporario->getProximo()->setAnterior(sentinela);
        sentinela->setProximo(temporario->getProximo());
        this->head = temporario->getProximo();
        delete temporario;
    }
    this->size--;
    return valor;
}

template <typename T>
void ListaDuplaCirc<T>::eliminaDoInicioDuplo() {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    ElementoDuplo<T> *temporario = this->head;
    this->head = temporario->getProximo();
    this->head->getAnterior()->setProximo(this->head);
    delete temporario;
    this->size--;
}

template <typename T>
void ListaDuplaCirc<T>::destroiListaDuplo() {
    ElementoDuplo<T> *sentinela = this->head->getAnterior();
    ListaDupla<T>::destroiListaDuplo();
    sentinela->setProximo(sentinela);
    sentinela->setAnterior(sentinela);
    this->head = sentinela;
    this->size = 0;
}

#endif
