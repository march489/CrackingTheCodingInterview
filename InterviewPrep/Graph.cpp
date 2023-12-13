#include "Graph.h"
#include "GraphNode.h"
#include <assert.h>

Graph::Graph( )
	: nodes( std::unordered_set<GraphNode*>( ) )
{

}

Graph::~Graph( )
{
	for ( auto it = this->nodes.begin( ); it != this->nodes.end( ); it++ )
	{
		delete ( *it );
	}

	this->nodes.clear( );
}

GraphNode* Graph::AddNode( std::string name )
{
	GraphNode* pNode = new GraphNode( name );
	assert( pNode );

	this->nodes.insert( pNode );

	return pNode;
}

void Graph::AddEdge( GraphNode* a, GraphNode* b )
{
	a->AddNeighbor( b );
	b->AddNeighbor( a );
}

void Graph::RemoveEdge( GraphNode* a, GraphNode* b )
{
	a->RemoveNeighbor( b );
	b->RemoveNeighbor( a );
}

void Graph::RemoveNode( GraphNode* pNode )
{
	this->nodes.erase( pNode );
	delete pNode;
}

