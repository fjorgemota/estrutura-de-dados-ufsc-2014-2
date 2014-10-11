// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include "util/NumeroAleatorio.hpp"
#include "relogio/Relogio.cpp"
#include "programa/Programa.cpp"

int main(int argc, char** argv) {
    INICIALIZA_NUMEROS_ALEATORIOS();
    Relogio* relogio = new Relogio();
    Programa* programa = new Programa(relogio);
    programa->executar();
    relogio->executar();
    delete relogio;
    delete programa;
    return 0;
}
#endif /* MAIN_CPP */
