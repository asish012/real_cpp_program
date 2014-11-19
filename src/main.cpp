#include <iostream>
#include <string>
#include "Dictionary.h"
#include "ScheckError.h"
#include "Parser.h"
#include "CSVReporter.h"

using namespace std;

int main() {
	cout << "scheck version 0.1" << endl;

	try {
		Dictionary dictionary("data/mydictionary.dat");

		string sub = "data/submission1.txt";
		ifstream submission(sub);
		if (! submission.is_open()) {
			throw ScheckError("Can't open submitted file");
		}

		Parser parser(submission);
		CSVReporter reporter(cout);
		reporter.reportHeader();

		string word;
		while ( (word = parser.nextWord()) != "") {
			if (! dictionary.check(word)) {
				reporter.reportMisspellDetails(word, parser.getContext(), parser.getLineNumber(), sub);
			}
		}
		reporter.reportFooter();
	} catch (const ScheckError & e) {
		cout << "Error: " << e.what() << endl;
		return 1;
	} catch (...) {
		cout << "Error: Unknown Exception" << endl;
		return 2;
	}
}
