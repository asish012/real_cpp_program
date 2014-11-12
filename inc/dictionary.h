#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>
#include <fstream>

class Dictionary
{
public:
	Dictionary(const std::string & filename) {
		std::string word;
		std::ifstream filereader(filename.c_str());
		while(std::getline(filereader, word)) {
			words_.insert(word);
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