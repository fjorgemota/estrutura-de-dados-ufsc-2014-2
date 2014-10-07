// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_SUMIDOURA_HPP
#define PISTA_SUMIDOURA_HPP
#include "Pista.cpp"

class PistaSumidoura: public Pista {
 protected:
    virtual void agendaNovoCarro();

 public:
    PistaSumidoura(Relogio *relogio, int tamanho, int velocidade);
}

#endif /* PISTA_SUMIDOURA_HPP */
