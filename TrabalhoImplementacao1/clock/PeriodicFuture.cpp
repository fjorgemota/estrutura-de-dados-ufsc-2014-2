/* 
 * File:   PeriodicEvent.cpp
 * Author: fernando
 * 
 * Created on 3 de Outubro de 2014, 00:16
 */
#ifndef PERIODIC_FUTURE_CPP
#define	PERIODIC_FUTURE_CPP
#include "PeriodicFuture.hpp"

PeriodicFuture::PeriodicFuture(int interval) : Future(interval) {}


bool PeriodicFuture::canRun(int now) {
    return (now % this->getTime()) == 0;
}

bool PeriodicFuture::canRemove() {
    return false;
}
#endif
