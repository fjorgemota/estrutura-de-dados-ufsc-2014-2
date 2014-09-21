// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "ListaDupEnc.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ListaDupEncTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->obj = ListaDupEnc<Objeto>();
        this->inteiros = ListaDupEnc<int>();
    }

 protected:
     ListaDupEnc<int> inteiros;
     ListaDupEnc<Objeto> obj;
};

TEST_F(ListaDupEncTest, listaVaziaDuplo) {
    ASSERT_TRUE(inteiros.listaVaziaDuplo());
}

TEST_F(ListaDupEncTest, adicionaDuplo) {
    ASSERT_TRUE(inteiros.listaVaziaDuplo());
    inteiros.adicionaDuplo(500);
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(90);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    ASSERT_EQ(0, inteiros.posicaoDuplo(500));
    ASSERT_TRUE(inteiros.contem(500));
    ASSERT_TRUE(inteiros.contem(42));
    ASSERT_TRUE(inteiros.contem(1995));
    ASSERT_TRUE(inteiros.contem(2014));
    ASSERT_TRUE(inteiros.contem(90));
    ASSERT_FALSE(inteiros.contem(2600));
}

TEST_F(ListaDupEncTest, adicionaNoInicioDuplo) {
    ASSERT_TRUE(inteiros.listaVaziaDuplo());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaNaPosicaoDuplo(55, 2);
    inteiros.adicionaNoInicioDuplo(90);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    ASSERT_EQ(0, inteiros.posicaoDuplo(90));
    ASSERT_EQ(1, inteiros.posicaoDuplo(42));
    ASSERT_EQ(2, inteiros.posicaoDuplo(55));
    ASSERT_EQ(3, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(4, inteiros.posicaoDuplo(2014));
    ASSERT_FALSE(inteiros.contem(2600));
}

/*TEST_F(ListaDupEncTest, retiraDoInicioDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaNaPosicaoDuplo(55, 2);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    ASSERT_EQ(42, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(55, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(1995, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(2014, inteiros.retiraDoInicioDuplo());
    ASSERT_TRUE(inteiros.listaVaziaDuplo());
}*/

TEST_F(ListaDupEncTest, retiraDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 2);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    ASSERT_TRUE(inteiros.contem(42));
    ASSERT_EQ(90, inteiros.retiraDuplo());
    ASSERT_EQ(5100, inteiros.retiraDuplo());
    ASSERT_EQ(2014, inteiros.retiraDuplo());
    ASSERT_EQ(1995, inteiros.retiraDuplo());
    ASSERT_EQ(42, inteiros.retiraDuplo());
    ASSERT_EQ(77, inteiros.retiraDuplo());
    ASSERT_EQ(55, inteiros.retiraDuplo());
    ASSERT_TRUE(inteiros.listaVaziaDuplo());
}

TEST_F(ListaDupEncTest, posicaoDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 3);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    ASSERT_EQ(0, inteiros.posicaoDuplo(55));
    ASSERT_EQ(1, inteiros.posicaoDuplo(42));
    ASSERT_EQ(2, inteiros.posicaoDuplo(77));
    ASSERT_EQ(3, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(4, inteiros.posicaoDuplo(2014));
    ASSERT_EQ(5, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(6, inteiros.posicaoDuplo(90));
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
}

TEST_F(ListaDupEncTest, contem) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 3);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    ASSERT_TRUE(inteiros.contem(42));
    ASSERT_TRUE(inteiros.contem(1995));
    ASSERT_TRUE(inteiros.contem(2014));
    ASSERT_TRUE(inteiros.contem(5100));
    ASSERT_TRUE(inteiros.contem(90));
    ASSERT_TRUE(inteiros.contem(55));
    ASSERT_TRUE(inteiros.contem(77));
    ASSERT_FALSE(inteiros.contem(50));
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
}

/*TEST_F(ListaDupEncTest, retiraEspecificoDuplo) {
    ASSERT_TRUE(inteiros.listaVaziaDuplo());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(55);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNaPosicaoDuplo(8, 2);
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
    // ASSERT_EQ(5100, inteiros.retiraEspecificoDuplo(5100));
    ASSERT_EQ(55, inteiros.retiraEspecificoDuplo(55));
    ASSERT_EQ(77, inteiros.retiraEspecificoDuplo(77));
    ASSERT_EQ(8, inteiros.retiraEspecificoDuplo(8));
    ASSERT_ANY_THROW(inteiros.retiraEspecificoDuplo(2600));
    ASSERT_FALSE(inteiros.listaVaziaDuplo());
}*/
