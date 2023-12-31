#include "BinaryTree.h"
#include <assert.h>
#include <queue>
#include <unordered_set>

BinaryTree::BinaryTree( )
	: pRoot{ nullptr }
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
