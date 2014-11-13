#include "parser.h"
#include "scheckerror.h"

using namespace std;

Parser::Parser(istream & stream) : submission_(stream) {
}

string Parser::nextWord() {
	string word;
	if(submission_ >> word)
		return word;
	else if(submission_.eof())
		return "";
	else
		throw ScheckError("Error while reading submitted input");
}
