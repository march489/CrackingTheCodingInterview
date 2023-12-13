#ifndef STACK_OF_PLATES_H
#define STACK_OF_PLATES_H

#include "MyStack.h"

template<typename T>
class StackOfPlates
{
public:
	StackOfPlates( );
	StackOfPlates( const StackOfPlates& ) = delete;
	StackOfPlates& operator=( const StackOfPlates& ) = delete;
	~StackOfPlates( );

	void push( T _data );
	T& peek( ) const;
	T pop( );
	bool isEmpty( ) const;
	size_t size( ) const;
	T popAt( int index );

private:
	void privAddStack( );
	void privDeleteTopStack( );

public:
	MyStack<T>* pTopStack;
	size_t _size;
};

template<typename T>
T StackOfPlates<T>::popAt( int index )
{
	assert( this->_size / MyStack<T>::STACK_CAPACITY >= index );
	MyStack<T>* pStack = this->pTopStack;

	while ( pStack && index > 0 )
	{
		pStack = pStack->pNextStack;
		index--;
	}

	if ( pStack && not pStack->isEmpty( ) )
	{
		T val = pStack->pop( );
		return val;
	}
	else
	{
		assert( false );
	}
}

template<typename T>
StackOfPlates<T>::~StackOfPlates( )
{
	while ( this->pTopStack )
	{
		this->privDeleteTopStack( );
	}
}

template<typename T>
T StackOfPlates<T>::pop( )
{
	assert( this->pTopStack && not this->pTopStack->isEmpty( ) );
	T val = this->pTopStack->pop( );

	if ( pTopStack->isEmpty( ) )
	{
		this->privDeleteTopStack( );
	}

	this->_size--;
	return val;
}

template<typename T>
T& StackOfPlates<T>::peek( ) const
{
	assert( this->pTopStack && not this->pTopStack->isEmpty( ) );
	return this->pTopStack->peek( );
}

template<typename T>
void StackOfPlates<T>::push( T _data )
{
	if ( this->pTopStack && this->pTopStack->size( ) < MyStack<T>::STACK_CAPACITY )
	{
		this->pTopStack->push( _data );
	}
	else
	{
		this->privAddStack( );
		this->pTopStack->push( _data );
	}

	this->_size++;
}

template<typename T>
bool StackOfPlates<T>::isEmpty( ) const
{
	return this->_size == 0;
}

template<typename T>
size_t StackOfPlates<T>::size( ) const
{
	return this->_size;
}

template<typename T>
void StackOfPlates<T>::privDeleteTopStack( )
{
	assert( this->pTopStack );

	MyStack<T>* pTop = this->pTopStack;
	this->pTopStack = pTop->pNextStack;

	delete pTop;
	pTop = nullptr;
}

template<typename T>
void StackOfPlates<T>::privAddStack( )
{
	MyStack<T>* pStack = new MyStack<T>( );
	assert( pStack );

	pStack->pNextStack = this->pTopStack;
	this->pTopStack = pStack;
}

template<typename T>
StackOfPlates<T>::StackOfPlates( )
	: pTopStack{ nullptr }, _size{ 0 }
{
	this->privAddStack( );
}

#endif // !STACK_OF_PLATES_H
