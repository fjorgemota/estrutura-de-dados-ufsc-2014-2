// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLA_CPP
#define LISTADUPLA_CPP
#include "ListaDupla.hpp"
#include <cstddef>

template <typename T>
ListaDupla<T>::ListaDupla() {
    this->head = NULL;
    this->size = 0;
}

template <typename T>
ListaDupla<T>::~ListaDupla() {
    this->destroiListaDuplo();
}

template <typename T>
void ListaDupla<T>::adicionaDuplo(const T& dado) {
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
void ListaDupla<T>::adicionaNoInicioDuplo(const T& dado) {
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(NULL, dado, this->head);
    this->head = novo;
    if (novo->getProximo() != NULL) {
        novo->getProximo()->setAnterior(novo);
    }
    this->size++;
}

template <typename T>
void ListaDupla<T>::adicionaNaPosicaoDuplo(const T& dado, int posicao) {
    if (posicao == 0) {
        this->adicionaNoInicioDuplo(dado);
    } else if (posicao >= this->size || posicao < 0) {
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
void ListaDupla<T>::adicionaEmOrdem(const T& dado) {
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        return this->adicionaNoInicioDuplo(dado);
    }
    if (this->listaVazia()) {
        this->adicionaNoInicioDuplo(dado);
    }
    int posicao = 1;
    while (temporario->getProximo() != NULL &&
            this->maior(dado, temporario->getInfo())) {
        temporario = temporario->getProximo();
        posicao++;
    }
    if (this->maior(dado, temporario->getInfo())) {
        this->adicionaNaPosicaoDuplo(dado, posicao);
    } else {
        this->adicionaNaPosicaoDuplo(dado, posicao-1);
    }
}

template <typename T>
void ListaDupla<T>::eliminaDoInicioDuplo() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    ElementoDuplo<T> *temporario = this->head;
    this->head = temporario->getProximo();
    if (this->head != NULL) {
        this->head->setAnterior(NULL);
        delete this->head->getAnterior();
    }
    this->size--;
}

template <typename T>
T ListaDupla<T>::retiraDuplo() {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    T valor;
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "Impossível remover";
    }
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
T ListaDupla<T>::retiraDoInicioDuplo() {
    if (this->listaVazia()) {
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
T ListaDupla<T>::retiraDaPosicaoDuplo(int posicao) {
    if (this->listaVazia()) {
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
T ListaDupla<T>::retiraEspecificoDuplo(const T& dado) {
    int resultado = this->posicaoDuplo(dado);
    return this->retiraDaPosicaoDuplo(resultado);
}

template <typename T>
void ListaDupla<T>::destroiListaDuplo() {
    ElementoDuplo<T> *atual = this->head;

    while (atual != NULL) {
        ElementoDuplo<T> *anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    this->head = NULL;
    this->size = 0;
}

template <typename T>
bool ListaDupla<T>::listaVazia() const {
    return this->size == 0;
}

template <typename T>
bool ListaDupla<T>::contemDuplo(const T& dado) {
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
int ListaDupla<T>::posicaoDuplo(const T& dado) {
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista esta vazia";
    }
    for (contador = 0; contador < this->size; contador++) {
        if (temporario->getInfo() == dado) {
            return contador;
        }
        temporario = temporario->getProximo();
    }
    throw "O elemento não pertence à lista duplamente encadeada";
}

template <typename T>
T* ListaDupla<T>::posicaoMemDuplo(const T& dado) const {
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    if (temporario == NULL) {
        throw "A lista esta vazia";
    }
    for (contador = 0; contador < this->size+1; contador++) {
        if (temporario->getInfo() == dado) {
            T valor = temporario->getInfo();
            return &valor;
        }
        temporario = temporario->getProximo();
    }
    throw "O elemento não pertence à lista duplamente encadeada";
}

template <typename T>
T ListaDupla<T>::mostra(int pos) {
    int contagem;
    if (pos < 0) {
       throw "Posicao invalida";
    }
    ElementoDuplo<T> *temporario = this->head;
    for (contagem = 0; contagem < pos; contagem++) {
        if (temporario == NULL) {
            throw "Impossível pegar valor";
        }
        temporario = temporario->getProximo();
    }
    if (temporario == NULL) {
        throw "Impossível remover";
    }
    return temporario->getInfo();
}

template <typename T>
int ListaDupla<T>::verUltimo() {
    if (this->head == NULL) {
        throw "A lista esta vazia";
    }
    return this->size-1;
}

template <typename T>
bool ListaDupla<T>::igual(T dado1, T dado2) {
    if (dado1 == dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaDupla<T>::maior(T dado1, T dado2) {
    if (dado1 > dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaDupla<T>::menor(T dado1, T dado2) {
    if (dado1 < dado2) {
        return true;
    }
    return false;
}

#endif
