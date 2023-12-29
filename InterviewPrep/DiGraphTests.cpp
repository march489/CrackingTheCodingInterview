#include "DiGraph.h"
#include "DiGraphNode.h"
#include <iostream>
#include <assert.h>

void DiGraph::RunTests_DiGraph( )
{
	std::cout << "Running DiGraph tests...";

	DiGraph graph;

	DiGraphNode* pA = graph.AddNode( "A", 10 );
	DiGraphNode* pB = graph.AddNode( "B", 20 );
	DiGraphNode* pC = graph.AddNode( "C", 30 );
	DiGraphNode* pD = graph.AddNode( "D", 40 );
	DiGraphNode* pE = graph.AddNode( "E", 50 );
	DiGraphNode* pF = graph.AddNode( "F", 60 );
	DiGraphNode* pG = graph.AddNode( "G", 70 );

	graph.AddEdge( pF, pC );
	graph.AddEdge( pF, pB );
	graph.AddEdge( pF, pA );
	graph.AddEdge( pC, pA );
	graph.AddEdge( pB, pA );
	graph.AddEdge( pA, pE );
	graph.AddEdge( pB, pE );
	graph.AddEdge( pD, pG );


	std::vector<std::string>* pBuildOrder = graph.CreateBuildOrder( );

	std::cout << "Build Order:";
	for ( std::string name : *pBuildOrder )
	{
		std::cout << ' ' << name;
	}

	std::cout << '\n';
	std::cout << " all tests pass.\n";
}