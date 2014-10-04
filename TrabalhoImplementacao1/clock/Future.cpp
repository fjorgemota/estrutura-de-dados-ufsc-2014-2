// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURE_CPP
#define FUTURE_CPP
#include "Future.hpp"

Future::Future(int interval, char* desc) : Event(interval, EVENT_FUTURE, desc) {
    this->remove = false;
}

Future::Future(int interval) : Event(interval, EVENT_FUTURE) {
    this->remove = false;
}

bool Future::canRun(int now) {
    bool result = this->getTime() == now;
    if (result) {
        this->remove = true;
    }
    return result;
}

bool Future::canRemove() {
    return this->remove;
}
#endif
