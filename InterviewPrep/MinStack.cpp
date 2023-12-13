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
}

int MinStack::min( ) const
{
	assert( this->pTop );
	MinStackNode* pMinTop = (MinStackNode*) this->pTop;
	return pMinTop->minAtPush;
}
