// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef LISTA_HPP
#define LISTA_HPP
#define TAMANHO_MAXIMO_LISTA 30

/*!
 * Representa uma lista cujos elementos podem ser adicionados, 'pegados' de 
 * uma posição específica e removidos facilmente sem necessidade de manipulação 
 * de arranjos por quem usa esta classe
 * 
 * @see Lista::adiciona
 * @see Lista::retiraDaPosicao
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
      * Constrói uma lista vazia com o tamanho padrão (30)
      */
     Lista<T>();

    /*! 
     * Constrói uma lista vazia com o tamanho máximo especificado
     * 
     * @param tamanho O número máximo de elementos que a lista pode conter
     */
    explicit Lista<T>(int tamanhoMaximo);

    /*!
     * Adiciona um valor à lista
     * 
     * @param obj O objeto a ser adicionado na lista
     * @see Lista::adicionaNaPosicao
     * @see Lista::adicionaEspecifico
     * @see Lista::adicionaEmOrdem
     */
    void adiciona(T obj);

    /*!
     * Um novo dado é adicionado à primeira posição, enquanto os então presentes
     * são "empurrados" para cima para a adiçao do dado
     * 
     * @param dado O dado a ser adicionado no início da lista
     * @see Lista::adiciona
     * @see Lista::adicionaEmOrdem
     * @see Lista::adicionaEspecifico
     */
    void adicionaNoInicio(T dado);

    /*!
     * Pega o valor do primeiro elemento inserido na lista, 
     * que está, portanto, mais tempo presente na lista
     * 
     * @see Lista::pegaValor
     */
    T pegaPrimeiro();

    /*!
     * Adiciona um dado valor a uma posição especificada, enquanto os dados então
     * presentes são "empurrados" para cima para a entrada do novo dado
     * 
     * @param dado O dado a ser adicionado
     * @param destino A posição na qual o dado será armazenado
     * @see Lista::adiciona
     * @see Lista::adicionaEmOrdem
     * @see Lista::adicionaNoInicio
     */
    void adicionaNaPosicao(T dado, int destino);

    /*!
     * Adiciona o elemento à lista logo após a algum dado inferior a ele
     * 
     * @param dado O dado a ser adicionado à lista
     * @see Lista::insertionSort
     */
    void adicionaEmOrdem(T dado);

    /*!
     * Remove o último elemento inserido na lista, que é, portanto, 
     * o valor que está menos tempo presente na lista
     * 
     * @see Lista::retiraDaPosicao
     * @see Lista::retiraDoInicio
     * @see Lista::retiraEspecifico
     */
    T retira();

    /*!
     * Remove o primeiro valor inserido na lista, que é, portanto, 
     * o valor que está mais tempo presente na lista
     * 
     * @see Lista::retiraDaPosicao
     * @see Lista::retira
     * @see Lista::retiraEspecifico
     */
    T retiraDoInicio();

    /*!
     * Remove um valor da posição especificado pelo usuário
     * 
     * @param posicao Posição do elemento que vai ser removido
     * @see Lista::retiraDoInicio
     * @see Lista::removerUltimo
     * @see Lista::retira
     * @see Lista::troca
     */
    T retiraDaPosicao(int posicao);

    /*!
     * Retira da lista o valor especificado
     * 
     * @param dado O dado a ser removido da lista
     */
    T retiraEspecifico(T dado);

    /*!
     * Retorna o número de elementos presentes na lista atualmente
     */
    int pegaTamanho();

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
    void destroiLista();

    /*!
     * Verifica se um dado especificado pertence à lista
     * 
     * @param dado O valor especificado que pode ou não estar na lista
     */
    bool contem(T dado);

    /*!
     * Retorna o valor do atributo interno topo
     */
    int pegaTopo();

    /*!
     * Retorna a posição de um dado especificado
     * 
     * @param dado O dado cuja posiçao sera retornada
     */
    int posicao(T dado);

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
     * Organiza os dados de um vetor em ordem crescente
     */
    void insertionSort();
};
#include "Lista.cpp"
#endif /* LISTA_HPP */
