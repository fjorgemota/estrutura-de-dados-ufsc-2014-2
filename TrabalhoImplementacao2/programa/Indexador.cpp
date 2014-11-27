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

Indexador::Indexador(RemovedorLexico *removedor) {
	this->indicePrimario = NULL;
	this->indiceSecundario = NULL;
	this->removedor = removedor;
}

string* Indexador::purifica(string *nome) {
	unsigned int posBarra = nome->find_last_of('/');
	if (posBarra != string::npos) {
		string *nomeSemBarra = new string(nome->substr(posBarra + 1));
		nome = nomeSemBarra;
	}
	int pos = nome->size()-4;
	if (nome->substr(pos) == string(".txt")) {
		string *nomeSemExtensao = new string(nome->substr(0, pos));
		return nomeSemExtensao;
	}
	return nome;
}

string* Indexador::leConteudo(string *nome) {
	struct stat propriedades;
	if (stat(nome->c_str(), &propriedades) == -1) {
		return NULL;
	}
	ifstream *input = new ifstream(nome->c_str());
	if(input == NULL) {
		return NULL;
	}
	char *conteudo = new char[propriedades.st_size];
	input->read(conteudo, propriedades.st_size);
	input->close();
	string *resultado = new string(conteudo);
	delete input;
	delete conteudo;
	return resultado;
}


void Indexador::indexaArquivo(string *nome) {
	ManPage *manpage = new ManPage();
	manpage->comando = this->purifica(nome);
	manpage->conteudo = this->leConteudo(nome);
	if (this->indicePrimario == NULL) {
		this->indicePrimario = new IndicePrimario(*manpage);
	} else {
		this->indicePrimario = this->indicePrimario->inserir(*manpage, this->indicePrimario);
	}
	ListaDupla<string> *palavras = this->removedor->separa_em_palavras(*(manpage->conteudo));
	palavras = this->removedor->remove_conectivos(palavras);
	string *palavrasVetor = palavras->paraVetor();
	int l = palavras->verUltimo();
	for (int i = 0; i <= l; i++) {
		Word *palavra  = new Word();
		string palavraString = palavrasVetor[i];
		palavra->word = new string(palavraString);

		if (this->indiceSecundario == NULL) {
			palavra->comandos = new ListaDupla<string* >();
			palavra->comandos->adicionaNoInicioDuplo(manpage->comando);
			this->indiceSecundario = new IndiceSecundario(*palavra);
			continue;
		}
		Word *palavraResultado;
		try {
			palavraResultado = this->indiceSecundario->busca(*palavra, this->indiceSecundario);
			if (!palavraResultado->comandos->contemDuplo(manpage->comando)) {
				palavraResultado->comandos->adicionaNoInicioDuplo(manpage->comando);
			}
			delete palavra;
		} catch(const char *e){
			palavra->comandos = new ListaDupla<string* >();
			palavra->comandos->adicionaNoInicioDuplo(manpage->comando);
			this->indiceSecundario = this->indiceSecundario->inserir(
				*palavra,
				this->indiceSecundario
			);
		}
	}
	delete palavras;
}

void Indexador::salvaIndicePrimario(string *nome) {
	if (this->indicePrimario == NULL) {
		return;
	}
	ofstream *output = new ofstream(nome->c_str(),
		ios::out //abre arquivo para escrita.
		//ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
		| ios::binary //arquivo binario.
	);
	SerializadorManPage *serializador = new SerializadorManPage();
	ListaDupla<ManPage* > *man_pages = this->indicePrimario->reversed_breadth_first();
	int i, l;
	l = man_pages->verUltimo();
	ManPage **vetor = man_pages->paraVetor();
	ManPage *arr = new ManPage[l+1];
	for(i = 0; i <= l; i++) {
		arr[i] = *(vetor[l-i]);
	}
	serializador->escreve(output, arr, l);
	output->close();
	delete arr;
	delete vetor;
	delete serializador;
	delete output;
}

void Indexador::salvaIndiceSecundario(string *nome) {
	if (this->indiceSecundario == NULL) {
		return;
	}
	ofstream *output = new ofstream(nome->c_str(),
		ios::out //abre arquivo para escrita.
		//ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
		| ios::binary //arquivo binario.
	);
	SerializadorWord *serializador = new SerializadorWord();
	ListaDupla<Word* > *palavras = this->indiceSecundario->reversed_breadth_first();
	int i, l;
	l = palavras->verUltimo();
	Word **vetor = palavras->paraVetor();
	Word *arr = new Word[l+1];
	for(i = 0; i <= l; i++) {
		arr[i] = *(vetor[l-i]);
	}
	serializador->escreve(output, arr, l);
	output->close();
	delete arr;
	delete vetor;
	delete serializador;
	delete output;
}


#endif /** INDEXADOR_CPP */