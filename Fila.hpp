// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FILA_HPP
#define FILA_HPP
#define TAMANHO_MAXIMO_FILA 30
#include "Lista.hpp"

/*!
 * Representa uma fila. Estrutura no qual os elementos são adicionados sempre
 * ao fim da fila mas só podem ser retirados do seu início
 * 
 * @see Fila::inclui()
 * @see Fila::retira()
 */
template <typename T>
class Fila {
 private:
    Lista<T> *lista;  //! < A lista no qual os elementos da fila serão guardados

 public:
    /*!
     * Constŕói uma fila com tamanho máximo (30)
     */
    Fila();

    /*!
     * Constrói uma fila vazia com o tamanho máximo especificado
     * 
     * @param tamanho O número máximo de elementos que a fila pode conter
     */
    Fila<T>(int tamanhoMaximo);

    /*!
     * Adiciona um valor à fila
     * 
     * @param dado O objeto à ser adicionado na fila
     * @see Lista::adiciona
     */
    void inclui(T dado);

    /*!
     * Remove o primeiro elemento adicionado à fila, ou seja, o elemento que
     * está mais tempo nela
     * 
     * @see Lista::retiraDoInicio
     */
    T retira();

    /*!
     * Retorna o último elemento adicionado na fila, ou seja, o elemento que
     * está menos tempo nela
     * 
     * @see Lista::pegaPrimeiro
     */
    T ultimo();

    /*!
     * Retorna a posição do último elemento adicionado na fila, ou seja,
     * o elemento que está menos tempo nela
     * 
     * @see Lista::pegaPrimeiro
     */
    int getUltimo();

    /*!
     * Retorna um valor booleano indicando se a fila está cheia ou não
     * 
     * @see Lista::listaCheia
     */
    bool filaCheia();

    /*!
     * Retorna um valor booleano indicando se a fila está vazia ou não
     * 
     * @see Lista::listaVazia
     */
    bool filaVazia();

    /*!
     * Reseta todo o conteúdo da fila, de forma que ela fique novamente
     * com tamanho zero
     */
    void inicializaFila();
};
#include "Fila.cpp"
#endif /* FILA_HPP */
