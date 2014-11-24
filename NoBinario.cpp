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
    delete this->getEsquerda();
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
            arv = arv->getDireita();
        } else {
            arv = arv->getEsquerda();
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
        if (arv->getEsquerda() == NULL) {
            arv->esquerda = this->pegaNovoNo(dado);
        } else {
            arv->esquerda = this->inserir(dado, arv->getEsquerda());
        }
    } else if (dado) {
        if (arv->getDireita() == NULL) {
            arv->direita = this->pegaNovoNo(dado);
        } else {
            arv->direita = this->inserir(dado, arv->getDireita());
        }
    }
    return this->balanco_insere(arv);
}

template <typename T>
NoBinario<T>* NoBinario<T>::remover(NoBinario<T>* arv, const T& dado) {
    if (arv == NULL) {
        return arv;
    }
    if (dado < *(arv->getDado())) {
        // Elemento deve estar à esquerda
        arv->esquerda = this->remover(arv->getEsquerda(), dado);
        return this->balanco_remove(arv);
    }
    if (dado > *(arv->getDado())) {
        // Elemento deve estar à direita
        arv->direita = this->remover(arv->getDireita(), dado);
        return this->balanco_remove(arv);
    }
    // Encontrado elemento que queremos remover
    if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
        // Dois filhos
        NoBinario<T> *tmp = this->minimo(arv->getDireita());
        arv->dado = new T(static_cast<T const&>(*(tmp->getDado())));
        arv->direita = this->remover(arv->getDireita(), *(tmp->getDado()));
        return this->balanco_remove(arv);
    }
    if (arv->getDireita() != NULL) {
        return this->balanco_remove(arv->getDireita());
    }
    if (arv->getEsquerda() != NULL) {
        return this->balanco_remove(arv->getEsquerda());
    }
    delete arv;
    return NULL;
}

template <typename T>
NoBinario<T>* NoBinario<T>::minimo(NoBinario<T>* nodo) {
    if (nodo->getEsquerda() == NULL) {
        return nodo;
    }
    return this->minimo(nodo->getEsquerda());
}

template <typename T>
void NoBinario<T>::preOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    elementos.push_back(nodo);
    this->preOrdem(nodo->getEsquerda());
    this->preOrdem(nodo->getDireita());
}

template <typename T>
void NoBinario<T>::emOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->emOrdem(nodo->getEsquerda());
    this->elementos.push_back(nodo);
    this->emOrdem(nodo->getDireita());
}

template <typename T>
void NoBinario<T>::posOrdem(NoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    this->posOrdem(nodo->getEsquerda());
    this->posOrdem(nodo->getDireita());
    this->elementos.push_back(nodo);
}

#endif /* NO_BINARIO_CPP */
