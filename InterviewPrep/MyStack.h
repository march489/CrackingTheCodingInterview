#ifndef MY_STACK_H
#define MY_STACK_H

#include "StackNode.h"
#include <assert.h>

template<typename T>
class StackNode;

template<typename T>
class MyStack
{
public:
	MyStack( );
	MyStack( const MyStack& ) = delete;
	MyStack& operator=( const MyStack& ) = delete;
	virtual ~MyStack( );

	T pop( );
	virtual void push( T item );
	T& peek( ) const;
	bool isEmpty( ) const;
	size_t size( ) const;

	static const size_t STACK_CAPACITY = 5;

public:
	// data
	StackNode<T>* pTop;
	MyStack<T>* pNextStack;
	size_t _size;
};

template<typename T>
size_t MyStack<T>::size( ) const
{
	return this->_size;
}

template<typename T>
MyStack<T>::MyStack( )
	: pTop{ nullptr }, pNextStack{ nullptr }, _size{ 0 }
{
}

template<typename T>
MyStack<T>::~MyStack( )
{
	StackNode<T>* pNode = this->pTop;
	StackNode<T>* tmp{ nullptr };

	while ( pTop )
	{
		tmp = pTop;
		pTop = pTop->pNext;

		delete tmp;
		tmp = nullptr;
	}
}

template<typename T>
T MyStack<T>::pop( )
{
	assert( this->pTop );

	StackNode<T>* pNode = this->pTop;
	T val = pNode->data;

	// clean up
	this->pTop = this->pTop->pNext;
	delete pNode;
	pNode = nullptr;

	this->_size--;

	return val;
}

template<typename T>
void MyStack<T>::push( T item )
{
	StackNode<T>* pNode = new StackNode<T>( item );
	assert( pNode );

	pNode->pNext = this->pTop;
	this->pTop = pNode;

	this->_size++;
}

template<typename T>
T& MyStack<T>::peek( ) const
{
	assert( this->pTop );
	return this->pTop->data;
}

template<typename T>
bool MyStack<T>::isEmpty( ) const
{
	return ( this->pTop == nullptr );
}




#endif // !MY_STACK_H