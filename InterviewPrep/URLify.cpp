#include "URLify.h"
#include <regex>
#include <assert.h>

void RunTests_URLify()
{
	std::cout << "Beginning URLify tests...";

	const std::string url_name( "Marcello%20Delgado" );

	assert( URLify( "Marcello Delgado" ) == url_name );
	assert( URLify( "      Marcello         Delgado       " ) == url_name );
	assert( URLify( "      Marcello \t Delgado       " ) == url_name );

	std::cout << " all tests passed." << std::endl;
}

std::string URLify( const std::string& s )
{
	std::string t = s;
	trim( t );

	const std::regex spaces( "\\s+" );
	const char* const url_replacement = "%20";

	return std::regex_replace( t, spaces, url_replacement );
}

void ltrim( std::string& s )
{
	s.erase( s.begin(),
			 std::find_if( s.begin(),
						   s.end(),
						   []( unsigned char ch )
						   {
							   return !std::isspace( ch );
						   } ) );
}

void rtrim( std::string& s ) {
	s.erase( std::find_if( s.rbegin(),
						   s.rend(),
						   []( unsigned char ch )
						   {
							   return !std::isspace( ch );
						   } ).base(),
							   s.end() );
}

void trim( std::string& s )
{
	ltrim( s );
	rtrim( s );
}