/* 
 * File:   main.cpp
 * Author: caique
 *
 * Created on 21 de Agosto de 2014, 14:20
 */

#include <cstdlib>
#include <cstdio>
#include "Lista.hpp"
using namespace std;

int main(int argc, char** argv) {
    Lista teste = Lista(7);
    teste.adicionar(0);
    teste.adicionar(5);
    teste.adicionar(4);
    teste.adicionar(9);
    teste.adicionar(42);
    teste.adicionar(50);
    teste.adicionar(32);
    printf("O tamanho da Lista é: %d", teste.pegaTamanho());
    teste.removerPrimeiro();
    teste.removerUltimo();
    teste.remover(3);
    printf("\nO primeiro valor é: %d", teste.mostreValor(1));
    printf("\nO segundo valor é: %d", teste.mostreValor(2));
    printf("\nO terceiro valor é: %d", teste.mostreValor(3));
    printf("\nO quarto valor é: %d", teste.mostreValor(4));
    printf("\nO valor do topo é: %d", teste.mostreTopo());
    printf("\nO tamanho da lista é: %d", teste.pegaTamanho());
    teste.troca(2, 4);
    printf("\nO segundo valor é: %d", teste.mostreValor(2));
    printf("\nO quarto valor é: %d", teste.mostreValor(4));
    return 0;
}