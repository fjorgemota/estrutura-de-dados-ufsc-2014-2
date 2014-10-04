// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef RELOGIO_HPP
#define RELOGIO_HPP
#include "ListaDupla.cpp"
#include "Event.cpp"
#include "Future.cpp"

class Clock {
 private:
    ListaDupla<Event*> *historic;
    ListaDupla<Future*> *futures;
    int now;
 public:
    Clock();
    ~Clock();
    void add(Event *ev);
    void schedule(Future *fut);
    void listFutures();
    void listHistoric();
    void run();
};

#endif /* RELOGIO_HPP */

