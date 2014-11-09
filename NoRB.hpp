// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NO_RB_HPP
#define NO_RB_HPP

#define RB_RUBRO true
#define RB_NEGRO false

template <typename T>
class NoRB {
 private:
    T* dado;  //!< Atributo onde é guardado o valor representado pelo nó
    NoRB<T>* esquerda;  //!< Atributo que aponta para menor nó descendente
    NoRB<T>* direita;  //!< Atributo que aponta para maior nó descendente
    NoRB<T>* pai;  //!< Atributo que aponta para nó ascendente
    bool cor;
 public:
    explicit NoRB(const T& dado);
}


#endif /* NO_RB_HPP */