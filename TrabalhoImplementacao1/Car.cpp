// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef CAR_CPP
#define CAR_CPP
#include "Car.hpp"

template <typename T>
Car<T>::Car(int size) {
    this->size = size;
}

template <typename T>
int Car<T>::getSize() {
    return this->size + 3;
}

#endif /* CAR_CPP */
