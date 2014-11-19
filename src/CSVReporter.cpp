#include "CSVReporter.h"

using std::string;

CSVReporter::CSVReporter(std::ostream & os) : Reporter(os) {}

void CSVReporter::reportHeader() {
	out() << "word,context,line,file\n";
}

void CSVReporter::reportMisspellDetails(const std::string & word, const std::string & context, unsigned int lineNo, const std::string & filename) {
	out() << word << ",";
	out() << context << ",";
	out() << '"' << lineNo << '"' << ",";
	out() << filename << "\n";
}

void CSVReporter::reportFooter() {
	// Nothing to do.
}