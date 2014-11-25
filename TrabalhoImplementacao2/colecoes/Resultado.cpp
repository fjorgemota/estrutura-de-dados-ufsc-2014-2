#ifndef RESULTADOS_CPP
#define RESULTADOS_CPP
#include "Resultado.hpp"

template <typename T>
Resultado<T>* Resultado<T>::intersecao(Resultado<T> *lista_comparar) {
	int i, j, maximo1, maximo2;
	T procurado;
	maximo1 = this->verUltimo();
	maximo2 = lista_comparar->verUltimo();
	Resultado<T> *saida = new Resultado<T>();

	for (i = 0; i <= maximo1; i++) {
		procurado = this->mostra(i);
		for (j = 0; j <= maximo2; j++) {
			if (lista_comparar->mostra(j) == procurado) {
				saida->adicionaNoInicioDuplo(procurado);
			}
		}
	}

	return saida;
}

#endif /* RESULTADOS_CPP */