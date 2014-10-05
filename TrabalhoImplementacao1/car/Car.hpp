// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef CAR_HPP
#define CAR_HPP

template <typename T>
class Car {
 private:
    int size;

 public:
     explicit Car(int size);
     int getSize();
};

#endif /* CAR_HPP */

