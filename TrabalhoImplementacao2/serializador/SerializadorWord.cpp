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
	int i, i2;
	Serializador<char> *serializadorChar = new Serializador<char>();
	Serializador<int> *serializadorInt = new Serializador<int>();
	int tamanho = *(serializadorInt->le(arquivo));
	Word *resultado = new Word[tamanho];
	for(i=0; i<tamanho; i++) {
		char *word = serializadorChar->le(arquivo);
		int nTitulos = *(serializadorInt->le(arquivo));
		ListaDupla<string* > *comandos = new ListaDupla<string* >(); 
		for(i2=0; i2 <= nTitulos; i2++) {
			char *comando = serializadorChar->le(arquivo);
			comandos->adicionaDuplo(new string(comando));
		}
		resultado[i].word = new string(word);
		resultado[i].comandos = comandos;
	}

	return resultado;
}

void SerializadorWord::escreve(ofstream *arquivo, Word* dado, int tamanho) {
	Serializador<char> *serializadorChar = new Serializador<char>();
	Serializador<int> *serializadorInt = new Serializador<int>();
	serializadorInt->escreve(arquivo, &tamanho, 1);
	for (int i=0; i<tamanho; i++) {
		Word palavra = dado[i];
		serializadorChar->escreve(arquivo, (char *)palavra.word->c_str(), palavra.word->size());
		serializadorInt->escreve(arquivo, new int(palavra.comandos->verUltimo()), 1);
		int l = palavra.comandos->verUltimo();
		string **comandos = palavra.comandos->paraVetor();
		for(int i2=0; i2 <= l; i2++) {
			string *comando = comandos[i2];
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

#endif /** SERIALIZADOR_WORD_CPP */