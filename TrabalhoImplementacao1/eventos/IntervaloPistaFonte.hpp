// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef INTERVALO_PISTA_FONTE_HPP
#define INTERVALO_PISTA_FONTE_HPP
#include "./pista/PistaFonte.cpp"
#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"

class IntervaloPistaFonte : public Futuro {
 private:
    PistaFonte *pista;
    Relogio *relogio;
    int intervaloMinimo;
    int intervaloMaximo;

 public:
    IntervaloPistaFonte(PistaFonte *pista,  Relogio *relogio,
        int intervaloMinimo, int intervaloMaximo);
    void agenda();
    void executa();
    virtual bool podeRemover();
};

#endif /* INTERVALO_PISTA_FONTE_HPP */
