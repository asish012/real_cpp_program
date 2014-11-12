#ifndef INC_SCHECKERROR_H
#define INC_SCHECKERROR_H

#include <string>
#include <stdexcept>

class ScheckError : public std::runtime_error {
public:
	ScheckError(const std::string & msg) : std::runtime_error(msg) {

	}	
};

#endif