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
    // delete this->esquerda;
    // delete this->dado;
    // delete this->direita;
}

template <typename T>
T* NoBinario<T>::getDado() {
    return this->dado;
}

template <typename T>
NoBinario<T>* NoBinario<T>::getElementos() {
    return &this->elementos[0];
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
    if (dado < *(arv->getDado())) {
        if (arv->esquerda == NULL) {
            NoBinario<T>* oNovo = new NoBinario(dado);
            arv->esquerda = oNovo;
        } else {
            return this->inserir(dado, arv->esquerda);
        }
    } else {
        if (arv->direita == NULL) {
            NoBinario<T>* oNovo = new NoBinario(dado);
            arv->direita = oNovo;
        } else {
            return this->inserir(dado, arv->direita);
        }
    }
    return this->balanco_insere(arv);;
}

template <typename T>
NoBinario<T>* NoBinario<T>::remover(NoBinario<T>* arv, const T& dado) {
    if (arv == NULL) {
        return arv;
    }
    if (dado < *(arv->getDado())) {
        // Elemento deve estar à esquerda
        arv->esquerda = this->remover(arv->esquerda, dado);
        return arv;
    }
    if (dado > *(arv->getDado())) {
        // Elemento deve estar à direita
        arv->direita = this->remover(arv->direita, dado);
        return arv;
    }
    // Encontrado elemento que queremos remover
    if (arv->direita != NULL && arv->esquerda != NULL) {
        // Dois filhos
        NoBinario<T> *tmp = this->minimo(arv->direita);
        arv->dado = tmp->getDado();
        arv->direita = this->remover(arv->direita, *(arv->getDado()));
        return arv;
    }
    if (arv->direita != NULL) {
        return arv->direita;
    }
    if (arv->esquerda != NULL) {
        return arv->esquerda;
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
    elementos.push_back(*nodo);
    this->preOrdem(nodo->esquerda);
    this->preOrdem(nodo->direita);
}

template <typename T>
void NoBinario<T>::emOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->emOrdem(nodo->esquerda);
    this->elementos.push_back(*nodo);
    this->emOrdem(nodo->direita);
}

template <typename T>
void NoBinario<T>::posOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->posOrdem(nodo->esquerda);
    this->posOrdem(nodo->direita);
    this->elementos.push_back(*nodo);
}

#endif /* NO_BINARIO_CPP */
