#include "BitManipulation.h"
#include <iostream>
#include <assert.h>

void InsertionTest( )
{
	int N = 0b10000000000;
	int M = 0b10011;
	int i = 2;
	int j = 6;

	int result = Insertion( N, M, i, j );
	assert( result == 0b10001001100 );

	N = 0b100010000111;
	M = 0b1011;
	i = 3;
	j = 6;

	result = Insertion( N, M, i, j );
	assert( result == 0b100011011111 );

	N = 0xab860013;
	M = 0xcd;
	i = 8;
	j = 15;

	result = Insertion( N, M, i, j );
	assert( result == 0xab86cd13 );
}

void BinaryToStringTest( )
{
	float x = 0.815f;
	std::string representation = BinaryToString( x );
	assert( representation == "0x3f50a3d7" );

	x = 0.31255f;
	representation = BinaryToString( x );
	assert( representation == "0x3ea0068e" );
}

void BinaryRepTest( )
{
	int x = 12;
	std::string representation = i32_to_string_binary( x );
	assert( representation == "00000000000000000000000000001100" );

	x = -12;
	representation = i32_to_string_binary( x );
	assert( representation == "11111111111111111111111111110100" );
}

void FlipBitToWinTest( )
{
	int x = 1775;
	assert( FlipBitToWin( x ) == 8 );
}

void NextNumberTest( )
{
}

void RunTests_BitManipulation( )
{
	std::cout << "Starting BitManipulation tests...";

	ShiftOperationDemos( );
	InsertionTest( );
	BinaryToStringTest( );
	BinaryRepTest( );
	FlipBitToWinTest( );
	NextNumberTest( );

	std::cout << " all tests pass.\n";
}