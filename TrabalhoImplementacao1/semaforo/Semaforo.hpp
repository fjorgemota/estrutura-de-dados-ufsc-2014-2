// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP
#include "../util/ListaEnc.cpp"

#define SEMAFORO_ABERTO true
#define SEMAFORO_FECHADO false

class Semaforo {
 private:
    int intervalo;
    bool aberto;
 public:
    explicit Semaforo(int intervalo);
    int pegaIntervalo();
    bool estaAberto();
    bool estaFechado();
    void abre();
    void fecha();
};

#endif /* SEMAFORO_HPP */
