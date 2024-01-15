#include "BinaryTree.h"
#include <assert.h>
#include <queue>
#include <unordered_set>

BinaryTree::BinaryTree( )
	: pRoot{ nullptr }, size( 0 )
{

}

BinaryTree::~BinaryTree( )
{
	if ( this->pRoot )
	{
		delete this->pRoot;
		this->pRoot = nullptr;
	}
}

BinaryTree::BinaryTree( const std::vector<int>& arr )
	: pRoot{ nullptr }
{
	this->pRoot = this->CreateNodesFromArray( arr, 0, (int) arr.size( ) - 1 );
}

BinaryTreeNode* BinaryTree::AddNode( int k )
{
	this->size += 1;

	if ( this->pRoot )
	{
		return this->AddNode( this->pRoot, k );
	}
	else
	{
		this->pRoot = new BinaryTreeNode( k );
		assert( this->pRoot );

		return this->pRoot;
	}
}

BinaryTreeNode* BinaryTree::FindNode( int k ) const
{
	BinaryTreeNode* pNode = this->pRoot;

	while ( pNode )
	{
		if ( pNode->data < k )
		{
			pNode = pNode->GetRightChild( );
		}
		else if ( pNode->data > k )
		{
			pNode = pNode->GetLeftChild( );
		}
		else
		{
			// match!
			break;
		}
	}

	return pNode;
}

BinaryTreeNode* BinaryTree::AddNode( BinaryTreeNode* pRoot, int k )
{
	BinaryTreeNode* pNode{ nullptr };
	if ( k < pRoot->data )
	{
		if ( pRoot->GetLeftChild( ) )
		{
			return this->AddNode( pRoot->GetLeftChild( ), k );
		}
		else
		{
			pNode = new BinaryTreeNode( k );
			assert( pNode );

			pNode->SetParent( pRoot );
			pRoot->SetLeftChild( pNode );
			return pNode;
		}
	}
	else if ( k > pRoot->data )
	{
		if ( pRoot->GetRightChild( ) )
		{
			return this->AddNode( pRoot->GetRightChild( ), k );
		}
		else
		{
			pNode = new BinaryTreeNode( k );
			assert( pNode );

			pNode->SetParent( pRoot );
			pRoot->SetRightChild( pNode );
			return pNode;
		}
	}
	else
	{
		// do nothing
	}

	return pNode;
}

BinaryTreeNode* BinaryTree::CreateNodesFromArray( const std::vector<int>& arr,
												  int start,
												  int end )
{
	if ( end < start )
	{
		return nullptr;
	}

	int midpt = ( start + end ) / 2;

	BinaryTreeNode* pNode = new BinaryTreeNode( arr[midpt] );
	assert( pNode );

	this->size += 1;

	BinaryTreeNode* pLeftChild = this->CreateNodesFromArray( arr, start, midpt - 1 );
	pNode->SetLeftChild( pLeftChild );

	if ( pLeftChild )
	{
		pLeftChild->SetParent( pNode );
	}

	BinaryTreeNode* pRightChild = this->CreateNodesFromArray( arr, midpt + 1, end );
	pNode->SetRightChild( pRightChild );

	if ( pRightChild )
	{
		pRightChild->SetParent( pNode );
	}

	return pNode;
}

std::vector<std::list<int>*>* BinaryTree::privAllSequences( BinaryTreeNode* pNode )
{
	std::vector<std::list<int>*>* pResult = new std::vector<std::list<int>*>( );
	assert( pResult );

	if ( not pNode )
	{
		pResult->push_back( new std::list<int>( ) );
		return pResult;
	}

	std::list<int>* pPrefix = new std::list<int>( );
	assert( pPrefix );
	pPrefix->push_back( pNode->data );

	std::vector<std::list<int>*>* pLeftSeqs = this->privAllSequences( pNode->leftChild );
	std::vector<std::list<int>*>* pRightSeqs = this->privAllSequences( pNode->rightChild );

	for ( std::list<int>* leftSeq : *pLeftSeqs )
	{
		for ( std::list<int>* rightSeq : *pRightSeqs )
		{
			std::vector<std::list<int>*>* pWovenLists = new std::vector<std::list<int>*>( );
			assert( pResult );

			privWeaveLists( leftSeq, rightSeq, pWovenLists, pPrefix );

			for ( std::list<int>* pList : *pWovenLists ) {
				pResult->push_back( pList );
			}
		}
	}

	return pResult;
}

