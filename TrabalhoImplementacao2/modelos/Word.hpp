#ifndef WORD_HPP
#define WORD_HPP

class Word {
 public:
 	char word[256];

 	bool operator < (const Word& word) const;

 	bool operator > (const Word& word) const;
};

#include "Word.cpp"

#endif