// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PILHA_HPP
#define PILHA_HPP
#include "Lista.hpp"
#define TAMANHO_MAXIMO_PILHA 30

/*!
 * Representa uma pilha. Estrutura que a cada novo elemento, pode ser adicionado
 * e removido apenas pelo topo, tal valor pode ser verificado, assim como a sua
 * posiçao
 * 
 * @see Pilha::empilha()
 * @see Pilha::desempilha()
 * @see Pilha::topo()
 */
template <typename T>
class Pilha {
 private:
    Lista<T> *lista;  //! < A lista no qual os elemetos da pilha serão guardados

 public:
    /*!
     * Constrói uma pilha vazia com um tamanho padrão (30)
     */
    Pilha();

    /*!
     * Constrói uma pilha vazia
     * 
     * @param t O tamanho da pilha especificado pelo usuário
     */
    Pilha<T>(int t);

    /*!
     * Adiciona um novo valor à pilha 
     * 
     * @param dado O dado a ser adicionado para a pilha
     * @see Lista::adicionar()
     */
    void empilha(T dado);

    /*!
    * Remove um valor da pilha, isto é, que está armazenado no topo
    * 
    * @see Lista::removerUltimo()
    * @see Pilha::topo()
    */
    T desempilha();

    /*!
     * Apresenta o valor que está no topo
     */
    T topo();

    /*!
     * Mostra posição em que o valor topo está armazenado
     */
    int getPosTopo();

    /*!
     * Apaga todos os valores presentes na pilha, mantendo seu tamanho original
     * 
     * @see Lista::limpaLista()
     */
    void limparPilha();

    /*!
     * Verifica se a pilha não contém nenhum elemento
     */
    bool PilhaVazia();

    /*!
     * Verifica se a pilha possui o número máximo de elementos armazenáveis
     */
    bool PilhaCheia();
};

#endif /* PILHA_HPP */
