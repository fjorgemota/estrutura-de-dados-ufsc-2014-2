// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PISTA_SUMIDOURA_HPP
#define FUTURO_PISTA_SUMIDOURA_HPP
#include "../relogio/Futuro.cpp"
#include "../pistas/PistaSumidoura.cpp"

class FuturoPistaSumidoura : public Futuro {
 private:
    PistaSumidoura *pista;

 public:
    explicit FuturoPistaSumidoura(PistaSumidoura* pista);
    virtual void executa();
};

#endif /* FUTURO_PISTA_SUMIDOURA_HPP */
