// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>

#include "Pilha.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto{};

class PilhaTest: public testing::Test {
 public:
    virtual void SetUp() {
        this->inteiro = Pilha<int>(2);
        this->obj = Pilha<Objeto>();
    }

 protected:
    Pilha<int> inteiro;
    Pilha<Objeto> obj;
};

TEST_F(PilhaTest, PilhaVazia) {
    ASSERT_TRUE(inteiro.PilhaVazia());
}

TEST_F(PilhaTest, PilhaCheia) {
    ASSERT_FALSE(inteiro.PilhaCheia());
}

TEST_F(PilhaTest, empilha) {
    ASSERT_TRUE(inteiro.PilhaVazia());
    ASSERT_FALSE(inteiro.PilhaCheia());
    inteiro.empilha(5);
    inteiro.empilha(2);
    ASSERT_FALSE(inteiro.PilhaVazia());
    ASSERT_TRUE(inteiro.PilhaCheia());
    ASSERT_ANY_THROW(inteiro.empilha(2));
}

TEST_F(PilhaTest, desempilha) {
    ASSERT_TRUE(inteiro.PilhaVazia());
    ASSERT_FALSE(inteiro.PilhaCheia());
    ASSERT_ANY_THROW(inteiro.desempilha());
    inteiro.empilha(5);
    inteiro.empilha(2);
    ASSERT_FALSE(inteiro.PilhaVazia());
    ASSERT_TRUE(inteiro.PilhaCheia());
    ASSERT_EQ(inteiro.desempilha(), 2);
    ASSERT_EQ(inteiro.desempilha(), 5);
}

TEST_F(PilhaTest, getPosTopo) {
    ASSERT_ANY_THROW(inteiro.getPosTopo());
    inteiro.empilha(5);
    ASSERT_EQ(inteiro.getPosTopo(), 0);
    inteiro.empilha(3);
    ASSERT_EQ(inteiro.getPosTopo(), 1);
}

TEST_F(PilhaTest, topo) {
    ASSERT_ANY_THROW(inteiro.topo());
    inteiro.empilha(5);
    ASSERT_EQ(inteiro.topo(), 5);
    inteiro.empilha(3);
    ASSERT_EQ(inteiro.topo(), 3);
}


TEST_F(PilhaTest, inicializaPilha) {
    ASSERT_FALSE(inteiro.PilhaCheia());
    ASSERT_TRUE(inteiro.PilhaVazia());
    inteiro.empilha(5);
    inteiro.empilha(2);
    ASSERT_TRUE(inteiro.PilhaCheia());
    ASSERT_FALSE(inteiro.PilhaVazia());
    inteiro.limparPilha();
    ASSERT_FALSE(inteiro.PilhaCheia());
    ASSERT_TRUE(inteiro.PilhaVazia());
}
