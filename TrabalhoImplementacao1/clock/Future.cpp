/* 
 * File:   Future.cpp
 * Author: fernando
 * 
 * Created on 3 de Outubro de 2014, 00:28
 */
#ifndef FUTURE_CPP
#define	FUTURE_CPP
#include "Future.hpp"

Future::Future(int time) : Event(time, EVENT_FUTURE) {
    this->remove = false;
}

bool Future::canRun(int now) {
    bool result = this->getTime() == now;
    if(result) {
        this->remove = true;
    }
    return result;
}

bool Future::canRemove() {
    return this->remove;
}
#endif
