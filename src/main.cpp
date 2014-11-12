#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main() {
	cout << "scheck version 0.1" << endl;

	Dictionary dictionary("mydict.dat");
	string word = "dog";
	if(dictionary.check(word)) {
		cout << word << " is OK\n";
	} else {
		cout << word << " is misspelt\n";
	}
}