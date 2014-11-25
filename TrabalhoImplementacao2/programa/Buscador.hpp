#ifndef BUSCADOR_HPP
#define BUSCADOR_HPP

#include "../colecoes/Resultado.hpp"
#include "../modelos/ManPage.hpp"
#include <string>
#include <fstream>

using std::string;

class Buscador {
 protected:
 	string indicePrimario;
 	string indiceSecundario;

 public:
 	Buscador(string indicePrimario, string indiceSecundario);
 	Resultado<ManPage>* buscaNoIndicePrimario(string termo);
 	Resultado<string>* buscaNoIndiceSecundario(string *termos);
};
#include "Buscador.cpp"
#endif /* BUSCADOR_HPP */
