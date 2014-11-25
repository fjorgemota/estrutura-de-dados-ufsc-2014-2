#ifndef INDICE_PRIMARIO_HPP
#define INDICE_PRIMARIO_HPP

#include "Indice.hpp"
#include "../modelos/ManPage.hpp"
#include "../util/ListaDupla.hpp"

/*!
 * Estrutura temporaria que armazena as ManPages (paginas
 * de usuario) em disco.
 *
 * @see IndiceSecundario::breadth_first()
 */
class IndicePrimario : public Indice<ManPage> {
 protected:
 	/*!
     * Retorna um novo no IndicePrimario
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
    * Constrói um nó IndicePrimario
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit IndicePrimario(const ManPage& dado);

    /*!
     * Libera a memória relacionada ao nó IndicePrimario
     */
    virtual ~IndicePrimario();

    /*!
    * Retorna a altura do nó IndicePrimario
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
     * Insere um determimado dado no IndicePrimario 
     * passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado no indicePrimario
     * @param arv IndicePrimario no qual o dado deve ser buscado
     */
    IndicePrimario* inserir(const ManPage& dado, IndicePrimario* arv);

    /*!
     * Remove um determinado dado do IndicePrimario
     * passado no parâmetro arv
     * 
     * @param dado Dado a ser removido do indicePrimario
     * @param arv IndicePrimario no qual o dado deve ser removido
     */
    IndicePrimario* remover(IndicePrimario* arv, const ManPage& dado);

    /*!
     * Retorna o valor mínimo do IndicePrimario
     * passado no parametro nodo
     *
     * @param arv IndicePrimario do qual o valor mínimo deve ser buscado
     */
    IndicePrimario* minimo(IndicePrimario* nodo);

    /*!
     * Metodo que armazena os conteudos da arvore de indices
     * no disco
     */
 	ListaDupla<ManPage* >* reversed_breadth_first();
};

#include "IndicePrimario.cpp"

#endif /** INDICE_PRIMARIO_HPP */