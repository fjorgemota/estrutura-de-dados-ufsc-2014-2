/* 
 * File:   Fila.hpp
 * Author: fernando
 *
 * Created on 25 de Agosto de 2014, 22:14
 */

#ifndef FILA_HPP
#define	FILA_HPP

#include "Lista.hpp"

/*!
 * Representa uma fila. Estrutura no qual os elementos são adicionados sempre
 * ao fim da fila mas só podem ser retirados do seu inicio.
 */
class Fila {
private: 
    Lista* lista;
public:
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
    void inclui(int dado);
    
    /*!
     * Remove o primeiro elemento adicionado na fila, ou seja, o elemento
     * está à mais tempo nela.
     * 
     * @see Lista::removePrimeiro
     */
    void retira();
    
    /*!
     * Retorna o primeiro elemento adicionado na fila, ou seja, o elemento
     * está à mais tempo nela
     * 
     * @see Lista::pegaPrimeiro
     */
    int ultimo();
    
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
};

#endif	/* FILA_HPP */

