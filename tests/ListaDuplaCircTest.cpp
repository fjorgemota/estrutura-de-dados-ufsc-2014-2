// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "ListaDuplaCirc.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto{};

class ListaDuplaCircTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->obj = ListaDuplaCirc<Objeto>();
        this->inteiros = ListaDuplaCirc<int>();
    }

 protected:
    ListaDuplaCirc<int> inteiros;
    ListaDuplaCirc<Objeto> obj;
};

TEST_F(ListaDuplaCircTest, adicionaDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(2500);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(5200);
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_TRUE(inteiros.contemDuplo(5100));
    ASSERT_TRUE(inteiros.contemDuplo(2500));
    ASSERT_TRUE(inteiros.contemDuplo(90));
    ASSERT_FALSE(inteiros.contemDuplo(2600));
    // inteiros.imprimeLista();
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaCircTest, adicionaNaPosicaoDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaNaPosicaoDuplo(5200, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(42));
    // inteiros.imprimeLista();
    ASSERT_EQ(1, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(2, inteiros.posicaoDuplo(5200));
    ASSERT_EQ(3, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(4, inteiros.posicaoDuplo(90));
    ASSERT_EQ(5, inteiros.posicaoDuplo(80));
}

TEST_F(ListaDuplaCircTest, adicionaNoInicioDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(54);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(42));
    ASSERT_EQ(1, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(2, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(3, inteiros.posicaoDuplo(90));
    ASSERT_EQ(4, inteiros.posicaoDuplo(80));
    ASSERT_EQ(5, inteiros.posicaoDuplo(54));
    ASSERT_NO_THROW(inteiros.adicionaNoInicioDuplo(5200));
    ASSERT_EQ(0, inteiros.posicaoDuplo(5200));
    ASSERT_NO_THROW(inteiros.adicionaNoInicioDuplo(66));
    ASSERT_EQ(0, inteiros.posicaoDuplo(66));
    ASSERT_NO_THROW(inteiros.retiraDoInicioDuplo());
    ASSERT_FALSE(inteiros.contemDuplo(66));
    ASSERT_EQ(0, inteiros.posicaoDuplo(5200));
}

TEST_F(ListaDuplaCircTest, retiraDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNoInicioDuplo(15);
    inteiros.adicionaNaPosicaoDuplo(500, 3);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(15));
    ASSERT_EQ(1, inteiros.posicaoDuplo(42));
    ASSERT_EQ(2, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(3, inteiros.posicaoDuplo(500));
    ASSERT_EQ(4, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(5, inteiros.posicaoDuplo(90));
    ASSERT_EQ(6, inteiros.posicaoDuplo(80));
    ASSERT_EQ(7, inteiros.posicaoDuplo(77));
    // inteiros.imprimeLista();
    ASSERT_EQ(77, inteiros.retiraDuplo());
    ASSERT_EQ(80, inteiros.retiraDuplo());
    ASSERT_EQ(90, inteiros.retiraDuplo());
    ASSERT_EQ(5100, inteiros.retiraDuplo());
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(0, inteiros.posicaoDuplo(15));
    ASSERT_EQ(1, inteiros.posicaoDuplo(42));
    ASSERT_EQ(2, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(3, inteiros.posicaoDuplo(500));
    ASSERT_FALSE(inteiros.contemDuplo(5100));
    ASSERT_FALSE(inteiros.contemDuplo(90));
    ASSERT_FALSE(inteiros.contemDuplo(80));
    ASSERT_FALSE(inteiros.contemDuplo(77));
    // inteiros.imprimeLista();
}

TEST_F(ListaDuplaCircTest, retiraDoInicioDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNoInicioDuplo(15);
    inteiros.adicionaNaPosicaoDuplo(2600, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(15, inteiros.retiraDoInicioDuplo());
    ASSERT_EQ(77, inteiros.retiraDuplo());
    ASSERT_EQ(42, inteiros.retiraDoInicioDuplo());
    ASSERT_TRUE(inteiros.contemDuplo(1995));
    ASSERT_TRUE(inteiros.contemDuplo(5100));
    ASSERT_TRUE(inteiros.contemDuplo(90));
    ASSERT_TRUE(inteiros.contemDuplo(80));
    // inteiros.imprimeLista();
}

TEST_F(ListaDuplaCircTest, retiraDaPosicaoDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNoInicioDuplo(15);
    inteiros.adicionaNaPosicaoDuplo(2600, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(5100, inteiros.retiraDaPosicaoDuplo(4));
    ASSERT_EQ(80, inteiros.retiraDaPosicaoDuplo(5));
    ASSERT_FALSE(inteiros.contemDuplo(5100));
    ASSERT_FALSE(inteiros.contemDuplo(80));
    // inteiros.imprimeLista();
}

TEST_F(ListaDuplaCircTest, retiraEspecificoDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNoInicioDuplo(15);
    inteiros.adicionaNaPosicaoDuplo(2600, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_EQ(1995, inteiros.retiraEspecificoDuplo(1995));
    ASSERT_EQ(90, inteiros.retiraEspecificoDuplo(90));
    ASSERT_ANY_THROW(inteiros.retiraEspecificoDuplo(7800));
    ASSERT_ANY_THROW(inteiros.posicaoDuplo(6));
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_FALSE(inteiros.contemDuplo(1995));
    ASSERT_TRUE(inteiros.contemDuplo(5100));
    ASSERT_TRUE(inteiros.contemDuplo(80));
    ASSERT_TRUE(inteiros.contemDuplo(77));
    ASSERT_TRUE(inteiros.contemDuplo(15));
    ASSERT_FALSE(inteiros.contemDuplo(90));
    // inteiros.imprimeLista();
}

TEST_F(ListaDuplaCircTest, adicionaEmOrdemDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaNoInicioDuplo(15);
    inteiros.adicionaNaPosicaoDuplo(2600, 2);
    inteiros.adicionaEmOrdem(50);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_NO_THROW(inteiros.adicionaEmOrdem(5000));
    ASSERT_NO_THROW(inteiros.adicionaEmOrdem(2800));
    ASSERT_TRUE(inteiros.contemDuplo(5000));
    ASSERT_TRUE(inteiros.contemDuplo(2800));
    ASSERT_TRUE(inteiros.contemDuplo(50));
    ASSERT_TRUE(inteiros.contemDuplo(2600));
    ASSERT_EQ(80, inteiros.retiraDuplo());
    ASSERT_EQ(5000, inteiros.retiraDaPosicaoDuplo(6));
    ASSERT_EQ(1995, inteiros.retiraEspecificoDuplo(1995));
    ASSERT_ANY_THROW(inteiros.adicionaNaPosicaoDuplo(55, 7));
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaDuplo(51);
    ASSERT_EQ(7, inteiros.verUltimo());
    // inteiros.imprimeLista();
}

TEST_F(ListaDuplaCircTest, mostra) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(51);
    inteiros.adicionaDuplo(80);
    ASSERT_NO_THROW(inteiros.adicionaNaPosicaoDuplo(2600, 2));
    ASSERT_ANY_THROW(inteiros.adicionaNaPosicaoDuplo(2600, -1));
    ASSERT_EQ(42, inteiros.mostra(0));
    ASSERT_EQ(5100, inteiros.mostra(1));
    ASSERT_EQ(2600, inteiros.mostra(2));
    ASSERT_EQ(90, inteiros.mostra(3));
    ASSERT_EQ(51, inteiros.mostra(4));
    ASSERT_EQ(80, inteiros.mostra(5));
    inteiros.retiraDuplo();
    ASSERT_ANY_THROW(inteiros.mostra(5));
    inteiros.adicionaNaPosicaoDuplo(5200, 3);
    ASSERT_EQ(42, inteiros.mostra(0));
    ASSERT_EQ(5100, inteiros.mostra(1));
    ASSERT_EQ(2600, inteiros.mostra(2));
    ASSERT_EQ(5200, inteiros.mostra(3));
    ASSERT_EQ(90, inteiros.mostra(4));
    ASSERT_EQ(51, inteiros.mostra(5));
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaCircTest, posicaoDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(51);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(75);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_NO_THROW(inteiros.adicionaEmOrdem(77));
    ASSERT_NO_THROW(inteiros.adicionaNaPosicaoDuplo(1995, 4));
    ASSERT_EQ(0, inteiros.posicaoDuplo(42));
    ASSERT_EQ(1, inteiros.posicaoDuplo(77));
    ASSERT_EQ(2, inteiros.posicaoDuplo(5100));
    ASSERT_EQ(3, inteiros.posicaoDuplo(90));
    ASSERT_EQ(4, inteiros.posicaoDuplo(1995));
    ASSERT_EQ(5, inteiros.posicaoDuplo(51));
    ASSERT_EQ(6, inteiros.posicaoDuplo(80));
    ASSERT_EQ(7, inteiros.posicaoDuplo(75));
    ASSERT_ANY_THROW(inteiros.posicaoDuplo(94));
}

TEST_F(ListaDuplaCircTest, posicaoMemDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(51);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(75);
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaCircTest, contemDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(543);
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_TRUE(inteiros.contemDuplo(5100));
    ASSERT_TRUE(inteiros.contemDuplo(90));
    ASSERT_TRUE(inteiros.contemDuplo(543));
    inteiros.adicionaEmOrdem(50);
    ASSERT_TRUE(inteiros.contemDuplo(50));
    ASSERT_FALSE(inteiros.contemDuplo(77));
    ASSERT_FALSE(inteiros.contemDuplo(1995));
    inteiros.adicionaNaPosicaoDuplo(77, 2);
    ASSERT_TRUE(inteiros.contemDuplo(77));
    ASSERT_NO_THROW(inteiros.retiraDuplo());
    ASSERT_NO_THROW(inteiros.retiraDaPosicaoDuplo(1));
    ASSERT_ANY_THROW(inteiros.retiraDaPosicaoDuplo(5));
    ASSERT_TRUE(inteiros.contemDuplo(42));
    ASSERT_TRUE(inteiros.contemDuplo(90));
    ASSERT_FALSE(inteiros.contemDuplo(543));
    ASSERT_TRUE(inteiros.contemDuplo(77));
    ASSERT_TRUE(inteiros.contemDuplo(5100));
    ASSERT_FALSE(inteiros.contemDuplo(567));
}

TEST_F(ListaDuplaCircTest, listaVazia) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaDuplo(1995);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaDuplo(5100);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaDuplo(90);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaDuplo(80);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaDuplo(77);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaNoInicioDuplo(15);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.adicionaNaPosicaoDuplo(2600, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_FALSE(inteiros.listaVazia());
    inteiros.retiraDuplo();
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaCircTest, destroiListaDuplo) {
    ASSERT_TRUE(inteiros.listaVazia());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(77);
    inteiros.adicionaNoInicioDuplo(15);
    inteiros.adicionaNaPosicaoDuplo(2600, 2);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_NO_THROW(inteiros.destroiListaDuplo());
    ASSERT_TRUE(inteiros.listaVazia());
    ASSERT_ANY_THROW(inteiros.retiraDaPosicaoDuplo(0));
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(90);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(77);
    ASSERT_FALSE(inteiros.listaVazia());
    ASSERT_NO_THROW(inteiros.~ListaDuplaCirc());
    ASSERT_TRUE(inteiros.listaVazia());
}

TEST_F(ListaDuplaCircTest, verUltimo) {
    ASSERT_TRUE(inteiros.listaVazia());
    ASSERT_ANY_THROW(inteiros.verUltimo());
    inteiros.adicionaDuplo(42);
    inteiros.adicionaDuplo(5100);
    inteiros.adicionaDuplo(1995);
    inteiros.adicionaDuplo(80);
    inteiros.adicionaDuplo(66);
    ASSERT_EQ(4, inteiros.verUltimo());
    inteiros.adicionaEmOrdem(80);
    inteiros.adicionaEmOrdem(90);
    inteiros.adicionaNaPosicaoDuplo(500, 3);
    inteiros.adicionaNaPosicaoDuplo(600, 2);
    ASSERT_EQ(8, inteiros.verUltimo());
    inteiros.retiraDaPosicaoDuplo(5);
    inteiros.retiraDuplo();
    inteiros.retiraEspecificoDuplo(80);
    inteiros.retiraDoInicioDuplo();
    ASSERT_EQ(4, inteiros.verUltimo());
    ASSERT_FALSE(inteiros.listaVazia());
}

TEST_F(ListaDuplaCircTest, maior) {
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

TEST_F(ListaDuplaCircTest, menor) {
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

TEST_F(ListaDuplaCircTest, igual) {
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
