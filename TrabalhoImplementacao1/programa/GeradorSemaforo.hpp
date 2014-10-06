// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_HPP
#define GERADOR_SEMAFORO_HPP
#include "../semaforo/Semaforo.hpp"

class GeradorSemaforo {
 private:
    int intervalo;

 public:
    GeradorSemaforo(int intervalo);
    Semaforo semO1leste();
    Semaforo semN1sul();
    Semaforo semN2sul();
    Semaforo semS1norte();
    Semaforo semS2norte();
    Semaforo semC1oeste();
    Semaforo semC1leste();
    Semaforo semL1oeste();
};

#endif /* GERADOR_SEMAFORO_HPP */
