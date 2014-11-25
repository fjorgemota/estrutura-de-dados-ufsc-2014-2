#ifndef SERIALIZADOR_MAN_PAGE_CPP
#define SERIALIZADOR_MAN_PAGE_CPP

#include "Serializador.hpp"
#include "SerializadorManPage.hpp"
#include "../modelos/ManPage.hpp"
#include "../util/ListaDupla.hpp"
#include <string>

using std::string;

ManPage* SerializadorManPage::le(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();

	char *comando = serializadorChar->le(arquivo);
	char *conteudo = serializadorChar->le(arquivo);
	ManPage *resultado = new ManPage();
	resultado->comando = new string(comando);
	resultado->conteudo = new string(conteudo);
	return resultado;
}

void SerializadorManPage::escreve(ofstream *arquivo, ManPage* dado, int tamanho) {
	Serializador<char> *serializadorChar = new Serializador<char>();

	for (int i=0; i<tamanho; i++) {
		ManPage manpage = dado[i];
		serializadorChar->escreve(arquivo, (char*) manpage.comando->c_str(), manpage.comando->size());
		serializadorChar->escreve(arquivo, (char*) manpage.conteudo->c_str(), manpage.conteudo->size());
	}
	delete serializadorChar;
}


void SerializadorManPage::proximaPosicao(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	serializadorChar->proximaPosicao(arquivo);
	this->pulaConteudo(arquivo);
	delete serializadorChar;
}

string* SerializadorManPage::leComando(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	char *comando = serializadorChar->le(arquivo);
	string *palavraString = new string(comando);
	delete serializadorChar;
	return palavraString;
}

void SerializadorManPage::pulaConteudo(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	serializadorChar->proximaPosicao(arquivo);
	delete serializadorChar;
}

#endif /** SERIALIZADOR_MAN_PAGE_CPP */