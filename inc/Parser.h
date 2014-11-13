#ifndef INC_PARSER_H
#define INC_PARSER_H

#include <iostream>
#include <sstream>
#include <string>

class Parser
{
public:
	Parser(std::istream & stream);
	std::string nextWord();
	unsigned int getLineNumber() const;
	std::string getContext() const;

private:	
	std::istream & submission_;
	unsigned int lineNumber_;
	std::string line_;
	std::istringstream ss_;
	bool readNextLine();
};

#endif
