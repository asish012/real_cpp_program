#include "Settings.h"
#include "ScheckError.h"

const char * const DEF_DICT = "data/mydictionary.dat";
const char * const DICT_OPT = "-d";
const char * const CSV_OPT =  "-csv";
const char * const XML_OPT =  "-xml";

Settings :: Settings( CommandLine & cl ) : mRepType( rtCSV ), mDictName( DEF_DICT )  {
	if ( cl.HasOpt( CSV_OPT ) && cl.HasOpt( XML_OPT ) ) {
		throw ScheckError( "Only one output type can be specified" );
	}
	if ( cl.ExtractOpt( CSV_OPT ) ) {
		mRepType = rtCSV;
	}
	if ( cl.ExtractOpt( XML_OPT ) ) {
		mRepType = rtXML;
	}
	cl.ExtractOpt( DICT_OPT, mDictName ) ;

	if ( cl.MoreOpts() ) {
		throw ScheckError( "Invalid command line" );
	}
}

Settings::Report Settings :: ReportType() const {
	return mRepType;
}

std::string Settings :: DictName() const {
	return mDictName;
}
