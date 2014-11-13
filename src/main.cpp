#include <iostream>
#include <string>
#include "dictionary.h"
#include "scheckerror.h"
#include "parser.h"

using namespace std;

int main() {
	cout << "scheck version 0.1" << endl;

	try {
		Dictionary dictionary("data/mydictionary.dat");

		ifstream submission("data/submission1.txt");
		if (! submission.is_open()) {
			throw ScheckError("Can't open submitted file");
		}

		Parser parser(submission);

		string word;
		while ( (word = parser.nextWord()) != "") {
			if (dictionary.check(word)) {
				cout << word << " is OK\n";
			} else {
				cout << word << " is misspelt at Line " << parser.getLineNumber() << endl;
			}
		}
	} catch (const ScheckError & e) {
		cout << "Error: " << e.what() << endl;
		return 1;
	} catch (...) {
		cout << "Error: Unknown Exception" << endl;
		return 2;
	}
}
