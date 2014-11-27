#ifndef REMOVEDOR_LEXICO_CPPrem
#define REMOVEDOR_LEXICO_CPP
#include "RemovedorLexico.hpp"
#include "NoAVL.hpp"
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

RemovedorLexico::RemovedorLexico() {
	this->conectivosProibidos = new NoAVL<string>(string(""));
	this->criar_lista_artigos();
	this->criar_lista_conjuncoes();
	this->criar_lista_preposicoes();
	this->criar_lista_pronomes();
}

RemovedorLexico::~RemovedorLexico() {
	delete this->conectivosProibidos;
}

bool RemovedorLexico::eConectivo(string palavra) {
	return (palavra.size() > 2 && !(this->conectivosProibidos->contem(palavra, this->conectivosProibidos)));
}

string RemovedorLexico::removeCaracteresEspeciais(string str) {
	int i;
    int l = str.size();
    string resultado;
    resultado.reserve(l);
    for(i = 0; i < l; i++) {
    	char caractere = str[i];
    	if(caractere >= 'A' && caractere <= 'Z') {
    		caractere = caractere + 32; // Lowercase it all :D
    	}
        if((caractere >= 'a' && caractere <= 'z') || (caractere >= '0' && caractere <= '9')) {
            resultado += caractere;
        }   
    }
    return resultado;
}

ListaDupla<string>* RemovedorLexico::separaEmPalavras(string busca) {
	ListaDupla<string> *termos = new ListaDupla<string>();
	string palavra;
	stringstream stream(busca);
	while (stream >> palavra) {
		termos->adicionaNoInicioDuplo(this->removeCaracteresEspeciais(palavra));	
	}
	return termos;
}

ListaDupla<string>* RemovedorLexico::removeConectivos(ListaDupla<string> *palavras) {
	ListaDupla<string> *resultado = new ListaDupla<string>();	
	int i = 0;
	int l = palavras->verUltimo();
	string *vetor = palavras->paraVetor();
	for(i = 0; i <= l; i++) {
		if (this->eConectivo(vetor[i])) {
			resultado->adicionaNoInicioDuplo(vetor[i]);
		}
	}
	return resultado;
}

void RemovedorLexico::criar_lista_artigos() {
	this->conectivosProibidos = this->conectivosProibidos->inserir("a", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("an", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("the", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("no", this->conectivosProibidos);
}

void RemovedorLexico::criar_lista_conjuncoes() {
	this->conectivosProibidos = this->conectivosProibidos->inserir("for", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("and", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("nor", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("but", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("or", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("yet", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("so", this->conectivosProibidos);
}

void RemovedorLexico::criar_lista_preposicoes() {
	this->conectivosProibidos = this->conectivosProibidos->inserir("aboard", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("about", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("above", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("across", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("after", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("against", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("ahead", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("along", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("amid", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("amidst", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("among", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("around", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("as", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("aside", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("at", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("athwart", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("atop", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("barring", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("because", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("before", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("behind", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("below", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("beneath", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("beside", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("besides", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("between", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("beyond", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("by", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("circa", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("concerning", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("despite", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("down", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("during", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("except", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("excluding", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("following", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("from", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("in", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("including", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("inside", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("instead", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("into", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("like", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("minus", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("near", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("of", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("off", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("on", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("onto", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("opposite", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("out", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("outside", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("over", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("past", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("plus", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("prior", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("regarding", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("regardless", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("save", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("since", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("tan", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("through", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("till", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("to", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("toward", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("towards", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("under", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("underneath", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("unlike", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("until", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("up", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("upon", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("versus", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("via", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("with", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("within", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("without", this->conectivosProibidos);
}

void RemovedorLexico::criar_lista_pronomes() {
	this->conectivosProibidos = this->conectivosProibidos->inserir("I", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("me", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("we", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("us", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("you", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("she", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("her", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("he", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("him", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("it", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("they", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("them", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("what", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("which", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("who", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("whom", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("whose", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("whichever", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("whoever", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("whomever", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("this", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("these", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("that", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("those", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("anybody", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("anyone", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("anything", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("each", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("either", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("everybody", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("everyone", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("everything", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("neither", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("nobody", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("nothing", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("one", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("somebody", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("someone", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("something", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("both", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("few", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("many", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("several", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("all", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("any", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("most", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("none", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("some", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("myself", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("ourselves", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("yourself", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("yourselves", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("himself", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("herself", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("itself", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("themselves", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("my", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("its", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("is", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("our", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("your", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("their", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("mine", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("his", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("hers", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("ours", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("yours", this->conectivosProibidos);
	this->conectivosProibidos = this->conectivosProibidos->inserir("theirs", this->conectivosProibidos);
}

#endif /* REMOVEDOR_LEXICO_CPP */
