// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>

#include "Fila.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto{};

class FilaTest: public testing::Test {
 public:
    virtual void SetUp() {
        this->obj = Fila<Objeto>();
        this->inteiro = Fila<int>(2);
    }

 protected:
    Fila<int> inteiro;
    Fila<Objeto> obj;
};

TEST_F(FilaTest, FilaVazia) {
    ASSERT_TRUE(inteiro.filaVazia());
}

TEST_F(FilaTest, FilaCheia) {
    ASSERT_FALSE(inteiro.filaCheia());
}

TEST_F(FilaTest, inclui) {
    ASSERT_TRUE(inteiro.filaVazia());
    ASSERT_FALSE(inteiro.filaCheia());
    inteiro.inclui(5);
    ASSERT_EQ(inteiro.ultimo(), 5);
    inteiro.inclui(2);
    ASSERT_EQ(inteiro.ultimo(), 2);
    ASSERT_FALSE(inteiro.filaVazia());
    ASSERT_TRUE(inteiro.filaCheia());
    ASSERT_ANY_THROW(inteiro.inclui(3));
}

TEST_F(FilaTest, retira) {
    ASSERT_TRUE(inteiro.filaVazia());
    ASSERT_FALSE(inteiro.filaCheia());
    ASSERT_ANY_THROW(inteiro.retira());
    inteiro.inclui(5);
    inteiro.inclui(2);
    ASSERT_FALSE(inteiro.filaVazia());
    ASSERT_TRUE(inteiro.filaCheia());
    ASSERT_EQ(inteiro.retira(), 5);
    ASSERT_EQ(inteiro.retira(), 2);
}

TEST_F(FilaTest, getUltimo) {
    ASSERT_EQ(inteiro.getUltimo(), -1);
    inteiro.inclui(5);
    ASSERT_EQ(inteiro.getUltimo(), 0);
    inteiro.inclui(3);
    ASSERT_EQ(inteiro.getUltimo(), 1);
}

TEST_F(FilaTest, ultimo) {
    ASSERT_ANY_THROW(inteiro.ultimo());
    inteiro.inclui(5);
    ASSERT_EQ(inteiro.ultimo(), 5);
    inteiro.inclui(3);
    ASSERT_EQ(inteiro.ultimo(), 3);
}

TEST_F(FilaTest, inicializaFila) {
    ASSERT_FALSE(inteiro.filaCheia());
    ASSERT_TRUE(inteiro.filaVazia());
    inteiro.inclui(5);
    inteiro.inclui(2);
    ASSERT_TRUE(inteiro.filaCheia());
    ASSERT_FALSE(inteiro.filaVazia());
    inteiro.inicializaFila();
    ASSERT_FALSE(inteiro.filaCheia());
    ASSERT_TRUE(inteiro.filaVazia());
}
