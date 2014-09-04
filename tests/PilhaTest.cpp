// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>

#include "Pilha.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto{};

class PilhaTest: public testing::Test {
 protected:
    Pilha<int> i = Pilha<int>(2);
    Pilha<Objeto> o = Pilha<Objeto>();
};

TEST_F(PilhaTest, PilhaVazia) {
    ASSERT_TRUE(i.PilhaVazia());
}

TEST_F(PilhaTest, PilhaCheia) {
    ASSERT_FALSE(i.PilhaCheia());
}

TEST_F(PilhaTest, empilha) {
    ASSERT_TRUE(i.PilhaVazia());
    ASSERT_FALSE(i.PilhaCheia());
    i.empilha(5);
    i.empilha(2);
    ASSERT_FALSE(i.PilhaVazia());
    ASSERT_TRUE(i.PilhaCheia());
    ASSERT_ANY_THROW(i.empilha(2));
}

TEST_F(PilhaTest, desempilha) {
    ASSERT_TRUE(i.PilhaVazia());
    ASSERT_FALSE(i.PilhaCheia());
    ASSERT_ANY_THROW(i.desempilha());
    i.empilha(5);
    i.empilha(2);
    ASSERT_FALSE(i.PilhaVazia());
    ASSERT_TRUE(i.PilhaCheia());
    ASSERT_EQ(i.desempilha(), 2);
    ASSERT_EQ(i.desempilha(), 5);
}

TEST_F(PilhaTest, getPosTopo) {
    ASSERT_ANY_THROW(i.getPosTopo());
    i.empilha(5);
    ASSERT_EQ(i.getPosTopo(), 0);
    i.empilha(3);
    ASSERT_EQ(i.getPosTopo(), 1);
}

TEST_F(PilhaTest, topo) {
    ASSERT_ANY_THROW(i.topo());
    i.empilha(5);
    ASSERT_EQ(i.topo(), 5);
    i.empilha(3);
    ASSERT_EQ(i.topo(), 3);
}


TEST_F(PilhaTest, inicializaPilha) {
    ASSERT_FALSE(i.PilhaCheia());
    ASSERT_TRUE(i.PilhaVazia());
    i.empilha(5);
    i.empilha(2);
    ASSERT_TRUE(i.PilhaCheia());
    ASSERT_FALSE(i.PilhaVazia());
    i.limparPilha();
    ASSERT_FALSE(i.PilhaCheia());
    ASSERT_TRUE(i.PilhaVazia());
}
