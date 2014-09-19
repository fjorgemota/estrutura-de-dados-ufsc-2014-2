// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FILAENC_HPP
#define FILAENC_HPP
#include "ListaEnc.hpp"

/*!
 * Classe que representa uma Fila encadeada, como tal, tem seus elementos
 * adicionados a partir do inicio da lista e retirados do final da lista,
 * no estilo first-in first-out (primeiro a entrar e primeiro a sair).
 * 
 * @see FilaEnc::adiciona
 * @see FilaEnc::retira
 */
template <typename T>
class FilaEnc {
 private:
    ListaEnc<T> *listaEnc;  //!< Lista encadeada no qual os leementos da fila
                            //!< sao inseridos.
 public:
    /*!
     * Constroi uma fila encadeada vazia
     */
    FilaEnc();

    /*!
     * Adiciona um elemento no inicio da fila.
     * 
     * @param dado Elemento a ser inserido
     */
    void adiciona(T dado);

    /*!
     * Retira um elemento do final da fila.
     */
    T retira();

    /*!
     * Retira um elemento do inicio da lista
     */
    T retiraDoInicio();
};

#include "FilaEnc.cpp"
#endif /* FILAENC_HPP */
