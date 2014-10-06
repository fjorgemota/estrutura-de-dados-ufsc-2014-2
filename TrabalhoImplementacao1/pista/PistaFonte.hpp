// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_FONTE_HPP
#define PISTA_FONTE_HPP
#include "Pista.cpp"

class PistaFonte: public Pista {
 public:
    PistaFonte(Relogio *relogio, Semaforo *semaforo, int tamanho,
        int velocidade, ListaDupla<T> pistas);
};

#endif /* PISTA_FONTE_HPP */
