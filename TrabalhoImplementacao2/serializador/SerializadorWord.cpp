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

SerializadorWord::SerializadorWord() {
	this->serializadorChar = new Serializador<char>();
	this->serializadorInt = new Serializador<int>();	
}

Word* SerializadorWord::le(ifstream *arquivo) {
	int i, i2;
	int tamanho = *(this->serializadorInt->le(arquivo));
	Word *resultado = new Word[tamanho];
	for(i=0; i<tamanho; i++) {
		char *word = this->serializadorChar->le(arquivo);
		int nTitulos = *(this->serializadorInt->le(arquivo));
		ListaDupla<string* > *comandos = new ListaDupla<string* >(); 
		for(i2=0; i2 <= nTitulos; i2++) {
			char *comando = this->serializadorChar->le(arquivo);
			comandos->adicionaDuplo(new string(comando));
		}
		resultado[i].word = new string(word);
		resultado[i].comandos = comandos;
	}

	return resultado;
}

void SerializadorWord::escreve(ofstream *arquivo, Word* dado, int tamanho) {
	this->serializadorInt->escreve(arquivo, &tamanho, 1);
	for (int i=0; i<tamanho; i++) {
		Word palavra = dado[i];
		this->serializadorChar->escreve(arquivo, (char *)palavra.word->c_str(), palavra.word->size());
		int l = palavra.comandos->verUltimo();
		this->serializadorInt->escreve(arquivo, new int(l), 1);
		string **comandos = palavra.comandos->paraVetor();
		for(int i2=0; i2 <= l; i2++) {
			string *comando = comandos[i2];
			this->serializadorChar->escreve(arquivo, (char *)comando->c_str(), comando->size());
		}
	}
}


void SerializadorWord::proximaPosicao(ifstream *arquivo) {
	this->serializadorChar->proximaPosicao(arquivo);
	this->pulaComandos(arquivo);
}

string* SerializadorWord::leWord(ifstream *arquivo) {
	char *palavra = this->serializadorChar->le(arquivo);
	string *palavraString = new string(palavra);
	return palavraString;
}

void SerializadorWord::pulaComandos(ifstream *arquivo) {
	int tamanho = *(this->serializadorInt->le(arquivo));
	int i;
	for (i=0; i <= tamanho; i++) {
		this->serializadorChar->proximaPosicao(arquivo);
	}
}

ListaDupla<string>* SerializadorWord::leComandos(ifstream *arquivo) {
	int tamanho, i;
	tamanho = *(this->serializadorInt->le(arquivo));
	ListaDupla<string>* comandos = new ListaDupla<string>();
	for (i = 0; i <= tamanho; i++) {
		comandos->adicionaNoInicioDuplo(string(this->serializadorChar->le(arquivo)));
	}
	return comandos;
}

#endif /** SERIALIZADOR_WORD_CPP */