#ifndef WORD_CPP
#define WORD_CPP
#include "Word.hpp"
#include <stdio.h>

bool Word::operator < (const Word& other) const {
	return *(this->word) < *(other.word);
}

bool Word::operator > (const Word& other) const {
	return *(this->word) > *(other.word);
}

bool Word::operator != (const Word& other) const {
	return *(this->word) != *(other.word);
}

#endif /** WORD_CPP */