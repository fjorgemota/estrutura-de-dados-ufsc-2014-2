// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "ListaDupla.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ListaDuplaTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->obj = ListaDupla<Objeto>();
        this->inteiros = ListaDupla<int>();
    }

 protected:
     ListaDupla<int> inteiros;
     ListaDupla<Objeto> obj;
};

TEST_F(ListaDuplaTest, listaVaziaDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, adicionaDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(500);
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(90);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(500));
    ASSERT_TRUE(inteiros.contemDuplo(500));
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_TRUE(inteiros.contemDuplo(1995));
    ASSERT_TRUE(inteiros.contemDuplo(2014));
    ASSERT_TRUE(inteiros.contemDuplo(90));
    ASSERT_FALSE(inteiros.contemDuplo(2600));
}

TEST_F(ListaDuplaTest, adicionaNoInicioDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaNaPosicaoDuplo(55, 2);
    inteiros.adicionaNoInicioDuplo(90);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(90));
    ASSERT_EQ(1, inteiros.posicaoDuplo(42));
    ASSERT_EQ(2, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(3, inteiros.posicaoDuplo(55));
    ASSERT_EQ(4, inteiros.posicaoDuplo(2014));
    ASSERT_FALSE(inteiros.contemDuplo(2600));
}

TEST_F(ListaDuplaTest, adicionaNaPosicaoDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaNaPosicaoDuplo(2, 0);
    inteiros.adicionaNaPosicaoDuplo(90, 1);
    inteiros.adicionaNaPosicaoDuplo(95, 1);
    inteiros.adicionaNaPosicaoDuplo(80, 3);
    inteiros.adicionaNaPosicaoDuplo(2014, 4);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(2));
    ASSERT_EQ(1, inteiros.posicaoDuplo(95));
    ASSERT_EQ(2, inteiros.posicaoDuplo(90));
    ASSERT_EQ(3, inteiros.posicaoDuplo(80));
    ASSERT_EQ(4, inteiros.posicaoDuplo(2014));
}

