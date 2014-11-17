#include "Parser.h"
#include "ScheckError.h"

using namespace std;

Parser::Parser(istream & stream) : submission_(stream), lineNumber_(0), charPos_(0), state_(inSpace) {
}

string Parser::nextWord() {
	string word;
	while (char c = nextChar()) {
		switch (state_) {
			case inSpace:
				if (std::isalpha(c)) {
					state_ = inWord;
					word += c;
				} else if (std::isdigit(c)) {
					state_ = inDigit;
				}
				break;
			case inWord:
				if (std::isalpha(c) || c == '\'') {
					word += c;
				} else if (std::isdigit(c)) {
					state_ = inDigit;
				} else {
					state_ = inSpace;
					return word;
				}
				break;
			case inDigit:
				if (std::isspace(c)) {
					state_ = inSpace;
					word = "";
				}
				break;
			default:
				throw ScheckError ("Bad Character");
				break;
		}		
	}
	return "";
}

unsigned int Parser::getLineNumber() const {
	return lineNumber_;
}

string Parser::getContext() const {
	return line_;
}

bool Parser::readLine() {
	if (getline(submission_, line_)) {
		lineNumber_++;
		charPos_ = 0;
		line_ += ' ';
		return true;
	} else if (submission_.eof()) {
		return false;
	} else {
		throw ScheckError("File read error");
	}
}

char Parser::nextChar() {
	if (charPos_ >= line_.size()) {
		if (! readLine()) {
			return 0;
		}
	}
	return line_[charPos_++];
}
