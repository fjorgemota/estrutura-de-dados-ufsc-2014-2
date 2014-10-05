// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAPHORE_CPP
#define SEMAPHORE_CPP
#include "Semaphore.hpp"

Semaphore::Semaphore(int interval) {
    this->interval = interval;
    this->input = ListaEnc<Road*>();
    this->output = ListaEnc<Road*>();
}

int Semaphore::getInterval() {
    return this->interval;
}

#endif
