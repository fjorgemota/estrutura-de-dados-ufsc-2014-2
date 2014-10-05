// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP
#include "Road.hpp"
#include "ListaEnc.hpp"

class Semaphore {
 private:
    int interval;
    ListaEnc<Road*> input;
    ListaEnc<Road*> output;
 public:
    explicit Semaphore(int interval);
    int getInterval();
};

#endif /* SEMAPHORE_HPP */
