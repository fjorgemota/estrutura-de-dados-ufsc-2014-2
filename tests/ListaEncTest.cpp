// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "ListaEnc.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ListaEncTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->inteiro = ListaEnc<int>();
        this->obj = ListaEnc<Objeto>();
    }

 protected:
    ListaEnc<int> inteiro;
    ListaEnc<int> valores;
    ListaEnc<Objeto> obj;
};

TEST_F(ListaEncTest, listaVazia) {
    ASSERT_TRUE(inteiro.listaVazia());
}

TEST_F(ListaEncTest, retira) {
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(70);
    inteiro.adiciona(7);
    ASSERT_EQ(7, inteiro.retira());
}

TEST_F(ListaEncTest, retiraDoInicio) {
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    ASSERT_EQ(45, inteiro.retiraDoInicio());
}

TEST_F(ListaEncTest, contem) {
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    ASSERT_FALSE(inteiro.contem(42));
    ASSERT_TRUE(inteiro.contem(75));
}

TEST_F(ListaEncTest, posicao) {
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    ASSERT_EQ(2, inteiro.posicao(7));
    ASSERT_EQ(1, inteiro.posicao(6));
    ASSERT_EQ(0, inteiro.posicao(75));
    ASSERT_ANY_THROW(inteiro.posicao(1990));
}

/*
TEST_F(ListaEncTest, posicaoMem) {
    int n = 7;
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(n);
    
    ASSERT_EQ(&n, inteiro.posicaoMem(n));
    ASSERT_ANY_THROW(inteiro.posicaoMem(1990));
}*/

TEST_F(ListaEncTest, igual) {
    inteiro.adiciona(75);
    inteiro.adiciona(100);
    inteiro.adiciona(53);
    inteiro.adiciona(88);
    inteiro.adiciona(75);
    ASSERT_TRUE(inteiro.igual(75, 75));
    ASSERT_FALSE(inteiro.igual(100, 88));
}


TEST_F(ListaEncTest, retiraEspecifico) {
    inteiro.adiciona(605);
    inteiro.adiciona(123);
    inteiro.adiciona(780);
    inteiro.adiciona(88);
    inteiro.adiciona(76);
    ASSERT_ANY_THROW(inteiro.retiraEspecifico(42));
    inteiro.retiraEspecifico(605);
    ASSERT_FALSE(inteiro.contem(605));
}

TEST_F(ListaEncTest, adicionaNoInicio) {
    inteiro.adiciona(75);
    inteiro.adiciona(100);
    inteiro.adiciona(53);
    inteiro.adiciona(88);
    inteiro.adiciona(75);
    inteiro.adiciona(64);
    inteiro.adiciona(1);
    inteiro.adiciona(0);
    inteiro.adiciona(42);
    inteiro.adicionaNoInicio(1995);
    ASSERT_TRUE(inteiro.contem(1995));
    ASSERT_EQ(inteiro.retiraDoInicio(), 1995);
    ASSERT_EQ(inteiro.retiraDoInicio(), 75);
}

TEST_F(ListaEncTest, maior) {
    inteiro.adiciona(5100);
    inteiro.adiciona(42);
    inteiro.adiciona(6);
    inteiro.adiciona(2600);
    inteiro.adiciona(6);
    ASSERT_TRUE(inteiro.maior(5100, 2600));
    ASSERT_FALSE(inteiro.maior(6, 42));
}

TEST_F(ListaEncTest, menor) {
    inteiro.adiciona(5100);
    inteiro.adiciona(42);
    inteiro.adiciona(6);
    inteiro.adiciona(2600);
    inteiro.adiciona(6);
    ASSERT_TRUE(inteiro.menor(2600, 5100));
    ASSERT_FALSE(inteiro.menor(42, 6));
}


TEST_F(ListaEncTest, adicionaNaPosicao) {
    inteiro.adiciona(51);
    inteiro.adiciona(42);
    inteiro.adiciona(900);
    inteiro.adiciona(2600);
    inteiro.adiciona(5100);
    inteiro.adiciona(1995);
    inteiro.adiciona(2015);
    inteiro.adiciona(80363);
    inteiro.adiciona(78);
    inteiro.adicionaNaPosicao(123, 1);
    ASSERT_EQ(123, inteiro.retiraDoInicio());
    inteiro.adicionaNaPosicao(43, 2);
    ASSERT_EQ(51, inteiro.retiraDoInicio());
    ASSERT_EQ(43, inteiro.retiraDoInicio());
    ASSERT_EQ(42, inteiro.retiraDoInicio());
    inteiro.adicionaNaPosicao(50, 3);
    ASSERT_EQ(900, inteiro.retiraDoInicio());
    ASSERT_EQ(2600, inteiro.retiraDoInicio());
    ASSERT_EQ(50, inteiro.retiraDoInicio());
}


