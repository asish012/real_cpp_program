#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main() {
	cout << "scheck version 0.1" << endl;

	Dictionary dictionary("data/mydictionary.dat");
	
	string word;
	while(getline(cin, word)) {
		if(dictionary.check(word)) {
			cout << word << " is OK\n";
		} else {
			cout << word << " is misspelt\n";
		}
	}

}