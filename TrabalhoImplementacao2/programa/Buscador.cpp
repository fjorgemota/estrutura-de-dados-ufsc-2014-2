#ifndef BUSCADOR_CPP
#define BUSCADOR_CPP

#include "Buscador.hpp"
#include <string>

using std::string;

Buscador::Buscador(string *indicePrimario, string *indiceSecundario) {
	this->indicePrimario = indicePrimario;
	this->indiceSecundario = indiceSecundario;
}

Resultado<ManPage>* Buscador::buscaNoIndicePrimario(string *termo) {
	int contador;
	string *comparar, *resposta;
	ifstream *arquivo = new ifstream(this->indicePrimario->c_str());
	SerializadorManPage *manpage = new SerializadorManPage();
	Serializador<int> *serializadorInt = new Serializador<int>();
	int tamanho = *(serializadorInt->le(arquivo));

	for (contador = 0; contador <= tamanho; contador++) {
		comparar = manpage->leComando(arquivo); 
		if (comparar == termo) {
			resposta = manpage->leConteudo(arquivo);
			cout << "Termo procurado: " << resposta << endl;
			ManPage *resultado = new ManPage();
			resultado->comando = comparar;
			resultado->conteudo = resposta;
			return resultado;
		} else {
			manpage->pulaConteudo(arquivo);
		}
	}

	delete serializadorInt;
	delete manpage;
}

template <typename T>
Resultado<string>* Buscador::buscaNoIndiceSecundario(ListaDupla<string* > *termos) {
	int tamanho, contador1, contador2, contador3, tamanho_termos;
	string valores;
	ListaDupla<T> *resposta = new ListaDupla<T>();
	ifstream *arquivo = new ifstream(this->indiceSecundario->c_str());
	bool primeira_palavra = true;
	tamanho_termos = termos->verUltimo();
	Resultado<string> *palavras = new Resultado<string>();
	Serializador<int> *serializadorInt = new Serializador<int>();
	tamanho = *(serializadorInt->le(arquivo));
	SerializadorWord *words = new SerializadorWord();

	for(contador1 = 0; contador1 <= tamanho; contador1++) {
		valores = words->leWord(arquivo);
		for (contador2 = 0; contador2 <= tamanho_termos; contador2++){ 
			if (termos->mostra(contador) == valores) {
				resposta = words->leComandos(arquivo);
				cout << "Termo procurado: " << resposta << endl;
				if (primeira_palavra) {
					primeira_palavra = false;
					int t = resposta->getUltimo();
					for (contador3 = 0; contador3 <= t; contador3++) {
						palavras->adicionaNoInicioDuplo(resposta->mostra(contador));
					}
				} else {
					palavras = palavras->intersecao(resposta);
				}
			} else {
				words->pulaComandos(arquivo);
			}
		}
	}

	delete words;
	delete serializadorInt;
	return palavras;
}

#endif /* BUSCADOR_CPP */
