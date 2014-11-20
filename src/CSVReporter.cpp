#include "CSVReporter.h"

using std::string;

// Handle word with cotation symbol (")
string toCSV(const string & word) {
	string csvstr;
	for (unsigned int i = 0; i < word.size(); ++i) {
		if (word[i] == '"') {
			csvstr += '"';
		}
		csvstr += word[i];
	}
	return '"' + csvstr + '"';
}

CSVReporter::CSVReporter(std::ostream & os) : Reporter(os) {}

void CSVReporter::reportHeader() {
	out() << "word,context,line,file\n";
}

void CSVReporter::reportMisspellDetails(const std::string & word, const std::string & context, unsigned int lineNo, const std::string & filename) {
	out() << toCSV(word) << ",";
	out() << toCSV(context) << ",";
	out() << '"' << lineNo << '"' << ",";
	out() << toCSV(filename) << "\n";
}

void CSVReporter::reportFooter() {
	// Nothing to do.
}
