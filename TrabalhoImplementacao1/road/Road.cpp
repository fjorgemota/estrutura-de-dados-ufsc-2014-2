// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ROAD_CPP
#define ROAD_CPP
#include "Road.hpp"

Road<T>::Road(int size, int speed) {
    this->size = size;
    this->speed = speed;
}

int Road<T>::getSize() {
    return this->size;
}

int Road<T>::getSpeed() {
    return this->speed;
}

#endif /* ROAD_CPP */
