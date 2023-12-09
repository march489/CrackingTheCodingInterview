#include "IsPermutation.h"
#include <assert.h>

void RunTests_IsPermutation()
{
	std::cout << "Beginning IsPermutation tests...";

	std::string monday = "monday";
	std::string dynamo = "dynamo";
	std::string mondays = "mondays";
	std::string mondaymonday = "mondaymonday";
	std::string mmoonnddaayy = "mmoonnddaayy";

	assert( IsPermutation( monday, dynamo ) );
	assert( IsPermutation( dynamo, monday ) );
	assert( IsPermutation( mmoonnddaayy, mondaymonday ) );
	assert( IsPermutation( mondaymonday, mmoonnddaayy ) );
	assert( IsPermutation( monday, monday ) );

	assert( !IsPermutation( monday, mondaymonday ) );
	assert( !IsPermutation( mondaymonday, monday) );
	assert( !IsPermutation( monday, mondays ) );
	assert( !IsPermutation( mondays, monday ) );
	assert( !IsPermutation( mondays, dynamo ) );
	assert( !IsPermutation( dynamo, mondaymonday ) );

	std::cout << " all tests passed." << std::endl;
}

bool IsPermutation( const std::string a, const std::string b )
{
	std::unordered_map<char, int> a_frequencies = frequencies( a );

	for (char ch : b)
	{
		if (--a_frequencies[ch] < 0)
		{
			return false;
		}
	}

	for (auto pair : a_frequencies)
	{
		if (pair.second > 0)
		{
			return false;
		}
	}

	return true;
}

std::unordered_map<char, int> frequencies( const std::string s )
{
	std::unordered_map<char, int> result = std::unordered_map<char, int>();

	for (char ch : s)
	{
		++result[ch];
	}

	return result;
}