#ifndef INDICE_HPP
#define INDICE_HPP
#include "../util/NoAVL.hpp"
#include "../util/ListaDupla.hpp"

/*!
 * Estrutura temporaria com a principal funçao de salvar
 * os conteudos de uma arvore AVL em disco, na ordem em que
 * foram referenciados
 *
 * @see: Indice::breadth_fist()
 */
template <typename T>
class Indice : public NoAVL<T> {
 protected:
 	/*!
     * Retorna um novo Indice
     *
     * @param dado O dado a ser incluído no novo Indice
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
    * Constrói um nó de Indice
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit Indice(const T& dado);

    /*!
     * Libera a memória relacionada ao Indice
     */
    virtual ~Indice();

    /*!
    * Retorna a altura do nó do Indice
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
     * Insere um determimado dado no Indice passado
     * no parâmetro arv
     * 
     * @param dado Dado a ser buscado pelo indice
     * @param arv Indice no qual o dado deve ser buscado
     */
    Indice<T>* inserir(const T& dado, Indice<T>* arv);

    /*!
     * Remove um determinado dado no Indice passado no
     * parâmetro arv
     * 
     * @param dado Dado a ser removido do Indice
     * @param arv Indice no qual o dado deve ser removido
     */
    Indice<T>* remover(Indice<T>* arv, const T& dado);

    /*!
     * Retorna o valor mínimo do Indice passado no
     * parametro nodo
     *
     * @param arv Indice do qual o valor mínimo deve ser buscado
     */
    Indice<T>* minimo(Indice<T>* nodo);

    /*!
     * Metodo que armazena os conteudos da arvore de indices
     * no disco
     */
 	ListaDupla<T* >* reversed_breadth_first();
};

#include "Indice.cpp"
#endif /** INDICE_HPP */
