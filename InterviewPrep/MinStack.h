#ifndef MIN_STACK_H
#define MIN_STACK_H

#include "MyStack.h"


class MinStack : public MyStack<int>
{
public: 
	MinStack( );
	MinStack( const MinStack& ) = delete;
	MinStack& operator=( const MinStack& ) = delete;
	virtual ~MinStack( );

	int min( ) const;
	virtual void push( int item ) override;
};


#endif // !MIN_STACK_H
