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
    // Rotações à Direita
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

TEST_F(NoAVLTest, insereRotacaoSimplesDireita) {
    NoAVL<int> *nodoRaiz = inteiro->inserir(11, inteiro);
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));

    //Rotação simples à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(1, nodoRaiz->getAltura());
    ASSERT_EQ(10, *(elementos[0]->getDado()));
    ASSERT_EQ(11, *(elementos[1]->getDado()));
    ASSERT_EQ(12, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoSimplesEsquerda) {
    NoAVL<int> *nodoRaiz = inteiro->inserir(9, inteiro);
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    // Rotação simples à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(1, nodoRaiz->getAltura());
    ASSERT_EQ(8, *(elementos[0]->getDado()));
    ASSERT_EQ(9, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoDuplaEsquerda) {
    NoAVL<int> *noRaiz = inteiro->inserir(7, inteiro);
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(1, noRaiz->getAltura());
    ASSERT_EQ(7, *(elementos[0]->getDado()));
    ASSERT_EQ(8, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoDuplaDireita) {
    NoAVL<int> *noRaiz = inteiro->inserir(12, inteiro);
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(1, noRaiz->getAltura());
    ASSERT_EQ(10, *(elementos[0]->getDado()));
    ASSERT_EQ(11, *(elementos[1]->getDado()));
    ASSERT_EQ(12, *(elementos[2]->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoSimplesDireita) {
    ASSERT_NO_THROW(inteiro->inserir(5, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(15, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(14, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(16, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(6, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(17, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(18, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(3, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(19, inteiro));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 15));
    //Rotação simples à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(3, *(elementos[0]->getDado()));
    ASSERT_EQ(5, *(elementos[1]->getDado()));
    ASSERT_EQ(6, *(elementos[2]->getDado()));
    ASSERT_EQ(7, *(elementos[3]->getDado()));
    ASSERT_EQ(8, *(elementos[4]->getDado()));
    ASSERT_EQ(10, *(elementos[5]->getDado()));
    ASSERT_EQ(13, *(elementos[6]->getDado()));
    ASSERT_EQ(14, *(elementos[7]->getDado()));
    ASSERT_EQ(16, *(elementos[8]->getDado()));
    ASSERT_EQ(17, *(elementos[9]->getDado()));
    ASSERT_EQ(18, *(elementos[10]->getDado()));
    ASSERT_EQ(19, *(elementos[11]->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoSimplesEsquerda) {
    ASSERT_NO_THROW(inteiro->inserir(5, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(15, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(14, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(16, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(6, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 15));
    // Rotação simples à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(2, inteiro->getAltura());
    ASSERT_EQ(5, *(elementos[0]->getDado()));
    ASSERT_EQ(6, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
    ASSERT_EQ(13, *(elementos[3]->getDado()));
    ASSERT_EQ(14, *(elementos[4]->getDado()));
    ASSERT_EQ(16, *(elementos[5]->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoDuplaEsquerda) {
    ASSERT_NO_THROW(inteiro->inserir(4, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(15, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(14, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(17, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(6, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(20, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(25, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(2, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(26, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(18, inteiro));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 26));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 25));
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(2, *(elementos[0]->getDado()));
    ASSERT_EQ(4, *(elementos[1]->getDado()));
    ASSERT_EQ(6, *(elementos[2]->getDado()));
    ASSERT_EQ(7, *(elementos[3]->getDado()));
    ASSERT_EQ(8, *(elementos[4]->getDado()));
    ASSERT_EQ(10, *(elementos[5]->getDado()));
    ASSERT_EQ(13, *(elementos[6]->getDado()));
    ASSERT_EQ(14, *(elementos[7]->getDado()));
    ASSERT_EQ(15, *(elementos[8]->getDado()));
    ASSERT_EQ(17, *(elementos[9]->getDado()));
    ASSERT_EQ(18, *(elementos[10]->getDado()));
    ASSERT_EQ(20, *(elementos[11]->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoDuplaDireita) {
    ASSERT_NO_THROW(inteiro->inserir(4, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(15, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(14, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(17, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(6, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(20, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(25, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(2, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(26, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(16, inteiro));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 14));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 13));
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);
    
    std::vector<NoAVL<int>* > elementos = inteiro->getElementos();
    
    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(2, *(elementos[0]->getDado()));
    ASSERT_EQ(4, *(elementos[1]->getDado()));
    ASSERT_EQ(6, *(elementos[2]->getDado()));
    ASSERT_EQ(7, *(elementos[3]->getDado()));
    ASSERT_EQ(8, *(elementos[4]->getDado()));
    ASSERT_EQ(10, *(elementos[5]->getDado()));
    ASSERT_EQ(15, *(elementos[6]->getDado()));
    ASSERT_EQ(16, *(elementos[7]->getDado()));
    ASSERT_EQ(17, *(elementos[8]->getDado()));
    ASSERT_EQ(20, *(elementos[9]->getDado()));
    ASSERT_EQ(25, *(elementos[10]->getDado()));
    ASSERT_EQ(26, *(elementos[11]->getDado()));
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
    ASSERT_EQ(2, inteiro->getAltura());
    
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_EQ(2, inteiro->getAltura());
}
