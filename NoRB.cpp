// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_RB_CPP
#define NO_RB_CPP
#include "NoRB.hpp"
#include <vector>
#include <cstdlib>
#include "NoBinario.hpp"

template <typename T>
NoRB<T>::NoRB(const T& dado) : NoBinario<T>(dado)  {
    this->pai = NULL;
}


template <typename T>
NoRB<T>::~NoRB() {
    delete this->pai;
}

template <typename T>
NoRB<T>* NoRB<T>::balanco_insere(NoBinario<T>* arv_b) {
    NoRB<T> *pai, *avo;
    NoRB<T> *arv = this->binarioParaRB(arv_b);
    arv->cor = RB_RUBRO;
    while (arv->pai != NULL && arv->pai->cor == RB_RUBRO) {
        pai = arv->pai;
        avo = pai->pai;
        if (pai != NULL && avo != NULL) {
            if (avo->direita->getDado() == pai->getDado()) {
                return this->correcaoDireitaInsercao(arv, pai, avo);
            } else {
                return this->correcaoEsquerdaInsercao(arv, pai, avo);
            }
        }
    }
    arv->cor = RB_NEGRO;
    return arv;
}

template <typename T>
NoRB<T>* NoRB<T>::correcaoEsquerdaInsercao(NoRB<T>* arv,
                        NoRB<T>* pai, NoRB<T>* avo) {
    NoRB<T>* tio;
    tio = avo->direita;
    if (tio->cor == RB_RUBRO) {
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
NoRB<T>* NoRB<T>::correcaoDireitaInsercao(NoRB<T>* arv,
                        NoRB<T>* pai, NoRB<T>* avo) {
    NoRB<T>* tio;
    tio = avo->esquerda;
    if (tio->cor == RB_RUBRO) {
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
NoRB<T>* NoRB<T>::balanco_remove(NoBinario<T>* arv_b) {
    NoRB<T> *novo;
    NoRB<T> *arv = this->binarioParaRB(arv_b);
    novo = this->minimo(arv->direita);
    novo->cor = arv->cor;
    if (novo->cor == RB_NEGRO &&
            (novo->direita->cor == RB_RUBRO
                || novo->esquerda->cor == RB_RUBRO)) {
        novo->cor = RB_RUBRO;
        novo->direita->cor = RB_NEGRO;
        novo->esquerda->cor = RB_NEGRO;
    }
    if ((novo->cor == RB_NEGRO || novo->cor == RB_RUBRO)
                    && novo->direita->cor == RB_NEGRO) {
        this->correcaoDireitaRemocao(novo);
    } else if ((novo->cor == RB_NEGRO || novo->cor == RB_RUBRO)
                    && novo->esquerda->cor == RB_NEGRO) {
        this->correcaoEsquerdaRemocao(novo);
    }

    return novo;
}

template <typename T>
NoRB<T>* NoRB<T>::correcaoEsquerdaRemocao(NoRB<T>* raiz) {
    NoRB<T> *irmao = raiz->pai->direita;
    NoRB<T> *pai = raiz->pai;
    if (irmao->cor == RB_RUBRO) {
        pai->cor = RB_NEGRO;
        irmao->cor = RB_RUBRO;
        this->rotacaoSimplesEsquerda(pai);
    }
    if (irmao->direita->cor == RB_NEGRO
        && irmao->esquerda->cor == RB_NEGRO) {
        irmao->cor = RB_RUBRO;
        raiz = pai;
    } else if (irmao->direita->cor == RB_NEGRO
        && irmao->esquerda->cor == RB_RUBRO) {
        irmao->cor = RB_RUBRO;
        irmao->esquerda = RB_NEGRO;
        this->rotacaoSimplesDireita(irmao);
    }
    if (irmao->direita->cor == RB_RUBRO) {
        irmao->direita->cor = RB_NEGRO;
        irmao->cor = pai->cor;
        pai = RB_NEGRO;
        this->rotacaoSimplesEsquerda(pai);
    }
    return raiz;
}

template <typename T>
NoRB<T>* NoRB<T>::correcaoDireitaRemocao(NoRB<T>* raiz) {
    NoRB<T> *irmao = raiz->pai->esquerda;
    NoRB<T> *pai = raiz->pai;
    if (irmao->cor == RB_RUBRO) {
        pai->cor = RB_NEGRO;
        irmao->cor = RB_RUBRO;
        this->rotacaoSimplesDireita(pai);
    }
    if (irmao->esquerda->cor == RB_NEGRO && irmao->direita->cor == RB_NEGRO) {
        irmao->cor = RB_RUBRO;
        raiz = pai;
    } else if (irmao->esquerda->cor == RB_NEGRO
        && irmao->direita->cor == RB_RUBRO) {
        irmao->cor = RB_RUBRO;
        irmao->direita->cor = RB_NEGRO;
        this->rotacaoSimplesEsquerda(irmao);
    }
    if (irmao->esquerda->cor == RB_RUBRO) {
        irmao->esquerda->cor = RB_NEGRO;
        irmao->cor = pai->cor;
        pai->cor = RB_NEGRO;
        this->rotacaoSimplesDireita(pai);
    }
    return raiz;
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
NoRB<T>* NoRB<T>::rotacaoSimplesDireita(NoRB<T>* raiz) {
    NoRB<T> *pai, *nodo;
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
    NoRB<T> *pai, *nodo;
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

template <typename T>
bool NoRB<T>::getCor() {
    return this->cor;
}

/** Métodos sobrescritos */

template <typename T>
std::vector<NoRB<T>* > NoRB<T>::getElementos() {
    std::vector<NoRB<T>* > resultado;
    unsigned int i;
    std::vector<NoBinario<T>* > elementos = NoBinario<T>::getElementos();
    for (i = 0; i < elementos.size(); i++) {
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
