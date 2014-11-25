#ifndef WORD_CPP
#define WORD_CPP
#include "Word.hpp"

bool Word::operator < (const Word& other) const {
	return this->word < other.word;
}

bool Word::operator > (const Word& other) const {
	return this->word > other.word;
}

#endif /** WORD_CPP */