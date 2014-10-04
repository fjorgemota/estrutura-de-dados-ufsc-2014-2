/* 
 * File:   Relogio.cpp
 * Author: fernando
 * 
 * Created on 2 de Outubro de 2014, 22:40
 */
#ifndef CLOCK_CPP
#define	CLOCK_CPP
#include "Clock.hpp"
#include "Future.cpp"
#include "Event.cpp"
#include <cstdio>
#ifdef DEBUG
#include <unistd.h>
#endif
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


void Clock::list() {
    int i, last;
    
    #ifdef DEBUG
    printf("Registered futures:\n");
    if(this->futures->listaVazia()) {
        printf("- No futures registered");
    } else {
        last = this->futures->verUltimo();
        for (i = 0; i <= last; i++) {
            printf("\t- %s\n", this->futures->mostra(i)->getDescription());
        }
    }
    #endif
    printf("Registered events:\n");
    if(this->historic->listaVazia()) {
        printf("\t- No Events registered\n");
    } else {
        last = this->historic->verUltimo();
        for (i = 0; i <= last; i++) {
            Event *ev = this->historic->mostra(i);
            printf(
                    "\t- [At %d][Type %d] %s\n",
                    ev->getTime(),
                    ev->getType(),
                    ev->getDescription()
            );
        }
    }
}

void Clock::run() {
    while(1) {
        if(this->futures->listaVazia()) {
            break;
        }
        int cont, last;
        last = this->futures->verUltimo();
        cont = 0;
        while(cont <= last) {
            Future *event = this->futures->mostra(cont);
            if(event->canRun(this->now)) {
                event->run();
            }
            if(event->canRemove()) {
                this->futures->retiraDaPosicaoDuplo(cont);
                last--;
                continue;
            }
            cont++;
        }
        this->now++;
        #ifdef DEBUG
        sleep(1);
        #endif
    }
}
#endif
