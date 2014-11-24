#ifndef INDICE_CPP
#define INDICE_CPP
#include "Indice.hpp"
#include "../util/NoAVL.hpp"
#include "../util/ListaDupla.hpp"
#include "../util/FilaEnc.hpp"

template <typename T>
Indice<T>::Indice(const T& dado) : NoAVL<T>(dado) {}

template <typename T>
Indice<T>::~Indice() {}

/** Métodos sobrescritos */

template <typename T>
std::vector<Indice<T>* > Indice<T>::getElementos() {
    std::vector<Indice<T>* > resultado;
    unsigned int i;
    std::vector<NoAVL<T>* > elementos = NoAVL<T>::getElementos();
    for (i = 0; i < elementos.size(); i++) {
        resultado.push_back(this->AVLParaIndice(elementos[i]));
    }
    return resultado;
}

template <typename T>
Indice<T>* Indice<T>::getEsquerda() {
    return this->AVLParaIndice(NoAVL<T>::getEsquerda());
}

template <typename T>
Indice<T>* Indice<T>::getDireita() {
    return this->AVLParaIndice(NoAVL<T>::getDireita());
}

template <typename T>
Indice<T>* Indice<T>::inserir(const T& dado, Indice<T>* arv) {
    return this->AVLParaIndice(NoAVL<T>::inserir(dado, arv));
}

template <typename T>
Indice<T>* Indice<T>::remover(Indice<T>* arv, const T& dado) {
    return this->AVLParaIndice(NoAVL<T>::remover(arv, dado));
}

template <typename T>
Indice<T>* Indice<T>::minimo(Indice<T>* nodo) {
    return this->AVLParaIndice(NoAVL<T>::minimo(nodo));
}

/** Métodos Indice */

template <typename T>
Indice<T>* Indice<T>::pegaNovoNo(const T& dado) {
	return new Indice<T>(dado);
}

template <typename T>
Indice<T>* Indice<T>::AVLParaIndice(NoAVL<T> *avl) {
	Indice<T> *raiz = static_cast<Indice<T>*>(avl);
    if (raiz != NULL) {
        raiz->esquerda = this->AVLParaIndice(avl->getEsquerda());
        raiz->direita = this->AVLParaIndice(avl->getDireita());
    }
    return raiz;
}

template <typename T>
ListaDupla<T > Indice<T>::breadth_first()  {
	FilaEnc<Indice<T>* > *itens = new FilaEnc<Indice<T>* >();
	ListaDupla<T > *dados = new ListaDupla<T >();
	itens->inclui(this);
	while(itens->filaVazia() == false) {
		Indice<T > *nodo = itens->retira();
		if (nodo->getEsquerda() != NULL) {
			itens->inclui(nodo->getEsquerda());
		}
		if (nodo->getDireita() != NULL) {
			itens->inclui(nodo->getDireita());
		}
		dados->adicionaDuplo(*(nodo->getDado()));
	}
	return *dados;
}

#endif	