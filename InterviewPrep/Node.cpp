#include "Node.h"
#include <assert.h>
#include <iostream>

int Node::nodeCount = 0;

void Node::RunTests_Node()
{
	std::cout << "Beginning Node tests...";

	Node* pHead = new Node( 1 );
	
	for (int i = 2; i <= 100; i++)
	{
		pHead->AppendToTail( i );
	}

	assert( Node::nodeCount == 100 );

	Node* it = pHead;
	for (int i = 1; i <= 100; i++)
	{
		assert( it->data == i );
		it = it->pNext;
	}

	Node::DeleteList( pHead );

	// make sure all dynamic allocations have been freed
	assert( Node::nodeCount == 0 );

	std::cout << " all tests passed." << std::endl;
}

Node::~Node()
{
	Node::nodeCount--;
}

Node::Node( int k )
	: pNext( nullptr ), data( k )
{
	Node::nodeCount++;
}

Node* Node::AppendToTail( int k )
{
	Node* pEnd = new Node( k );
	assert( pEnd );

	Node* it = this;
	while (it->pNext != nullptr)
	{
		it = it->pNext;
	}

	assert( it );
	assert( it->pNext == nullptr );
	it->pNext = pEnd;
	return pEnd;
}

void Node::DeleteList( Node* pNode )
{
	Node* head = pNode;
	Node* next = pNode->pNext;

	while (head)
	{
		delete head;
		head = next;
		next = head ? head->pNext : nullptr;
	}

	assert( head == nullptr );
	pNode = nullptr;
}