// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FILA_HPP
#define	FILA_HPP

#include "Lista.hpp"

/*!
 * Representa uma fila. Estrutura no qual os elementos são adicionados sempre
 * ao fim da fila mas só podem ser retirados do seu inicio.
 */
template <typename T>
class Fila {
private: 
    Lista<T> *lista;
public:
    /*!
     * Constŕoi uma fila que aceita apenas "int" e com tamanho máximo 30.
     */
    Fila();
    /*!
     * Constrói uma lista vazia com o tamanho máximo especificado.
     * 
     * @param tamanho O número máximo de elementos que a lista pode conter.
     */
    Fila(int tamanhoMaximo);
    
    /*!
     * Adiciona um valor à fila.
     * 
     * @param dado O objeto à ser adicionado na fila
     * @see Lista::adicionar
     */
    void inclui(T dado);
    
    /*!
     * Remove o primeiro elemento adicionado na fila, ou seja, o elemento
     * está à mais tempo nela.
     * 
     * @see Lista::removePrimeiro
     */
    T retira();
    
    /*!
     * Retorna o ultimo elemento adicionado na fila, ou seja, o elemento
     * está a menos tempo nela
     * 
     * @see Lista::pegaPrimeiro
     */
    T ultimo();
    
    /*!
     * Retorna a posicao do ultimo elemento adicionado na fila, ou seja,
     * o elemento está a menos tempo nela
     * 
     * @see Lista::pegaPrimeiro
     */
    int getUltimo();
    
    /*!
     * Retorna um valor booleando indicando se a fila está cheia ou não.
     * 
     * @see Lista::listaCheia
     */
    bool filaCheia();
    
    /*!
     * Retorna um valor booleando indicando se a fila está vazia ou não.
     * 
     * @see Lista::listaVazia
     */
    bool filaVazia();
    
    /*!
     * Reseta todo o conteudo da fila. De forma que ela fique novamente
     * com tamanho zero.
     */
    void inicializaFila();
};

#endif	/* FILA_HPP */
