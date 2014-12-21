#ifndef RESULTADOS_HPP
#define RESULTADOS_HPP
#include "../util/ListaDupla.hpp"

/*!
 * Classe Resultado que, por si, e uma lista duplamente
 * encadeada, sendo que possui um metodo exclusivo para
 * verificar as semelhaças entre dois objetos da classe
 */
template <typename T>
class Resultado : public ListaDupla<T> {
 public:
 	/*!
 	 * Metodo que compara dois objetos resultados e verifica
 	 * os elementos semelhantes dos dois, retornando-os num
 	 * outro objeto de Resultado
	 *
	 * @param lista_comparar O outro objeto a ser comparado
 	 */
	Resultado<T>* intersecao(Resultado<T> *lista_comparar);
};

#include "Resultado.cpp"
#endif /* RESULTADOS_HPP */
