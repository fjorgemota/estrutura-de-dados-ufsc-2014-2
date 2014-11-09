// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

/*!
 * Representa um nó binário, que por sua vez tem capacidade de representar
 * uma árvore binária de busca om percursos completa. Cada nó guarda 
 * apenas um único valor e aponta para dois outros nós descendentes
 * nesse tipo de estrutura, sendo que esses nós descendentes são sempre
 * organizados de forma a ter o menor valor no nó descendente da esquerda
 * e o maior valor no nó descendente da direita. Além disso, possui
 * métodos para facilitar o percurso através dos nós da árvore.
 * 
 * @see NoBinario::inserir
 * @see NoBinario::remover
 * @see NoBinario::preOrdem
 * @see NoBinario::emOrdem
 * @see NoBinario::posOrdem
 */
template <typename T>
class NoBinario {
 protected:
    T* dado;  //!< Atributo onde é guardado o valor representado pelo nó
    NoBinario<T>* esquerda;  //!< Atributo que aponta para menor nó descendente
    NoBinario<T>* direita;  //!< Atributo que aponta para maior nó descendente
    /*!
     * Método que deve balancear os valores da árvore assim que eles forem
     * inseridos na mesma.
     *
     * @param arv Árvore no qual os valores devem ser balanceados
     */
    virtual NoBinario<T>* balanco_insere(NoBinario<T>* arv);
    
    /*!
     * Método que deve balancear os valores da árvore assim que eles forem
     * removidos da mesma.
     *
     * @param arv Árvore no qual os valores devem ser balanceados
     */
    virtual NoBinario<T>* balanco_remove(NoBinario<T>* arv);
    
    std::vector<NoBinario<T>* > elementos;  //!< Elementos acessados durante
                                            // o percurso realizado
    
    /*
     * Retorna um novo nó para a árvore binária
     *
     * @param: dado O dado a ser inserido no nó binário
     */
    virtual NoBinario<T>* pegaNovoNo(const T& dado);

 public:
    /*!
     * Constrói um nó binário
     */
    NoBinario<T>(const T& dado);

    /*!
     * Libera a memória relacionada ao nó binário
     */
    virtual ~NoBinario<T>();

    /*!
     * Retorna o dado representado pelo nó binário
     */
    T* getDado();

    /*!
     * Retorna os elementos percorridos pelos métodos de percurso
     */
    std::vector<NoBinario<T>* > getElementos();
    
    /*!
     * Retorna o filho da esquerda da raiz
     */
    NoBinario<T>* getEsquerda();
    
    /*!
     * Retorna o filho da direita da raiz
     */
    NoBinario<T>* getDireita();

    /*!
     * Busca um determinado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    T* busca(const T& dado, NoBinario<T>* arv);

    /*!
     * Insere um determimado dado na árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser buscado na árvore
     * @param arv Árvore no qual o dado deve ser buscado
     */
    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv);

    /*!
     * Remove um determinado dado da árvore representada
     * pelo nó binário passado no parâmetro arv
     * 
     * @param dado Dado a ser removido da árvore
     * @param arv Árvore no qual o dado deve ser removido
     */
    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado);

    /*!
     * Retorna o valor mínimo guardado na árvore representada
     * pelo nó binário passado no parãmetro arv
     *
     * @param arv Árvore do qual o valor mínimo deve ser buscado
     */
    NoBinario<T>* minimo(NoBinario<T>* nodo);

    /*!
     * Realiza um percurso de pré-ordem (raiz primeiro, depois
     * descendente da esquerda e depois descendente da direita)
     * na árvore representada pelo parâmetro arv
     *
     * @param arv Árvore do qual o percurso deve ser realizado
     */
    void preOrdem(NoBinario<T>* nodo);

    /*!
     * Realiza um percurso de em-ordem (descendente da esquerda
     * primeiro, depois raiz e depois descendente da direita)
     * na árvore representada pelo parâmetro arv
     *
     * @param arv Árvore do qual o percurso deve ser realizado
     */
    void emOrdem(NoBinario<T>* nodo);

    /*!
     * Realiza um percurso de pós-ordem (descendente da esquerda
     * primeiro, depois descendente da direita e depois raiz)
     * na árvore representada pelo parâmetro arv
     *
     * @param arv Árvore do qual o percurso deve ser realizado
     */
    void posOrdem(NoBinario<T>* nodo);
};

#include "NoBinario.cpp"
#endif /* NO_BINARIO_HPP */
