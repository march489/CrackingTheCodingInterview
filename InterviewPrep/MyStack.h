#ifndef MY_STACK_H
#define MY_STACK_H

#include "StackNode.h"

template<typename T>
class MyStack
{
public:
	MyStack( );
	MyStack( const MyStack& ) = delete;
	MyStack& operator=( const MyStack& ) = delete;
	~MyStack( );

	T pop( );
	void push( T item );
	T& peek( ) const;
	bool isEmpty( ) const;

private:
	
private:
	// data
	StackNode<T>* pTop;
};

#endif // !MY_STACK_H