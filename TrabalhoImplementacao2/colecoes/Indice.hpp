#ifndef INDICE_HPP
#define INDICE_HPP
#include "../util/NoAVL.hpp"
#include "../util/ListaDupla.hpp"

template <typename T>
class Indice : public NoAVL<T> {
 protected:
 	/*!
     * Retorna um novo Indice
     *
     * @param dado O dado a ser incluído no novo nó
     */
    virtual Indice<T>* pegaNovoNo(const T& dado);

     /*!
      * Método que converte nós de árvore AVL para nós de
      * Indice
      *
      * @param avl A árvore AVL que será convertida
      */
    Indice<T>* AVLParaIndice(NoAVL<T> *avl);
 public:
 	/*!
    * Constrói um nó AVL
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit Indice(const T& dado);

    /*!
     * Libera a memória relacionada ao nó AVL
     */
    virtual ~Indice();

    /*!
    * Retorna a altura do nó AVL
    */
    int getAltura();

    /** Métodos sobrescritos */

    /*!
    * Retorna os elementos percorridos pelos métodos de percurso
    */
    std::vector<Indice<T>* > getElementos();

    /*!
     * Retorna o filho da esquerda da raiz
     */
    Indice<T>* getEsquerda();

    /*!
     * Retorna o filho da direita da raiz
     */
    Indice<T>* getDireita();

    /*!
     * Insere um determimado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    Indice<T>* inserir(const T& dado, Indice<T>* arv);

    /*!
     * Remove um determinado dado da árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser removido da árvore
     * @param arv Árvore no qual o dado deve ser removido
     */
    Indice<T>* remover(Indice<T>* arv, const T& dado);

    /*!
     * Retorna o valor mínimo guardado na árvore representada
     * pelo nó binário passado no parãmetro arv
     *
     * @param arv Árvore do qual o valor mínimo deve ser buscado
     */
    Indice<T>* minimo(Indice<T>* nodo);

 	ListaDupla<T > breadth_first();
};

#include "Indice.cpp"
#endif /** INDICE_HPP */
