#ifndef REMOVEDOR_LEXICO_HPP
#define REMOVEDOR_LEXICO_HPP

#include <string>
#include "NoAVL.hpp"

using std::string;

/*!
 * Classe que representa uma lista de conectivos que nao serao
 * considerados na busca pelas manpages, sao eles: artigos,
 * conjunçoes, preposiçoes e pronomes (todos da lingua inglesa)
 */
class RemovedorLexico {
 private:
 	NoAVL<string> *conectivosProibidos;  
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
 	 * Verifica se dada palavra e um conectivo
 	 *
 	 * @param palavra Palavra a ser verificada
 	 */
 	bool eConectivo(string palavra);
	
	/*!
 	 * Metodo que retorna uma lista duplamente encadeada com
 	 * cada palavra referenciada pelo parametro
 	 *
 	 * @param busca String que sera dividida em palavras
 	 */
 	ListaDupla<string>* separaEmPalavras(string busca);
	
	/*!
 	 * Remove todo e qualquer caractere que não seja número
 	 * ou letra de uma string e também aplica o lowercase
 	 * nas letras válidas
 	 */
 	string removeCaracteresEspeciais(string str);
 	
 	/*!
 	 * Metodo que remove os conectivos de uma lista de palavras
 	 *
 	 * @param palavras A lista a ser verificada
 	 */
 	ListaDupla<string>* removeConectivos(ListaDupla<string> *palavras);
};

#include "RemovedorLexico.cpp"
#endif /* REMOVEDOR_LEXICO_HPP */
