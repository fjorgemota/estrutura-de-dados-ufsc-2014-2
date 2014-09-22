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
void ListaDupEnc<T>::adicionaDuplo(const T& dado) {
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        return this->adicionaNoInicioDuplo(dado);
    }
    while (temporario->getProximo() != NULL) {
        temporario = temporario->getProximo();
    }
    temporario->setProximo(new ElementoDuplo<T>(temporario, dado, NULL));
    this->size++;
}

template <typename T>
void ListaDupEnc<T>::adicionaNoInicioDuplo(const T& dado) {
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(NULL, dado, this->head);
    this->head = novo;
    if (novo->getProximo() != NULL) {
        novo->getProximo()->setAnterior(novo);
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
    posicao -= 1;
    ElementoDuplo<T> *novo;
    ElementoDuplo<T> *anterior = this->head;
    for (contagem = 0; contagem < posicao; contagem++) {
        if (anterior == NULL) {
            throw "Não é possível adicionar valores";
        }
        anterior = anterior->getProximo();
    }
    if (anterior == NULL) {
        throw "Não é possível adicionar valores";
    }
    novo = new ElementoDuplo<T>(anterior, dado, anterior->getProximo());
    if (novo->getProximo() != NULL) {
        novo->getProximo()->setAnterior(novo);
    }
    anterior->setProximo(novo);
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
    this->head = temporario->getProximo();
    valor = temporario->getInfo();
    if (this->head != NULL) {
        this->head->setAnterior(NULL);
        delete this->head->getAnterior();
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
    posicao -= 1;
    ElementoDuplo<T> *temporario = this->head;
    for (contagem = 0; contagem < posicao; contagem++) {
        if (temporario == NULL) {
            throw "Impossível remover";
        }
        temporario = temporario->getProximo();
    }
    if (temporario == NULL) {
        throw "Impossível remover";
    }
    ElementoDuplo<T> *remover = temporario->getProximo();
    valor = remover->getInfo();
    temporario->setProximo(remover->getProximo());
    if (temporario->getProximo() != NULL) {
        remover->getProximo()->setAnterior(temporario);
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
    if (temporario->getProximo() == NULL) {
        valor = temporario->getInfo();
        this->head = NULL;
        this->size--;
        delete temporario;
        return valor;
    }
    for (contador = 0; contador < this->size-2; contador++) {
        temporario = temporario->getProximo();
    }
    valor = temporario->getProximo()->getInfo();
    delete temporario->getProximo();
    temporario->setProximo(NULL);
    this->size--;
    return valor;
}

template <typename T>
T ListaDupEnc<T>::retiraEspecificoDuplo(const T& dado) {
    if (this->listaVaziaDuplo()) {
        throw "A lista esta vazia";
    }
    int contador = 0;
    ElementoDuplo<T> *temporario = this->head;
    while (temporario != NULL) {
        if (temporario->getInfo() == dado) {
            return this->retiraDaPosicaoDuplo(contador);
        }
        temporario = temporario->getProximo();
        contador++;
    }
    throw "O elemento não está presente na lista";
}

template <typename T>
bool ListaDupEnc<T>::contem(const T& dado) {
    ElementoDuplo<T> *temporario = this->head;
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
        temporario = temporario->getProximo();
    }
    throw "O elemento não pertence à lista duplamente encadeada";
}

template <typename T>
bool ListaDupEnc<T>::igual(T dado1, T dado2) {
    if (dado1 == dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaDupEnc<T>::maior(T dado1, T dado2) {
    if (dado1 > dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaDupEnc<T>::menor(T dado1, T dado2) {
    if (dado1 < dado2) {
        return true;
    }
    return false;
}

#endif
