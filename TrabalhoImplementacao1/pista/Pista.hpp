// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_HPP
#define PISTA_HPP
#include "../util/FilaEnc.cpp"
#include "../carro/Carro.cpp"

class Pista: private FilaEnc<Carro*> {
 private:
    int tamanhoMaximo;
    int velocidade;

 public:
    Pista(int tamanhoMaximo, int velocidade);
    int pegaTamanhoMaximo();
    int pegaVelocidade();
};

#endif /* PISTA_HPP */
