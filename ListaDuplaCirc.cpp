// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLACIRC_CPP
#define LISTADUPLACIRC_CPP
#include "ListaDuplaCirc.hpp"
#include <cstddef>

template <typename T>
ListaDuplaCirc<T>::ListaDuplaCirc() {
    this->sentinela = new ElementoDuplo<T>();
    this->sentinela->setAnterior(this->sentinela);
    this->sentinela->setProximo(this->sentinela);
    this->size = 0;
}

template <typename T>
ListaDuplaCirc<T>::~ListaDuplaCirc() {
    this->destroiListaDuplo();
}

template <typename T>
void ListaDuplaCirc<T>::adicionaDuplo(const T& dado) {
    ElementoDuplo<T> *temporario = this->sentinela->getAnterior();
    if (temporario == NULL) {
        return this->adicionaNoInicioDuplo(dado);
    }
    temporario->setProximo(new ElementoDuplo<T>(temporario, dado,
                                                       this->sentinela));
    this->sentinela->setAnterior(temporario->getProximo());
    this->size++;
}

/*template <typename T>
void ListaDuplaCirc<T>::adicionaDuplo(const T& dado) {
    int contagem;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (temporario == NULL) {
        return this->adicionaNoInicioDuplo(dado);
    }
    for (contagem = 1; contagem < this->size; contagem++) {
        temporario = temporario->getProximo();
    }
    temporario->setProximo(new ElementoDuplo<T>(temporario, dado, 
                                                       this->sentinela));
    this->sentinela->setAnterior(temporario->getProximo());
    this->size++;
}*/

template <typename T>
void ListaDuplaCirc<T>::adicionaNoInicioDuplo(const T& dado) {
    ElementoDuplo<T> *novo = new ElementoDuplo<T>(this->sentinela, dado,
                                                this->sentinela->getProximo());
    this->sentinela->setProximo(novo);
    novo->getProximo()->setAnterior(novo);
    this->size++;
}

template <typename T>
void ListaDuplaCirc<T>::adicionaNaPosicaoDuplo(const T& dado, int pos) {
    if (pos == 0) {
        this->adicionaNoInicioDuplo(dado);
    } else if (pos >= this->size || pos < 0) {
        throw "Posicao inválida";
    }
    int contagem;
    pos -= 1;
    ElementoDuplo<T> *novo;
    ElementoDuplo<T> *anterior = this->sentinela->getProximo();
    for (contagem = 0; contagem < pos; contagem++) {
        if (anterior == NULL) {
            throw "Não é possível adicionar valores";
        }
        anterior = anterior->getProximo();
    }
    if (anterior == NULL) {
        throw "Não é possível adicionar valores";
    }
    novo = new ElementoDuplo<T>(anterior, dado, anterior->getProximo());
    anterior->setProximo(novo);
    novo->getProximo()->setAnterior(novo);
    this->size++;
}

template <typename T>
void ListaDuplaCirc<T>::adicionaEmOrdem(const T& data) {
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (temporario == NULL || this->listaVazia()) {
        return this->adicionaNoInicioDuplo(data);
    }
    int contagem;
    for (contagem = 0; contagem < this->size; contagem++) {
        if (this->menor(data, temporario->getInfo())) {
            return this->adicionaNaPosicaoDuplo(data, contagem);
        }
        temporario = temporario->getProximo();
    }
}

template <typename T>
T ListaDuplaCirc<T>::retiraDuplo() {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    T valor;
    ElementoDuplo<T> *temporario = this->sentinela->getAnterior();
    if (temporario == NULL) {
        valor = temporario->getInfo();
        this->sentinela->setProximo(this->sentinela);
        this->size--;
        delete temporario;
        return valor;
    }
    valor = temporario->getInfo();
    temporario->getAnterior()->setProximo(this->sentinela);
    this->sentinela->setAnterior(temporario->getAnterior());
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
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (temporario == NULL) {
        throw "Impossível remover";
    }
    this->sentinela->setProximo(temporario->getProximo());
    valor = temporario->getInfo();
    if (this->sentinela->getProximo() != NULL) {
        temporario->getProximo()->setAnterior(this->sentinela);
        this->sentinela->setAnterior(temporario->getAnterior()->getAnterior());
        delete temporario;
    }
    this->size--;
    return valor;
}

/*template <typename T>
T ListaDuplaCirc<T>::retiraDuplo() {
    if (this->listaVazia()) {
        throw "A lista esta vazia";
    }
    T valor;
    int contador;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (temporario == NULL) {
        valor = temporario->getInfo();
        this->sentinela->setProximo(this->sentinela);
        this->size--;
        delete temporario;
        return valor;
    }
    for (contador = 0; contador < this->size-2; contador++) {
        temporario = temporario->getProximo();
    }
    valor = temporario->getProximo()->getInfo();
    delete temporario->getProximo();
    temporario->setProximo(this->sentinela);
    this->sentinela->setAnterior(temporario);
    this->size--;
    return valor;
} */

