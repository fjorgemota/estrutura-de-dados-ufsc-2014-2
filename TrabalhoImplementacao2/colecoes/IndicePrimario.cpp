#ifndef INDICE_PRIMARIO_CPP
#define INDICE_PRIMARIO_CPP

#include "IndicePrimario.hpp"
#include "../util/FilaEnc.hpp"
#include "../util/NoAVL.hpp"
#include "../util/ListaDupla.hpp"
#include <stdio.h>
IndicePrimario::IndicePrimario(const int& dado) : NoAVL(dado) {}

ListaDupla<int > IndicePrimario::breadth_first()  {
	FilaEnc<NoAVL<int>* > *itens = new FilaEnc<NoAVL<int>* >();
	ListaDupla<int > *man_pages = new ListaDupla<int >();
	itens->inclui(this);
	while(itens->filaVazia() == false) {
		NoAVL<int > *man_page = itens->retira();
		printf("Processando nodo %d\n", *(man_page->getDado()));
		if (man_page->getEsquerda() != NULL) {
			printf("Incluindo nó à esquerda\n");
			itens->inclui(man_page->getEsquerda());
		}
		if (man_page->getDireita() != NULL) {
			printf("Incluindo nó à direita\n");
			itens->inclui(man_page->getDireita());
		}
		man_pages->adicionaDuplo(*(man_page->getDado()));
	}
	return *man_pages;
}

#endif