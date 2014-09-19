// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>
#include "FilaEnc.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto { };

class FilaEncTest : public testing::Test {
 public:
    virtual void SetUp() {
        this->obj = FilaEnc<Objeto>();
        this->inteiro = FilaEnc<int>();
    }

 protected:
     FilaEnc<Objeto> obj;
     FilaEnc<int> inteiro;
};

TEST_F(FilaEncTest, adiciona) {
    inteiro.adiciona(2);
    inteiro.adiciona(4);
    inteiro.adiciona(8);
    inteiro.adiciona(12);
    ASSERT_EQ(inteiro.retira(), 2);
    ASSERT_EQ(inteiro.retira(), 4);
    ASSERT_EQ(inteiro.retira(), 8);
    ASSERT_EQ(inteiro.retira(), 12);
}

TEST_F(FilaEncTest, retira) {
    inteiro.adiciona(3);
    inteiro.adiciona(9);
    inteiro.adiciona(12);
    inteiro.adiciona(6);
    ASSERT_EQ(inteiro.retira(), 3);
    ASSERT_EQ(inteiro.retira(), 9);
    ASSERT_EQ(inteiro.retira(), 12);
    ASSERT_EQ(inteiro.retira(), 6);
}

TEST_F(FilaEncTest, retiraDoInicio) {
    inteiro.adiciona(3);
    inteiro.adiciona(9);
    inteiro.adiciona(12);
    inteiro.adiciona(6);
    ASSERT_EQ(inteiro.retiraDoInicio(), 6);
    ASSERT_EQ(inteiro.retiraDoInicio(), 12);
    ASSERT_EQ(inteiro.retiraDoInicio(), 9);
    ASSERT_EQ(inteiro.retiraDoInicio(), 3);
}