template <typename T>
T ListaDuplaCirc<T>::retiraDaPosicaoDuplo(int pos) {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    } else if (pos < 0 || pos >= this->size) {
        throw "Posição inválida";
    } else if (pos == 0) {
        return this->retiraDoInicioDuplo();
    }
    int contador;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    for (contador = 0; contador < pos-1; contador++) {
        temporario = temporario->getProximo();
    }
    ElementoDuplo<T> *remover = temporario->getProximo();
    T valor = remover->getInfo();
    temporario->setProximo(remover->getProximo());
    if (temporario->getProximo() != NULL) {
        remover->getProximo()->setAnterior(temporario);
    }
    this->size--;
    return valor;
}

template <typename T>
T ListaDuplaCirc<T>::retiraEspecificoDuplo(const T& dado) {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    int posicao = this->posicaoDuplo(dado);
    return this->retiraDaPosicaoDuplo(posicao);
}

template <typename T>
void ListaDuplaCirc<T>::eliminaDoInicioDuplo() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    this->sentinela->setProximo(temporario->getProximo());
    if (this->sentinela->getProximo() != NULL) {
        temporario->getProximo()->setAnterior(this->sentinela);
        delete temporario;
    }
    this->size--;
}

template <typename T>
int ListaDuplaCirc<T>::verUltimo() {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    } else {
        return this->size-1;
    }
}

template <typename T>
int ListaDuplaCirc<T>::posicaoDuplo(const T& dado) const {
    int contador;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
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
T *ListaDuplaCirc<T>::posicaoMemDuplo(const T& dado) const {
    int contagem;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (temporario == NULL) {
        throw "Impossível verificar";
    }
    for (contagem = 0; contagem < this->size; contagem++) {
        if (temporario->getInfo() == dado) {
            T valor = temporario->getInfo();
            return &valor;
        }
        temporario = temporario->getProximo();
    }
    throw "O elemento não está presente na lista duplamente encadeada circular";
}

template <typename T>
T ListaDuplaCirc<T>::mostra(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw "Posição inválida";
    }
    int contador;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    for (contador = 0; contador < pos; contador++) {
        if (temporario == NULL) {
            throw "Impossível achar valor";
        }
        temporario = temporario->getProximo();
    }
    return temporario->getInfo();
}

template <typename T>
bool ListaDuplaCirc<T>::contemDuplo(const T& dado) {
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    int contagem;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (temporario == NULL) {
        throw "Impossível verificar";
    }
    for (contagem = 1; contagem <= this->size; contagem++) {
        if (temporario->getInfo() == dado) {
            return true;
        }
        temporario = temporario->getProximo();
    }
    return false;
}

template <typename T>
bool ListaDuplaCirc<T>::listaVazia() const {
    return this->size == 0;
}

template <typename T>
void ListaDuplaCirc<T>::destroiListaDuplo() {
    int contagem;
    ElementoDuplo<T> *anterior;
    ElementoDuplo<T> *atual = this->sentinela->getProximo();
    for (contagem = 0; contagem < this->size; contagem++) {
        anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    this->sentinela->setAnterior(this->sentinela);
    this->sentinela->setProximo(this->sentinela);
    this->size = 0;
}

template <typename T>
void ListaDuplaCirc<T>::imprimeLista() {
    int contagem;
    ElementoDuplo<T> *temporario = this->sentinela->getProximo();
    if (this->listaVazia()) {
        throw "A lista está vazia";
    }
    printf("Elemento antes do sentinela: %d\n", temporario->getAnterior()->
                                                    getAnterior()->getInfo());
    for (contagem = 1; contagem < this->size; contagem++) {
        printf("Elemento %d: %d\n", (contagem-1), temporario->getInfo());
        temporario = temporario->getProximo();
    }
    printf("Elemento %d: %d\n", (contagem-1), temporario->getInfo());
    printf("Elemento após o sentinela: %d\n", temporario->getProximo()->
                                                    getProximo()->getInfo());
}

template <typename T>
bool ListaDuplaCirc<T>::igual(T dado1, T dado2) {
    if (dado1 == dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaDuplaCirc<T>::maior(T dado1, T dado2) {
    if (dado1 > dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool ListaDuplaCirc<T>::menor(T dado1, T dado2) {
    if (dado1 < dado2) {
        return true;
    }
    return false;
}

#endif
