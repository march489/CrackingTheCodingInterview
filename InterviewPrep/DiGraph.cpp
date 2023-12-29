#include "DiGraph.h"
#include "DiGraphNode.h"
#include <assert.h>
#include <algorithm>

DiGraph::DiGraph( )
	: Graph( )
{

}

DiGraph::~DiGraph( )
{
	//Graph::~Graph( );
}

void DiGraph::AddEdge( DiGraphNode* pSrc, DiGraphNode* pDest )
{
	if ( this->nodes.contains( pSrc ) and this->nodes.contains( pDest ) )
	{
		pSrc->AddOutNeighbor( pDest );
		pDest->AddInNeighbor( pSrc );
	}
}

void DiGraph::RemoveEdge( DiGraphNode* pSrc, DiGraphNode* pDest )
{
	if ( this->nodes.contains( pSrc ) and this->nodes.contains( pDest ) )
	{
		pSrc->RemoveOutNeighbor( pDest );
		pDest->RemoveInNeighbor( pSrc );
	}
}

DiGraphNode* DiGraph::AddNode( std::string name, int data )
{
	DiGraphNode* pNode = new DiGraphNode( name, data );
	assert( pNode );

	if ( this->nodes.empty( ) )
	{
		this->pRoot = pNode;
	}

	this->nodes.insert( pNode );

	return pNode;
}

void DiGraph::RemoveNode( DiGraphNode* pNode )
{
	this->nodes.erase( pNode );

	for ( GraphNode* pVertex : this->nodes )
	{
		DiGraphNode* pDGN = (DiGraphNode*) pVertex;		// downcast safely

		pDGN->RemoveInNeighbor( pNode );
		pDGN->RemoveOutNeighbor( pNode );
	}

	// set a new root if necessary
	if ( this->pRoot = pNode )
	{
		this->pRoot = this->nodes.empty( ) ? nullptr : *this->nodes.cbegin( );
	}

	delete pNode;
	pNode = nullptr;
}

std::vector<std::string>* DiGraph::CreateBuildOrder( )
{
	std::vector<std::string>* pBuildOrder = new std::vector<std::string>( );
	std::unordered_set<DiGraphNode*> toDelete;
	size_t counter = this->nodes.size( );
	size_t originalSize = counter;

	while ( not this->nodes.empty( ) and
			counter > 0 )
	{
		for ( GraphNode* pGN : this->nodes )
		{
			DiGraphNode* pDGN = (DiGraphNode*) pGN;	// downcast with confidence

			if ( pDGN->GetInDegree( ) == 0 )
			{
				// add everything with no dependencies
				pBuildOrder->push_back( pDGN->GetName( ) );
				toDelete.insert( pDGN );
			}
		}

		// remove the ones you inserted
		for ( DiGraphNode* pDGN : toDelete )
		{
			this->RemoveNode( pDGN );
		}

		// reset 
		toDelete.clear( );
		counter--;
	}

	if ( pBuildOrder->size( ) < originalSize )
	{
		// if we didn't get everyone, wipe the slate
		pBuildOrder->clear( );
	}

	return pBuildOrder;
}

