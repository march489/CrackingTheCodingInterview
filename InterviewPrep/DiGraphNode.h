#ifndef DIGRAPH_NODE_H
#define DIGRAPH_NODE_H

#include "GraphNode.h"

class DiGraphNode : public GraphNode
{
public:
	DiGraphNode( ) = delete;
	DiGraphNode( const DiGraphNode& in );
	DiGraphNode& operator=( const DiGraphNode& in );
	virtual ~DiGraphNode( );

	DiGraphNode( std::string _name, int _data );

	bool IsInNeighbor( DiGraphNode* pNeighbor ) const;
	size_t GetInDegree( ) const;

	void AddInNeighbor( DiGraphNode* pNeighbor );
	void RemoveInNeighbor( DiGraphNode* pNeighbor );

	friend DiGraph;

protected:
	std::unordered_set<DiGraphNode*> inNeighbors;
};


#endif // !DIGRAPH_NODE_H
