#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <assert.h>

void BinaryTree::RunTests_BinaryTree( )
{
	std::cout << "Beginning BinaryTree tests...\n";

	BinaryTree::RunTests_BinaryTree_AddNode( );
	//BinaryTree::RunTests_BinaryTree_FindNode( );
	//BinaryTree::RunTests_BinaryTree_ConstructorFromVector( );

	std::cout << " all tests pass.\n";
}

void BinaryTree::RunTests_BinaryTree_AddNode( )
{
	BinaryTree bTree;

	bTree.AddNode( 5 );
	bTree.AddNode( 3 );
	bTree.AddNode( 7 );
	bTree.AddNode( 10 );
	bTree.AddNode( 20 );
	bTree.AddNode( 12 );
	bTree.AddNode( 9 );

	std::cout << "\nPrinting Binary Tree -- BFS ...\n";
	bTree.BFS( &BinaryTreeNode::Print );

	std::cout << "\n\nPrinting Binary Tree -- DFS ...\n";
	bTree.DFS( &BinaryTreeNode::Print );

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 16, 17, 18 ,19, 20 };
	BinaryTree bTree2( vec );

	std::cout << "\nPrinting Binary Tree -- BFS ...\n";
	bTree2.BFS( &BinaryTreeNode::Print );

	std::cout << "\n\nPrinting Binary Tree -- DFS ...\n";
	bTree2.DFS( &BinaryTreeNode::Print );

	std::vector<std::list<BinaryTreeNode*>>* pVec = bTree2.NodesByDepth( );
	assert( pVec );

	std::cout << "\nPrinting Nodes by Depth...\n";
	int depth = 0;
	for ( auto list : ( *pVec ) )
	{
		printf( "\tPrinting nodes at depth %d:\n", depth );
		for ( auto pNode : list )
		{
			pNode->Print( );
		}
		depth++;
	}

	printf( "bTree2 height: %d\n", bTree2.height( ) );
	delete pVec;
	pVec = nullptr;

	BinaryTreeNode* pTarget = bTree2.FindNode( 1 );
	assert( pTarget and pTarget->data == 1 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 2 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 3 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 4 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 5 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 6 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 7 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 8 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 9 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 10 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 11 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 12 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 13 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 14 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 15 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 16 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 17 );
		
	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 18 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 19 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget and pTarget->data == 20 );

	pTarget = bTree2.sucessor( pTarget );
	assert( pTarget == nullptr );

	std::cout << "Running PrintBSTSeqs:\n";
	bTree.PrintBSTSequences( );
}