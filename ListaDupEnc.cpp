// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPENC_CPP
#define LISTADUPENC_CPP
#include "ListaDupEnc.hpp"
#include <cstddef>

template <typename T>
ListaDupEnc<T>::ListaDupEnc() {
    this->head = NULL;
    this->size = 0;
}

template <typename T>
void ListaDupEnc<T>::adicionaNoInicioDuplo(const T& dado) {
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(NULL, dado, this->head);
    if (novo == NULL) {
        throw "Nao e possivel adicionar mais valores a lista";
    }
    this->head = novo;
    if (novo->getSucessor() != NULL) {
        novo->getSucessor()->setAnterior(novo);
    }
    this->size++;
}

template <typename T>
void ListaDupEnc<T>::adicionaNaPosicaoDuplo(const T& dado, int posicao) {
    if (posicao == 0) {
        this->adicionaNoInicioDuplo(dado);
    } else if (posicao > this->size+1 || posicao < 0) {
        throw "Posicao inválida";
    }
    int contagem;
    ElementoDuplo<T> *novo;
    ElementoDuplo<T> *anterior = this->head;
    for (contagem = 0; contagem < posicao-2; contagem++) {
        if (anterior == NULL) {
            throw "Não é possível adicionar valores";
        }
        anterior = anterior->getSucessor();
    }
    novo = new ElementoDuplo<T>(anterior, dado, anterior->getSucessor());
    if (novo->getSucessor() != NULL) {
        novo->getSucessor()->setAnterior(novo);
    }
    anterior->setSucessor(novo);
    this->size++;
}

template <typename T>
void ListaDupEnc<T>::adicionaDuplo(const T& dado) {
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "Impossível adicionar";
    }
    while (temporario->getSucessor() != NULL) {
        temporario = temporario->getSucessor();
    }
    temporario->setSucessor(new ElementoDuplo<T>(temporario->getAnterior(),
                                                    dado, NULL));
    this->size++;
}

template <typename T>
bool ListaDupEnc<T>::listaVaziaDuplo() {
    return this->size == 0;
}

template <typename T>
T ListaDupEnc<T>::retiraDoInicioDuplo() {
    if (this->listaVaziaDuplo()) {
        throw "A lista está vazia";
    }
    T valor;
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "Impossível remover";
    }
    this->head = temporario->getSucessor();
    valor = temporario->getInfo();
    if (this->head != NULL) {
        this->head->setAnterior(NULL);
    }
    this->size--;
    return valor;
}

template <typename T>
T ListaDupEnc<T>::retiraDaPosicaoDuplo(int posicao) {
    if (this->listaVaziaDuplo()) {
        throw "A lista está vazia";
    } else if (posicao > this->size+1 || posicao < 0) {
        throw "Posição inválida";
    } else if (posicao == 0) {
        return this->retiraDoInicioDuplo();
    }
    int contagem;
    T valor;
    ElementoDuplo<T> *temporario = this->head;
    for (contagem = 0; contagem < posicao-2; contagem++) {
        if (temporario == NULL) {
            throw "Impossível remover";
        }
        temporario = temporario->getAnterior();
    }
    ElementoDuplo<T> *remover = temporario->getSucessor();
    valor = remover->getInfo();
    temporario->setSucessor(remover->getSucessor());
    if (temporario->getSucessor() != NULL) {
        remover->getSucessor()->setAnterior(temporario);
    }
    this->size--;
    return valor;
}

template <typename T>
T ListaDupEnc<T>::retiraDuplo() {
    if (this->listaVaziaDuplo()) {
        throw "A lista esta vazia";
    }
    T valor;
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    if (temporario->getSucessor() == NULL) {
        valor = temporario->getInfo();
        this->head = NULL;
        this->size--;
        delete temporario;
        return valor;
    }
    for (contador = 0; contador < this->size-2; contador++) {
        temporario = temporario->getSucessor();
    }
    valor = temporario->getSucessor()->getInfo();
    delete temporario->getSucessor();
    temporario->setSucessor(NULL);
    this->size--;
    return valor;
}

template <typename T>
bool ListaDupEnc<T>::contem(const T& dado) {
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista está vazia";
    }
    while (temporario->getSucessor() != NULL) {
        temporario = temporario->getSucessor();
        if (temporario->getInfo() == dado) {
            return true;
        }
    }
    return false;
}

template <typename T>
int ListaDupEnc<T>::posicaoDuplo(const T& dado) {
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista esta vazia";
    }
    for (contador = 0; contador < this->size+1; contador++) {
        if (temporario->getInfo() == dado) {
            return contador;
        }
        temporario = temporario->getSucessor();
    }
    throw "O elemento não pertence à lista duplamente encadeada";
}

#endif
