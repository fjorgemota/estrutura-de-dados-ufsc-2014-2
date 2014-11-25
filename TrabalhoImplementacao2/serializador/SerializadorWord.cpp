#ifndef SERIALIZADOR_WORD_CPP
#define SERIALIZADOR_WORD_CPP

#include "Serializador.hpp"
#include "SerializadorWord.hpp"
#include "../modelos/Word.hpp"
#include "../util/ListaDupla.hpp"
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;

Word* SerializadorWord::le(ifstream *arquivo) {
	int i;
	Serializador<char> *serializadorChar = new Serializador<char>();
	Serializador<int> *serializadorInt = new Serializador<int>();

	char *word = serializadorChar->le(arquivo);
	int nTitulos = *(serializadorInt->le(arquivo));
	ListaDupla<string* > *comandos = new ListaDupla<string* >(); 
	Word *resultado = new Word();
	for(i=0; i <= nTitulos; i++) {
		char *comando = serializadorChar->le(arquivo);
		comandos->adicionaDuplo(new string(comando));
	}
	resultado->word = new string(word);
	resultado->comandos = comandos;

	return resultado;
}

void SerializadorWord::escreve(ofstream *arquivo, Word* dado, int tamanho) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	Serializador<int> *serializadorInt = new Serializador<int>();

	for (int i=0; i<tamanho; i++) {
		Word palavra = dado[i];
		serializadorChar->escreve(arquivo, (char *)palavra.word->c_str(), palavra.word->size());
		serializadorInt->escreve(arquivo, new int(palavra.comandos->verUltimo()), 1);
		for(int i2=0; i2 <= palavra.comandos->verUltimo(); i2++) {
			string *comando = palavra.comandos->mostra(i2);
			serializadorChar->escreve(arquivo, (char *)comando->c_str(), comando->size());
		}
	}
}


void SerializadorWord::proximaPosicao(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	serializadorChar->proximaPosicao(arquivo);
	this->pulaComandos(arquivo);
}

string* SerializadorWord::leWord(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	char *palavra = serializadorChar->le(arquivo);
	string *palavraString = new string(palavra);
	return palavraString;
}

void SerializadorWord::pulaComandos(ifstream *arquivo) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	Serializador<int> *serializadorInt = new Serializador<int>();
	int tamanho = *(serializadorInt->le(arquivo));
	while(tamanho--) {
		serializadorChar->proximaPosicao(arquivo);
	}
}

ListaDupla<string>* SerializadorWord::leComandos(ifstream *arquivo) {
	int tamanho, a;
	Serializador<int> *serializadorInt = new Serializador<int>();
	Serializador<char> *serializadorChar = new Serializador<char>();
	tamanho = *(serializadorInt->le(arquivo));
	ListaDupla<string>* comandos = new ListaDupla<string>();
	for (a = 0; a <= tamanho; a++) {
		comandos->adicionaNoInicioDuplo(string(serializadorChar->le(arquivo)));
	}
	return comandos;
}

#endif /** SERIALIZADOR_WORD_CPP */