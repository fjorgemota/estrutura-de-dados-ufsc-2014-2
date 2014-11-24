#ifndef SERIALIZADOR_CPP
#define SERIALIZADOR_CPP
#include "Serializador.hpp"

template <typename T>
T* Serializador<T>::le(ifstream *arquivo) {
	int tamanho, contador;
	arquivo->read((char*)&tamanho, sizeof(int));
	T* dados = new T[tamanho];
	for (contador = 0; contador < tamanho; contador++) {
		arquivo->read((char*) &dados[contador], sizeof(T));
		//printf("Lendo letra %c\n", dados[contador] );
	}
	//dados[contador] = '\0';
	return dados;
}

template <typename T>
void Serializador<T>::escreve(ofstream *arquivo, T* dado, int tamanho) {
	int contador;
	arquivo->write((char*)&tamanho, sizeof(int));
	for (contador = 0; contador < tamanho; contador++) {
		arquivo->write((char*)&dado[contador], sizeof(T));
		//printf("Escrevendo letra %c\n", dado[contador] );
	}
}

template <typename T>
int Serializador<T>::proximaPosicao(ifstream *arquivo) {
	int tamanho;
	
	int posicao_atual = arquivo->tellg();
	arquivo->read((char*)tamanho, sizeof(int));
	int proxima_posicao = sizeof(int) + (tamanho*sizeof(T)) + posicao_atual;
	arquivo->seekg(posicao_atual, arquivo->beg);
	
	return proxima_posicao;
}

#endif /* SERIALIZADOR_CPP */