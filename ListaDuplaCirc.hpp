// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLACIRC_HPP
#define LISTADUPLACIRC_HPP
#include "ListaDupla.hpp"

/*!
 * Classe que apresenta seus elementos com em uma lista duplamente encadeada, 
 * contudo, o primeiro e último elementos são interligados através de um
 * sentinela, que faz com que a lista passe a ser circular
 * 
 * @see: ListaDuplaCirc::adicionaDuplo
 * @see: ListaDuplaCirc::retiraDuplo
 * @see: ListaDuplaCirc::mostra
 */
template <typename T>
class ListaDuplaCirc: public ListaDupla<T> {
 public:
     /*!
      * Constrói uma lista duplamente encadeada circular
      */
    ListaDuplaCirc();

    /*!
     * Destrói a lista duplamente encadeada circular, assim como todos os elemen-
     * tos presentes nela
     */
    ~ListaDuplaCirc();

    /*!
     * Adiciona um novo valor ao final da lista
     * 
     * @param: dado O dado a ser adicionado na lista duplamente encadeada circular
     */
    void adicionaDuplo(const T& dado);

    /*!
     * Adiciona um novo valor no início da lista
     * 
     * @param: dado O dado a ser adicionado na lista duplamente encadeada circular
     */
    void adicionaNoInicioDuplo(const T& dado);

    /*!
     * Retira da lista o último valor adicionado nela
     */
    T retiraDuplo();

    /*!
     * Retira da lista o primeiro dado presente
     */
    virtual T retiraDoInicioDuplo();

    /*!
     * Remove da lista o primeiro valor acrescentado à lista
     */
    virtual void eliminaDoInicioDuplo();

    /*!
     * Apaga todos os valores presente na lista duplamente encadeada circular,
     * assim como todos os elementos nela então armazenados
     */
    void destroiListaDuplo();
};
#include "ListaDuplaCirc.cpp"
#endif /* LISTADUPLACIRC_HPP */
