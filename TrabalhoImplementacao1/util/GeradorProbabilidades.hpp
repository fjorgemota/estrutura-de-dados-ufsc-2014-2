// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PROBABILIDADES_HPP
#define GERADOR_PROBABILIDADES_HPP
#include "ListaDupla.cpp"

template <typename T>
class GeradorProbabilidades {
 private:
    ListaDupla<T> *lista;
 public:
    GeradorProbabilidades();
    void adiciona(T dado, int porcentagem);
    ListaDupla<T> pegaLista();
};
#endif /* GERADOR_PROBABILIDADES_HPP */
