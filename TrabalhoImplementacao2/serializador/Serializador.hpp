#ifndef SERIALIZADOR_HPP
#define SERIALIZADOR_HPP

#include "../util/ListaDupla.hpp"
#include <iostream> //cout
#include <fstream> //fstream

using std::ofstream;
using std::ifstream;

template<typename T>
class Serializador {
 public:
 	virtual T* le(ifstream *arquivo);
 	virtual void escreve(ofstream *arquivo, T* dado, int tamanho);
 	virtual void proximaPosicao(ifstream *arquivo);
};

#include "Serializador.cpp"

#endif /*SERIALIZADOR_HPP*/
