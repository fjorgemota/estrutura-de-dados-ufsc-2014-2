#ifndef RELOGIO_HPP
#define	RELOGIO_HPP
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
    void list();
    void run();
};

#endif	/* RELOGIO_HPP */

