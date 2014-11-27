// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLA_CPP
#define LISTADUPLA_CPP
#include "ListaDupla.hpp"
#include <cstdlib>

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
    if (this->listaVazia()) {
        return this->adicionaNoInicioDuplo(dado);
    }
    int contagem;
    ElementoDuplo<T> *temporario = this->head;
    for (contagem = 0; contagem < this->size-1; contagem++) {
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "O valor foi detetado como nulo na posiçao: " +contagem;
        }
    }
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(temporario, dado, NULL);
    temporario->setProximo(novo);
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
    if (posicao == 0 || this->listaVazia()) {
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
    if (this->listaVazia()) {
        return this->adicionaNoInicioDuplo(dado);
    }
    ElementoDuplo<T> *temporario = this->head;
    int posicao, maximo;
    posicao = 0;
    maximo = this->size-1;
    while (posicao < maximo && this->maior(dado, temporario->getInfo())) {
        temporario = temporario->getProximo();
        posicao++;
    }
    if (this->maior(dado, temporario->getInfo())) {
        this->adicionaNaPosicaoDuplo(dado, posicao+1);
    } else {
        this->adicionaNaPosicaoDuplo(dado, posicao);
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
    if (this->size == 1) {
        return this->retiraDoInicioDuplo();
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
    valor = temporario->getInfo();
    this->head = temporario->getProximo();
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
    } else if (posicao >= this->size || posicao < 0) {
        throw "Posição inválida";
    } else if (posicao == 0) {
        return this->retiraDoInicioDuplo();
    }
    int contagem;
    T valor;
    posicao -= 1;
    ElementoDuplo<T> *temporario = this->head;
    for (contagem = 0; contagem < posicao; contagem++) {
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "O valor foi detectado como nulo na posição "+contagem;
        }
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
    delete remover;
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
    int contagem, maximo;
    maximo = this->size-1;
    ElementoDuplo<T> *atual = this->head;
    for (contagem = 0; contagem <= maximo; contagem++) {
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
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    int contador, max;
    max = this->size-1;
    ElementoDuplo<T> *temporario = this->head;
    for (contador = 0; contador <= max; contador++) {
        if (temporario == NULL) {
            throw "O temporário foi detectado como nulo na posiçao "+contador;
        }
        if (temporario->getInfo() == dado) {
            return true;
        }
        temporario = temporario->getProximo();
    }
    return false;
}

template <typename T>
int ListaDupla<T>::posicaoDuplo(const T& dado) {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    for (contador = 0; contador <= this->size-1; contador++) {
        if (temporario->getInfo() == dado) {
            return contador;
        }
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "Temporario foi detectado como nulo na posiçao "+contador;
        }
    }
    throw "O elemento não pertence à lista duplamente encadeada";
}

template <typename T>
T* ListaDupla<T>::posicaoMemDuplo(const T& dado) const {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    int contador;
    ElementoDuplo<T> *temporario = this->head;
    for (contador = 0; contador <= this->size-1; contador++) {
        if (temporario->getInfo() == dado) {
            T valor = temporario->getInfo();
            return &valor;
        }
        temporario = temporario->getProximo();
        if (temporario == NULL) {
            throw "Temporario detectado com valor nulo na posiçao "+contador;
        }
    }
    throw "O elemento não pertence à lista duplamente encadeada";
}

template <typename T>
T ListaDupla<T>::mostra(int pos) {
    int contagem;
    if (pos < 0 || pos >= this->size) {
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
    if (this->listaVazia()) {
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

template <typename T>
T* ListaDupla<T>::paraVetor() {
    int tamanho = this->verUltimo() + 1;
    T* resultado = new T[tamanho];
    ElementoDuplo<T> *temporario = this->head;
    for(int i=0; i < tamanho; i++) {
        resultado[i] = temporario->getInfo();
        temporario = temporario->getProximo();
    }
    return resultado;
}

#endif
