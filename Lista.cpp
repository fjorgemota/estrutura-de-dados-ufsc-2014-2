// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota
#include "Lista.hpp"

#define PRIMEIRO_ELEMENTO 0

Lista::Lista(int tamanho) {
    if (tamanho < 1) {
        throw "Impossivel criar lista";
    }
    this->topo = -1;
    this->arranjo = new int[tamanho];
}

void Lista::adicionar(int obj) {
    if (topo >= tamanho) {
        throw "Nao e possivel adicionar mais valores";
    }
    this->topo += 1;
    this->arranjo[this->topo] = obj;
}

int Lista::pegaTamanho() {
    return  this->topo + 1;
}

void Lista::removerUltimo() {
    this->remover(this->topo);
}

void Lista::removerPrimeiro() {
    this->remover(PRIMEIRO_ELEMENTO);
}

int Lista::pegaPrimeiro() {
    return this->pegaValor(PRIMEIRO_ELEMENTO);
}

int Lista::pegaUltimo() {
    return this->pegaValor(this->topo);
}

int Lista::pegaValor(int valor) {
    if (valor < 0 || valor >= topo) {
        throw "Posicao indefinida";
    }
    return this->arranjo[valor];
}

void Lista::remover(int posicao) {
    if (topo == -1) {
        throw "Nao ha elementos para remover";
    }
    for (int a = posicao-1; a <= topo; a++) {
        this->arranjo[a] = this->arranjo[a+1];
    }
    this->topo -= 1;
}

void Lista::troca(int posicao1, int posicao2) {
    int aux = this->pegaValor(posicao1);
    this->arranjo[posicao1] = this->pegaValor(posicao2);
    this->arranjo[posicao2] = aux;
}
