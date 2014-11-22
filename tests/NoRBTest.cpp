// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <vector>
#include "gtest/gtest.h"
#include "NoRB.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class NoRBTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->inteiro = new NoRB<int>(10);
        this->obj = new NoRB<Objeto>(Objeto());
    }

 protected:
    NoRB<int> *inteiro;
    NoRB<Objeto> *obj;
};
