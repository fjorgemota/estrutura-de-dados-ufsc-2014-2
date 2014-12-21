#ifndef INDICE_SECUNDARIO_HPP
#define INDICE_SECUNDARIO_HPP

#include "Indice.hpp"
#include "../modelos/Word.hpp"
#include "../util/ListaDupla.hpp"

/*!
 * Estrutura temporaria que armazena as palavras de
 * busca no disco
 *
 * @see IndiceSecundario::breadth_first()
 */
class IndiceSecundario : public Indice<Word> {
 protected:
 	/*!
     * Retorna um novo no IndiceSecundario
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
    * Constrói um nó IndiceSecundario
    *
    * @param dado O dado a ser adicionado ao nó
    */
    explicit IndiceSecundario(const Word& dado);

    /*!
     * Libera a memória relacionada ao nó IndiceSecundario
     */
    virtual ~IndiceSecundario();

    /*!
    * Retorna a altura do nó IndiceSecundario
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
     * Insere um determimado dado no IndiceSecundario passado
     * no parâmetro arv
     * 
     * @param dado Dado a ser buscado no indiceSecundario
     * @param arv IndiceSecundario no qual o dado deve ser buscado
     */
    IndiceSecundario* inserir(const Word& dado, IndiceSecundario* arv);

    /*!
     * Remove um determinado dado do IndiceSecundario passado
     * no parâmetro arv
     * 
     * @param dado Dado a ser removido do indiceSecundario
     * @param arv IndiceSecundario no qual o dado deve ser removido
     */
    IndiceSecundario* remover(IndiceSecundario* arv, const Word& dado);

    /*!
     * Retorna o valor mínimo do IndiceSecundario passado
     * no parametro nodo
     *
     * @param arv IndiceSecundario do qual o valor mínimo deve ser buscado
     */
    IndiceSecundario* minimo(IndiceSecundario* nodo);

    /*!
     * Metodo que armazena os conteudos da arvore de indices
     * no disco
     */
 	ListaDupla<Word* >* reversed_breadth_first();
};

#include "IndiceSecundario.cpp"

#endif /** INDICE_SECUNDARIO_HPP */