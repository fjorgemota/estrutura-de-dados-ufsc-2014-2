// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_RB_HPP
#define NO_RB_HPP

#include "NoBinario.hpp"
#include <vector>

#define RB_RUBRO true
#define RB_NEGRO false

template <typename T>
class NoRB : public NoBinario<T> {
 private:
    T* dado;  //!< Atributo onde é guardado o valor representado pelo nó
    NoRB<T>* esquerda;  //!< Atributo que aponta para menor nó descendente
    NoRB<T>* direita;  //!< Atributo que aponta para maior nó descendente
    NoRB<T>* pai;  //!< Atributo que aponta para nó ascendente
    bool cor; //!< Atributo que indica a cor do nó

    /*
	 * Retorna um novo nó AVL
	 *
	 * @param dado O dado a ser incluído no novo nó
	 */
 	virtual NoRB<T>* pegaNovoNo(const T& dado);
    
    /*
     * Método que balanceia a árvore a medida que os valores
     * são adicionados
     *
     * @param arv A árvore que será balanceada
     */
    virtual NoRB<T>* balanco_insere(NoBinario<T>* arv);
    
    /*
     * Método que balanceia a árvore a medida que os valores
     * são removidos
     *
     * @param arv A árvore que será balanceada
     */
    virtual NoRB<T>* balanco_remover(NoBinario<T>* arv);
 	
 	/*
 	 * Método que converte nós de árvore binária para nós de
 	 * AVL, isto é, incluindo um atributo altura neles
 	 *
 	 * @param binario A árvore binária que será convertida
 	 */
 	NoRB<T>* binarioParaRB(NoBinario<T> *binario);

 public:
    explicit NoRB(const T& dado);

    /*
 	 * Retorna a altura do nó AVL
 	 */
 	int getAltura();
 	
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