#include "DiGraph.h"
#include "GraphNode.h"
#include <assert.h>

DiGraph::DiGraph( )
	: Graph( )
{

}

DiGraph::~DiGraph( )
{
	//Graph::~Graph( );
}

void DiGraph::AddEdge( GraphNode* pSrc, GraphNode* pDest )
{
	if ( this->nodes.contains( pSrc ) and this->nodes.contains( pDest ) )
	{
		pSrc->AddNeighbor( pDest );
	}
}

void DiGraph::RemoveEdge( GraphNode* pSrc, GraphNode* pDest )
{
	if ( this->nodes.contains( pSrc ) and this->nodes.contains( pDest ) )
	{
		pSrc->RemoveNeighbor( pDest );
	}
}

std::vector<GraphNode*>* DiGraph::BuildOrder( ) const
{
	// TODO: Make this make sense
	std::unordered_set<GraphNode*> nodesWithoutDependencies = this->nodes;
	for ( GraphNode* pNode : this->nodes )
	{
		for ( GraphNode* pNeighbor : pNode->neighbors )
		{
			nodesWithoutDependencies.erase( pNeighbor );
		}
	}

	if ( nodesWithoutDependencies.empty( ) )
	{
		assert( false );
	}

	std::vector<GraphNode*>* pBuildOrder = new std::vector<GraphNode*>( );
	assert( pBuildOrder );


}
