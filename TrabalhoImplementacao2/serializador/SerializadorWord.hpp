#ifndef SERIALIZADOR_WORD_HPP
#define SERIALIZADOR_WORD_HPP

#include "../modelos/Word.hpp"
#include <iostream> //cout
#include <fstream> //fstream
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;

/*!
 * Classe que verifica as palavras (words) das
 * manual pages a serem pesquisadas, podendo
 * serem lidas, escritas e pular conteudos
 * irrelevantes para a pesquisa em questao
 */
class SerializadorWord {
 public:
 	/*!
 	 * Metodo que le as palavras de um arquivo
 	 *
 	 * @param arquivo O arquivo a ser verificado
 	 */
 	Word* le(ifstream *arquivo);

 	/*!
 	 * Metodo que escreve as palavras num arquivo
 	 *
 	 * @param arquivo O arquivo a ser verificado
 	 * @param dado O dado a ser escrito
 	 * @param tamanho O tamanho do arquivo
 	 */
 	void escreve(ofstream *arquivo, Word* dado, int tamanho);

 	/*!
 	 * Metodo que calcula a proxima posiçao de uma
 	 * palavra
 	 *
 	 * @param arquivo O arquivo a ser verificado
 	 */
 	void proximaPosicao(ifstream *arquivo);

 	/*!
 	 * Metodo que le as palavras de um arquivo
 	 *
 	 * @param arquivo O arquivo a ser verificado
 	 */
 	string* leWord(ifstream *arquivo);

 	/*!
 	 * Metodo que pula os comandos irrelevantes para
 	 * a pesquisa em questao
 	 *
 	 * @param arquivo O arquivo a ser verificado
 	 */
 	void pulaComandos(ifstream *arquivo);

 	/*!
 	 * Metodo que le os comandos de um arquivo
 	 *
 	 * @param arquivo O arquivo a ser lido
 	 */
 	ListaDupla<string>* leComandos(ifstream *arquivo);
};

#include "SerializadorWord.cpp"
#endif /** SERIALIZADOR_WORD_HPP */
