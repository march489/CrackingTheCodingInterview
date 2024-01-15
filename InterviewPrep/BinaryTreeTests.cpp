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

	assert( bTree.size == 7 );
	assert( bTree.height( ) == 5 );
	assert( bTree.PathsWithSum( 12 ) == 2 );

	std::cout << "\nPrinting Binary Tree -- BFS ...\n";
	bTree.BFS( &BinaryTreeNode::Print );

	std::cout << "\n\nPrinting Binary Tree -- DFS ...\n";
	bTree.DFS( &BinaryTreeNode::Print );

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 16, 17, 18 ,19, 20 };
	BinaryTree bTree2( vec );

	assert( bTree2.size == 20 );

	int pathsSizeOne = bTree2.PathsWithSum( 1 );
	assert( pathsSizeOne == 1 );

	std::cout << "\nPrinting Binary Tree -- BFS ...\n";
	bTree2.BFS( &BinaryTreeNode::Print );

	std::cout << "\n\nPrinting Binary Tree -- DFS ...\n";
	bTree2.DFS( &BinaryTreeNode::Print );

	std::vector<std::list<BinaryTreeNode*>>* pVec = bTree2.NodesByDepth( );
	assert( pVec );

	std::cout << "\nPrinting Nodes by Depth...\n";
	int depth = 0;
	for ( auto& list : ( *pVec ) )
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

	BinaryTree bTree3;
	BinaryTreeNode* pNodeA = bTree3.AddNode( 10 );
	BinaryTreeNode* pNodeB = new BinaryTreeNode( -2 );
	BinaryTreeNode* pNodeC = new BinaryTreeNode( 0 );
	BinaryTreeNode* pNodeD = new BinaryTreeNode( 5 );
	BinaryTreeNode* pNodeE = new BinaryTreeNode( 3 );
	BinaryTreeNode* pNodeF = new BinaryTreeNode( 4 );
	BinaryTreeNode* pNodeG = new BinaryTreeNode( 0 );
	BinaryTreeNode* pNodeH = new BinaryTreeNode( -5 );
	BinaryTreeNode* pNodeI = new BinaryTreeNode( -10 );
	
	pNodeA->SetLeftChild( pNodeB );
	pNodeA->SetRightChild( pNodeC );

	pNodeB->SetLeftChild( pNodeD );
	pNodeB->SetRightChild( pNodeE );

	pNodeE->SetLeftChild( pNodeH );

	pNodeC->SetLeftChild( pNodeF );
	pNodeC->SetRightChild( pNodeG );
	pNodeG->SetRightChild( pNodeI );

	std::cout << "\nPrinting Binary Tree -- BFS ...\n";
	bTree3.BFS( &BinaryTreeNode::Print );
	std::cout << "\nPrinting Binary Tree -- DFS ...\n";
	bTree3.DFS( &BinaryTreeNode::Print );

	assert( bTree3.PathsWithSum( 10 ) == 3 );
	assert( bTree3.PathsWithSum( 0 ) == 4 );
}