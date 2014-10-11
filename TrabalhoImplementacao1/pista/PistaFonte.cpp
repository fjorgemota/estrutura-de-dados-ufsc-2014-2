// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_FONTE_CPP
#define PISTA_FONTE_CPP
#include "Pista.cpp"
#include "PistaFonte.hpp"

PistaFonte::PistaFonte(Relogio *relogio, Semaforo *semaforo, int tamanho,
    int velocidade, ListaDupla<Pista*> *pistas) : Pista(
    relogio, semaforo, tamanho, velocidade, pistas) {}

#endif /* PISTA_FONTE_CPP */
