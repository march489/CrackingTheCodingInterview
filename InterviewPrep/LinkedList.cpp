#include "LinkedList.h"
#include "Node.h"
#include <assert.h>
#include <iostream>
#include <unordered_set>

LinkedList::LinkedList( )
	: poHead( nullptr )
{

}

Node* LinkedList::AppendNodeToTail( int k )
{
	Node* pNewNode = nullptr;

	if ( this->poHead )
	{
		pNewNode = this->poHead->AppendToTail( k );
		assert( pNewNode );
	}
	else
	{
		pNewNode = new Node( k );
		assert( pNewNode );
		this->poHead = pNewNode;
	}

	return pNewNode;
}

Node* LinkedList::FindNode( int k )
{
	Node* it = this->poHead;

	while ( it && it->data != k )
	{
		it = it->pNext;
	}

	// if we leave the while-loop, it's either because
	// a) we found the node with the correct data, or
	// b) we've reached the end of the list (nullptr)
	return it;
}

bool LinkedList::DeleteNode( int k )
{
	if ( this->poHead )
	{
		if ( this->poHead->data == k )
		{
			Node* tmp = this->poHead;
			this->poHead = this->poHead->pNext;
			delete tmp;
			tmp = nullptr;

			return true;
		}
		else
		{
			Node* pPrev = this->poHead;
			Node* pDeleteMe = this->poHead->pNext;

			while ( pDeleteMe && pDeleteMe->data != k )
			{
				pPrev = pDeleteMe;
				pDeleteMe = pDeleteMe->pNext;
			}

			// if we leave the while-loop, it's either because
			// a) we found the node with the correct data, or
			// b) we've reached the end of the list (nullptr)

			if ( pDeleteMe )
			{
				// option (a)
				pPrev->pNext = pDeleteMe->pNext;
				delete pDeleteMe;
				pDeleteMe = nullptr;

				// successful deletion
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

void LinkedList::ClearList( )
{
	while ( this->poHead )
	{
		this->DeleteNode( this->poHead->data );
	}

	assert( this->poHead == nullptr );
}

void LinkedList::RemoveDuplicates( )
{
	std::unordered_set<int> keys = std::unordered_set<int>( );

	Node* pNode = this->poHead;

	while ( pNode )
	{
		bool insertSuccessful = keys.insert( pNode->data ).second;

		// no true insertion --> we have a duplicate
		// delete the earlier copy in the list
		// cant do better --> 
		// in singly linked lists you have to walk the list
		// to adjust pointers after delete 
		// (actually slower to delete this particular node)
		if ( !insertSuccessful )
		{
			this->DeleteNode( pNode->data );
		}

		pNode = pNode->pNext;
	}
}

void LinkedList::DeleteMiddleNode( )
{
	Node* pSlow = this->poHead;

	if ( pSlow == nullptr )
	{
		// early exit --> list is empty
		return;
	}
	else
	{
		// do nothing
	}

	Node* pFast = pSlow->pNext;

	if ( pFast == nullptr || pFast->pNext == nullptr )
	{
		// early exit -> list is too short to have "middle" elements
		return;
	}
	else
	{
		// do nothing, keep going
	}

	// we know now we have at least 3 elements on the list
	// pSlow == list[0]
	// pFast == list[1]

	Node* pPrev = nullptr;

	// walk the list
	while ( pFast && pFast->pNext )
	{
		pPrev = pSlow;
		pSlow = pSlow->pNext;
		pFast = pFast->pNext;

		if ( pFast )
		{
			pFast = pFast->pNext;
		}
	}

	// we fall out of the while loop when pFast reaches the end of the list
	// do pointer surgery
	pPrev->pNext = pSlow->pNext;

	delete pSlow;
	pSlow = nullptr;
}

Node* LinkedList::KthToLast( int k ) const
{
	Node* pNode{ nullptr };
	Node* pFast{ nullptr };

	if ( k >= 0 )
	{
		pFast = this->poHead;

		while ( pFast && k > 0 )
		{
			pFast = pFast->pNext;
			k--;
		}

		// when we fall out of the for loop,
		// either pFast is valid or nullptr
		// if valid, then k guaranteed to be 0.

		if ( pFast )
		{
			pNode = this->poHead;

			while ( pFast->pNext )
			{
				pFast = pFast->pNext;
				pNode = pNode->pNext;
			}
		}
		else
		{
			// do nothing
		}
	}
	else
	{
		// do nothing
	}

	return pNode;
}

void LinkedList::Partition( int k )
{
	Node* pNode = this->poHead;
	Node* pLeftPartition = nullptr;
	Node* pLeftTail = nullptr;
	Node* pRightPartition = nullptr;
	Node* pRightTail = nullptr;

	auto addToPartition = [] ( Node*& pPartitionHead, Node*& pPartitionTail, Node* p )
		{
			if ( pPartitionTail )
			{
				assert( pPartitionHead );
				assert( pPartitionTail->pNext == nullptr );

				pPartitionTail->pNext = p;
				pPartitionTail = p;
			}
			else
			{
				assert( pPartitionHead == nullptr );

				pPartitionHead = p;
				pPartitionTail = p;
			}
		};

	while ( pNode )
	{
		if ( pNode->data < k )
		{
			addToPartition( pLeftPartition, pLeftTail, pNode );
		}
		else
		{
			addToPartition( pRightPartition, pRightTail, pNode );
		}

		Node* pTmp = pNode;

		// disconnect the node
		pNode = pNode->pNext;
		pTmp->pNext = nullptr;
	}

	if ( pLeftPartition )
	{
		if( pLeftTail )
		{
			this->poHead = pLeftPartition;
			pLeftTail->pNext = pRightPartition;
		}
		else
		{
			// scream
			assert( false );
		}
	}
	else
	{
		this->poHead = pRightPartition;
	}
}

void LinkedList::RunTests_LinkedList( )
{
	std::cout << "Beginning LinkedList tests...";

	LinkedList::DeleteTest( );
	LinkedList::RemoveDupsTest( );
	LinkedList::DeleteMiddleTest( );
	LinkedList::KthToLastTest( );
	LinkedList::PartitionTest( );

	// assert that all dynamic allocations have been freed
	assert( Node::nodeCount == 0 );

	std::cout << " all tests passed." << std::endl;
}

void LinkedList::DeleteTest( )
{
	LinkedList pList = LinkedList( );
	assert( pList.poHead == nullptr );

	pList.AppendNodeToTail( 10 );
	pList.AppendNodeToTail( 20 );
	pList.AppendNodeToTail( 30 );
	pList.AppendNodeToTail( 40 );

	// walk down the list and test
	Node* pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 10 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 20 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 4 );

	// delete from the middle
	bool status = pList.DeleteNode( 20 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 10 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 3 );

	// delete from the beginning
	status = pList.DeleteNode( 10 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 2 );

	// delete from the end
	status = pList.DeleteNode( 40 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 1 );

	// delete the last element
	status = pList.DeleteNode( 30 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 0 );
}

void LinkedList::RemoveDupsTest( )
{
	LinkedList list = LinkedList( );

	list.AppendNodeToTail( 10 );
	list.AppendNodeToTail( 20 );
	list.AppendNodeToTail( 30 );
	list.AppendNodeToTail( 40 );
	list.AppendNodeToTail( 20 );
	list.AppendNodeToTail( 30 );
	list.AppendNodeToTail( 40 );
	list.AppendNodeToTail( 50 );

	assert( Node::nodeCount == 8 );

	list.RemoveDuplicates( );

	assert( Node::nodeCount == 5 );

	// walk the list
	// walk down the list and test
	Node* pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 10 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 20 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 50 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
}

void LinkedList::DeleteMiddleTest( )
{
	LinkedList list = LinkedList( );

	for ( int i = 0; i < 5; i++ )
	{
		list.AppendNodeToTail( i );
	}

	Node* pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 5 );

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 4 );

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 3 );

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 2 );

	// future calls should do nothing
	// because there are no middle nodes

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 2 );
}

