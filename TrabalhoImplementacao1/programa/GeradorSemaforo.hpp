// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_HPP
#define GERADOR_SEMAFORO_HPP
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"
#include "../relogio/Relogio.cpp"

class GeradorSemaforo {
 private:
    Semaforo* semO1leste;
    Semaforo* semN1sul;
    Semaforo* semN2sul;
    Semaforo* semS1norte;
    Semaforo* semS2norte;
    Semaforo* semC1oeste;
    Semaforo* semC1leste;
    Semaforo* semL1oeste;
    void agendaSemaforosS1();
    void agendaSemaforosS2();

 public:
    explicit GeradorSemaforo(Relogio *relogio, int intervalo);
    Semaforo* pegaSemO1leste();
    Semaforo* pegaSemN1sul();
    Semaforo* pegaSemN2sul();
    Semaforo* pegaSemS1norte();
    Semaforo* pegaSemS2norte();
    Semaforo* pegaSemC1oeste();
    Semaforo* pegaSemC1leste();
    Semaforo* pegaSemL1oeste();
};

#endif /* GERADOR_SEMAFORO_HPP */
