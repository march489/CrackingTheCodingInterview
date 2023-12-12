#include "LinkedList.h"
#include "Node.h"
#include <assert.h>
#include <unordered_set>
#include <stack>
#include <deque>

LinkedList::LinkedList( )
	: poHead( nullptr )
{

}

LinkedList::LinkedList( const LinkedList& inNode )
	: poHead( nullptr )
{
	Node* pOriginalNode = inNode.poHead;
	Node* pCopyTail = nullptr;

	while ( pOriginalNode )
	{
		if ( this->poHead )
		{
			// hygiene check
			assert( pCopyTail && pCopyTail->pNext == nullptr );

			// create new node
			pCopyTail->pNext = new Node( pOriginalNode->data );
			assert( pCopyTail->pNext );

			pCopyTail = pCopyTail->pNext;
		}
		else
		{
			this->poHead = new Node( pOriginalNode->data );
			assert( this->poHead );

			pCopyTail = this->poHead;
		}

		pOriginalNode = pOriginalNode->pNext;
	}
}

LinkedList& LinkedList::operator=( const LinkedList& inNode )
{
	// just in case
	this->ClearList( );

	// copy the list over
	Node* pOriginalNode = inNode.poHead;
	Node* pCopyTail = nullptr;

	while ( pOriginalNode )
	{
		if ( this->poHead )
		{
			// hygiene check
			assert( pCopyTail && pCopyTail->pNext == nullptr );

			// create new node
			pCopyTail->pNext = new Node( pOriginalNode->data );
			assert( pCopyTail->pNext );

			pCopyTail = pCopyTail->pNext;
		}
		else
		{
			this->poHead = new Node( pOriginalNode->data );
			assert( this->poHead );

			pCopyTail = this->poHead;
		}

		pOriginalNode = pOriginalNode->pNext;
	}

	return *this;
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
		if ( pLeftTail )
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

LinkedList LinkedList::ReverseSum( const LinkedList& rhs ) const
{
	Node* pLeft = this->poHead;
	Node* pRight = rhs.poHead;
	int carry = 0;

	LinkedList result;
	Node* pResultTail{ nullptr };

	while ( pLeft || pRight )
	{
		int left = 0;
		int right = 0;

		// get digits safely
		if ( pLeft )
		{
			left = pLeft->data;
			pLeft = pLeft->pNext;
		}
		else
		{
			// do nothing
		}

		if ( pRight )
		{
			right = pRight->data;
			pRight = pRight->pNext;
		}
		else
		{
			// do nothing
		}

		int tmp = left + right + carry;

		// adjust if over 10 & set carry flag
		if ( tmp > 9 )
		{
			carry = 1;
			tmp -= 10;
		}
		else
		{
			carry = 0;
		}

		// create new node
		Node* pNode = new Node( tmp );
		assert( pNode );

		// attach to result
		if ( result.poHead )
		{
			assert( pResultTail );
			pResultTail->pNext = pNode;
		}
		else
		{
			result.poHead = pNode;
		}

		// update the tail
		pResultTail = pNode;
	}

	if ( carry == 1 )
	{
		pResultTail->pNext = new Node( 1 );
		assert( pResultTail->pNext );
	}

	return result;
}

bool LinkedList::IsPalindrome( ) const
{
	std::deque<int> deque;

	Node* pNode = this->poHead;

	while ( pNode )
	{
		deque.push_back( pNode->data );
		pNode = pNode->pNext;
	}

	while ( deque.size( ) > 1 )
	{
		if ( deque.front( ) == deque.back( ) )
		{
			deque.pop_back( );
			deque.pop_front( );
		}
		else
		{
			break;
		}
	}

	return deque.size( ) <= 1;
}

bool LinkedList::IsPalindromeAlt( ) const
{
	auto CloneAndReverseList = [] ( const LinkedList& list )
		{
			Node* pNode = list.poHead;
			Node* pNewHead = nullptr;
			Node* tmp = nullptr;

			while ( pNode )
			{
				tmp = new Node( pNode->data );
				tmp->pNext = pNewHead;
				pNewHead = tmp;

				pNode = pNode->pNext;
			}

			LinkedList result;
			result.poHead = pNewHead;

			return result;
		};

	LinkedList listReversed = CloneAndReverseList( *this );

	Node* pForward = this->poHead;
	Node* pReverse = listReversed.poHead;

	bool bIsPalindrome = true;

	while ( pForward && bIsPalindrome )
	{
		bIsPalindrome = ( pForward->data == pReverse->data );
		pForward = pForward->pNext;
		pReverse = pReverse->pNext;
	}

	return bIsPalindrome;
}

std::optional<Node*> LinkedList::Intersect( const LinkedList& otherList ) const
{
	std::unordered_set<Node*> addresses;
	std::optional<Node*> result;

	Node* pNode = this->poHead;
	while ( pNode )
	{
		addresses.insert( pNode );
		pNode = pNode->pNext;
	}

	bool bUniqueInsertion = true;
	pNode = otherList.poHead;
	while ( pNode && bUniqueInsertion )
	{
		bUniqueInsertion = addresses.insert( pNode ).second;
		if ( bUniqueInsertion )
		{
			pNode = pNode->pNext;
		}
		else
		{
			break;
		}
	}

	if ( not bUniqueInsertion )
	{
		result.emplace( pNode );
	}

	return result;
}

std::optional<Node*> LinkedList::ContainsLoop( ) const
{
	std::unordered_set<Node*> addresses;

	Node* pNode = this->poHead;
	bool bUniqueInsertion = true;
	while ( pNode )
	{
		bUniqueInsertion = addresses.insert( pNode ).second;
		if ( bUniqueInsertion )
		{
			pNode = pNode->pNext;
		}
		else
		{
			break;
		}
	}

	return bUniqueInsertion ? std::nullopt : std::optional<Node*>( std::in_place, pNode );
}

LinkedList::~LinkedList( )
{
	this->ClearList( );
}