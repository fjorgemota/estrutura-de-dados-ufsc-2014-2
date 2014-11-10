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
    NoRB<T>* pai, avo;
    arv->cor = RB_RUBRO;
    while (arv->pai != NULL && !arv->pai->cor) {
        pai = arv->pai;
        avo = pai->pai;
        // Se avo for rubro e pai negro,
        // propriedade 4 ferida!
        if (!avo->cor && !pai->cor) {
            if (avo->direita->getDado() == pai->getDado()) {
                return this->correcaoDireita(arv, pai, avo);
            } else {
                return this->correcaoEsquerda(arv, pai, avo);
            }
        }
    }
    arv->cor = RB_NEGRO;
    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>*::correcaoEsquerda(NoRB<T>* arv, 
                        NoRB<T>* pai, NoRB<T>* avo) {
    NoRB<T>* tio;
    tio = avo->direita;
    if (!tio->cor) {
        tio->cor = RB_NEGRO;
        pai->cor = RB_NEGRO;
        avo->cor = RB_RUBRO;
        arv = avo;
    } else if (arv->getDado() == pai->direita->getDado()) {
        this->rotacaoSimplesEsquerda(pai);
        arv = arv->esquerda;
    }
    pai->cor = RB_NEGRO;
    avo->cor = RB_RUBRO;
    this->rotacaoSimplesDireita(avo);
    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>*::correcaoDireita(NoRB<T>* arv, 
                        NoRB<T>* pai, NoRB<T>* avo) {
    NoRB<T>* tio;
    tio = avo->esquerda;
    if (!tio->cor) {
        tio->cor = RB_NEGRO;
        pai->cor = RB_NEGRO;
        avo->cor = RB_RUBRO;
        arv = avo;
    } else if (pai->esquerda->getDado() == arv->getDado()) {
        this->rotacaoSimplesDireita(pai);
        arv = arv->direita;
    }
    pai->cor = RB_NEGRO;
    avo->cor = RB_RUBRO;
    this->rotacaoSimplesEsquerda(avo);
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

template <typename T>
NoRB<T>* NoRB<T>::rotacaoSimplesDireita(NoRB<T>* raiz) {
    NoRB<T>* pai, nodo;
    bool lado;

    pai = raiz->getPai();
    if (raiz->getEsquerda()->getDado() == pai->getDado()) {
        lado = true;
    } else {
        lado = false;
    }
    nodo = raiz->esquerda;
    raiz->esquerda = nodo->direita;
    nodo->direita = raiz;

    nodo->pai = pai;
    raiz->esquerda->pai = nodo;
    raiz->direita->pai = raiz;

    if (lado) {
        pai->esquerda = nodo;
    } else {
        pai->direita = nodo;
    }
    return nodo;
}

template <typename T>
NoRB<T>* NoRB<T>::rotacaoSimplesEsquerda(NoRB<T>* raiz) {
    NoRB<T>* pai, nodo;
    bool lado;

    pai = raiz->getPai();
    if (raiz->getEsquerda()->getDado() == pai->getDado()) {
        lado = true;
    } else {
        lado = false;
    }
    nodo = raiz->direita;
    raiz->direita = nodo->esquerda;
    nodo->esquerda = raiz;

    nodo->pai = pai;
    raiz->direita->pai = nodo;
    raiz->esquerda->pai = raiz;

    if (lado) {
        pai->esquerda = nodo;
    } else {
        pai->direita = nodo;
    }
    return nodo;
}

template <typename T>
NoRB<T>* NoRB<T>::getPai() {
    return this->pai;
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
