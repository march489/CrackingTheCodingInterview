#ifndef MIN_STACK_NODE_H
#define MIN_STACK_NODE_H

#include "StackNode.h"
#include <limits>

class MinStack;


class MinStackNode : public StackNode<int>
{
public:
	MinStackNode( ) = delete;
	MinStackNode( const MinStackNode& ) = delete;
	MinStackNode& operator=( const MinStackNode& ) = delete;
	virtual ~MinStackNode( ) = default;

	MinStackNode( int k );

	friend MinStack;

private:
	int minAtPush;
};

MinStackNode::MinStackNode( int k )
	: StackNode<int>( k ),
	minAtPush{ INT_MAX }
{

}

#endif // !MIN_STACK_NODE_H
