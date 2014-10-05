// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_HPP
#define PISTA_HPP
#include "../util/FilaEnc.cpp"
#include "../carro/Carro.cpp"
#include "ListaDupla.hpp"

class Pista: private FilaEnc<Carro*> {
 private:
    int tamanhoMaximo;  //!< O tamanho maximo da pista, definida em metros
    int velocidade;  //!< A velocidade limite que a pista possui, os carros andarao nesta velocidade
    int tamanhoDisponivel;   //!< O tamanho que esta disponivel, ou seja, 
    						// definira se ela suportara mais carros
    ListaDupla<Pista> pistasSaida;
    FilaEnc<Carro*> carrosbloqueados;

 public:
    Pista(int tamanhoMaximo, int velocidade, ListaDupla<T> pistas);
    int pegaTamanhoMaximo();
    int pegaVelocidade();
    bool adiciona(Carro* carro);
    Carro sairDaPista();
    void transfere();
    Pista sorteiaPista();
    bool estaCheia(Carro* carro);
};

#endif /* PISTA_HPP */
