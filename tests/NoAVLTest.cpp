// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <vector>
#include "gtest/gtest.h"
#include "NoAVL.hpp"

int main(int argc, char **argv) {
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
        inteiro = inteiro->inserir(h, inteiro);
    }
    for (h = 1; h < 11; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    for (h = 11; h < 20; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(NoAVLTest, insereRotacaoSimplesDireita) {
    inteiro = inteiro->inserir(11, inteiro);
    inteiro = inteiro->inserir(12, inteiro);

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(11, *(inteiro->getDado()));
    ASSERT_EQ(10, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(12, *(inteiro->getDireita()->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoSimplesEsquerda) {
    inteiro = inteiro->inserir(9, inteiro);
    inteiro = inteiro->inserir(8, inteiro);

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(9, *(inteiro->getDado()));
    ASSERT_EQ(8, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(10, *(inteiro->getDireita()->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoDuplaEsquerda) {
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(8, *(inteiro->getDado()));
    ASSERT_EQ(7, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(10, *(inteiro->getDireita()->getDado()));
}

TEST_F(NoAVLTest, insereRotacaoDuplaDireita) {
    inteiro = inteiro->inserir(12, inteiro);
    inteiro = inteiro->inserir(11, inteiro);

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(11, *(inteiro->getDado()));
    ASSERT_EQ(10, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(12, *(inteiro->getDireita()->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoSimplesDireita) {
    inteiro = inteiro->inserir(5, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(16, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(17, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->inserir(18, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(3, inteiro);
    inteiro = inteiro->inserir(19, inteiro);
    inteiro = inteiro->remover(inteiro, 15);
    // Rotação simples à Direita

    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(3, *(inteiro->getEsquerda()->getEsquerda()
                        ->getEsquerda()->getDado()));
    ASSERT_EQ(5, *(inteiro->getEsquerda()->getEsquerda()->getDado()));
    ASSERT_EQ(6, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(7, *(inteiro->getEsquerda()
                        ->getDireita()->getDado()));
    ASSERT_EQ(8, *(inteiro->getEsquerda()->getDireita()
                        ->getDireita()->getDado()));
    ASSERT_EQ(10, *(inteiro->getDado()));
    ASSERT_EQ(13, *(inteiro->getDireita()->getEsquerda()
                        ->getEsquerda()->getDado()));
    ASSERT_EQ(14, *(inteiro->getDireita()->getEsquerda()->getDado()));
    ASSERT_EQ(16, *(inteiro->getDireita()->getDado()));
    ASSERT_EQ(17, *(inteiro->getDireita()->getDireita()
                        ->getEsquerda()->getDado()));
    ASSERT_EQ(18, *(inteiro->getDireita()->getDireita()->getDado()));
    ASSERT_EQ(19, *(inteiro->getDireita()->getDireita()
                        ->getDireita()->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoSimplesEsquerda) {
    inteiro = inteiro->inserir(5, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(16, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->remover(inteiro, 15);

    ASSERT_EQ(2, inteiro->getAltura());
    ASSERT_EQ(5, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(6, *(inteiro->getEsquerda()->getDireita()->getDado()));
    ASSERT_EQ(10, *(inteiro->getDado()));
    ASSERT_EQ(13, *(inteiro->getDireita()->getEsquerda()->getDado()));
    ASSERT_EQ(14, *(inteiro->getDireita()->getDado()));
    ASSERT_EQ(16, *(inteiro->getDireita()->getDireita()->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoDuplaEsquerda) {
    inteiro = inteiro->inserir(4, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(17, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(20, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->inserir(25, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(2, inteiro);
    inteiro = inteiro->inserir(26, inteiro);
    inteiro = inteiro->inserir(18, inteiro);

    ASSERT_EQ(4, inteiro->getAltura());

    inteiro = inteiro->remover(inteiro, 26);
    inteiro = inteiro->remover(inteiro, 25);
    // Rotação dupla à Direita
    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(2, *(inteiro->getEsquerda()->getEsquerda()
                                ->getEsquerda()->getDado()));

    ASSERT_EQ(4, *(inteiro->getEsquerda()->getEsquerda()->getDado()));
    ASSERT_EQ(6, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(7, *(inteiro->getEsquerda()->getDireita()->getDado()));
    ASSERT_EQ(8, *(inteiro->getEsquerda()->getDireita()
                                ->getDireita()->getDado()));

    ASSERT_EQ(10, *(inteiro->getDado()));
    ASSERT_EQ(13, *(inteiro->getDireita()->getEsquerda()
                                ->getEsquerda()->getDado()));

    ASSERT_EQ(14, *(inteiro->getDireita()->getEsquerda()->getDado()));
    ASSERT_EQ(15, *(inteiro->getDireita()->getDado()));
    ASSERT_EQ(17, *(inteiro->getDireita()->getDireita()
                                ->getEsquerda()->getDado()));

    ASSERT_EQ(18, *(inteiro->getDireita()->getDireita()->getDado()));
    ASSERT_EQ(20, *(inteiro->getDireita()->getDireita()
                                ->getDireita()->getDado()));
}


TEST_F(NoAVLTest, insercao1) {
    inteiro = inteiro->inserir(1, inteiro);
    inteiro = inteiro->inserir(2, inteiro);

    ASSERT_EQ(2,  *(inteiro->getDado()));
    ASSERT_EQ(1,  *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(10, *(inteiro->getDireita()->getDado()));
}


TEST_F(NoAVLTest, insercao) {
    inteiro = inteiro->inserir(1, inteiro);
    inteiro = inteiro->inserir(2, inteiro);
    inteiro = inteiro->inserir(3, inteiro);
    inteiro = inteiro->inserir(4, inteiro);
    inteiro = inteiro->inserir(5, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(9, inteiro);

    ASSERT_EQ(4, *(inteiro->getDado()));
    ASSERT_EQ(2, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(1, *(inteiro->getEsquerda()->getEsquerda()->getDado()));
    ASSERT_EQ(3, *(inteiro->getEsquerda()->getDireita()
                                    ->getDado()));

    ASSERT_EQ(8, *(inteiro->getDireita()->getDado()));
    ASSERT_EQ(6, *(inteiro->getDireita()->getEsquerda()
                                    ->getDado()));
    ASSERT_EQ(5, *(inteiro->getDireita()->getEsquerda()
                                    ->getEsquerda()->getDado()));
    ASSERT_EQ(7, *(inteiro->getDireita()->getEsquerda()
                                    ->getDireita()->getDado()));

    ASSERT_EQ(10, *(inteiro->getDireita()->getDireita()->getDado()));
    ASSERT_EQ(9,  *(inteiro->getDireita()->getDireita()
                                    ->getEsquerda()->getDado()));
}

TEST_F(NoAVLTest, removerRotacaoDuplaDireita) {
    inteiro = inteiro->inserir(4, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(17, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(20, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->inserir(25, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(2, inteiro);
    inteiro = inteiro->inserir(26, inteiro);
    inteiro = inteiro->inserir(16, inteiro);

    ASSERT_EQ(4, inteiro->getAltura());

    inteiro = inteiro->remover(inteiro, 14);
    inteiro = inteiro->remover(inteiro, 13);
    // Rotação dupla à Direita

    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(2, *(inteiro->getEsquerda()->getEsquerda()
                                    ->getEsquerda()->getDado()));

    ASSERT_EQ(4, *(inteiro->getEsquerda()->getEsquerda()->getDado()));
    ASSERT_EQ(6, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(7, *(inteiro->getEsquerda()->getDireita()->getDado()));
    ASSERT_EQ(8, *(inteiro->getEsquerda()->getDireita()
                                    ->getDireita()->getDado()));

    ASSERT_EQ(10, *(inteiro->getDado()));
    ASSERT_EQ(15, *(inteiro->getDireita()->getEsquerda()
                                    ->getEsquerda()->getDado()));

    ASSERT_EQ(16, *(inteiro->getDireita()->getEsquerda()->getDado()));
    ASSERT_EQ(17, *(inteiro->getDireita()->getEsquerda()
                                    ->getDireita()->getDado()));

    ASSERT_EQ(25, *(inteiro->getDireita()->getDireita()->getDado()));
    ASSERT_EQ(26, *(inteiro->getDireita()->getDireita()
                                    ->getDireita()->getDado()));
}

TEST_F(NoAVLTest, remover) {
    int h;
    for (h = 0; h < 10; h++) {
        inteiro = inteiro->inserir(h, inteiro);
    }

    for (h = 0; h < 10; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }

    for (h = 0; h < 10; h++) {
        inteiro = inteiro->remover(inteiro, h);
    }

    for (h = 0; h < 10; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(NoAVLTest, busca) {
    int h;
    for (h = 0; h < 10; h++) {
        inteiro = inteiro->inserir(h, inteiro);
    }

    for (h = 0; h < 10; h++) {
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
        inteiro = inteiro->inserir(h, inteiro);
        ASSERT_EQ(h, *(inteiro->minimo(inteiro)->getDado()));
    }
}

TEST_F(NoAVLTest, getAltura) {
    ASSERT_EQ(0, inteiro->getAltura());
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(12, inteiro);
    ASSERT_EQ(1, inteiro->getAltura());

    inteiro = inteiro->inserir(9, inteiro);
    inteiro = inteiro->inserir(11, inteiro);
    ASSERT_EQ(2, inteiro->getAltura());

    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    ASSERT_EQ(2, inteiro->getAltura());
}