int BinaryTree::privPathsWithSum( std::list<int>* totals, BinaryTreeNode* pNode, int sum ) const
{
	int result = 0;

	if ( pNode )
	{
		if ( pNode->data == sum )
		{
			// bonus path of length 1 if pNode->data == sum
			result++;
		}

		int difference = sum - pNode->data;
		for ( int& pathSum : *totals )
		{
			if ( pathSum == difference )
			{
				// count valid paths
				result++;
			}

			// update each entry to pass onto children
			pathSum += pNode->data;
		}

		// now append yourself as a link in the chain before passing to children
		totals->push_back( pNode->data );

		// call on each of your children
		result += this->privPathsWithSum( totals, pNode->leftChild, sum );
		result += this->privPathsWithSum( totals, pNode->rightChild, sum ); 

		// reset totals before returning to parent
		totals->pop_back( );
		for ( int& pathSum : *totals )
		{
			pathSum -= pNode->data;
		}

		return result;
	}
	else
	{
		// pNode == nullptr
		// we should return 0
	}

	return result;
}

void BinaryTree::privWeaveLists( std::list<int>* pFirst, std::list<int>* pSecond, std::vector<std::list<int>*>* pResults, std::list<int>* pPrefix )
{
	if ( pFirst->size( ) == 0 or pSecond->size( ) == 0 )
	{
		std::list<int>* result = new std::list<int>( );
		assert( result );

		for ( auto it = pPrefix->begin( ); it != pPrefix->end( ); it++ )
		{
			result->push_back( *it );
		}

		for ( auto it = pFirst->begin( ); it != pFirst->end( ); it++ )
		{
			result->push_back( *it );
		}

		for ( auto it = pSecond->begin( ); it != pSecond->end( ); it++ )
		{
			result->push_back( *it );
		}

		pResults->push_back( result );

		return;
	}

	// go left first
	pPrefix->push_back( pFirst->front( ) );
	pFirst->pop_front( );
	privWeaveLists( pFirst, pSecond, pResults, pPrefix );

	// reset
	pFirst->push_front( pPrefix->back( ) );
	pPrefix->pop_back( );

	// now go right
	pPrefix->push_back( pSecond->front( ) );
	pSecond->pop_front( );
	privWeaveLists( pFirst, pSecond, pResults, pPrefix );

	// reset
	pSecond->push_front( pPrefix->back( ) );
	pPrefix->pop_back( );
}

void BinaryTree::privDFS( void( BinaryTreeNode::* fptr )( void ),
						  BinaryTreeNode* pNode )
{
	if ( pNode->GetLeftChild( ) )
	{
		this->privDFS( fptr, pNode->GetLeftChild( ) );
	}

	std::invoke( fptr, pNode );

	if ( pNode->GetRightChild( ) )
	{
		this->privDFS( fptr, pNode->GetRightChild( ) );
	}
}

void BinaryTree::DFS( void ( BinaryTreeNode::* fptr ) ( void ) )
{
	if ( this->pRoot )
	{
		this->privDFS( fptr, this->pRoot );
	}
}

void BinaryTree::BFS( void ( BinaryTreeNode::* fptr ) ( void ) )
{
	std::queue<BinaryTreeNode*> queue;

	queue.push( this->pRoot );

	BinaryTreeNode* pNode;
	while ( not queue.empty( ) )
	{
		pNode = queue.front( );
		queue.pop( );

		if ( pNode->GetLeftChild( ) ) { queue.push( pNode->GetLeftChild( ) ); }
		if ( pNode->GetRightChild( ) ) { queue.push( pNode->GetRightChild( ) ); }

		std::invoke( fptr, pNode );
	}
}

