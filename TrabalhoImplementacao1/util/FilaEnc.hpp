// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FILAENC_HPP
#define FILAENC_HPP
#include "ListaEnc.hpp"

/*!
 * Classe que representa uma Fila encadeada, como tal, tem seus elementos
 * adicionados a partir do inicio da lista e retirados do final da lista,
 * no estilo first-in first-out (primeiro a entrar e primeiro a sair).
 * 
 * @see FilaEnc::inclui
 * @see FilaEnc::retira
 */
template <typename T>
class FilaEnc {
 private:
    ListaEnc<T> *listaEnc;  //!< Lista encadeada no qual os elementos da fila
                            //!< sao inseridos.
 public:
    /*!
     * Constroi uma fila encadeada vazia
     */
    FilaEnc();

    /*!
     * Destrói a fila encadeada assim como os valores armazenados nela
     */
    ~FilaEnc();

    /*!
     * Adiciona um elemento no inicio da fila.
     * 
     * @param dado Elemento a ser inserido
     */
    void inclui(T dado);

    /*!
     * Retira um elemento do final da fila.
     */
    T retira();

    /*!
     * Retorna o valor do ultimo valor presente na fila, ou seja, o que esta 
     * menos tempo nela
     */
    T ultimo();

    /*!
     * Retorna o valor do primeiro valor presente na fila, ou seja, o que esta
     * mais tempo nela
     */
    T primeiro();

    /*!
     * Apaga todos os valores presentes na fila encadeada
     */
    void limparFila();

    /*!
     * Informa se a fila encadeada esta vazia
     */
    bool filaVazia();

    /*!
     * Retira um elemento do inicio da fila
     */
    T retiraDoInicio();
};

#include "FilaEnc.cpp"
#endif /* FILAENC_HPP */
