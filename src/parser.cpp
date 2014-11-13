#include "parser.h"
#include "scheckerror.h"

using namespace std;

Parser::Parser(istream & stream) : submission_(stream), lineNumber_(0) {
}

string Parser::nextWord() {
	string word;
	if (ss_ >> word)
		return word;
	else if (ss_.eof()) {
		if (readNextLine())	{
			return nextWord();
		} else {
			return "";
		}
	} else {
		throw ScheckError("StringStream read error");
	}
}

unsigned int Parser::getLineNumber() const {
	return lineNumber_;
}

string Parser::getContext() const {
	return line_;
}

bool Parser::readNextLine() {
	if (getline(submission_, line_)) {
		ss_.clear();
		ss_.str(line_);
		lineNumber_++;
		return true;
	} else if (submission_.eof()) {
		return false;
	} else {
		throw ScheckError("File read error");
	}
}
