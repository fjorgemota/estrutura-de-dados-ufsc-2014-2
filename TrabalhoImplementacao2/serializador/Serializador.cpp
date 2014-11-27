#ifndef SERIALIZADOR_CPP
#define SERIALIZADOR_CPP
#include "Serializador.hpp"

template <typename T>
T* Serializador<T>::le(ifstream *arquivo) {
	int tamanho;
	arquivo->read((char*)&tamanho, sizeof(int));
	T* dados = new T[tamanho+1];
	arquivo->read((char*) dados, sizeof(T)*(tamanho+1));
	return dados;
}

template <typename T>
void Serializador<T>::escreve(ofstream *arquivo, T* dado, int tamanho) {
	arquivo->write((char*)&tamanho, sizeof(int));
	arquivo->write((char*) dado, sizeof(T)*(tamanho+1));
}

template <typename T>
void Serializador<T>::proximaPosicao(ifstream *arquivo) {
	int tamanho;
	
	arquivo->read((char*) &tamanho, sizeof(int));
	arquivo->seekg((sizeof(T)*(tamanho+1)) + arquivo->tellg(), arquivo->beg);
}

#endif /* SERIALIZADOR_CPP */