// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_HPP
#define FUTURO_HPP

#include "Evento.cpp"
#include "Retorno.hpp"

class Futuro: public Evento, public Retorno {
 private:
    bool remover;
 public:
    Futuro(int intervalo, char *descricao);
    explicit Futuro(int descricao);
    Futuro();
    virtual bool podeExecutar(int horaAtual);
    virtual bool podeRemover();
};

#endif /* FUTURO_HPP */
