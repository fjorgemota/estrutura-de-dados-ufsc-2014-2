#ifndef INDICE_SECUNDARIO_CPP
#define INDICE_SECUNDARIO_CPP
#include "IndiceSecundario.hpp"
#include "Indice.hpp"
#include "../modelos/Word.hpp"
#include "../util/ListaDupla.hpp"

IndiceSecundario::IndiceSecundario(const Word& dado) : Indice<Word>(dado) {}

IndiceSecundario::~IndiceSecundario() {}

/** Métodos sobrescritos */

std::vector<IndiceSecundario* > IndiceSecundario::getElementos() {
    std::vector<IndiceSecundario* > resultado;
    unsigned int i;
    std::vector<Indice* > elementos = Indice<Word>::getElementos();
    for (i = 0; i < elementos.size(); i++) {
        resultado.push_back(this->IndiceParaIndiceSecundario(elementos[i]));
    }
    return resultado;
}

IndiceSecundario* IndiceSecundario::getEsquerda() {
    return this->IndiceParaIndiceSecundario(Indice<Word>::getEsquerda());
}

IndiceSecundario* IndiceSecundario::getDireita() {
    return this->IndiceParaIndiceSecundario(Indice<Word>::getDireita());
}

IndiceSecundario* IndiceSecundario::inserir(const Word& dado, IndiceSecundario* arv) {
    return this->IndiceParaIndiceSecundario(Indice<Word>::inserir(dado, arv));
}

IndiceSecundario* IndiceSecundario::remover(IndiceSecundario* arv, const Word& dado) {
    return this->IndiceParaIndiceSecundario(Indice<Word>::remover(arv, dado));
}

IndiceSecundario* IndiceSecundario::minimo(IndiceSecundario* nodo) {
    return this->IndiceParaIndiceSecundario(Indice<Word>::minimo(nodo));
}

/** Métodos IndiceSecundario */

IndiceSecundario* IndiceSecundario::pegaNovoNo(const Word& dado) {
	return new IndiceSecundario(dado);
}

IndiceSecundario* IndiceSecundario::IndiceParaIndiceSecundario(Indice<Word> *avl) {
	IndiceSecundario *raiz = static_cast<IndiceSecundario*>(avl);
    if (raiz != NULL) {
        raiz->esquerda = this->IndiceParaIndiceSecundario(avl->getEsquerda());
        raiz->direita = this->IndiceParaIndiceSecundario(avl->getDireita());
    }
    return raiz;
}

ListaDupla<Word > IndiceSecundario::breadth_first()  {
	return Indice<Word>::breadth_first();
}

#endif /** INDICE_SECUNDARIO_CPP */