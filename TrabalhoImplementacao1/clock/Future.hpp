/* 
 * File:   Future.hpp
 * Author: fernando
 *
 * Created on 3 de Outubro de 2014, 00:28
 */

#ifndef FUTURE_HPP
#define	FUTURE_HPP

#include "Event.cpp"
#include "Callback.hpp"

class Future: public Event, public Callback {
 private:
     bool remove;
 public:
    Future(int time);
    virtual bool canRun(int now);
    virtual bool canRemove();
};

#endif	/* FUTURE_HPP */

