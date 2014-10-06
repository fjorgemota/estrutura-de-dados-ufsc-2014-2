// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_TRANSFERE_CARRO_HPP
#define INTERVALO_TRANSFERE_CARRO_HPP
#include "../pista/Pista.hpp"
#include "TrabalhoImplementacao1/relogio/Futuro.hpp"
#include "TrabalhoImplementacao1/semaforo/Semaforo.hpp"

class IntervaloTransfereCarro : public Futuro {
 private:
    Pista *pista;
    Semaforo *semaforo;

 public:
    IntervaloTransfereCarro(Pista* pista, Semaforo* semaforo);
    virtual void executa();
};
#include "TrabalhoImplementacao1/relogio/IntervaloTransfereCarro.cpp"
#endif /* INTERVALO_TRANSFERE_CARRO_HPP */
