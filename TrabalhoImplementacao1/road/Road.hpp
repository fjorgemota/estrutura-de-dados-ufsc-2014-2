// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ROAD_HPP
#define ROAD_HPP
#include "FilaEnc.cpp"
#include "car/Car.cpp"

class Road: public FilaEnc<Car> {
 private:
    int size;
    int speed;

 public:
    Road(int size, int speed);
    int getSize();
    int getSpeed();
};

#endif /* ROAD_HPP */
