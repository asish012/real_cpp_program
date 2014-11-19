#ifndef INC_REPORTER_H
#define INC_REPORTER_H

#include <iostream>

class Reporter
{
public:
	Reporter(std::ostream & os) : ostr_(os) {}
	virtual ~Reporter() {}

	virtual void reportHeader() = 0;
	virtual void reportMisspellDetails(const std::string & word, const std::string & context, unsigned int lineNo, const std::string & filename) = 0;
	virtual void reportFooter() = 0;

protected:
	std::ostream & out() {
		return ostr_;
	}

private:
	std::ostream & ostr_;
};

#endif