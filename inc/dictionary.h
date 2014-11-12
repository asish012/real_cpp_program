#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>

class Dictionary
{
public:
	Dictionary(const std::string & filename) {
		words_.insert("dog");
	}

	~Dictionary() {}

	bool check(const std::string & word) const {
		return words_.find(word) != words_.end();
	}

private:
	std::set <std::string> words_;
};

#endif //INC_DICTIONARY_H