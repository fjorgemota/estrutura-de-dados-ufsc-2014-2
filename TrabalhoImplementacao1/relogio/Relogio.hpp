// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef RELOGIO_HPP
#define RELOGIO_HPP
#include "../util/ListaDupla.cpp"
#include "Evento.cpp"
#include "Futuro.cpp"

class Relogio {
 private:
    ListaDupla<Evento*> *historico;
    ListaDupla<Futuro*> *futuros;
    int horaAtual;
 public:
    Relogio();
    ~Relogio();
    void registra(Evento *ev);
    void agenda(Futuro *fut);
    void listaFuturos();
    void listaHistorico();
    void executa();
};

#endif /* RELOGIO_HPP */
