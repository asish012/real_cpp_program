#ifndef INC_SETTINGS_H
#define INC_SETTINGS_H

#include "CommandLine.h"

class Settings {
	public:
		enum Report { 
			rtCSV, rtXML
		};

		Settings( CommandLine & cl );

		Report ReportType() const; 
		std::string DictName() const;

	private:
		Report mRepType;
		std::string mDictName;
};

#endif
