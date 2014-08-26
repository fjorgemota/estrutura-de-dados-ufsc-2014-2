// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PILHA_HPP
#define	PILHA_HPP
#include "Lista.hpp"
//template <typename Lista>
/*!
 * Representa uma pilha. Estrutura que a cada novo elemento, pode ser adicionado
 * e removido apenas pelo topo. Tal valor pode ser verificado, assim como a sua
 * posiçao.
 * 
 * @see Pilha::empilha()
 * @see Pilha::desempilha()
 * @see Pilha::Topo()
 */
class Pilha {
public:
    /*!
     * Constrói uma pilha vazia
     * 
     * @param t O tamanho da pilha especificado pelo usuário
     */
    //Pilha();
    Pilha(int t);
    
    /*!
     * Adiciona um novo valor à pilha 
     * 
     * @param dado O dado a ser adicionado para a pilha
     * @see Lista::adicionar()
     */
    void empilha(int dado);
    
    /*!
    * Remove um valor da pilha, isto é, que está armazenado no topo
    * 
    * @see Lista::removerUltimo()
    * @see Pilha::Topo()
    */
    int desempilha();
    
    /*!
     * Apresenta o valor que está no topo
     */
    int topo();
    
    /*!
     * Mostra posição em que o valor topo está armazenado
     */
    int getPosTopo();
    
    /*!
     * Apaga todos os valores presentes na pilha
     */
    void limparPilha();
    
    /*!
     * Verifica se a pilha não contém nenhum elemento
     * 
     * @see Pilha::PilhaCheia()
     */
    bool PilhaVazia();
    
    /*!
     * Verifica se a pilha possui o número máximo de elementos armazenáveis
     * 
     * @see Pilha::PilhaVazia()
     */
    bool PilhaCheia();
private:
    Lista* lista;
};

#endif	/* PILHA_HPP */