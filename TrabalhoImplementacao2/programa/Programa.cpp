#ifndef PROGRAMA_CPP
#define PROGRAMA_CPP

#include "Programa.hpp"
#include "Indexador.hpp"
#include "../util/ListaDupla.hpp"
#include <string>

using std::string;

Programa::Programa(string indicePrimario, string indiceSecundario) {
	this->indicePrimario = indicePrimario;
	this->indiceSecundario = indiceSecundario;
}

void Programa::executa(int argc, char **argv) {
	if (argv <= 2) {
		printf("./main <action> <arguments>\n");
		return 1;
	}
	string acao(argv[1]);
	if (acao == string("index")) {
		ListaDupla<string> *arquivos = new ListaDupla<string>();
		for (int i = 2; i < argc; i++) {
			arquivos->adicionaDuplo(string(argv[i]));
		}
		this->indexar(arquivos);
	} else if (acao == string("search-primary-index")) {
		if (argc > 2) {
			printf("You can search only one term using primary index");
			return 2;
		}
		this->procurarIndicePrimario(new string(argv[2]));
	} else if (acao == string("search-secondary-index")) {
		ListaDupla<string* > *arquivos = new ListaDupla<string* >();
		for (int i = 2; i < argc; i++) {
			arquivos->adicionaDuplo(new string(argv[i]));
		}
		this->procurarIndiceSecundario(arquivos);
	}
	return 0;
}

void Programa::indexar(ListaDupla<string* > *arquivos) {
	RemovedorLexico *removedor = new RemovedorLexico();
	Indexador *indexer = new Indexador(removedor);
	for(int i=1; i <= arquivos->verUltimo(); i++) {
		printf("\rIndexando arquivo %d de %d", i-1, argc-2);
		indexer->indexaArquivo(arquivos->mostra(i));	
	} 
	printf("\n");
	indexer->salvaIndicePrimario(this->indicePrimario);
	indexer->salvaIndiceSecundario(this->indiceSecundario);
}

Resultado<ManPage>* Programa::procurarIndicePrimario(string *termo) {
	Buscador *buscador = new Buscador(this->indicePrimario, this->indiceSecundario);
	Resultado<ManPage>* resultados = buscador->buscaNoIndicePrimario(termo);
	delete buscador;
	return resultados;
}

void Programa::procurarIndiceSecundario(ListaDupla<string* > *termos) {
	Buscador *buscador = new Buscador(this->indicePrimario, this->indiceSecundario);
	Resultado<ManPage>* resultados = buscador->buscaNoIndiceSecundario(termos);
	delete buscador;
	return resultados;
}
#endif /** PROGRAMA_CPP */