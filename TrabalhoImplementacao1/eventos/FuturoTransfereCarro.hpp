// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_TRANSFERE_CARRO_HPP
#define FUTURO_TRANSFERE_CARRO_HPP
#include "../pista/Pista.cpp"
#include "../relogio/Futuro.cpp"
#include "../semaforo/Semaforo.cpp"

class FuturoTransfereCarro : public Futuro {
 private:
    Pista *pista;
    Semaforo *semaforo;

 public:
    FuturoTransfereCarro(Pista* pista, Semaforo* semaforo, int intervalo);
    virtual void executar();
};
#include "TrabalhoImplementacao1/relogio/IntervaloTransfereCarro.cpp"
#endif /* FUTURO_TRANSFERE_CARRO_HPP */
