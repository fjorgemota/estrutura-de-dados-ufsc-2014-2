// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_HPP
#define GERADOR_SEMAFORO_HPP
#include "../semaforo/Semaforo.hpp"

class GeradorSemaforo {
 private:
    int intervalo;

 public:
    GeradorSemaforo(int intervalo);
    Semaforo* geraSemO1leste();
    Semaforo* geraSemN1sul();
    Semaforo* geraSemN2sul();
    Semaforo* geraSemS1norte();
    Semaforo* geraSemS2norte();
    Semaforo* geraSemC1oeste();
    Semaforo* geraSemC1leste();
    Semaforo* geraSemL1oeste();
};

#endif /* GERADOR_SEMAFORO_HPP */
