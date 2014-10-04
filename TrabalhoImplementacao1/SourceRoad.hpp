// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SOURCEROAD_HPP
#define SOURCEROAD_HPP
#include "Road.hpp"

template <typename T>
class SourceRoad: public Road<T> {
 public:
     SourceRoad(int size, int speed);
};



#endif /* ROADNORMAL_HPP */
