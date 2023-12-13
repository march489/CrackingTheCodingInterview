#include "BinaryHeap.h"
#include <assert.h>
#include <iostream>

BinaryHeap::BinaryHeap( )
	: heap{ std::vector<int>( ) }
{

}

BinaryHeap::~BinaryHeap( )
{

}

size_t BinaryHeap::GetLeftChildIndex( size_t parentIndex ) const
{
	return 2 * parentIndex + 1;
}

size_t BinaryHeap::GetRightChildIndex( size_t parentIndex ) const
{
	return 2 * parentIndex + 2;
}

size_t BinaryHeap::GetParentIndex( size_t childIndex ) const
{
	if ( childIndex == 0 )
	{
		return 0;
	}

	return ( childIndex - 1 ) / 2;

}

size_t BinaryHeap::size( ) const
{
	return this->heap.size( );
}

int BinaryHeap::Min( ) const
{
	assert( not this->heap.empty( ) );
	return this->heap[0];
}

int BinaryHeap::ExtractMin( )
{
	assert( not this->heap.empty( ) );

	// save the last val
	size_t index = 0;
	int val = this->heap[index];

	// swap the min with the last value
	size_t lastIndex = this->heap.size( ) - 1;
	std::swap( this->heap[0],
			   this->heap[lastIndex] );

	// the back now holds the prev min, and we pop() it
	this->heap.pop_back( );

	size_t childIndex = this->GetLeftChildIndex( index );

	// sink
	while ( childIndex < this->heap.size( ) )
	{
		if ( childIndex + 1 < this->heap.size( ) &&
			 this->heap[childIndex] > this->heap[childIndex + 1] )
		{
			// move to the right child if it exists and is bigger than the left
			childIndex++;
		}

		if ( this->heap[childIndex] < this->heap[index] )
		{
			std::swap( this->heap[childIndex], this->heap[index] );
			index = childIndex;
			childIndex = this->GetLeftChildIndex( index );
		}
		else
		{
			break;
		}
	}

	return val;
}

void BinaryHeap::Insert( int val )
{
	size_t index = this->heap.size( );
	this->heap.push_back( val );

	// swim up if needed
	if (index > 0 )
	{
		size_t parentIndex = this->GetParentIndex( index );

		// swim up
		while ( index > 0 &&
				this->heap[parentIndex] > this->heap[index] )
		{
			std::swap( this->heap[parentIndex], this->heap[index] );
			index = parentIndex;
			parentIndex = this->GetParentIndex( index );
		}
	}
}

void BinaryHeap::Print( ) const
{
	std::cout << "Binary Heap array: ";

	for ( size_t i = 0; i < this->heap.size( ); i++ )
	{
		std::cout << this->heap[i] << " ";
	}

	std::cout << std::endl;
}