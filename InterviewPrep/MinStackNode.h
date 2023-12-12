#ifndef MIN_STACK_NODE_H
#define MIN_STACK_NODE_H

#include "StackNode.h"

class MinStackNode : public StackNode<int>
{
public:
	MinStackNode( ) = delete;
	MinStackNode( const MinStackNode& ) = delete;
	MinStackNode& operator=( const MinStackNode& ) = delete;
	virtual ~MinStackNode( ) = default;

	MinStackNode( int k );

private:
	int minAtPush;
};

#endif // !MIN_STACK_NODE_H
