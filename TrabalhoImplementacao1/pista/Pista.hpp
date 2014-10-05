// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_HPP
#define PISTA_HPP
#include "../util/FilaEnc.cpp"
#include "../carro/Carro.cpp"

class Pista: private FilaEnc<Carro*> {
 private:
    int tamanhoMaximo;
    int velocidade;
    int tamanhoDisponivel;

 public:
    Pista(int tamanhoMaximo, int velocidade);
    int pegaTamanhoMaximo();
    int pegaVelocidade();
    bool adiciona(Carro* carro);
};

#endif /* PISTA_HPP */
