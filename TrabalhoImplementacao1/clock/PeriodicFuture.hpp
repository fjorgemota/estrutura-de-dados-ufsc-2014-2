/* 
 * File:   PeriodicEvent.hpp
 * Author: fernando
 *
 * Created on 3 de Outubro de 2014, 00:16
 */

#ifndef PERIODICEVENT_HPP
#define	PERIODICEVENT_HPP

#include "Future.cpp"

class PeriodicFuture : public Future {
public:
    PeriodicFuture(int interval);
    virtual bool canRun(int now);
    virtual bool canRemove();
};

#endif	/* PERIODICEVENT_HPP */