TEST_F(ListaDuplaTest, adicionaEmOrdemDuplo) {
    inteiros.adicionaEmOrdem(2);
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(7);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(1977);
    inteiros.adicionaEmOrdem(25);
    ASSERT_EQ(0, inteiros.posicaoDuplo(2));
    ASSERT_EQ(1, inteiros.posicaoDuplo(25));
    ASSERT_EQ(2, inteiros.posicaoDuplo(42));
    ASSERT_EQ(3, inteiros.posicaoDuplo(7));
    ASSERT_EQ(4, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(5, inteiros.posicaoDuplo(90));
    ASSERT_EQ(6, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(7, inteiros.posicaoDuplo(1977));
}

TEST_F(ListaDuplaTest, eliminaDoInicioDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaNaPosicaoDuplo(55, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(42, inteiros.mostra(0));
    ASSERT_NO_THROW(inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(1995, inteiros.mostra(0));
    ASSERT_NO_THROW(inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(55, inteiros.mostra(0));
    ASSERT_NO_THROW(inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(2014, inteiros.mostra(0));
    ASSERT_NO_THROW(inteiros.retiraDoInicioDuplo());
    ASSERT_ANY_THROW(inteiros.retiraDoInicioDuplo());
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, retiraDoInicioDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaNaPosicaoDuplo(55, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(42, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(1995, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(55, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(2014, inteiros.retiraDoInicioDuplo());
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, retiraDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_EQ(90, inteiros.retiraDuplo());
    ASSERT_EQ(5100, inteiros.retiraDuplo());
    ASSERT_EQ(2014, inteiros.retiraDuplo());
    ASSERT_EQ(1995, inteiros.retiraDuplo());
    ASSERT_EQ(77, inteiros.retiraDuplo());
    ASSERT_EQ(42, inteiros.retiraDuplo());
    ASSERT_EQ(55, inteiros.retiraDuplo());
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, destroiListaDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_TRUE(inteiros.contemDuplo(42));
    inteiros.destroiListaDuplo();
    ASSERT_ANY_THROW(inteiros.contemDuplo(42));
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, posicaoDuplo) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 3);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(55));
    ASSERT_EQ(1, inteiros.posicaoDuplo(42));
    ASSERT_EQ(2, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(3, inteiros.posicaoDuplo(77));
    ASSERT_EQ(4, inteiros.posicaoDuplo(2014));
    ASSERT_EQ(5, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(6, inteiros.posicaoDuplo(90));
    ASSERT_ANY_THROW(inteiros.posicaoDuplo(1556));
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, mostra) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 3);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_ANY_THROW(inteiros.mostra(-1));
    ASSERT_EQ(55, inteiros.mostra(0));
    ASSERT_EQ(42, inteiros.mostra(1));
    ASSERT_EQ(1995, inteiros.mostra(2));
    ASSERT_EQ(77, inteiros.mostra(3));
    ASSERT_EQ(2014, inteiros.mostra(4));
    ASSERT_EQ(5100, inteiros.mostra(5));
    ASSERT_EQ(90, inteiros.mostra(6));
    ASSERT_ANY_THROW(inteiros.mostra(7));
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, verUltimo) {
    ASSERT_ANY_THROW(inteiros.verUltimo());
    inteiros.adicionaDuplo(42);
    ASSERT_EQ(0, inteiros.verUltimo());
    inteiros.adicionaDuplo(1995);
    ASSERT_EQ(1, inteiros.verUltimo());
    inteiros.adicionaDuplo(2014);
    ASSERT_EQ(2, inteiros.verUltimo());
    inteiros.adicionaDuplo(5100);
    ASSERT_EQ(3, inteiros.verUltimo());
    inteiros.adicionaDuplo(90);
    ASSERT_EQ(4, inteiros.verUltimo());
    inteiros.adicionaNoInicioDuplo(55);
    ASSERT_EQ(5, inteiros.verUltimo());
    inteiros.adicionaNaPosicaoDuplo(77, 3);
    ASSERT_EQ(6, inteiros.verUltimo());
}

TEST_F(ListaDuplaTest, contem) {
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(2014);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaNoInicioDuplo(55);
    inteiros.adicionaNaPosicaoDuplo(77, 3);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_TRUE(inteiros.contemDuplo(1995));
    ASSERT_TRUE(inteiros.contemDuplo(2014));
    ASSERT_TRUE(inteiros.contemDuplo(5100));
    ASSERT_TRUE(inteiros.contemDuplo(90));
    ASSERT_TRUE(inteiros.contemDuplo(55));
    ASSERT_TRUE(inteiros.contemDuplo(77));
    ASSERT_FALSE(inteiros.contemDuplo(50));
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, retiraEspecificoDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(55);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNaPosicaoDuplo(8, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(5100, inteiros.retiraEspecificoDuplo(5100));
    ASSERT_EQ(55, inteiros.retiraEspecificoDuplo(55));
    ASSERT_EQ(77, inteiros.retiraEspecificoDuplo(77));
    ASSERT_EQ(8, inteiros.retiraEspecificoDuplo(8));
    ASSERT_EQ(42, inteiros.retiraEspecificoDuplo(42));
    ASSERT_EQ(1995, inteiros.retiraEspecificoDuplo(1995));
    ASSERT_ANY_THROW(inteiros.retiraEspecificoDuplo(2600));
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, maior) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(55);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNaPosicaoDuplo(8, 2);
    ASSERT_TRUE(inteiros.maior(1995, 42));
    ASSERT_FALSE(inteiros.maior(42, 5100));
    ASSERT_FALSE(inteiros.maior(55, 5100));
    inteiros.adicionaDuplo(77);
    ASSERT_TRUE(inteiros.maior(77, 42));
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, menor) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(55);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNaPosicaoDuplo(8, 2);
    ASSERT_FALSE(inteiros.menor(1995, 42));
    ASSERT_TRUE(inteiros.menor(42, 5100));
    ASSERT_TRUE(inteiros.menor(55, 5100));
    inteiros.adicionaDuplo(77);
    ASSERT_FALSE(inteiros.menor(5100, 77));
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaTest, igual) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(55);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNaPosicaoDuplo(8, 2);
    inteiros.adicionaNaPosicaoDuplo(42, 4);
    ASSERT_FALSE(inteiros.igual(1995, 42));
    ASSERT_TRUE(inteiros.igual(42, 42));
    ASSERT_FALSE(inteiros.igual(55, 5100));
    inteiros.adicionaDuplo(5100);
    ASSERT_TRUE(inteiros.igual(5100, 5100));
    ASSERT_FALSE(inteiros.listaVazia());
}
