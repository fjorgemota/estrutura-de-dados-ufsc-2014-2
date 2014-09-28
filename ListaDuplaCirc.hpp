// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTADUPLACIRC_HPP
#define LISTADUPLACIRC_HPP
#include "ElementoDuplo.hpp"

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
class ListaDuplaCirc {
 protected:
     ElementoDuplo<T> *sentinela;  //!< Elemento sentinela que apontará para o
                                  //!< começo e final da lista circular
     int size;  //!< Tamanho da lista duplamente encadeada circular

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
     * @see: ListaDuplaCirc::adicionaNoInicioDuplo
     * @see: ListaDuplaCirc::adicionaNaPosicao
     * @see: ListaDuplaCirc::adicionaEmOrdem
     */
    void adicionaDuplo(const T& dado);

    /*!
     * Adiciona um novo valor no início da lista
     * 
     * @param: dado O dado a ser adicionado na lista duplamente encadeada circular
     * @see: ListaDuplaCirc::adicionaDuplo
     * @see: ListaDuplaCirc::adicionaNaPosicaoDuplo
     * @see: ListaDuplaCirc::adicionaEmOrdemDuplo
     */
    void adicionaNoInicioDuplo(const T& dado);

    /*!
     * Adiciona um novo valor à lista de acordo com a posição especificada
     * 
     * @param: dado O dado a ser adicionado na lista duplamente encadeada circular
     * @param pos A posicao em que o dado será adicionado
     * @see: ListaDuplaCirc::adicionaDuplo
     * @see: ListaDuplaCirc::adicionaNoInicioDuplo
     * @see:ListaDuplaCirc::adicionaEmOrdemDuplo
     */
    void adicionaNaPosicaoDuplo(const T& dado, int pos);

    /*!
     * Adiciona um novo valor à lista logo após a um valor inferior ao especificado
     * 
     * @param: dado O dado a ser adicionado na lista duplamente encadeada circular
     * @see: ListaDuplaCirc::adicionaDuplo
     * @see: ListaDuplaCirc::adicionaNoInicioDuplo
     * @see: ListaDuplaCirc::adicionaNaPosicaoDuplo
     */
    void adicionaEmOrdem(const T& data);

    /*!
     * Retira da lista o último valor adicionado nela
     * 
     * @see: ListaDuplaCirc::retiraDoInicioDuplo
     * @see: ListaDuplaCirc::retiraDaPosicaoDuplo
     * @see: ListaDuplaCirc::retiraEspecificoDuplo
     */
    T retiraDuplo();

    /*!
     * Retira da lista o primeiro dado presente
     * 
     * @see: ListaDuplaCirc::retiraDuplo
     * @see: ListaDuplaCirc::retiraDaPosicaoDuplo
     * @see: ListaDuplaCirc::retiraEspecificoDuplo
     */
    T retiraDoInicioDuplo();

    /*!
     * Retira um dado da lista de acordo com a posição especificada
     * 
     * @param: pos A posição do dado que será retirado
     * @see: ListaDuplaCirc::retiraDuplo
     * @see: ListaDuplaCirc::retiraDoInicioDuplo
     * @see: ListaDuplaCirc::retiraEspecificoDuplo
     */
    T retiraDaPosicaoDuplo(int pos);

    /*!
     * Retira da lista o dado especificado
     * 
     * @param: dado O dado a ser removido da lista duplamente encadeada circular
     * @see: ListaDuplaCirc::retiraDuplo
     * @see: ListaDuplaCirc::retiraDoInicioDuplo
     * @see: ListaDuplaCirc::retiraDaPosicaoDuplo
     */
    T retiraEspecificoDuplo(const T& dado);

    /*!
     * Remove da lista o primeiro valor acrescentado à lista
     * 
     * @see: ListaDuplaCirc::retiraDuplo
     * @see: ListaDuplaCirc::retiraDoInicioDuplo
     * @see: ListaDuplaCirc::retiraDaPosicaoDuplo
     * @see: ListaDuplaCirc::retiraEspecificoDuplo
     */
    void eliminaDoInicioDuplo();

    /*!
     * Informa a posição de um dado especificado
     * 
     * @param: dado O dado cuja posição será mostrada
     */
    int posicaoDuplo(const T& dado) const;

    /*!
     * Retorna a posição de memória de um dado especificado
     * 
     * @param: dado O dado cuja posição de memória será revelada
     */
    T* posicaoMemDuplo(const T& dado) const;

    /*!
     * Informa se um dado especificado está ou não presente na lista
     * 
     * @param: dado O dado que será avalidado se está presente na lista
     */
    bool contemDuplo(const T& dado);

    /*!
     * Retorna o dado de acordo com a posição especificada
     * 
     * @param: pos A posição da lista o qual o elemento será retirado
     */
    T mostra(int pos);

    /*!
     * Retorna a posição do último elemento presente na lista
     */
    int verUltimo();

    /*!
     * Mostra se a lista duplamente encadeada circular está vazia
     */
    bool listaVazia() const;

    /*!
     * Imprime todos os valores presente na lista duplamente encadeada circular
     */
    void imprimeLista();

    /*!
     * Apaga todos os valores presente na lista duplamente encadeada circular,
     * assim como todos os elementos nela então armazenados
     */
    void destroiListaDuplo();

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
#include "ListaDuplaCirc.cpp"
#endif /* LISTADUPLACIRC_HPP */
