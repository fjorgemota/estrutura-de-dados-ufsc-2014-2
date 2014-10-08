// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef RELOGIO_CPP
#define RELOGIO_CPP
#include <iostream>
#include "Relogio.hpp"
#include "Futuro.cpp"
#include "Evento.cpp"

using std::cout;
using std::endl;

Relogio::Relogio() {
    this->segundoAtual = 0;
    this->paraExecucao = false;
    this->futuros = new ListaDupla<Futuro*>();
    this->historico = new ListaDupla<Evento*>();
}

Relogio::~Relogio() {
    this->futuros->destroiListaDuplo();
    this->historico->destroiListaDuplo();
}

int Relogio::pegaSegundoAtual() {
    return this->segundoAtual;
}

int Relogio::contaEventosDoTipo(int tipo) {
    if (this->historico->listaVazia()) {
        return 0;
    }
    int i, total, ultimo;
    ultimo = this->historico->verUltimo();
    total = 0;
    for (i = 0; i <= ultimo; i++) {
        Evento *ev = this->historico->mostra(i);
        if (ev->pegaTipo() == tipo) {
            total++;
        }
    }
    return total;
}

void Relogio::registra(Evento *ev) {
    ev->configuraSegundo(this->segundoAtual);
    this->historico->adicionaDuplo(ev);
}

void Relogio::agenda(Futuro *fut) {
    this->futuros->adicionaDuplo(fut);
}

void Relogio::agendaDaquiA(Futuro *fut, int intervaloFuturo) {
    fut->configuraSegundo(this->pegaSegundoAtual() + intervaloFuturo);
    this->futuros->adicionaDuplo(fut);
}

void Relogio::parar() {
    this->paraExecucao = true;
}

void Relogio::listaFuturos() {
    int i, ultimo;
    cout << "Eventos futuros:\n" << endl;
    if (this->futuros->listaVazia()) {
        cout << "- Nenhum futuro registrado" << endl;
    } else {
        ultimo = this->futuros->verUltimo();
        for (i = 0; i <= ultimo; i++) {
            cout << "\t- " << this->futuros->mostra(i)->pegaDescricao() << endl;
        }
    }
}

void Relogio::listaHistorico() {
    int i, ultimo;
    cout << "Eventos registrados:" << endl;
    if (this->historico->listaVazia()) {
        cout << "\t- Nenhum evento registrado\n";
    } else {
        ultimo = this->historico->verUltimo();
        for (i = 0; i <= ultimo; i++) {
            Evento *ev = this->historico->mostra(i);
            cout <<
                "\t- [Segundo " << ev->pegaSegundo() << "][Tipo "
                    << ev->pegaTipo() << "] ";
            cout << ev->pegaDescricao() << endl;
        }
    }
}

void Relogio::executar() {
    int contador, ultimo, totalHistorico;
    while (this->paraExecucao == false) {
        cout << "\r";
        cout << this->segundoAtual << " Segundos simulados. ";
        if (this->futuros->listaVazia()) {
            cout << "Não há tarefas para executar";
            break;
        }
        ultimo = this->futuros->verUltimo();
        cout << ultimo << " Tarefas agendadas. ";
        if (this->historico->listaVazia()) {
            totalHistorico = 0;
        } else {
            totalHistorico = this->historico->verUltimo() + 1;
        }
        cout << totalHistorico << " Tarefas registradas.";
        contador = 0;
        while (contador <= ultimo) {
            Futuro *evento = this->futuros->mostra(contador);
            if (evento->podeExecutar(this->segundoAtual)) {
                evento->executar();
            }
            if (evento->podeRemover()) {
                evento = this->futuros->retiraDaPosicaoDuplo(contador);
                ultimo--;
                delete evento;
                continue;
            }
            contador++;
        }
        this->segundoAtual++;
    }
}
#endif /* RELOGIO_CPP */
