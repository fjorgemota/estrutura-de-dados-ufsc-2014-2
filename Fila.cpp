/* 
 * File:   Fila.cpp
 * Author: fernando
 * 
 * Created on 25 de Agosto de 2014, 22:14
 */

#include "Fila.hpp"
#include "Lista.hpp"

Fila::Fila(int tamanhoMaximo) {
    this->lista = new Lista(tamanhoMaximo);
}

bool Fila::filaCheia() {
    return this->lista->listaCheia();
}

bool Fila::filaVazia() {
    return this->lista->listaVazia();
}

void Fila::inclui(int dado) {
    this->lista->adicionar(dado);
}

void Fila::retira(){
    this->lista->removerPrimeiro();
}

int Fila::ultimo() {
    return this->lista->pegaPrimeiro();
}
