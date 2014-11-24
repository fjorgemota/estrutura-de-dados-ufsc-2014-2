#ifndef INDICE_PRIMARIO_CPP
#define INDICE_PRIMARIO_CPP
#include "IndicePrimario.hpp"
#include "Indice.hpp"
#include "../util/ListaDupla.hpp"

IndicePrimario::IndicePrimario(const ManPage& dado) : Indice(dado) {}

IndicePrimario::~IndicePrimario() {}

/** Métodos sobrescritos */

std::vector<IndicePrimario* > IndicePrimario::getElementos() {
    std::vector<IndicePrimario* > resultado;
    unsigned int i;
    std::vector<Indice* > elementos = Indice<ManPage>::getElementos();
    for (i = 0; i < elementos.size(); i++) {
        resultado.push_back(this->IndiceParaIndicePrimario(elementos[i]));
    }
    return resultado;
}

IndicePrimario* IndicePrimario::getEsquerda() {
    return this->IndiceParaIndicePrimario(Indice<ManPage>::getEsquerda());
}

IndicePrimario* IndicePrimario::getDireita() {
    return this->IndiceParaIndicePrimario(Indice<ManPage>::getDireita());
}

IndicePrimario* IndicePrimario::inserir(const ManPage& dado, IndicePrimario* arv) {
    return this->IndiceParaIndicePrimario(Indice<ManPage>::inserir(dado, arv));
}

IndicePrimario* IndicePrimario::remover(IndicePrimario* arv, const ManPage& dado) {
    return this->IndiceParaIndicePrimario(Indice<ManPage>::remover(arv, dado));
}

IndicePrimario* IndicePrimario::minimo(IndicePrimario* nodo) {
    return this->IndiceParaIndicePrimario(Indice<ManPage>::minimo(nodo));
}

/** Métodos IndicePrimario */

IndicePrimario* IndicePrimario::pegaNovoNo(const ManPage& dado) {
	return new IndicePrimario(dado);
}

IndicePrimario* IndicePrimario::IndiceParaIndicePrimario(Indice<ManPage> *avl) {
	IndicePrimario *raiz = static_cast<IndicePrimario*>(avl);
    if (raiz != NULL) {
        raiz->esquerda = this->IndiceParaIndicePrimario(avl->getEsquerda());
        raiz->direita = this->IndiceParaIndicePrimario(avl->getDireita());
    }
    return raiz;
}

ListaDupla<ManPage > IndicePrimario::breadth_first()  {
	return Indice<ManPage>::breadth_first();
}

#endif	