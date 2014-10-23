// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <gtest/gtest.h>
#include <NoBinario.hpp>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class NoBinarioTest : public ::testing::Test {
 protected:
    NoBinario<Objeto>* objeto;
    NoBinario<int>* inteiro;
 public:
    virtual void SetUp() {
        this->inteiro = new NoBinario<int>(10);
        this->objeto = new NoBinario<Objeto>(Objeto());
    }
};

TEST_F(NoBinarioTest, getDado) {
    ASSERT_EQ(10, *(inteiro->getDado()));
    inteiro = new NoBinario<int>(5);
    ASSERT_EQ(5, *(inteiro->getDado()));
    inteiro = new NoBinario<int>(15);
    ASSERT_EQ(15, *(inteiro->getDado()));
}

TEST_F(NoBinarioTest, busca) {
    ASSERT_EQ(10, *(inteiro->busca(10, inteiro)));
    ASSERT_NO_THROW(inteiro->inserir(5, inteiro));
    ASSERT_EQ(5, *(inteiro->busca(5, inteiro)));
    ASSERT_NO_THROW(inteiro->inserir(20, inteiro));
    ASSERT_EQ(20, *(inteiro->busca(20, inteiro)));
    ASSERT_NO_THROW(inteiro->inserir(3, inteiro));
    ASSERT_EQ(3, *(inteiro->busca(3, inteiro)));
    ASSERT_NO_THROW(inteiro->inserir(16, inteiro));
    ASSERT_EQ(16, *(inteiro->busca(16, inteiro)));
    ASSERT_ANY_THROW(inteiro->busca(14, inteiro));
}

TEST_F(NoBinarioTest, inserir) {
    int i;
    for (i = 0; i < 10; i++) {
        ASSERT_NO_THROW(inteiro->inserir(i, inteiro));
    }
    for (i = 11; i < 20; i++) {
        ASSERT_NO_THROW(inteiro->inserir(i, inteiro));
    }
    for (i = 0; i < 10; i++) {
        ASSERT_EQ(i, *(inteiro->busca(i, inteiro)));
    }
    for (i = 11; i < 20; i++) {
        ASSERT_EQ(i, *(inteiro->busca(i, inteiro)));
    }
}

TEST_F(NoBinarioTest, remover) {
    int i;
    for (i = 0; i < 10; i++) {
        ASSERT_NO_THROW(inteiro->inserir(i, inteiro));
    }
    for (i = 11; i < 20; i++) {
        ASSERT_NO_THROW(inteiro->inserir(i, inteiro));
    }
    for (i = 0; i < 10; i++) {
        ASSERT_EQ(i, *(inteiro->busca(i, inteiro)));
    }
    for (i = 11; i < 20; i++) {
        ASSERT_EQ(i, *(inteiro->busca(i, inteiro)));
    }
    for (i = 0; i < 10; i++) {
        ASSERT_NO_THROW(inteiro->remover(inteiro, i));
    }
    for (i = 11; i < 20; i++) {
        ASSERT_NO_THROW(inteiro->remover(inteiro, i));
    }
    for (i = 0; i < 10; i++) {
        ASSERT_ANY_THROW(inteiro->busca(i, inteiro));
    }
    for (i = 11; i < 20; i++) {
        ASSERT_ANY_THROW(inteiro->busca(i, inteiro));
    }
}


TEST_F(NoBinarioTest, minimo) {
    int i;
    ASSERT_EQ(10, *(inteiro->minimo(inteiro)->getDado()));
    for (i = 9;  i >= 0; i--) {
        ASSERT_NO_THROW(inteiro->inserir(i, inteiro));
        ASSERT_EQ(i, *(inteiro->minimo(inteiro)->getDado()));
    }
}

TEST_F(NoBinarioTest, preOrdem) {
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    ASSERT_NO_THROW(inteiro->preOrdem(inteiro));
    NoBinario<int> *elementos = inteiro->getElementos();
    ASSERT_EQ(10, *(elementos[0].getDado()));
    ASSERT_EQ(8, *(elementos[1].getDado()));
    ASSERT_EQ(9, *(elementos[2].getDado()));
    ASSERT_EQ(11, *(elementos[3].getDado()));
    ASSERT_EQ(12, *(elementos[4].getDado()));
}

TEST_F(NoBinarioTest, emOrdem) {
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    ASSERT_NO_THROW(inteiro->emOrdem(inteiro));
    NoBinario<int> *elementos = inteiro->getElementos();
    ASSERT_EQ(8, *(elementos[0].getDado()));
    ASSERT_EQ(9, *(elementos[1].getDado()));
    ASSERT_EQ(10, *(elementos[2].getDado()));
    ASSERT_EQ(11, *(elementos[3].getDado()));
    ASSERT_EQ(12, *(elementos[4].getDado()));
}

TEST_F(NoBinarioTest, posOrdem) {
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    ASSERT_NO_THROW(inteiro->posOrdem(inteiro));
    NoBinario<int> *elementos = inteiro->getElementos();
    ASSERT_EQ(9, *(elementos[0].getDado()));
    ASSERT_EQ(8, *(elementos[1].getDado()));
    ASSERT_EQ(12, *(elementos[2].getDado()));
    ASSERT_EQ(11, *(elementos[3].getDado()));
    ASSERT_EQ(10, *(elementos[4].getDado()));
}
