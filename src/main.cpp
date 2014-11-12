#include <iostream>
#include <string>
#include "dictionary.h"
#include "scheckerror.h"

using namespace std;

int main() {
	cout << "scheck version 0.1" << endl;

	try {
		Dictionary dictionary("data/mydictionary.dat");
		string word;
		while(getline(cin, word)) {
			if(dictionary.check(word)) {
				cout << word << " is OK\n";
			} else {
				cout << word << " is misspelt\n";
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