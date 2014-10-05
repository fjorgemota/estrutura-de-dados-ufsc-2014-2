// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef RELOGIO_CPP
#define RELOGIO_CPP
#include <cstdio>
#include "Relogio.hpp"
#include "Futuro.cpp"
#include "Evento.cpp"
Relogio::Relogio() {
    this->horaAtual = 0;
    this->futuros = new ListaDupla<Futuro*>();
    this->historico = new ListaDupla<Evento*>();
}

Relogio::~Relogio() {
    this->futuros->destroiListaDuplo();
    this->historico->destroiListaDuplo();
}

void Relogio::registra(Evento *ev) {
    ev->configuraHora(this->horaAtual);
    this->historico->adicionaDuplo(ev);
}

void Relogio::agenda(Futuro *fut) {
    this->futuros->adicionaDuplo(fut);
}


void Relogio::listaFuturos() {
    int i, ultimo;
    printf("Eventos futuros:\n");
    if (this->futuros->listaVazia()) {
        printf("- Nenhum futuro registrado");
    } else {
        ultimo = this->futuros->verUltimo();
        for (i = 0; i <= ultimo; i++) {
            printf("\t- %s\n", this->futuros->mostra(i)->pegaDescricao());
        }
    }
}

void Relogio::listaHistorico() {
    int i, ultimo;
    printf("Eventos registrados:\n");
    if (this->historico->listaVazia()) {
        printf("\t- Nenhum evento registrado\n");
    } else {
        ultimo = this->historico->verUltimo();
        for (i = 0; i <= ultimo; i++) {
            Evento *ev = this->historico->mostra(i);
            printf("\t- [At %d][Tipo %d] %s\n", ev->pegaHora(), ev->pegaTipo(),
                    ev->pegaDescricao());
        }
    }
}

void Relogio::executa() {
    while (1) {
        if (this->futuros->listaVazia()) {
            break;
        }
        int contador, ultimo;
        ultimo = this->futuros->verUltimo();
        contador = 0;
        while (contador <= ultimo) {
            Futuro *evento = this->futuros->mostra(contador);
            if (evento->podeExecutar(this->horaAtual)) {
                evento->executa();
            }
            if (evento->podeRemover()) {
                this->futuros->retiraDaPosicaoDuplo(contador);
                ultimo--;
                continue;
            }
            contador++;
        }
        this->horaAtual++;
    }
}
#endif
