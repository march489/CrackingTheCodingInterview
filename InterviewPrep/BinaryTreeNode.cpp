#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode( int _data )
	: leftChild{ nullptr }, rightChild{ nullptr }, data( _data )
{

}

BinaryTreeNode::BinaryTreeNode( const BinaryTreeNode& in )
	: leftChild{ nullptr }, rightChild{ nullptr }, data( in.data )
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