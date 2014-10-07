// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_FIM_CPP
#define FUTURO_FIM_CPP

#include <cstdio>
#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../util/ListaDupla.cpp"
#include "FuturoFim.hpp"

FuturoFim::FuturoFim(Relogio *relogio, ListaDupla<Semaforo*> semaforos,
    int pararEm) : Futuro(pararEm) {
    this->relogio = relogio;
    this->semaforos = semaforos;
}

void FuturoFim::executar() {
    this->relogio->parar();
    this->relogio->listaHistorico();
    printf("Estatisticas dos semáforos:\n");
    
}


#endif /* FUTURO_FIM_CPP */
