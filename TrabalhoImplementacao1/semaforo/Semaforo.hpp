// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP
#include "../pista/Pista.cpp"
#include "../util/ListaEnc.cpp"

class Semaforo {
 private:
    int intervalo;
    ListaEnc<Road*> entrada;
    ListaEnc<Road*> saida;
 public:
    explicit Semaforo(int intervalo);
    int getInterval();
};

#endif /* SEMAFORO_HPP */