TEST_F(ListaEncTest, retiraDaPosicao) {
    inteiro.adiciona(90); // 0
    inteiro.adiciona(1977); // 1
    inteiro.adiciona(42); // 2
    inteiro.adiciona(304); // 3
    inteiro.adiciona(2001); // 4
    inteiro.adiciona(5100); // 5
    inteiro.adiciona(77); // 6
    ASSERT_EQ(2001, inteiro.retiraDaPosicao(4));
    ASSERT_EQ(304, inteiro.retiraDaPosicao(3));
    ASSERT_EQ(5100, inteiro.retiraDaPosicao(3));
    ASSERT_ANY_THROW(inteiro.retiraDaPosicao(7));
    ASSERT_EQ(90, inteiro.retiraDoInicio());
    ASSERT_EQ(1977, inteiro.retiraDoInicio());
    ASSERT_EQ(42, inteiro.retiraDoInicio());
    ASSERT_EQ(77, inteiro.retiraDoInicio());
}

/*TEST_F(ListaEncTest, destroiLista) {
    inteiro.adiciona(90);
    inteiro.adiciona(1977);
    inteiro.adiciona(42);
    inteiro.adiciona(304);
    inteiro.adiciona(2001);
    inteiro.adiciona(5100);
    inteiro.adiciona(77);
    inteiro.adiciona(79);
    inteiro.adiciona(3000);
    inteiro.adiciona(890);
    inteiro.destroiLista();
    ASSERT_TRUE(inteiro.listaVazia());
}*/

TEST_F(ListaEncTest, adicionaEmOrdem) {
    inteiro.adiciona(42);
    inteiro.adiciona(7);
    inteiro.adiciona(1995);
    inteiro.adiciona(90);
    inteiro.adiciona(5100);
    inteiro.adiciona(1977);
    inteiro.adicionaEmOrdem(25);
    ASSERT_EQ(0, inteiro.posicao(25));
    ASSERT_EQ(1, inteiro.posicao(42));
    ASSERT_EQ(2, inteiro.posicao(7));
    ASSERT_EQ(3, inteiro.posicao(1995));
    ASSERT_EQ(4, inteiro.posicao(90));
    ASSERT_EQ(5, inteiro.posicao(5100));
    ASSERT_EQ(6, inteiro.posicao(1977));
}

/*TEST_F(ListaEncTest, InsertionSort) {
    inteiro.adiciona(42);
    inteiro.adiciona(7);
    inteiro.adiciona(1995);
    inteiro.adiciona(90);
    inteiro.adiciona(5100);
    inteiro.adiciona(1977);
    inteiro.insertionSort();
    ASSERT_EQ(0, inteiro.posicao(7));
    ASSERT_EQ(1, inteiro.posicao(42));
    ASSERT_EQ(2, inteiro.posicao(90));
    ASSERT_EQ(3, inteiro.posicao(1977));
    ASSERT_EQ(4, inteiro.posicao(1995));
    ASSERT_EQ(5, inteiro.posicao(5100));
}*/

/*
TEST_F(ListaEncTest, troca) {
    inteiro.adiciona(2001);
    inteiro.adiciona(5100);
    inteiro.adiciona(54);
    inteiro.adiciona(123);
    inteiro.adiciona(42);
    inteiro.adiciona(890);
    inteiro.troca(1, 4);
    ASSERT_EQ(42, inteiro.pegaValor(1));
    ASSERT_EQ(5100, inteiro.pegaValor(4));
}

TEST_F(ListaEncTest, InsertionSort) {
    inteiro.adiciona(42);
    inteiro.adiciona(7);
    inteiro.adiciona(1995);
    inteiro.adiciona(90);
    inteiro.adiciona(5100);
    inteiro.adiciona(1977);
    inteiro.adiciona(50);
    inteiro.adiciona(7);
    inteiro.adiciona(20);
    inteiro.adiciona(45);
    inteiro.insertionSort();
    ASSERT_EQ(7, inteiro.pegaPrimeiro());
    ASSERT_EQ(7, inteiro.pegaValor(1));
    ASSERT_EQ(20, inteiro.pegaValor(2));
    ASSERT_EQ(42, inteiro.pegaValor(3));
    ASSERT_EQ(45, inteiro.pegaValor(4));
    ASSERT_EQ(50, inteiro.pegaValor(5));
    ASSERT_EQ(90, inteiro.pegaValor(6));
    ASSERT_EQ(1977, inteiro.pegaValor(7));
    ASSERT_EQ(1995, inteiro.pegaValor(8));
    ASSERT_EQ(5100, inteiro.pegaUltimo());
}

TEST_F(ListaEncTest, adicionaEmOrdem) {
    inteiro.adiciona(42);
    inteiro.adiciona(7);
    inteiro.adiciona(1995);
    inteiro.adiciona(90);
    inteiro.adiciona(5100);
    inteiro.adiciona(14);
    inteiro.adiciona(50);
    inteiro.adiciona(5);
    inteiro.adiciona(20);
    inteiro.adicionaEmOrdem(25);
    ASSERT_EQ(5, inteiro.pegaPrimeiro());
    ASSERT_EQ(7, inteiro.pegaValor(1));
    ASSERT_EQ(14, inteiro.pegaValor(2));
    ASSERT_EQ(20, inteiro.pegaValor(3));
    ASSERT_EQ(25, inteiro.pegaValor(4));
    ASSERT_EQ(42, inteiro.pegaValor(5));
    ASSERT_EQ(50, inteiro.pegaValor(6));
    ASSERT_EQ(90, inteiro.pegaValor(7));
    ASSERT_EQ(1995, inteiro.pegaValor(8));
    ASSERT_EQ(5100, inteiro.pegaUltimo());
}*/
