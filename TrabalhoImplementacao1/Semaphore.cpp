// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAPHORE_CPP
#define SEMAPHORE_CPP
#include "Semaphore.hpp"

template <typename T>
Semaphore<T>::Semaphore() {
    this->imput = ListaEnc<Road*>();
    this->exit = ListaEnc<Road*>();
}

#endif
