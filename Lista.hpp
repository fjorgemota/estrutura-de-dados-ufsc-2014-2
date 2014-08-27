// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_HPP
#define	LISTA_HPP
template <typename T>

/*!
 * Representa uma lista cujos elementos podem ser adicionados, 'pegados' de 
 * uma posição específica e removidos facilmente sem necessidade de manipulação 
 * de arranjos por quem usa esta classe.
 * 
 * @see Lista::adicionar
 * @see Lista::remover
 * @see Lista::pegaValor
 */
class Lista {
public:
    /*! 
     * Constrói uma lista vazia com o tamanho máximo especificado.
     * 
     * @param tamanho O número máximo de elementos que a lista pode conter.
     */
    Lista(int tamanhoMaximo);
    
    /*!
     * Adiciona um valor à lista.
     * 
     * @param obj O objeto à ser adicionado na lista
     */
    void adicionar(T obj); 
    
    /*!
     * Retorna o numero de elementos presentes na lista atualmente
     */
    int pegaTamanho();
    
    /*!
     * Remove um valor da posicao especificado pelo usuário.
     * 
     * @param posicao Posição do elemento que vai ser removido
     * @see Lista::removerPrimeiro
     * @see Lista::removerUltimo
     * @see Lista::troca
     */
    void remover(int posicao);
    
    /*!
     * Remove o primeiro valor inserido na lista, que é, portanto, 
     * o valor que está  à mais tempo presente na lista.
     * 
     * @see Lista::remover
     */
    void removerPrimeiro();
    
    /*!
     * Remove o último elemento inserido na lista, que é, portanto, 
     * o valor que está à menos tempo presente na lista.
     * 
     * @see Lista::remover
     */
    void removerUltimo();
    
    /*!
     * Pega o valor do primeiro elemento inserido na lista, 
     * que está, portanto, a mais tempo presente na lista.
     * 
     * @see Lista::pegaValor
     */
    int pegaPrimeiro();
    
    /*!
     * Pega o valor do ultimo elemento adicionado, 
     * que está, portanto, a menos tempo presente na lista.
     * 
     * @see Lista::pegaValor
     */
    int pegaUltimo();
    
    /*!
     * Pega o valor da posição especificada.
     * 
     * @param A posição do qual o elemento deve ser retirado
     * @see Lista::pegaUltimo
     * @see Lista::pegaPrimeiro
     */
    int pegaValor(int posicao); 
    
    /*!
     * Realiza a troca de posição entre dois elementos da lista.
     * 
     * @param posicao1 Posição do 1º elemento cujo valor que vai ser trocado com o do 2º elemento
     * @param posicao2 Posição do 2º elemento cujo valor vai ser trocado com o do 1º elemento
     */
    void troca(int posicao1, int posicao2);
    
    /*!
     * Retorna um booleano indicando se a lista está cheia ou não.
     */
    bool listaCheia();
    
    /*!
     * Retorna um booleano indicando se a lista está vazia ou não.
     */
    bool listaVazia();
    
    /*!
     * Apaga todos os valores da lista, sem alterar seu tamanho original.
     */
    void limpaLista();
    
private:
    T* arranjo; //! < É onde é guardado os valores salvos na lista. 
    int topo; //! < O topo é a última posição, de baixo para cima.
    int tamanhoMaximo; //! < Tamanho máximo da lista
};

#endif	/* LISTA_HPP */
