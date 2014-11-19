#ifndef INC_CSV_REPORTER_H
#define INC_CSV_REPORTER_H

#include "Reporter.h"

class CSVReporter : public Reporter
{
public:
	CSVReporter(std::ostream & os);
	void reportHeader();
	void reportMisspellDetails(const std::string & word, const std::string & context, unsigned int lineNo, const std::string & filename);
	void reportFooter();
};

#endif