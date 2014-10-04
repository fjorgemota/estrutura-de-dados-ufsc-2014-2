// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ROAD_HPP
#define ROAD_HPP
#include "FilaEnc.hpp"

template <typename T>
class Road: public FilaEnc<T> {
 protected:
    int size;
    int speed;

 public:
    Road(int size, int speed);
    int getSize();
    int getSpeed();
};

#endif /* ROAD_HPP */
