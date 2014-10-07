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
    bool paraExecucao;
 public:
    Relogio();
    ~Relogio();
    int pegaHoraAtual();
    void registra(Evento *ev);
    void agenda(Futuro *fut);
    void agendaDaquiA(Futuro *fut, int horaAtual);
    void parar();
    void listaFuturos();
    void listaHistorico();
    void executar();
};

#endif /* RELOGIO_HPP */
