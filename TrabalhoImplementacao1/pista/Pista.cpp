// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_CPP
#define PISTA_CPP
#include "Pista.hpp"
#include "../util/FilaEnc.cpp"

Pista::Pista(int tamanho, int velocidade) {
    this->tamanho = tamanho;
    this->velocidade = velocidade;
    this->tamanhoDisponivel = velocidade;
}

int Pista::pegaTamanho() {
    return this->tamanho;
}

int Pista::pegaVelocidade() {
    return this->velocidade;
}

bool Pista::adiciona(Carro* carro) {
	int temporario = this->tamanhoDisponivel - car->pegaTamanho();
	if (temporario < 0) {
		return false;
	} else {
		this->inclui(carro);
		this->tamanhoDisponivel = temporario;
		return true;
	}
}

#endif /* PISTA_CPP */