BinaryTreeNode* BinaryTree::MRCA( BinaryTreeNode* pA, BinaryTreeNode* pB ) const
{
	std::unordered_set<BinaryTreeNode*> ancestors = std::unordered_set<BinaryTreeNode*>( );

	BinaryTreeNode* pCursor = pA;
	while ( pCursor )
	{
		ancestors.insert( pCursor );
		pCursor = pCursor->parent;
	}

	pCursor = pB;
	while ( pCursor and ( not ancestors.contains( pCursor ) ) )
	{
		pCursor = pCursor->parent;
	}

	return pCursor;
}

std::vector<std::list<BinaryTreeNode*>>* BinaryTree::NodesByDepth( ) const
{
	std::vector<std::list<BinaryTreeNode*>>* pResult = new std::vector<std::list<BinaryTreeNode*>>( );

	typedef std::pair<BinaryTreeNode*, int> DepthNode;

	std::queue<DepthNode> queue;
	queue.push( DepthNode( this->pRoot, 0 ) );

	while ( not queue.empty( ) )
	{
		const auto [pNode, depth] = queue.front( );
		queue.pop( );

		if ( pResult->size( ) < depth + 1 )
		{
			// vector too small --> add new list head
			pResult->emplace_back( std::list<BinaryTreeNode*>( ) );
		}

		// add node to the appropriate linked list
		( *pResult )[depth].push_back( pNode );

		// add its children to the queue
		if ( pNode->GetLeftChild( ) )
		{
			queue.push( DepthNode( pNode->GetLeftChild( ), depth + 1 ) );
		}

		if ( pNode->GetRightChild( ) )
		{
			queue.push( DepthNode( pNode->GetRightChild( ), depth + 1 ) );
		}
	}

	return pResult;
}

int BinaryTree::height( ) const
{
	return this->pRoot ? this->pRoot->height( ) + 1 : 0;
}

bool BinaryTree::IsBalanced( ) const
{
	if ( not this->pRoot )
	{
		return true;
	}
	else
	{
		int leftHeight = this->pRoot->leftChild ? this->pRoot->leftChild->height( ) : 0;
		int rightHeight = this->pRoot->rightChild ? this->pRoot->rightChild->height( ) : 0;

		return ( leftHeight - rightHeight <= 1 ) or ( rightHeight - leftHeight <= 1 );
	}
}

BinaryTreeNode* BinaryTree::sucessor( BinaryTreeNode* pNode ) const
{
	std::unordered_set<BinaryTreeNode*> visited;

	int d = pNode->data + 1;

	BinaryTreeNode* p = pNode;
	visited.insert( p );

	while ( p and ( p->data < d ) )
	{
		visited.insert( p );

		if ( p->rightChild and ( not visited.contains( p->rightChild ) ) )
		{
			p = p->rightChild;
		}
		else
		{
			p = p->parent;
		}
	}

	// we're definitely over, but maybe we overshot

	if ( p )
	{
		while ( p->leftChild and ( not visited.contains( p->leftChild ) ) )
		{
			p = p->leftChild;
		}
	}

	return p;
}

BinaryTreeNode* BinaryTree::GetRandomNode( ) const
{
	BinaryTreeNode* pResult = this->pRoot;

	if ( pResult )
	{
		unsigned int steps = rand( ) % this->size;

		for ( int i = 0; i < steps; i++ )
		{
			pResult = this->sucessor( pResult );
		}
	}

	return pResult;
}

int BinaryTree::PathsWithSum( int sum ) const
{
	return this->privPathsWithSum( new std::list<int>( ), this->pRoot, sum );
}

void BinaryTree::PrintBSTSequences( )
{
	if ( this->pRoot )
	{
		std::vector<std::list<int>*>* pResults = this->privAllSequences( this->pRoot );
		assert( pResults );

		for ( std::list<int>* pList : *pResults )
		{
			for ( int i : *pList )
			{
				std::cout << i << " ";
			}

			std::cout << std::endl;
		}
	}
}


