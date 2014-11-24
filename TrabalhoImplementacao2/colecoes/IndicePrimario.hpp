#ifndef INDICE_PRIMARIO_HPP
#define INDICE_PRIMARIO_HPP

#include "Indice.hpp"
#include "../modelos/ManPage.hpp"

class IndicePrimario : public Indice<ManPage> {
 protected:
 	/*!
     * Retorna um novo IndicePrimario
     *
     * @param dado O dado a ser incluído no novo nó
     */
    virtual IndicePrimario* pegaNovoNo(const ManPage& dado);

     /*!
      * Método que converte nós de árvore AVL para nós de
      * IndicePrimario
      *
      * @param avl A árvore AVL que será convertida
      */
    IndicePrimario* IndiceParaIndicePrimario(Indice<ManPage> *avl);

 public:
    /*!
    * Constrói um nó AVL
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit IndicePrimario(const ManPage& dado);

    /*!
     * Libera a memória relacionada ao nó AVL
     */
    virtual ~IndicePrimario();

    /*!
    * Retorna a altura do nó AVL
    */
    int getAltura();

    /** Métodos sobrescritos */

    /*!
    * Retorna os elementos percorridos pelos métodos de percurso
    */
    std::vector<IndicePrimario* > getElementos();

    /*!
     * Retorna o filho da esquerda da raiz
     */
    IndicePrimario* getEsquerda();

    /*!
     * Retorna o filho da direita da raiz
     */
    IndicePrimario* getDireita();

    /*!
     * Insere um determimado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    IndicePrimario* inserir(const ManPage& dado, IndicePrimario* arv);

    /*!
     * Remove um determinado dado da árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser removido da árvore
     * @param arv Árvore no qual o dado deve ser removido
     */
    IndicePrimario* remover(IndicePrimario* arv, const ManPage& dado);

    /*!
     * Retorna o valor mínimo guardado na árvore representada
     * pelo nó binário passado no parãmetro arv
     *
     * @param arv Árvore do qual o valor mínimo deve ser buscado
     */
    IndicePrimario* minimo(IndicePrimario* nodo);

 	ListaDupla<ManPage > breadth_first();
};

#include "IndicePrimario.cpp"

#endif /** INDICE_PRIMARIO_HPP */