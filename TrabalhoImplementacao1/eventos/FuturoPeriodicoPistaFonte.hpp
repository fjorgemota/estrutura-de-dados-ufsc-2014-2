// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_PISTA_FONTE_HPP
#define FUTURO_PERIODICO_PISTA_FONTE_HPP
#include "../pista/PistaFonte.cpp"
#include "../relogio/Relogio.cpp"
#include "../relogio/FuturoPeriodico.cpp"

class FuturoPeriodicoPistaFonte : public FuturoPeriodico {
 private:
    PistaFonte *pista;
    Relogio *relogio;
    int intervaloMinimo;
    int intervaloMaximo;

 public:
    FuturoPeriodicoPistaFonte(PistaFonte *pista,  Relogio *relogio,
        int intervaloMinimo, int intervaloMaximo);
    void agendar();
    void executar();
};

#endif /* FUTURO_PERIODICO_PISTA_FONTE_HPP */
