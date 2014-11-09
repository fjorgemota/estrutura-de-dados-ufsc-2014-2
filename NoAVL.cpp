// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_AVL_CPP
#define NO_AVL_CPP
#include "NoBinario.hpp"
#include "NoAVL.hpp"
#include <vector>

template <typename T>
NoAVL<T>::NoAVL (const T& dado): NoBinario<T>(dado) {
	this->altura = 0;
}

template <typename T>
NoAVL<T>* NoAVL<T>::pegaNovoNo(const T& dado) {
    return new NoAVL<T>(dado);
}

template <typename T>
NoAVL<T>* NoAVL<T>::binarioParaAVL(NoBinario<T> *binario) {
    NoAVL<T> *raiz = static_cast<NoAVL<T>*>(binario);
    if (raiz != NULL) {
        raiz->esquerda = this->binarioParaAVL(binario->getEsquerda());
        raiz->direita = this->binarioParaAVL(binario->getDireita());
    }
    return raiz;
}

template <typename T>
int NoAVL<T>::getAltura() {
	return this->altura;
}

template <typename T>
void NoAVL<T>::atualizaAltura(NoAVL<T>* raiz) {
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        raiz->altura = 0;
    } else {
        raiz->altura = this->max(raiz->esquerda, raiz->direita) + 1;
    }
}

template <typename T>
int NoAVL<T>::pegaBalanceamento(NoAVL<T>* raiz) {
	if (raiz->esquerda == NULL && raiz->direita == NULL) {
		return -1;
	} else if (raiz->esquerda != NULL && raiz->direita != NULL) {
		// Se altura > 0, o lado esquerdo e maior, caso contrario, direito.
		this->atualizaAltura(raiz->esquerda);
		this->atualizaAltura(raiz->direita);
		return (raiz->esquerda->getAltura() - raiz->direita->getAltura());
	} else if (raiz->esquerda != NULL) {
		this->atualizaAltura(raiz->esquerda);
		return (raiz->esquerda->getAltura() + 1);
	} else {
		this->atualizaAltura(raiz->direita);
		return (-1 - raiz->direita->getAltura());
	}
}


template <typename T>
NoAVL<T>* NoAVL<T>::balancear(NoAVL<T>* raiz) {
    int balanceamentoPai, balanceamentoFE, balanceamentoFD;
	this->atualizaAltura(raiz);
	balanceamentoPai = this->pegaBalanceamento(raiz);
	
	if (raiz->direita != NULL && balanceamentoPai < -1) {
	    balanceamentoFD = this->pegaBalanceamento(raiz->direita);
	    // Se a raiz possuir desbalanceamento a direita
    	if (balanceamentoFD == -1) {
    		return rotacaoSimplesEsquerda(raiz);
    	}
    	// Ha um desbalanceamento no filho a direita e, apos resolver,
    	// rotaciona a raiz para a esquerda para manter o equilibrio
    	if (balanceamentoFD == 1) {
    		raiz->direita = rotacaoSimplesDireita(raiz->direita);
    		return rotacaoSimplesEsquerda(raiz);
    	}
	}

    if (raiz->esquerda != NULL && balanceamentoPai > 1) {
        balanceamentoFE = this->pegaBalanceamento(raiz->esquerda);
    	// Se a raiz possuir desbalanceamento a esquerda
    	if (balanceamentoFE == 1) {
    		return rotacaoSimplesDireita(raiz);
    	}
    	
    	// Ha um desbalanceamento no filho a esquerda e, apos resolver,
    	// rotaciona a raiz para a direita para manter o equilibrio
    	if (balanceamentoFE == -1) {
    		raiz->esquerda = rotacaoSimplesEsquerda(raiz->esquerda);
    		return rotacaoSimplesDireita(raiz);
    	}
    }
	return raiz;
}

template<typename T>
NoAVL<T>* NoAVL<T>::rotacaoSimplesDireita(NoAVL<T>* X) {
	NoAVL<T>* Y;
	
	Y = X->esquerda;
	X->esquerda = Y->direita;
	Y->direita = X;
	
	this->atualizaAltura(Y);
	this->atualizaAltura(X);

	return X;
}

template<typename T>
NoAVL<T>* NoAVL<T>::rotacaoSimplesEsquerda(NoAVL<T>* X) {
	NoAVL<T>* Y;
	
	Y = X->direita;
	X->direita = Y->esquerda;
	Y->esquerda = X;

	this->atualizaAltura(Y);
	this->atualizaAltura(X);

	return X;
}

template <typename T>
NoAVL<T>* NoAVL<T>::balanco_insere(NoBinario<T>* arv) {
	NoAVL<T>* raiz = this->binarioParaAVL(arv);
	return this->balancear(raiz);
}

template <typename T>
NoAVL<T>* NoAVL<T>::balanco_remover(NoBinario<T>* arv) {
	NoAVL<T>* raiz = this->binarioParaAVL(arv);
	return this->balancear(raiz);
}

template <typename T>
int NoAVL<T>::max(NoAVL<T>* no1, NoAVL<T>* no2) {
	if (no1 == NULL && no2 == NULL) {
	    return -1;
	} else if (no1 == NULL) {
	    return no2->getAltura();
    } else if(no2 == NULL) {
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
    for(i=0; i < elementos.size(); i++) {
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