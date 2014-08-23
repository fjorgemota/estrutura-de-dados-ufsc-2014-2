#include "Lista.hpp"
#include <iostream>

Lista::Lista(int tamanho) {
    this->topo = -1;
    this->arranjo = new int[tamanho];
}

void Lista::adicionar(int obj) {
    this->topo += 1;
    this->arranjo[this->topo] = obj; 
}

int Lista::pegaTamanho(){
    return  this->topo + 1;
}

void Lista::removerUltimo(){
    this->topo -= 1;
}

void Lista::removerPrimeiro(){
    for(int a = 0; a<=topo; a++){
        this->arranjo[a] = this->arranjo[a+1];
    }
    this->topo -= 1;
}

int Lista::mostreTopo(){
    return this->arranjo[this->topo];
}

int Lista::mostreValor(int valor){
    return this->arranjo[valor-1];
}

void Lista::remover(int posicao){
    try{
        throw topo == -1;
        for(int a = posicao-1; a<=topo; a++){
        this->arranjo[a] = this->arranjo[a+1];
        }
        this->topo -= 1;
    }
    catch(int e){
        std::cout << "Erro ao remover" << std::endl;
    }
}

void Lista::troca(int posicao1, int posicao2){
    int aux = this->arranjo[posicao1-1];
    this->arranjo[posicao1-1] = this->arranjo[posicao2-1];
    this->arranjo[posicao2-1] = aux;
}