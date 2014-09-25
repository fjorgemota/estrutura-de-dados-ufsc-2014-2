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
    ASSERT_TRUE(inteiro.PilhaVazia());
    inteiro.empilha(42);
    inteiro.empilha(5100);
    inteiro.empilha(1995);
    ASSERT_FALSE(inteiro.PilhaVazia());
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

TEST_F(PilhaEncTest, limparPilha) {
    inteiro.empilha(600);
    inteiro.empilha(42);
    inteiro.empilha(2600);
    inteiro.empilha(5100);
    inteiro.empilha(42);
    ASSERT_FALSE(inteiro.PilhaVazia());
    inteiro.desempilha();
    inteiro.desempilha();
    ASSERT_FALSE(inteiro.PilhaVazia());
    inteiro.limparPilha();
    ASSERT_TRUE(inteiro.PilhaVazia());
}

TEST_F(PilhaEncTest, PilhaEnc) {
    inteiro.empilha(600);
    inteiro.empilha(50);
    inteiro.empilha(2600);
    inteiro.empilha(5100);
    inteiro.empilha(42);
    ASSERT_FALSE(inteiro.PilhaVazia());
    inteiro.desempilha();
    inteiro.desempilha();
    inteiro.empilha(300);
    inteiro.empilha(80);
    inteiro.empilha(5200);
    inteiro.empilha(1990);
    inteiro.empilha(42);
    ASSERT_FALSE(inteiro.PilhaVazia());
    inteiro.~PilhaEnc();
    ASSERT_TRUE(inteiro.PilhaVazia());
}

TEST_F(PilhaEncTest, topo) {
    ASSERT_ANY_THROW(inteiro.topo());
    inteiro.empilha(600);
    inteiro.empilha(42);
    inteiro.empilha(2600);
    inteiro.empilha(5100);
    inteiro.empilha(42);
    ASSERT_FALSE(inteiro.PilhaVazia());
    ASSERT_EQ(42, inteiro.topo());
    inteiro.limparPilha();
    ASSERT_TRUE(inteiro.PilhaVazia());
    ASSERT_ANY_THROW(inteiro.topo());
    inteiro.empilha(42);
    inteiro.empilha(1995);
    inteiro.empilha(5200);
    inteiro.empilha(7800);
    inteiro.empilha(1995);
    ASSERT_FALSE(inteiro.PilhaVazia());
    ASSERT_EQ(1995, inteiro.topo());
}
