// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_SEMAFORO_HPP
#define INTERVALO_SEMAFORO_HPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"

class IntervaloSemaforo : public FuturoPeriodico {
 private:
    Semaforo *semaforo;
 public:
    explicit IntervaloSemaforo(Semaforo *semaforo);
    virtual void executa();
};

#endif
