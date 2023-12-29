#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include "Graph.h"

class DiGraphNode;

class DiGraph : public Graph
{
public:
	DiGraph( );
	DiGraph( const DiGraph& ) = delete;
	DiGraph& operator=( const DiGraph& ) = delete;
	virtual ~DiGraph( );

	void AddEdge( DiGraphNode* pSrc, DiGraphNode* pDest );
	void RemoveEdge( DiGraphNode* pSrc, DiGraphNode* pDest );

	DiGraphNode* AddNode( std::string name, int data );
	void RemoveNode( DiGraphNode* pNode );

	std::vector<std::string>* CreateBuildOrder( ); 	// consumes digraph

	static void RunTests_DiGraph( );
};

#endif // !DIGRAPH_H
