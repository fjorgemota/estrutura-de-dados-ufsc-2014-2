// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef CLOCK_CPP
#define CLOCK_CPP
#include <cstdio>
#include "Clock.hpp"
#include "Future.cpp"
#include "Event.cpp"
Clock::Clock() {
    this->now = 0;
    this->futures = new ListaDupla<Future*>();
    this->historic = new ListaDupla<Event*>();
}

Clock::~Clock() {
    this->futures->destroiListaDuplo();
    this->historic->destroiListaDuplo();
}

void Clock::add(Event *ev) {
    ev->setTime(this->now);
    this->historic->adicionaDuplo(ev);
}

void Clock::schedule(Future *fut) {
    this->futures->adicionaDuplo(fut);
}


void Clock::listFutures() {
    int i, last;
    printf("Registered futures:\n");
    if (this->futures->listaVazia()) {
        printf("- No futures registered");
    } else {
        last = this->futures->verUltimo();
        for (i = 0; i <= last; i++) {
            printf("\t- %s\n", this->futures->mostra(i)->getDescription());
        }
    }
}

void Clock::listHistoric() {
    int i, last;
    printf("Registered events:\n");
    if (this->historic->listaVazia()) {
        printf("\t- No Events registered\n");
    } else {
        last = this->historic->verUltimo();
        for (i = 0; i <= last; i++) {
            Event *ev = this->historic->mostra(i);
            printf("\t- [At %d][Type %d] %s\n", ev->getTime(), ev->getType(),
                    ev->getDescription());
        }
    }
}

void Clock::run() {
    while (1) {
        if (this->futures->listaVazia()) {
            break;
        }
        int cont, last;
        last = this->futures->verUltimo();
        cont = 0;
        while (cont <= last) {
            Future *event = this->futures->mostra(cont);
            if (event->canRun(this->now)) {
                event->run();
            }
            if (event->canRemove()) {
                this->futures->retiraDaPosicaoDuplo(cont);
                last--;
                continue;
            }
            cont++;
        }
        this->now++;
    }
}
#endif
