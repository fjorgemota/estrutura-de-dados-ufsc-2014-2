#ifndef SERIALIZADOR_CPP
#define SERIALIZADOR_CPP
#include "Serializador.hpp"

template <typename T>
T* Serializador<T>::le(ifstream *arquivo) {
	int tamanho;
	arquivo->read((char*)&tamanho, sizeof(int));
	T* dados = new T[tamanho];
	arquivo->read((char*) &dados, sizeof(T)*tamanho);
	return dados;
}

template <typename T>
void Serializador<T>::escreve(ofstream *arquivo, T* dado, int tamanho) {
	arquivo->write((char*)&tamanho, sizeof(int));
	arquivo->write((char*)&dado, sizeof(T)*tamanho);
}

template <typename T>
void Serializador<T>::proximaPosicao(ifstream *arquivo) {
	int tamanho;
	
	int posicao_atual = arquivo->tellg();
	arquivo->read((char*) &tamanho, sizeof(int));
	int proxima_posicao = (tamanho*sizeof(T)) + posicao_atual;
	arquivo->seekg(proxima_posicao, arquivo->beg);
}

#endif /* SERIALIZADOR_CPP */