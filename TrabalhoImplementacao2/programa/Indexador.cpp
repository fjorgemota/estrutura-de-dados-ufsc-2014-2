#ifndef INDEXADOR_CPP
#define INDEXADOR_CPP

#include "Indexador.hpp"
#include "../modelos/ManPage.hpp"
#include "../modelos/Word.hpp"
#include "../util/ListaDupla.hpp"
#include "../serializador/SerializadorManPage.hpp"
#include "../serializador/SerializadorWord.hpp"
#include <string> //strstr
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

char* Indexador::retiraExtensao(char *nome) {
	string nomeString(nome);
	if (nomeString.substr(nomeString.size()-4) == string(".txt")) {
		return (char*) nomeString.substr(0, nomeString.size()-4).c_str();
	}
	return nome;
}

string* Indexador::leConteudo(char *nome) {
	struct stat propriedades;
	if (stat(nome, &propriedades) == -1) {
		return NULL;
	}
	ifstream *input = new ifstream(nome);
	if(input == NULL) {
		return NULL;
	}
	char *conteudo = new char[propriedades.st_size];
	input->read(conteudo, propriedades.st_size);
	return new string(conteudo);
}

Indexador::Indexador(RemovedorLexico *removedor) {
	this->indicePrimario = NULL;
	this->indiceSecundario = NULL;
	this->removedor = removedor;
}

void Indexador::indexaArquivo(char *nome) {
	char *comando = this->retiraExtensao(nome);
	ManPage *manpage = new ManPage();
	manpage->comando = new string(comando);
	manpage->conteudo = this->leConteudo(nome);
	if (this->indicePrimario == NULL) {
		this->indicePrimario = new IndicePrimario(*manpage);
	} else {
		this->indicePrimario = this->indicePrimario->inserir(*manpage, this->indicePrimario);
	}
	ListaDupla<string> *palavras = this->removedor->separa_em_palavras(*(manpage->conteudo));
	palavras = this->removedor->remove_conectivos(palavras);
	for (int i = 0; i <= palavras->verUltimo(); i++) {
		Word *palavra;
		string palavraString = palavras->mostra(i);
		if (this->indiceSecundario == NULL) {
			palavra = new Word();
			palavra->word = &palavraString;
			palavra->comandos = new ListaDupla<string* >();
			this->indiceSecundario = new IndiceSecundario(*palavra);
		}
		bool localizado;
		try {
			palavra = this->indiceSecundario->busca(*palavra, this->indiceSecundario);
			localizado = true;
		} catch(char *e){
			palavra = new Word();
			palavra->word = &palavraString;
			palavra->comandos = new ListaDupla<string* >();
			localizado = false;
		}
		if (palavra->comandos == NULL) {}
		palavra->comandos->adicionaDuplo(new string(comando));
		if (!localizado) {
			this->indiceSecundario = this->indiceSecundario->inserir(
				*palavra,
				this->indiceSecundario
			);
		}
	}
}

void Indexador::salvaIndicePrimario(char *nome) {
	if (this->indicePrimario == NULL) {
		return;
	}
	ofstream *output = new ofstream(nome,
		ios::out //abre arquivo para escrita.
		//ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
		| ios::binary //arquivo binario.
	);
	SerializadorManPage *serializador = new SerializadorManPage();
	Serializador<int> *serializadorInt = new Serializador<int>();
	ListaDupla<ManPage > man_pages = this->indicePrimario->breadth_first();
	serializadorInt->escreve(output, new int(man_pages.verUltimo()), 1);
	for(int i = 0; i <= man_pages.verUltimo(); i++) {
		ManPage man_page = man_pages.mostra(i);
		serializador->escreve(output, &man_page, 1);
	}
	output->close();
}

void Indexador::salvaIndiceSecundario(char *nome) {
	if (this->indiceSecundario == NULL) {
		return;
	}
	ofstream *output = new ofstream(nome,
		ios::out //abre arquivo para escrita.
		//ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
		| ios::binary //arquivo binario.
	);
	SerializadorWord *serializador = new SerializadorWord();
	Serializador<int> *serializadorInt = new Serializador<int>();
	ListaDupla<Word > palavras = this->indiceSecundario->breadth_first();
	serializadorInt->escreve(output, new int(palavras.verUltimo()), 1);
	for(int i = 0; i <= palavras.verUltimo(); i++) {
		Word palavra = palavras.mostra(i);
		serializador->escreve(output, &palavra, 1);
	}
	output->close();
}


#endif /** INDEXADOR_CPP */