// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PROBABILIDADES_HPP
#define GERADOR_PROBABILIDADES_HPP
#include "ListaDupla.cpp"

/*
 * Um gerador de probabilidades e formado por uma lista
 * duplamente encadeada onde os valores sao incluidos e
 * a eles sao atribuidos uma porcentagem, indicando a possibi-
 * lidade de sua ocorrencia
 */
template <typename T>
class GeradorProbabilidades {
 private:
    ListaDupla<T> *lista;  //!< A lista onde os eventos e a probabilidade
                          //!< de um dado sera armazenado
 public:
 	/*
 	 * Inicializa o gerador de probabilidades com uma lista vazia
 	 */
    GeradorProbabilidades();

    /*
     * Adiciona um dado ao gerador de probabilidade, juntamente com
     * a porcentagem indicando a possibilidade de ocorrencia
	 * 
	 * @param dado O dado a ser armazenado na lista
	 * @param porcentagem A porcentagem, indicando a possibilidade de ocorrencia
     */
    void adiciona(T dado, int porcentagem);

    /*
     * Retorna a lista contendo os dados a avaliar e suas 
     * respectivas probabilidades
     */
    ListaDupla<T>* pegaLista();
};
#endif /* GERADOR_PROBABILIDADES_HPP */
