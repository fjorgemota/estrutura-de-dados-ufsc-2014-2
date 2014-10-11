// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PROGRAMA_CPP
#define PROGRAMA_CPP
#include <iostream>
#include <string>
#include "../eventos/FuturoFim.cpp"
#include "../relogio/Futuro.cpp"
#include "Programa.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define SEPARADOR_PERGUNTA "------------------------------------------------"

Programa::Programa(Relogio *relogio) {
    this->relogio = relogio;
    this->geradorSemaforos = new GeradorSemaforo(this->relogio);
    this->geradorPistas = new GeradorPistas(this->relogio,
                                        this->geradorSemaforos);
    this->geradorPistas->geraPistas();
}

Programa::~Programa() {
    delete this->geradorPistas;
    delete this->geradorSemaforos;
}

void Programa::perguntaTempoDuracao() {
    int duracao;
    cout <<
        "Por quanto tempo deseja executar a simulação? (em segundos)"
            << endl;
    cin >> duracao;
    cout << SEPARADOR_PERGUNTA << endl;
    Futuro *fim = new FuturoFim(this->relogio,
        this->geradorSemaforos->pegaSemaforosS1(),
        this->geradorSemaforos->pegaSemaforosS2(),
        this->perguntaMostraEventos(),
        duracao);
    this->relogio->agenda(fim);
}

void Programa::perguntaIntervaloSemaforo() {
    int intervalo;
    cout << "Qual será o intervalo de alternância do semáforo?" << endl;
    cin >> intervalo;
    cout << SEPARADOR_PERGUNTA << endl;
    this->geradorSemaforos->agendaSemaforosS1(intervalo);
    this->geradorSemaforos->agendaSemaforosS2(intervalo);
}

bool Programa::perguntaMostraEventos() {
    string resposta;
    cout << "Você deseja mostrar os eventos ocorridos no fim da execução? (S/N)"
        << endl;
    cin >> resposta;
    cout << SEPARADOR_PERGUNTA << endl;
    return resposta == "S" || resposta == "s";
}

void Programa::executar() {
    this->perguntaTempoDuracao();
    this->perguntaIntervaloSemaforo();
}

#endif /* PROGRAMA_CPP */
