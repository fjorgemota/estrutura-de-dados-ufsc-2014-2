// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota
#include "Lista.hpp"

#define PRIMEIRO_ELEMENTO 0

Lista::Lista(int tamanhoMaximo) {
    if (tamanhoMaximo < 1) {
        throw "Impossivel criar lista com menos de 1 elemento";
    }
    this->topo = -1;
    this->arranjo = new int[tamanhoMaximo];
    this->tamanhoMaximo = tamanhoMaximo;
}

void Lista::adicionar(int obj) {
    if (this->topo >= this->tamanhoMaximo) {
        throw "Nao e possivel adicionar mais valores: Tamanho maximo excedido";
    }
    this->topo += 1;
    this->arranjo[this->topo] = obj;
}

bool Lista::listaCheia() {
    return this->pegaTamanho() == this->tamanhoMaximo;
}

bool Lista::listaVazia() {
    return this->pegaTamanho() == PRIMEIRO_ELEMENTO;
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

int Lista::pegaValor(int posicao) {
    if (posicao < 0 || posicao > topo) {
        throw "Posicao invalida: A posicao esta fora dos limites da lista";
    }
    return this->arranjo[posicao];
}

void Lista::remover(int posicao) {
    if (topo == -1) {
        throw "Nao ha elementos para remover: A lista esta vazia";
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
