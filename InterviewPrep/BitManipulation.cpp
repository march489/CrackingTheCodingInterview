#include "BitManipulation.h"
#include <iostream>
#include <assert.h>
#include <vector>
#include <numeric>

void ShiftOperationDemos( )
{
	int x = 0x80000fff;

	int a = x << 4;
	int b = x >> 4;

	std::cout << "\nint x = 0x80000fff\n";
	printf_s( "x: %11d (0x%08x)\n", x, x );
	printf_s( "a: %11d (0x%08x)\n", a, a );
	printf_s( "b: %11d (0x%08x)\n", b, b );

	std::cout << std::endl;

	unsigned int y = (unsigned) x;

	unsigned int c = y << 4;
	unsigned int d = y >> 4;

	std::cout << "\nint y = (unsigned int) x\n";
	printf_s( "x: %11d (0x%08x)\n", y, y );
	printf_s( "c: %11d (0x%08x)\n", c, c );
	printf_s( "d: %11d (0x%08x)\n", d, d );
}

bool GetBit( int num, unsigned char index )
{
	assert( index < 32 );

	int mask = ( 1 << index );
	return ( num & mask ) != 0;
}

int SetBit( int num, unsigned char index )
{
	assert( index < 32 );

	return num | ( 1 << index );
}

int ClearBit( int num, unsigned char index )
{
	assert( index < 32 );

	int mask = ~( 1 << index );
	return num & mask;
}

bool IsF32Precise( float x )
{
	assert( x < 1.0f && x >= 0.0f );
	//volatile float power = 10000000 * x;
	//return (power / 10000000 ) == x;

	// no good way to determine truth
	return true;
}

std::string i32_to_string_binary( int n )
{
	std::string result;
	for ( int shift = 31; shift >= 0; shift-- )
	{
		int bit = ( 1 << shift ) & n;
		result += ( bit != 0 ) ? "1" : "0";
	}
	return result;
}

int Insertion( int N, int M, int startIndex, int endIndex )
{
	int upperMask = ~( ( 1 << ( endIndex + 1 ) ) - 1 );
	int lowerMask = ( 1 << startIndex ) - 1;
	int mask = upperMask | lowerMask;

	// wipe the relevant bits
	N &= mask;

	// write the appropriate bits
	return  N | ( M << startIndex );
}

std::string BinaryToString( float x )
{
	std::string result;
	char buffer[3]{ 0 };

	if ( IsF32Precise( x ) )
	{
		result = "0x";
		unsigned char* p = (unsigned char*) &x;

		int bytes;
		for ( int i = 3; i >= 0; i-- )
		{
			bytes = sprintf_s( buffer, sizeof( buffer ), "%02x", p[i] );
			assert( bytes == 2 );

			result += buffer;
		}
	}
	else
	{
		result = "ERROR";
	}

	return result;
}

int FlipBitToWin( int n )
{
	auto CountLongestStreak = [] ( int k )
		{
			std::string representation = i32_to_string_binary( k );
			char* cspRep = (char*) representation.c_str( );
			const char* delim = "0";
			rsize_t maxSize = representation.size( );
			char* nextToken;

			char* token = strtok_s( cspRep, delim, &nextToken );

			std::vector<size_t> lengths;

			while ( token )
			{
				lengths.push_back( strnlen_s( token, maxSize ) );
				token = strtok_s( NULL, delim, &nextToken );
			}

			if ( lengths.size( ) > 0 )
			{
				return *std::max_element( lengths.begin( ), lengths.end( ) );
			}
			else
			{
				return (size_t) 1;
			}
		};

	std::vector<size_t> streaks;
	for ( int i = 0; i < 32; i++ )
	{
		int m = SetBit( n, i );
		streaks.push_back( CountLongestStreak( m ) );
	}

	return (int) *std::max_element( streaks.begin( ), streaks.end( ) );

}
std::pair<unsigned int, unsigned int> NextNumber( int n )
{
	// first find lowest bit set to 1
	unsigned int lowestOneIndex = 0;
	while ( not GetBit( n, lowestOneIndex ) )
	{
		lowestOneIndex += 1;
	}

	// next find the second highest index with bit set to 0
	unsigned int secondZeroIndex = 31;
	bool firstOne = false;
	bool bEqualsZero = false;

	while ( ( not firstOne ) or  ( bEqualsZero = GetBit( n, secondZeroIndex ) ) )
	{
		firstOne |= bEqualsZero;
		secondZeroIndex--;

		if ( secondZeroIndex == 0 )
			break;
	}

	
}
;