// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_FIM_CPP
#define FUTURO_FIM_CPP

#include <iostream>
#include <string>
#include "../relogio/Evento.cpp"
#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"
#include "FuturoFim.hpp"

using std::cout;
using std::endl;
using std::string;

#define INDENTACAO "    "

FuturoFim::FuturoFim(Relogio *relogio, ListaDupla<Semaforo*> *semaforosS1,
    ListaDupla<Semaforo*> *semaforosS2, bool mostraEventos,
    int pararEm) : Futuro(pararEm) {
    this->relogio = relogio;
    this->semaforosS1 = semaforosS1;
    this->semaforosS2 = semaforosS2;
    this->mostraEventos = mostraEventos;
}

void FuturoFim::executar() {
    this->relogio->parar();
    if (this->mostraEventos) {
        this->relogio->listaHistorico();
    }
    cout << endl << "- Estatisticas dos semáforos do cruzamento S1:" << endl;
    int i, ultimo, totalCarrosPorSemaforo,
                        totalCarrosSemaforo, totalCarrosPistaFonte;
    int totalCarrosChegaramSemaforo;
    Semaforo *semaforo;
    string descricao;
    ultimo = this->semaforosS1->verUltimo();
    totalCarrosSemaforo = 0;
    for (i = 0; i <= ultimo; i++) {
        semaforo = this->semaforosS1->mostra(i);
        totalCarrosPorSemaforo = semaforo->pegaContador();
        descricao = semaforo->pegaDescricao();
        cout << INDENTACAO << "- " << totalCarrosPorSemaforo <<
                        " carros passaram pelo semaforo " << descricao << endl;
        totalCarrosSemaforo += totalCarrosPorSemaforo;
    }
    cout << "- Estatisticas dos semáforos do cruzamento S2:" << endl;
    ultimo = this->semaforosS2->verUltimo();
    for (i = 0; i <= ultimo; i++) {
        semaforo = this->semaforosS2->mostra(i);
        totalCarrosPorSemaforo = semaforo->pegaContador();
        descricao = semaforo->pegaDescricao();
        cout << INDENTACAO << "- " << totalCarrosPorSemaforo
                        << " carros passaram pelo semaforo "
                            << descricao << endl;
        totalCarrosSemaforo += totalCarrosPorSemaforo;
    }
    cout << "- Algumas outras informações importantes:" << endl;
    cout << INDENTACAO << "- " << totalCarrosSemaforo
                    << " carros passaram pelos semaforos dos dois cruzamentos."
                                << endl;
    totalCarrosPistaFonte = this->
                    relogio->contaEventosDoTipo(EVENTO_CARRO_ENTRA_PISTA);
    cout << "\r" << INDENTACAO <<  "- " << totalCarrosPistaFonte
                    << " carros entraram no sistema através de uma das pistas fontes"
                                << endl;

    totalCarrosChegaramSemaforo = this->
                    relogio->contaEventosDoTipo(EVENTO_CARRO_CHEGA_SEMAFORO);
    cout << "\r" << INDENTACAO <<  "- " << totalCarrosChegaramSemaforo
                    << " carros chegaram nos semáforos dos dois cruzamentos"
                                << endl;
}

#endif /* FUTURO_FIM_CPP */
