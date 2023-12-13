#include "BinaryHeap.h"
#include <iostream>
#include <assert.h>

void BinaryHeap::RunTests_BinaryHeap( )
{
	std::cout << "Begining BinaryHeap tests...";

	BinaryHeap heap;

	heap.Insert( 5 );
	// heap.Print( );

	heap.Insert( 10 );
	// heap.Print( );

	heap.Insert( 11 );
	// heap.Print( );

	heap.Insert( 6 );
	// heap.Print( );

	heap.Insert( 4 );
	// heap.Print( );

	heap.Insert( 12 );
	// heap.Print( );

	heap.Insert( 7 );
	// heap.Print( );

	assert( heap.size( ) == 7 );

	int val;

	val = heap.ExtractMin( );
	assert( val == 4 );
	assert( heap.size( ) == 6 );

	val = heap.ExtractMin( );
	assert( val == 5 );
	assert( heap.size( ) == 5 );

	val = heap.ExtractMin( );
	assert( val == 6 );
	assert( heap.size( ) == 4 );

	val = heap.ExtractMin( );
	assert( val == 7 );
	assert( heap.size( ) == 3 );

	val = heap.ExtractMin( );
	assert( val == 10 );
	assert( heap.size( ) == 2 );

	val = heap.ExtractMin( );
	assert( val == 11 );
	assert( heap.size( ) == 1 );

	val = heap.ExtractMin( );
	assert( val == 12 );
	assert( heap.size( ) == 0 );

	std::cout << " all tests passed." << std::endl;
}