#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>
#include <fstream>
#include "scheckerror.h"

class Dictionary {
public:
	Dictionary(const std::string & filename) {		
		std::ifstream wordfile(filename.c_str());
		if (! wordfile.is_open())
		{
			throw ScheckError("Couldn't open word file: " + filename);
		}

		std::string word;
		while(std::getline(wordfile, word)) {
			words_.insert(word);
		}

		if (! wordfile.eof())
		{
			throw ScheckError("Error reading word file: " + filename);
		}
	}

	~Dictionary() {}

	bool check(const std::string & word) const {
		return words_.find(word) != words_.end();
	}

private:
	std::set <std::string> words_;
};

#endif //INC_DICTIONARY_H