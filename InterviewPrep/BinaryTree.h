#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <list>
#include "BinaryTreeNode.h"

class BinaryTree
{
public:
	BinaryTree( );
	BinaryTree( const BinaryTree& ) = delete;
	BinaryTree& operator=( const BinaryTree& ) = delete;
	~BinaryTree( );

	// specialized constructor
	BinaryTree( const std::vector<int>& arr );

	BinaryTreeNode* AddNode( int k );
	BinaryTreeNode* FindNode( int k ) const;

	void DFS( void ( BinaryTreeNode::* fptr ) ( void ) );
	void BFS( void ( BinaryTreeNode::* fptr ) ( void ) );

	BinaryTreeNode* MRCA( BinaryTreeNode* pA, BinaryTreeNode* pB ) const;
	std::vector<std::list<BinaryTreeNode*>>* NodesByDepth( ) const;
	int height( ) const;
	bool IsBalanced( ) const;
	BinaryTreeNode* sucessor( BinaryTreeNode* pNode ) const;

	static void RunTests_BinaryTree( );

private:
	void privDFS( void ( BinaryTreeNode::* fptr ) ( void ),
				  BinaryTreeNode* pNode );

	BinaryTreeNode* AddNode( BinaryTreeNode* pRoot, int k );
	BinaryTreeNode* CreateNodesFromArray( const std::vector<int>& arr,
										  int start,
										  int end );

	// tests
	static void RunTests_BinaryTree_AddNode( );


private:
	BinaryTreeNode* pRoot;
};
#endif // !BINARY_TREE_H
