#ifndef INC_PARSER_H
#define INC_PARSER_H

#include <iostream>

class Parser
{
public:
	Parser(std::istream & stream);
	std::string nextWord();
	unsigned int lineNumber() const;
	std::string getContext() const;

private:
	std::istream & submission_;
};

#endif
