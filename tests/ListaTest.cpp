// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "Lista.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ListaTest: public ::testing::Test {
 protected:
    Lista<int> inteiro = Lista<int>(10);
    Lista<Objeto> obj = Lista<Objeto>(10);
};

TEST_F(ListaTest, ListaVazia) {
    ASSERT_TRUE(inteiro.ListaVazia());
}

TEST_F(ListaTest, Adiciona) {
    inteiro.Adiciona(900);
    ASSERT_EQ(0, inteiro.pegaTopo());
    inteiro.Adiciona(42);
    ASSERT_EQ(1, inteiro.pegaTopo());
}

TEST_F(ListaTest, ListaCheia) {
    ASSERT_FALSE(inteiro.ListaCheia());
    inteiro.Adiciona(2);
    inteiro.Adiciona(2);
    inteiro.Adiciona(42);
    inteiro.Adiciona(5);
    inteiro.Adiciona(32);
    inteiro.Adiciona(45);
    inteiro.Adiciona(75);
    inteiro.Adiciona(6);
    inteiro.Adiciona(7);
    inteiro.Adiciona(75);
    ASSERT_TRUE(inteiro.ListaCheia());
}

TEST_F(ListaTest, Retira) {
    inteiro.Adiciona(45);
    inteiro.Adiciona(75);
    inteiro.Adiciona(6);
    inteiro.Adiciona(70);
    inteiro.Adiciona(7);
    ASSERT_EQ(7, inteiro.Retira());
}

TEST_F(ListaTest, RetiraDoInicio) {
    inteiro.Adiciona(45);
    inteiro.Adiciona(75);
    inteiro.Adiciona(6);
    inteiro.Adiciona(7);
    ASSERT_EQ(45, inteiro.RetiraDoInicio());
}

TEST_F(ListaTest, Contem) {
    inteiro.Adiciona(45);
    inteiro.Adiciona(75);
    inteiro.Adiciona(6);
    inteiro.Adiciona(7);
    ASSERT_FALSE(inteiro.Contem(42));
    ASSERT_TRUE(inteiro.Contem(75));
}

TEST_F(ListaTest, Posicao) {
    inteiro.Adiciona(75);
    inteiro.Adiciona(6);
    inteiro.Adiciona(7);
    ASSERT_EQ(2, inteiro.Posicao(7));
    ASSERT_ANY_THROW(inteiro.Posicao(1990));
}

TEST_F(ListaTest, Igual) {
    inteiro.Adiciona(75);
    inteiro.Adiciona(100);
    inteiro.Adiciona(53);
    inteiro.Adiciona(88);
    inteiro.Adiciona(75);
    ASSERT_TRUE(inteiro.Igual(75, 75));
    ASSERT_FALSE(inteiro.Igual(100, 88));
    ASSERT_ANY_THROW(inteiro.Igual(100, 42));
}

TEST_F(ListaTest, RetiraEspecifico) {
    inteiro.Adiciona(605);
    inteiro.Adiciona(123);
    inteiro.Adiciona(780);
    inteiro.Adiciona(88);
    inteiro.Adiciona(76);
    ASSERT_ANY_THROW(inteiro.RetiraEspecifico(42));
    ASSERT_EQ(605, inteiro.RetiraEspecifico(605));
}

TEST_F(ListaTest, AdicionaNoInicio) {
    inteiro.Adiciona(75);
    inteiro.Adiciona(100);
    inteiro.Adiciona(53);
    inteiro.Adiciona(88);
    inteiro.Adiciona(75);
    inteiro.Adiciona(64);
    inteiro.Adiciona(1);
    inteiro.Adiciona(0);
    inteiro.Adiciona(42);
    ASSERT_EQ(0, inteiro.AdicionaNoInicio(1995));
    ASSERT_ANY_THROW(inteiro.AdicionaNoInicio(800));
}

TEST_F(ListaTest, pegaPrimeiro) {
    ASSERT_ANY_THROW(inteiro.pegaPrimeiro());
    inteiro.Adiciona(75);
    inteiro.Adiciona(64);
    inteiro.Adiciona(1);
    inteiro.Adiciona(0);
    inteiro.Adiciona(42);
    ASSERT_EQ(75, inteiro.pegaPrimeiro());
}

TEST_F(ListaTest, pegaTopo) {
    inteiro.Adiciona(75);
    inteiro.Adiciona(64);
    inteiro.Adiciona(1);
    inteiro.Adiciona(0);
    inteiro.Adiciona(42);
    ASSERT_EQ(4, inteiro.pegaTopo());
    inteiro.Retira();
    ASSERT_EQ(3, inteiro.pegaTopo());
}
