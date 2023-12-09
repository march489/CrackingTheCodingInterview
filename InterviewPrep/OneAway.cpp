#include "OneAway.h"
#include <assert.h>
#include <unordered_map>
#include "IsPermutation.h"

bool OneAway( std::string a, std::string b )
{
	// assuming we're using std::strings, which know their size O(1)
	int sizeDifference = (int)(a.size() - b.size());
	if (sizeDifference < -1 || sizeDifference > 1)
	{
		return false;
	}

	std::string& shortString = (sizeDifference <= 0) ? a : b;
	std::string& longString = (sizeDifference <= 0) ? b : a;

	auto itShort = shortString.begin();
	auto itLong = longString.begin();

	int errors = 0;
	while (itShort != shortString.end() && itLong != longString.end() && errors < 2)
	{
		if (*itShort != *itLong)
		{
			// definitely a problem
			errors++;

			// but can we salvage the situation
			// we cant have both an insertion & a replacement (too far away)
			// so we look one ahead
			if (sizeDifference != 0)
			{
				itLong++;

				if (*itShort != *itLong)
				{
					// if there's still a mismatch, it's dead
					errors++;
				}
			}
		}
		
		// advance the pointers but avoid a crash
		if (itShort != shortString.end())
			itShort++;
		if (itLong != longString.end())
			itLong++;
	}

	return errors < 2;
}

void RunTests_OneAway()
{
	std::cout << "Beginning OneAway tests...";

	assert( OneAway( "pale", "ple" ) );
	assert( OneAway( "pales", "pale" ) );
	assert( OneAway( "pale", "bale" ) );
	assert( !OneAway( "pale", "bake" ) );
	assert( !OneAway( "pale", "elap" ) );

	std::cout << " all tests passed." << std::endl;
}
