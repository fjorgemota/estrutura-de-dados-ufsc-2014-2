#ifndef SERIALIZADOR_MAN_PAGE_HPP
#define SERIALIZADOR_MAN_PAGE_HPP

#include "../modelos/ManPage.hpp"
#include "Serializador.hpp"
#include <iostream> //cout
#include <fstream> //fstream
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;

/*!
 * Classe que verifica as ManPages (manual pages)
 * atraves de leituras e escritas, sendo tambem
 * possivel pular conteudos que nao sao relevantes
 * para a pesquisa em questao
 */
class SerializadorManPage {
 private:
 	Serializador<char> *serializadorChar;
 	Serializador<int> *serializadorInt;

 public:

 	/*!
 	 * Inicializa os serializadores necessários
 	 */
 	SerializadorManPage();

 	/*!
 	 * Metodo que le um arquivo manual page
 	 *
 	 * @param arquivo O arquivo a ser lido
 	 */
 	ManPage* le(ifstream *arquivo);

 	/*!
 	 * Metodo que escreve em um arquivo manual
 	 * page
 	 *
 	 * @param arquivo O arquivo a ser escrito
 	 * @param dado O dado a ser inserido na ManPage
 	 * @param tamanho O tamanho do arquivo
 	 */
 	void escreve(ofstream *arquivo, ManPage* dado, int tamanho);

 	/*!
 	 * Metodo que calcula a proxima posicao de
 	 * um arquivo ManPage
 	 *
 	 * @param arquivo O arquivo a ser verificado
 	 */
 	void proximaPosicao(ifstream *arquivo);

 	/*!
 	 * Metodo que le o comando descrito na ManPage
 	 *
 	 * @param arquivo O arquivo a ser lido
 	 */
 	string* leComando(ifstream *arquivo);

 	/*!
 	 * Metodo que pula os conteudo irrelevantes
 	 * para a pesquisa em questao
 	 *
 	 * @param arquivo O arquivo que sera verificado
 	 */
 	void pulaConteudo(ifstream *arquivo);

 	/*!
 	 * Metodo que le o conteudo referente ao comando
 	 * referenciado na pesquisa
 	 *
 	 * @param arquivo O arquivo cujo conteudo sera verificado
 	 */
 	string* leConteudo(ifstream *arquivo);
};

#include "SerializadorManPage.cpp"

#endif /** SERIALIZADOR_MAN_PAGE_HPP */