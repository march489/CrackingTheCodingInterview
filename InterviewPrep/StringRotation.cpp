#include "StringRotation.h"
#include <assert.h>

void RunTests_StringRotation()
{
	std::cout << "Beginning StringRotation tests...";

	// testing IsSubstring
	assert( IsSubstring( "Marcello", "cello" ) );
	assert( IsSubstring( "waterbottle", "erb" ) );
	assert( !IsSubstring( "waterbottle", "leb" ) );
	assert( !IsSubstring( "thi ng", "thing" ) );

	//testing IsStringRotation
	assert( IsStringRotation( "waterbottle", "erbottlewat" ) );
	assert( IsStringRotation( "tepid", "pidte" ) );
	assert( !IsStringRotation( "tepid", "pid" ) );

	std::cout << " all tests passed." << std::endl;
}

bool IsStringRotation( std::string s, std::string rotCandidate )
{
	std::string doubleString = s + s;
	return (rotCandidate.size() == s.size()) &&
		IsSubstring( doubleString, rotCandidate );
}

bool IsSubstring( std::string haystack, std::string needle )
{
	return haystack.find( needle ) != std::string::npos;
}