#ifndef INDICE_SECUNDARIO_HPP
#define INDICE_SECUNDARIO_HPP

#include "Indice.hpp"
#include "../modelos/Word.hpp"

class IndiceSecundario : public Indice<Word> {
 protected:
 	/*!
     * Retorna um novo IndiceSecundario
     *
     * @param dado O dado a ser incluído no novo nó
     */
    virtual IndiceSecundario* pegaNovoNo(const Word& dado);

     /*!
      * Método que converte nós de árvore AVL para nós de
      * IndiceSecundario
      *
      * @param avl A árvore AVL que será convertida
      */
    IndiceSecundario* IndiceParaIndiceSecundario(Indice<Word> *avl);

 public:
    /*!
    * Constrói um nó AVL
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit IndiceSecundario(const Word& dado);

    /*!
     * Libera a memória relacionada ao nó AVL
     */
    virtual ~IndiceSecundario();

    /*!
    * Retorna a altura do nó AVL
    */
    int getAltura();

    /** Métodos sobrescritos */

    /*!
    * Retorna os elementos percorridos pelos métodos de percurso
    */
    std::vector<IndiceSecundario* > getElementos();

    /*!
     * Retorna o filho da esquerda da raiz
     */
    IndiceSecundario* getEsquerda();

    /*!
     * Retorna o filho da direita da raiz
     */
    IndiceSecundario* getDireita();

    /*!
     * Insere um determimado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    IndiceSecundario* inserir(const Word& dado, IndiceSecundario* arv);

    /*!
     * Remove um determinado dado da árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser removido da árvore
     * @param arv Árvore no qual o dado deve ser removido
     */
    IndiceSecundario* remover(IndiceSecundario* arv, const Word& dado);

    /*!
     * Retorna o valor mínimo guardado na árvore representada
     * pelo nó binário passado no parãmetro arv
     *
     * @param arv Árvore do qual o valor mínimo deve ser buscado
     */
    IndiceSecundario* minimo(IndiceSecundario* nodo);

 	ListaDupla<Word > breadth_first();
};

#include "IndiceSecundario.cpp"

#endif /** INDICE_SECUNDARIO_HPP */