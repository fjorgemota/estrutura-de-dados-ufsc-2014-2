// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PILHAENC_HPP
#define PILHAENC_HPP
#include "ListaEnc.hpp"

/*!
 * Classe que representa uma pilha encadeada, como tal, tem seus elementos
 * adicionados e retirados a partir do topo, no estilo first-in last-out (primeiro
 * a entrar e último a sair).
 * 
 * @see: ListaEnc::empilha()
 * @see: ListaEnc::desempilha()
 */
template <typename T>
class PilhaEnc {
 private:
    ListaEnc<T> *pilhaEnc;  //!< A lista encadeada no qual os elementos
                            //!<  da pilha serão guardados
 public:
    /*!  
     * Constrói uma pilha encadeada vazia
     */
    PilhaEnc();

    /*!
     * Adiciona ao topo da pilha um valor especificado
     * 
     * @param: dado O dado a ser adicionado na pilha
     */
    void empilha(const T& dado);

    /*!
     * Retira o último valor da pilha, ou seja, o que está menos tempo presente
     */
    T desempilha();

    /*!
     * Verifica se um dado valor pertence à pilha
     * 
     * @param dado O dado a ser verificado
     */
    bool contem(const T& dado);

    /*!
     * Verifica se a pilha está vazia
     */
    bool pilhaVazia();
};
#include "PilhaEnc.cpp"
#endif /* PILHAENC_HPP */
