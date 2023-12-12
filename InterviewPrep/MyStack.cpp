#include "MyStack.h"
#include <assert.h>

template<typename T>
MyStack<T>::MyStack( )
	: pTop{ nullptr }
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

	return val;
}

template<typename T>
void MyStack<T>::push( T item )
{
	StackNode<T>* pNode = new StackNode<T>( item );
	assert( pNode );

	pNode->pNext = this->pTop;
	this->pTop = pNode->pNext;
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

