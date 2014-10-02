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
    inteiro.inclui(2);
    inteiro.inclui(4);
    inteiro.inclui(8);
    inteiro.inclui(12);
    ASSERT_EQ(inteiro.retira(), 2);
    ASSERT_EQ(inteiro.retira(), 4);
    ASSERT_EQ(inteiro.retira(), 8);
    ASSERT_EQ(inteiro.retira(), 12);
}

TEST_F(FilaEncTest, retira) {
    inteiro.inclui(3);
    inteiro.inclui(9);
    inteiro.inclui(12);
    inteiro.inclui(6);
    ASSERT_EQ(inteiro.retira(), 3);
    ASSERT_EQ(inteiro.retira(), 9);
    ASSERT_EQ(inteiro.retira(), 12);
    ASSERT_EQ(inteiro.retira(), 6);
}

TEST_F(FilaEncTest, retiraDoInicio) {
    inteiro.inclui(3);
    inteiro.inclui(9);
    inteiro.inclui(12);
    inteiro.inclui(6);
    ASSERT_EQ(inteiro.retiraDoInicio(), 6);
    ASSERT_EQ(inteiro.retiraDoInicio(), 12);
    ASSERT_EQ(inteiro.retiraDoInicio(), 9);
    ASSERT_EQ(inteiro.retiraDoInicio(), 3);
}

TEST_F(FilaEncTest, limparFila) {
    ASSERT_TRUE(inteiro.filaVazia());
    inteiro.inclui(42);
    inteiro.inclui(5100);
    inteiro.inclui(1995);
    inteiro.inclui(90);
    inteiro.inclui(2600);
    inteiro.inclui(5200);
    ASSERT_FALSE(inteiro.filaVazia());
    inteiro.retira();
    inteiro.retira();
    ASSERT_FALSE(inteiro.filaVazia());
    inteiro.limparFila();
    ASSERT_TRUE(inteiro.filaVazia());
}

TEST_F(FilaEncTest, primeiro) {
    ASSERT_ANY_THROW(inteiro.primeiro());
    ASSERT_TRUE(inteiro.filaVazia());
    inteiro.inclui(42);
    inteiro.inclui(5100);
    inteiro.inclui(1995);
    inteiro.inclui(90);
    inteiro.inclui(2600);
    inteiro.inclui(5200);
    ASSERT_FALSE(inteiro.filaVazia());
    ASSERT_EQ(42, inteiro.primeiro());
    inteiro.retira();
    ASSERT_EQ(5100, inteiro.primeiro());
    inteiro.retira();
    ASSERT_EQ(1995, inteiro.primeiro());
    inteiro.retira();
    ASSERT_EQ(90, inteiro.primeiro());
    inteiro.retira();
    ASSERT_EQ(2600, inteiro.primeiro());
    inteiro.retira();
    ASSERT_EQ(5200, inteiro.primeiro());
    inteiro.retira();
    ASSERT_TRUE(inteiro.filaVazia());
    ASSERT_ANY_THROW(inteiro.primeiro());
}

TEST_F(FilaEncTest, ultimo) {
    ASSERT_ANY_THROW(inteiro.ultimo());
    ASSERT_TRUE(inteiro.filaVazia());
    inteiro.inclui(42);
    inteiro.inclui(5100);
    inteiro.inclui(1995);
    inteiro.inclui(90);
    inteiro.inclui(2600);
    inteiro.inclui(5200);
    ASSERT_EQ(5200, inteiro.ultimo());
    inteiro.inclui(80);
    ASSERT_EQ(80, inteiro.ultimo());
    inteiro.retira();
    ASSERT_EQ(80, inteiro.ultimo());
}
