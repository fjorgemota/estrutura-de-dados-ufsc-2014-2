// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP
#include <cstdlib>

/*!
 * Representa uma elemento de uma lista simples encadeada. Estrutura no qual os
 * elementos são adicionados de forma a formarem uma conexão simples entre o 
 * elemento atual e o próximo elemento.
 */
template<typename T>
class Elemento {
 public:
    /*!
     * Constrói um elemento guardando o valor especificao no parâmetro info
     * e apontando para um próximo elemento referenciado pelo ponteiro do
     * parâmetro next.
     * 
     * @param info Valor a ser guardado pelo elemento
     * @param next Ponteiro para o próximo elemento da lista
     */
    Elemento(const T& info, Elemento<T>* next) {
        this->info = new T(info);
        this->_next = next;
    }

    ~Elemento() {
        delete info;
    }

    /*!
     * Retorna o ponteiro para o próximo elemento em relação ao elemento atual.
     */
    Elemento<T>* getProximo() const {
        return _next;
    }

    /*!
     * Retorna o valor que o elemento está representando oficialmente.
     */
    T getInfo() const {
        return *info;
    }

    /*!
     * Seta o próximo elemento em relação ao elemento atual.
     * 
     * @param next Ponteiro para o próximo elemento em relação ao elemento atual.
     */
    void setProximo(Elemento<T>* next) {
        _next = next;
    }

 private:
    T *info;
    Elemento<T>* _next;
};

#endif
