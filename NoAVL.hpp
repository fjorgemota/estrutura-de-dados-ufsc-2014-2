// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <vector>
#include "NoBinario.hpp"

/*!
 * Representa um nó AVL, sendo assim podendo representar uma árvore AVL,
 * que é também uma binária, tendo as mesmas funções básicas. A exclusividade 
 * da árvore AVL é o atributo altura, que mantém o balanceamento e evita
 * deteriorizações, portanto, um nó nunca pode ter a subtração das alturas dos
 * respectivos descendentes maior que um (desequilíbrio à direita) ou menor
 * que um (desequilíbrio à esquerda), sendo que tais problemas são resolvidos
 * através de rotações simples ou duplas na árvore.
 *
 * @see NoAVL<T>::rotacaoSimplesEsquerda()
 * @see NoAVL<T>::rotacaoSimplesDireita()
 * @see NoAVL<T>::getAltura();
 */
template <typename T>
class NoAVL : public NoBinario<T> {
 protected:
    int altura;  //!< Representa a altura do nó AVL

    /*!
     * Retorna um novo nó AVL
     *
     * @param dado O dado a ser incluído no novo nó
     */
    virtual NoAVL<T>* pegaNovoNo(const T& dado);

    /*!
     * Método que balanceia a árvore a medida que os valores
     * são adicionados
     *
     * @param arv A árvore que será balanceada
     */
    virtual NoAVL<T>* balanco_insere(NoBinario<T>* arv);

    /*!
     * Método que balanceia a árvore a medida que os valores
     * são removidos
     *
     * @param arv A árvore que será balanceada
     */
    virtual NoAVL<T>* balanco_remove(NoBinario<T>* arv);

     /*!
      * Método que converte nós de árvore binária para nós de
      * AVL, isto é, incluindo um atributo altura neles
      *
      * @param binario A árvore binária que será convertida
      */
    NoAVL<T>* binarioParaAVL(NoBinario<T> *binario);

     /*!
      * Verifica e retorna a subtração de dois nós descendentes
      *
      * @param raiz Nó cujo balanceamento será feito
      */
    int pegaBalanceamento(NoAVL<T>* raiz);

     /*!
      * Atualiza a altura de um nó
      *
      * @param raiz Nó cuja altura será atualizada
      */
    void atualizaAltura(NoAVL<T>* raiz);

    /*!
     * Realiza uma rotação simples à esquerda. 
     * Se houver um desbalanceamento à direita, uma
     * rotação simples à esquerda resolve o problema
     * 
     * @param raiz A árvore a ser rotacionada
     */
    NoAVL<T>* rotacaoSimplesEsquerda(NoAVL<T>* raiz);

    /*!
     * Realiza uma rotação simples à direita. 
     * Se houver um desbalanceamento à esquerda, uma
     * rotação simples à direita resolve o problema
     * 
     * @param raiz A árvore a ser rotacionada
     */
    NoAVL<T>* rotacaoSimplesDireita(NoAVL<T>* raiz);

    /*!
    * Método que verifica o balanceamento e qual rotação 
    * necessária realizar após a adição/remoção de um nó
    *
    * @param raiz Árvore que será balanceada e/ou rotacionada
    */
    NoAVL<T>* balancear(NoAVL<T>* raiz);

    /*!
     * Retorna a altura máxima entre dois nós
     *
     * @param no1 Nó cuja altura será comparada com o segundo nó
     * @param no2 Nó cuja altura será comparada com o primeiro nó
     */
    int maximo(NoAVL<T>* no1, NoAVL<T>* no2);

 public:
    /*!
    * Constrói um nó AVL
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit NoAVL(const T& dado);

    /*!
     * Libera a memória relacionada ao nó AVL
     */
    virtual ~NoAVL();

    /*!
    * Retorna a altura do nó AVL
    */
    int getAltura();

    /** Métodos sobrescritos */

    /*!
    * Retorna os elementos percorridos pelos métodos de percurso
    */
    std::vector<NoAVL<T>* > getElementos();

    /*!
     * Retorna o filho da esquerda da raiz
     */
    NoAVL<T>* getEsquerda();

    /*!
     * Retorna o filho da direita da raiz
     */
    NoAVL<T>* getDireita();

    /*!
     * Insere um determimado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv);

    /*!
     * Remove um determinado dado da árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser removido da árvore
     * @param arv Árvore no qual o dado deve ser removido
     */
    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado);

    /*!
     * Retorna o valor mínimo guardado na árvore representada
     * pelo nó binário passado no parãmetro arv
     *
     * @param arv Árvore do qual o valor mínimo deve ser buscado
     */
    NoAVL<T>* minimo(NoAVL<T>* nodo);
};

#include "NoAVL.cpp"
#endif /* NO_AVL_HPP */
