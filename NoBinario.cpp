// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_BINARIO_CPP
#define NO_BINARIO_CPP
#include "NoBinario.hpp"
#include <cstdlib>
#include <vector>

template <typename T>
NoBinario<T>* NoBinario<T>::balanco_insere(NoBinario<T>* arv) {
    return arv;
}

template <typename T>
NoBinario<T>* NoBinario<T>::balanco_remove(NoBinario<T>* arv) {
    return arv;
}

template <typename T>
NoBinario<T>::NoBinario(const T& dado) {
    this->dado = new T(dado);
    this->esquerda = NULL;
    this->direita = NULL;
}

template <typename T>
NoBinario<T>::~NoBinario() {
    delete this->esquerda;
    delete this->direita;
    delete this->dado;
}

template <typename T>
T* NoBinario<T>::getDado() {
    return this->dado;
}

template <typename T>
std::vector<NoBinario<T>* > NoBinario<T>::getElementos() {
    return this->elementos;
}

template <typename T>
NoBinario<T>* NoBinario<T>::getDireita() {
    return this->direita;
}

template <typename T>
NoBinario<T>* NoBinario<T>::getEsquerda() {
    return this->esquerda;
}

template <typename T>
NoBinario<T>* NoBinario<T>::pegaNovoNo(const T& dado) {
    return new NoBinario<T>(dado);
}

template <typename T>
T* NoBinario<T>::busca(const T& info, NoBinario<T> *arv) {
    while (arv != NULL && *(arv->getDado()) != info) {
        if (*(arv->getDado()) < info) {
            arv = arv->direita;
        } else {
            arv = arv->esquerda;
        }
    }
    if (arv == NULL) {
        throw "Elemento não encontrado";
    }
    return arv->getDado();
}

template <typename T>
NoBinario<T>* NoBinario<T>::inserir(const T& dado, NoBinario<T>* arv) {
    NoBinario<T> *resultado = arv;
    if (dado < *(arv->getDado())) {
        if (arv->esquerda == NULL) {
            resultado = this->pegaNovoNo(dado);
            arv->esquerda = resultado;
        } else {
            resultado = this->inserir(dado, arv->esquerda);
        }
    } else {
        if (arv->direita == NULL) {
            resultado = this->pegaNovoNo(dado);
            arv->direita = resultado;
        } else {
            resultado = this->inserir(dado, arv->direita);
        }
    }
    this->balanco_insere(arv);
    return resultado;
}

template <typename T>
NoBinario<T>* NoBinario<T>::remover(NoBinario<T>* arv, const T& dado) {
    if (arv == NULL) {
        return arv;
    }
    if (dado < *(arv->getDado())) {
        // Elemento deve estar à esquerda
        arv->esquerda = this->remover(arv->esquerda, dado);
        this->balanco_remove(arv);
        return arv;
    }
    if (dado > *(arv->getDado())) {
        // Elemento deve estar à direita
        arv->direita = this->remover(arv->direita, dado);
        this->balanco_remove(arv);
        return arv;
    }
    // Encontrado elemento que queremos remover
    if (arv->direita != NULL && arv->esquerda != NULL) {
        // Dois filhos
        NoBinario<T> *tmp = this->minimo(arv->direita);
        arv->dado = new T(static_cast<T const&>(*(tmp->getDado())));
        arv->direita = this->remover(arv->direita, *(tmp->getDado()));
        return this->balanco_remove(arv);
    }
    if (arv->direita != NULL) {
        return this->balanco_remove(arv->direita);
    }
    if (arv->esquerda != NULL) {
        return this->balanco_remove(arv->esquerda);
    }
    delete arv;
    return NULL;
}

template <typename T>
NoBinario<T>* NoBinario<T>::minimo(NoBinario<T>* nodo) {
    if (nodo->esquerda == NULL) {
        return nodo;
    }
    return this->minimo(nodo->esquerda);
}

template <typename T>
void NoBinario<T>::preOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    elementos.push_back(nodo);
    this->preOrdem(nodo->esquerda);
    this->preOrdem(nodo->direita);
}

template <typename T>
void NoBinario<T>::emOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->emOrdem(nodo->esquerda);
    this->elementos.push_back(nodo);
    this->emOrdem(nodo->direita);
}

template <typename T>
void NoBinario<T>::posOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->posOrdem(nodo->esquerda);
    this->posOrdem(nodo->direita);
    this->elementos.push_back(nodo);
}

#endif /* NO_BINARIO_CPP */
