#ifndef REMOVEDOR_LEXICO_HPP
#define REMOVEDOR_LEXICO_HPP

#include <string>
#include "ListaDupla.hpp"

using std::string;

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
 	 * Destrói lista de conectivos proibidos, liberando memória
 	 */
 	~RemovedorLexico();

 	/*!
 	 * 
 	 */
 	bool e_conectivo(string palavra);
	
	/*!
 	 * 
 	 */
 	ListaDupla<string>* separa_em_palavras(string busca);
 	/*!
 	 * 
 	 */
 	ListaDupla<string>* remove_conectivos(ListaDupla<string> *palavras);
};

#include "RemovedorLexico.cpp"
#endif /* REMOVEDOR_LEXICO_HPP */
