// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>

#include "Fila.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto{};

class FilaTest: public testing::Test {
 protected:
    Fila<int> i = Fila<int>(2);
    Fila<Objeto> o = Fila<Objeto>();
};

TEST_F(FilaTest, FilaVazia) {
    ASSERT_TRUE(i.filaVazia());
}

TEST_F(FilaTest, FilaCheia) {
    ASSERT_FALSE(i.filaCheia());
}

TEST_F(FilaTest, inclui) {
    ASSERT_TRUE(i.filaVazia());
    ASSERT_FALSE(i.filaCheia());
    i.inclui(5);
    ASSERT_EQ(i.ultimo(), 5);
    i.inclui(2);
    ASSERT_EQ(i.ultimo(), 2);
    ASSERT_FALSE(i.filaVazia());
    ASSERT_TRUE(i.filaCheia());
    ASSERT_ANY_THROW(i.inclui(3));
}

TEST_F(FilaTest, retira) {
    ASSERT_TRUE(i.filaVazia());
    ASSERT_FALSE(i.filaCheia());
    ASSERT_ANY_THROW(i.retira());
    i.inclui(5);
    i.inclui(2);
    ASSERT_FALSE(i.filaVazia());
    ASSERT_TRUE(i.filaCheia());
    ASSERT_EQ(i.retira(), 5);
    ASSERT_EQ(i.retira(), 2);
}

TEST_F(FilaTest, getUltimo) {
    ASSERT_EQ(i.getUltimo(), -1);
    i.inclui(5);
    ASSERT_EQ(i.getUltimo(), 0);
    i.inclui(3);
    ASSERT_EQ(i.getUltimo(), 1);
}

TEST_F(FilaTest, ultimo) {
    ASSERT_ANY_THROW(i.ultimo());
    i.inclui(5);
    ASSERT_EQ(i.ultimo(), 5);
    i.inclui(3);
    ASSERT_EQ(i.ultimo(), 3);
}

TEST_F(FilaTest, inicializaFila) {
    ASSERT_FALSE(i.filaCheia());
    ASSERT_TRUE(i.filaVazia());
    i.inclui(5);
    i.inclui(2);
    ASSERT_TRUE(i.filaCheia());
    ASSERT_FALSE(i.filaVazia());
    i.inicializaFila();
    ASSERT_FALSE(i.filaCheia());
    ASSERT_TRUE(i.filaVazia());
}
