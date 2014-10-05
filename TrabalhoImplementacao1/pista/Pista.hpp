// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_HPP
#define PISTA_HPP
#include "../util/FilaEnc.cpp"
#include "../carro/Carro.cpp"

class Pista: private FilaEnc<Carro*> {
 private:
    int tamanhoMaximo;  //!< O tamanho maximo da pista, definida em metros
    int velocidade;  //!< A velocidade limite que a pista possui, os carros andarao nesta velocidade
    int tamanhoDisponivel;   //!< O tamanho que esta disponivel, ou seja, 
    						// definira se ela suportara mais carros

 public:
    Pista(int tamanhoMaximo, int velocidade);
    int pegaTamanhoMaximo();
    int pegaVelocidade();
    bool adiciona(Carro* carro);
};

#endif /* PISTA_HPP */
