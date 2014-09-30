// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>

#include "ListaCirc.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ListaCircTest : public testing::Test {
 public:
    virtual void SetUp() {
        this->obj = ListaCirc<Objeto*>();
        this->inteiro = ListaCirc<int>();
    }
 protected:
    ListaCirc<Objeto*> obj;
    ListaCirc<int> inteiro;
};

TEST_F(ListaCircTest, adicionaNoInicio) {
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adicionaNoInicio(1);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(0, inteiro.verUltimo());
    inteiro.adicionaNoInicio(2);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(2, inteiro.mostra(0));
    ASSERT_EQ(1, inteiro.mostra(1));
    ASSERT_EQ(1, inteiro.verUltimo());
    inteiro.adicionaNoInicio(3);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(3, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(1, inteiro.mostra(2));
    ASSERT_EQ(2, inteiro.verUltimo());
    inteiro.adicionaNoInicio(4);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(1, inteiro.mostra(3));
    ASSERT_EQ(3, inteiro.verUltimo());
}

TEST_F(ListaCircTest, retiraDoInicio) {
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adicionaNoInicio(1);
    inteiro.adicionaNoInicio(2);
    inteiro.adicionaNoInicio(3);
    inteiro.adicionaNoInicio(4);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(1, inteiro.mostra(3));
    ASSERT_EQ(3, inteiro.verUltimo());
    ASSERT_EQ(4, inteiro.retiraDoInicio());
    ASSERT_EQ(2, inteiro.verUltimo());
    ASSERT_EQ(3, inteiro.retiraDoInicio());
    ASSERT_EQ(1, inteiro.verUltimo());
    ASSERT_EQ(2, inteiro.retiraDoInicio());
    ASSERT_EQ(0, inteiro.verUltimo());
    ASSERT_EQ(1, inteiro.retiraDoInicio());
    ASSERT_ANY_THROW(inteiro.retiraDoInicio());
}

TEST_F(ListaCircTest, eliminaDoInicio) {
    ASSERT_TRUE(inteiro.listaVazia());
    ASSERT_ANY_THROW(inteiro.eliminaDoInicio());
    inteiro.adicionaNoInicio(1);
    inteiro.adicionaNoInicio(2);
    inteiro.adicionaNoInicio(3);
    inteiro.adicionaNoInicio(4);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(1, inteiro.mostra(3));
    ASSERT_EQ(3, inteiro.verUltimo());
    ASSERT_NO_THROW(inteiro.eliminaDoInicio());
    ASSERT_EQ(3, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(1, inteiro.mostra(2));
    ASSERT_EQ(2, inteiro.verUltimo());
    ASSERT_NO_THROW(inteiro.eliminaDoInicio());
    ASSERT_EQ(2, inteiro.mostra(0));
    ASSERT_EQ(1, inteiro.mostra(1));
    ASSERT_EQ(1, inteiro.verUltimo());
    ASSERT_NO_THROW(inteiro.eliminaDoInicio());
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(0, inteiro.verUltimo());
    ASSERT_NO_THROW(inteiro.eliminaDoInicio());
    ASSERT_ANY_THROW(inteiro.eliminaDoInicio());
}

TEST_F(ListaCircTest, adicionaNaPosicao) {
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adicionaNoInicio(1);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(1, inteiro.mostra(0));
    inteiro.adicionaNoInicio(2);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(2, inteiro.mostra(0));
    ASSERT_EQ(1, inteiro.mostra(1));
    inteiro.adicionaNoInicio(3);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(3, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(1, inteiro.mostra(2));
    inteiro.adicionaNoInicio(4);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(1, inteiro.mostra(3));
    ASSERT_NO_THROW(inteiro.adicionaNaPosicao(4, 2));
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(4, inteiro.mostra(2));
    ASSERT_EQ(2, inteiro.mostra(3));
    ASSERT_EQ(1, inteiro.mostra(4));
    ASSERT_NO_THROW(inteiro.adicionaNaPosicao(1, 0));
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(4, inteiro.mostra(1));
    ASSERT_EQ(3, inteiro.mostra(2));
    ASSERT_EQ(4, inteiro.mostra(3));
    ASSERT_EQ(2, inteiro.mostra(4));
    ASSERT_EQ(1, inteiro.mostra(5));
    ASSERT_ANY_THROW(inteiro.adicionaNaPosicao(10, 10));
    ASSERT_NO_THROW(inteiro.adicionaNaPosicao(8, 1));
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(8, inteiro.mostra(1));
    ASSERT_EQ(4, inteiro.mostra(2));
    ASSERT_EQ(3, inteiro.mostra(3));
    ASSERT_EQ(4, inteiro.mostra(4));
    ASSERT_EQ(2, inteiro.mostra(5));
    ASSERT_EQ(1, inteiro.mostra(6));
    ASSERT_NO_THROW(inteiro.adicionaNaPosicao(9, 6));
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(8, inteiro.mostra(1));
    ASSERT_EQ(4, inteiro.mostra(2));
    ASSERT_EQ(3, inteiro.mostra(3));
    ASSERT_EQ(4, inteiro.mostra(4));
    ASSERT_EQ(2, inteiro.mostra(5));
    ASSERT_EQ(9, inteiro.mostra(6));
    ASSERT_EQ(1, inteiro.mostra(7));
}

TEST_F(ListaCircTest, posicao) {
    ASSERT_TRUE(inteiro.listaVazia());
    ASSERT_ANY_THROW(inteiro.posicao(1));
    inteiro.adicionaNoInicio(1);
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(0, inteiro.posicao(1));
    inteiro.adicionaNoInicio(2);
    ASSERT_EQ(0, inteiro.posicao(2));
    ASSERT_EQ(1, inteiro.posicao(1));
    inteiro.adicionaNoInicio(3);
    ASSERT_EQ(0, inteiro.posicao(3));
    ASSERT_EQ(1, inteiro.posicao(2));
    ASSERT_EQ(2, inteiro.posicao(1));
    inteiro.adicionaNoInicio(4);
    ASSERT_EQ(0, inteiro.posicao(4));
    ASSERT_EQ(1, inteiro.posicao(3));
    ASSERT_EQ(2, inteiro.posicao(2));
    ASSERT_EQ(3, inteiro.posicao(1));
    ASSERT_ANY_THROW(inteiro.posicao(10));
}

TEST_F(ListaCircTest, contem) {
    ASSERT_FALSE(inteiro.contem(1));
    ASSERT_FALSE(inteiro.contem(2));
    ASSERT_FALSE(inteiro.contem(3));
    ASSERT_FALSE(inteiro.contem(4));
    inteiro.adicionaNoInicio(1);
    ASSERT_TRUE(inteiro.contem(1));
    ASSERT_FALSE(inteiro.contem(2));
    ASSERT_FALSE(inteiro.contem(3));
    ASSERT_FALSE(inteiro.contem(4));
    inteiro.adicionaNoInicio(2);
    ASSERT_TRUE(inteiro.contem(1));
    ASSERT_TRUE(inteiro.contem(2));
    ASSERT_FALSE(inteiro.contem(3));
    ASSERT_FALSE(inteiro.contem(4));
    inteiro.adicionaNoInicio(3);
    ASSERT_TRUE(inteiro.contem(1));
    ASSERT_TRUE(inteiro.contem(2));
    ASSERT_TRUE(inteiro.contem(3));
    ASSERT_FALSE(inteiro.contem(4));
    inteiro.adicionaNoInicio(4);
    ASSERT_TRUE(inteiro.contem(1));
    ASSERT_TRUE(inteiro.contem(2));
    ASSERT_TRUE(inteiro.contem(3));
    ASSERT_TRUE(inteiro.contem(4));
}


TEST_F(ListaCircTest, retiraDaPosicao) {
    inteiro.adicionaNoInicio(1);
    inteiro.adicionaNoInicio(2);
    inteiro.adicionaNoInicio(3);
    inteiro.adicionaNoInicio(4);
    ASSERT_ANY_THROW(inteiro.retiraDaPosicao(-1));
    ASSERT_ANY_THROW(inteiro.retiraDaPosicao(5));
    ASSERT_EQ(3, inteiro.verUltimo());
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(1, inteiro.mostra(3));
    ASSERT_EQ(1, inteiro.retiraDaPosicao(3));
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
    ASSERT_EQ(2, inteiro.verUltimo());
    ASSERT_EQ(2, inteiro.retiraDaPosicao(2));
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_ANY_THROW(inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
    ASSERT_EQ(1, inteiro.verUltimo());
    ASSERT_EQ(3, inteiro.retiraDaPosicao(1));
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_ANY_THROW(inteiro.mostra(1));
    ASSERT_ANY_THROW(inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
    ASSERT_EQ(0, inteiro.verUltimo());
    ASSERT_EQ(4, inteiro.retiraDaPosicao(0));
    ASSERT_ANY_THROW(inteiro.mostra(0));
    ASSERT_ANY_THROW(inteiro.mostra(1));
    ASSERT_ANY_THROW(inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
}

TEST_F(ListaCircTest, adiciona) {
    inteiro.adiciona(1);
    ASSERT_EQ(1, inteiro.mostra(0));
    inteiro.adiciona(2);
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    inteiro.adiciona(3);
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(3, inteiro.mostra(2));
    inteiro.adiciona(4);
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(3, inteiro.mostra(2));
    ASSERT_EQ(4, inteiro.mostra(3));
}

TEST_F(ListaCircTest, adicionaEmOrdem) {
    inteiro.adicionaEmOrdem(1);
    inteiro.adicionaEmOrdem(2);
    inteiro.adicionaEmOrdem(3);
    inteiro.adicionaEmOrdem(5);
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(3, inteiro.mostra(2));
    ASSERT_EQ(5, inteiro.mostra(3));
    inteiro.adicionaEmOrdem(6);
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(3, inteiro.mostra(2));
    ASSERT_EQ(5, inteiro.mostra(3));
    ASSERT_EQ(6, inteiro.mostra(4));
    inteiro.adicionaEmOrdem(0);
    ASSERT_EQ(0, inteiro.mostra(0));
    ASSERT_EQ(1, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(3, inteiro.mostra(3));
    ASSERT_EQ(5, inteiro.mostra(4));
    ASSERT_EQ(6, inteiro.mostra(5));
    inteiro.adicionaEmOrdem(4);
    ASSERT_EQ(0, inteiro.mostra(0));
    ASSERT_EQ(1, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(3, inteiro.mostra(3));
    ASSERT_EQ(4, inteiro.mostra(4));
    ASSERT_EQ(5, inteiro.mostra(5));
    ASSERT_EQ(6, inteiro.mostra(6));
}

TEST_F(ListaCircTest, retira) {
    inteiro.adiciona(1);
    inteiro.adiciona(2);
    inteiro.adiciona(3);
    inteiro.adiciona(4);
    ASSERT_EQ(3, inteiro.verUltimo());
    ASSERT_EQ(4, inteiro.retira());
    ASSERT_EQ(2, inteiro.verUltimo());
    ASSERT_EQ(3, inteiro.retira());
    ASSERT_EQ(1, inteiro.verUltimo());
    ASSERT_EQ(2, inteiro.retira());
    ASSERT_EQ(0, inteiro.verUltimo());
    ASSERT_EQ(1, inteiro.retira());
}

TEST_F(ListaCircTest, retiraEspecifico) {
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adiciona(1);
    inteiro.adiciona(2);
    inteiro.adiciona(3);
    inteiro.adiciona(4);
    ASSERT_EQ(3, inteiro.verUltimo());
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_TRUE(inteiro.contem(4));
    ASSERT_EQ(4, inteiro.retiraEspecifico(4));
    ASSERT_EQ(2, inteiro.verUltimo());
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_FALSE(inteiro.contem(4));
    ASSERT_TRUE(inteiro.contem(3));
    ASSERT_EQ(3, inteiro.retiraEspecifico(3));
    ASSERT_EQ(1, inteiro.verUltimo());
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_FALSE(inteiro.contem(3));
    ASSERT_TRUE(inteiro.contem(2));
    ASSERT_EQ(2, inteiro.retiraEspecifico(2));
    ASSERT_EQ(0, inteiro.verUltimo());
    ASSERT_FALSE(inteiro.listaVazia());
    ASSERT_FALSE(inteiro.contem(2));
    ASSERT_TRUE(inteiro.contem(1));
    ASSERT_EQ(1, inteiro.retiraEspecifico(1));
    ASSERT_FALSE(inteiro.contem(1));
    ASSERT_TRUE(inteiro.listaVazia());
}


TEST_F(ListaCircTest, mostra) {
    inteiro.adicionaNoInicio(1);
    ASSERT_EQ(1, inteiro.mostra(0));
    ASSERT_ANY_THROW(inteiro.mostra(1));
    ASSERT_ANY_THROW(inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
    inteiro.adicionaNoInicio(2);
    ASSERT_EQ(2, inteiro.mostra(0));
    ASSERT_EQ(1, inteiro.mostra(1));
    ASSERT_ANY_THROW(inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
    inteiro.adicionaNoInicio(3);
    ASSERT_EQ(3, inteiro.mostra(0));
    ASSERT_EQ(2, inteiro.mostra(1));
    ASSERT_EQ(1, inteiro.mostra(2));
    ASSERT_ANY_THROW(inteiro.mostra(3));
    inteiro.adicionaNoInicio(4);
    ASSERT_EQ(4, inteiro.mostra(0));
    ASSERT_EQ(3, inteiro.mostra(1));
    ASSERT_EQ(2, inteiro.mostra(2));
    ASSERT_EQ(1, inteiro.mostra(3));
}

TEST_F(ListaCircTest, verUltimo) {
    ASSERT_ANY_THROW(inteiro.verUltimo());
    inteiro.adiciona(1);
    ASSERT_EQ(0, inteiro.verUltimo());
    inteiro.adiciona(2);
    ASSERT_EQ(1, inteiro.verUltimo());
    inteiro.adiciona(3);
    ASSERT_EQ(2, inteiro.verUltimo());
    inteiro.adiciona(4);
    ASSERT_EQ(3, inteiro.verUltimo());
    ASSERT_EQ(4, inteiro.retira());
    ASSERT_EQ(2, inteiro.verUltimo());
    ASSERT_EQ(3, inteiro.retira());
    ASSERT_EQ(1, inteiro.verUltimo());
    ASSERT_EQ(2, inteiro.retira());
    ASSERT_EQ(0, inteiro.verUltimo());
    ASSERT_EQ(1, inteiro.retira());
    ASSERT_ANY_THROW(inteiro.verUltimo());
}

TEST_F(ListaCircTest, listaVazia) {
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adiciona(1);
    ASSERT_FALSE(inteiro.listaVazia());
    inteiro.eliminaDoInicio();
    ASSERT_TRUE(inteiro.listaVazia());
}


TEST_F(ListaCircTest, maior) {
    ASSERT_TRUE(inteiro.maior(5100, 2600));
    ASSERT_FALSE(inteiro.maior(6, 42));
}

TEST_F(ListaCircTest, menor) {
    ASSERT_TRUE(inteiro.menor(2600, 5100));
    ASSERT_FALSE(inteiro.menor(42, 6));
}


TEST_F(ListaCircTest, igual) {
    ASSERT_TRUE(inteiro.igual(140, 140));
    ASSERT_FALSE(inteiro.igual(42, 6));
}

TEST_F(ListaCircTest, destroiLista) {
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adiciona(1);
    inteiro.adiciona(2);
    inteiro.adiciona(3);
    inteiro.adiciona(4);
    ASSERT_FALSE(inteiro.listaVazia());
    inteiro.destroiLista();
    ASSERT_TRUE(inteiro.listaVazia());
    inteiro.adiciona(10);
    ASSERT_EQ(10, inteiro.mostra(0));
}
