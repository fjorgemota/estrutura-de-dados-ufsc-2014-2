#ifndef SERIALIZADOR_HPP
#define SERIALIZADOR_HPP
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include "../util/ListaDupla.hpp"

using std::ofstream;
using std::ifstream;

template<typename T>
class Serializador {
 public:
 	virtual T* le(ifstream *arquivo);
 	virtual void escreve(ofstream *arquivo, T* dado, int tamanho);
 	int proximaPosicao(ifstream *arquivo);
};

#include "Serializador.cpp"

#endif /*SERIALIZADOR_HPP*/
