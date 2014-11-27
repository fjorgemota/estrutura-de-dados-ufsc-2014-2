#ifndef SERIALIZADOR_MAN_PAGE_CPP
#define SERIALIZADOR_MAN_PAGE_CPP

#include "Serializador.hpp"
#include "SerializadorManPage.hpp"
#include "../modelos/ManPage.hpp"
#include "../util/ListaDupla.hpp"
#include <string>

using std::string;

SerializadorManPage::SerializadorManPage() {
	this->serializadorChar = new Serializador<char>();
	this->serializadorInt = new Serializador<int>();	
}

ManPage* SerializadorManPage::le(ifstream *arquivo) {

	int tamanho = *(this->serializadorInt->le(arquivo));

	ManPage *resultado = new ManPage[tamanho];
	for(int i=0; i <= tamanho; i++) {
		char *comando = this->serializadorChar->le(arquivo);
		char *conteudo = this->serializadorChar->le(arquivo);
		resultado[i].comando = new string(comando);
		resultado[i].conteudo = new string(conteudo);
	}
	return resultado;
}

void SerializadorManPage::escreve(ofstream *arquivo, ManPage* dado, int tamanho) {
	this->serializadorInt->escreve(arquivo, &tamanho, 1);

	for (int i=0; i <= tamanho; i++) {
		ManPage manpage = dado[i];
		this->serializadorChar->escreve(arquivo, (char*) manpage.comando->c_str(), manpage.comando->size());
		this->serializadorChar->escreve(arquivo, (char*) manpage.conteudo->c_str(), manpage.conteudo->size());
	}
}


void SerializadorManPage::proximaPosicao(ifstream *arquivo) {
	this->serializadorChar->proximaPosicao(arquivo);
	this->pulaConteudo(arquivo);
}

string* SerializadorManPage::leComando(ifstream *arquivo) {
	char *comando = this->serializadorChar->le(arquivo);
	string *palavraString = new string(comando);
	return palavraString;
}

void SerializadorManPage::pulaConteudo(ifstream *arquivo) {
	this->serializadorChar->proximaPosicao(arquivo);
}

string* SerializadorManPage::leConteudo(ifstream *arquivo) {
	char *conteudo = this->serializadorChar->le(arquivo);
	string *palavra = new string(conteudo);
	return palavra;
}

#endif /** SERIALIZADOR_MAN_PAGE_CPP */