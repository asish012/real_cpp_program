#include <iostream>
#include <string>
#include "Dictionary.h"
#include "ScheckError.h"
#include "Parser.h"
#include "CSVReporter.h"
#include "CommandLine.h"
#include "Settings.h"

using namespace std;

Reporter * MakeReporter(Settings::Report rt) { 
	if (rt == Settings::rtCSV) {
		return new CSVReporter(cout);
	} else { 
		// return new XMLReporter(cout);
		throw ScheckError("XMLReporter not implemented yet");
	}
}

void CheckSubmission(const Dictionary & d, istream & sub, const std::string & subname, Reporter & rep) {
	Parser parser(sub);
	rep.reportHeader();
	string word;
	while ( (word = parser.nextWord()) != "") {
		if (! d.check(word)) {
			rep.reportMisspellDetails(word, parser.getContext(), parser.getLineNumber(), subname);
		}
	}
	rep.reportFooter();
}

int main(int argc, char * argv[]) {
	cout << "scheck version 0.1" << endl;

	try {
		CommandLine cl(argc, argv);
		Settings settings(cl);

		Dictionary d(settings.DictName());
		unique_ptr<Reporter> rep(MakeReporter(settings.ReportType()));

		if (cl.Argc() == 1) {
			CheckSubmission(d, cin, "stdin", *rep); 
		} else { 
			for(int i = 1; i < cl.Argc(); i++) {
				ifstream sub(cl.Argv(i).c_str());
				if (! sub.is_open()) {
					throw ScheckError("Cannotopenfile" + cl.Argv(i));
				}
				CheckSubmission(d, sub, cl.Argv(i), *rep);
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
