// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_SEMAFORO_HPP
#define FUTURO_PERIODICO_SEMAFORO_HPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"

class FuturoPeriodicoSemaforo : public FuturoPeriodico {
 private:
    Semaforo *semaforo;
 public:
    explicit FuturoPeriodicoSemaforo(Semaforo *semaforo);
    virtual void executa();
};

#endif /* FUTURO_PERIODICO_SEMAFORO_HPP */
