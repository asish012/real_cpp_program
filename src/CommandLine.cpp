#include "CommandLine.h"

using std::string;

CommandLine::CommandLine( int argc, char *argv[] ) {
	for ( int i = 0; i < argc; i++ ) {
		mArgs.push_back( argv[i] );
	}
}


CommandLine::Iter CommandLine::FindOpt( const string & opt ) {
	for ( int i = 1; i < Argc(); i++ ) {
		if ( opt == Argv( i  ) ) {
			return mArgs.begin() + i;
		}
	}
	return mArgs.end();
}

bool CommandLine::MoreOpts() const {
	for ( int i = 1; i < Argc(); i++ ) {
		if ( Argv(i) != "" && Argv(i).at(0) == '-' ) {
			return true;
		}
	}
	return false;
}

bool CommandLine::HasOpt( const string & opt ) const {
	return const_cast<CommandLine*>(this)->FindOpt( opt ) != mArgs.end();
}

bool CommandLine::ExtractOpt( const string & opt ) {
	Iter pos = FindOpt( opt );
	if ( pos != mArgs.end() ) {
		mArgs.erase( pos );
		return true;
	}
	else {
		return false;
	}
}

bool CommandLine::ExtractOpt( const string & opt, string & val ) {
	Iter pos = FindOpt( opt );
	if ( pos != mArgs.end() && pos != mArgs.end() - 1  ) {
		val = *(pos+ 1);
		mArgs.erase( pos, pos + 2 );
		return true;
	}
	else {
		return false;
	}
}

int CommandLine::Argc() const {
	return mArgs.size();
}

string CommandLine::Argv( unsigned int i ) const {
	return mArgs.at( i );
}


