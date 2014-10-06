// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_PISTA_SUMIDOURA_HPP
#define INTERVALO_PISTA_SUMIDOURA_HPP
#include "TrabalhoImplementacao1/relogio/Futuro.hpp"
#include "TrabalhoImplementacao1/pistas/Pista.hpp"

class IntervaloPistaSumidoura : public Futuro {
 private:
    PistaSumidoura *pista;

 public:
    explicit IntervaloPistaSumidoura(PistaSumidoura* pista);
    virtual void executa();
};
#include "TrabalhoImplementacao1/eventos/IntervaloPistaSumidoura.cpp"
#endif
