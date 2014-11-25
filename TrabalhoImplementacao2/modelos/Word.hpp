#ifndef WORD_HPP
#define WORD_HPP

#include <string>

using std::string;

class Word {
 public:
 	string *word;
 	ListaDupla<string* > *comandos;

 	bool operator < (const Word& word) const;

 	bool operator > (const Word& word) const;

 	bool operator != (const Word& word) const;
};

#include "Word.cpp"

#endif /** WORD_HPP */