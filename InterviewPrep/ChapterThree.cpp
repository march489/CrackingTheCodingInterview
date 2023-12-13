#include "ChapterThree.h"
#include "MinStack.h"
#include "StackOfPlates.h"
#include <iostream>
#include <assert.h>

void RunTests_ChapterThree( )
{
	std::cout << "Beginning Stack tests...";
	
	/////////////////////////////
	////// STRING STACK /////////
	/////////////////////////////
	
	MyStack<std::string> stringStack;
	assert( stringStack.isEmpty( ) );

	const std::string s0 = "What a to do";
	const std::string s1 = "to die today";
	const std::string s2 = "at a minute or two to two";
	const std::string s3 = "a thing distinctly";
	const std::string s4 = "hard to say but";
	const std::string s5 = "harder still to do";

	stringStack.push( s5 );
	stringStack.push( s4 );
	stringStack.push( s3 );
	stringStack.push( s2 );
	stringStack.push( s1 );
	stringStack.push( s0 );

	assert( not stringStack.isEmpty( ) );

	std::string peek;
	std::string pop;

	peek = stringStack.peek( );
	assert( peek == s0 );

	pop = stringStack.pop( );
	assert( pop == s0 );

	peek = stringStack.peek( );
	assert( peek == s1 );

	pop = stringStack.pop( );
	assert( pop == s1 );

	peek = stringStack.peek( );
	assert( peek == s2 );

	pop = stringStack.pop( );
	assert( pop == s2 );

	peek = stringStack.peek( );
	assert( peek == s3 );

	pop = stringStack.pop( );
	assert( pop == s3 );

	peek = stringStack.peek( );
	assert( peek == s4 );

	pop = stringStack.pop( );
	assert( pop == s4 );

	peek = stringStack.peek( );
	assert( peek == s5 );

	pop = stringStack.pop( );
	assert( pop == s5 );

	assert( stringStack.isEmpty( ) );

	/////////////////////////////
	///////// MIN STACK /////////
	/////////////////////////////

	MinStack stack;
	assert( stack.isEmpty( ) );

	stack.push( 12 );
	stack.push( 14 );
	stack.push( 11 );
	stack.push( 9 );
	stack.push( 20 );

	assert( not stack.isEmpty( ) );

	int pk;
	int pp;
	int mn;

	pk = stack.peek( );
	assert( pk == 20 );
	mn = stack.min( );
	assert( mn == 9 );
	pp = stack.pop( );
	assert( pp = 20 );


	pk = stack.peek( );
	assert( pk == 9 );
	mn = stack.min( );
	assert( mn == 9 );
	pp = stack.pop( );
	assert( pp = 9 );

	pk = stack.peek( );
	assert( pk == 11 );
	mn = stack.min( );
	assert( mn == 11 );
	pp = stack.pop( );
	assert( pp = 11 );

	pk = stack.peek( );
	assert( pk == 14 );
	mn = stack.min( );
	assert( mn == 12 );
	pp = stack.pop( );
	assert( pp = 14 );


	pk = stack.peek( );
	assert( pk == 12 );
	mn = stack.min( );
	assert( mn == 12 );
	pp = stack.pop( );
	assert( pp = 12 );

	assert( stack.isEmpty( ) );

	/////////////////////////////
	////// STACK OF PLATES //////
	/////////////////////////////

	StackOfPlates<int> plates;

	assert( plates.isEmpty( ) );

	for ( int i = 0; i < 12; i++ )
	{
		plates.push( i );
	}

	assert( plates.size( ) == 12 );

	MyStack<int>* pStack = plates.pTopStack;
	assert( pStack );
	assert( pStack->size( ) == 2 );

	StackNode<int>* pNode = pStack->pTop;
	assert( pNode );
	assert( pNode->data == 11 );

	pNode = pNode->pNext;
	assert( pNode );
	assert( pNode->data == 10 );

	pNode = pNode->pNext;
	assert( pNode == nullptr );



	pStack = pStack->pNextStack;
	assert( pStack );
	assert( pStack->size( ) == MyStack<int>::STACK_CAPACITY );

	pNode = pStack->pTop;
	assert( pNode );
	assert( pNode->data == 9 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 7 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 6 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode == nullptr );


	pStack = pStack->pNextStack;
	assert( pStack );
	assert( pStack->size( ) == MyStack<int>::STACK_CAPACITY );

	pNode = pStack->pTop;
	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode == nullptr );

	pStack = pStack->pNextStack;
	assert( pStack == nullptr );

	plates.pop( );
	plates.pop( );
	plates.pop( );

	assert( plates.size( ) == 9 );

	pStack = plates.pTopStack;
	assert( pStack );
	assert( pStack->size( ) == 4 );

	std::cout << " all tests passed" << std::endl;
}