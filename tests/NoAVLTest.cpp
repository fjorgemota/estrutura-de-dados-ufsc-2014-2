// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "gtest/gtest.h"
#include "NoAVL.hpp"
#include <cstdlib>
#include <vector>

int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class NoAVLTest: public ::testing::Test {
 public:
    virtual void SetUp() {
        this->inteiro = new NoAVL<int>(10);
        this->obj = new NoAVL<Objeto>(Objeto());
    }
    
 protected:
    NoAVL<int> *inteiro;
    NoAVL<Objeto> *obj;
};

TEST_F(NoAVLTest, inserir) {
    int h;
    // Rotações à esquerda
    for (h = 1; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
    }
    for (h = 1; h < 11; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    for (h = 11; h < 20; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(NoAVLTest, insereRotacaoSimplesEsquerda) {
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    //Rotação simples à esquerda
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(10, *(elementos[0]->getDado()));
    ASSERT_EQ(11, *(elementos[1]->getDado()));
    ASSERT_EQ(12, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoSimplesDireita) {
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    // Rotação simples à direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(8, *(elementos[0]->getDado()));
    ASSERT_EQ(9, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoDuplaDireita) {
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    // Rotação dupla à direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(7, *(elementos[0]->getDado()));
    ASSERT_EQ(8, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoDuplaEsquerda) {
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    // Rotação dupla à esquerda
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(10, *(elementos[0]->getDado()));
    ASSERT_EQ(11, *(elementos[1]->getDado()));
    ASSERT_EQ(12, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, remover) {
    int h;
    for (h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
    }
    
    for (h = 0; h < 10; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    
    for (h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->remover(inteiro, h));
    }
    
    for (h = 0; h < 10; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(NoAVLTest, busca) {
    int h;
    for(h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
    }
    
    for(h = 0; h < 10; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    
    for (h = 11; h < 20; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(NoAVLTest, minimo) {
    int h;
    ASSERT_EQ(10, *(inteiro->minimo(inteiro)->getDado()));
    for (h = 9; h >= 0; h--) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
        ASSERT_EQ(h, *(inteiro->minimo(inteiro)->getDado()));
    }
}

TEST_F(NoAVLTest, getAltura) {
    ASSERT_EQ(0, inteiro->getAltura());
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    ASSERT_EQ(1, inteiro->getAltura());
    
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    ASSERT_EQ(1, inteiro->getAltura());
    
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_EQ(1, inteiro->getAltura());
}