void LinkedList::KthToLastTest( )
{
	LinkedList list;

	for ( int i = 9; i >= 0; i-- )
	{
		list.AppendNodeToTail( i );
	}

	assert( Node::nodeCount == 10 );

	Node* pNode = nullptr;
	for ( int i = 0; i < 10; i++ )
	{
		pNode = list.KthToLast( i );
		assert( pNode );
		assert( pNode->data == i );
	}
}

void LinkedList::PartitionTest( )
{
	LinkedList list1;

	list1.AppendNodeToTail( 3 );
	list1.AppendNodeToTail( 0 );
	list1.AppendNodeToTail( 5 );
	list1.AppendNodeToTail( 3 );
	list1.AppendNodeToTail( 2 );
	list1.AppendNodeToTail( 4 );
	list1.AppendNodeToTail( 8 );
	list1.AppendNodeToTail( 8 );
	list1.AppendNodeToTail( 1 );
	list1.AppendNodeToTail( 1 );
	list1.AppendNodeToTail( -2 );
	list1.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 12 );

	list1.Partition( 3 );

	Node* pNode = list1.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	/////////////////////////////////

	LinkedList list2;

	list2.AppendNodeToTail( 3 );
	list2.AppendNodeToTail( 0 );
	list2.AppendNodeToTail( 5 );
	list2.AppendNodeToTail( 3 );
	list2.AppendNodeToTail( 2 );
	list2.AppendNodeToTail( 4 );
	list2.AppendNodeToTail( 8 );
	list2.AppendNodeToTail( 8 );
	list2.AppendNodeToTail( 1 );
	list2.AppendNodeToTail( 1 );
	list2.AppendNodeToTail( -2 );
	list2.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 24 );

	list2.Partition( 8 );

	pNode = list2.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	/////////////////////////////////

	LinkedList list3;

	list3.AppendNodeToTail( 3 );
	list3.AppendNodeToTail( 0 );
	list3.AppendNodeToTail( 5 );
	list3.AppendNodeToTail( 3 );
	list3.AppendNodeToTail( 2 );
	list3.AppendNodeToTail( 4 );
	list3.AppendNodeToTail( 8 );
	list3.AppendNodeToTail( 8 );
	list3.AppendNodeToTail( 1 );
	list3.AppendNodeToTail( 1 );
	list3.AppendNodeToTail( -2 );
	list3.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 36 );

	list3.Partition( -2 );

	pNode = list3.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	/////////////////////////////////

	LinkedList list4;

	list4.AppendNodeToTail( 3 );
	list4.AppendNodeToTail( 0 );
	list4.AppendNodeToTail( 5 );
	list4.AppendNodeToTail( 3 );
	list4.AppendNodeToTail( 2 );
	list4.AppendNodeToTail( 4 );
	list4.AppendNodeToTail( 8 );
	list4.AppendNodeToTail( 8 );
	list4.AppendNodeToTail( 1 );
	list4.AppendNodeToTail( 1 );
	list4.AppendNodeToTail( -2 );
	list4.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 48 );

	// should do nothing
	list4.Partition( 11 );

	pNode = list4.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	// should do nothing
	list4.Partition( -5 );

	pNode = list4.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );
}

LinkedList::~LinkedList( )
{
	this->ClearList( );
}