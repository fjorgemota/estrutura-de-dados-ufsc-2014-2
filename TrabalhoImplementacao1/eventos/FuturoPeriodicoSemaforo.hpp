// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_SEMAFORO_HPP
#define FUTURO_PERIODICO_SEMAFORO_HPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"

class FuturoPeriodicoSemaforo : public FuturoPeriodico {
 private:
    ListaDupla<Semaforo*> *semaforo;
    int semaforoEscolhido;
 public:
    explicit FuturoPeriodicoSemaforo(ListaDupla<Semaforo*> *semaforo);
    virtual void executa();
};

#endif /* FUTURO_PERIODICO_SEMAFORO_HPP */
