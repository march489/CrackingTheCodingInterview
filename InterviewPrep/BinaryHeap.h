#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>

class BinaryHeap
{
public:
	BinaryHeap( );
	BinaryHeap( const BinaryHeap& ) = delete;
	BinaryHeap& operator=( const BinaryHeap& ) = delete;
	~BinaryHeap( );

public:
	// accessors and data
	size_t size( ) const;

	// data structure
	void Insert( int val );
	int ExtractMin( );
	inline int Min( ) const;

	// for debugging
	void Print( ) const;

	static void RunTests_BinaryHeap( );

private:
	size_t GetParentIndex( size_t childIndex ) const;
	inline size_t GetLeftChildIndex( size_t parentIndex ) const;
	inline size_t GetRightChildIndex( size_t parentIndex ) const;

private:
	std::vector<int> heap;
};
#endif // !BINARY_HEAP_H
