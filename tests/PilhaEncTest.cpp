// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "PilhaEnc.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto{};

class PilhaEncTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->inteiro = PilhaEnc<int>();
        this->obj = PilhaEnc<Objeto>();
    }

 protected:
    PilhaEnc<int> inteiro;
    PilhaEnc<Objeto> obj;
};

TEST_F(PilhaEncTest, pilhaVazia) {
    ASSERT_TRUE(inteiro.pilhaVazia());
    inteiro.empilha(42);
    inteiro.empilha(5100);
    inteiro.empilha(1995);
    ASSERT_FALSE(inteiro.pilhaVazia());
}

TEST_F(PilhaEncTest, empilha) {
    inteiro.empilha(42);
    inteiro.empilha(5100);
    inteiro.empilha(90);
    inteiro.empilha(1995);
    inteiro.empilha(77);
    ASSERT_TRUE(inteiro.contem(42));
    ASSERT_TRUE(inteiro.contem(5100));
    ASSERT_TRUE(inteiro.contem(90));
    ASSERT_TRUE(inteiro.contem(1995));
    ASSERT_TRUE(inteiro.contem(77));
    ASSERT_FALSE(inteiro.contem(89));
    ASSERT_EQ(77, inteiro.desempilha());
}

TEST_F(PilhaEncTest, desempilha) {
    inteiro.empilha(42);
    inteiro.empilha(5100);
    inteiro.empilha(90);
    inteiro.empilha(1995);
    inteiro.empilha(77);
    ASSERT_EQ(77, inteiro.desempilha());
    ASSERT_FALSE(inteiro.contem(77));
}

TEST_F(PilhaEncTest, contem) {
    inteiro.empilha(42);
    inteiro.empilha(5100);
    inteiro.empilha(90);
    inteiro.empilha(1995);
    inteiro.empilha(77);
    ASSERT_TRUE(inteiro.contem(42));
    ASSERT_TRUE(inteiro.contem(5100));
    ASSERT_TRUE(inteiro.contem(90));
    ASSERT_TRUE(inteiro.contem(1995));
    ASSERT_TRUE(inteiro.contem(77));
    ASSERT_FALSE(inteiro.contem(89));
}
