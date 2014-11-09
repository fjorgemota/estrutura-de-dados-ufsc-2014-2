// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_RB_CPP
#define NO_RB_CPP
#include "NoRB.hpp"
#include <cstdlib>
#include <vector>


template <typename T>
NoRB<T>::NoRB(const T& dado) : NoBinario<T>(dado)  {
    this->pai = NULL;

}

template <typename T>
NoRB<T>* NoRB<T>::balanco_insere(NoRB<T>* arv) {
    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>::balanco_remove(NoRB<T>* arv) {
    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>::pegaNovoNo(const T& dado) {
    return new NoRB<T>(dado);
}

template <typename T>
NoRB<T>* NoRB<T>::binarioParaRB(NoBinario<T> *binario) {
    NoRB<T> *raiz = static_cast<NoRB<T>*>(binario);
    if (raiz != NULL) {
        raiz->esquerda = this->binarioParaRB(binario->getEsquerda());
        raiz->direita = this->binarioParaRB(binario->getDireita());
    }
    return raiz;
}


template <typename T>
NoRB<T>::~NoRB() {
    // delete this->esquerda;
    // delete this->dado;
    // delete this->direita;
}


/** Métodos sobrescritos */

template <typename T>
std::vector<NoRB<T>* > NoRB<T>::getElementos() {
    std::vector<NoRB<T>* > resultado;
    unsigned int i;
    std::vector<NoBinario<T>* > elementos = NoBinario<T>::getElementos();
    for(i=0; i < elementos.size(); i++) {
        resultado.push_back(this->binarioParaRB(elementos[i]));
    }
    return resultado;
}

template <typename T>
NoRB<T>* NoRB<T>::getEsquerda() {
    return this->binarioParaRB(NoBinario<T>::getEsquerda());
}

template <typename T>
NoRB<T>* NoRB<T>::getDireita() {
    return this->binarioParaRB(NoBinario<T>::getDireita());
    
}

template <typename T>
NoRB<T>* NoRB<T>::inserir(const T& dado, NoRB<T>* arv) {
    return this->binarioParaRB(NoBinario<T>::inserir(dado, arv));
}

template <typename T>
NoRB<T>* NoRB<T>::remover(NoRB<T>* arv, const T& dado) {
    return this->binarioParaRB(NoBinario<T>::remover(arv, dado));
}

template <typename T>
NoRB<T>* NoRB<T>::minimo(NoRB<T>* nodo) {
    return this->binarioParaRB(NoBinario<T>::minimo(nodo));
}

#endif /* NO_RB_CPP */
