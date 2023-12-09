#include "IsUnique.h"
#include <unordered_set>
#include <assert.h>


bool IsUniqueWithMap( const std::string s )
{
	std::unordered_set<char> chars = std::unordered_set<char>();

	for (char ch : s)
	{
		auto result = chars.insert( ch );
		if (!result.second)
		{
			return false;
		}
	}

	return true;
}

bool IsUniqueNoMap( const std::string s )
{
	size_t length = s.size();
	for (size_t i = 0u; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (s[i] == s[j])
			{
				return false;
			}
		}
	}

	return true;
}

void RunTests_IsUnqiue()
{
	std::cout << "Beginning IsUnique tests...";

	assert( IsUniqueWithMap( "ANDRE" ) );
	assert( !IsUniqueWithMap( "Marcello" ) );
	assert( IsUniqueWithMap( "AaBbCcDdEe" ) );

	assert( IsUniqueNoMap( "ANDRE" ) );
	assert( !IsUniqueNoMap( "Marcello" ) );
	assert( IsUniqueNoMap( "AaBbCcDdEe" ) );

	std::cout << " all tests passed." << std::endl;
}