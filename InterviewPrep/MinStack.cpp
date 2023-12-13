#include "MinStack.h"
#include "MinStackNode.h"
#include <algorithm>

MinStack::MinStack( )
	: MyStack<int>( )
{

}

MinStack::~MinStack( )
{

}

void MinStack::push( int item )
{
	MinStackNode* pPrevTop = (MinStackNode*) this->pTop;
	int prevMin = pPrevTop ? pPrevTop->minAtPush : INT_MAX;

	MinStackNode* pNode = new MinStackNode( item );
	assert( pNode );

	pNode->minAtPush = std::min( item, prevMin );

	pNode->pNext = this->pTop;
	this->pTop = pNode;

	this->_size++;
}

int MinStack::min( ) const
{
	assert( this->pTop );
	MinStackNode* pMinTop = (MinStackNode*) this->pTop;
	return pMinTop->minAtPush;
}

void MinStack::sort( )
{
	if ( this->isEmpty( ) )
	{
		return;
	}

	MinStack tmpStack;
	
	for ( size_t i = 1; i < this->_size; i++ )
	{
		// move the top i elements over
		for ( int j = 0; j < i; j++ )
		{
			tmpStack.push( this->pop( ) );
		}

		int val = this->pop( );

		while ( not tmpStack.isEmpty( ) && tmpStack.peek( ) > val )
		{
			this->push( tmpStack.pop( ) );
		}

		// exit the loop if tmpStack is empty 
		// or the top of tmpStack is <= val

		this->push( val );

		// move the rest of the stack
		while ( not tmpStack.isEmpty( ) )
		{
			this->push( tmpStack.pop( ) );
		}
	}
}
