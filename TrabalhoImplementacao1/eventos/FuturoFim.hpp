// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_FIM_HPP
#define FUTURO_FIM_HPP

#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../util/ListaDupla.cpp"

class FuturoFim : public Futuro {
 private:
    Relogio *relogio;
    ListaDupla<Semaforo*> semaforos;

 public:
    FuturoFim(Relogio *relogio, ListaDupla<Semaforo*> semaforos, int pararEm);
    virtual void executar();
}

#endif /* FUTURO_FIM_HPP */
