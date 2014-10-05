// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ROAD_HPP
#define ROAD_HPP
#include "util/FilaEnc.cpp"
#include "Carro/Carro.cpp"

class Pista: private FilaEnc<Carro*> {
 private:
    int tamanhoMaximo;
    int velocidade;

 public:
    Pista(int tamanhoMaximo, int velocidade);
    int pegaTamanhoMaximo();
    int pegaVelocidade();
};

#endif /* ROAD_HPP */
