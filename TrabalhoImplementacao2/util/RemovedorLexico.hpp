#ifdef REMOVEDOR_LEXICO_HPP
#define REMOVEDOR_LEXICO_HPP

#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <vector>
#include <strings.h>
#include "../util/ListaDupla.hpp"

using namespace std;

/*!
 * Classe que representa uma lista de conectivos que nao serao
 * considerados na busca pelas manpages, sao eles: artigos,
 * conjunçoes, preposiçoes e pronomes (todos da lingua inglesa)
 */
class RemovedorLexico {
 private:
 	ListaDupla<string> *conectivosProibidos;  
 			//!< Lista duplamente encadeada com os conectivos nao
 			//!< incluidos na busca pelas manpages
 	/*!
 	 * Inclui, na lista duplamente encadeada, os artigos
 	 * da lingua inglesa
 	 */
 	void criar_lista_artigos();

 	/*!
 	 * Inclui, na lista duplamente encadeada, as conjunçoes
 	 * da lingua inglesa
 	 */
 	void criar_lista_conjuncoes();

 	/*!
 	 * Inclui, na lista duplamente encadeada, as preposiçoes
 	 * da lingua inglesa
 	 */
 	void criar_lista_preposicoes();
 	
	/*!
	 * Inclui, na lista duplamente encadeada, os pronomes
 	 * da lingua inglesa
	 */
 	void criar_lista_pronomes();

 public:
 	/*!
 	 * Constroi uma lista vazia para a inclusao dos conectivos
 	 * que nao serao considerados na busca pela manpages
 	 */
 	RemovedorLexico();

 	/*!
 	 * 
 	 */
 	string remover_conectivo_unica_palavra(string palavra);

 	/*!
 	 * 
 	 */
 	vector<string> separar_em_palavras(string busca);
};

#include "RemovedorLexico.cpp"
#endif /* REMOVEDOR_LEXICO_HPP */
