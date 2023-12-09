#include "PalindromePermutation.h"
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include "IsPermutation.h"
#include <assert.h>

void RunTests_PalindromePermutation()
{
	std::cout << "Beginning PalindromPermutation tests...";

	assert( PalindromePermutation( "taco cat" ) );
	assert( PalindromePermutation( "tact coa" ) );
	assert( PalindromePermutation( "aabbccdd" ) );
	assert( PalindromePermutation( "aa bb cc cdd" ) );
	assert( !PalindromePermutation( "aa bbb ccc dd" ) );

	std::cout << " all tests passed." << std::endl;
}


bool PalindromePermutation( std::string s )
{
	// // One solution
	//StripWhiteSpace( s );
	//std::unordered_map<char, int> freqs = frequencies( s );

	//int charsWithOddFreqs = 0;
	//for (auto it = freqs.begin(); it != freqs.end(); it++)
	//{
	//	charsWithOddFreqs += (it->second % 2);
	//}

	//return charsWithOddFreqs <= 1;

	// Another solution
	StripWhiteSpace( s );
	std::unordered_set<char> openParentheses = std::unordered_set<char>();
	openParentheses.reserve( s.size() );
	
	for (auto it = s.begin(); it != s.end(); it++)
	{
		if (openParentheses.find( *it ) != openParentheses.end())
		{
			// is found --> pop
			openParentheses.erase( *it );
		}
		else
		{
			// not found --> push
			openParentheses.insert( *it );
		}
	}

	return openParentheses.size() <= 1;
}

void StripWhiteSpace( std::string& s )
{
	// potentially replace with walking down the list and doing nothing is std::isspace returns true
	const std::regex spaces = std::regex( "\\s+" );
	const char* const nothing = "";

	s = std::regex_replace( s, spaces, nothing );
}