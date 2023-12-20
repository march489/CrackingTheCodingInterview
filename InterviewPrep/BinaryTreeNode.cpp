#include "BinaryTreeNode.h"
#include <iostream>

BinaryTreeNode::BinaryTreeNode( int _data )
	: parent{ nullptr }, leftChild{ nullptr }, rightChild{ nullptr }, data( _data )
{

}

BinaryTreeNode* BinaryTreeNode::GetLeftChild( )
{
	return this->leftChild;
}

BinaryTreeNode* BinaryTreeNode::GetRightChild( )
{
	return this->rightChild;
}

BinaryTreeNode* BinaryTreeNode::GetParent( )
{
	return this->parent;
}

void BinaryTreeNode::SetLeftChild( BinaryTreeNode* pNode )
{
	this->leftChild = pNode;
}

void BinaryTreeNode::SetRightChild( BinaryTreeNode* pNode )
{
	this->rightChild = pNode;
}

void BinaryTreeNode::SetParent( BinaryTreeNode* pNode )
{
	this->parent = pNode;
}

int BinaryTreeNode::height( ) const
{
	int leftHeight = this->leftChild ? this->leftChild->height( ) : -1;
	int rightHeight = this->rightChild ? this->rightChild->height( ) : -1;

	return std::max( leftHeight, rightHeight ) + 1;
}

void BinaryTreeNode::Print( )
{
	printf( "0x%p (%d)\n", this, this->data );
}

BinaryTreeNode::BinaryTreeNode( const BinaryTreeNode& in )
	: parent{ nullptr }, leftChild{ nullptr }, rightChild{ nullptr }, data( in.data )
{

}

BinaryTreeNode& BinaryTreeNode::operator=( const BinaryTreeNode& in )
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->data = in.data;

	return *this;
}

BinaryTreeNode::~BinaryTreeNode( )
{
	if ( this->leftChild )
	{
		delete this->leftChild;
		this->leftChild = nullptr;
	}

	if ( this->rightChild )
	{
		delete this->rightChild;
		this->rightChild = nullptr;
	}
}