// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_CPP
#define LISTA_CPP
#include "Lista.hpp"
#define PRIMEIRO_ELEMENTO 0

template <typename T>
Lista<T>::Lista(int tamanhoMaximo) {
    if (tamanhoMaximo < 1) {
        throw "Impossível criar lista com menos de 1 elemento";
    }
    this->topo = -1;
    this->arranjo = new T[tamanhoMaximo];
    this->tamanhoMaximo = tamanhoMaximo;
}

template <typename T>
int Lista<T>::Adiciona(T obj) {
    this->topo += 1;
    if (this->topo >= this->tamanhoMaximo) {
        throw "Não é possível adicionar mais valores: Tamanho máximo excedido";
    }
    this->arranjo[this->topo] = obj;
    return this->topo;
}

template <typename T>
int Lista<T>::AdicionaNaPosicao(T dado, int destino) {
    if (destino >= this->tamanhoMaximo || destino < 0) {
        throw "Não é possível adicionar o valor na posição especificada";
    }
    int posicao;
    this->topo += 1;
    for (posicao = topo; posicao > destino; posicao--) {
        this->arranjo[posicao] = this->arranjo[posicao-1];
    }
    this->arranjo[destino] = dado;
    return destino;
}

template <typename T>
bool Lista<T>::ListaCheia() {
    return this->pegaTamanho() == this->tamanhoMaximo;
}

template <typename T>
bool Lista<T>::ListaVazia() {
    return this->pegaTamanho() == PRIMEIRO_ELEMENTO;
}

template <typename T>
int Lista<T>::pegaTamanho() {
    return  this->topo + 1;
}

template <typename T>
T Lista<T>::Retira() {
    if (this->ListaVazia()) {
        throw "Não há elementos para remover, a lista está vazia";
    }
    this->topo -= 1;
    return this->arranjo[this->topo + 1];
}

template <typename T>
T Lista<T>::RetiraDoInicio() {
    T valor = this->RetiraDaPosicao(PRIMEIRO_ELEMENTO);
    return valor;
}

template <typename T>
T Lista<T>::pegaPrimeiro() {
    return this->pegaValor(PRIMEIRO_ELEMENTO);
}

template <typename T>
T Lista<T>::pegaUltimo() {
    return this->pegaValor(this->topo);
}

template <typename T>
T Lista<T>::pegaValor(int posicao) {
    if (posicao < 0 || posicao > topo) {
        throw "Posição inválida: A posição está fora dos limites da lista";
    }
    return this->arranjo[posicao];
}

template <typename T>
T Lista<T>::RetiraDaPosicao(int fonte) {
    if (this->ListaVazia()) {
        throw "Não há elementos para remover: A lista está vazia";
    } else if (fonte > topo || fonte < 0) {
        throw "Impossivel remover valores: posiçao invalida";
    }
    int posicao;
    T valor;
    valor = this->arranjo[fonte];
    posicao = fonte;
    for (int a = posicao; a <= topo; a++) {
        this->arranjo[a] = this->arranjo[a+1];
    }
    this->topo -= 1;
    return valor;
}

template <typename T>
int Lista<T>::AdicionaNoInicio(T dado) {
    if (this->ListaCheia()) {
        throw "Lista Cheia, não é possível adicionar mais elementos";
    }
    return this->AdicionaNaPosicao(dado, PRIMEIRO_ELEMENTO);
}

template <typename T>
int Lista<T>::AdicionaEmOrdem(T dado) {
    if (this->ListaCheia()) {
        throw "A lista está cheia";
    }
    int posicao = 0;
    while (posicao <= this->topo &&
            this->Maior(dado, this->arranjo[posicao])) {
        posicao++;
    }
    return this->AdicionaNaPosicao(dado, posicao);
}

template <typename T>
T Lista<T>::RetiraEspecifico(T dado) {
    if (this->ListaVazia()) {
        throw "A lista esta vazia";
    } else if (!this->Contem(dado)) {
        throw "O dado não pertence à lista";
    }
    int h;
    h = this->Posicao(dado);
    return this->RetiraDaPosicao(h);
}

template <typename T>
void Lista<T>::troca(int posicao1, int posicao2) {
    int aux = this->pegaValor(posicao1);
    this->arranjo[posicao1] = this->pegaValor(posicao2);
    this->arranjo[posicao2] = aux;
}

template <typename T>
void Lista<T>::DestroiLista() {
    this->topo = -1;
}

template <typename T>
bool Lista<T>::Contem(T dado) {
    int h;
    for (h = 0; h <= topo; h++) {
        if (this->arranjo[h] == dado) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Lista<T>::Posicao(T dado) {
    int a;
    for (a = 0; a<= topo; a++) {
        if (this->arranjo[a] == dado) {
            return a;
        }
    }
    throw "O dado não pertence à lista";
}

template <typename T>
int Lista<T>::pegaTopo() {
    return this->topo;
}

template <typename T>
bool Lista<T>::Igual(T dado1, T dado2) {
    if (!this->Contem(dado1)) {
        throw "O primeiro dado não pertence à lista";
    } else if (!this->Contem(dado2)) {
        throw "O segundo dado não pertence à lista";
    }
    if (dado1 == dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::Maior(T dado1, T dado2) {
    if (!this->Contem(dado1)) {
        throw "O primeiro dado não pertence à lista";
    } else if (!this->Contem(dado2)) {
        throw "O segundo dado não pertence à lista";
    }
    if (dado1 > dado2) {
        return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::Menor(T dado1, T dado2) {
    if (!this->Contem(dado1)) {
        throw "O primeiro dado não pertence à lista";
    } else if (!this->Contem(dado2)) {
        throw "O segundo dado não pertence à lista";
    }
    if (dado1 < dado2) {
        return true;
    }
    return false;
}

/*template<typename T>
bool T::operator==(T dado, T dado2) {
    if (dado == dado2) {
        return true;
    }
    return false;
}

template<typename T>
bool T::operator>(T dado, T dado2) {
    if (T > t) {
        return true;
    }
    return false;
}

template<typename T>
bool T::operator<(T dado, T dado2) {
    if (T < t) {
        return true;
    }
    return false;
}*/

#endif
