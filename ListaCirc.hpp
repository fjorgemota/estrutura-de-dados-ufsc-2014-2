// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTACIRC_HPP
#define LISTACIRC_HPP

#include "ListaEnc.hpp"

/*!
 * Representa uma lista cujos elementos podem ser adicionados, 'pegados' de 
 * uma posição específica e removidos facilmente sem necessidade de manipulação 
 * de arranjos por quem usa esta classe e de forma circular
 * 
 * @see ListaCirc::adiciona
 * @see ListaCirc::retiraDaPosicao
 * @see ListaCirc::pegaValor
 */
template <typename T>
class ListaCirc: public ListaEnc<T> {
 public:
    /*!
     * Constroi uma lista circular 
     */
    ListaCirc();

    /*!
     * Apaga todos os elementos da lista circular
     */
    ~ListaCirc();

    /*!
     * Adiciona um determinado valor ao final da lista circular
     * 
     * @param dado O objeto a ser adicionado na lista
     */
    void adiciona(const T& dado);

    /*!
     * Adiciona um determinado valor no inicio da lista circular
     * 
     * @param dado O objeto a ser adicionado na lista
     */
    void adicionaNoInicio(const T& dado);

    /*!
     * Remove o primeiro valor inserido na lista e retorna o valor do elemento
     * retirado
     * 
     * @see ListaCirc::retiraDaPosicao
     * @see ListaCirc::retira
     * @see ListaCirc::retiraEspecifico
     */
    virtual T retiraDoInicio();

    /*!
     * Remove o primeiro valor inserido na lista sem retornar o valor do 
     * elemento retirado
     *
     * @see ListaCirc::retiraDaPosicao
     * @see ListaCirc::retira
     * @see ListaCirc::retiraEspecifico
     */
    virtual void eliminaDoInicio();

    /*!
     * Retorna o valor do elemento encontrado na posição especificada
     * 
     * @param pos A posição do elemento que vai ter seu valor retornado
     */
    T mostra(int pos);

    /*!
     * Retorna a posição do último elemento presente na lista
     */
    int verUltimo();

    /*!
     * Apaga todos os elementos da lista circular
     */
    void destroiLista();
};

#include "ListaCirc.cpp"
#endif /* LISTACIRC_HPP */
