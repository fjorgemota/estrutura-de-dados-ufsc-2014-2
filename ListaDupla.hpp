// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLA_HPP
#define LISTADUPLA_HPP
#include "ElementoDuplo.hpp"

/*!
 * Classe que representa uma lista duplamente encadeada, cujos elementos 
 * podem ser adicionados, removidos e vistos a partir de uma dada direçao e pelo
 * sentido contrario, inclusive.
 * 
 * @see ListaDupla::adicionaDuplo
 * @see ListaDupla::retiraDuplo
 */
template <typename T>
class ListaDupla {
 protected:
     ElementoDuplo<T> *head;  //!< Elemento duplo que representa a cabeça
                             //!< de lista
     int size;  //!< Variável que indica o tamanho da lista

 public:
    /*!
     * Constrói uma lista duplamente encadeada vazia
     */
    ListaDupla();

    /*!
     * Destrói a lista duplamente encadeada, assim como todos os seus elementos 
     * são removidos da memória
     */
    ~ListaDupla();

    /*!
     * Adiciona um novo elemento ao final da lista
     * 
     * @param dado O dado a ser armazenado na lista duplamente encadeada
     * @see ListaDupla::adicionaNoInicioDuplo
     * @see ListaDupla::adicionaNaPosicaoDuplo
     */
    virtual void adicionaDuplo(const T& dado);

    /*!
     * Adiciona um novo elemento ao início da lista
     * 
     * @param dado O dado a ser armazenado na lista duplemente encadeada
     * @see ListaDupla::adicionaDuplo
     * @see ListaDupla::adicionaNaPosicaoDuplo
     */
    virtual void adicionaNoInicioDuplo(const T& dado);

    /*!
     * Adiciona um novo elemento à lista em um determinada posição
     * 
     * @param dado O dado a ser armazenado na lista duplamente encadeada
     * @param posicao A posicao que o dado será guardado
     * @see ListaDupla::adicionaDuplo
     * @see ListaDupla::adicionaNoInicioDuplo
     */
    void adicionaNaPosicaoDuplo(const T& dado, int posicao);

    /*!
     * Adiciona o elemento à lista logo após a algum dado inferior a ele
     * 
     * @param dado O dado a ser adicionado à lista
     */
    void adicionaEmOrdem(const T& dado);

    /*!
     * Apaga o elemento localizado no inicio da lista, sem retornar seu valor
     */
    virtual void eliminaDoInicioDuplo();

    /*!
     * Remove da lista duplamente encadeada o ultimo valor armazenado, ou seja,
     * o que esta menos presente nela
     * 
     * @see ListaDupla::retiraDoInicioDuplo
     * @see ListaDupla::retiraDaPosicaoDuplo
     * @see ListaDupla::retiraEspecificoDuplo
     */
    T retiraDuplo();

    /*!
     * Remove o primeiro elemento presente da lista duplamente encadeada
     * 
     * @see ListaDupla::retiraDuplo
     * @see ListaDupla::retiraDaPosicaoDuplo
     * @see ListaDupla::retiraEspecificoDuplo
     */
    T retiraDoInicioDuplo();

    /*!
     * Remove da lista duplamente encadeada o elemento de acordo com a posição
     * especificada
     * 
     * @param posicao A posicao do dado que será removido
     * @see ListaDupla::retiraDuplo
     * @see ListaDupla::retiraDoInicioDuplo
     * @see ListaDupla::retiraEspecificoDuplo
     */
    T retiraDaPosicaoDuplo(int posicao);

    /*!
     * Remove da lista duplamente encadeada um valor especifico
     * 
     * @param dado O dado a ser removido da lista duplamente encadeada
     * @see ListaDupla::retiraDoInicioDuplo
     * @see ListaDupla::retiraDuplo
     * @see ListaDupla::retiraDaPosicao
     */
    T retiraEspecificoDuplo(const T& dado);

    /*!
     * Apaga todos os valores da lista
     */
    virtual void destroiListaDuplo();

    /*!
     * Verifica se a lista duplamente encadeada esta vazia;
     */
    bool listaVazia() const;

    /*!
     * Verifica se um dado elemento pertece à lista duplamente encadeada
     * 
     * @param dado O dado a ser verificado se está ou não presente na lista
     */
    bool contemDuplo(const T& dado);

    /*!
     * Retorna a posição de um valor especificado
     * 
     * @param dado O dado a ser verificado
     */
    int posicaoDuplo(const T& dado);

    /*!
     * Retorna a posição na memória do valor especificado conforme encontrado
     * na lista
     * 
     * @param dado O dado a ter sua posicao na memoria pesquisada
     */
    T* posicaoMemDuplo(const T& dado) const;

    /*!
     * Retorna o valor salvo na posicao especificada
     * 
     * @param pos A posicao da lista do qual o elemento deve ser retirado
     */
    T mostra(int pos);

    /*!
     * Retorna a posicao do ultimo elemento cadastrado na lista
     * 
     */
    int verUltimo();

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

    /*!
     * Converte a lista para um array pointer e retorna, que é mais rápido de 
     * nas operações de leitura. 
     */
    T* paraVetor();
};
#include "ListaDupla.cpp"
#endif /* ListaDupla_HPP */
