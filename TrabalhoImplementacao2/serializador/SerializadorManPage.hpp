#ifndef SERIALIZADOR_MAN_PAGE_HPP
#define SERIALIZADOR_MAN_PAGE_HPP

#include "../modelos/ManPage.hpp"
#include "Serializador.hpp"
#include <iostream> //cout
#include <fstream> //fstream
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;

class SerializadorManPage {
 public:
 	ManPage* le(ifstream *arquivo);
 	void escreve(ofstream *arquivo, ManPage* dado, int tamanho);
 	void proximaPosicao(ifstream *arquivo);
 	string* leComando(ifstream *arquivo);
 	void pulaConteudo(ifstream *arquivo);
};

#include "SerializadorManPage.cpp"

#endif /** SERIALIZADOR_MAN_PAGE_HPP */