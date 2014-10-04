#ifndef ROAD_CPP
#define	ROAD_CPP
#include "Road.hpp"

template <typename T>
Road<T>::Road(int size, int speed) {
    this->size = size;
    this->speed = speed;
}

template <typename T>
int Road<T>::getSize() {
    return this->size;
}

template <typename T>
int Road<T>::getSpeed() {
    return this->speed;
}

#endif	/* ROAD_CPP */
