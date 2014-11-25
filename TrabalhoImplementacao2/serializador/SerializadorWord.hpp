#ifndef SERIALIZADOR_WORD_HPP
#define SERIALIZADOR_WORD_HPP

#include "../modelos/Word.hpp"
#include <iostream> //cout
#include <fstream> //fstream
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;

class SerializadorWord {
 public:
 	Word* le(ifstream *arquivo);
 	void escreve(ofstream *arquivo, Word* dado, int tamanho);
 	void proximaPosicao(ifstream *arquivo);
 	string* leWord(ifstream *arquivo);
 	void pulaComandos(ifstream *arquivo);
};

#include "SerializadorWord.cpp"

#endif /** SERIALIZADOR_WORD_HPP */