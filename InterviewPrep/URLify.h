#ifndef URLIFY_H
#define URLIFY_H

#include <iostream>

std::string URLify( const std::string& a );
void rtrim( std::string& s );	// in place
void ltrim( std::string& s );	// in place
void trim( std::string& s );		// in place

void RunTests_URLify();

#endif // !URLIFY_H
