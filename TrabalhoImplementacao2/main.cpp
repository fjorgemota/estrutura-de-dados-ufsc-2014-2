// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include "programa/Programa.hpp"
#include <string>

using std::string;

int main(int argc, char **argv) {
	Programa *programa = new Programa(new string("manpages.dat"), new string("manwords.dat"));

	return programa->executa(argc, argv);
}