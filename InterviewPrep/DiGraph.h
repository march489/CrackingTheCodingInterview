#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <unordered_set>
#include <iostream>
#include "Graph.h"

class DiGraph : public Graph
{
public:
	DiGraph( );
	DiGraph( const DiGraph& ) = delete;
	DiGraph& operator=( const DiGraph& ) = delete;
	virtual ~DiGraph( );

	virtual void AddEdge( GraphNode* pSrc, GraphNode* pDest ) override;
	virtual void RemoveEdge( GraphNode* pSrc, GraphNode* pDest ) override;

	std::vector<GraphNode*>* BuildOrder( ) const;

	static void RunTests_DiGraph( );
};

#endif // !DIGRAPH_H
