// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_HPP
#define FUTURO_PERIODICO_HPP

#include "Futuro.cpp"

class FuturoPeriodico : public Futuro {
 public:
    FuturoPeriodico(int intervalo, char* description);
    explicit FuturoPeriodico(int intervalo);
    FuturoPeriodico();
    virtual bool podeExecutar(int agora);
    virtual bool podeRemover();
};

#endif /* FUTURO_PERIODICO_HPP */
