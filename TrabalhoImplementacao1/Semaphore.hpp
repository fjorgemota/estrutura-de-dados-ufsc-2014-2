// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP
#include "Road.hpp"
#include "ListaEnc.hpp"

template <typename T>
class Semaphore {
 private:
    ListaEnc<Road*> imput;
    ListaEnc<Road*> exit;

 public:
    Semaphore();
};

#endif /* SEMAPHORE_HPP */
