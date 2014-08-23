/* 
 * File:   Lista.hpp
 * Author: caique
 *
 * Created on 21 de Agosto de 2014, 14:25
 */

#ifndef LISTA_HPP
#define	LISTA_HPP

class Lista {
public:
    /*! Construtor Lista
     * 
     * Constrói uma lista.
     * Um arranjo (array) é incializado e definido com tamanho especificado pelo 
     * usuário. O arranjo não possui nenhum valor, mas o topo é pré-carregado 
     * com o valor '-1' (menos um) que, por convenção, serve para indicar uma 
     * lista vazia.
     */
    Lista(int tamanho);
    void adicionar(int obj); //!< Adiciona um valor pelo topo.
    int pegaTamanho();
    void remover(int posicao); //!< Remove um valor especificado pelo usuário.
    void removerPrimeiro(); //!< Remove o primeiro valor, por baixo do arranjo.
    void removerUltimo();
    int mostreTopo();
    int mostreValor(int valor); //!< Apresenta o valor da posição especificada.
    void troca(int posicao1, int posicao2);
    
private:
    int* arranjo; //! < O arranjo indica a 'lista' em si. 
    int topo; //! < O topo é a última posição, de baixo para cima.
    int tamanho;
};

#endif	/* LISTA_HPP */