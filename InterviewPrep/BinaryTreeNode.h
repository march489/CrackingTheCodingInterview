#ifndef TREE_NODE_H
#define TREE_NODE_H

class BinaryTreeNode
{
public:
	BinaryTreeNode( ) = delete;
	BinaryTreeNode( const BinaryTreeNode& in );
	BinaryTreeNode& operator=( const BinaryTreeNode& in );
	~BinaryTreeNode( );		// we'll see

	BinaryTreeNode( int _data );

public:
	// data
	BinaryTreeNode* leftChild;
	BinaryTreeNode* rightChild;
	int data;
};
#endif // !TREE_NODE_H
