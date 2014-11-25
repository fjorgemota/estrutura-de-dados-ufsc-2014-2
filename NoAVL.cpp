// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_AVL_CPP
#define NO_AVL_CPP
#include "NoAVL.hpp"
#include <vector>
#include "NoBinario.hpp"

template <typename T>
NoAVL<T>::NoAVL(const T& dado): NoBinario<T>(dado) {
    this->altura = 0;
}

template <typename T>
NoAVL<T>::~NoAVL() {}

template <typename T>
NoAVL<T>* NoAVL<T>::pegaNovoNo(const T& dado) {
    return new NoAVL<T>(dado);
}

template <typename T>
NoAVL<T>* NoAVL<T>::binarioParaAVL(NoBinario<T> *binario) {
    NoAVL<T> *raiz = static_cast<NoAVL<T>*>(binario);
    return raiz;
}

template <typename T>
int NoAVL<T>::getAltura() {
    return this->altura;
}

template <typename T>
void NoAVL<T>::atualizaAltura(NoAVL<T>* raiz) {
    raiz->altura = this->maximo(raiz->getEsquerda(), raiz->getDireita()) + 1;
}

template <typename T>
int NoAVL<T>::pegaBalanceamento(NoAVL<T>* raiz) {
    if (raiz->getEsquerda() == NULL && raiz->getDireita() == NULL) {
        return -1;
    } else if (raiz->getEsquerda() != NULL && raiz->getDireita() != NULL) {
        // Se altura > 0, o lado esquerdo e maior, caso contrario, direito.
        this->atualizaAltura(raiz->getEsquerda());
        this->atualizaAltura(raiz->getDireita());
        return (raiz->getEsquerda()->getAltura() -
                    raiz->getDireita()->getAltura());
    } else if (raiz->getEsquerda() != NULL) {
        this->atualizaAltura(raiz->getEsquerda());
        return (raiz->getEsquerda()->getAltura() + 1);
    } else {
        this->atualizaAltura(raiz->getDireita());
        return (-1 - raiz->getDireita()->getAltura());
    }
}


template <typename T>
NoAVL<T>* NoAVL<T>::balancear(NoAVL<T>* raiz) {
    int balanceamentoPai, balanceamentoFE, balanceamentoFD;
    balanceamentoPai = this->pegaBalanceamento(raiz);
    if (raiz->getDireita() != NULL && balanceamentoPai < -1) {
        balanceamentoFD = this->pegaBalanceamento(raiz->getDireita());
        // Ha um desbalanceamento no filho a direita e, apos resolver,
        // rotaciona a raiz para a esquerda para manter o equilibrio
        if (balanceamentoFD == 1) {
            raiz->direita = this->rotacaoSimplesEsquerda(raiz->getDireita());
        }
        // Se a raiz possuir desbalanceamento a direita
        raiz = this->rotacaoSimplesDireita(raiz);
    } else if (raiz->getEsquerda() != NULL && balanceamentoPai > 1) {
        balanceamentoFE = this->pegaBalanceamento(raiz->getEsquerda());
        // Ha um desbalanceamento no filho a esquerda e, apos resolver,
        // rotaciona a raiz para a direita para manter o equilibrio
        if (balanceamentoFE == -1) {
            raiz->esquerda = this->rotacaoSimplesDireita(raiz->getEsquerda());
        }
        // Se a raiz possuir desbalanceamento a esquerda
        raiz = this->rotacaoSimplesEsquerda(raiz);
    }
    this->atualizaAltura(raiz);
    return raiz;
}

template<typename T>
NoAVL<T>* NoAVL<T>::rotacaoSimplesEsquerda(NoAVL<T>* X) {
    NoAVL<T>* Y;

    Y = X->getEsquerda();
    X->esquerda = Y->getDireita();
    Y->direita = X;

    this->atualizaAltura(Y);
    this->atualizaAltura(X);

    return Y;
}

template<typename T>
NoAVL<T>* NoAVL<T>::rotacaoSimplesDireita(NoAVL<T>* X) {
    NoAVL<T>* Y;

    Y = X->getDireita();
    X->direita = Y->getEsquerda();
    Y->esquerda = X;

    this->atualizaAltura(Y);
    this->atualizaAltura(X);

    return Y;
}

template <typename T>
NoAVL<T>* NoAVL<T>::balanco_insere(NoBinario<T>* arv) {
    NoAVL<T>* raiz = this->binarioParaAVL(arv);
    return this->balancear(raiz);
}

template <typename T>
NoAVL<T>* NoAVL<T>::balanco_remove(NoBinario<T>* arv) {
    NoAVL<T>* raiz = this->binarioParaAVL(arv);
    return this->balancear(raiz);
}

template <typename T>
int NoAVL<T>::maximo(NoAVL<T>* no1, NoAVL<T>* no2) {
    if (no1 == NULL && no2 == NULL) {
        return -1;
    } else if (no1 == NULL) {
        return no2->getAltura();
    } else if (no2 == NULL) {
        return no1->getAltura();
    }

    if (no1->getAltura() > no2->getAltura()) {
        return no1->getAltura();
    } else {
        return no2->getAltura();
    }
}

/** Métodos sobrescritos */

template <typename T>
std::vector<NoAVL<T>* > NoAVL<T>::getElementos() {
    std::vector<NoAVL<T>* > resultado;
    unsigned int i;
    std::vector<NoBinario<T>* > elementos = NoBinario<T>::getElementos();
    for (i = 0; i < elementos.size(); i++) {
        resultado.push_back(this->binarioParaAVL(elementos[i]));
    }
    return resultado;
}

template <typename T>
NoAVL<T>* NoAVL<T>::getEsquerda() {
    return this->binarioParaAVL(NoBinario<T>::getEsquerda());
}

template <typename T>
NoAVL<T>* NoAVL<T>::getDireita() {
    return this->binarioParaAVL(NoBinario<T>::getDireita());
}

template <typename T>
NoAVL<T>* NoAVL<T>::inserir(const T& dado, NoAVL<T>* arv) {
    return this->binarioParaAVL(NoBinario<T>::inserir(dado, arv));
}

template <typename T>
NoAVL<T>* NoAVL<T>::remover(NoAVL<T>* arv, const T& dado) {
    return this->binarioParaAVL(NoBinario<T>::remover(arv, dado));
}

template <typename T>
NoAVL<T>* NoAVL<T>::minimo(NoAVL<T>* nodo) {
    return this->binarioParaAVL(NoBinario<T>::minimo(nodo));
}

#endif /* NO_AVL_CPP */
