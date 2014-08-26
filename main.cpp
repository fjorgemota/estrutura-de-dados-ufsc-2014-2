// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <cstdlib>
#include <cstdio>
#include "Lista.hpp"
#include "Fila.cpp"

using std::printf;

int main(int argc, char** argv) {
    Lista teste = Lista(7);
    teste.adicionar(0);
    teste.adicionar(5);
    teste.adicionar(4);
    teste.adicionar(9);
    teste.adicionar(42);
    teste.adicionar(50);
    teste.adicionar(32);
    printf("O tamanho da Lista é: %d\n", teste.pegaTamanho());
    teste.removerPrimeiro();
    teste.removerUltimo();
    teste.remover(3);
    printf("O primeiro valor é: %d\n", teste.pegaValor(0));
    printf("O segundo valor é: %d\n", teste.pegaValor(1));
    printf("O terceiro valor é: %d\n", teste.pegaValor(2));
    printf("O quarto valor é: %d\n", teste.pegaValor(3));
    printf("O ultimo valor é: %d\n", teste.pegaUltimo());
    printf("O tamanho da lista é: %d\n", teste.pegaTamanho());
    teste.troca(1, 3);
    printf("O segundo valor é: %d\n", teste.pegaValor(1));
    printf("O quarto valor é: %d\n", teste.pegaValor(3));
    
    Fila testeFila = Fila(10);
    printf(testeFila.filaCheia()? "A fila esta cheia\n": "A fila nao esta cheia\n");
    printf(testeFila.filaVazia()? "A fila esta vazia\n": "A fila nao esta vazia\n");
    for(int a=0; a < 10; a++) {
        printf("Adicionando numero %d na fila\n", a);
        testeFila.inclui(a);
    }
    printf(testeFila.filaCheia()? "A fila esta cheia\n": "A fila nao esta cheia\n");
    printf(testeFila.filaVazia()? "A fila esta vazia\n": "A fila nao esta vazia\n");
    for(int a=0; a < 10; a++) {
        printf("Retirando numero da fila: O numero é %d\n", testeFila.ultimo());
        testeFila.retira();
    }
    printf(testeFila.filaCheia()? "A fila esta cheia\n": "A fila nao esta cheia\n");
    printf(testeFila.filaVazia()? "A fila esta vazia\n": "A fila nao esta vazia\n");
    
    return EXIT_SUCCESS;
}
