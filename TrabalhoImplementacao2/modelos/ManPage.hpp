#ifndef MAN_PAGE_HPP
#define MAN_PAGE_HPP

#include <string>

using std::string;

/*!
 * Classe que representa ManPage (manual page) sao arquivos 
 * com instruçoes/informaçoes de ajuda para os sistemas 
 * operacionais baseados em Unix.  
 */
class ManPage {
 public:
	string *comando;  //!< O comando representando topicos da ManPage
	string *conteudo;   //!< O conteudo referente ao comando

	/*!
	 * Operador de inserçao (a esquerda)
	 *
	 * @param manpage O novo conteudo a receber
	 */
 	bool operator < (const ManPage& manpage)const;

 	/*!
 	 * Operador de inserçao (a direita)
 	 *
 	 * @param manpage Variavel cujo novo conteudo sera
 	 * 				atribuido
 	 */
 	bool operator > (const ManPage& manpage) const;
};

#include "ManPage.cpp"
#endif /** MAN_PAGE_HPP */
