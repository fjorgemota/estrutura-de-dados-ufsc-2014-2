#ifndef INDICE_PRIMARIO_HPP
#define INDICE_PRIMARIO_HPP

#include "../util/NoAVL.hpp"
#include "../util/ListaDupla.hpp"
#include "../modelos/ManPage.hpp"

class IndicePrimario : public NoAVL<int> {
 public:
    explicit IndicePrimario(const int& dado);
 	ListaDupla<int> breadth_first();
};

#include "IndicePrimario.cpp"

#endif /** INDICE_PRIMARIO_HPP */