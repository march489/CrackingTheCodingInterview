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
	
	BinaryTreeNode* GetLeftChild( );
	BinaryTreeNode* GetRightChild( );
	BinaryTreeNode* GetParent( );

	void SetLeftChild( BinaryTreeNode* );
	void SetRightChild( BinaryTreeNode* );
	void SetParent( BinaryTreeNode* );

	int height( ) const;

	void Print( );

public:
	// data
	BinaryTreeNode* parent;
	BinaryTreeNode* leftChild;
	BinaryTreeNode* rightChild;
	int data;
};
#endif // !TREE_NODE_H
