// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_SUMIDOURA_HPP
#define PISTA_SUMIDOURA_HPP
#include "Pista.cpp"

class PistaSumidoura: public Pista {
 protected:
    virtual void agendaCarro();

 public:
    PistaSumidoura(Relogio *relogio, Semaforo *semaforo, int tamanho,
    int velocidade);
}

#endif /* PISTA_SUMIDOURA_HPP */
