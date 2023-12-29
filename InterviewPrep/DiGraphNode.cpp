#include "DiGraphNode.h"

DiGraphNode::DiGraphNode( const DiGraphNode& in )
	: GraphNode( in ),
	inNeighbors( std::unordered_set<DiGraphNode*>( ) )
{
}

DiGraphNode& DiGraphNode::operator=( const DiGraphNode& in )
{
	this->name = in.name;
	this->data = in.data;
	this->outNeighbors.clear( );
	this->inNeighbors.clear( );

	return *this;
}

DiGraphNode::~DiGraphNode( )
{
	this->inNeighbors.clear( );
}

DiGraphNode::DiGraphNode( std::string _name, int _data )
	: GraphNode( _name, _data ),
	inNeighbors( std::unordered_set<DiGraphNode*>( ) )
{
}

bool DiGraphNode::IsInNeighbor( DiGraphNode* pNeighbor ) const
{
	return this->inNeighbors.contains( pNeighbor );
}

size_t DiGraphNode::GetInDegree( ) const
{
	return this->inNeighbors.size( );
}

void DiGraphNode::AddInNeighbor( DiGraphNode* pNeighbor )
{
	this->inNeighbors.insert( pNeighbor );
}

void DiGraphNode::RemoveInNeighbor( DiGraphNode* pNeighbor )
{
	this->inNeighbors.erase( pNeighbor );
}
