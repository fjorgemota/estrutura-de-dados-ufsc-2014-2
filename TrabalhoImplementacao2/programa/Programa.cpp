#ifndef PROGRAMA_CPP
#define PROGRAMA_CPP

#include "Programa.hpp"
#include "Buscador.hpp"
#include "Indexador.hpp"
#include "../util/RemovedorLexico.hpp"
#include "../modelos/ManPage.hpp"
#include "../modelos/Word.hpp"
#include "../colecoes/Resultado.hpp"
#include "../util/ListaDupla.hpp"
#include <string>

using std::string;

Programa::Programa(string *indicePrimario, string *indiceSecundario) {
	this->indicePrimario = indicePrimario;
	this->indiceSecundario = indiceSecundario;
	this->removedor = new RemovedorLexico();
}

int Programa::executa(int argc, char **argv) {
	if (argc <= 2) {
		printf("./main <action> <arguments>\n");
		printf("Action can be ONE of:\n");
		printf("- index - Accepts as arguments the filenames of the manpages to index\n");
		printf("- search-primary-index - Accepts as unique argument the command to search in the primary index\n");
		printf("- search-secondary-index - Accepts as arguments the words to search in the secondary index\n");
		return 1;
	}
	string acao(argv[1]);
	if (acao == string("index")) {
		ListaDupla<string* > *arquivos = new ListaDupla<string* >();
		for (int i = 2; i < argc; i++) {
			arquivos->adicionaNoInicioDuplo(new string(argv[i]));
		}
		this->indexar(arquivos);
	} else if (acao == string("search-primary-index")) {
		if (argc > 3) {
			printf("You can search only one term using primary index\n");
			return 2;
		}
		string keyword = string(argv[2]);
		keyword = this->removedor->removeCaracteresEspeciais(keyword);
		ManPage* resultado = this->procurarIndicePrimario(new string(keyword));
		if (resultado == NULL) {
			printf("No result found for '%s'\n", argv[2]);
			return 0;
		}
		printf("Found result for the search '%s'\n",argv[2]);
		printf("Command: %s\n", resultado->comando->c_str());
		printf("Content: %s\n", resultado->conteudo->c_str());
	} else if (acao == string("search-secondary-index")) {
		ListaDupla<string* > *arquivos = new ListaDupla<string* >();
		for (int i = 2; i < argc; i++) {
			string keyword = string(argv[i]);
			keyword = this->removedor->removeCaracteresEspeciais(keyword);
			arquivos->adicionaNoInicioDuplo(new string(keyword));
		}
		Resultado<string> *resultados = this->procurarIndiceSecundario(arquivos);
		if (resultados->listaVazia()) {
			printf("No result found for your search\n");
			return 0;
		}
		int l = resultados->verUltimo();
		printf("Found %d results that match your search:\n", l+1);
		for(int i=0; i <= l; i++) {
			printf("- %s\n", resultados->mostra(i).c_str());
		}
	}
	return 0;
}

void Programa::indexar(ListaDupla<string* > *arquivos) {
	Indexador *indexer = new Indexador(this->removedor);
	for(int i=0; i <= arquivos->verUltimo(); i++) {
		string *arquivo = arquivos->mostra(i);
		printf("- Indexing %s\n", arquivo->c_str());
		indexer->indexaArquivo(arquivo);	
	} 
	printf("Saving primary index\n");
	indexer->salvaIndicePrimario(this->indicePrimario);
	printf("Saving secondary index\n");
	indexer->salvaIndiceSecundario(this->indiceSecundario);
}

ManPage* Programa::procurarIndicePrimario(string *termo) {
	Buscador *buscador = new Buscador(this->indicePrimario, this->indiceSecundario);
	ManPage* resultado = buscador->buscaNoIndicePrimario(termo);
	delete buscador;
	return resultado;
}

Resultado<string>* Programa::procurarIndiceSecundario(ListaDupla<string* > *termos) {
	Buscador *buscador = new Buscador(this->indicePrimario, this->indiceSecundario);
	Resultado<string>* resultados = buscador->buscaNoIndiceSecundario(termos);
	delete buscador;
	return resultados;
}
#endif /** PROGRAMA_CPP */