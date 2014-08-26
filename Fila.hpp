/* 
 * File:   Fila.hpp
 * Author: fernando
 *
 * Created on 25 de Agosto de 2014, 22:14
 */

#ifndef FILA_HPP
#define	FILA_HPP

#include "Lista.hpp"

class Fila {
private: 
    Lista* lista;
public:
    Fila(int tamanhoMaximo);
    void inclui(int dado);
    void retira();
    int ultimo();
    bool filaCheia();
    bool filaVazia();
};

#endif	/* FILA_HPP */

