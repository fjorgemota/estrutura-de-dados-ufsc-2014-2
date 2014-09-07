// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "Lista.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ListaTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->inteiro = Lista<int>(10);
        this->valores = Lista<int>();
        this->obj = Lista<Objeto>(10);
    }

 protected:
    Lista<int> inteiro;
    Lista<int> valores;
    Lista<Objeto> obj;
};

TEST_F(ListaTest, listaPadrao) {
    int h;
    for (h = 0; h < 30; h++) {
        valores.adiciona(h);
    }
    ASSERT_EQ(30, valores.pegaTamanho());
}

TEST_F(ListaTest, listaVazia) {
    ASSERT_TRUE(inteiro.listaVazia());
}

TEST_F(ListaTest, adiciona) {
    inteiro.adiciona(900);
    ASSERT_EQ(0, inteiro.pegaTopo());
    inteiro.adiciona(42);
    ASSERT_EQ(1, inteiro.pegaTopo());
}

TEST_F(ListaTest, listaCheia) {
    ASSERT_FALSE(inteiro.listaCheia());
    inteiro.adiciona(2);
    inteiro.adiciona(2);
    inteiro.adiciona(42);
    inteiro.adiciona(5);
    inteiro.adiciona(32);
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    inteiro.adiciona(75);
    ASSERT_TRUE(inteiro.listaCheia());
}

TEST_F(ListaTest, retira) {
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(70);
    inteiro.adiciona(7);
    ASSERT_EQ(7, inteiro.retira());
}

TEST_F(ListaTest, retiraDoInicio) {
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    ASSERT_EQ(45, inteiro.retiraDoInicio());
    ASSERT_EQ(75, inteiro.pegaPrimeiro());
}

TEST_F(ListaTest, contem) {
    inteiro.adiciona(45);
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    ASSERT_FALSE(inteiro.contem(42));
    ASSERT_TRUE(inteiro.contem(75));
}

TEST_F(ListaTest, posicao) {
    inteiro.adiciona(75);
    inteiro.adiciona(6);
    inteiro.adiciona(7);
    ASSERT_EQ(2, inteiro.posicao(7));
    ASSERT_ANY_THROW(inteiro.posicao(1990));
}

TEST_F(ListaTest, igual) {
    inteiro.adiciona(75);
    inteiro.adiciona(100);
    inteiro.adiciona(53);
    inteiro.adiciona(88);
    inteiro.adiciona(75);
    ASSERT_TRUE(inteiro.igual(75, 75));
    ASSERT_FALSE(inteiro.igual(100, 88));
}

TEST_F(ListaTest, retiraEspecifico) {
    inteiro.adiciona(605);
    inteiro.adiciona(123);
    inteiro.adiciona(780);
    inteiro.adiciona(88);
    inteiro.adiciona(76);
    ASSERT_ANY_THROW(inteiro.retiraEspecifico(42));
    inteiro.retiraEspecifico(605);
    ASSERT_FALSE(inteiro.contem(605));
}

TEST_F(ListaTest, adicionaNoInicio) {
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
    ASSERT_EQ(1995, inteiro.pegaPrimeiro());
    ASSERT_TRUE(inteiro.contem(1995));
    ASSERT_ANY_THROW(inteiro.adicionaNoInicio(800));
}

TEST_F(ListaTest, pegaPrimeiro) {
    ASSERT_ANY_THROW(inteiro.pegaPrimeiro());
    inteiro.adiciona(75);
    inteiro.adiciona(64);
    inteiro.adiciona(1);
    inteiro.adiciona(0);
    inteiro.adiciona(42);
    ASSERT_EQ(75, inteiro.pegaPrimeiro());
}

TEST_F(ListaTest, pegaTopo) {
    inteiro.adiciona(75);
    inteiro.adiciona(64);
    inteiro.adiciona(1);
    inteiro.adiciona(0);
    inteiro.adiciona(42);
    ASSERT_EQ(4, inteiro.pegaTopo());
    inteiro.retira();
    ASSERT_EQ(3, inteiro.pegaTopo());
}

