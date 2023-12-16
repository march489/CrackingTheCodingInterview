#include "Graph.h"
#include "GraphNode.h"
#include <assert.h>
#include <queue>
#include <unordered_map>

Graph::Graph( )
	: nodes( std::unordered_set<GraphNode*>( ) ),
	pRoot{ nullptr }
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

GraphNode* Graph::AddNode( std::string name, int data )
{
	GraphNode* pNode = new GraphNode( name, data );
	assert( pNode );

	if ( this->nodes.empty( ) )
	{
		this->pRoot = pNode;
	}

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

void Graph::SetRoot( GraphNode* a )
{
	if ( this->nodes.contains( a ) )
	{
		this->pRoot = a;
	}
	else
	{
		// do nothing & move on
	}
}

GraphNode* Graph::GetRoot( ) const
{
	return this->pRoot;
}

void Graph::ForEach_DepthFirst( void( GraphNode::* fptr )( void ) const )
{
	std::unordered_set<GraphNode*> visitedNodes;

	this->privForEach_DFS( fptr, this->pRoot, visitedNodes );
}

void Graph::ForEach_BreadthFirst( void( GraphNode::* fptr )( void ) const )
{
	std::unordered_set<GraphNode*> visitedNodes;
	std::queue<GraphNode*> queue;

	queue.push( this->pRoot );

	while ( not queue.empty( ) )
	{
		GraphNode* pNode = queue.front( );
		queue.pop( );

		bool bNotPreviouslyVisited = visitedNodes.insert( pNode ).second;

		if ( bNotPreviouslyVisited )
		{
			std::invoke( fptr, pNode );
			for ( auto it = pNode->neighbors.begin( ); it != pNode->neighbors.end( ); it++ )
			{
				queue.push( *it );
			}
		}
	}
}

std::vector<GraphNode*>* Graph::FindShortestPath( GraphNode* pStart, GraphNode* pFinish )
{
	std::unordered_map<GraphNode*, GraphNode*> predecessors;
	//typedef std::tuple<GraphNode*, GraphNode*> ToFromPair;

	std::queue<GraphNode*> queue;
	std::unordered_set<GraphNode*> visitedNodes;

	queue.push( pFinish );

	GraphNode* pNode = nullptr;
	while ( not queue.empty( ) )
	{
		pNode = queue.front( );
		queue.pop( );

		if ( pNode == pStart )
		{
			// were' done!
			break;
		}

		bool bNotPreviouslyVisited = visitedNodes.insert( pNode ).second;

		if ( bNotPreviouslyVisited )
		{
			for ( auto it = pNode->neighbors.begin( ); it != pNode->neighbors.end( ); it++ )
			{
				// only add a predecessor if it doesn't already have one
				// a previous one is linked to a shorter path,
				// though this doesn't guaranteed *it is in visitedNodes
				if ( not predecessors[*it] && not visitedNodes.contains( *it ) )
				{
					predecessors[*it] = pNode;
				}

				queue.push( *it );
			}
		}

		// reset
		pNode = nullptr;
	}

	std::vector<GraphNode*>* pResult = new std::vector<GraphNode*>( );
	assert( pResult );

	while ( pNode )
	{
		pResult->push_back( pNode );
		pNode = predecessors[pNode];
	}

	return pResult;
}

void Graph::Print( const char* const pName ) const
{
	// cute way to call print using fxn pointers
	void ( GraphNode:: * fptr )( void ) const = &GraphNode::Print;

	std::cout << pName << ":\n";
	for ( auto it = this->nodes.begin( ); it != this->nodes.end( ); it++ )
	{
		//( *it )->Print( );
		std::invoke( fptr, *it );
	}
}

void Graph::RunTests_GraphBasics( )
{
	Graph graph;

	GraphNode* pBlinky = graph.AddNode( "Blinky", 23 );
	GraphNode* pPinky = graph.AddNode( "Pinky", 15 );
	GraphNode* pInky = graph.AddNode( "Inky", 11 );
	GraphNode* pSue = graph.AddNode( "Sue", 28 );
	GraphNode* pMsPacMan = graph.AddNode( "MsPacMan", 24 );

	graph.AddEdge( pBlinky, pPinky );
	graph.AddEdge( pBlinky, pInky );
	graph.AddEdge( pSue, pMsPacMan );
	graph.AddEdge( pMsPacMan, pInky );
	graph.AddEdge( pSue, pInky );

	//graph.Print( "Basic graph" );

	std::cout << "\nDepth First Print:" << std::endl;
	graph.ForEach_DepthFirst( &GraphNode::Print );

	std::cout << "\nSetting Inky as root, and DFS print\n";
	graph.SetRoot( pInky );
	graph.ForEach_DepthFirst( &GraphNode::Print );

	std::cout << "\nRunning BreadthFirst from Inky as root:\n";
	graph.ForEach_BreadthFirst( &GraphNode::Print );

	std::cout << "\nSetting root back to Blinky, and doing BreadthFirst\n";
	graph.SetRoot( pBlinky );
	graph.ForEach_BreadthFirst( &GraphNode::Print );

	std::cout << "\nShortest Path from Blinky to itself:\n";
	std::vector<GraphNode*>* pShortestPath = graph.FindShortestPath( pBlinky, pBlinky );
	assert( pShortestPath );

	for ( size_t index = 0; index < pShortestPath->size( ); index++ )
	{
		( *pShortestPath )[index]->Print( );
	}

	// reset 
	delete pShortestPath;
	pShortestPath = nullptr;

	std::cout << "\nShortest Path from MsPacMan to Sue:\n";
	pShortestPath = graph.FindShortestPath( pMsPacMan, pSue );
	assert( pShortestPath );

	for ( size_t index = 0; index < pShortestPath->size( ); index++ )
	{
		( *pShortestPath )[index]->Print( );
	}

	delete pShortestPath;
	pShortestPath = nullptr;
}

void Graph::privForEach_DFS( void( GraphNode::* fptr )( void ) const, GraphNode* pNode, std::unordered_set<GraphNode*>& visitedNodes )
{
	bool bNotPreviouslyVisited = visitedNodes.insert( pNode ).second;

	if ( bNotPreviouslyVisited )
	{
		std::invoke( fptr, pNode );

		for ( auto it = pNode->neighbors.begin( ); it != pNode->neighbors.end( ); it++ )
		{
			privForEach_DFS( fptr, ( *it ), visitedNodes );
		}
	}
}

void Graph::RemoveNode( GraphNode* pNode )
{
	this->nodes.erase( pNode );
	delete pNode;
}

