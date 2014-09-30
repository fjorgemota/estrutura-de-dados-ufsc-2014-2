// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef ELEMENTODUPLO_HPP
#define ELEMENTODUPLO_HPP
#include <cstdlib>

/*!
 * Classe que representa um elemento de uma lista duplamente encadeada, estrutura
 * no qual os elementos são interligados formando uma conexão entre o elemento 
 * atual com o sucessor e antecessor 
 */
template <typename T>
class ElementoDuplo {
 private:
    ElementoDuplo<T> *antecessor;  //!< Representa um ponteiro para o elemento
                                  //!< anterior
    ElementoDuplo<T> *sucessor;  //!< Representa um ponteiro para o elemento
                                //!< sucessor
     T *info;  //!< O valor apontado pelo elemento

 public:
    /*!
     * Constrói um elemento duplo
     * 
     * @param: antes O elemento duplo antecessor que será apontado pelo atual
     * @param: info O valor que será apontado pelo elemento duplo atual
     * @param: proximo O elemento duplo sucessor que será apontado pelo atual
     */
    ElementoDuplo(ElementoDuplo<T> *antes, const T& info,
                                            ElementoDuplo<T> *proximo) {
        this->antecessor = antes;
        this->info = new T(info);
        this->sucessor = proximo;
    }

    /*!
     * Remove o valor armazenado no elemento duplo
     */
    ~ElementoDuplo() {
        delete info;
    }

    /*!
     * Retorna o valor que está apontando para o antecessor
     */
    ElementoDuplo<T> *getAnterior() const {
        return this->antecessor;
    }

    /*!
     * Retorna o valor que está apontando para o secessor
     */
    ElementoDuplo<T> *getProximo() const {
        return this->sucessor;
    }

    /*!
     * Retorna o valor que está apontando para a informação armazenada no
     * elemento duplo
     */
    T getInfo() const {
        return *info;
    }

    /*!
     * Seta um sucessor em relação ao elemento atual
     * 
     * @param: novo O novo elemento duplo que será apontado pelo atual
     */
    void setProximo(ElementoDuplo<T> *novo) {
        this->sucessor = novo;
    }

    /*!
     * Seta um antecessor em relação ao elemento atual
     * 
     * @param: novo O novo elemento duplo que será apontado pelo atual
     */
    void setAnterior(ElementoDuplo<T> *novo) {
        this->antecessor = novo;
    }
};

#endif /* ELEMENTODUPLO_HPP */
