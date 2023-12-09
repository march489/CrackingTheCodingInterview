#include <assert.h>
#include "StringCompression.h"
#include "IsPermutation.h"
#include <string>

#define ONE_BYTE 1u

std::string StringCompression( const std::string& s )
{
	if (s.empty())
	{
		return s;
	}

	std::string result = "";

	char prevChar = s[0];
	unsigned int count = 0;

	for (auto ch : s)
	{
		if (ch == prevChar)
		{
			count++;
		}
		else
		{
			result += prevChar;

			std::string num = std::to_string( count );
			result.append( num );

			count = 1;
			prevChar = ch;
		}
	}

	// last char 
	result += prevChar;

	std::string num = std::to_string( count );
	result.append( num );

	if (result.size() < s.size())
	{
		return result;
	}
	else
	{
		return s;
	}
}

void RunTests_StringCompression()
{
	std::cout << "Beginning StringCompression tests...";

	assert( StringCompression( "aaaabbbccd" ) == "a4b3c2d1" );
	assert( StringCompression( "aabcccccaaa" ) == "a2b1c5a3" );
	assert( StringCompression( "abc" ) == "abc" );
	assert( StringCompression( "aaaaaaaaaaaabbbbbbbbbbbbcc" ) == "a12b12c2" );
	assert( StringCompression( "AaAaAaAa" ) == "AaAaAaAa" );
	assert( StringCompression( "AAAAAaaaaa" ) == "A5a5" );
	assert( StringCompression( "aabb" ) == "aabb" );

	std::cout << " all tests passed." << std::endl;
}
