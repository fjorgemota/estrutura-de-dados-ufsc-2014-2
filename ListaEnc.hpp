// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_ENCADEADA_HPP
#include "Elemento.hpp"
#define LISTA_ENCADEADA_HPP
#define PRIMEIRO_ELEMENTO 0

/*!
 * Representa uma lista cujos elementos podem ser adicionados, 'pegados' de 
 * uma posição específica e removidos facilmente sem necessidade de manipulação 
 * de arranjos por quem usa esta classe
 * 
 * @see ListaEncadeada::adiciona
 * @see ListaEncadeada::retiraDaPosicao
 * @see ListaEncadeada::pegaValor
 */
template <typename T>
class ListaEnc {
 protected:
    Elemento<T> *head;  //!< Onde é guardado os valores salvos na lista
    int size;  //!< Tamanho máximo da lista

 public:
     /*!
      * Constrói uma lista encadeada vazia
      */
    ListaEnc();

     /*!
      * Libera toda a memória possível da lista. Eliminando-a da memória
      */
    ~ListaEnc();

    /*!
     * Adiciona um valor à lista
     * 
     * @param obj O objeto a ser adicionado na lista
     * @see ListaEncadeada::adicionaNaPosicao
     * @see ListaEncadeada::adicionaEmOrdem
     */
    virtual void adiciona(const T& dado);

    /*!
     * Um novo dado é adicionado à primeira posição, enquanto os então presentes
     * são "empurrados" para cima para a adiçao do dado
     * 
     * @param dado O dado a ser adicionado no início da lista
     * @see ListaEncadeada::adiciona
     * @see ListaEncadeada::adicionaEmOrdem
     * @see ListaEncadeada::adicionaEspecifico
     */
    virtual void adicionaNoInicio(const T& dado);

    /*!
     * Adiciona um dado valor a uma posição especificada, enquanto os dados então
     * presentes são "empurrados" para cima para a entrada do novo dado
     * 
     * @param dado O dado a ser adicionado
     * @param destino A posição na qual o dado será armazenado
     * @see ListaEncadeada::adiciona
     * @see ListaEncadeada::adicionaEmOrdem
     * @see ListaEncadeada::adicionaNoInicio
     */
    void adicionaNaPosicao(const T& dado, int destino);

    /*!
     * Adiciona o elemento à lista logo após a algum dado inferior a ele
     * 
     * @param dado O dado a ser adicionado à lista
     */
    void adicionaEmOrdem(const T& dado);

    /*!
     * Remove o último elemento inserido na lista, que é, portanto, 
     * o valor que está menos tempo presente na lista
     * 
     * @see ListaEncadeada::retiraDaPosicao
     * @see ListaEncadeada::retiraDoInicio
     * @see ListaEncadeada::retiraEspecifico
     */
    T retira();

    /*!
     * Remove o primeiro valor inserido na lista, que é, portanto, 
     * o valor que está mais tempo presente na lista. E retorna tal valor
     * 
     * @see ListaEncadeada::retiraDaPosicao
     * @see ListaEncadeada::retira
     * @see ListaEncadeada::retiraEspecifico
     */
    virtual T retiraDoInicio();

    /*!
     * Remove o primeiro valor inserido na lista, que é, portanto,
     * o valor que está mais tempo presente na lista
     *
     *  @see ListaEncadeada::retiraDaPosicao
     * @see ListaEncadeada::retira
     * @see ListaEncadeada::retiraEspecifico
     */
    virtual void eliminaDoInicio();

    /*!
     * Remove um valor da posição especificado pelo usuário
     * 
     * @param posicao Posição do elemento que vai ser removido
     * @see ListaEncadeada::retiraDoInicio
     * @see ListaEncadeada::removerUltimo
     * @see ListaEncadeada::retira
     * @see ListaEncadeada::troca
     */
    T retiraDaPosicao(int posicao);

    /*!
     * Retira da lista o valor especificado
     * 
     * @param dado O dado a ser removido da lista
     */
    T retiraEspecifico(T dado);

    /*!
     * Apaga todos os valores da lista
     */
    void destroiLista();

    /*!
     * Retorna um booleano indicando se a lista está vazia ou não
     */
    bool listaVazia() const;

    /*!
     * Verifica se um dado especificado pertence à lista
     * 
     * @param dado O valor especificado que pode ou não estar na lista
     */
    bool contem(const T& dado);

    /*!
     * Retorna a posição de um dado especificado
     * 
     * @param dado O dado cuja posiçao sera retornada
     */
    int posicao(const T& dado);

    /*!
     * Retorna a posição da memória de um dado especificado
     * 
     * @param dado O dado cuja posiçao sera retornada
     */
    T* posicaoMem(const T& dado) const;

    /*!
     * Retorna o valor que está armazenado no início da lista encadeada
     */
    T topo();

    /*!
     * Retorna o último valor presente na lista encadeada
     */
    T ultimo();

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
#include "ListaEnc.cpp"
#endif /* LISTA_ENCADEADA_HPP */
