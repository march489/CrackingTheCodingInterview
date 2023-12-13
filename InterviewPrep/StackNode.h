#ifndef STACK_NODE_H
#define STACK_NODE_H

template<typename T>
class MyStack;

template<typename T>
class StackNode
{
public:
	StackNode( ) = delete;
	StackNode( const StackNode& ) = delete;
	StackNode& operator=( const StackNode& ) = delete;
	virtual ~StackNode( ) = default;

	StackNode( T in );

	friend MyStack;

public:
	// Data
	StackNode<T>* pNext;
	T data;
};

template<typename T>
StackNode<T>::StackNode( T in )
	: data{ in }, pNext{ nullptr }
{

}


#endif