#ifndef SERIALIZADOR_CPP
#define SERIALIZADOR_CPP
#include "Serializador.hpp"

template <typename T>
T* Serializador<T>::le(ifstream *arquivo) {
	int tamanho, contador;
	arquivo->read((char*)&tamanho, sizeof(int));
	T* dados = new T[tamanho];
	for (contador = 0; contador <= tamanho; contador++) {
		arquivo->read((char*) &dados[contador], sizeof(T));
	}
	return dados;
}

template <typename T>
void Serializador<T>::escreve(ofstream *arquivo, T* dado, int tamanho) {
	int contador;
	arquivo->write((char*)&tamanho, sizeof(int));
	for (contador = 0; contador <= tamanho; contador++) {
		arquivo->write((char*)&dado[contador], sizeof(T));
	}
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