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
	enum State { inSpace = 0, inWord, inDigit};
	State state_;
	std::istream & submission_;
	unsigned int lineNumber_;
	std::string line_;
	unsigned int charPos_;
	bool readLine();
	char nextChar();	
};

#endif
