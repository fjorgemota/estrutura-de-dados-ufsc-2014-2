#ifndef WORD_HPP
#define WORD_HPP

#include <string>

using std::string;

/*!
 * Classe que representa uma palavra (word) que sera
 * usada como referencia para as buscas
 */
class Word {
 public:
 	string *word;  //!< Palavra referenciada
 	ListaDupla<string* > *comandos;  
 	//!<lista duplamente encadeada com os comandos 
 	//!< referentes a palavra

 	/*!
 	 * Operador de inserçao (a esquerda)
 	 *
 	 * @param word A palavra que carrega um novo
 	 *				conteudo
 	 */
 	bool operator < (const Word& word) const;

 	/*!
 	 * Operador de insercao (a direita)
 	 *
 	 * @param word A palavra que tera um novo 
 	 * 			   conteudo inserido
 	 */
 	bool operator > (const Word& word) const;

 	/*!
 	 * Verifica se ambas as palavras sao iguais
	 * 
	 * @param word A palavra a ser comparada
 	 */
 	bool operator != (const Word& word) const;
};

#include "Word.cpp"

#endif /** WORD_HPP */