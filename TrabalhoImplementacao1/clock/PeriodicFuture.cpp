// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PERIODIC_FUTURE_CPP
#define PERIODIC_FUTURE_CPP
#include "PeriodicFuture.hpp"

PeriodicFuture::PeriodicFuture(int interv, char* desc):Future(interv, desc) {}

PeriodicFuture::PeriodicFuture(int interval) : Future(interval) {}

bool PeriodicFuture::canRun(int now) {
    return (now % this->getTime()) == 0;
}

bool PeriodicFuture::canRemove() {
    return false;
}
#endif
