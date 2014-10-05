// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_CPP
#define PISTA_CPP
#include "Pista.hpp"
#include "../util/FilaEnc.cpp"

Pista::Pista(int tamanho, int velocidade) : FilaEnc() {
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
	if (temporario > 0) {
		this->inclui(carro);
		this->tamanhoDisponivel = temporario;
		return true;
	} else {
		return false;
	}
}

#endif /* PISTA_CPP */