TEST_F(ListaTest, maior) {
    inteiro.adiciona(5100);
    inteiro.adiciona(42);
    inteiro.adiciona(6);
    inteiro.adiciona(2600);
    inteiro.adiciona(6);
    ASSERT_TRUE(inteiro.maior(5100, 2600));
    ASSERT_FALSE(inteiro.maior(6, 42));
}

TEST_F(ListaTest, menor) {
    inteiro.adiciona(5100);
    inteiro.adiciona(42);
    inteiro.adiciona(6);
    inteiro.adiciona(2600);
    inteiro.adiciona(6);
    ASSERT_TRUE(inteiro.menor(2600, 5100));
    ASSERT_FALSE(inteiro.menor(42, 6));
}

TEST_F(ListaTest, adicionaNaPosicao) {
    inteiro.adiciona(51);
    inteiro.adiciona(42);
    inteiro.adiciona(900);
    inteiro.adiciona(2600);
    inteiro.adiciona(5100);
    inteiro.adiciona(1995);
    inteiro.adiciona(2015);
    inteiro.adiciona(80363);
    inteiro.adiciona(78);
    inteiro.adicionaNaPosicao(123, 6);
    ASSERT_EQ(123, inteiro.pegaValor(6));
    ASSERT_ANY_THROW(inteiro.adicionaNoInicio(321));
}

TEST_F(ListaTest, retiraDaPosicao) {
    inteiro.adiciona(90);
    inteiro.adiciona(1977);
    inteiro.adiciona(42);
    inteiro.adiciona(304);
    inteiro.adiciona(2001);
    inteiro.adiciona(5100);
    inteiro.adiciona(77);
    ASSERT_EQ(2001, inteiro.retiraDaPosicao(4));
    ASSERT_ANY_THROW(inteiro.retiraDaPosicao(7));
}

TEST_F(ListaTest, destroiLista) {
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
    ASSERT_TRUE(inteiro.listaCheia());
    inteiro.destroiLista();
    ASSERT_TRUE(inteiro.listaVazia());
    ASSERT_EQ(-1, inteiro.pegaTopo());
}

TEST_F(ListaTest, pegaTamanho) {
    inteiro.adiciona(2001);
    inteiro.adiciona(5100);
    inteiro.adiciona(54);
    inteiro.adiciona(123);
    inteiro.adiciona(98);
    inteiro.adiciona(890);
    ASSERT_EQ(6, inteiro.pegaTamanho());
    inteiro.adiciona(65);
    inteiro.adiciona(42);
    inteiro.adiciona(1977);
    inteiro.adiciona(54);
    ASSERT_EQ(10, inteiro.pegaTamanho());
}

TEST_F(ListaTest, pegaUltimo) {
    inteiro.adiciona(2001);
    inteiro.adiciona(5100);
    inteiro.adiciona(54);
    inteiro.adiciona(123);
    inteiro.adiciona(98);
    inteiro.adiciona(890);
    ASSERT_EQ(890, inteiro.pegaUltimo());
    inteiro.retira();
    ASSERT_EQ(98, inteiro.pegaUltimo());
}

TEST_F(ListaTest, pegaValor) {
    inteiro.adiciona(42);
    inteiro.adiciona(1995);
    inteiro.adiciona(5100);
    inteiro.adiciona(1977);
    ASSERT_EQ(42, inteiro.pegaValor(0));
    ASSERT_EQ(1995, inteiro.pegaValor(1));
    ASSERT_EQ(5100, inteiro.pegaValor(2));
    ASSERT_EQ(1977, inteiro.pegaValor(3));
}

TEST_F(ListaTest, troca) {
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

TEST_F(ListaTest, InsertionSort) {
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
    ASSERT_TRUE(inteiro.listaCheia());
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
    ASSERT_TRUE(inteiro.listaCheia());
}

TEST_F(ListaTest, adicionaEmOrdem) {
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
    ASSERT_TRUE(inteiro.listaCheia());
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
    ASSERT_TRUE(inteiro.listaCheia());
}
