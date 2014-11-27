#ifndef BUSCADOR_CPP
#define BUSCADOR_CPP

#include "Buscador.hpp"
#include "../serializador/SerializadorManPage.hpp"
#include "../serializador/SerializadorWord.hpp"
#include "../serializador/Serializador.hpp"
#include "../modelos/ManPage.hpp"
#include <fstream>
#include <string>

using std::ifstream;
using std::ios;
using std::string;

Buscador::Buscador(string *indicePrimario, string *indiceSecundario) {
	this->indicePrimario = indicePrimario;
	this->indiceSecundario = indiceSecundario;
}

ManPage* Buscador::buscaNoIndicePrimario(string *termo) {
	int contador;
	string *comparar, *resposta;
	ifstream *arquivo = new ifstream(this->indicePrimario->c_str(),
		ios::in 
		| ios::binary
	);
	SerializadorManPage *manpage = new SerializadorManPage();
	Serializador<int> *serializadorInt = new Serializador<int>();
	int tamanho = *(serializadorInt->le(arquivo));

	for (contador = 0; contador <= tamanho; contador++) {
		comparar = manpage->leComando(arquivo); 
		if (*comparar == *termo) {
			resposta = manpage->leConteudo(arquivo);
			ManPage *resultado = new ManPage();
			resultado->comando = comparar;
			resultado->conteudo = resposta;
			return resultado;
		} else {
			manpage->pulaConteudo(arquivo);
		}
	}
	arquivo->close();

	delete serializadorInt;
	delete manpage;
	return NULL;
}

Resultado<string>* Buscador::buscaNoIndiceSecundario(ListaDupla<string* > *termos) {
	int tamanho, contador1, contador2, contador3, tamanho_termos;
	string *palavra;
	ListaDupla<string> *resposta = new ListaDupla<string>();
	ifstream *arquivo = new ifstream(this->indiceSecundario->c_str(),
		ios::in 
		| ios::binary 
	);
	bool primeira_palavra = true;
	Resultado<string> *palavras = new Resultado<string>();
	Serializador<int> *serializadorInt = new Serializador<int>();
	tamanho = *(serializadorInt->le(arquivo));
	SerializadorWord *words = new SerializadorWord();
	string **termosVetor = termos->paraVetor();
	tamanho_termos = termos->verUltimo();

	for(contador1 = 0; contador1 <= tamanho; contador1++) {
		palavra = words->leWord(arquivo);
		bool resultadoEncontrado = false;
		for (contador2 = 0; contador2 <= tamanho_termos; contador2++){ 
			if (*termosVetor[contador2] == *palavra) {
				resultadoEncontrado = true;
			}
		}
		if (resultadoEncontrado) {
			resposta = words->leComandos(arquivo);
			if (primeira_palavra) {
				primeira_palavra = false;
				int t = resposta->verUltimo();
				string *respostaVetor = resposta->paraVetor();
				for (contador3 = 0; contador3 <= t; contador3++) {
					palavras->adicionaNoInicioDuplo(respostaVetor[contador3]);
				}
			} else {
				palavras = palavras->intersecao( (Resultado<string>*) resposta);
			}
		} else {
			words->pulaComandos(arquivo);
		}
		delete palavra;
	}
	arquivo->close();

	delete words;
	delete serializadorInt;
	return palavras;
}

#endif /* BUSCADOR_CPP */
