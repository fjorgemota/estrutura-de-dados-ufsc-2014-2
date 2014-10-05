// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef MAIN_CPP
#define MAIN_CPP
#include <cstdlib>
#include <cstdio>
#include "relogio/Relogio.cpp"
#include "relogio/FuturoPeriodico.cpp"

int main(int argc, char** argv) {
    Relogio relogio = Relogio();
    relogio.executa();
    return 0;
}
#endif
