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
	Serializador<int> *serializadorInt = new Serializador<int>();

	int tamanho = *(serializadorInt->le(arquivo));

	ManPage *resultado = new ManPage[tamanho];
	for(int i=0; i <= tamanho; i++) {
		char *comando = serializadorChar->le(arquivo);
		char *conteudo = serializadorChar->le(arquivo);
		resultado[i].comando = new string(comando);
		resultado[i].conteudo = new string(conteudo);
	}
	return resultado;
}

void SerializadorManPage::escreve(ofstream *arquivo, ManPage* dado, int tamanho) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	Serializador<int> *serializadorInt = new Serializador<int>();

	serializadorInt->escreve(arquivo, &tamanho, 1);

	for (int i=0; i <= tamanho; i++) {
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

string* SerializadorManPage::leConteudo(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	char *conteudo = serializadorChar->le(arquivo);
	string *palavra = new string(conteudo);
	delete serializadorChar;
	return palavra;
}

#endif /** SERIALIZADOR_MAN_PAGE_CPP */