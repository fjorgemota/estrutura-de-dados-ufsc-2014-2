// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_HPP
#define LISTA_HPP

/*!
 * Representa uma lista cujos elementos podem ser adicionados, 'pegados' de 
 * uma posição específica e removidos facilmente sem necessidade de manipulação 
 * de arranjos por quem usa esta classe
 * 
 * @see Lista::adicionar
 * @see Lista::remover
 * @see Lista::pegaValor
 */
template <typename T>
class Lista {
 private:
    T* arranjo;  //! < Onde é guardado os valores salvos na lista
    int topo;  //! < O topo é a última posição, de baixo para cima
    int tamanhoMaximo;  //! < Tamanho máximo da lista

 public:
    /*! 
     * Constrói uma lista vazia com o tamanho máximo especificado
     * 
     * @param tamanho O número máximo de elementos que a lista pode conter
     */
    Lista<T>(int tamanhoMaximo);

    /*!
     * Adiciona um valor à lista
     * 
     * @param obj O objeto a ser adicionado na lista
     */
    void adicionar(T obj);

    /*!
     * Retorna o número de elementos presentes na lista atualmente
     */
    int pegaTamanho();

    /*!
     * Remove um valor da posição especificado pelo usuário
     * 
     * @param posicao Posição do elemento que vai ser removido
     * @see Lista::removerPrimeiro
     * @see Lista::removerUltimo
     * @see Lista::troca
     */
    void remover(int posicao);

    /*!
     * Remove o primeiro valor inserido na lista, que é, portanto, 
     * o valor que está mais tempo presente na lista
     * 
     * @see Lista::remover
     */
    void removerPrimeiro();

    /*!
     * Remove o último elemento inserido na lista, que é, portanto, 
     * o valor que está menos tempo presente na lista
     * 
     * @see Lista::remover
     */
    void removerUltimo();

    /*!
     * Pega o valor do primeiro elemento inserido na lista, 
     * que está, portanto, mais tempo presente na lista
     * 
     * @see Lista::pegaValor
     */
    T pegaPrimeiro();

    /*!
     * Pega o valor do último elemento adicionado, 
     * que está, portanto, menos tempo presente na lista
     * 
     * @see Lista::pegaValor
     */
    T pegaUltimo();

    /*!
     * Pega o valor da posição especificada
     * 
     * @param A posição do qual o elemento deve ser retirado
     * @see Lista::pegaUltimo
     * @see Lista::pegaPrimeiro
     */
    T pegaValor(int posicao);

    /*!
     * Realiza a troca de posição entre dois elementos da lista
     * 
     * @param posicao1 Posição do 1º elemento cujo valor que vai ser trocado com o do 2º elemento
     * @param posicao2 Posição do 2º elemento cujo valor vai ser trocado com o do 1º elemento
     */
    void troca(int posicao1, int posicao2);

    /*!
     * Retorna um booleano indicando se a lista está cheia ou não
     */
    bool listaCheia();

    /*!
     * Retorna um booleano indicando se a lista está vazia ou não
     */
    bool listaVazia();

    /*!
     * Apaga todos os valores da lista
     */
    void limpaLista();

    /*!
     * Retorna o valor interno do topo
     */
    int pegaTopo();
};
#include "Lista.cpp"
#endif /* LISTA_HPP */
