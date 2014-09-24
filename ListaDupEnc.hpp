// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPENC_HPP
#define LISTADUPENC_HPP
#include "ElementoDuplo.hpp"

/*!
 * Classe que representa uma lista duplamente encadeada, cujos elementos 
 * podem ser adicionados, removidos e vistos a partir de uma dada direçao e pelo
 * sentido contrario, inclusive.
 * 
 * @see: ListaDupEnc::adicionaDuplo
 * @see: ListaDupEnc::retiraDuplo
 */
template <typename T>
class ListaDupEnc {
 private:
     ElementoDuplo<T> *head;  //!< Elemento duplo que representa a cabeça
                             //!< de lista
     int size;  //!< Variável que indica o tamanho da lista

 public:
     /*!
      * Constrói uma lista duplamente encadeada vazia
      */
     ListaDupEnc();

     /*!
      * Adiciona um novo elemento ao início da lista
      * 
      * @param dado O dado a ser armazenado na lista duplemente encadeada
      * @see: ListaDupEnc::adicionaDuplo
      * @see: ListaDupEnc::adicionaNaPosicaoDuplo
      */
     void adicionaNoInicioDuplo(const T& dado);

     /*!
      * Adiciona um novo elemento à lista em um determinada posição
      * 
      * @param: dado O dado a ser armazenado na lista duplamente encadeada
      * @param: posicao A posicao que o dado será guardado
      * @see: ListaDupEnc::adicionaDuplo
      * @see: ListaDupEnc::adicionaNoInicioDuplo
      */
     void adicionaNaPosicaoDuplo(const T& dado, int posicao);

     /*!
     * Adiciona o elemento à lista logo após a algum dado inferior a ele
     * 
     * @param dado O dado a ser adicionado à lista
     */
     void adicionaEmOrdemDuplo(const T& dado);

     /*!
      * Adiciona um novo elemento ao final da lista
      * 
      * @param: dado O dado a ser armazenado na lista duplamente encadeada
      * @see: ListaDupEnc::adicionaNoInicioDuplo
      * @see: ListaDupEnc::adicionaNaPosicaoDuplo
      */
     void adicionaDuplo(const T& dado);

     /*!
      * Remove o primeiro elemento presente da lista duplamente encadeada
      * 
      * @see: ListaDupEnc::retiraDuplo
      * @see: ListaDupEnc::retiraDaPosicaoDuplo
      * @see: ListaDupEnc::retiraEspecificoDuplo
      */
     T retiraDoInicioDuplo();

     /*!
      * Remove da lista duplamente encadeada o elemento de acordo com a posição
      * especificada
      * 
      * @param: posicao A posicao do dado que será removido
      * @see: ListaDupEnc::retiraDuplo
      * @see: ListaDupEnc::retiraDoInicioDuplo
      * @see: ListaDupEnc::retiraEspecificoDuplo
      */
     T retiraDaPosicaoDuplo(int posicao);

     /*!
      * Remove da lista duplamente encadeada o ultimo valor armazenado, ou seja,
      * o que esta menos presente nela
      * 
      * @see: ListaDupEnc::retiraDoInicioDuplo
      * @see: ListaDupEnc::retiraDaPosicaoDuplo
      * @see: ListaDupEnc::retiraEspecificoDuplo
      */
     T retiraDuplo();

     /*!
      * Remove da lista duplamente encadeada um valor especifico
      * 
      * @param dado O dado a ser removido da lista duplamente encadeada
      * @see: ListaDupEnc::retiraDoInicioDuplo
      * @see: ListaDupEnc::retiraDuplo
      * @see: ListaDupEnc::retiraDaPosicao
      */
     T retiraEspecificoDuplo(const T& dado);

    /*!
     * Apaga todos os valores da lista
     */
    void destroiListaDuplo();

     /*!
      * Verifica se a lista duplamente encadeada esta vazia;
      */
     bool listaVaziaDuplo();

     /*!
      * Verifica se um dado elemento pertece à lista duplamente encadeada
      * 
      * @param dado O dado a ser verificado se está ou não presente na lista
      */
     bool contem(const T& dado);

     /*!
      * Retorna a posição de um valor especificado
      * 
      * @param: dado O dado a ser verificado
      */
     int posicaoDuplo(const T& dado);

     /*!
     * Verifica se os dois dados especificados da lista são iguais
     * 
     * @param dado1 O primeiro dado a ser comparado com o segundo
     * @param dado2 O segundo dado a ser comparado com o primeiro
     */
    bool igual(T dado1, T dado2);

    /*!
     * Verifica se o primeiro dado especificado é maior que o segundo
     * 
     * @param dado1 O primeiro dado a ser comparado com o segundo
     * @param dado2 O segundo dado a ser comparado com o primeiro
     */
    bool maior(T dado1, T dado2);

    /*!
     * Verifica se o primeiro dado especificado é menor que o segundo
     * 
     * @param dado1 O primeiro dado a ser comparado com o segundo
     * @param dado2 O segundo dado a ser comparado com a segundo
     */
    bool menor(T dado1, T dado2);
};
#include "ListaDupEnc.cpp"
#endif /* LISTADUPENC_HPP */
