// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_RB_HPP
#define NO_RB_HPP

#include <vector>
#include "NoBinario.hpp"

#define RB_RUBRO true
#define RB_NEGRO false

/*!
 * Representa um no rubro-negro, sendo assim podendo representar uma arvore
 * rubro-negra, que tambem e uma binaria, tendo as mesmas funçoes basicas. A
 * exclusividade esta na adiçao do atributo booleano cor, garantindo que nenhum
 * caminho de uma direçao seja duas vezes maior que a da outra, portanto, um no 
 * rubro-negro tem seguintes as propriedades:
 *
 * 1) Cada no e vermelho (rubro) ou preto (negro);
 * 2) A raiz e a folha da arvore sao negros;
 * 3) Cada no rubro possui um pai negro;
 * 4) Para um no, todos os caminhos ate uma folha contem o mesmo numero de
 * nos negros.
 *
 * Quando uma propriedade e violada, a correçao e feita atraves de relocoloraçoes
 * e/ou rotaçoes simples na arvore
 *
 * @see NoRB<T>::rotacaoSimplesEsquerda()
 * @see NoRB<T>::rotacaoSimplesDireita()
 * @see NoRB<T>::correcaoEsquerdaInsercao()
 * @see NoRB<T>::correcaoDireitaInsercao()
 * @see NoRB<T>::correcaoEsquerdaRemocao()
 * @see NoRB<T>::correcaoDireitaRemocao()
 */
template <typename T>
class NoRB : public NoBinario<T> {
 private:
    T* dado;  //!< Atributo onde é guardado o valor representado pelo nó
    NoRB<T>* esquerda;  //!< Atributo que aponta para menor nó descendente
    NoRB<T>* direita;  //!< Atributo que aponta para maior nó descendente
    NoRB<T>* pai;  //!< Atributo que aponta para nó ascendente
    bool cor;  //!< Atributo que indica a cor do nó

    /*!
     * Retorna um novo nó Rubro-Negro
     *
     * @param dado O dado a ser incluído no novo nó
     */
    virtual NoRB<T>* pegaNovoNo(const T& dado);

    /*!
     * Método que balanceia a árvore a medida que os valores
     * são adicionados
     *
     * @param arv A árvore que será balanceada
     */
    virtual NoRB<T>* balanco_insere(NoBinario<T>* arv);

    /*!
     * Método que balanceia a árvore a medida que os valores
     * são removidos
     *
     * @param arv A árvore que será balanceada
     */
    virtual NoRB<T>* balanco_remove(NoBinario<T>* arv);

    /*!
    * Método que converte nós de árvore binária para nós de
    * Rubro-Negro, isto é, incluindo um atributo cor neles
    *
    * @param binario A árvore binária que será convertida
    */
    NoRB<T>* binarioParaRB(NoBinario<T> *binario);

 public:
    /*!
     * Constroi um no Rubro-Negro
     */
    explicit NoRB(const T& dado);

    /*!
     * Libera a memória relacionada ao nó RB
     */
    virtual ~NoRB();

    /*!
     * Retorna o pai do nodo
     */
    NoRB<T>* getPai();

    /*!
     * Retorna a cor do no
     */
    bool getCor();

    /*!
     * Realiza uma rotaçao simples a esquerda
     *
     * @param raiz A raiz da subarvore que sera rotacionada
     */
    NoRB<T>* rotacaoSimplesDireita(NoRB<T>* raiz);

    /*!
     * Realiza uma rotaçao simples a direita
     *
     * @param raiz A raiz da subarvore que sera rotacionada
     */
    NoRB<T>* rotacaoSimplesEsquerda(NoRB<T>* raiz);

    /*!
     * Corrige as violaçoes das definiçoes apos uma inserçao
     * ocorrida a esquerda 
     *
     * @param arv O no atual que esta sendo avaliado
     * @param pai O no ascendente a arv
     * @param avo O no ascendente ao pai de arv
     */
    NoRB<T>* correcaoEsquerdaInsercao(NoRB<T>* arv, NoRB<T>* pai, NoRB<T>* avo);

    /*!
     * Corrige as violaçoes das definiçoes apos uma inserçao
     * ocorrida a direita
     *
     * @param arv O no atual que esta sendo avaliado
     * @param pai O no ascendente a arv
     * @param avo O no ascendente ao pai de arv
     */
    NoRB<T>* correcaoDireitaInsercao(NoRB<T>* arv, NoRB<T>* pai, NoRB<T>* avo);

    /*!
     * Corrige as violaçoes das definiçoes apos uma remoçao
     * ocorrida a esquerda
     *
     * @param raiz O sucessor inordem do no removido
     */
    NoRB<T>* correcaoEsquerdaRemocao(NoRB<T>* raiz);

    /*!
     * Corrige as violaçoes das definiçoes apos uma remoçao
     * ocorrida a direita
     *
     * @param raiz O sucessor inordem do no removido
     */
    NoRB<T>* correcaoDireitaRemocao(NoRB<T>* raiz);

    /** Métodos sobrescritos */

    /*!
    * Retorna os elementos percorridos pelos métodos de percurso
    */
    std::vector<NoRB<T>* > getElementos();

    /*!
     * Retorna o filho da esquerda da raiz
     */
    NoRB<T>* getEsquerda();

    /*!
     * Retorna o filho da direita da raiz
     */
    NoRB<T>* getDireita();

    /*!
     * Insere um determimado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    NoRB<T>* inserir(const T& dado, NoRB<T>* arv);

    /*!
     * Remove um determinado dado da árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser removido da árvore
     * @param arv Árvore no qual o dado deve ser removido
     */
    NoRB<T>* remover(NoRB<T>* arv, const T& dado);

    /*!
     * Retorna o valor mínimo guardado na árvore representada
     * pelo nó binário passado no parãmetro arv
     *
     * @param arv Árvore do qual o valor mínimo deve ser buscado
     */
    NoRB<T>* minimo(NoRB<T>* nodo);
};

#include "NoRB.cpp"

#endif /* NO_RB_HPP */
